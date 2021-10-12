/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSDynamicTriShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSDynamicTriShape::TYPE("BSDynamicTriShape", &BSTriShape::TYPE );

BSDynamicTriShape::BSDynamicTriShape() : dynamicDataSize((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSDynamicTriShape::~BSDynamicTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSDynamicTriShape::GetType() const {
	return TYPE;
}

NiObject * BSDynamicTriShape::Create() {
	return new BSDynamicTriShape;
}

void BSDynamicTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::Read( in, link_stack, info );
	NifStream( dynamicDataSize, in, info );
	vertices.resize(dynamicDataSize / 16);
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSDynamicTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::Write( out, link_map, missing_link_stack, info );
	dynamicDataSize = dynamicDataSizeCalc(info);
	NifStream( dynamicDataSize, out, info );
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSDynamicTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSTriShape::asString();
	out << "  Dynamic Data Size:  " << dynamicDataSize << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSDynamicTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSTriShape::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSDynamicTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSTriShape::GetRefs();
	return refs;
}

std::list<NiObject *> BSDynamicTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSTriShape::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned int Niflib::BSDynamicTriShape::dataSizeCalc(const Niflib::NifInfo& info) const
{
	return 0;
}

unsigned short Niflib::BSDynamicTriShape::numVerticesCalc(const Niflib::NifInfo& info) const
{
	if (vertices.size() > std::numeric_limits<unsigned short>::max())
		throw std::overflow_error(name + ": Vertices exceeds maximum allowed size");

	return static_cast<unsigned short>(vertices.size());
}

unsigned int Niflib::BSDynamicTriShape::dynamicDataSizeCalc(const Niflib::NifInfo& info) const
{
	return 16 * numVerticesCalc(info);
}

//--END CUSTOM CODE--//
