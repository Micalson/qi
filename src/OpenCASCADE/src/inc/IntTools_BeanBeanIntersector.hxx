// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IntTools_BeanBeanIntersector_HeaderFile
#define _IntTools_BeanBeanIntersector_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BRepAdaptor_Curve_HeaderFile
#include <BRepAdaptor_Curve.hxx>
#endif
#ifndef _Handle_Geom_Curve_HeaderFile
#include <Handle_Geom_Curve.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _GeomAPI_ProjectPointOnCurve_HeaderFile
#include <GeomAPI_ProjectPointOnCurve.hxx>
#endif
#ifndef _IntTools_MarkedRangeSet_HeaderFile
#include <IntTools_MarkedRangeSet.hxx>
#endif
#ifndef _IntTools_SequenceOfRanges_HeaderFile
#include <IntTools_SequenceOfRanges.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Geom_Curve;
class TopoDS_Edge;
class BRepAdaptor_Curve;
class IntTools_SequenceOfRanges;
class IntTools_Range;


//! The class BeanBeanIntersector computes ranges of parameters on <br>
//!         the curve of a first bean (part of edge) that bounds the parts of bean which <br>
//!	        are on the other bean according to tolerance of edges. <br>
class IntTools_BeanBeanIntersector  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   IntTools_BeanBeanIntersector();
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT   IntTools_BeanBeanIntersector(const TopoDS_Edge& theEdge1,const TopoDS_Edge& theEdge2);
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT   IntTools_BeanBeanIntersector(const BRepAdaptor_Curve& theCurve1,const BRepAdaptor_Curve& theCurve2,const Standard_Real theBeanTolerance1,const Standard_Real theBeanTolerance2);
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT   IntTools_BeanBeanIntersector(const BRepAdaptor_Curve& theCurve1,const BRepAdaptor_Curve& theCurve2,const Standard_Real theFirstParOnCurve1,const Standard_Real theLastParOnCurve1,const Standard_Real theFirstParOnCurve2,const Standard_Real theLastParOnCurve2,const Standard_Real theBeanTolerance1,const Standard_Real theBeanTolerance2);
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT     void Init(const TopoDS_Edge& theEdge1,const TopoDS_Edge& theEdge2) ;
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT     void Init(const BRepAdaptor_Curve& theCurve1,const BRepAdaptor_Curve& theCurve2,const Standard_Real theBeanTolerance1,const Standard_Real theBeanTolerance2) ;
  
//! Initializes the algorithm <br>
//! <br>
  Standard_EXPORT     void Init(const BRepAdaptor_Curve& theCurve1,const BRepAdaptor_Curve& theCurve2,const Standard_Real theFirstParOnCurve1,const Standard_Real theLastParOnCurve1,const Standard_Real theFirstParOnCurve2,const Standard_Real theLastParOnCurve2,const Standard_Real theBeanTolerance1,const Standard_Real theBeanTolerance2) ;
  
//! Sets bounding parameters for first bean if IsFirstBean is true <br>
//! and for second bean if IsFirstBean is false <br>
//! <br>
  Standard_EXPORT     void SetBeanParameters(const Standard_Boolean IsFirstBean,const Standard_Real theFirstParOnCurve,const Standard_Real theLastParOnCurve) ;
  
//! Launches the algorithm <br>
//! <br>
  Standard_EXPORT     void Perform() ;
  
//! Returns true if the computations was successfull <br>
//! otherwise returns false <br>
        Standard_Boolean IsDone() const;
  
  Standard_EXPORT    const IntTools_SequenceOfRanges& Result() const;
  
  Standard_EXPORT     void Result(IntTools_SequenceOfRanges& theResults) const;





protected:





private:

  
  Standard_EXPORT     void ComputeRoughIntersection() ;
  
  Standard_EXPORT     Standard_Boolean FastComputeIntersection() ;
  
  Standard_EXPORT     void ComputeUsingExtrema(const IntTools_Range& theRange2) ;
  
  Standard_EXPORT     void ComputeNearRangeBoundaries(const IntTools_Range& theRange2) ;
  
  Standard_EXPORT     void ComputeRangeFromStartPoint(const Standard_Boolean ToIncreaseParameter,const Standard_Real theParameter,const Standard_Integer theIndex,const Standard_Real theParameter2,const IntTools_Range& theRange2) ;
  
  Standard_EXPORT     Standard_Real Distance(const Standard_Real theArg,Standard_Real& theArgOnOtherBean) ;


BRepAdaptor_Curve myCurve1;
BRepAdaptor_Curve myCurve2;
Handle_Geom_Curve myTrsfCurve1;
Handle_Geom_Curve myTrsfCurve2;
Standard_Real myFirstParameter1;
Standard_Real myLastParameter1;
Standard_Real myFirstParameter2;
Standard_Real myLastParameter2;
Standard_Real myBeanTolerance1;
Standard_Real myBeanTolerance2;
Standard_Real myCurveResolution1;
Standard_Real myCriteria;
GeomAPI_ProjectPointOnCurve myProjector;
IntTools_MarkedRangeSet myRangeManager;
Standard_Real myDeflection;
IntTools_SequenceOfRanges myResults;
Standard_Boolean myIsDone;


};


#include <IntTools_BeanBeanIntersector.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif