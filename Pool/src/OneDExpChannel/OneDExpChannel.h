//=============================================================================
//
// file :        OneDExpChannel.h
//
// description : Include for the OneDExpChannel class.
//
// project :	OneDimensionExperimentalChannel
//
// $Author:  $
//
// $Revision:  $
//
// $Log:  $
//
// copyleft :    European Synchrotron Radiation Facility
//               BP 220, Grenoble 38043
//               FRANCE
//
//=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================
#ifndef _ONEDEXPCHANEL_H
#define _ONEDEXPCHANEL_H

#include "PoolIndBaseDev.h"

//#include <tango.h>
//using namespace Tango;
namespace Pool_ns
{
    struct OneDExpChannelPool;
}

/**
 * @author	$Author:  $
 * @version	$Revision:  $
 */

 //	Add your own constants definitions here.
 //-----------------------------------------------


namespace OneDExpChannel_ns
{

class OneDThread;
/**
 * Class Description:
 * One Dimension Experiment device used by the Sardana project device pool
 */

/*
 *	Device States Description:
*  Tango::ON :       The experiment channel is ON
*  Tango::FAULT :    A fault has been reported by the device controller
*  Tango::UNKNOWN :  Impossible to communicate with the device controller
*  Tango::MOVING :   An acquisition is running
 */


//class OneDExpChannel: public Tango::Device_4Impl
class OneDExpChannel: public Pool_ns::PoolIndBaseDev
{
public :
	//	Add your own data members here
	//-----------------------------------------


	//	Here is the Start of the automatic code generation part
	//-------------------------------------------------------------	
/**
 *	@name attributes
 *	Attributs member data.
 */
//@{
		Tango::DevLong	*attr_DataLength_read;
		Tango::DevLong	attr_DataLength_write;
		Tango::DevDouble	*attr_Data_read;
		Tango::DevDouble	*attr_Value_read;
//@}

/**
 *	@name Device properties
 *	Device properties member data.
 */
//@{
/**
 *	Maximum Length of the spectrum data
 */
	Tango::DevLong	maxDataLength;
//@}

/**@name Constructors
 * Miscellaneous constructors */
//@{
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	OneDExpChannel(Tango::DeviceClass *cl,string &s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device Name
 */
	OneDExpChannel(Tango::DeviceClass *cl,const char *s);
/**
 * Constructs a newly allocated Command object.
 *
 *	@param cl	Class.
 *	@param s 	Device name
 *	@param d	Device description.
 */
	OneDExpChannel(Tango::DeviceClass *cl,const char *s,const char *d);
//@}

/**@name Destructor
 * Only one desctructor is defined for this class */
//@{
/**
 * The object desctructor.
 */	
	~OneDExpChannel() {delete_device();};
/**
 *	will be called at device destruction or at init command.
 */
	void delete_device();
//@}

	
/**@name Miscellaneous methods */
//@{
/**
 *	Initialize the device
 */
	virtual void init_device();
/**
 *	Always executed method befor execution command method.
 */
	virtual void always_executed_hook();

//@}

/**
 * @name OneDExpChannel methods prototypes
 */

//@{
/**
 *	Hardware acquisition for attributes.
 */
	virtual void read_attr_hardware(vector<long> &attr_list);
/**
 *	Extract real attribute values for DataLength acquisition result.
 */
	virtual void read_DataLength(Tango::Attribute &attr);
/**
 *	Write DataLength attribute values to hardware.
 */
	virtual void write_DataLength(Tango::WAttribute &attr);
/**
 *	Extract real attribute values for Data acquisition result.
 */
	virtual void read_Data(Tango::Attribute &attr);
/**
 *	Extract real attribute values for Value acquisition result.
 */
	virtual void read_Value(Tango::Attribute &attr);
/**
 *	Read/Write allowed for DataLength attribute.
 */
	virtual bool is_DataLength_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for Data attribute.
 */
	virtual bool is_Data_allowed(Tango::AttReqType type);
/**
 *	Read/Write allowed for Value attribute.
 */
	virtual bool is_Value_allowed(Tango::AttReqType type);
/**
 *	Execution allowed for Start command.
 */
	virtual bool is_Start_allowed(const CORBA::Any &any);
/**
 *	Execution allowed for Abort command.
 */
	virtual bool is_Abort_allowed(const CORBA::Any &any);
/**
 * Start acquiring data
 *	@exception DevFailed
 */
	void	start();
/**
 * Stop acquiring data
 *	@exception DevFailed
 */
	void	abort();

/**
 *	Read the device properties from database
 */
	 void get_device_property();
//@}

	//	Here is the end of the automatic code generation part
	//-------------------------------------------------------------	

    Pool_ns::OneDExpChannelPool &get_oned_element();

protected :	
	//	Add your own data members here
	//-----------------------------------------

	
public:
	struct ShData
	{
		bool							th_exit;
		bool							i_am_dead;
		long							error_nb;
		bool							cont_error;
		bool							stop_if_no_time;
		long							cum_time;
		long							cum_type;
		vector<double>					read_values;
		vector<double>					acq_dates;
		Tango::DevErrorList				errors;
		long							fire_event;
		struct timespec					sleep_time;
	};
	
protected:	
	
    double			read_value;
	double			cum_read_value;
	Tango::DevLong	cum_nb;
	Tango::DevLong	cum_err;
	
	OneDThread		*th;	
	omni_mutex		the_mutex;
	ShData			the_shared_data;
	
	struct Simu_data
	{	
		double				simu_time;
		long				simu_type;
		OneDExpChannel		*channel;
		
		Simu_data(OneDExpChannel *);
		~Simu_data();
	};
	
	Simu_data			*save_atts;

	void inform_ghost(Tango::DevState,Tango::DevState);

    /**
     * This command gets the device status (stored in its <i>device_status</i> dat
     * a member) and returns it to the caller.
     *      @return Status description
     *      @exception DevFailed
     */
	virtual Tango::ConstDevString   dev_status();
	
	
public:	
	virtual void base_abort(bool);
	void save_att_values() {save_atts = new Simu_data(this);}
	void restore_att_values() {if (save_atts!=NULL){delete save_atts;save_atts=NULL;}}

    virtual void pool_elem_changed(Pool_ns::PoolElemEventList &, Pool_ns::PoolElementEvent &) {}
};

}	// namespace_ns

#endif	// _ONEDEXPCHANEL_H