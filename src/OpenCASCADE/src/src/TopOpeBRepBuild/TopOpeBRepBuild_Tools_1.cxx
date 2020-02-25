// Created on: 2000-02-11
// Created by: Peter KURNEV
// Copyright (c) 2000-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.



#include <TopOpeBRepBuild_Tools.ixx>


#include <TopTools_IndexedMapOfShape.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Face.hxx>

#include <TopLoc_Location.hxx>

#include <BRep_TVertex.hxx>
#include <BRep_TEdge.hxx>
#include <BRep_TFace.hxx>
#include <BRep_Tool.hxx>
#include <BRep_GCurve.hxx>
#include <BRep_ListIteratorOfListOfPointRepresentation.hxx>
#include <BRep_ListIteratorOfListOfCurveRepresentation.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_PointRepresentation.hxx>

#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_TrimmedCurve.hxx>

#include <GeomAdaptor_Curve.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomAdaptor_HSurface.hxx>

#include <Geom2d_Curve.hxx>

#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom2dAdaptor.hxx>
#include <GeomProjLib.hxx>

#include <gp_Pnt.hxx>

#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>

#include <ProjLib_ProjectedCurve.hxx>
#include <Extrema_LocateExtPC.hxx>
#include <BRepCheck_Wire.hxx>

static 
  void CheckEdge (const TopoDS_Edge& E,
		  const Standard_Real aMaxTol);
static 
  void CorrectEdgeTolerance (const TopoDS_Edge& myShape,
			     const TopoDS_Face& S,
			     const Standard_Real aMaxTol);
static 
  Standard_Boolean Validate(const Adaptor3d_Curve& CRef,
			 const Adaptor3d_Curve& Other,
			 const Standard_Real Tol,
			 const Standard_Boolean SameParameter,
			 Standard_Real& aNewTolerance);

//=======================================================================
// Function : CorrectTolerances
// purpose : 
//=======================================================================
  void TopOpeBRepBuild_Tools::CorrectTolerances(const TopoDS_Shape& aShape,
						const Standard_Real aMaxTol)
{
  TopOpeBRepBuild_Tools::CorrectPointOnCurve(aShape, aMaxTol);
  TopOpeBRepBuild_Tools::CorrectCurveOnSurface(aShape, aMaxTol);
}

//=======================================================================
// Function : CorrectPointOnCurve
// purpose : 
//=======================================================================
  void TopOpeBRepBuild_Tools::CorrectPointOnCurve(const TopoDS_Shape& S,
						  const Standard_Real aMaxTol)
{
  Standard_Integer i, aNb;
  TopTools_IndexedMapOfShape Edges;
  TopExp::MapShapes (S, TopAbs_EDGE, Edges);
  aNb=Edges.Extent();
  for (i=1; i<=aNb; i++) {
    const TopoDS_Edge& E= TopoDS::Edge(Edges(i));
    CheckEdge(E, aMaxTol);
  }     
}

//=======================================================================
// Function : CorrectCurveOnSurface
// purpose : 
//=======================================================================
  void TopOpeBRepBuild_Tools::CorrectCurveOnSurface(const TopoDS_Shape& S,
						    const Standard_Real aMaxTol)
{
  Standard_Integer i, aNbFaces, j, aNbEdges;
  TopTools_IndexedMapOfShape Faces;
  TopExp::MapShapes (S, TopAbs_FACE, Faces);
  
  aNbFaces=Faces.Extent();
  for (i=1; i<=aNbFaces; i++) {
    const TopoDS_Face& F= TopoDS::Face(Faces(i));
    TopTools_IndexedMapOfShape Edges;
    TopExp::MapShapes (F, TopAbs_EDGE, Edges);
    aNbEdges=Edges.Extent();
    for (j=1; j<=aNbEdges; j++) {
      const TopoDS_Edge& E= TopoDS::Edge(Edges(j));
      CorrectEdgeTolerance (E, F, aMaxTol);
    }
  }
}

//=======================================================================
// Function : CorrectEdgeTolerance
// purpose :  Correct tolerances for Edge 
//=======================================================================
void CorrectEdgeTolerance (const TopoDS_Edge& myShape, 
			   const TopoDS_Face& S,
			   const Standard_Real aMaxTol)
{
  // 
  // 1. Minimum of conditions to Perform
  Handle (BRep_CurveRepresentation) myCref;
  Handle (Adaptor3d_HCurve) myHCurve;

  myCref.Nullify();

  Handle(BRep_TEdge)& TE = *((Handle(BRep_TEdge)*)&myShape.TShape());
  BRep_ListIteratorOfListOfCurveRepresentation itcr(TE->Curves());
  Standard_Boolean Degenerated, SameParameter, SameRange;

  Standard_Integer unique = 0;

  Degenerated   = TE->Degenerated();
  SameParameter = TE->SameParameter();
  SameRange     = TE->SameRange();
  
  if (!SameRange && SameParameter) {
    return;
  }

  while (itcr.More()) {
    const Handle(BRep_CurveRepresentation)& cr = itcr.Value();
    if (cr->IsCurve3D()) {
      unique++;
      if (myCref.IsNull() && !cr->Curve3D().IsNull()) {
	myCref = cr;
      }
    }
    itcr.Next();
  }
  
  if (unique==0) {
    return;//...No3DCurve
  }
  if (unique>1) {
    return;//...Multiple3DCurve;
  }

  if (myCref.IsNull() && !Degenerated) {
    itcr.Initialize(TE->Curves());
    while (itcr.More()) {
      const Handle(BRep_CurveRepresentation)& cr = itcr.Value();
      if (cr->IsCurveOnSurface()) {
	myCref = cr;
	break;
      }
      itcr.Next();
    }
  }
  
  else if (!myCref.IsNull() && Degenerated){
    return ;//...InvalidDegeneratedFlag;
  }
  
  if (!myCref.IsNull()) {
    const Handle(BRep_GCurve)& GCref = *((Handle(BRep_GCurve)*)&myCref);
    Standard_Real First,Last;
    GCref->Range(First,Last);
    if (Last<=First) {
      myCref.Nullify();
      return ;//InvalidRange;
    }
    
    else {
      if (myCref->IsCurve3D()) {
	Handle(Geom_Curve) C3d = Handle(Geom_Curve)::DownCast
	  (myCref->Curve3D()->Transformed (myCref->Location().Transformation()));
	GeomAdaptor_Curve GAC3d(C3d,First,Last);
	myHCurve = new GeomAdaptor_HCurve(GAC3d);
      }
      else { // curve on surface
	Handle(Geom_Surface) Sref = myCref->Surface();
	Sref = Handle(Geom_Surface)::DownCast(Sref->Transformed(myCref->Location().Transformation()));
	const  Handle(Geom2d_Curve)& PCref = myCref->PCurve();
	Handle(GeomAdaptor_HSurface) GAHSref = new GeomAdaptor_HSurface(Sref);
	Handle(Geom2dAdaptor_HCurve) GHPCref = new Geom2dAdaptor_HCurve(PCref, First, Last);
	Adaptor3d_CurveOnSurface ACSref(GHPCref,GAHSref);
	myHCurve = new Adaptor3d_HCurveOnSurface(ACSref);
      }
    }
  }

  //=============================================== 
  // 2. Tolerances in InContext
  {
    if (myCref.IsNull()) 
      return;
    Standard_Boolean ok=Standard_True;

    Standard_Real Tol = BRep_Tool::Tolerance(TopoDS::Edge(myShape));
    Standard_Real aNewTol=Tol;

    Standard_Real First = myHCurve->FirstParameter();
    Standard_Real Last  = myHCurve->LastParameter();
    
    Handle(BRep_TFace)& TF = *((Handle(BRep_TFace)*) &S.TShape());
    const TopLoc_Location& Floc = S.Location();
    const TopLoc_Location& TFloc = TF->Location();
    const Handle(Geom_Surface)& Su = TF->Surface();
    TopLoc_Location L = (Floc * TFloc).Predivided(myShape.Location());
    //      Standard_Boolean checkclosed = Standard_False;
    Standard_Boolean pcurvefound = Standard_False;

    itcr.Initialize(TE->Curves());
    while (itcr.More()) {
      const Handle(BRep_CurveRepresentation)& cr = itcr.Value();
      if (cr != myCref && cr->IsCurveOnSurface(Su,L)) {
	pcurvefound = Standard_True;
	const Handle(BRep_GCurve)& GC = *((Handle(BRep_GCurve)*)&cr);
	Standard_Real f,l;
	GC->Range(f,l);
	if (SameRange && (f != First || l != Last)) {
	  return ;//BRepCheck_InvalidSameRangeFlag);
	  if (SameParameter) {
	    return; //BRepCheck_InvalidSameParameterFlag);
	  }
        }
	
	Handle(Geom_Surface) Sb = cr->Surface();
	Sb = Handle(Geom_Surface)::DownCast (Su->Transformed(L.Transformation()));
	Handle(Geom2d_Curve) PC = cr->PCurve();
	Handle(GeomAdaptor_HSurface) GAHS = new GeomAdaptor_HSurface(Sb);
	Handle(Geom2dAdaptor_HCurve) GHPC = new Geom2dAdaptor_HCurve(PC,f,l);
	Adaptor3d_CurveOnSurface ACS(GHPC,GAHS);
	ok = Validate(myHCurve->Curve(), ACS, Tol, SameParameter, aNewTol);
	if (ok) {
	  if (cr->IsCurveOnClosedSurface()) {
	    //return ;// BRepCheck::Add(lst,BRepCheck_InvalidCurveOnClosedSurface);
	  }
	  else {
	    //return;//BRepCheck::Add(lst,BRepCheck_InvalidCurveOnSurface);
	  }
	  if (SameParameter) {
	    //return;//BRepCheck::Add(lst,BRepCheck_InvalidSameParameterFlag);
	  }
//	  printf("(Edge,1) Tolerance=%15.10lg\n", aNewTol);
	  if (aNewTol<aMaxTol)
	    TE->UpdateTolerance(aNewTol); 
	}

	if (cr->IsCurveOnClosedSurface()) {
	  //	    checkclosed = Standard_True;
	  GHPC->ChangeCurve2d().Load(cr->PCurve2(),f,l); // same bounds
	  ACS.Load(GAHS); // sans doute inutile
	  ACS.Load(GHPC); // meme remarque...
	  ok = Validate(myHCurve->Curve(),ACS,Tol,SameParameter, aNewTol);
	  if (ok) {
	    //return;//BRepCheck::Add(lst,BRepCheck_InvalidCurveOnClosedSurface);
	    if (SameParameter) {
	      //return;//BRepCheck::Add(lst,BRepCheck_InvalidSameParameterFlag);
	    }
//	    printf("(Edge,2) Tolerance=%15.10lg\n", aNewTol);
	    if (aNewTol<aMaxTol)
	      TE->UpdateTolerance(aNewTol); 
	  }
	}
      }
      itcr.Next();
    }
    
    if (!pcurvefound) {
      Handle(Geom_Plane) P;
      Handle(Standard_Type) styp = Su->DynamicType();
      if (styp == STANDARD_TYPE(Geom_RectangularTrimmedSurface)) {
	P = Handle(Geom_Plane)::DownCast(Handle(Geom_RectangularTrimmedSurface)::
					 DownCast(Su)->BasisSurface());
      }
      else {
	P = Handle(Geom_Plane)::DownCast(Su);
      }
      if (P.IsNull()) { // not a plane
	return;//BRepCheck::Add(lst,BRepCheck_NoCurveOnSurface);
      }
      
      else {// on fait la projection a la volee, comme BRep_Tool
	P = Handle(Geom_Plane)::DownCast(P->Transformed(L.Transformation()));
	//on projette Cref sur ce plan
	Handle(GeomAdaptor_HSurface) GAHS = new GeomAdaptor_HSurface(P);
	
	// Dub - Normalement myHCurve est une GeomAdaptor_HCurve
	GeomAdaptor_Curve& Gac = Handle(GeomAdaptor_HCurve)::DownCast(myHCurve)->ChangeCurve();
	Handle(Geom_Curve) C3d = Gac.Curve();
	Handle(Geom_Curve) ProjOnPlane = GeomProjLib::ProjectOnPlane
	  (new Geom_TrimmedCurve(C3d,First,Last), P, P->Position().Direction(), Standard_True);

	Handle(GeomAdaptor_HCurve) aHCurve = new GeomAdaptor_HCurve(ProjOnPlane);
	
	ProjLib_ProjectedCurve proj(GAHS,aHCurve);
	Handle(Geom2d_Curve) PC = Geom2dAdaptor::MakeCurve(proj);
	Handle(Geom2dAdaptor_HCurve) GHPC = 
	  new Geom2dAdaptor_HCurve(PC, myHCurve->FirstParameter(), myHCurve->LastParameter());
	
	Adaptor3d_CurveOnSurface ACS(GHPC,GAHS);
	
	ok = Validate(myHCurve->Curve(),ACS,
                      Tol,Standard_True, aNewTol); // voir dub...
	if (ok) {
	  //return;//BRepCheck::Add(lst,BRepCheck_InvalidCurveOnSurface);
//	  printf("(Edge,3) Tolerance=%15.10lg\n", aNewTol);
	  if (aNewTol<aMaxTol)
	    TE->UpdateTolerance(aNewTol); 
	}
      }
      
    }//end of if (!pcurvefound) {
  } // end of  2. Tolerances in InContext

}

#define NCONTROL 23
//=======================================================================
//function : Validate
//purpose  : 
//=======================================================================
Standard_Boolean Validate(const Adaptor3d_Curve& CRef,
		       const Adaptor3d_Curve& Other,
		       const Standard_Real Tol,
		       const Standard_Boolean SameParameter,
		       Standard_Real& aNewTolerance)
{
  Standard_Real First, Last, MaxDistance, aD;

  First = CRef.FirstParameter();
  Last  = CRef.LastParameter();
  MaxDistance = Tol*Tol;

  Standard_Integer i, aNC1=NCONTROL-1;

  Standard_Boolean aFlag=Standard_False;
  Standard_Boolean proj = (!SameParameter || 
			   First != Other.FirstParameter() ||
			   Last  != Other.LastParameter());
  //
  // 1. 
  if (!proj) {
    for (i = 0; i < NCONTROL; i++) {
      Standard_Real prm = ((aNC1-i)*First + i*Last)/aNC1;
      gp_Pnt pref   = CRef.Value(prm);
      gp_Pnt pother = Other.Value(prm);
      
      aD=pref.SquareDistance(pother);

      if (aD > MaxDistance) {
	MaxDistance=aD;
	aFlag=Standard_True;
      }
    }
  }
  
  //
  // 2.
  else {
    Extrema_LocateExtPC refd,otherd;
    Standard_Real OFirst, OLast;
    OFirst = Other.FirstParameter();
    OLast  = Other.LastParameter();
    
    gp_Pnt pd  = CRef.Value(First);
    gp_Pnt pdo = Other.Value(OFirst);
    
    aD = pd.SquareDistance(pdo);
    if (aD > MaxDistance) {
      MaxDistance=aD;
      aFlag=Standard_True;
    }

    pd  = CRef.Value(Last);
    pdo = Other.Value(OLast);
    aD = pd.SquareDistance(pdo);
    if (aD > MaxDistance) {
      MaxDistance=aD;
      aFlag=Standard_True;
    }

    refd.Initialize(CRef, First, Last, CRef.Resolution(Tol));
    otherd.Initialize(Other, OFirst, OLast, Other.Resolution(Tol));
    
    for (i = 2; i< aNC1; i++) {
      Standard_Real rprm = ((aNC1-i)*First + i*Last)/aNC1;
      gp_Pnt pref = CRef.Value(rprm);

      Standard_Real oprm = ((aNC1-i)*OFirst + i*OLast)/aNC1;
      gp_Pnt pother = Other.Value(oprm);

      refd.Perform(pother,rprm);
      if (!refd.IsDone() || refd.SquareDistance() > Tol * Tol) {
	if (refd.IsDone()) {
	  aD=refd.SquareDistance();
	  if (aD > MaxDistance) {
	    aFlag=Standard_True;
	    MaxDistance=aD;
	  }
	}
      }

      otherd.Perform(pref,oprm);
      if (!otherd.IsDone() || otherd.SquareDistance() > Tol * Tol) {
	
	if (otherd.IsDone()) {
	  aD=otherd.SquareDistance();
	  if (aD > MaxDistance) {
	    aFlag=Standard_True;
	    MaxDistance=aD;
	  }
	}
      }
    }
  }

  if (aFlag) {
    aD=sqrt (MaxDistance);
    aNewTolerance=aD*1.05;
  }

  return aFlag;
  
}

//=======================================================================
// Function : CheckEdge
// purpose :  Correct tolerances for Vertices on Edge 
//=======================================================================
void CheckEdge (const TopoDS_Edge& Ed, const Standard_Real aMaxTol)
{
  TopoDS_Edge E=Ed;
  E.Orientation(TopAbs_FORWARD);

  gp_Pnt Controlp;
  
  TopExp_Explorer aVExp;
  aVExp.Init(E, TopAbs_VERTEX);
  for (; aVExp.More(); aVExp.Next()) {
    TopoDS_Vertex aVertex= TopoDS::Vertex(aVExp.Current());

    Handle(BRep_TVertex)& TV = *((Handle(BRep_TVertex)*) &aVertex.TShape());
    const gp_Pnt& prep = TV->Pnt();

    Standard_Real Tol, aD2, aNewTolerance, dd;

    Tol =BRep_Tool::Tolerance(aVertex);
    Tol = Max(Tol, BRep_Tool::Tolerance(E));
    dd=0.1*Tol;
    Tol*=Tol;

    const TopLoc_Location& Eloc = E.Location();
    BRep_ListIteratorOfListOfPointRepresentation itpr;
    
    Handle(BRep_TEdge)& TE = *((Handle(BRep_TEdge)*)&E.TShape());
    BRep_ListIteratorOfListOfCurveRepresentation itcr(TE->Curves());
    while (itcr.More()) {
      const Handle(BRep_CurveRepresentation)& cr = itcr.Value();
      const TopLoc_Location& loc = cr->Location();
      TopLoc_Location L = (Eloc * loc).Predivided(aVertex.Location());
      
      if (cr->IsCurve3D()) {
	const Handle(Geom_Curve)& C = cr->Curve3D();
	if (!C.IsNull()) {
	  itpr.Initialize(TV->Points());
	  while (itpr.More()) {
	    const Handle(BRep_PointRepresentation)& pr = itpr.Value();
	    if (pr->IsPointOnCurve(C,L)) {
	      Controlp = C->Value(pr->Parameter());
	      Controlp.Transform(L.Transformation());
	      aD2=prep.SquareDistance(Controlp);
	      if (aD2 > Tol) {
		aNewTolerance=sqrt(aD2)+dd;
//		printf("(Vert,1) Tolerance=%15.10lg\n", aNewTolerance);
		if (aNewTolerance<aMaxTol)
		  TV->UpdateTolerance(aNewTolerance);
	      }
	    }
	    itpr.Next();
	  }
	  
	  TopAbs_Orientation orv = aVertex.Orientation();
	  if (orv == TopAbs_FORWARD || orv == TopAbs_REVERSED) {
	    const Handle(BRep_GCurve)& GC = *((Handle(BRep_GCurve)*)&cr);
	    
	    if (orv==TopAbs_FORWARD)
	      Controlp = C->Value(GC->First());
	    else 
	      Controlp = C->Value(GC->Last());

	    Controlp.Transform(L.Transformation());
	    aD2=prep.SquareDistance(Controlp);
	    
	    if (aD2 > Tol) {
	      aNewTolerance=sqrt(aD2)+dd;
//	      printf("(Vert,2) Tolerance=%15.10lg\n", aNewTolerance);
	      if (aNewTolerance<aMaxTol)
		TV->UpdateTolerance(aNewTolerance);
	    }
	  }
	}
      }
      itcr.Next();
    }
  }
}

//=======================================================================
//function : CheckFaceClosed2d
//purpose  : 
//=======================================================================

Standard_Boolean TopOpeBRepBuild_Tools::CheckFaceClosed2d(const TopoDS_Face& theFace)
{
  Standard_Boolean isClosed = Standard_True;
  TopExp_Explorer ex(theFace,TopAbs_WIRE);
  for (; ex.More() && isClosed; ex.Next()) {
    const TopoDS_Wire& aW = TopoDS::Wire(ex.Current());
    BRepCheck_Wire aWChk(aW);
    BRepCheck_Status aStatus = aWChk.Orientation(theFace);
    if (aStatus != BRepCheck_NoError)
      isClosed = Standard_False;
  }
  return isClosed;
}