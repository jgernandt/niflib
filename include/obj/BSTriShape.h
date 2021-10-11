/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSTRISHAPE_H_
#define _BSTRISHAPE_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiAVObject.h"

// Include structures
#include "../gen/NiBound.h"
#include "../Ref.h"
#include "../gen/BSVertexDesc.h"
#include "../gen/BSVertexData.h"
#include "../gen/BSVertexDataSSE.h"
#include "../gen/HalfVector3.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;
class BSShaderProperty;
class NiAlphaProperty;
class BSTriShape;
typedef Ref<BSTriShape> BSTriShapeRef;

/*! Fallout 4 Tri Shape */
class BSTriShape : public NiAVObject {
public:
	/*! Constructor */
	NIFLIB_API BSTriShape();

	/*! Destructor */
	NIFLIB_API virtual ~BSTriShape();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

private:
	//The must be overridable, since blocks like BSDynamicTriShape exist that keep the data in a separate field
	virtual unsigned int dataSizeCalc(const Niflib::NifInfo& info) const;
	virtual unsigned short numVerticesCalc(const Niflib::NifInfo& info) const;

	//--END CUSTOM CODE--//
protected:
	/*! Unknown. */
	NiBound boundingSphere;
	/*! Unknown. */
	array<6,float > boundMinMax;
	/*! Unknown. */
	Ref<NiObject > skin;
	/*! Unknown. */
	Ref<BSShaderProperty > shaderProperty;
	/*! Unknown. */
	Ref<NiAlphaProperty > alphaProperty;
	/*! Unknown. */
	BSVertexDesc vertexDesc;
	/*! Unknown. */
	mutable unsigned int numTriangles;
	/*! Unknown. */
	mutable unsigned short numVertices;
	/*! Unknown. */
	mutable unsigned int dataSize;
	/*! Unknown. */
	vector<BSVertexData > vertexData;
	/*! Unknown. */
	vector<Triangle > triangles;
	/*! Unknown. */
	unsigned int particleDataSize;
	/*! Unknown. */
	vector<HalfVector3 > particleVertices;
	/*! Unknown. */
	vector<HalfVector3 > particleNormals;
	/*! Unknown. */
	vector<Triangle > trianglesCopy;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
