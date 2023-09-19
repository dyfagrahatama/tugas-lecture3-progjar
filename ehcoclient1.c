#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024
int main(int argc,char* argv[])
{
int sockfd;
int n;
socklen_t len;
char sendline[1024],recvline[1024];
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("10.0.2.4");
servaddr.sin_port=htons(5035);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
strcpy(sendline,"");
printf("Selamat Datang!!!\n\n Nama: ");
scanf("%s",sendline);
len=sizeof(servaddr);
sendto(sockfd,sendline,MAXLINE,0,(struct
sockaddr*)&servaddr,len);
n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
recvline[n]=0;
printf("\n Halo User! : %s\n\n",recvline);
strcpy(sendline,"");
printf("\n NIM : ");
scanf("%s",sendline);
len=sizeof(servaddr);
sendto(sockfd,sendline,MAXLINE,0,(struct
sockaddr*)&servaddr,len);
n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
recvline[n]=0;
printf("\n NIM Bagus! : %s\n\n",recvline);
strcpy(sendline,"Biar Semangat");
printf("\n Harapan Untuk Hari ini : ");
scanf("%s",sendline);
len=sizeof(servaddr);
sendto(sockfd,sendline,MAXLINE,0,(structsockaddr*)&servaddr,len);
n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
recvline[n]=0;
printf("\n Semoga Tercapai! : %s\n\n",recvline);
return 0;
}
