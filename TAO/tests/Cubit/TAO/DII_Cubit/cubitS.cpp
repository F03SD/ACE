// @(#)cubitS.cpp	05/14/97
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// TEST:	hand-written C-style "Cubit" stubs and "skeletons"
//

#include "tao/corba.h"

#include "cubitS.h"
#include "cubitC.cpp"

#include "method_db.i"

TAO_Dynamic_Hash_OpTable tao_cubit_optable (cubit_operations, 7, 14);  // Dynamic Operation Table

_skel_Cubit::_skel_Cubit (const char *obj_name)
{
#if 0
  const char* mn = "_skel_Cubit::_skel_Cubit ()";

  char *type_id = "IDL:Cubit:1.0";
  IIOP_Object *data;
  TAO_ORB_Core *ocp = TAO_ORB_Core_instance ();
  CORBA::POA_ptr oa = ocp->root_poa ();
  CORBA::ORB_ptr orb = ocp->orb ();

  if (oa == 0)
    {
      // We just have to assume that oa will be good, or we have to
      // throw an exception.  For now we "assume", but we'll
      ACE_ERROR ((LM_ERROR, " (%P|%t) %s Unable to locate a valid object adapter\n", mn));
      return;
    }

  this->optable_ = &tao_cubit_optable;
  data = new IIOP_Object (type_id);

  data->profile.iiop_version.major = IIOP::MY_MAJOR;
  data->profile.iiop_version.minor = IIOP::MY_MINOR;
  const ACE_INET_Addr& addr = ocp->orb_params ()->addr ();
  data->profile.host = ACE_OS::strdup (addr.get_host_name ());
  data->profile.port = addr.get_port_number ();
  data->profile.object_key.length =  ACE_OS::strlen (obj_name);
  data->profile.object_key.maximum = data->profile.object_key.length;
  data->profile.object_key.buffer =
    new CORBA::Octet[(size_t)data->profile.object_key.length + 1];

  ACE_OS::memcpy (data->profile.object_key.buffer,
		  obj_name,
		  data->profile.object_key.length+1);

  this->set_parent (data);
  this->sub_ = this;

  if (oa->bind (data->profile.object_key, this) == -1)
    ACE_ERROR ((LM_ERROR,
		" (%P|%t) %s Unable to bind object to key '%s': %p\n",
		mn,
		data->profile.object_key.buffer));
#endif
  const CORBA::String repoID = "IDL:Cubit:1.0"; // repository ID
  IIOP_Object *data; // Actual object reference
  TAO_ORB_Core *ocp = TAO_ORB_Core_instance (); // underlying ORB core instance
  CORBA::POA_ptr oa = TAO_ORB_Core_instance ()->root_poa (); // underlying OA
  const ACE_INET_Addr &addr = ocp->orb_params ()->addr ();
  this->optable_ = &tao_cubit_optable;

  // set up an IIOP object
  data = new IIOP_Object (CORBA::string_dup (repoID), addr, obj_name);
  this->set_parent (data); // store the IIOP obj ref with us
  if (oa) oa->bind (data->profile.object_key, this); // register ourselves
}

void
_skel_Cubit::_cube_octet_skel (CORBA::ServerRequest &req,
                               void *obj,
                               void */*context*/,
                               CORBA::Environment   &env)
{
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr	nv;
  CORBA::Any temp_value (CORBA::_tc_octet);

  req.orb ()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  dexc (env, "cube_octet, add value");

  req.params (nvlist, env);
  dexc (env, "cube_octet, get params");

  // Call Implementation
  CORBA::Octet *value = new CORBA::Octet;
  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;

  *value = the_cubit->Cubit_cube_octet (*(CORBA::Octet *) nv->value ()->value (), env);

  CORBA::Any *any = new CORBA::Any (CORBA::_tc_octet, value, CORBA::B_TRUE);

  req.result (any, env);
  dexc (env, "cube_octet, result");
}

void
_skel_Cubit::_cube_short_skel (CORBA::ServerRequest &req,
                               void *obj, void */*context*/,
                               CORBA::Environment   &env)
{
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr nv;
  CORBA::Any temp_value (CORBA::_tc_short);

  req.orb ()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  dexc (env, "cube_short, add_value");

  req.params (nvlist, env);
  dexc (env, "cube_short, get params");

  // Call Implementation
  CORBA::Short *value = new CORBA::Short;
  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;
  *value = the_cubit->Cubit_cube_short (*(CORBA::Short *) nv->value ()->value (), env);

  CORBA::Any *any = new CORBA::Any (CORBA::_tc_short, value, CORBA::B_TRUE);

  req.result (any, env);
  dexc (env, "cube_short, result");
}

void
_skel_Cubit::_cube_long_skel (CORBA::ServerRequest &req,
                              void *obj, void */*context*/,
                              CORBA::Environment   &env)
{
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr nv;
  CORBA::Any temp_value (CORBA::_tc_long);

  req.orb ()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  dexc (env, "cube_long, add_value");

  req.params (nvlist, env);
  dexc (env, "cube_long, get params");

  // Call Implementation
  CORBA::Long *value = new CORBA::Long;
  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;
  *value = the_cubit->Cubit_cube_long (*(CORBA::Long *) nv->value ()->value (), env);

  CORBA::Any  		*any =
    new CORBA::Any (CORBA::_tc_long, value, CORBA::B_TRUE);

  req.result (any, env);
  dexc (env, "cube_long, result");
}

void
_skel_Cubit::_cube_struct_skel (CORBA::ServerRequest &req,
                                void *obj, void */*context*/,
                                CORBA::Environment   &env)
{
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr nv;
  CORBA::Any temp_value (TC_Cubit_Many);

  req.orb ()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  dexc (env, "cube_struct, add_value");

  req.params (nvlist, env);
  dexc (env, "cube_struct, get params");

  // Call Implementation
  Cubit_Many *value;
  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;
  value = the_cubit->Cubit_cube_struct (*(Cubit_Many *) nv->value ()->value (), env);

  Cubit_Many *retval = new Cubit_Many;
  retval->o = (CORBA::Octet)value->o;
  retval->s = (CORBA::Short)value->s;
  retval->l = value->l;

  // dmsg2 ("cube struct.o, %d -> %d", value->o, retval->o);
  // dmsg2 ("cube struct.s, %d -> %d", value->s, retval->s);
  // dmsg2 ("cube struct.l, %d -> %d", value->l, retval->l);

  CORBA::Any *any = new CORBA::Any (TC_Cubit_Many, retval, CORBA::B_TRUE);

  req.result (any, env);
  dexc (env, "cube_struct, result");
}

void
_skel_Cubit::_cube_union_skel (CORBA::ServerRequest	&req,
                               void *obj, void */*context*/,
                               CORBA::Environment   &env)
{
  CORBA::NVList_ptr nvlist;
  CORBA::NamedValue_ptr nv;
  CORBA::Any temp_value (TC_Cubit_oneof);

  req.orb ()->create_list (0, nvlist);
  nv = nvlist->add_value (0, temp_value, CORBA::ARG_IN, env);
  dexc (env, "cube_union_3rd, add_value");

  req.params (nvlist, env);
  dexc (env, "cube_union_3rd, get params");

  // Call Implementation
  Cubit_oneof *v;
  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;
  v = the_cubit->Cubit_cube_union (*(Cubit_oneof *) nv->value ()->value (), env);

  Cubit_oneof *r = new Cubit_oneof;
  r->_disc = v->_disc;
  r->o = (CORBA::Octet) (v->o);
  r->s = (CORBA::Short) (v->s);
  r->l = v->l;
  r->cm.o = (CORBA::Octet) (v->cm.o);
  r->cm.s = (CORBA::Short) (v->cm.s);
  r->cm.l =  v->cm.l;

  CORBA::Any *any = new CORBA::Any (TC_Cubit_oneof, r, CORBA::B_TRUE);

  req.result (any, env);
  dexc (env, "cube_struct, result");
}

void
_skel_Cubit::_please_exit_skel (CORBA::ServerRequest &req,
                                void *obj, void */*context*/,
                                CORBA::Environment   &env)
{
  ACE_UNUSED_ARG (req);

  _skel_Cubit *the_cubit = (_skel_Cubit *) obj;
  the_cubit->Cubit_please_exit (env);
}

void _skel_Cubit::dispatch (CORBA::ServerRequest &req,
                            void *context,
                            CORBA::Environment &env)
{
  TAO_Skeleton skel; // pointer to skeleton for operation
  CORBA::String opname = req.op_name (); // retrieve operation name
  // find the skeleton corresponding to this opname
  if (this->find (opname, skel) == -1)
  {
    env.exception (new CORBA_BAD_OPERATION (CORBA::COMPLETED_NO));
    ACE_ERROR ((LM_ERROR, "Bad operation <%s>\n", opname));
  }
  else
  	skel (req, this, context, env);
}
