/* uexit.c: define uexit to do an exit with the right status.  We can't
   just call `exit' from the web files, since the webs use `exit' as a
   loop label.  Public domain. */

#include <w2c/config.h>
#ifdef __IPHONE__
#include <pthread.h>
#endif

void
uexit (int unix_code)
{
  int final_code;

  if (unix_code == 0)
    final_code = EXIT_SUCCESS;
  else if (unix_code == 1)
    final_code = EXIT_FAILURE;
  else
    final_code = unix_code;
#ifdef __IPHONE__
  // This function is called for each exit, either regular exit 
  // or exit after error. 
  // We need to deallocate everything
  pthread_exit(NULL); 
#else 
  exit (final_code);
#endif 
}
