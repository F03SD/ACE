#include "Options.h"
// $Id$

#include "Benchmark.h"

#if defined (ACE_HAS_THREADS)

extern int buffer;
extern int synch_count;

class Pipe_Proc_Test : public Benchmark
{
public:
  int init (int, char **);
  virtual int svc (void);

private:
  int pipe_handles[2];

  void reader (ACE_HANDLE handle);
};

int
Pipe_Proc_Test::init (int, char **)
{
  synch_count = 1;

  if (ACE_OS::pipe (this->pipe_handles) == -1)
    ACE_OS::perror ("pipe"), ACE_OS::exit (1);

  switch (ACE_OS::fork ())
    {
    case -1:
      ACE_OS::perror ("fork"), ACE_OS::exit (1);
    case 0:
      this->reader (pipe_handles[0]);
      /* NOTREACHED */
      break;
    default:
      break;
    }
  return 1;
}

void
Pipe_Proc_Test::reader (ACE_HANDLE handle)
{
  int  ni = this->thr_id ();
  int length = options.msg_size ();
  char *to;
  
  ACE_NEW (to, char[length]);

  while (ACE_OS::read (handle, to, length) > 0)
    options.thr_work_count[ni]++;
}


int
Pipe_Proc_Test::svc (void)
{
  ssize_t length = options.msg_size ();
  int ni = this->thr_id ();
  ACE_HANDLE handle = this->pipe_handles[1];
  char *from; 

  ACE_NEW_RETURN (from, char[length], -1);

  while (!this->done ())
    if (ACE_OS::write (handle, from, length) == length)
      options.thr_work_count[ni]++;
    else
      ACE_OS::perror ("write");
    
  ACE_OS::close (this->pipe_handles[0]);
  ACE_OS::close (this->pipe_handles[1]);
  return 0;
}

extern "C" ACE_Service_Object *pipe_proc_test (void);

ACE_Service_Object *pipe_proc_test (void)
{
  return new Pipe_Proc_Test;
}

// ACE_Service_Object_Type ppt (&pipe_proc_test, "Pipe_Proc_Test");
#endif /* ACE_HAS_THREADS */
