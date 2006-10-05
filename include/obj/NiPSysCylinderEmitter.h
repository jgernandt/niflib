/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSCYLINDEREMITTER_H_
#define _NIPSYSCYLINDEREMITTER_H_

#include "NiPSysVolumeEmitter.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiPSysCylinderEmitter;
typedef Ref<NiPSysCylinderEmitter> NiPSysCylinderEmitterRef;

/*!
 * NiPSysCylinderEmitter - Unknown.
 */

class NIFLIB_API NiPSysCylinderEmitter : public NI_P_SYS_CYLINDER_EMITTER_PARENT {
public:
	NiPSysCylinderEmitter();
	~NiPSysCylinderEmitter();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_P_SYS_CYLINDER_EMITTER_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
