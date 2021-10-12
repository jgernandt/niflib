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
#include "../../include/obj/NiPSysData.h"
#include "../../include/gen/NiParticleInfo.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NiRotatingParticlesData::TYPE );

NiPSysData::NiPSysData() : hasRotationSpeeds(false), numAddedParticles((unsigned short)0), addedParticlesBase((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysData::~NiPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysData::GetType() const {
	return TYPE;
}

NiObject * NiPSysData::Create() {
	return new NiPSysData;
}

void NiPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Read( in, link_stack, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) {
		particleInfo.resize(numVertices);
		for (unsigned int i2 = 0; i2 < particleInfo.size(); i2++) {
			NifStream( particleInfo[i2].velocity, in, info );
			if ( info.version <= 0x0A040001 ) {
				NifStream( particleInfo[i2].rotationAxis, in, info );
			};
			NifStream( particleInfo[i2].age, in, info );
			NifStream( particleInfo[i2].lifeSpan, in, info );
			NifStream( particleInfo[i2].lastUpdate, in, info );
			NifStream( particleInfo[i2].spawnGeneration, in, info );
			NifStream( particleInfo[i2].code, in, info );
		};
	};
	if ( (info.userVersion2 == 155) ) {
		NifStream( unknownVector, in, info );
	};
	if ( info.version >= 0x14000002 ) {
		NifStream( hasRotationSpeeds, in, info );
	};
	if ( ( info.version >= 0x14000002 ) && ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) ) {
		if ( hasRotationSpeeds ) {
			rotationSpeeds.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationSpeeds.size(); i3++) {
				NifStream( rotationSpeeds[i3], in, info );
			};
		};
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) {
		NifStream( numAddedParticles, in, info );
		NifStream( addedParticlesBase, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::Write( out, link_map, missing_link_stack, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) {
		for (unsigned int i2 = 0; i2 < particleInfo.size(); i2++) {
			NifStream( particleInfo[i2].velocity, out, info );
			if ( info.version <= 0x0A040001 ) {
				NifStream( particleInfo[i2].rotationAxis, out, info );
			};
			NifStream( particleInfo[i2].age, out, info );
			NifStream( particleInfo[i2].lifeSpan, out, info );
			NifStream( particleInfo[i2].lastUpdate, out, info );
			NifStream( particleInfo[i2].spawnGeneration, out, info );
			NifStream( particleInfo[i2].code, out, info );
		};
	};
	if ( (info.userVersion2 == 155) ) {
		NifStream( unknownVector, out, info );
	};
	if ( info.version >= 0x14000002 ) {
		NifStream( hasRotationSpeeds, out, info );
	};
	if ( ( info.version >= 0x14000002 ) && ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) ) {
		if ( hasRotationSpeeds ) {
			for (unsigned int i3 = 0; i3 < rotationSpeeds.size(); i3++) {
				NifStream( rotationSpeeds[i3], out, info );
			};
		};
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion2 > 0))) ) {
		NifStream( numAddedParticles, out, info );
		NifStream( addedParticlesBase, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiRotatingParticlesData::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particleInfo.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Velocity:  " << particleInfo[i1].velocity << endl;
		out << "    Rotation Axis:  " << particleInfo[i1].rotationAxis << endl;
		out << "    Age:  " << particleInfo[i1].age << endl;
		out << "    Life Span:  " << particleInfo[i1].lifeSpan << endl;
		out << "    Last Update:  " << particleInfo[i1].lastUpdate << endl;
		out << "    Spawn Generation:  " << particleInfo[i1].spawnGeneration << endl;
		out << "    Code:  " << particleInfo[i1].code << endl;
	};
	out << "  Unknown Vector:  " << unknownVector << endl;
	out << "  Has Rotation Speeds:  " << hasRotationSpeeds << endl;
	if ( hasRotationSpeeds ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationSpeeds.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Speeds[" << i2 << "]:  " << rotationSpeeds[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Added Particles:  " << numAddedParticles << endl;
	out << "  Added Particles Base:  " << addedParticlesBase << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiRotatingParticlesData::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiRotatingParticlesData::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiRotatingParticlesData::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short Niflib::NiPSysData::GetBSMaxVertices() const
{
	return bsMaxVertices;
}

void Niflib::NiPSysData::SetBSMaxVertices(unsigned short i)
{
	bsMaxVertices = i;
}

bool NiPSysData::GetHasVertexColors() const
{
	return hasVertexColors;
}
void NiPSysData::SetHasVertexColors(bool b)
{
	hasVertexColors = b;
}

bool NiPSysData::GetHasSubtextures() const
{
	return hasTextureIndices;
}

void NiPSysData::SetHasSubtextures(bool b)
{
	hasTextureIndices = b;
}

std::vector<Vector4>& NiPSysData::GetSubtextureOffsets()
{
	return subtextureOffsets;
}

const std::vector<Vector4>& NiPSysData::GetSubtextureOffsets() const
{
	return subtextureOffsets;
}

bool NiPSysData::GetHasRotationAngles() const
{
	return hasRotationAngles;
}

void NiPSysData::SetHasRotationAngles(bool b)
{
	hasRotationAngles = b;
}

bool NiPSysData::GetHasRotationSpeeds() const
{
	return hasRotationSpeeds;
}

void NiPSysData::SetHasRotationSpeeds(bool b)
{
	hasRotationSpeeds = b;
}

//--END CUSTOM CODE--//
