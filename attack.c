// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
  
// Driver code
int main() {
    int sockfd;
    char *exploit = "DOMINION.sys: flip.exe 7 from Biden,Joe to Trump,DonaldJ";
    struct sockaddr_in     servaddr;
    char dominionip[10];
    int dominionport;

    printf("Specify Dominion Server IP address: ");
    fgets(dominionip, 10, stdin);
    printf("Specify Dominion Server port: ");
    scanf("%10d", &dominionport);
    printf("Server IP: %s, Server Port: %d\n", dominionip, dominionport);
  
    // Creating socket file descriptor
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
  
    memset(&servaddr, 0, sizeof(servaddr));
      
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(dominionport);
    servaddr.sin_addr.s_addr = inet_addr(dominionip);
      
    int n, len;
      
    // Ensure election goes to biden!
    sendto(sockfd, (const char *)exploit, strlen(exploit),
        MSG_CONFIRM, (const struct sockaddr *) &servaddr, 
            sizeof(servaddr));
    printf("Exploit Sent!.\n");
    close(sockfd);
    return 0;
}
