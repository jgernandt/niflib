/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/niflib.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiSkinData.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiGeometry.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiBoundAABB.h"
#include "../../include/gen/MaterialData.h"
#include "../../include/gen/MaterialData.h"
#include "../../include/obj/BSShaderProperty.h"
#include "../../include/obj/NiAlphaProperty.h"
#include "../../include/obj/NiGeometryData.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiParticleSystem.h"
#include "../../include/obj/NiSkinInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeometry::TYPE("NiGeometry", &NiAVObject::TYPE );

NiGeometry::NiGeometry() : skin(NULL), data(NULL), skinInstance(NULL), shaderProperty(NULL), alphaProperty(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiGeometry::~NiGeometry() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiGeometry::GetType() const {
	return TYPE;
}

NiObject * NiGeometry::Create() {
	return new NiGeometry;
}

void NiGeometry::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			NifStream( boundingSphere.center, in, info );
			NifStream( boundingSphere.radius, in, info );
			if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( ((info.userVersion == 0x20000) || (info.userVersion == 0x30000)) ) ) {
				NifStream( boundingSphere.div2Aabb.numCorners, in, info );
				for (unsigned int i4 = 0; i4 < 2; i4++) {
					NifStream( boundingSphere.div2Aabb.corners[i4], in, info );
				};
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 == 155) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			for (unsigned int i3 = 0; i3 < 6; i3++) {
				NifStream( boundMinMax[i3], in, info );
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( (!(info.userVersion2 >= 100)) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( ( info.version >= 0x0303000D ) && ( (!(info.userVersion2 >= 100)) ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!(info.userVersion2 >= 100)) ) ) {
		if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
			NifStream( materialData.hasShader, in, info );
			if ( materialData.hasShader ) {
				NifStream( materialData.shaderName, in, info );
				NifStream( materialData.shaderExtraData, in, info );
			};
		};
		if ( info.version >= 0x14020005 ) {
			NifStream( materialData.numMaterials, in, info );
			materialData.materialName.resize(materialData.numMaterials);
			for (unsigned int i3 = 0; i3 < materialData.materialName.size(); i3++) {
				NifStream( materialData.materialName[i3], in, info );
			};
			materialData.materialExtraData.resize(materialData.numMaterials);
			for (unsigned int i3 = 0; i3 < materialData.materialExtraData.size(); i3++) {
				NifStream( materialData.materialExtraData[i3], in, info );
			};
			NifStream( materialData.activeMaterial, in, info );
		};
		if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( (info.userVersion == 1) ) ) {
			NifStream( materialData.cyanideUnknown, in, info );
		};
		if ( ( info.version >= 0x0A030001 ) && ( info.version <= 0x0A040001 ) ) {
			NifStream( materialData.worldshiftUnknown, in, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( materialData.materialNeedsUpdate, in, info );
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
				NifStream( materialData.hasShader, in, info );
				if ( materialData.hasShader ) {
					NifStream( materialData.shaderName, in, info );
					NifStream( materialData.shaderExtraData, in, info );
				};
			};
			if ( info.version >= 0x14020005 ) {
				NifStream( materialData.numMaterials, in, info );
				materialData.materialName.resize(materialData.numMaterials);
				for (unsigned int i4 = 0; i4 < materialData.materialName.size(); i4++) {
					NifStream( materialData.materialName[i4], in, info );
				};
				materialData.materialExtraData.resize(materialData.numMaterials);
				for (unsigned int i4 = 0; i4 < materialData.materialExtraData.size(); i4++) {
					NifStream( materialData.materialExtraData[i4], in, info );
				};
				NifStream( materialData.activeMaterial, in, info );
			};
			if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( (info.userVersion == 1) ) ) {
				NifStream( materialData.cyanideUnknown, in, info );
			};
			if ( ( info.version >= 0x0A030001 ) && ( info.version <= 0x0A040001 ) ) {
				NifStream( materialData.worldshiftUnknown, in, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( materialData.materialNeedsUpdate, in, info );
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeometry::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObject::Write( out, link_map, missing_link_stack, info );
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			NifStream( boundingSphere.center, out, info );
			NifStream( boundingSphere.radius, out, info );
			if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( ((info.userVersion == 0x20000) || (info.userVersion == 0x30000)) ) ) {
				NifStream( boundingSphere.div2Aabb.numCorners, out, info );
				for (unsigned int i4 = 0; i4 < 2; i4++) {
					NifStream( boundingSphere.div2Aabb.corners[i4], out, info );
				};
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 == 155) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			for (unsigned int i3 = 0; i3 < 6; i3++) {
				NifStream( boundMinMax[i3], out, info );
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
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
		};
	};
	if ( (!(info.userVersion2 >= 100)) ) {
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
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
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
	};
	if ( ( info.version >= 0x0303000D ) && ( (!(info.userVersion2 >= 100)) ) ) {
		if ( info.version < VER_3_3_0_13 ) {
			WritePtr32( &(*skinInstance), out );
		} else {
			if ( skinInstance != NULL ) {
				map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(skinInstance) );
				if (it != link_map.end()) {
					NifStream( it->second, out, info );
					missing_link_stack.push_back( NULL );
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( skinInstance );
				}
			} else {
				NifStream( 0xFFFFFFFF, out, info );
				missing_link_stack.push_back( NULL );
			}
		}
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			if ( info.version < VER_3_3_0_13 ) {
				WritePtr32( &(*skinInstance), out );
			} else {
				if ( skinInstance != NULL ) {
					map<NiObjectRef,unsigned int>::const_iterator it = link_map.find( StaticCast<NiObject>(skinInstance) );
					if (it != link_map.end()) {
						NifStream( it->second, out, info );
						missing_link_stack.push_back( NULL );
					} else {
						NifStream( 0xFFFFFFFF, out, info );
						missing_link_stack.push_back( skinInstance );
					}
				} else {
					NifStream( 0xFFFFFFFF, out, info );
					missing_link_stack.push_back( NULL );
				}
			}
		};
	};
	if ( ( info.version >= 0x0A000100 ) && ( (!(info.userVersion2 >= 100)) ) ) {
		materialData.numMaterials = (unsigned int)(materialData.materialName.size());
		if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
			NifStream( materialData.hasShader, out, info );
			if ( materialData.hasShader ) {
				NifStream( materialData.shaderName, out, info );
				NifStream( materialData.shaderExtraData, out, info );
			};
		};
		if ( info.version >= 0x14020005 ) {
			NifStream( materialData.numMaterials, out, info );
			for (unsigned int i3 = 0; i3 < materialData.materialName.size(); i3++) {
				NifStream( materialData.materialName[i3], out, info );
			};
			for (unsigned int i3 = 0; i3 < materialData.materialExtraData.size(); i3++) {
				NifStream( materialData.materialExtraData[i3], out, info );
			};
			NifStream( materialData.activeMaterial, out, info );
		};
		if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( (info.userVersion == 1) ) ) {
			NifStream( materialData.cyanideUnknown, out, info );
		};
		if ( ( info.version >= 0x0A030001 ) && ( info.version <= 0x0A040001 ) ) {
			NifStream( materialData.worldshiftUnknown, out, info );
		};
		if ( info.version >= 0x14020007 ) {
			NifStream( materialData.materialNeedsUpdate, out, info );
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			materialData.numMaterials = (unsigned int)(materialData.materialName.size());
			if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x14010003 ) ) {
				NifStream( materialData.hasShader, out, info );
				if ( materialData.hasShader ) {
					NifStream( materialData.shaderName, out, info );
					NifStream( materialData.shaderExtraData, out, info );
				};
			};
			if ( info.version >= 0x14020005 ) {
				NifStream( materialData.numMaterials, out, info );
				for (unsigned int i4 = 0; i4 < materialData.materialName.size(); i4++) {
					NifStream( materialData.materialName[i4], out, info );
				};
				for (unsigned int i4 = 0; i4 < materialData.materialExtraData.size(); i4++) {
					NifStream( materialData.materialExtraData[i4], out, info );
				};
				NifStream( materialData.activeMaterial, out, info );
			};
			if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) && ( (info.userVersion == 1) ) ) {
				NifStream( materialData.cyanideUnknown, out, info );
			};
			if ( ( info.version >= 0x0A030001 ) && ( info.version <= 0x0A040001 ) ) {
				NifStream( materialData.worldshiftUnknown, out, info );
			};
			if ( info.version >= 0x14020007 ) {
				NifStream( materialData.materialNeedsUpdate, out, info );
			};
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
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
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiGeometry::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	if ( IsDerivedType(NiParticleSystem::TYPE) ) {
		out << "    Center:  " << boundingSphere.center << endl;
		out << "    Radius:  " << boundingSphere.radius << endl;
		out << "    Num Corners:  " << boundingSphere.div2Aabb.numCorners << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Corners[" << i2 << "]:  " << boundingSphere.div2Aabb.corners[i2] << endl;
			array_output_count++;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Bound Min Max[" << i2 << "]:  " << boundMinMax[i2] << endl;
			array_output_count++;
		};
		out << "    Skin:  " << skin << endl;
	};
	out << "  Data:  " << data << endl;
	out << "  Skin Instance:  " << skinInstance << endl;
	materialData.numMaterials = (unsigned int)(materialData.materialName.size());
	out << "  Has Shader:  " << materialData.hasShader << endl;
	if ( materialData.hasShader ) {
		out << "    Shader Name:  " << materialData.shaderName << endl;
		out << "    Shader Extra Data:  " << materialData.shaderExtraData << endl;
	};
	out << "  Num Materials:  " << materialData.numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materialData.materialName.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Material Name[" << i1 << "]:  " << materialData.materialName[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materialData.materialExtraData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Material Extra Data[" << i1 << "]:  " << materialData.materialExtraData[i1] << endl;
		array_output_count++;
	};
	out << "  Active Material:  " << materialData.activeMaterial << endl;
	out << "  Cyanide Unknown:  " << materialData.cyanideUnknown << endl;
	out << "  WorldShift Unknown:  " << materialData.worldshiftUnknown << endl;
	out << "  Material Needs Update:  " << materialData.materialNeedsUpdate << endl;
	out << "  Shader Property:  " << shaderProperty << endl;
	out << "  Alpha Property:  " << alphaProperty << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiGeometry::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiAVObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( IsDerivedType(NiParticleSystem::TYPE) ) {
			skin = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( (!(info.userVersion2 >= 100)) ) {
		data = FixLink<NiGeometryData>( objects, link_stack, missing_link_stack, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			data = FixLink<NiGeometryData>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( ( info.version >= 0x0303000D ) && ( (!(info.userVersion2 >= 100)) ) ) {
		skinInstance = FixLink<NiSkinInstance>( objects, link_stack, missing_link_stack, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 >= 100) ) ) {
		if ( (!IsDerivedType(NiParticleSystem::TYPE)) ) {
			skinInstance = FixLink<NiSkinInstance>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( ( info.version >= 0x14020007 ) && ( info.version <= 0x14020007 ) && ( (info.userVersion2 > 34) ) ) {
		shaderProperty = FixLink<BSShaderProperty>( objects, link_stack, missing_link_stack, info );
		alphaProperty = FixLink<NiAlphaProperty>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiGeometry::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( skin != NULL )
		refs.push_back(StaticCast<NiObject>(skin));
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( skinInstance != NULL )
		refs.push_back(StaticCast<NiObject>(skinInstance));
	if ( shaderProperty != NULL )
		refs.push_back(StaticCast<NiObject>(shaderProperty));
	if ( alphaProperty != NULL )
		refs.push_back(StaticCast<NiObject>(alphaProperty));
	return refs;
}

std::list<NiObject *> NiGeometry::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiAVObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiGeometryData> NiGeometry::GetData() const {
	return DynamicCast<NiGeometryData>(data);
}

void NiGeometry::SetData(NiGeometryData* n) {
	data = n;
}

string NiGeometry::GetShader() const {
	return materialData.shaderName;
}

void NiGeometry::SetShader(const string& n) {
	//Check if name is blank, if so clear shader
	if (n.size() == 0) {
		materialData.hasShader = false;
		materialData.shaderName.clear();
	}
	else {
		materialData.shaderName = n;
	}
}

Ref<NiSkinInstance> NiGeometry::GetSkinInstance() const {
	return skinInstance;
}

void NiGeometry::SetSkinInstance(Ref<NiSkinInstance> skin) {
	skinInstance = skin;
}

void NiGeometry::BindSkin(vector< Ref<NiNode> >& bone_nodes) {
	BindSkinWith(bone_nodes, NULL);
}

void NiGeometry::BindSkinWith(vector< Ref<NiNode> >& bone_nodes, NiObject* (*SkinInstConstructor)())
{
	if (SkinInstConstructor == NULL) {
		SkinInstConstructor = NiSkinInstance::Create;
	}

	//Ensure skin is not aleady bound
	if (skinInstance != 0) {
		throw runtime_error("You have attempted to re-bind a skin that is already bound.  Unbind it first.");
	}

	//Ensure that some bones are given
	if (bone_nodes.size() == 0) {
		throw runtime_error("You must specify at least one bone node.");
	}

	//--Find a suitable skeleton root--//

	//The skeleton root will be the common ancestor of all bones which influence this skin,
	//and the skin object itself.

	vector<NiAVObjectRef> objects;
	objects.push_back(NiAVObjectRef(this));
	for (size_t i = 0; i < bone_nodes.size(); ++i) {
		objects.push_back(StaticCast<NiAVObject>(bone_nodes[i]));
	}

	NiNodeRef skeleton_root = FindCommonAncestor(objects);

	if (skeleton_root == NULL) {
		throw runtime_error("Failed to find suitable skeleton root.");
	}

	//Create a skin instance using the bone and root data
	skinInstance = DynamicCast<NiSkinInstance>(SkinInstConstructor());
	if (skinInstance == NULL) {
		throw runtime_error("Failed to construct NiSkinInstance");
	}

	skinInstance->BindSkin(skeleton_root, bone_nodes);

	//Create a NiSkinData object based on this mesh
	skinInstance->SetSkinData(new NiSkinData(this));
};

void NiGeometry::ApplySkinOffset() {
	if (GetParent() == NULL) {
		throw runtime_error("Attempted to apply skin transforms on a shape with no parent.");
	}

	if (skinInstance == NULL) {
		throw runtime_error("Attempted to apply skin transforms on a shape with no skin instance.");
	}

	if (skinInstance->GetSkinData() == NULL) {
		throw runtime_error("Attempted to apply skin transforms on a shape with no skin data.");
	}

	//Get ancestors
	list<NiNodeRef> ancestors;
	ancestors = ListAncestors(this);

	//Propagate transforms on ancestors below skeleton root
	bool below_root = false;

	for (list<NiNodeRef>::iterator it = ancestors.begin(); it != ancestors.end(); ++it) {
		if (*it == skinInstance->GetSkeletonRoot()) {
			below_root = true;
			continue;
		}
		if (below_root) {
			(*it)->PropagateTransform();
		}
	}

	//Now apply the transforms to the vertices and normals of this mesh
	this->ApplyTransforms();

	//Set the skin overall transform to the identity
	skinInstance->GetSkinData()->SetOverallTransform(Matrix44::IDENTITY);

	//Reset skin offsets
	skinInstance->GetSkinData()->ResetOffsets(this);
}

void NiGeometry::NormalizeSkinWeights() {
	if (IsSkin() == false) {
		throw runtime_error("NormalizeSkinWeights called on a mesh that is not a skin.");
	}
	NiSkinDataRef niSkinData = this->GetSkinInstance()->GetSkinData();

	NiGeometryDataRef niGeomData = this->GetData();
	if (niGeomData == NULL) {
		throw runtime_error("NormalizeSkinWeights called on a mesh with no geometry data.");
	}

	niSkinData->NormalizeWeights(niGeomData->GetVertexCount());
}

bool NiGeometry::IsSkin() {
	//Determine whether this is a skin by looking for a skin instance and
	//skin data
	if (skinInstance != NULL && skinInstance->GetSkinData() != NULL) {
		return true;
	}
	else {
		return false;
	}
}

void NiGeometry::UnbindSkin() {
	//Clear skin instance
	skinInstance = NULL;
}

void NiGeometry::GetSkinDeformation(vector<Vector3>& vertices, vector<Vector3>& normals) const {
	//--Get required data & insure validity--//

	NiGeometryDataRef geom_data = GetData();

	if (geom_data == NULL) {
		throw runtime_error("This NiGeometry has no NiGeometryData so there are no vertices to get.");
	}

	NiSkinInstanceRef skin_inst = GetSkinInstance();


	if (skin_inst == NULL) {
		throw runtime_error("This NiGeometry is not influenced by a skin.");
	}

	NiSkinDataRef skin_data = skin_inst->GetSkinData();

	if (skin_data == NULL) {
		throw runtime_error("Skin Data is missing, cannot calculate skin influenced vertex position.");
	}

	//Ensure that skin instance bone count & skin data bone count match
	if (skin_inst->GetBoneCount() != skin_data->GetBoneCount()) {
		throw runtime_error("Skin Instance and Skin Data bone count do not match.");
	}

	//Get skeleton root
	NiNodeRef skel_root = skin_inst->GetSkeletonRoot();
	if (skel_root == NULL) {
		throw runtime_error("Skin Instance is not bound to a skeleton root.");
	}

	//Get the vertices & bone nodes
	vector<Vector3> in_verts = geom_data->GetVertices();
	vector<Vector3> in_norms = geom_data->GetNormals();

	vector<NiNodeRef> bone_nodes = skin_inst->GetBones();

	//Set up output arrays to hold the transformed vertices and normals
	vertices.resize(in_verts.size());
	normals.resize(in_norms.size());

	//Transform vertices into position based on skin data
	Matrix44 root_world = skel_root->GetWorldTransform();
	Matrix44 geom_world = GetWorldTransform();
	for (unsigned int i = 0; i < skin_data->GetBoneCount(); ++i) {
		Matrix44 bone_world = bone_nodes[i]->GetWorldTransform();
		Matrix44 bone_offset = skin_data->GetBoneTransform(i);
		vector<BoneVertData> weights = skin_data->GetBoneWeights(i);
		Matrix44 vert_trans = bone_offset * bone_world;
		Matrix44 norm_trans = Matrix44(vert_trans.GetRotation());
		for (unsigned int j = 0; j < weights.size(); ++j) {
			unsigned int index = weights[j].index;
			float weight = weights[j].weight;
			if (index < vertices.size()) {
				vertices[index] += (vert_trans * in_verts[index]) * weight;
			}
			if (index < normals.size()) {
				normals[index] += (norm_trans * in_norms[index]) * weight;
			}
		}
	}

	//Transform all vertices to final position
	Matrix44 geom_world_inv = geom_world.Inverse();
	Matrix44 geom_world_inv_rot = Matrix44(geom_world_inv.GetRotation());
	for (unsigned int i = 0; i < vertices.size(); ++i) {
		vertices[i] = geom_world_inv * vertices[i];
	}
	for (unsigned int i = 0; i < normals.size(); ++i) {
		normals[i] = geom_world_inv_rot * normals[i];
		//normals[i] = normals[i].Normalized();
	}
}

void NiGeometry::ApplyTransforms() {
	//Get Data
	NiGeometryDataRef geom_data = this->GetData();
	if (geom_data == NULL) {
		throw runtime_error("Called ApplyTransform on a NiGeometry object that has no NiGeometryData attached.");
	}

	//Transform the vertices by the local transform of this mesh
	geom_data->Transform(this->GetLocalTransform());

	//Now that the transforms have been applied, clear them to the identity
	this->SetLocalTransform(Matrix44::IDENTITY);
}

// Calculate bounding sphere using minimum-volume axis-align bounding box.  Its fast but not a very good fit.
static void CalcAxisAlignedBox(const vector<BoneVertData>& n, const vector<Vector3>& vertices, Vector3& center, float& radius)
{
	//--Calculate center & radius--//

	//Set lows and highs to first vertex
	Vector3 lows = vertices[n[0].index];
	Vector3 highs = vertices[n[0].index];

	//Iterate through the vertices, adjusting the stored values
	//if a vertex with lower or higher values is found
	for (unsigned int i = 0; i < n.size(); ++i) {
		const Vector3& v = vertices[n[i].index];

		if (v.x > highs.x) highs.x = v.x;
		else if (v.x < lows.x) lows.x = v.x;

		if (v.y > highs.y) highs.y = v.y;
		else if (v.y < lows.y) lows.y = v.y;

		if (v.z > highs.z) highs.z = v.z;
		else if (v.z < lows.z) lows.z = v.z;
	}

	//Now we know the extent of the shape, so the center will be the average
	//of the lows and highs
	center = (highs + lows) / 2.0f;

	//The radius will be the largest distance from the center
	Vector3 diff;
	float dist2(0.0f), maxdist2(0.0f);
	for (unsigned int i = 0; i < n.size(); ++i) {
		const Vector3& v = vertices[n[i].index];

		diff = center - v;
		dist2 = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
		if (dist2 > maxdist2) maxdist2 = dist2;
	};
	radius = sqrt(maxdist2);
}

// Calculate bounding sphere using average position of the points.  Better fit but slower.
static void CalcCenteredSphere(const vector<BoneVertData>& n, const vector<Vector3>& vertices, Vector3& center, float& radius)
{
	size_t nv = n.size();
	Vector3 sum;
	for (size_t i = 0; i < nv; ++i)
		sum += vertices[n[i].index];
	center = sum / float(nv);
	radius = 0.0f;
	for (size_t i = 0; i < nv; ++i) {
		Vector3 diff = vertices[n[i].index] - center;
		float mag = diff.Magnitude();
		radius = max(radius, mag);
	}
}

void NiGeometry::SetBoneWeights(unsigned int bone_index, const vector<BoneVertData>& n) {

	if (n.size() == 0) {
		throw runtime_error("You must specify at least one weight value.");
	}

	NiSkinInstanceRef skinInst = GetSkinInstance();

	if (skinInst == NULL) {
		throw runtime_error("You must bind a skin before setting vertex weights.  No NiSkinInstance found.");
	}

	NiSkinDataRef skinData = skinInst->GetSkinData();

	if (skinData == NULL) {
		throw runtime_error("You must bind a skin before setting vertex weights.  No NiSkinData found.");
	}

	NiGeometryDataRef geomData = GetData();

	if (geomData == NULL) {
		throw runtime_error("Attempted to set weights on a mesh with no geometry data.");
	}

	//Get vertex array
	vector<Vector3> vertices = geomData->GetVertices();

	Vector3 center; float radius;
	//CalcCenteredSphere(n, vertices, center, radius);
	CalcAxisAlignedBox(n, vertices, center, radius);

	//Translate center by bone matrix
	center = skinData->GetBoneTransform(bone_index) * center;

	skinData->SetBoneWeights(bone_index, n, center, radius);
}

int NiGeometry::GetActiveMaterial() const {
	return materialData.activeMaterial;
}

void NiGeometry::SetActiveMaterial(int value) {
	materialData.activeMaterial = value;
}

bool NiGeometry::HasShader() const {
	return materialData.hasShader;
}

Ref<NiProperty> NiGeometry::GetBSProperty(short index) {
	if (index == 0)
		return StaticCast<NiProperty>(shaderProperty);
	else if (index == 1)
		return StaticCast<NiProperty>(alphaProperty);
	else
		return nullptr;
}

void NiGeometry::SetBSProperty(short index, Niflib::Ref<NiProperty> value) {
	if (index == 0)
		shaderProperty = DynamicCast<BSShaderProperty>(value);
	else if (index == 1)
		alphaProperty = DynamicCast<NiAlphaProperty>(value);
}

Niflib::array<2, Ref<NiProperty > > Niflib::NiGeometry::GetBSProperties() {
	return Niflib::array<2, Ref<NiProperty>>(2, StaticCast<NiProperty>(shaderProperty), StaticCast<NiProperty>(alphaProperty));
}

void Niflib::NiGeometry::SetBSProperties(Niflib::array<2, Ref<NiProperty> > value) {
	shaderProperty = DynamicCast<BSShaderProperty>(value[0]);
	alphaProperty = DynamicCast<NiAlphaProperty>(value[1]);
}


Ref<BSShaderProperty> Niflib::NiGeometry::GetShaderProperty() const
{
	return shaderProperty;
}
void Niflib::NiGeometry::SetShaderProperty(Ref<BSShaderProperty> value)
{
	shaderProperty = value;
}

Ref<NiAlphaProperty> Niflib::NiGeometry::GetAlphaProperty() const
{
	return alphaProperty;
}
void Niflib::NiGeometry::SetAlphaProperty(Ref<NiAlphaProperty> value)
{
	alphaProperty = value;
}

//--END CUSTOM CODE--//
