#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <omp.h>  //compile with -fopenmp

bool isPrime(int num);
int howManyPrime(int start, int end);

int main() {

  omp_set_num_threads(4);

  // Socket pointer
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr,"ERROR opening socket\n");
    exit(0);
  }

  // port number
  int portno = 6666; // MAKE SURE THIS MATCHES THE SERVER

  // server address structure
  struct sockaddr_in serv_addr;

  // Set all the values in the server address to 0
  memset(&serv_addr, '0', sizeof(serv_addr)); 

  // Setup the type of socket (internet vs filesystem)
  serv_addr.sin_family = AF_INET;

   // Setup the port number
  // htons - is host to network byte order
  // network byte order is most sig byte first
  //   which might be host or might not be
  serv_addr.sin_port = htons(portno);


  // Setup the server host address
  struct hostent *server;
  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);  /// dest, src, size

  // Connect to the server
  if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR connecting\n");
    exit(0);
  }

  // Take in intervals from server

 // int numClients;
  //read(sockfd, &numClients, sizeof(numClients));

  int beginning;
  int end;

  int i;
  for (i = 0; i < 5; i++) {
    read(sockfd, &beginning, sizeof(beginning));
    read(sockfd, &end, sizeof(end));

    //printf("beginning %d - end %d\n", beginning, end);

    int numPrimes = howManyPrime(beginning, end);

    printf("Total number of primes for range %d - %d is: %d\n", beginning, end, numPrimes);

    write(sockfd, &numPrimes, sizeof(numPrimes));   
  }




  // char buffer[256];
  // printf("Please enter the message: "); // prints to client
  // memset(&buffer, '\0', 256); 
  // fgets(buffer,255,stdin);

  // int n = write(sockfd,buffer,strlen(buffer));
  // if (n < 0) {
  //   printf("ERROR writing to socket\n");
  //   exit(0);
  // }

  // memset(&buffer, '\0', 256);
  // n = read(sockfd,buffer,255);
  // if (n < 0) {
  //   printf("ERROR reading from socket\n");
  //   exit(0);
  // }
  // printf("%s\n",buffer);

  close(sockfd);
  return 0;

}

bool isPrime(int num) {
    int count = 2;
    while (num > count) {
      if ((num % count) == 0) {
        return false;
      }
      count++;
    }
    return true;
  }

int howManyPrime(int start, int end) { 
    int count = 0;
    int i;

    #pragma omp parallel reduction(+: count)
     {             
     #pragma omp for schedule(static, 1) // nowait
      for (i = start; i < end; i++) {
        if (isPrime(i)) {
         count++;
        }

      }
    }

  return count;
}