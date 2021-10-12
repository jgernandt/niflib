/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/MaterialData.h"
using namespace Niflib;

//Constructor
MaterialData::MaterialData() : hasShader(false), shaderExtraData((int)0), numMaterials((unsigned int)0), activeMaterial((int)-1), cyanideUnknown((byte)255), worldshiftUnknown((int)0), materialNeedsUpdate(false) {};

//Copy Constructor
MaterialData::MaterialData( const MaterialData & src ) {
	*this = src;
};

//Copy Operator
MaterialData & MaterialData::operator=( const MaterialData & src ) {
	this->hasShader = src.hasShader;
	this->shaderName = src.shaderName;
	this->shaderExtraData = src.shaderExtraData;
	this->numMaterials = src.numMaterials;
	this->materialName = src.materialName;
	this->materialExtraData = src.materialExtraData;
	this->activeMaterial = src.activeMaterial;
	this->cyanideUnknown = src.cyanideUnknown;
	this->worldshiftUnknown = src.worldshiftUnknown;
	this->materialNeedsUpdate = src.materialNeedsUpdate;
	return *this;
};

//Destructor
MaterialData::~MaterialData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
