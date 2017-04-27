#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "uwecSocket.h"

int main(){
    //Socket pointer
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        fprintf(sterr, "ERROR opening socket\n");
        exit(0);
    }
    //port number
    int portno = 7000;

    //Sever address structure
    struct sockaddr_in serv_addr;

    //Set all the values in the server address to 0
    memset($serv_addr, '0', sizeof(serv_addr));

    //Setup the type of socket (internet vs filesystem)


}
