/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

#include <cassert>

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSTriShape.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiBoundAABB.h"
#include "../../include/gen/BSVertexDesc.h"
#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
#include "../../include/gen/BSVertexDataSSE.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/obj/BSShaderProperty.h"
#include "../../include/obj/NiAlphaProperty.h"
#include "../../include/obj/NiObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSTriShape::TYPE("BSTriShape", &NiAVObject::TYPE );

BSTriShape::BSTriShape() : skin(NULL), shaderProperty(NULL), alphaProperty(NULL), numTriangles((unsigned int)0), numVertices((unsigned short)0), dataSize((unsigned int)0), particleDataSize((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSTriShape::~BSTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSTriShape::GetType() const {
	return TYPE;
}

NiObject * BSTriShape::Create() {
	return new BSTriShape;
}

void BSTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//Half-precision float i/o is broken. Not in general, but here they are trying to share the same storage.
	assert(info.userVersion2 != 130);

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	NifStream( boundingSphere.center, in, info );
	NifStream( boundingSphere.radius, in, info );
	if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( ((info.userVersion == 0x20000) || (info.userVersion == 0x30000)) ) ) {
		NifStream( boundingSphere.div2Aabb.numCorners, in, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( boundingSphere.div2Aabb.corners[i2], in, info );
		};
	};
	if ( (info.userVersion2 == 155) ) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( boundMinMax[i2], in, info );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( vertexDesc.bitfield, in, info );
	if ( (info.userVersion2 == 130) ) {
		NifStream( numTriangles, in, info );
	};
	if ( (info.userVersion2 < 130) ) {
		NifStream( reinterpret_cast<unsigned short&>(numTriangles), in, info );
	};
	NifStream( numVertices, in, info );
	NifStream( dataSize, in, info );
	if ( (info.userVersion2 == 130) ) {
		if ( (dataSize > 0) ) {
			vertexData.resize(numVertices);
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				if ( (((vertexDesc >> 44) & 0x401) == 0x401) ) {
					NifStream( vertexData[i3].vertex, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x411) ) {
					NifStream( vertexData[i3].bitangentX, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x401) ) {
					NifStream( vertexData[i3].unusedW, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x401) == 0x1) ) {
					NifStream( vertexData[i3].vertex.x, in, info );
					NifStream( vertexData[i3].vertex.y, in, info );
					NifStream( vertexData[i3].vertex.z, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x11) ) {
					NifStream( vertexData[i3].bitangentX, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x1) ) {
					NifStream( vertexData[i3].unusedW, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x2) != 0) ) {
					NifStream( vertexData[i3].uv.u, in, info );
					NifStream( vertexData[i3].uv.v, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x8) != 0) ) {
					NifStream( vertexData[i3].normal.x, in, info );
					NifStream( vertexData[i3].normal.y, in, info );
					NifStream( vertexData[i3].normal.z, in, info );
					NifStream( vertexData[i3].bitangentY, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x18) == 0x18) ) {
					NifStream( vertexData[i3].tangent.x, in, info );
					NifStream( vertexData[i3].tangent.y, in, info );
					NifStream( vertexData[i3].tangent.z, in, info );
					NifStream( vertexData[i3].bitangentZ, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x20) != 0) ) {
					NifStream( vertexData[i3].vertexColors.r, in, info );
					NifStream( vertexData[i3].vertexColors.g, in, info );
					NifStream( vertexData[i3].vertexColors.b, in, info );
					NifStream( vertexData[i3].vertexColors.a, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x40) != 0) ) {
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneWeights[i5], in, info );
					};
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneIndices[i5], in, info );
					};
				};
				if ( (((vertexDesc >> 44) & 0x100) != 0) ) {
					NifStream( vertexData[i3].eyeData, in, info );
				};
			};
		};
	};
	if ( (info.userVersion2 == 100) ) {
		if ( (dataSize > 0) ) {
			vertexData.resize(numVertices);
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				if ( (((vertexDesc >> 44) & 0x1) != 0) ) {
					NifStream( vertexData[i3].vertex, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x11) == 0x11) ) {
					NifStream( vertexData[i3].bitangentX, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x11) == 0x1) ) {
					NifStream( vertexData[i3].unusedW, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x2) != 0) ) {
					NifStream( vertexData[i3].uv.u, in, info );
					NifStream( vertexData[i3].uv.v, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x8) != 0) ) {
					NifStream( vertexData[i3].normal.x, in, info );
					NifStream( vertexData[i3].normal.y, in, info );
					NifStream( vertexData[i3].normal.z, in, info );
					NifStream( vertexData[i3].bitangentY, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x18) == 0x18) ) {
					NifStream( vertexData[i3].tangent.x, in, info );
					NifStream( vertexData[i3].tangent.y, in, info );
					NifStream( vertexData[i3].tangent.z, in, info );
					NifStream( vertexData[i3].bitangentZ, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x20) != 0) ) {
					NifStream( vertexData[i3].vertexColors.r, in, info );
					NifStream( vertexData[i3].vertexColors.g, in, info );
					NifStream( vertexData[i3].vertexColors.b, in, info );
					NifStream( vertexData[i3].vertexColors.a, in, info );
				};
				if ( (((vertexDesc >> 44) & 0x40) != 0) ) {
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneWeights[i5], in, info );
					};
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneIndices[i5], in, info );
					};
				};
				if ( (((vertexDesc >> 44) & 0x100) != 0) ) {
					NifStream( vertexData[i3].eyeData, in, info );
				};
			};
		};
	};
	if ( (dataSize > 0) ) {
		triangles.resize(numTriangles);
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], in, info );
		};
	};
	if ( (info.userVersion2 == 100) ) {
		NifStream( particleDataSize, in, info );
		if ( (particleDataSize > 0) ) {
			particleVertices.resize(numVertices);
			for (unsigned int i3 = 0; i3 < particleVertices.size(); i3++) {
				NifStream( particleVertices[i3].x, in, info );
				NifStream( particleVertices[i3].y, in, info );
				NifStream( particleVertices[i3].z, in, info );
			};
			particleNormals.resize(numVertices);
			for (unsigned int i3 = 0; i3 < particleNormals.size(); i3++) {
				NifStream( particleNormals[i3].x, in, info );
				NifStream( particleNormals[i3].y, in, info );
				NifStream( particleNormals[i3].z, in, info );
			};
			trianglesCopy.resize(numTriangles);
			for (unsigned int i3 = 0; i3 < trianglesCopy.size(); i3++) {
				NifStream( trianglesCopy[i3], in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//Half-precision float i/o is broken. Not in general, but here they are trying to share the same storage.
	assert(info.userVersion2 != 130);

	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, missing_link_stack, info );
	dataSize = dataSizeCalc(info);
	numVertices = numVerticesCalc(info);
	//numVertices = (unsigned short)(vertexData.size());
	numTriangles = (unsigned int)(triangles.size());
	NifStream( boundingSphere.center, out, info );
	NifStream( boundingSphere.radius, out, info );
	if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( ((info.userVersion == 0x20000) || (info.userVersion == 0x30000)) ) ) {
		NifStream( boundingSphere.div2Aabb.numCorners, out, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( boundingSphere.div2Aabb.corners[i2], out, info );
		};
	};
	if ( (info.userVersion2 == 155) ) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( boundMinMax[i2], out, info );
		};
	};
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*skin), out );
	} else {
		if ( skin != NULL ) {
			map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(skin) );
			if (it != link_map.end()) {
				NifStream( it->second, out, info );
				missing_link_stack.push_back( NULL );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( skin );
			}
		} else {
			NifStream( 0xFFFFFFFF, out, info );
			missing_link_stack.push_back( NULL );
		}
	}
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*shaderProperty), out );
	} else {
		if ( shaderProperty != NULL ) {
			map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(shaderProperty) );
			if (it != link_map.end()) {
				NifStream( it->second, out, info );
				missing_link_stack.push_back( NULL );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( shaderProperty );
			}
		} else {
			NifStream( 0xFFFFFFFF, out, info );
			missing_link_stack.push_back( NULL );
		}
	}
	if ( info.version < VER_3_3_0_13 ) {
		WritePtr32( &(*alphaProperty), out );
	} else {
		if ( alphaProperty != NULL ) {
			map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(alphaProperty) );
			if (it != link_map.end()) {
				NifStream( it->second, out, info );
				missing_link_stack.push_back( NULL );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( alphaProperty );
			}
		} else {
			NifStream( 0xFFFFFFFF, out, info );
			missing_link_stack.push_back( NULL );
		}
	}
	NifStream( vertexDesc.bitfield, out, info );
	if ( (info.userVersion2 == 130) ) {
		NifStream( numTriangles, out, info );
	};
	if ( (info.userVersion2 < 130) ) {
		NifStream(reinterpret_cast<unsigned short&>(numTriangles), out, info );
	};
	NifStream( numVertices, out, info );
	NifStream( dataSize, out, info );
	if ( (info.userVersion2 == 130) ) {
		if ( (dataSize > 0) ) {
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				if ( (((vertexDesc >> 44) & 0x401) == 0x401) ) {
					NifStream( vertexData[i3].vertex, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x411) ) {
					NifStream( vertexData[i3].bitangentX, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x401) ) {
					NifStream( vertexData[i3].unusedW, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x401) == 0x1) ) {
					NifStream( vertexData[i3].vertex.x, out, info );
					NifStream( vertexData[i3].vertex.y, out, info );
					NifStream( vertexData[i3].vertex.z, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x11) ) {
					NifStream( vertexData[i3].bitangentX, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x411) == 0x1) ) {
					NifStream( vertexData[i3].unusedW, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x2) != 0) ) {
					NifStream( vertexData[i3].uv.u, out, info );
					NifStream( vertexData[i3].uv.v, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x8) != 0) ) {
					NifStream( vertexData[i3].normal.x, out, info );
					NifStream( vertexData[i3].normal.y, out, info );
					NifStream( vertexData[i3].normal.z, out, info );
					NifStream( vertexData[i3].bitangentY, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x18) == 0x18) ) {
					NifStream( vertexData[i3].tangent.x, out, info );
					NifStream( vertexData[i3].tangent.y, out, info );
					NifStream( vertexData[i3].tangent.z, out, info );
					NifStream( vertexData[i3].bitangentZ, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x20) != 0) ) {
					NifStream( vertexData[i3].vertexColors.r, out, info );
					NifStream( vertexData[i3].vertexColors.g, out, info );
					NifStream( vertexData[i3].vertexColors.b, out, info );
					NifStream( vertexData[i3].vertexColors.a, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x40) != 0) ) {
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneWeights[i5], out, info );
					};
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneIndices[i5], out, info );
					};
				};
				if ( (((vertexDesc >> 44) & 0x100) != 0) ) {
					NifStream( vertexData[i3].eyeData, out, info );
				};
			};
		};
	};
	if ( (info.userVersion2 == 100) ) {
		if ( (dataSize > 0) ) {
			for (unsigned int i3 = 0; i3 < vertexData.size(); i3++) {
				if ( (((vertexDesc >> 44) & 0x1) != 0) ) {
					NifStream( vertexData[i3].vertex, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x11) == 0x11) ) {
					NifStream( vertexData[i3].bitangentX, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x11) == 0x1) ) {
					NifStream( vertexData[i3].unusedW, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x2) != 0) ) {
					NifStream( vertexData[i3].uv.u, out, info );
					NifStream( vertexData[i3].uv.v, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x8) != 0) ) {
					NifStream( vertexData[i3].normal.x, out, info );
					NifStream( vertexData[i3].normal.y, out, info );
					NifStream( vertexData[i3].normal.z, out, info );
					NifStream( vertexData[i3].bitangentY, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x18) == 0x18) ) {
					NifStream( vertexData[i3].tangent.x, out, info );
					NifStream( vertexData[i3].tangent.y, out, info );
					NifStream( vertexData[i3].tangent.z, out, info );
					NifStream( vertexData[i3].bitangentZ, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x20) != 0) ) {
					NifStream( vertexData[i3].vertexColors.r, out, info );
					NifStream( vertexData[i3].vertexColors.g, out, info );
					NifStream( vertexData[i3].vertexColors.b, out, info );
					NifStream( vertexData[i3].vertexColors.a, out, info );
				};
				if ( (((vertexDesc >> 44) & 0x40) != 0) ) {
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneWeights[i5], out, info );
					};
					for (unsigned int i5 = 0; i5 < 4; i5++) {
						NifStream( vertexData[i3].boneIndices[i5], out, info );
					};
				};
				if ( (((vertexDesc >> 44) & 0x100) != 0) ) {
					NifStream( vertexData[i3].eyeData, out, info );
				};
			};
		};
	};
	if ( (dataSize > 0) ) {
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], out, info );
		};
	};
	if ( (info.userVersion2 == 100) ) {
		NifStream( particleDataSize, out, info );
		if ( (particleDataSize > 0) ) {
			for (unsigned int i3 = 0; i3 < particleVertices.size(); i3++) {
				NifStream( particleVertices[i3].x, out, info );
				NifStream( particleVertices[i3].y, out, info );
				NifStream( particleVertices[i3].z, out, info );
			};
			for (unsigned int i3 = 0; i3 < particleNormals.size(); i3++) {
				NifStream( particleNormals[i3].x, out, info );
				NifStream( particleNormals[i3].y, out, info );
				NifStream( particleNormals[i3].z, out, info );
			};
			for (unsigned int i3 = 0; i3 < trianglesCopy.size(); i3++) {
				NifStream( trianglesCopy[i3], out, info );
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string BSTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	numVertices = (unsigned short)(vertexData.size());
	numTriangles = (unsigned int)(triangles.size());
	out << "  Center:  " << boundingSphere.center << endl;
	out << "  Radius:  " << boundingSphere.radius << endl;
	out << "  Num Corners:  " << boundingSphere.div2Aabb.numCorners << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Corners[" << i1 << "]:  " << boundingSphere.div2Aabb.corners[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bound Min Max[" << i1 << "]:  " << boundMinMax[i1] << endl;
		array_output_count++;
	};
	out << "  Skin:  " << skin << endl;
	out << "  Shader Property:  " << shaderProperty << endl;
	out << "  Alpha Property:  " << alphaProperty << endl;
	out << "  Bitfield:  " << vertexDesc.bitfield << endl;
	out << "  Num Triangles:  " << numTriangles << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Data Size:  " << dataSize << endl;
	if ( (dataSize > 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexData.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( (((vertexDesc >> 44) & 0x401) == 0x401) ) {
				out << "        Vertex:  " << vertexData[i2].vertex << endl;
			};
			if ( (((vertexDesc >> 44) & 0x411) == 0x411) ) {
				out << "        Bitangent X:  " << vertexData[i2].bitangentX << endl;
			};
			if ( (((vertexDesc >> 44) & 0x411) == 0x401) ) {
				out << "        Unused W:  " << vertexData[i2].unusedW << endl;
			};
			if ( (((vertexDesc >> 44) & 0x2) != 0) ) {
				out << "        u:  " << vertexData[i2].uv.u << endl;
				out << "        v:  " << vertexData[i2].uv.v << endl;
			};
			if ( (((vertexDesc >> 44) & 0x8) != 0) ) {
				out << "        x:  " << vertexData[i2].normal.x << endl;
				out << "        y:  " << vertexData[i2].normal.y << endl;
				out << "        z:  " << vertexData[i2].normal.z << endl;
				out << "        Bitangent Y:  " << vertexData[i2].bitangentY << endl;
			};
			if ( (((vertexDesc >> 44) & 0x18) == 0x18) ) {
				out << "        x:  " << vertexData[i2].tangent.x << endl;
				out << "        y:  " << vertexData[i2].tangent.y << endl;
				out << "        z:  " << vertexData[i2].tangent.z << endl;
				out << "        Bitangent Z:  " << vertexData[i2].bitangentZ << endl;
			};
			if ( (((vertexDesc >> 44) & 0x20) != 0) ) {
				out << "        r:  " << vertexData[i2].vertexColors.r << endl;
				out << "        g:  " << vertexData[i2].vertexColors.g << endl;
				out << "        b:  " << vertexData[i2].vertexColors.b << endl;
				out << "        a:  " << vertexData[i2].vertexColors.a << endl;
			};
			if ( (((vertexDesc >> 44) & 0x40) != 0) ) {
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Weights[" << i4 << "]:  " << vertexData[i2].boneWeights[i4] << endl;
					array_output_count++;
				};
				array_output_count = 0;
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << vertexData[i2].boneIndices[i4] << endl;
					array_output_count++;
				};
			};
			if ( (((vertexDesc >> 44) & 0x100) != 0) ) {
				out << "        Eye Data:  " << vertexData[i2].eyeData << endl;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Triangles[" << i2 << "]:  " << triangles[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Particle Data Size:  " << particleDataSize << endl;
	if ( (particleDataSize > 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < particleVertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      x:  " << particleVertices[i2].x << endl;
			out << "      y:  " << particleVertices[i2].y << endl;
			out << "      z:  " << particleVertices[i2].z << endl;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < particleNormals.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      x:  " << particleNormals[i2].x << endl;
			out << "      y:  " << particleNormals[i2].y << endl;
			out << "      z:  " << particleNormals[i2].z << endl;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < trianglesCopy.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Triangles Copy[" << i2 << "]:  " << trianglesCopy[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void BSTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, missing_link_stack, info );
	skin = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
	shaderProperty = FixLink<BSShaderProperty>( objects, link_stack, missing_link_stack, info );
	alphaProperty = FixLink<NiAlphaProperty>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( skin != NULL )
		refs.push_back(StaticCast<NiObject>(skin));
	if ( shaderProperty != NULL )
		refs.push_back(StaticCast<NiObject>(shaderProperty));
	if ( alphaProperty != NULL )
		refs.push_back(StaticCast<NiObject>(alphaProperty));
	return refs;
}

std::list<NiObject *> BSTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiAVObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned int Niflib::BSTriShape::dataSizeCalc(const Niflib::NifInfo& info) const
{
	return 4 * vertexDesc.GetVertexDataSize() * numVerticesCalc(info) + 6 * numTriangles;
}

unsigned short Niflib::BSTriShape::numVerticesCalc(const Niflib::NifInfo& info) const
{
	if (vertexData.size() > std::numeric_limits<unsigned short>::max())
		throw std::overflow_error(name + ": Vertex Data exceeds maximum allowed size");

	return static_cast<unsigned short>(vertexData.size());
}

//--END CUSTOM CODE--//
