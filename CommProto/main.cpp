#include <stdio.h>
#include <comms.h>
#include <architecture/os/os_threads.h>
#include <architecture/os/include_defines.h>


int main(int c, char** args) {
  printf("Hello World!");
  Comms newComms = Comms();
  if (newComms.initConnection(UDP_LINK, 1337, "127.0.0.1"))
  {

	  newComms.run();
	  Sleep(1000);
	  newComms.stop();
	  Sleep(5000);
  }
  else
  {
	  printf("Failed\n");
  }
  return 0;
}
