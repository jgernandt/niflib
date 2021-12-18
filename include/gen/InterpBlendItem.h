/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _INTERPBLENDITEM_H_
#define _INTERPBLENDITEM_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;

/*! Interpolator item for array in NiBlendInterpolator. */
struct InterpBlendItem {
	/*! Default Constructor */
	NIFLIB_API InterpBlendItem();
	/*! Default Destructor */
	NIFLIB_API ~InterpBlendItem();
	/*! Copy Constructor */
	NIFLIB_API InterpBlendItem( const InterpBlendItem & src );
	/*! Copy Operator */
	NIFLIB_API InterpBlendItem & operator=( const InterpBlendItem & src );
	/*! Reference to an interpolator. */
	Ref<NiInterpolator > interpolator;
	/*! Unknown. */
	float weight;
	/*! Unknown. */
	float normalizedWeight;
	/*! Unknown. */
	int priority;
	/*! Unknown. */
	float easeSpinner;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
