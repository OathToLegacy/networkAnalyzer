#include "scanner.h"

void scanner_start(cli_config_t *cfg ) //change this to run through a JSON output log. Giving all errors
{
    //Take the IP and use TCP protocol to read the ports for the selected IP.
    //When the ports are read, check if they are active or not and return the status of the ports to a .JSON status.
    //Read the ports at the designated address until the end_port.
    char local_IP = cfg->ip;
    int local_startport = cfg->start_port;
    int local_endport = cfg->end_port;
    int current_portscan = cfg->start_port;
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed . . .\n");
         exit(0);
    }//Change to JSON and console output log
    else{printf("Socket successfully created");}
    
    bzero(&servaddr, sizeof(servaddr));

    //assigning IP and cycling through ports
    servaddr.sin_addr.s_addr = inet_addr(local_IP);
    servaddr.sin_port = htons(local_startport);

    while(local_startport != local_endport)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1)
        {
            printf("socket creation failed . . .\n");
            exit(0);
        }//Change this to be handled elsewhere. then stored in JSON
        else{printf("Socket successfully created . . . \n");} //Change this to be handeled by json
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(local_IP);
        servaddr.sin_port = htons(current_portscan);
        
        if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)))
        {
            
        }

    }




    

}