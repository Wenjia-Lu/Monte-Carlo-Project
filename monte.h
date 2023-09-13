#ifndef monte_h
    #define monte_h

        #include <stdio.h>
        #include <stdlib.h>
        #include <math.h>
        #include <string.h>
        #include <fcntl.h>
        #include <errno.h>
        #include <unistd.h>

        double calculate_pi(int points, int size);
        double calculate_ratio(int points, int size);
        double distance(int x, int y);
#endif
