// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _TopOpeBRepBuild_ShapeSet_HeaderFile
#define _TopOpeBRepBuild_ShapeSet_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopAbs_ShapeEnum_HeaderFile
#include <TopAbs_ShapeEnum.hxx>
#endif
#ifndef _TopOpeBRepTool_ShapeExplorer_HeaderFile
#include <TopOpeBRepTool_ShapeExplorer.hxx>
#endif
#ifndef _TopTools_ListOfShape_HeaderFile
#include <TopTools_ListOfShape.hxx>
#endif
#ifndef _TopTools_ListIteratorOfListOfShape_HeaderFile
#include <TopTools_ListIteratorOfListOfShape.hxx>
#endif
#ifndef _TopTools_IndexedDataMapOfShapeListOfShape_HeaderFile
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _TopTools_IndexedMapOfOrientedShape_HeaderFile
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class TopoDS_Shape;
class TopTools_ListOfShape;
class TCollection_AsciiString;



//! Auxiliary class providing an exploration of a set <br>
//! of shapes to build faces or solids. <br>
//! To build faces  : shapes are wires, elements are edges. <br>
//! To build solids : shapes are shells, elements are faces. <br>
//! The ShapeSet stores a list of shapes, a list of elements <br>
//! to start reconstructions, and a map to search neighbours. <br>
//! The map stores the connection  between elements through <br>
//! subshapes of type <SubShapeType> given in constructor. <br>
//! <SubShapeType> is : <br>
//!  - TopAbs_VERTEX to connect edges <br>
//!  - TopAbs_EDGE to connect faces <br>
//! <br>
//! Signature needed by the BlockBuilder : <br>
//!    InitStartElements(me : in out) <br>
//!    MoreStartElements(me) returns Boolean; <br>
//!    NextStartElement(me : in out); <br>
//!    StartElement(me) returns Shape; ---C++: return const & <br>
//!    InitNeighbours(me : in out; S : Shape); <br>
//!    MoreNeighbours(me) returns Boolean; <br>
//!    NextNeighbour(me : in out); <br>
//!    Neighbour(me) returns Shape; ---C++: return const & <br>
class TopOpeBRepBuild_ShapeSet  {
public:

  DEFINE_STANDARD_ALLOC

  //! Creates a ShapeSet  in order to build shapes connected <br>
//! by <SubShapeType>  shapes. <br>
//! <checkshape>:check (or not) the shapes, startelements, elements added. <br>
  Standard_EXPORT   TopOpeBRepBuild_ShapeSet(const TopAbs_ShapeEnum SubShapeType,const Standard_Boolean checkshape = Standard_True);
  
  Standard_EXPORT   virtual  void Delete() ;
Standard_EXPORT virtual ~TopOpeBRepBuild_ShapeSet(){Delete() ; }
  //! Adds <S> to the list of shapes. (wires or shells). <br>
  Standard_EXPORT   virtual  void AddShape(const TopoDS_Shape& S) ;
  //!  (S is a face or edge) <br>
//! Add S to the list of starting shapes used for reconstructions. <br>
//! apply AddElement(S). <br>
  Standard_EXPORT   virtual  void AddStartElement(const TopoDS_Shape& S) ;
  //!  for each subshape SE of S of type mySubShapeType <br>
//! - Add subshapes of S to the map of subshapes (mySubShapeMap) <br>
//! - Add S to the list of shape incident to subshapes of S. <br>
  Standard_EXPORT   virtual  void AddElement(const TopoDS_Shape& S) ;
  //! return a reference on myStartShapes <br>
  Standard_EXPORT    const TopTools_ListOfShape& StartElements() const;
  
  Standard_EXPORT     void InitShapes() ;
  
  Standard_EXPORT     Standard_Boolean MoreShapes() const;
  
  Standard_EXPORT     void NextShape() ;
  
  Standard_EXPORT    const TopoDS_Shape& Shape() const;
  
  Standard_EXPORT     void InitStartElements() ;
  
  Standard_EXPORT     Standard_Boolean MoreStartElements() const;
  
  Standard_EXPORT     void NextStartElement() ;
  
  Standard_EXPORT    const TopoDS_Shape& StartElement() const;
  
  Standard_EXPORT   virtual  void InitNeighbours(const TopoDS_Shape& S) ;
  
  Standard_EXPORT     Standard_Boolean MoreNeighbours() ;
  
  Standard_EXPORT     void NextNeighbour() ;
  
  Standard_EXPORT    const TopoDS_Shape& Neighbour() const;
  
  Standard_EXPORT     TopTools_ListOfShape& ChangeStartShapes() ;
  
  Standard_EXPORT     Standard_Boolean IsStartElement(const TopoDS_Shape& S) const;
  
  Standard_EXPORT     Standard_Boolean IsElement(const TopoDS_Shape& S) const;
  
  Standard_EXPORT     Standard_Boolean IsShape(const TopoDS_Shape& S) const;
  
  Standard_EXPORT     Standard_Integer NStartElement(const TopoDS_Shape& S) const;
  
  Standard_EXPORT     Standard_Integer NElement(const TopoDS_Shape& S) const;
  
  Standard_EXPORT     Standard_Integer NShape(const TopoDS_Shape& S) const;
  //! Build the list of neighbour shapes of myCurrentShape <br>
//! (neighbour shapes and myCurrentShapes are of type t) <br>
//! Initialize myIncidentShapesIter on neighbour shapes. <br>
  Standard_EXPORT   virtual  void FindNeighbours() ;
  
  Standard_EXPORT   virtual const TopTools_ListOfShape& MakeNeighboursList(const TopoDS_Shape& E,const TopoDS_Shape& V) ;
  
  Standard_EXPORT     Standard_Integer MaxNumberSubShape(const TopoDS_Shape& Shape) ;
  
  Standard_EXPORT     void CheckShape(const Standard_Boolean checkshape) ;
  
  Standard_EXPORT     Standard_Boolean CheckShape() const;
  
  Standard_EXPORT     Standard_Boolean CheckShape(const TopoDS_Shape& S,const Standard_Boolean checkgeom = Standard_False) ;
  
  Standard_EXPORT     void DumpName(Standard_OStream& OS,const TCollection_AsciiString& str) const;
  
  Standard_EXPORT     void DumpCheck(Standard_OStream& OS,const TCollection_AsciiString& str,const TopoDS_Shape& S,const Standard_Boolean chk) const;
  
  Standard_EXPORT   virtual  void DumpSS() ;
  
  Standard_EXPORT   virtual  void DumpBB() ;
  
  Standard_EXPORT     void DEBName(const TCollection_AsciiString& N) ;
  
  Standard_EXPORT    const TCollection_AsciiString& DEBName() const;
  
  Standard_EXPORT     void DEBNumber(const Standard_Integer I) ;
  
  Standard_EXPORT     Standard_Integer DEBNumber() const;
  
  Standard_EXPORT   virtual  TCollection_AsciiString SName(const TopoDS_Shape& S,const TCollection_AsciiString& sb = "",const TCollection_AsciiString& sa = "") const;
  
  Standard_EXPORT   virtual  TCollection_AsciiString SNameori(const TopoDS_Shape& S,const TCollection_AsciiString& sb = "",const TCollection_AsciiString& sa = "") const;
  
  Standard_EXPORT   virtual  TCollection_AsciiString SName(const TopTools_ListOfShape& S,const TCollection_AsciiString& sb = "",const TCollection_AsciiString& sa = "") const;
  
  Standard_EXPORT   virtual  TCollection_AsciiString SNameori(const TopTools_ListOfShape& S,const TCollection_AsciiString& sb = "",const TCollection_AsciiString& sa = "") const;





protected:

  
  Standard_EXPORT     void ProcessAddShape(const TopoDS_Shape& S) ;
  
  Standard_EXPORT     void ProcessAddStartElement(const TopoDS_Shape& S) ;
  
  Standard_EXPORT     void ProcessAddElement(const TopoDS_Shape& S) ;


TopAbs_ShapeEnum myShapeType;
TopAbs_ShapeEnum mySubShapeType;
TopOpeBRepTool_ShapeExplorer mySubShapeExplorer;
TopTools_ListOfShape myStartShapes;
TopTools_ListIteratorOfListOfShape myStartShapesIter;
TopTools_IndexedDataMapOfShapeListOfShape mySubShapeMap;
TopTools_ListIteratorOfListOfShape myIncidentShapesIter;
TopTools_ListOfShape myShapes;
TopTools_ListIteratorOfListOfShape myShapesIter;
TopoDS_Shape myCurrentShape;
TopTools_ListOfShape myCurrentShapeNeighbours;
Standard_Integer myDEBNumber;
TCollection_AsciiString myDEBName;
TopTools_IndexedMapOfOrientedShape myOMSS;
TopTools_IndexedMapOfOrientedShape myOMES;
TopTools_IndexedMapOfOrientedShape myOMSH;
Standard_Boolean myCheckShape;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif