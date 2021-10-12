/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/NiParticleInfo.h"
using namespace Niflib;

//Constructor
NiParticleInfo::NiParticleInfo() : age(0.0f), lifeSpan(0.0f), lastUpdate(0.0f), spawnGeneration((unsigned short)0), code((unsigned short)0) {};

//Copy Constructor
NiParticleInfo::NiParticleInfo( const NiParticleInfo & src ) {
	*this = src;
};

//Copy Operator
NiParticleInfo & NiParticleInfo::operator=( const NiParticleInfo & src ) {
	this->velocity = src.velocity;
	this->rotationAxis = src.rotationAxis;
	this->age = src.age;
	this->lifeSpan = src.lifeSpan;
	this->lastUpdate = src.lastUpdate;
	this->spawnGeneration = src.spawnGeneration;
	this->code = src.code;
	return *this;
};

//Destructor
NiParticleInfo::~NiParticleInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
