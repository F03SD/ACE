// @(#)svr.cpp	05/14/97
// Copyright 1994-1995 by Sun Microsystems Inc.
// All Rights Reserved
//
// TEST:	simple IIOP server for "cubit.idl" interface.
//
// Starts up, builds an objref, prints its string in debug mode,
// listens for messages, responds to them.
//
// Modified version of Cubit Example written by Sun Microsystems Inc.
// Modified by: Brian Mendel

#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"

#include "tao/corba.h"

#include "cubit_i.h"

// @@ Shouldn't this be defined in a headerfile somewhere?
extern void
print_exception (const CORBA_Exception *, const char *, FILE *f=stdout);

// Global Variables
static CORBA_String key = (CORBA_String) "key0";

static int num_of_objs = 1;

// Parses the command line arguments and returns an error status

static int 
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt opts (argc, argv, "dk:n:");
  int			c;
   
  while ((c = opts ()) != -1)
    switch (c) 
      {
      case 'd':  // debug flag
	TAO_debug_level++;
	break;
      case 'k':			// key (str)
	key = (CORBA_String) opts.optarg;
	break;
      case 'n':			// idle seconds b4 exit
	num_of_objs = ACE_OS::atoi (opts.optarg);
	break;
      case '?':
      default:
	ACE_ERROR_RETURN ((LM_ERROR,
			   "usage:  %s"
			   " [-d]"
			   " [-k {object_key}]"
			   "\n", argv [0]), 1);
      }
   
  return 0;  // Indicates successful parsing of command line
}

// Standard command line parsing utilities used.

int
main (int argc, char *argv[])
{
  CORBA_Environment env;
  char *orb_name = "internet";

  CORBA_ORB_ptr	orb_ptr = CORBA_ORB_init (argc, argv, orb_name, env);

  if (env.exception () != 0) 
    {
      print_exception (env.exception (), "ORB init");
      return 1;
    }

  // Initialize the Basic Object Adapter
  CORBA_BOA_ptr oa_ptr = orb_ptr->BOA_init (argc, argv, "ROA");

  if (oa_ptr == 0)
    ACE_ERROR_RETURN ((LM_ERROR, " (%P|%t) Unable to initialize the BOA.\n"), 1);

  // Parse remaining command line and verify parameters.

  parse_args (argc, argv);
  
  // Create implementation object with user specified key.
  Cubit_i_ptr *my_cubit = new Cubit_i_ptr[num_of_objs];

  for (int i = 0; i < num_of_objs; i++)
    {
      CORBA_String obj_str = CORBA_string_alloc (ACE_OS::strlen ((char *) key)+2);

      ::sprintf (obj_str, "%s%d", (char *) key, i);

      my_cubit[i] = new Cubit_i (obj_str);

      if (my_cubit[i] == 0)
        ACE_ERROR_RETURN ((LM_ERROR,
			   " (%P|%t) Unable to create implementation object&d\n",
			   i),
			  2);

      if (TAO_debug_level >= 1)
	{
	  // Why are we getting the BOA_ptr from here when we've
	  // already got it above?

	  CORBA_OctetSeq obj_key;
	  obj_key.buffer = (CORBA_Octet *) obj_str;
	  obj_key.length = obj_key.maximum = ACE_OS::strlen (obj_str);
     
	  CORBA_Object_ptr obj = 0;

	  if (oa_ptr->find (obj_key, obj) == -1)
	    ACE_ERROR_RETURN ((LM_ERROR,
			       " (%P|%t) Unable to locate object with key '%s', %p\n", 
			       key),
			      3);
     
	  // Stringify the objref we'll be implementing, and print it
	  // to stdout.  Someone will take that string and give it to
	  // some client.  Then release the object.

	  CORBA_String str;
         
	  str = orb_ptr->object_to_string (obj, env);

	  if (env.exception () != 0) 
	    {
	      print_exception (env.exception (), "object2string");
	      return 1;
	    }

	  ACE_OS::puts ((char *) str);
	  ACE_OS::fflush (stdout);
	  dmsg1 ("Object Created at: '%ul'", obj);
	  dmsg1 ("listening as object '%s'", str);
	}

      CORBA_string_free (obj_str);  
    }

//  Cubit_i_ptr  my_cubit = new Cubit_i (key);
//  if (my_cubit1 == 0)
//    ACE_ERROR_RETURN ((LM_ERROR, " (%P|%t) Unable to create implementation object\n"), 2);

  // Handle requests for this object until we're killed, or one of the
  // methods asks us to exit.

  // @@ Do we need the HOMEBREW_EVENT_LOOP stuff?  If not, can we remove it please?
#if !defined (USE_HOMEBREW_EVENT_LOOP)
  ACE_Reactor::run_event_loop ();
#else
  int terminationStatus = 0;

  while (1)
    {
      int result = params->reactor ()->handle_events ();

      if (result == -1)
	{
	  terminationStatus = -1;
	  break;
	}
    }
#endif /* USE_HOMEBREW_EVENT_LOOP */

  // Shut down the OA -- recycles all underlying resources (e.g. file
  // descriptors, etc).

  oa_ptr->clean_shutdown (env);
  return 0;
}
