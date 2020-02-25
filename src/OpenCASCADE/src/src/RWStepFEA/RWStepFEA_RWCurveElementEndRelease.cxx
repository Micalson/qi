// Created on: 2002-12-12
// Created by: data exchange team
// Copyright (c) 2002-2012 OPEN CASCADE SAS
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

// Generator:	ExpToCas (EXPRESS -> CASCADE/XSTEP Translator) V1.2

#include <RWStepFEA_RWCurveElementEndRelease.ixx>
#include <StepElement_HArray1OfCurveElementEndReleasePacket.hxx>
#include <StepElement_CurveElementEndReleasePacket.hxx>

//=======================================================================
//function : RWStepFEA_RWCurveElementEndRelease
//purpose  : 
//=======================================================================

RWStepFEA_RWCurveElementEndRelease::RWStepFEA_RWCurveElementEndRelease ()
{
}

//=======================================================================
//function : ReadStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndRelease::ReadStep (const Handle(StepData_StepReaderData)& data,
                                                   const Standard_Integer num,
                                                   Handle(Interface_Check)& ach,
                                                   const Handle(StepFEA_CurveElementEndRelease) &ent) const
{
  // Check number of parameters
  if ( ! data->CheckNbParams(num,2,ach,"curve_element_end_release") ) return;

  // Own fields of CurveElementEndRelease

  StepFEA_CurveElementEndCoordinateSystem aCoordinateSystem;
  data->ReadEntity (num, 1, "coordinate_system", ach, aCoordinateSystem);

  Handle(StepElement_HArray1OfCurveElementEndReleasePacket) aReleases;
  Standard_Integer sub2 = 0;
  if ( data->ReadSubList (num, 2, "releases", ach, sub2) ) {
    Standard_Integer nb0 = data->NbParams(sub2);
    aReleases = new StepElement_HArray1OfCurveElementEndReleasePacket (1, nb0);
    Standard_Integer num2 = sub2;
    for ( Standard_Integer i0=1; i0 <= nb0; i0++ ) {
      Handle(StepElement_CurveElementEndReleasePacket) anIt0;
      data->ReadEntity (num2, i0, "curve_element_end_release_packet", ach, STANDARD_TYPE(StepElement_CurveElementEndReleasePacket), anIt0);
      aReleases->SetValue(i0, anIt0);
    }
  }

  // Initialize entity
  ent->Init(aCoordinateSystem,
            aReleases);
}

//=======================================================================
//function : WriteStep
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndRelease::WriteStep (StepData_StepWriter& SW,
                                                    const Handle(StepFEA_CurveElementEndRelease) &ent) const
{

  // Own fields of CurveElementEndRelease

  SW.Send (ent->CoordinateSystem().Value());

  SW.OpenSub();
  for (Standard_Integer i1=1; i1 <= ent->Releases()->Length(); i1++ ) {
    Handle(StepElement_CurveElementEndReleasePacket) Var0 = ent->Releases()->Value(i1);
    SW.Send (Var0);
  }
  SW.CloseSub();
}

//=======================================================================
//function : Share
//purpose  : 
//=======================================================================

void RWStepFEA_RWCurveElementEndRelease::Share (const Handle(StepFEA_CurveElementEndRelease) &ent,
                                                Interface_EntityIterator& iter) const
{

  // Own fields of CurveElementEndRelease

  iter.AddItem (ent->CoordinateSystem().Value());

  for (Standard_Integer i2=1; i2 <= ent->Releases()->Length(); i2++ ) {
    Handle(StepElement_CurveElementEndReleasePacket) Var0 = ent->Releases()->Value(i2);
    iter.AddItem (Var0);
  }
}