/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BSVertexDataSSE.h"
#include "../../include/gen/HalfTexCoord.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteVector3.h"
#include "../../include/gen/ByteColor4.h"
using namespace Niflib;

//Constructor
BSVertexDataSSE::BSVertexDataSSE() : bitangentX(0.0f), unusedW((unsigned int)0), bitangentY((byte)0), bitangentZ((byte)0), eyeData(0.0f) {};

//Copy Constructor
BSVertexDataSSE::BSVertexDataSSE( const BSVertexDataSSE & src ) {
	*this = src;
};

//Copy Operator
BSVertexDataSSE & BSVertexDataSSE::operator=( const BSVertexDataSSE & src ) {
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
BSVertexDataSSE::~BSVertexDataSSE() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
