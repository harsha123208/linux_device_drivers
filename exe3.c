#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int fd=open("/dev/c1",O_RDWR);
 char buff;
 char data[100];
 int x;
 if(fd<0)
 {
  perror("fd");
  return 0;
 }
 printf("enter the data:");
 scanf("%s",data);
 write(fd,&data,strlen(data)+1);
 read(fd,&buff,1);
  if(buff=='1')
  printf("palindrome \n");
  else
  printf("not palindrome \n");

}
