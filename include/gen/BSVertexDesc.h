/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BSVERTEXDESC_H_
#define _BSVERTEXDESC_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct BSVertexDesc {
	/*! Default Constructor */
	NIFLIB_API BSVertexDesc();
	/*! Default Destructor */
	NIFLIB_API ~BSVertexDesc();
	/*! Copy Constructor */
	NIFLIB_API BSVertexDesc( const BSVertexDesc & src );
	/*! Copy Operator */
	NIFLIB_API BSVertexDesc & operator=( const BSVertexDesc & src );
	/*! The raw data of this bitfield */
	unsigned long long bitfield;
	//--BEGIN MISC CUSTOM CODE--//

	operator unsigned long long() const { return bitfield; }

	unsigned int GetVertexDataSize() const { return static_cast<unsigned int>(UnpackField(bitfield, 0, 4)); }
	void SetVertexDataSize(unsigned int val) { PackField(bitfield, val, 0, 4); }

	unsigned int GetDynamicVertexSize() const { return static_cast<unsigned int>(UnpackField(bitfield, 4, 4)); }
	void SetDynamicVertexSize(unsigned int val) { PackField(bitfield, val, 4, 4); }

	unsigned int GetUV1Offset() const { return static_cast<unsigned int>(UnpackField(bitfield, 8, 4)); }
	void SetUV1Offset(unsigned int val) { PackField(bitfield, val, 8, 4); }

	unsigned int GetUV2Offset() const { return static_cast<unsigned int>(UnpackField(bitfield, 12, 4)); }
	void SetUV2Offset(unsigned int val) { PackField(bitfield, val, 12, 4); }

	unsigned int GetNormalOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 16, 4)); }
	void SetNormalOffset(unsigned int val) { PackField(bitfield, val, 16, 4); }

	unsigned int GetTangentOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 20, 4)); }
	void SetTangentOffset(unsigned int val) { PackField(bitfield, val, 20, 4); }

	unsigned int GetColorOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 24, 4)); }
	void SetColorOffset(unsigned int val) { PackField(bitfield, val, 24, 4); }

	unsigned int GetSkinningDataOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 28, 4)); }
	void SetSkinningDataOffset(unsigned int val) { PackField(bitfield, val, 28, 4); }

	unsigned int GetLandscapeDataOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 32, 4)); }
	void SetLandscapeDataOffset(unsigned int val) { PackField(bitfield, val, 32, 4); }

	unsigned int GetEyeDataOffset() const { return static_cast<unsigned int>(UnpackField(bitfield, 36, 4)); }
	void SetEyeDataOffset(unsigned int val) { PackField(bitfield, val, 36, 4); }

	unsigned int GetUnused01() const { return static_cast<unsigned int>(UnpackField(bitfield, 40, 4)); }
	void SetUnused01(unsigned int val) { PackField(bitfield, val, 40, 4); }

	unsigned short GetVertexAttributes() const { return static_cast<unsigned short>(UnpackField(bitfield, 44, 12)); }
	void SetVertexAttributes(unsigned short val) { PackField(bitfield, val, 44, 12); }

	unsigned int GetUnknown02() const { return static_cast<unsigned int>(UnpackField(bitfield, 56, 8)); }
	void SetUnknown02(unsigned int val) { PackField(bitfield, val, 56, 8); }

	//--END CUSTOM CODE--//
};

}
#endif
