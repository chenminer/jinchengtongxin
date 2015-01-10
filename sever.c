#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <linux/input.h>  
#include <fcntl.h>  
#include <sys/time.h>   
#include <sys/stat.h>  
#include <unistd.h> 

#define PORT 5000
#define BACKLOG 10
#define LENGTH 512

int main(int argc,char **argv)
{
 int sockfd,nsockfd;
 int num;
 int sin_size;
 
 int fd, retval;  
 char buf[6];  
 fd_set readfds;  
 struct timeval tv;  
 fd = open( "/dev/input/mice", O_RDONLY );    
    
 char sdbuf[LENGTH];
 struct sockaddr_in addr_local;
 struct sockaddr_in addr_remote;
 char sendstr[16]={"123456789abcde"};
