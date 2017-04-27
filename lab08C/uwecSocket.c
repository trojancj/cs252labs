int setupServerSocket(int portno){          //Like new ServerSocket in Java
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("ERROR opening socket");
        exit(1);
    }
    //server address structure
    struct sockaddr_in serv_addr;

    //Set all the values in the server address to 0
    memset(&serv_addr, '0', sizeof(serv_addr));

    //Setup the type of socket (internet vs filesystem)
    serv_addr.sin_family = AF_INET;

    //Basically the machine we are on
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //Setup the port number
    //Htons - is host to network byte order
    //Network byte order is most sig bype first
    //Which might be host or might not be
    serv_addr.sin_port = htons(portno);
    
    //Bind the socket to the given port
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        printf("ERROR on binding\n");
        exit(1);
    }

    //Set it up to listen
    listen(sodfd,5);

    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

}

int callServer(char* host, int portno){    //Like new Socket in Java
    if(connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        printf("ERROR connecting\n");
        exit(0);
    }

}

int serverSocketAccept(int serverSocket){   //Like ss.accept() in Java


}

void writeInt(int x, int socket){           //Write an int over the given socketd


}

int readInt(int socket){                    //Read an int from the given socket


}
