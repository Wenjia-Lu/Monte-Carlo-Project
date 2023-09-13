#include "final.h"
void opensockets(int * piperay) {
  struct addrinfo *hints, *results;
  hints = calloc(1, sizeof(struct addrinfo));

  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM;            // TCP socket
  hints->ai_flags = AI_PASSIVE;                // only needed on server
  getaddrinfo(NULL, "9988", hints, &results);  // NULL is localhost or 127.0.0.1

  // create socket
  int listen_socket =
      socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  int yes = 1;
  if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) ==
      -1) {
    printf("sockopt error\n");
    printf("%s\n", strerror(errno));
    exit(-1);
  }

  int err = bind(listen_socket, results->ai_addr, results->ai_addrlen);
  if (err == -1) {
    printf("Error binding: %s", strerror(errno));
    exit(1);
  }
  listen(listen_socket, 10);  // 10 clients can wait to be processed

  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);

  while (1) {
    // wait for next client
    printf("[SOCKET - SERVER] Waiting for connection...\n");
    int client_socket =
        accept(listen_socket, (struct sockaddr*)&client_address, &sock_size);

    double inside;
    read(client_socket, &inside, sizeof(double));
    printf("[SOCKET - SERVER] received pi: %f from client\n",inside);
    write(piperay[WRITE],&inside,sizeof(inside));
    // close that client
    close(client_socket);
  }
  free(hints);
  freeaddrinfo(results);
}

void ssh_client(int lab_comp){
  char buff[256];
  sprintf(buff, "ssh -t cchien30@149.89.161.%d 'cd Documents/Systems/final-project/; make compile; make client; exit; $SHELL'", lab_comp);
  system(buff);
}
