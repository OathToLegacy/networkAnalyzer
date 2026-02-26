#include "scanner.h"

#define SA struct sockaddr

void scanner_start(const cli_config_t *cfg ) //change this to run through a JSON output log. Giving all errors
{
    //Take the IP and use TCP protocol to read the ports for the selected IP.
    //When the ports are read, check if they are active or not and return the status of the ports to a .JSON status.
    //Read the ports at the designated address until the end_port.
    
    int local_startport = cfg->start_port;
    int local_endport = cfg->end_port;
    int sockfd, connfd;
    struct sockaddr_in servaddr;
    
    //assigning IP and cycling through ports
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    if(inet_pton(AF_INET,cfg->ip, &servaddr.sin_addr) != 1){/*produce error code*/}

    
    
    while(local_startport <= local_endport)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1)
        {
            printf("socket creation failed . . .\n");
            /*produce outcome into JSON file*/
        }
        else{printf("Socket successfully created . . . \n");} //Change this to be handeled by json

        servaddr.sin_port = htons(local_startport);
        
        if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)))
        {
            printf("connection with server failed. . . \n");
            /*produce outcome into JSON file*/
        }
        else{ printf("connected to server. . .\n"); }
        
        close(sockfd);
        
        local_startport++;
        


    }




    

}