#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

  int numClients = 5;

  int beginning = 100;
  int end = 100000;


  // Get a socket of the right type
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("ERROR opening socket");
    exit(1);
  }

  // port number
  int portno = 6666; // YOU NEED TO CHANGE THIS EVERYTIME

  // server address structure
  struct sockaddr_in serv_addr;

  // Set all the values in the server address to 0
  memset(&serv_addr, '0', sizeof(serv_addr)); 

  // Setup the type of socket (internet vs filesystem)
  serv_addr.sin_family = AF_INET;

  // Basically the machine we are on...
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Setup the port number
  // htons - is host to network byte order
  // network byte order is most sig bype first
  //   which might be host or might not be
  serv_addr.sin_port = htons(portno);

  // Bind the socket to the given port
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR on binding\n");
    exit(1);
  }

  // set it up to listen
    listen(sockfd,5);

  int newsockfd;
  struct sockaddr_in cli_addr;
  socklen_t clilen = sizeof(cli_addr);

  // Wait for a call
  printf("waiting for a call...\n"); // prints to server

  int i;
  for (i = 0; i < numClients; i++) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("connected\n"); // prints to server
    if (newsockfd < 0) {
      printf("ERROR on accept");
      exit(1);
    }
  }


  // Send intervals to client
  int numPrimes[numClients];

  for (i = 0; i < numClients; i++) {

    int start = (end - beginning) / numClients * i + beginning;
    int stop = (end - beginning) / numClients * (i + 1) + beginning;

    printf("start = %d stop = %d\n", start, stop);

   // write(newsockfd, &numClients, sizeof(numClients));
    write(newsockfd, &start, sizeof(start));
    write(newsockfd, &stop, sizeof(stop));

    read(newsockfd, &numPrimes[i], sizeof(numPrimes));

  }

  int total;

  for(i = 0; i < numClients; i++) {
    total += numPrimes[i];
  }

  printf("number of primes is: %d\n", total);

  close(newsockfd);
  close(sockfd);
  return 0;
}