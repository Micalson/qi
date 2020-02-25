// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepIntCurveSurface_Inter_HeaderFile
#define _BRepIntCurveSurface_Inter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _gp_Lin_HeaderFile
#include <gp_Lin.hxx>
#endif
#ifndef _GeomAdaptor_Curve_HeaderFile
#include <GeomAdaptor_Curve.hxx>
#endif
#ifndef _TopExp_Explorer_HeaderFile
#include <TopExp_Explorer.hxx>
#endif
#ifndef _BRepClass_FaceClassifier_HeaderFile
#include <BRepClass_FaceClassifier.hxx>
#endif
#ifndef _IntCurveSurface_HInter_HeaderFile
#include <IntCurveSurface_HInter.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_BRepTopAdaptor_TopolTool_HeaderFile
#include <Handle_BRepTopAdaptor_TopolTool.hxx>
#endif
#ifndef _Handle_BRepAdaptor_HSurface_HeaderFile
#include <Handle_BRepAdaptor_HSurface.hxx>
#endif
#ifndef _TopAbs_State_HeaderFile
#include <TopAbs_State.hxx>
#endif
#ifndef _IntCurveSurface_TransitionOnCurve_HeaderFile
#include <IntCurveSurface_TransitionOnCurve.hxx>
#endif
class BRepTopAdaptor_TopolTool;
class BRepAdaptor_HSurface;
class StdFail_NotDone;
class TopoDS_Shape;
class GeomAdaptor_Curve;
class gp_Lin;
class IntCurveSurface_IntersectionPoint;
class gp_Pnt;
class TopoDS_Face;


//! Computes the intersection between a face and a curve <br>
//! <br>
class BRepIntCurveSurface_Inter  {
public:

  DEFINE_STANDARD_ALLOC

  //! Empty constructor; <br>
  Standard_EXPORT   BRepIntCurveSurface_Inter();
  //! Load the Shape, the curve  and initialize the <br>
//!           tolerance used for the classification. <br>
  Standard_EXPORT     void Init(const TopoDS_Shape& Sh,const GeomAdaptor_Curve& Cu,const Standard_Real Tol) ;
  //! Load the Shape, the curve  and initialize the <br>
//!           tolerance used for the classification. <br>
  Standard_EXPORT     void Init(const TopoDS_Shape& Sh,const gp_Lin& L,const Standard_Real Tol) ;
  //! returns True if there is a current face. <br>
  Standard_EXPORT     Standard_Boolean More() const;
  //! Sets the explorer to the next face. <br>
  Standard_EXPORT     void Next() ;
  //! returns the current Intersection point. <br>
  Standard_EXPORT     IntCurveSurface_IntersectionPoint Point() const;
  //! returns the current geometric Point <br>
  Standard_EXPORT    const gp_Pnt& Pnt() const;
  //! returns the U parameter of the current point <br>
//!          on the current face. <br>
  Standard_EXPORT     Standard_Real U() const;
  //! returns the V parameter of the current point <br>
//!          on the current face. <br>
  Standard_EXPORT     Standard_Real V() const;
  //! returns the  parameter of the current point <br>
//!          on the curve. <br>
  Standard_EXPORT     Standard_Real W() const;
  //! returns the current state  (IN or ON) <br>
  Standard_EXPORT     TopAbs_State State() const;
  //! returns the transition of the line on the surface (IN or OUT or UNKNOWN) <br>
  Standard_EXPORT     IntCurveSurface_TransitionOnCurve Transition() const;
  //! returns the current face. <br>
  Standard_EXPORT    const TopoDS_Face& Face() const;





protected:

  //! Internal function <br>
  Standard_EXPORT     void Find() ;




private:



Standard_Boolean empty;
Standard_Boolean curveisaline;
Standard_Real tolerance;
gp_Lin line;
GeomAdaptor_Curve curve;
TopExp_Explorer explorer;
BRepClass_FaceClassifier classifier;
IntCurveSurface_HInter intcs;
Standard_Integer currentindex;
Standard_Integer currentnbpoints;
Handle_BRepTopAdaptor_TopolTool FastClass;
Handle_BRepAdaptor_HSurface SurfForFastClass;
TopAbs_State currentstate;
Standard_Real currentU;
Standard_Real currentV;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif