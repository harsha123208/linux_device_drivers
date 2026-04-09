#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
 int fd=open("/dev/p2.1",O_RDWR);
 char buff[100];
 int x;
 if(fd<0)
 {
  perror("fd");
  return 0;
 }
 printf("enter the data:");
 scanf("%d",&x);
 write(fd,&x,4);
 read(fd,buff,sizeof(buff));
  if(buff[0]=='1')
  printf("even\n");
  else
  printf("odd\n");

}
