/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERDECLINATIONVARCTLR_H_
#define _NIPSYSEMITTERDECLINATIONVARCTLR_H_

#include "xml_extract.h"
#include NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_INCLUDE

/*
 * NiPSysEmitterDeclinationVarCtlr
 */

class NiPSysEmitterDeclinationVarCtlr;
typedef Ref<NiPSysEmitterDeclinationVarCtlr> NiPSysEmitterDeclinationVarCtlrRef;

class NiPSysEmitterDeclinationVarCtlr : public NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT {
public:
  NiPSysEmitterDeclinationVarCtlr();
  ~NiPSysEmitterDeclinationVarCtlr();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS
};

#endif