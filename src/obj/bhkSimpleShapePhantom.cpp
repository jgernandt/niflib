/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSimpleShapePhantom.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSimpleShapePhantom::TYPE("bhkSimpleShapePhantom", &BHK_SIMPLE_SHAPE_PHANTOM_PARENT::TypeConst() );

bhkSimpleShapePhantom::bhkSimpleShapePhantom() BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT {}

bhkSimpleShapePhantom::~bhkSimpleShapePhantom() {}

void bhkSimpleShapePhantom::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkSimpleShapePhantom::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkSimpleShapePhantom::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSimpleShapePhantom::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkSimpleShapePhantom::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSimpleShapePhantom::GetType() const {
	return TYPE;
};

