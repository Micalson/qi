// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Vrml_NormalBinding_HeaderFile
#define _Vrml_NormalBinding_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Vrml_MaterialBindingAndNormalBinding_HeaderFile
#include <Vrml_MaterialBindingAndNormalBinding.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif


//! defines a NormalBinding node of VRML specifying properties of geometry <br>
//!          and its appearance. <br>
//!  This node specifies how the current normals are bound to shapes that follow in the scene <br>
//!  graph. Each shape node may interpret bindings differently. <br>
//!  The bindings for faces and vertices are meaningful only for shapes that are made from <br>
//!  faces and vertices. Similarly, the indexed bindings are only used by the shapes that allow <br>
//!  indexing. For bindings that require multiple normals, be sure to have at least as many <br>
//!  normals defined as are necessary; otherwise, errors will occur. <br>
class Vrml_NormalBinding  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Vrml_NormalBinding(const Vrml_MaterialBindingAndNormalBinding aValue);
  
  Standard_EXPORT   Vrml_NormalBinding();
  
  Standard_EXPORT     void SetValue(const Vrml_MaterialBindingAndNormalBinding aValue) ;
  
  Standard_EXPORT     Vrml_MaterialBindingAndNormalBinding Value() const;
  
  Standard_EXPORT     Standard_OStream& Print(Standard_OStream& anOStream) const;





protected:





private:



Vrml_MaterialBindingAndNormalBinding myValue;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif