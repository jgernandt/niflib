/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _NIBOUND_H_
#define _NIBOUND_H_

#include "../NIF_IO.h"

// Include structures
#include "NiBoundAABB.h"
namespace Niflib {


/*! A sphere. */
struct NiBound {
	/*! Default Constructor */
	NIFLIB_API NiBound();
	/*! Default Destructor */
	NIFLIB_API ~NiBound();
	/*! Copy Constructor */
	NIFLIB_API NiBound( const NiBound & src );
	/*! Copy Operator */
	NIFLIB_API NiBound & operator=( const NiBound & src );
	/*! The sphere's center. */
	Vector3 center;
	/*! The sphere's radius. */
	float radius;
	/*! Unknown. */
	NiBoundAABB div2Aabb;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
