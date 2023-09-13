#include "client.h"
#include "monte.h"

int main(int argc, char* argv[]){
    int points = 0;
    int size = 0;
    if(argc < 3){ //3 param: ./client & points & size
    //int in = 5;
    //Calculate the number of points outside and inside here!
      points = 200000;//magic number avoidal // number of points
      size = 10000;// found through trial // r of circle, half sqr side len
    } else { //using strtol cuz apparently its better syntax than atoi
      //convert str to int in base 10
      points = (int) strtol(argv[1], (char**) NULL, 10);
      size = (int) strtol(argv[2], (char**) NULL, 10);
    } //

    //double pi = calculate_pi(points,size);

    int numChild = 4; // num children the client spawns
    int pointsPerChild = points/numChild; // distribute pts equally among kids

    int ppid = getpid(); // parent pid
    int pip_arr[2]; pipe(pip_arr); // 1 pipe for parent w/ numChild kids
    for(int i = 0; i < numChild; i++){
      if(getpid() == ppid){
        fork();
      }
    } // for; make [numChild] kids

    if(getpid() == ppid){ // parent
      close(pip_arr[WRITE]);

      // basically forking form of calculate_pi in monte
      double combinedResult = 0;
      double* ratio = malloc(sizeof(double*));
      for(int i = 0; i < numChild; i++){
        read(pip_arr[READ], ratio, sizeof(ratio));
        //printf("ratio: %f \n", *ratio);
        combinedResult += *ratio;
      }
      free(ratio);
      printf("\n\n[PARENT] %d children result: %f\n\n", numChild, combinedResult);
      sendtoserver(combinedResult);
    }// parent
    else { // child

      printf("[CHILD] received %d points...\n", pointsPerChild);
      close(pip_arr[READ]);
      double ratio = calculate_ratio(pointsPerChild, size);
      double *writeRatio = &ratio;
      printf("[CHILD] calculated: %f \n", ratio);
      write(pip_arr[WRITE], writeRatio, sizeof(writeRatio));

    } // child

    //printf("client w/ points:%d, size:%d, found pi:%f\n",points,size,pi);

    // sendtoserver(pi); // client send pi (3.14) to server

    return 0;
}

void sendtoserver(double in){

    char * retportray[3];
   // retportray[1] = "149.89.161.100"; // !! will be changed after execvp ssh !!
     retportray[1] = "localhost"; 
    
    retportray[2] = "9988";
    // printf("connecting to %s:%s\n",retportray[1],retportray[2]);

    struct addrinfo hints, *results;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int err;
    //         getaddrinfo(address,port,...)
    if ((err = getaddrinfo(retportray[1], retportray[2], &hints, &results)) != 0) {
        printf("error %d : %s\n", err, strerror(err));
        exit(1);
    }

    int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    if(sd < 0){
        printf("%s\n",strerror(errno));
        exit(1);
    }

    if ( connect(sd, results->ai_addr, results->ai_addrlen) < 0) {
        printf("Failed to connect\n");
        exit(1);
    }

    //DO STUFF
    int n;
    double inside = in; // pi (3.14)
    printf("[SOCKET - CLIENT] writing double: %f\n",inside);
    n = write(sd, &inside, sizeof(double)); // write to socket
  	if(n <= 0){
  		printf("\n write error:%s\n",strerror(errno));
      exit(1);
  	}
    printf("\n[SOCKET - CLIENT] %d bytes written.\n",n);

    freeaddrinfo(results);
}
