/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPointLight.h"

//Definition of TYPE constant
const Type NiPointLight::TYPE("NiPointLight", &NI_POINT_LIGHT_PARENT::TYPE );

NiPointLight::NiPointLight() NI_POINT_LIGHT_CONSTRUCT {}

NiPointLight::~NiPointLight() {}

void NiPointLight::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  NI_POINT_LIGHT_READ
}

void NiPointLight::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  NI_POINT_LIGHT_WRITE
}

string NiPointLight::asString( bool verbose ) const {
  NI_POINT_LIGHT_STRING
}

void NiPointLight::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  NI_POINT_LIGHT_FIXLINKS
}

const Type & NiPointLight::GetType() const {
  return TYPE;
};
