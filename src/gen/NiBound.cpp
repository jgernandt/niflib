/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiBoundAABB.h"
using namespace Niflib;

//Constructor
NiBound::NiBound() : radius(0.0f) {};

//Copy Constructor
NiBound::NiBound( const NiBound & src ) {
	*this = src;
};

//Copy Operator
NiBound & NiBound::operator=( const NiBound & src ) {
	this->center = src.center;
	this->radius = src.radius;
	this->div2Aabb = src.div2Aabb;
	return *this;
};

//Destructor
NiBound::~NiBound() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
