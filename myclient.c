#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>
#include "restart.h"
#include "uici.h"
 
int main(int argc, char *argv[]) {
   int bytescopied;
   int communfd[atoi(argv[3])];
   int connections;
   int i;
   int myndx;
   int pid;
   char *fuck = "AC4EX";
   u_port_t portnumber;
 
   if (argc != 4) {
      fprintf(stderr, "--> FUCKING USAGE: [host] [port] [max connections]\n");
      return 1;
   }
   connections = atoi(argv[3]);
   portnumber = (u_port_t)atoi(argv[2]);
   bytescopied = 0;
   myndx = 0;

   for(i = 0; i < connections; i++) {
	  myndx = i;
	  pid = fork();
	  if(pid) break;
   }

   if(pid) {
   		if ((communfd[myndx] = u_connect(portnumber, argv[1])) == -1) {
      		fprintf(stderr, "--> Failed to make connection [%d]\n", getpid());
      		return 1;
   		}

//		while(bytescopied) {
			if ((r_write(communfd[myndx], fuck, sizeof(fuck))) == -1) {
				fprintf(stderr, "--> FUCKING ERROR: on writing random hex value [%d]\n", getpid());
				exit(-1);
			} else {
				bytescopied += 4;
			}
//		}
   		fprintf(stderr, "\t--> [%d] connected to: %s\n", getpid(), argv[1]);
   		fprintf(stderr, "\t--> [%d] sent %d bytes\n", getpid(), bytescopied);
	
   }
   
   waitpid(-1, NULL, 0);
   fprintf(stdout, "Finished[%d]\n", getpid());
   return 0;
}
