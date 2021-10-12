/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/BSPSysSimpleColorModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSPSysSimpleColorModifier::TYPE("BSPSysSimpleColorModifier", &NiPSysModifier::TYPE );

BSPSysSimpleColorModifier::BSPSysSimpleColorModifier() : fadeInPercent(0.0f), fadeOutPercent(0.0f), color1EndPercent(0.0f), color1StartPercent(0.0f), color2EndPercent(0.0f), color2StartPercent(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSPSysSimpleColorModifier::~BSPSysSimpleColorModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSPSysSimpleColorModifier::GetType() const {
	return TYPE;
}

NiObject * BSPSysSimpleColorModifier::Create() {
	return new BSPSysSimpleColorModifier;
}

void BSPSysSimpleColorModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysModifier::Read( in, link_stack, info );
	NifStream( fadeInPercent, in, info );
	NifStream( fadeOutPercent, in, info );
	NifStream( color1EndPercent, in, info );
	NifStream( color1StartPercent, in, info );
	NifStream( color2EndPercent, in, info );
	NifStream( color2StartPercent, in, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( colors[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSPSysSimpleColorModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysModifier::Write( out, link_map, missing_link_stack, info );
	NifStream( fadeInPercent, out, info );
	NifStream( fadeOutPercent, out, info );
	NifStream( color1EndPercent, out, info );
	NifStream( color1StartPercent, out, info );
	NifStream( color2EndPercent, out, info );
	NifStream( color2StartPercent, out, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( colors[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSPSysSimpleColorModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Fade In Percent:  " << fadeInPercent << endl;
	out << "  Fade out Percent:  " << fadeOutPercent << endl;
	out << "  Color 1 End Percent:  " << color1EndPercent << endl;
	out << "  Color 1 Start Percent:  " << color1StartPercent << endl;
	out << "  Color 2 End Percent:  " << color2EndPercent << endl;
	out << "  Color 2 Start Percent:  " << color2StartPercent << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Colors[" << i1 << "]:  " << colors[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSPSysSimpleColorModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSysModifier::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSPSysSimpleColorModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

std::list<NiObject *> BSPSysSimpleColorModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysModifier::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

float BSPSysSimpleColorModifier::GetFadeInEnd() const
{
	return fadeInPercent;
}
void BSPSysSimpleColorModifier::SetFadeInEnd(float f)
{
	fadeInPercent = f;
}

float BSPSysSimpleColorModifier::GetFadeOutBegin() const
{
	return fadeOutPercent;
}
void BSPSysSimpleColorModifier::SetFadeOutBegin(float f)
{
	fadeOutPercent = f;
}

float BSPSysSimpleColorModifier::GetColor1End() const
{
	return color1EndPercent;
}
void BSPSysSimpleColorModifier::SetColor1End(float f)
{
	color1EndPercent = f;
}

float BSPSysSimpleColorModifier::GetColor2Begin() const
{
	return color1StartPercent;
}
void BSPSysSimpleColorModifier::SetColor2Begin(float f)
{
	color1StartPercent = f;
}

float BSPSysSimpleColorModifier::GetColor2End() const
{
	return color2EndPercent;
}
void BSPSysSimpleColorModifier::SetColor2End(float f)
{
	color2EndPercent = f;
}

float BSPSysSimpleColorModifier::GetColor3Begin() const
{
	return color2StartPercent;
}
void BSPSysSimpleColorModifier::SetColor3Begin(float f)
{
	color2StartPercent = f;
}

#include <cassert>
const Color4& BSPSysSimpleColorModifier::GetColor(int i) const
{
	assert(i < 3 && i >= 0);
	return colors[i];
}
void BSPSysSimpleColorModifier::SetColor(int i, const Color4& c)
{
	assert(i < 3 && i >= 0);
	colors[i] = c;
}

const Niflib::array<3, Color4>& BSPSysSimpleColorModifier::GetColors() const
{
	return colors;
}
void BSPSysSimpleColorModifier::SetColors(const Niflib::array<3, Color4>& c)
{
	colors = c;
}

//--END CUSTOM CODE--//
