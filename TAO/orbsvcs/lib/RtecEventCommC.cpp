// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington 
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "RtecEventCommC.h"

#if !defined (__ACE_INLINE__)
#include "RtecEventCommC.i"
#endif // !defined INLINE

static const CORBA::Long _oc_RtecEventComm_Disconnected[] =
{
  0, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4469, 0x73636f6e, 0x6e656374, 0x65643a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/Disconnected:1.0
  13, 0x44697363, 0x6f6e6e65, 0x63746564, 0x0,  // name = Disconnected
  0, // member count
};
static CORBA::TypeCode _tc__tc_RtecEventComm_Disconnected (CORBA::tk_struct, sizeof (_oc_RtecEventComm_Disconnected), (unsigned char *) &_oc_RtecEventComm_Disconnected, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_Disconnected = &_tc__tc_RtecEventComm_Disconnected;

static const CORBA::Long _oc_RtecEventComm_EventData[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
  10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
  2, // member count
    2, 0x78000000,  // name = x
    CORBA::tk_long,

    2, 0x79000000,  // name = y
    CORBA::tk_long,

};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventData (CORBA::tk_struct, sizeof (_oc_RtecEventComm_EventData), (unsigned char *) &_oc_RtecEventComm_EventData, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventData = &_tc__tc_RtecEventComm_EventData;

static const CORBA::Long _oc_RtecEventComm_Event[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  28, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e743a, 0x312e3000,  // repository ID = IDL:RtecEventComm/Event:1.0
  6, 0x4576656e, 0x74000000,  // name = Event
  4, // member count
    8, 0x736f7572, 0x63655f00,  // name = source_
    6, 0x74797065, 0x5f000000,  // name = type_
    6, 0x74696d65, 0x5f000000,  // name = time_
    6, 0x64617461, 0x5f000000,  // name = data_
    CORBA::tk_struct, // typecode kind
    84, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
      10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
      2, // member count
        2, 0x78000000,  // name = x
        CORBA::tk_long,

        2, 0x79000000,  // name = y
        CORBA::tk_long,

    };
static CORBA::TypeCode _tc__tc_RtecEventComm_Event (CORBA::tk_struct, sizeof (_oc_RtecEventComm_Event), (unsigned char *) &_oc_RtecEventComm_Event, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_Event = &_tc__tc_RtecEventComm_Event;

// *************************************************************
// class RtecEventComm::EventSet
// *************************************************************

// copy constructor
RtecEventComm::EventSet::EventSet (const RtecEventComm::EventSet &seq)
	: maximum_ (seq.maximum_),
	  length_ (seq.length_),
	  buffer_ (RtecEventComm::EventSet::allocbuf (seq.maximum_)),
	  release_ (1) // we always own it
{
  for (CORBA::ULong i=0; i < seq.length_; i++)
  	this->buffer_[i] = seq.buffer_[i];
}

// destructor
RtecEventComm::EventSet::~EventSet (void)
{
  if (this->release_) // we own the buffer
  {
    RtecEventComm::EventSet::freebuf (this->buffer_);
  }
}

// assignment operator
RtecEventComm::EventSet& 
RtecEventComm::EventSet::operator= (const RtecEventComm::EventSet &seq)
{
  if (this == &seq) return *this;
  if (this->release_)
  {
    RtecEventComm::EventSet::freebuf (this->buffer_);
  }
  this->length_ = seq.length_;
  this->maximum_ = seq.maximum_;
  this->buffer_ = RtecEventComm::EventSet::allocbuf (seq.maximum_),
  this->release_ =1; // we always own it
  for (CORBA::ULong i=0; i < seq.length_; i++)
  	this->buffer_[i] = seq.buffer_[i];
  return *this;
}

static const CORBA::Long _oc_RtecEventComm_EventSet[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_struct, // typecode kind
  192, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    28, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e743a, 0x312e3000,  // repository ID = IDL:RtecEventComm/Event:1.0
    6, 0x4576656e, 0x74000000,  // name = Event
    4, // member count
      8, 0x736f7572, 0x63655f00,  // name = source_
      6, 0x74797065, 0x5f000000,  // name = type_
      6, 0x74696d65, 0x5f000000,  // name = time_
      6, 0x64617461, 0x5f000000,  // name = data_
      CORBA::tk_struct, // typecode kind
      84, // encapsulation length
        TAO_ENCAP_BYTE_ORDER, // byte order
        32, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f4576, 0x656e7444, 0x6174613a, 0x312e3000,  // repository ID = IDL:RtecEventComm/EventData:1.0
        10, 0x4576656e, 0x74446174, 0x61000000,  // name = EventData
        2, // member count
          2, 0x78000000,  // name = x
          CORBA::tk_long,

          2, 0x79000000,  // name = y
          CORBA::tk_long,

          0,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_EventSet (CORBA::tk_sequence, sizeof (_oc_RtecEventComm_EventSet), (unsigned char *) &_oc_RtecEventComm_EventSet, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_EventSet = &_tc__tc_RtecEventComm_EventSet;

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_duplicate (RtecEventComm::PushConsumer_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PushConsumer::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PushConsumer:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PushConsumer_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PushConsumer::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PushConsumer (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PushConsumer::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_nil (void)
{
  return (RtecEventComm::PushConsumer_ptr)NULL;
} // end of _nil

RtecEventComm::PushConsumer_ptr RtecEventComm::PushConsumer::_bind (const char *host, CORBA::ULong port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PushConsumer::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PushConsumer::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PushConsumer::_nil ();
  else // narrow it
  	return RtecEventComm::PushConsumer::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PushConsumer_push_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0},
  {RtecEventComm::_tc_EventSet, PARAM_IN, 0}
};

static const TAO_Call_Data RtecEventComm_PushConsumer_push_calldata = 
{"push", 1, 2, RtecEventComm_PushConsumer_push_paramdata, 0, 0};

void  RtecEventComm::PushConsumer::push (const RtecEventComm::EventSet & data, CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushConsumer_push_calldata, 0, &data);
  return; // no value
  
}

static const TAO_Param_Data RtecEventComm_PushConsumer_disconnect_push_consumer_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PushConsumer_disconnect_push_consumer_calldata = 
{"disconnect_push_consumer", 1, 1, RtecEventComm_PushConsumer_disconnect_push_consumer_paramdata, 0, 0};

void  RtecEventComm::PushConsumer::disconnect_push_consumer (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushConsumer_disconnect_push_consumer_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PushConsumer[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x7368436f, 0x6e73756d, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PushConsumer:1.0
  13, 0x50757368, 0x436f6e73, 0x756d6572, 0x0,  // name = PushConsumer,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PushConsumer (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PushConsumer), (unsigned char *) &_oc_RtecEventComm_PushConsumer, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PushConsumer = &_tc__tc_RtecEventComm_PushConsumer;

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_duplicate (RtecEventComm::PushSupplier_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PushSupplier::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PushSupplier:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PushSupplier_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PushSupplier::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PushSupplier (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PushSupplier::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_nil (void)
{
  return (RtecEventComm::PushSupplier_ptr)NULL;
} // end of _nil

RtecEventComm::PushSupplier_ptr RtecEventComm::PushSupplier::_bind (const char *host, CORBA::ULong port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PushSupplier::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PushSupplier::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PushSupplier::_nil ();
  else // narrow it
  	return RtecEventComm::PushSupplier::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PushSupplier_disconnect_push_supplier_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PushSupplier_disconnect_push_supplier_calldata = 
{"disconnect_push_supplier", 1, 1, RtecEventComm_PushSupplier_disconnect_push_supplier_paramdata, 0, 0};

void  RtecEventComm::PushSupplier::disconnect_push_supplier (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PushSupplier_disconnect_push_supplier_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PushSupplier[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x73685375, 0x70706c69, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PushSupplier:1.0
  13, 0x50757368, 0x53757070, 0x6c696572, 0x0,  // name = PushSupplier,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PushSupplier (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PushSupplier), (unsigned char *) &_oc_RtecEventComm_PushSupplier, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PushSupplier = &_tc__tc_RtecEventComm_PushSupplier;

RtecEventComm::PullSupplier_ptr RtecEventComm::PullSupplier::_duplicate (RtecEventComm::PullSupplier_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PullSupplier_ptr RtecEventComm::PullSupplier::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PullSupplier::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PullSupplier:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PullSupplier_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PullSupplier::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PullSupplier (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PullSupplier::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PullSupplier_ptr RtecEventComm::PullSupplier::_nil (void)
{
  return (RtecEventComm::PullSupplier_ptr)NULL;
} // end of _nil

RtecEventComm::PullSupplier_ptr RtecEventComm::PullSupplier::_bind (const char *host, CORBA::ULong port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PullSupplier::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PullSupplier::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PullSupplier::_nil ();
  else // narrow it
  	return RtecEventComm::PullSupplier::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PullSupplier_pull_paramdata [] = 
{
  {RtecEventComm::_tc_Event, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PullSupplier_pull_calldata = 
{"pull", 1, 1, RtecEventComm_PullSupplier_pull_paramdata, 0, 0};

RtecEventComm::Event  RtecEventComm::PullSupplier::pull (CORBA::Environment &env)
{
  RtecEventComm::Event retval;
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return retval;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PullSupplier_pull_calldata, &retval);
  return retval;
  
}

static const TAO_Param_Data RtecEventComm_PullSupplier_try_pull_paramdata [] = 
{
  {RtecEventComm::_tc_Event, PARAM_RETURN, 0},
  {CORBA::_tc_boolean, PARAM_OUT, 0}
};

static const TAO_Call_Data RtecEventComm_PullSupplier_try_pull_calldata = 
{"try_pull", 1, 2, RtecEventComm_PullSupplier_try_pull_paramdata, 0, 0};

RtecEventComm::Event  RtecEventComm::PullSupplier::try_pull (CORBA::Boolean_out has_event, CORBA::Environment &env)
{
  RtecEventComm::Event retval;
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return retval;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PullSupplier_try_pull_calldata, &retval, &has_event);
  return retval;
  
}

static const TAO_Param_Data RtecEventComm_PullSupplier_disconnect_pull_supplier_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PullSupplier_disconnect_pull_supplier_calldata = 
{"disconnect_pull_supplier", 1, 1, RtecEventComm_PullSupplier_disconnect_pull_supplier_paramdata, 0, 0};

void  RtecEventComm::PullSupplier::disconnect_pull_supplier (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PullSupplier_disconnect_pull_supplier_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PullSupplier[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x6c6c5375, 0x70706c69, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PullSupplier:1.0
  13, 0x50756c6c, 0x53757070, 0x6c696572, 0x0,  // name = PullSupplier,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PullSupplier (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PullSupplier), (unsigned char *) &_oc_RtecEventComm_PullSupplier, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PullSupplier = &_tc__tc_RtecEventComm_PullSupplier;

RtecEventComm::PullConsumer_ptr RtecEventComm::PullConsumer::_duplicate (RtecEventComm::PullConsumer_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->AddRef ();
  
  return obj;
} // end of _duplicate

RtecEventComm::PullConsumer_ptr RtecEventComm::PullConsumer::_narrow (CORBA::Object_ptr obj, CORBA::Environment &env)
{
  if (CORBA::is_nil (obj)) return RtecEventComm::PullConsumer::_nil ();
  if (obj->_is_a ("IDL:RtecEventComm/PullConsumer:1.0", env))
  {
    STUB_Object *istub;
    RtecEventComm::PullConsumer_ptr new_obj; // to be returned 
    if (obj->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
      return RtecEventComm::PullConsumer::_nil ();
    
    obj->Release (); // need this since QueryIntf bumped our refcount
    new_obj = new RtecEventComm::PullConsumer (istub); // construct obj ref using the stub object
    return new_obj;
  } // end of if
  return RtecEventComm::PullConsumer::_nil (); // _narrow failed
} // end of _narrow

RtecEventComm::PullConsumer_ptr RtecEventComm::PullConsumer::_nil (void)
{
  return (RtecEventComm::PullConsumer_ptr)NULL;
} // end of _nil

RtecEventComm::PullConsumer_ptr RtecEventComm::PullConsumer::_bind (const char *host, CORBA::ULong port, const char *key, CORBA::Environment &env)
{
  CORBA::Object_ptr objref = CORBA::Object::_nil ();
  IIOP_Object *data = new IIOP_Object (host, port, key);
  if (!data) return RtecEventComm::PullConsumer::_nil ();
  // get the object_ptr using Query Interface
  if (data->QueryInterface (IID_CORBA_Object, (void **)&objref) != NOERROR)
  {
  	env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
  	return RtecEventComm::PullConsumer::_nil ();
  }
  data->Release (); // QueryInterface had bumped up our count
  if (CORBA::is_nil (objref))
  	return RtecEventComm::PullConsumer::_nil ();
  else // narrow it
  	return RtecEventComm::PullConsumer::_narrow (objref, env);
}

static const TAO_Param_Data RtecEventComm_PullConsumer_disconnect_pull_consumer_paramdata [] = 
{
  {CORBA::_tc_void, PARAM_RETURN, 0}
};

static const TAO_Call_Data RtecEventComm_PullConsumer_disconnect_pull_consumer_calldata = 
{"disconnect_pull_consumer", 1, 1, RtecEventComm_PullConsumer_disconnect_pull_consumer_paramdata, 0, 0};

void  RtecEventComm::PullConsumer::disconnect_pull_consumer (CORBA::Environment &env)
{
  STUB_Object *istub;

  if (this->QueryInterface (IID_STUB_Object, (void **)&istub) != NOERROR)
  {
    env.exception (new CORBA::DATA_CONVERSION (CORBA::COMPLETED_NO));
    return;
    }
  this->Release (); // QueryInterface has bumped up our refcount
  istub->do_call (env, &RtecEventComm_PullConsumer_disconnect_pull_consumer_calldata, 0);
  return; // no value
  
}

static const CORBA::Long _oc_RtecEventComm_PullConsumer[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  35, 0x49444c3a, 0x52746563, 0x4576656e, 0x74436f6d, 0x6d2f5075, 0x6c6c436f, 0x6e73756d, 0x65723a31, 0x2e300000,  // repository ID = IDL:RtecEventComm/PullConsumer:1.0
  13, 0x50756c6c, 0x436f6e73, 0x756d6572, 0x0,  // name = PullConsumer,
};
static CORBA::TypeCode _tc__tc_RtecEventComm_PullConsumer (CORBA::tk_objref, sizeof (_oc_RtecEventComm_PullConsumer), (unsigned char *) &_oc_RtecEventComm_PullConsumer, CORBA::B_FALSE);
CORBA::TypeCode_ptr RtecEventComm::_tc_PullConsumer = &_tc__tc_RtecEventComm_PullConsumer;

