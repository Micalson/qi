// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Vrml_Info_HeaderFile
#define _Vrml_Info_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _Standard_OStream_HeaderFile
#include <Standard_OStream.hxx>
#endif
class TCollection_AsciiString;


//!  defines a Info node of VRML specifying properties of geometry <br>
//!          and its appearance. <br>
//!  It  is  used  to  store  information  in  the  scene  graph, <br>
//!  Typically  for  application-specific  purposes,  copyright  messages, <br>
//!  or  other  strings. <br>
class Vrml_Info  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   Vrml_Info(const TCollection_AsciiString& aString = "<Undefined info>");
  
  Standard_EXPORT     void SetString(const TCollection_AsciiString& aString) ;
  
  Standard_EXPORT     TCollection_AsciiString String() const;
  
  Standard_EXPORT     Standard_OStream& Print(Standard_OStream& anOStream) const;





protected:





private:



TCollection_AsciiString myString;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif