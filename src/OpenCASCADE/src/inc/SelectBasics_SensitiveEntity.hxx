// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectBasics_SensitiveEntity_HeaderFile
#define _SelectBasics_SensitiveEntity_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_SelectBasics_SensitiveEntity_HeaderFile
#include <Handle_SelectBasics_SensitiveEntity.hxx>
#endif

#ifndef _Handle_SelectBasics_EntityOwner_HeaderFile
#include <Handle_SelectBasics_EntityOwner.hxx>
#endif
#ifndef _Standard_ShortReal_HeaderFile
#include <Standard_ShortReal.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class SelectBasics_EntityOwner;
class SelectBasics_ListOfBox2d;
class TColgp_Array1OfPnt2d;
class Bnd_Box2d;


//! root class ; the inheriting classes will be able to give <br>
//!          sensitive Areas for the dynamic selection algorithms <br>
class SelectBasics_SensitiveEntity : public MMgt_TShared {

public:

  
  Standard_EXPORT   virtual  void Set(const Handle(SelectBasics_EntityOwner)& TheOwnerId) ;
  
  Standard_EXPORT    const Handle_SelectBasics_EntityOwner& OwnerId() const;
  //! to be implemented specifically by each type of <br>
//!          sensitive  primitive . <br>
//! <br>
  Standard_EXPORT   virtual  void Areas(SelectBasics_ListOfBox2d& aresult)  = 0;
  //! returns True if the object is very close to the <br>
//!          sensitive areas it gave to the selector... <br>
//!          returns the minimum distance found if no match; <br>
//! <br>
//!          to be implemented specifically by each type of <br>
//!          sensitive  primitive . <br>
  Standard_EXPORT   virtual  Standard_Boolean Matches(const Standard_Real X,const Standard_Real Y,const Standard_Real aTol,Standard_Real& DMin)  = 0;
  //! returns True if the box (Xmin,YMin)------(Xmax,Ymax) <br>
//!          contains the SensitiveEntity. <br>
//!          Necessary for selection using elastic boxes,or segments. <br>
  Standard_EXPORT   virtual  Standard_Boolean Matches(const Standard_Real XMin,const Standard_Real YMin,const Standard_Real XMax,const Standard_Real YMax,const Standard_Real aTol)  = 0;
  //! returns True if the polyline xi,yi <br>
//!          contains the SensitiveEntity. <br>
//!          Necessary for selection using polyline selection <br>
  Standard_EXPORT   virtual  Standard_Boolean Matches(const TColgp_Array1OfPnt2d& Polyline,const Bnd_Box2d& aBox,const Standard_Real aTol)  = 0;
  
  Standard_EXPORT   virtual  Standard_Boolean NeedsConversion() const = 0;
  //! returns True if able to give 3D information <br>
//!          (Depth,...). See Select3D <br>
  Standard_EXPORT   virtual  Standard_Boolean Is3D() const = 0;
  //!  Sort Selected entities according to depth... <br>
  Standard_EXPORT   virtual  Standard_Real Depth() const;
  //! returns the max number of boxes the entity is able to give <br>
//!          at a time <br>
  Standard_EXPORT   virtual  Standard_Integer MaxBoxes() const = 0;
  
        void SetSensitivityFactor(const Standard_ShortReal aFactor) ;
  //! allows a better sensitivity for <br>
//!          a specific entity in selection algorithms <br>
//!          useful for small sized entities. <br>
        Standard_ShortReal SensitivityFactor() const;




  DEFINE_STANDARD_RTTI(SelectBasics_SensitiveEntity)

protected:

  
  Standard_EXPORT   SelectBasics_SensitiveEntity(const Handle(SelectBasics_EntityOwner)& OwnerId,const Standard_ShortReal aSensitivityFactor = 1);

Handle_SelectBasics_EntityOwner myOwnerId;


private: 


Standard_ShortReal mySFactor;


};


#include <SelectBasics_SensitiveEntity.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif