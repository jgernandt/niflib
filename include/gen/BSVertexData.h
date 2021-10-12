/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BSVERTEXDATA_H_
#define _BSVERTEXDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "HalfVector3.h"
#include "HalfTexCoord.h"
#include "ByteVector3.h"
#include "ByteColor4.h"
namespace Niflib {


/*!  */
struct BSVertexData {
	/*! Default Constructor */
	NIFLIB_API BSVertexData();
	/*! Default Destructor */
	NIFLIB_API ~BSVertexData();
	/*! Copy Constructor */
	NIFLIB_API BSVertexData( const BSVertexData & src );
	/*! Copy Operator */
	NIFLIB_API BSVertexData & operator=( const BSVertexData & src );
	/*! Unknown. */
	Vector3 vertex;
	/*! Unknown. */
	float bitangentX;
	/*! Unknown. */
	unsigned int unusedW;
	/*! Unknown. */
	HalfTexCoord uv;
	/*! Unknown. */
	ByteVector3 normal;
	/*! Unknown. */
	byte bitangentY;
	/*! Unknown. */
	ByteVector3 tangent;
	/*! Unknown. */
	byte bitangentZ;
	/*! Unknown. */
	ByteColor4 vertexColors;
	/*! Unknown. */
	array<4,unsigned short > boneWeights;
	/*! Unknown. */
	array<4,byte > boneIndices;
	/*! Unknown. */
	float eyeData;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
