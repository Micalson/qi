// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Contap_SequenceOfPathPointOfTheSearchOfContour_HeaderFile
#define _Contap_SequenceOfPathPointOfTheSearchOfContour_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TCollection_BaseSequence_HeaderFile
#include <TCollection_BaseSequence.hxx>
#endif
#ifndef _Handle_Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour_HeaderFile
#include <Handle_Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_NoSuchObject;
class Standard_OutOfRange;
class Contap_ThePathPointOfTheSearchOfContour;
class Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour;



class Contap_SequenceOfPathPointOfTheSearchOfContour  : public TCollection_BaseSequence {
public:

  DEFINE_STANDARD_ALLOC

  
      Contap_SequenceOfPathPointOfTheSearchOfContour();
  
  Standard_EXPORT     void Clear() ;
~Contap_SequenceOfPathPointOfTheSearchOfContour()
{
  Clear();
}
  
  Standard_EXPORT    const Contap_SequenceOfPathPointOfTheSearchOfContour& Assign(const Contap_SequenceOfPathPointOfTheSearchOfContour& Other) ;
   const Contap_SequenceOfPathPointOfTheSearchOfContour& operator =(const Contap_SequenceOfPathPointOfTheSearchOfContour& Other) 
{
  return Assign(Other);
}
  
  Standard_EXPORT     void Append(const Contap_ThePathPointOfTheSearchOfContour& T) ;
  
        void Append(Contap_SequenceOfPathPointOfTheSearchOfContour& S) ;
  
  Standard_EXPORT     void Prepend(const Contap_ThePathPointOfTheSearchOfContour& T) ;
  
        void Prepend(Contap_SequenceOfPathPointOfTheSearchOfContour& S) ;
  
        void InsertBefore(const Standard_Integer Index,const Contap_ThePathPointOfTheSearchOfContour& T) ;
  
        void InsertBefore(const Standard_Integer Index,Contap_SequenceOfPathPointOfTheSearchOfContour& S) ;
  
  Standard_EXPORT     void InsertAfter(const Standard_Integer Index,const Contap_ThePathPointOfTheSearchOfContour& T) ;
  
        void InsertAfter(const Standard_Integer Index,Contap_SequenceOfPathPointOfTheSearchOfContour& S) ;
  
  Standard_EXPORT    const Contap_ThePathPointOfTheSearchOfContour& First() const;
  
  Standard_EXPORT    const Contap_ThePathPointOfTheSearchOfContour& Last() const;
  
        void Split(const Standard_Integer Index,Contap_SequenceOfPathPointOfTheSearchOfContour& Sub) ;
  
  Standard_EXPORT    const Contap_ThePathPointOfTheSearchOfContour& Value(const Standard_Integer Index) const;
   const Contap_ThePathPointOfTheSearchOfContour& operator()(const Standard_Integer Index) const
{
  return Value(Index);
}
  
  Standard_EXPORT     void SetValue(const Standard_Integer Index,const Contap_ThePathPointOfTheSearchOfContour& I) ;
  
  Standard_EXPORT     Contap_ThePathPointOfTheSearchOfContour& ChangeValue(const Standard_Integer Index) ;
    Contap_ThePathPointOfTheSearchOfContour& operator()(const Standard_Integer Index) 
{
  return ChangeValue(Index);
}
  
  Standard_EXPORT     void Remove(const Standard_Integer Index) ;
  
  Standard_EXPORT     void Remove(const Standard_Integer FromIndex,const Standard_Integer ToIndex) ;





protected:





private:

  
  Standard_EXPORT   Contap_SequenceOfPathPointOfTheSearchOfContour(const Contap_SequenceOfPathPointOfTheSearchOfContour& Other);




};

#define SeqItem Contap_ThePathPointOfTheSearchOfContour
#define SeqItem_hxx <Contap_ThePathPointOfTheSearchOfContour.hxx>
#define TCollection_SequenceNode Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour
#define TCollection_SequenceNode_hxx <Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour.hxx>
#define Handle_TCollection_SequenceNode Handle_Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour
#define TCollection_SequenceNode_Type_() Contap_SequenceNodeOfSequenceOfPathPointOfTheSearchOfContour_Type_()
#define TCollection_Sequence Contap_SequenceOfPathPointOfTheSearchOfContour
#define TCollection_Sequence_hxx <Contap_SequenceOfPathPointOfTheSearchOfContour.hxx>

#include <TCollection_Sequence.lxx>

#undef SeqItem
#undef SeqItem_hxx
#undef TCollection_SequenceNode
#undef TCollection_SequenceNode_hxx
#undef Handle_TCollection_SequenceNode
#undef TCollection_SequenceNode_Type_
#undef TCollection_Sequence
#undef TCollection_Sequence_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif