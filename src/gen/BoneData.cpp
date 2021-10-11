/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BoneData.h"
#include "../../include/gen/SkinTransform.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiBoundAABB.h"
#include "../../include/gen/BoneVertData.h"
#include "../../include/gen/BoneVertData.h"
using namespace Niflib;

//Constructor
BoneData::BoneData() : numVertices((unsigned short)0) {};

//Copy Constructor
BoneData::BoneData( const BoneData & src ) {
	*this = src;
};

//Copy Operator
BoneData & BoneData::operator=( const BoneData & src ) {
	this->skinTransform = src.skinTransform;
	this->boundingSphere = src.boundingSphere;
	this->numVertices = src.numVertices;
	this->vertexWeights = src.vertexWeights;
	return *this;
};

//Destructor
BoneData::~BoneData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
