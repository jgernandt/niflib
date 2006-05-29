/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKRAGDOLLCONSTRAINT_H_
#define _BHKRAGDOLLCONSTRAINT_H_

#include "xml_extract.h"
#include BHK_RAGDOLL_CONSTRAINT_INCLUDE

/*
 * bhkRagdollConstraint
 */

class bhkRagdollConstraint;
typedef Ref<bhkRagdollConstraint> bhkRagdollConstraintRef;

class bhkRagdollConstraint : public BHK_RAGDOLL_CONSTRAINT_PARENT {
public:
  bhkRagdollConstraint();
  ~bhkRagdollConstraint();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_RAGDOLL_CONSTRAINT_MEMBERS
};

#endif