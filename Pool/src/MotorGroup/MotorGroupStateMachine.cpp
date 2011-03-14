//+=============================================================================
//
// file :         MotorGroupStateMachine.cpp
//
// description :  C++ source for the MotorGroup and its alowed. 
//                method for commands and attributes
//
// project :      TANGO Device Server
//
// $Author$
//
// $Revision$
//
// $Log$
// Revision 1.4  2007/04/30 14:51:20  tcoutinho
// - make possible to Add/Remove elements on motorgroup that are part of other motor group(s)
//
// Revision 1.3  2007/04/23 15:18:59  tcoutinho
// - first changes according to Sardana metting 26-03-2007: identical motor groups can be created, Add/Remove element from a MG, etc
//
// Revision 1.2  2006/07/07 12:40:19  etaurel
// - Commit after implementing the group multi motor read
//
// Revision 1.1  2006/03/29 07:09:59  etaurel
// - Added motor group features
//
// copyleft :     CELLS/ALBA
//				  Edifici Ciències Nord. Mòdul C-3 central.
//  			  Campus Universitari de Bellaterra. Universitat Autònoma de Barcelona
//  			  08193 Bellaterra, Barcelona
//  			  Spain
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#include "MotorGroup.h"
#include "MotorGroupClass.h"
#include <tango.h>

/*====================================================================
 *	This file contains the methods to allow commands and attributes
 * read or write execution.
 *
 * If you wand to add your own code, add it between 
 * the "End/Re-Start of Generated Code" comments.
 *
 * If you want, you can also add your own methods.
 *====================================================================
 */

namespace MotorGroup_ns
{

//=================================================
//		Attributes Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_Position_allowed
// 
// description : 	Read/Write allowed for Position attribute.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_Position_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_Elements_allowed
// 
// description : 	Read/Write allowed for Elements attribute.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_Elements_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_Motors_allowed
// 
// description : 	Read/Write allowed for Motors attribute.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_Motors_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_MotorGroups_allowed
// 
// description : 	Read/Write allowed for MotorGroups attribute.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_MotorGroups_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_PseudoMotors_allowed
// 
// description : 	Read/Write allowed for PseudoMotors attribute.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_PseudoMotors_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_Abort_allowed
// 
// description : 	Execution allowed for Abort command.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_Abort_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_AddElement_allowed
// 
// description : 	Execution allowed for AddElement command.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_AddElement_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::MOVING	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::UNKNOWN)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		MotorGroup::is_RemoveElement_allowed
// 
// description : 	Execution allowed for RemoveElement command.
//
//-----------------------------------------------------------------------------
bool MotorGroup::is_RemoveElement_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::MOVING	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::UNKNOWN)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}


}	// namespace MotorGroup_ns