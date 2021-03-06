// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _LocOpe_PntFace_HeaderFile
#define _LocOpe_PntFace_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _gp_Pnt_HeaderFile
#include <gp_Pnt.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _TopAbs_Orientation_HeaderFile
#include <TopAbs_Orientation.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class gp_Pnt;
class TopoDS_Face;



class LocOpe_PntFace  {
public:

  DEFINE_STANDARD_ALLOC

  //! Empty constructor. Useful only for the list. <br>
  Standard_EXPORT   LocOpe_PntFace();
  
      LocOpe_PntFace(const gp_Pnt& P,const TopoDS_Face& F,const TopAbs_Orientation Or,const Standard_Real Param,const Standard_Real UPar,const Standard_Real VPar);
  
       const gp_Pnt& Pnt() const;
  
       const TopoDS_Face& Face() const;
  
        TopAbs_Orientation Orientation() const;
  
        TopAbs_Orientation& ChangeOrientation() ;
  
        Standard_Real Parameter() const;
  
        Standard_Real UParameter() const;
  
        Standard_Real VParameter() const;





protected:





private:



gp_Pnt myPnt;
TopoDS_Face myFace;
TopAbs_Orientation myOri;
Standard_Real myPar;
Standard_Real myUPar;
Standard_Real myVPar;


};


#include <LocOpe_PntFace.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
