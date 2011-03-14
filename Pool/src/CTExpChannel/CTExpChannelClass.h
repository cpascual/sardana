//=============================================================================
//
// file :         CTExpChannelClass.h
//
// description :  Include for the CTExpChannelClass root class.
//                This class is represents the singleton class for
//                the CTExpChannel device class.
//                It contains all properties and methods which the 
//                CTExpChannel requires only once e.g. the commands.
//			
// project :      TANGO Device Server
//
// $Author$
//
// $Revision$
//
// $Log$
// Revision 1.5  2007/07/26 07:05:42  tcoutinho
// fix bug 10 : Change all tango commands from Stop to Abort
//
// Revision 1.4  2007/01/30 15:56:29  etaurel
// - Fix some memory leaks
// - Value is now a Double attribute
//
// Revision 1.3  2007/01/16 16:50:04  etaurel
// - It's now possible to write the Value attribute
//
// Revision 1.2  2007/01/16 14:23:19  etaurel
// - First release with Counter Timer
//
// Revision 1.1  2007/01/05 15:03:15  etaurel
// - First implementation of the Counter Timer class
//
//
// copyleft :   CELLS/ALBA
//		Edifici Ciences Nord
//		Campus Universitari de Bellaterra
//		Universitat Autonoma de Barcelona
//		08193 Bellaterra, Barcelona, SPAIN
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//=============================================================================

#ifndef _CTEXPCHANNELCLASS_H
#define _CTEXPCHANNELCLASS_H

#include <tango.h>
#include <CTExpChannel.h>


namespace CTExpChannel_ns
{//=====================================
//	Define classes for attributes
//=====================================
/**
 * The class for the Position attribute
 */
class SimulationModeAttrib: public Tango::Attr
{
public:
	SimulationModeAttrib():Attr("SimulationMode", Tango::DEV_BOOLEAN, Tango::READ_WRITE) {};
	~SimulationModeAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<CTExpChannel *>(dev))->read_SimulationMode(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<CTExpChannel *>(dev))->write_SimulationMode(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<CTExpChannel *>(dev))->is_SimulationMode_allowed(ty);}
};

// InstrumentAttrib
class InstrumentAttrib: public Tango::Attr
{
public:
	InstrumentAttrib():Attr("Instrument", Tango::DEV_STRING, Tango::READ_WRITE) {};
	~InstrumentAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<CTExpChannel *>(dev))->read_Instrument(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<CTExpChannel *>(dev))->write_Instrument(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<CTExpChannel *>(dev))->is_Instrument_allowed(ty);}
};

/**
 * The class for the Position attribute
 */
class ValueAttrib: public Tango::Attr
{
public:
	ValueAttrib():Attr("Value", Tango::DEV_DOUBLE, Tango::READ_WRITE) {};
	~ValueAttrib() {};
	
	virtual void read(Tango::DeviceImpl *dev,Tango::Attribute &att)
	{(static_cast<CTExpChannel *>(dev))->read_Value(att);}
	virtual void write(Tango::DeviceImpl *dev,Tango::WAttribute &att)
	{(static_cast<CTExpChannel *>(dev))->write_Value(att);}
	virtual bool is_allowed(Tango::DeviceImpl *dev,Tango::AttReqType ty)
	{return (static_cast<CTExpChannel *>(dev))->is_Value_allowed(ty);}
};

//=========================================
//	Define classes for commands
//=========================================
/**
 * The class for the Position command
 */
class AbortCmd : public Tango::Command
{
public:
	AbortCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	AbortCmd(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~AbortCmd() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<CTExpChannel *>(dev))->is_Abort_allowed(any);}
};


/**
 * The class for the Position command
 */
class StartClass : public Tango::Command
{
public:
	StartClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out,
				   const char        *in_desc,
				   const char        *out_desc,
				   Tango::DispLevel  level)
	:Command(name,in,out,in_desc,out_desc, level)	{};

	StartClass(const char   *name,
	               Tango::CmdArgType in,
				   Tango::CmdArgType out)
	:Command(name,in,out)	{};
	~StartClass() {};
	
	virtual CORBA::Any *execute (Tango::DeviceImpl *dev, const CORBA::Any &any);
	virtual bool is_allowed (Tango::DeviceImpl *dev, const CORBA::Any &any)
	{return (static_cast<CTExpChannel *>(dev))->is_Start_allowed(any);}
};



/**
 * The CTExpChannelClass singleton definition
 */
class CTExpChannelClass : public Tango::DeviceClass
{
public:
//	properties member data

//	add your own data members here
//------------------------------------

	long 			nb_static_attr;
	bool			first_call_to_device_factory;

public:
	Tango::DbData	cl_prop;
	Tango::DbData	cl_def_prop;
	Tango::DbData	dev_def_prop;

//	Method prototypes
	static CTExpChannelClass *init(const char *);
	static CTExpChannelClass *instance();
	~CTExpChannelClass();
	Tango::DbDatum	get_class_property(string &);
	Tango::DbDatum	get_default_device_property(string &);
	Tango::DbDatum	get_default_class_property(string &);
	
protected:
	CTExpChannelClass(string &);
	static CTExpChannelClass *_instance;
	void command_factory();
	void get_class_property();
	void attribute_factory(vector<Tango::Attr *> &);
	void write_class_property();
	void set_default_property();

private:
	void device_factory(const Tango::DevVarStringArray *);
};


}	//	namespace CTExpChannel_ns

#endif // _CTEXPCHANNELCLASS_H