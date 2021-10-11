/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/NiBoundAABB.h"
using namespace Niflib;

//Constructor
NiBoundAABB::NiBoundAABB() : numCorners((unsigned short)2) {};

//Copy Constructor
NiBoundAABB::NiBoundAABB( const NiBoundAABB & src ) {
	*this = src;
};

//Copy Operator
NiBoundAABB & NiBoundAABB::operator=( const NiBoundAABB & src ) {
	this->numCorners = src.numCorners;
	this->corners = src.corners;
	return *this;
};

//Destructor
NiBoundAABB::~NiBoundAABB() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
