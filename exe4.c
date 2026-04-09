#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
 int fd=open("/dev/exe4",O_RDWR);
 char buff;
 int data[100];
 int x;
 if(fd<0)
 {
  perror("fd");
  return 0;
 }
 printf("enter the data:");
 for(int i=0;i<5;i++)
 {
  scanf("%d",&data[i]);
 }
 write(fd,data,20);
 read(fd,data,20);
 for(int i=0;i<5;i++)
 {
  printf("%d ",data[i]);
 }
 printf("\n");

}
