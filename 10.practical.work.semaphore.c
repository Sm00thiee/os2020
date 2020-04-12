#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
pthread_mutex_t lock;

void *func1(void *args)
{
    int i,j;
    for(i=2;i<=1000000;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }

       if(c==2)
        {
            pthread_mutex_lock(&lock);
            printf("%d ",i);
            pthread_mutex_unlock(&lock);
        }
    }
}
void *func2(void *args)
{
  int i=1,j=1;
  int c=0;
  while(c+i<10000000)
  {
   pthread_mutex_lock(&lock);
   c=i+j;
   i=j;
   j=c;
   printf("%d ",c);
   pthread_mutex_unlock(&lock);
  }
}

int main()
{
  pthread_t prime,fibo;
  pthread_mutex_init(&lock,NULL);

  pthread_create(&prime, NULL ,func1, NULL);
  pthread_create(&fibo, NULL ,func2,NULL);

  pthread_join(prime,NULL);
  pthread_join(fibo,NULL);
  return 0;
}
