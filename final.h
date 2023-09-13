#ifndef final_h
    #define final_h
        #include <sys/socket.h>
        #include <sys/types.h>
        #include <sys/socket.h>
        #include <netdb.h>
        #include <time.h>
        #include <stdio.h>
        #include <string.h>
        #include <errno.h>
        #include <unistd.h>
        #include <stdlib.h>


        #define READ 0
        #define WRITE 1
        void opensockets(int*);
        void ssh_client(int lab_comp);
#endif
