/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BSVertexDesc.h"
using namespace Niflib;

//Constructor
BSVertexDesc::BSVertexDesc() : bitfield((unsigned long long)0) {};

//Copy Constructor
BSVertexDesc::BSVertexDesc( const BSVertexDesc & src ) {
	*this = src;
};

//Copy Operator
BSVertexDesc & BSVertexDesc::operator=( const BSVertexDesc & src ) {
	this->bitfield = src.bitfield;
	return *this;
};

//Destructor
BSVertexDesc::~BSVertexDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
