/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/BoneVertData.h"
using namespace Niflib;

//Constructor
BoneVertData::BoneVertData() : index((unsigned short)0), weight(0.0f) {};

//Copy Constructor
BoneVertData::BoneVertData( const BoneVertData & src ) {
	*this = src;
};

//Copy Operator
BoneVertData & BoneVertData::operator=( const BoneVertData & src ) {
	this->index = src.index;
	this->weight = src.weight;
	return *this;
};

//Destructor
BoneVertData::~BoneVertData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
