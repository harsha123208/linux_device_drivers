#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
void*thread1(void*);
void*thread2(void*);
int fd[2];
int pid;
int num;
void isr(int n)
{ kill(pid,19);
  raise(19);
}
int main()
{
 /*int fd[2];*/
 pipe(fd);
signal(2,isr);
 if((pid=fork())==0)
 {
  pthread_t t1;
  pthread_t t2;
  void*p;
  while(1)
 {
  pthread_create(&t1,0,thread1,0);
  pthread_join(t1,&p);
  pthread_create(&t2,0,thread2,p);
  sleep(5);
 }
 }
 else
 {char ch[10];
 while(1)
  {
   if(read(fd[0],ch,sizeof(ch))<0)
   {
    perror("problem in parent\n");
    }
    printf("in parent %s",ch);
    fflush(stdout); 
    sleep(5);
  }

  }

}
void*thread1(void*i)
{int x;
 srand(&x);
  num=rand()%100;
 return &num;
} 
void*thread2(void*j)
{
 char a[10];
sprintf(a,"%d\n",*(int*)j);
 write(fd[1],a,strlen(a)+1);
}

