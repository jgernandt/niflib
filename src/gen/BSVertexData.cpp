/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BSVertexData.h"
#include "../../include/gen/HalfVector3.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
using namespace Niflib;

//Constructor
BSVertexData::BSVertexData() : bitangentX(0.0f), unusedW((unsigned int)0), bitangentY((byte)0), bitangentZ((byte)0), eyeData(0.0f) {};

//Copy Constructor
BSVertexData::BSVertexData( const BSVertexData & src ) {
	*this = src;
};

//Copy Operator
BSVertexData & BSVertexData::operator=( const BSVertexData & src ) {
	this->vertex = src.vertex;
	this->bitangentX = src.bitangentX;
	this->unusedW = src.unusedW;
	this->uv = src.uv;
	this->normal = src.normal;
	this->bitangentY = src.bitangentY;
	this->tangent = src.tangent;
	this->bitangentZ = src.bitangentZ;
	this->vertexColors = src.vertexColors;
	this->boneWeights = src.boneWeights;
	this->boneIndices = src.boneIndices;
	this->eyeData = src.eyeData;
	return *this;
};

//Destructor
BSVertexData::~BSVertexData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
