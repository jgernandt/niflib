/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/InterpBlendItem.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Constructor
InterpBlendItem::InterpBlendItem() : interpolator(NULL), weight(0.0f), normalizedWeight(0.0f), priority((int)0), easeSpinner(0.0f) {};

//Copy Constructor
InterpBlendItem::InterpBlendItem( const InterpBlendItem & src ) {
	*this = src;
};

//Copy Operator
InterpBlendItem & InterpBlendItem::operator=( const InterpBlendItem & src ) {
	this->interpolator = src.interpolator;
	this->weight = src.weight;
	this->normalizedWeight = src.normalizedWeight;
	this->priority = src.priority;
	this->easeSpinner = src.easeSpinner;
	return *this;
};

//Destructor
InterpBlendItem::~InterpBlendItem() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
