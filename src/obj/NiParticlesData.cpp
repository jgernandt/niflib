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
#include "../../include/obj/NiParticlesData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiParticlesData::TYPE("NiParticlesData", &NiGeometryData::TYPE );

NiParticlesData::NiParticlesData() : numParticles((unsigned short)0), particleRadius(0.0f), hasRadii(false), numActive((unsigned short)0), hasSizes(false), hasRotations(false), hasRotationAngles(false), hasRotationAxes(false), hasTextureIndices(false), numSubtextureOffsets((unsigned int)0), aspectRatio(0.0f), aspectFlags((AspectFlags)0), speedToAspectAspect2(0.0f), speedToAspectSpeed1(0.0f), speedToAspectSpeed2(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiParticlesData::~NiParticlesData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiParticlesData::GetType() const {
	return TYPE;
}

NiObject * NiParticlesData::Create() {
	return new NiParticlesData;
}

void NiParticlesData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometryData::Read( in, link_stack, info );
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, in, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( particleRadius, in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasRadii, in, info );
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRadii ) {
			radii.resize(numVertices);
			for (unsigned int i3 = 0; i3 < radii.size(); i3++) {
				NifStream( radii[i3], in, info );
			};
		};
	};
	NifStream( numActive, in, info );
	NifStream( hasSizes, in, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) {
		if ( hasSizes ) {
			sizes.resize(numVertices);
			for (unsigned int i3 = 0; i3 < sizes.size(); i3++) {
				NifStream( sizes[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations, in, info );
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRotations ) {
			rotations.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotations.size(); i3++) {
				NifStream( rotations[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAngles, in, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) {
		if ( hasRotationAngles ) {
			rotationAngles.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationAngles.size(); i3++) {
				NifStream( rotationAngles[i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAxes, in, info );
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRotationAxes ) {
			rotationAxes.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationAxes.size(); i3++) {
				NifStream( rotationAxes[i3], in, info );
			};
		};
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion2 > 0)) ) {
		NifStream( hasTextureIndices, in, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		NifStream( numSubtextureOffsets, in, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( ((info.userVersion2 > 0) && (!(info.userVersion2 > 34))) ) ) {
		NifStream( numSubtextureOffsets, in, info );
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion2 > 0)) ) {
		subtextureOffsets.resize(numSubtextureOffsets);
		for (unsigned int i2 = 0; i2 < subtextureOffsets.size(); i2++) {
			NifStream( subtextureOffsets[i2], in, info );
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		NifStream( aspectRatio, in, info );
		NifStream( aspectFlags, in, info );
		NifStream( speedToAspectAspect2, in, info );
		NifStream( speedToAspectSpeed1, in, info );
		NifStream( speedToAspectSpeed2, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometryData::Write( out, link_map, missing_link_stack, info );
	numSubtextureOffsets = (unsigned int)(subtextureOffsets.size());
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, out, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( particleRadius, out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasRadii, out, info );
	};
	if ( ( info.version >= 0x0A010000 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRadii ) {
			for (unsigned int i3 = 0; i3 < radii.size(); i3++) {
				NifStream( radii[i3], out, info );
			};
		};
	};
	NifStream( numActive, out, info );
	NifStream( hasSizes, out, info );
	if ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) {
		if ( hasSizes ) {
			for (unsigned int i3 = 0; i3 < sizes.size(); i3++) {
				NifStream( sizes[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasRotations, out, info );
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRotations ) {
			for (unsigned int i3 = 0; i3 < rotations.size(); i3++) {
				NifStream( rotations[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAngles, out, info );
	};
	if ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) {
		if ( hasRotationAngles ) {
			for (unsigned int i3 = 0; i3 < rotationAngles.size(); i3++) {
				NifStream( rotationAngles[i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( hasRotationAxes, out, info );
	};
	if ( ( info.version >= 0x14000004 ) && ( (!((info.version >= 0x14020007) && (info.userVersion >= 11))) ) ) {
		if ( hasRotationAxes ) {
			for (unsigned int i3 = 0; i3 < rotationAxes.size(); i3++) {
				NifStream( rotationAxes[i3], out, info );
			};
		};
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion2 > 0)) ) {
		NifStream( hasTextureIndices, out, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		NifStream( numSubtextureOffsets, out, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( ((info.userVersion2 > 0) && (!(info.userVersion2 > 34))) ) ) {
		NifStream( numSubtextureOffsets, out, info );
	};
	if ( ((info.version >= 0x14020007) && (info.userVersion2 > 0)) ) {
		for (unsigned int i2 = 0; i2 < subtextureOffsets.size(); i2++) {
			NifStream( subtextureOffsets[i2], out, info );
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		NifStream( aspectRatio, out, info );
		NifStream( aspectFlags, out, info );
		NifStream( speedToAspectAspect2, out, info );
		NifStream( speedToAspectSpeed1, out, info );
		NifStream( speedToAspectSpeed2, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiParticlesData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometryData::asString();
	numSubtextureOffsets = (unsigned int)(subtextureOffsets.size());
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Particle Radius:  " << particleRadius << endl;
	out << "  Has Radii:  " << hasRadii << endl;
	if ( hasRadii ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < radii.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Radii[" << i2 << "]:  " << radii[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Active:  " << numActive << endl;
	out << "  Has Sizes:  " << hasSizes << endl;
	if ( hasSizes ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Sizes[" << i2 << "]:  " << sizes[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotations:  " << hasRotations << endl;
	if ( hasRotations ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotations.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotations[" << i2 << "]:  " << rotations[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotation Angles:  " << hasRotationAngles << endl;
	if ( hasRotationAngles ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationAngles.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Angles[" << i2 << "]:  " << rotationAngles[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotation Axes:  " << hasRotationAxes << endl;
	if ( hasRotationAxes ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationAxes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Axes[" << i2 << "]:  " << rotationAxes[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Texture Indices:  " << hasTextureIndices << endl;
	out << "  Num Subtexture Offsets:  " << numSubtextureOffsets << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < subtextureOffsets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Subtexture Offsets[" << i1 << "]:  " << subtextureOffsets[i1] << endl;
		array_output_count++;
	};
	out << "  Aspect Ratio:  " << aspectRatio << endl;
	out << "  Aspect Flags:  " << aspectFlags << endl;
	out << "  Speed to Aspect Aspect 2:  " << speedToAspectAspect2 << endl;
	out << "  Speed to Aspect Speed 1:  " << speedToAspectSpeed1 << endl;
	out << "  Speed to Aspect Speed 2:  " << speedToAspectSpeed2 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiParticlesData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiGeometryData::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiParticlesData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

std::list<NiObject *> NiParticlesData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiGeometryData::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
