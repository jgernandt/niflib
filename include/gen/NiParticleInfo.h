/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _NIPARTICLEINFO_H_
#define _NIPARTICLEINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Called NiPerParticleData in NiOldParticles.
 *         Holds the state of a particle at the time the system was saved.
 */
struct NiParticleInfo {
	/*! Default Constructor */
	NIFLIB_API NiParticleInfo();
	/*! Default Destructor */
	NIFLIB_API ~NiParticleInfo();
	/*! Copy Constructor */
	NIFLIB_API NiParticleInfo( const NiParticleInfo & src );
	/*! Copy Operator */
	NIFLIB_API NiParticleInfo & operator=( const NiParticleInfo & src );
	/*! Particle direction and speed. */
	Vector3 velocity;
	/*! Unknown. */
	Vector3 rotationAxis;
	/*! Unknown. */
	float age;
	/*! Unknown. */
	float lifeSpan;
	/*! Timestamp of the last update. */
	float lastUpdate;
	/*! Unknown. */
	unsigned short spawnGeneration;
	/*! Usually matches array index */
	unsigned short code;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
