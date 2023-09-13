#include "monte.h"

/* this step is replaced by child processes

double calculate_pi(int points, int size){
  return calculate_ratio(points,size) * 4.0;
}

*/

double calculate_ratio(int points, int size){

  //open urandom
  int file = open("/dev/urandom",O_RDONLY);
  if(file == -1){
    printf("%s\n",strerror(errno));
    exit(errno);
  }

  int points_inside=0;
  int x=0;
  int y=0;

  for(int i = 0; i < points; i++){
    read(file, &x, sizeof(int));
    x %= size;
    read(file, &y, sizeof(int));
    y %= size;

    if(distance(x,y) <= size)
      points_inside++;
  }
  printf("\n[MONTE] Num points inside: %d\n",points_inside);

  close(file);

  return (points_inside * 1.0) / points;
}

double distance(int x, int y){
  return sqrt(x*x + y*y);
}
