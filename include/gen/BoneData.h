/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BONEDATA_H_
#define _BONEDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "SkinTransform.h"
#include "NiBound.h"
#include "BoneVertData.h"
namespace Niflib {


/*! NiSkinData::BoneData. Skinning data component. */
struct BoneData {
	/*! Default Constructor */
	NIFLIB_API BoneData();
	/*! Default Destructor */
	NIFLIB_API ~BoneData();
	/*! Copy Constructor */
	NIFLIB_API BoneData( const BoneData & src );
	/*! Copy Operator */
	NIFLIB_API BoneData & operator=( const BoneData & src );
	/*! Offset of the skin from this bone in bind position. */
	SkinTransform skinTransform;
	/*! Note that it's a Sphere Containing Axis Aligned Box not a minimum volume Sphere */
	NiBound boundingSphere;
	/*! Number of weighted vertices. */
	mutable unsigned short numVertices;
	/*! The vertex weights. */
	vector<BoneVertData > vertexWeights;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
