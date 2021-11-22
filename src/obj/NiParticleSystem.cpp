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
#include "../../include/obj/NiParticleSystem.h"
#include "../../include/gen/BSVertexDesc.h"
#include "../../include/obj/NiPSysData.h"
#include "../../include/obj/NiPSysModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticleSystem::TYPE("NiParticleSystem", &NiParticles::TYPE );

NiParticleSystem::NiParticleSystem() : farBegin((unsigned short)0), farEnd((unsigned short)0), nearBegin((unsigned short)0), nearEnd((unsigned short)0), data(NULL), worldSpace(1), numModifiers((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticleSystem::~NiParticleSystem() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticleSystem::GetType() const {
	return TYPE;
}

NiObject * NiParticleSystem::Create() {
	return new NiParticleSystem;
}

void NiParticleSystem::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiParticles::Read( in, link_stack, info );
	if ( (info.userVersion2 >= 100) ) {
		NifStream( vertexDesc.bitfield, in, info );
	};
	if ( (info.userVersion2 >= 83) ) {
		NifStream( farBegin, in, info );
		NifStream( farEnd, in, info );
		NifStream( nearBegin, in, info );
		NifStream( nearEnd, in, info );
	};
	if ( (info.userVersion2 >= 100) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( worldSpace, in, info );
		NifStream( numModifiers, in, info );
		modifiers.resize(numModifiers);
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleSystem::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticles::Write( out, link_map, missing_link_stack, info );
	numModifiers = (unsigned int)(modifiers.size());
	if ( (info.userVersion2 >= 100) ) {
		NifStream( vertexDesc.bitfield, out, info );
	};
	if ( (info.userVersion2 >= 83) ) {
		NifStream( farBegin, out, info );
		NifStream( farEnd, out, info );
		NifStream( nearBegin, out, info );
		NifStream( nearEnd, out, info );
	};
	if ( (info.userVersion2 >= 100) ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*data), out );
		} else {
			if ( data != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(data) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( data );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( worldSpace, out, info );
		NifStream( numModifiers, out, info );
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			if ( info.version < VER_3_3_0_13 ) {
				WritePtr32( &(*modifiers[i2]), out );
			} else {
				if ( modifiers[i2] != NULL ) {
					map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(modifiers[i2]) );
					if (it != link_map.end()) {
						NifStream( it->second, out, info );
						missing_link_stack.push_back( NULL );
					} else {
						NifStream( 0xFFFFFFFF, out, info );
						missing_link_stack.push_back( modifiers[i2] );
					}
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( NULL );
				}
			}
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticleSystem::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticles::asString();
	numModifiers = (unsigned int)(modifiers.size());
	out << "  Bitfield:  " << vertexDesc.bitfield << endl;
	out << "  Far Begin:  " << farBegin << endl;
	out << "  Far End:  " << farEnd << endl;
	out << "  Near Begin:  " << nearBegin << endl;
	out << "  Near End:  " << nearEnd << endl;
	out << "  Data:  " << data << endl;
	out << "  World Space:  " << worldSpace << endl;
	out << "  Num Modifiers:  " << numModifiers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < modifiers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Modifiers[" << i1 << "]:  " << modifiers[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticleSystem::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticles::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( (info.userVersion2 >= 100) ) {
		data = FixLink<NiPSysData>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x0A010000 ) {
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			modifiers[i2] = FixLink<NiPSysModifier>( objects, link_stack, missing_link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticleSystem::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	for (unsigned int i1 = 0; i1 < modifiers.size(); i1++) {
		if ( modifiers[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(modifiers[i1]));
	};
	return refs;
}

std::list<NiObject *> NiParticleSystem::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiParticles::GetPtrs();
	for (unsigned int i1 = 0; i1 < modifiers.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

BSVertexDesc& Niflib::NiParticleSystem::GetVertexDescriptor()
{
	return vertexDesc;
}

const BSVertexDesc& Niflib::NiParticleSystem::GetVertexDescriptor() const
{
	return vertexDesc;
}

#include <cassert>

//UV2 83 and 100 store their data in different places. 
//Since we don't know what we're supposed to be, we assign to both and read from whichever is assigned.
Ref<NiPSysData> Niflib::NiParticleSystem::GetData() const
{
	//When we are first loaded, at most one of our datas will be assigned. We don't know which one.
	//If they are both something but different, someone assigned through NiGeometry::SetData. Let's treat this as a logic error.
	assert(data == NiGeometry::data || !data || !NiGeometry::data);
	return data ? data : DynamicCast<NiPSysData>(NiGeometry::data);
}

void Niflib::NiParticleSystem::SetData(const Ref<NiPSysData>& obj)
{
	data = obj;
	NiGeometry::data = obj;
}

bool Niflib::NiParticleSystem::GetWorldSpace() const
{
	return worldSpace;
}

void Niflib::NiParticleSystem::SetWorldSpace(bool b)
{
	worldSpace = b;
}

void Niflib::NiParticleSystem::AddModifier(const Ref<NiPSysModifier>& mod)
{
	//Insert at back
	if (mod) {
		auto target = mod->GetTarget();
		if (target != this) {
			if (target)
				throw runtime_error("NiParticleSystem tried to add a modifier which is targeting another NiParticleSystem.");

			mod->SetTarget(this);
			modifiers.push_back(mod);
		}
	}
}

void Niflib::NiParticleSystem::RemoveModifier(NiPSysModifier* mod)
{
	//Find and erase mod
	if (mod) {
		auto it = std::find(modifiers.begin(), modifiers.end(), mod);
		if (it != modifiers.end()) {
			modifiers.erase(it);
			mod->SetTarget(nullptr);
		}
	}
}

void Niflib::NiParticleSystem::ClearModifiers()
{
	for (auto&& mod : modifiers) {
		if (mod)
			mod->SetTarget(nullptr);
	}
	modifiers.clear();
}

const vector<Ref<NiPSysModifier>>& Niflib::NiParticleSystem::GetModifiers() const
{
	return modifiers;
}

//--END CUSTOM CODE--//
