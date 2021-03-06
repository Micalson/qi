// Copyright (c) 1999-2012 OPEN CASCADE SAS
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

#include <MDataXtd_ShapeRetrievalDriver.ixx>
#include <PDataXtd_Shape.hxx>
#include <TDataXtd_Shape.hxx>
#include <CDM_MessageDriver.hxx>

MDataXtd_ShapeRetrievalDriver::MDataXtd_ShapeRetrievalDriver(const Handle(CDM_MessageDriver)& theMsgDriver):MDF_ARDriver(theMsgDriver)
{}

Standard_Integer MDataXtd_ShapeRetrievalDriver::VersionNumber() const
{ return 0; }

Handle(Standard_Type) MDataXtd_ShapeRetrievalDriver::SourceType() const
{ return STANDARD_TYPE(PDataXtd_Shape); }

Handle(TDF_Attribute) MDataXtd_ShapeRetrievalDriver::NewEmpty() const
{ return new TDataXtd_Shape; }

void MDataXtd_ShapeRetrievalDriver::Paste(const Handle(PDF_Attribute)& Source,const Handle(TDF_Attribute)& Target,const Handle(MDF_RRelocationTable)& RelocTable) const
{
}

