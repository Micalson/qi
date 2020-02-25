// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_Array1OfCurveElementEndRelease_HeaderFile
#define _StepFEA_Array1OfCurveElementEndRelease_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_StepFEA_CurveElementEndRelease_HeaderFile
#include <Handle_StepFEA_CurveElementEndRelease.hxx>
#endif
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class StepFEA_CurveElementEndRelease;



class StepFEA_Array1OfCurveElementEndRelease  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   StepFEA_Array1OfCurveElementEndRelease(const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT   StepFEA_Array1OfCurveElementEndRelease(const Handle(StepFEA_CurveElementEndRelease)& Item,const Standard_Integer Low,const Standard_Integer Up);
  
  Standard_EXPORT     void Init(const Handle(StepFEA_CurveElementEndRelease)& V) ;
  
  Standard_EXPORT     void Destroy() ;
~StepFEA_Array1OfCurveElementEndRelease()
{
  Destroy();
}
  
        Standard_Boolean IsAllocated() const;
  
  Standard_EXPORT    const StepFEA_Array1OfCurveElementEndRelease& Assign(const StepFEA_Array1OfCurveElementEndRelease& Other) ;
   const StepFEA_Array1OfCurveElementEndRelease& operator =(const StepFEA_Array1OfCurveElementEndRelease& Other) 
{
  return Assign(Other);
}
  
        Standard_Integer Length() const;
  
        Standard_Integer Lower() const;
  
        Standard_Integer Upper() const;
  
        void SetValue(const Standard_Integer Index,const Handle(StepFEA_CurveElementEndRelease)& Value) ;
  
       const Handle_StepFEA_CurveElementEndRelease& Value(const Standard_Integer Index) const;
     const Handle_StepFEA_CurveElementEndRelease& operator ()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
        Handle_StepFEA_CurveElementEndRelease& ChangeValue(const Standard_Integer Index) ;
      Handle_StepFEA_CurveElementEndRelease& operator ()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}





protected:





private:

  
  Standard_EXPORT   StepFEA_Array1OfCurveElementEndRelease(const StepFEA_Array1OfCurveElementEndRelease& AnArray);


Standard_Integer myLowerBound;
Standard_Integer myUpperBound;
Standard_Address myStart;
Standard_Boolean isAllocated;


};

#define Array1Item Handle_StepFEA_CurveElementEndRelease
#define Array1Item_hxx <StepFEA_CurveElementEndRelease.hxx>
#define TCollection_Array1 StepFEA_Array1OfCurveElementEndRelease
#define TCollection_Array1_hxx <StepFEA_Array1OfCurveElementEndRelease.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif