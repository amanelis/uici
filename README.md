This file contains information about compiling the programs from Appendix C
of UNIX Systems Programming.

Under Solaris: no changes needed.

Under Linux:
   Compiling the programs under Linux typically requires that the constant
   _GNU_SOURCE be defined.  Run the convertlinux program once to modify the
   makefile use this constant.

   Also, Linux does not need the -lsocket library.  The convertlinux program
   removes this from makefile.

   Lastly, linux does not support gethostbyname_r and gethostbyaddr_r as
   described in the text so the convertlinux program removes these
   implementations from the default compilation.

Under Mac OS X:
   Mac OS X does not need either of the libraries -lsocket or -lnsl.
   Run the convertmac program once to remove these from the makefile.

   Also, Max OS X does not support gethostbyname_r and gethostbyaddr_r
   so the convertlinux program removes these implementations from the 
   default compilation.