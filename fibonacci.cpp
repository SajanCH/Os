#include<stdio.h>			
#include<pthread.h>

int arr[1000];
void *fibo(); 		    	  

void *sequence(int n)
{
	int i,a=0,b=1,nextterm=0;			
	
	arr[n];
	arr[1]=a;
	arr[2]=b;
	for(i=3;i<n;i++)     
	{	
		nextterm=a+b;	
		arr[i]=nextterm;
		a=b;
		b=nextterm;
		nextterm=0;
	}sleep(1);
}		

void *fibo()
{
	int n,j;
		
	scanf("%d",&n);    				
	printf("child process created\n");
	sequence(n);
	printf("child process ended\n");
	printf("Fibonacci Series is:\n");
	for(j=0;j<n;j++)
	{                       		
		printf("%d\n",arr[j]);
	}
}

int main()
{
	pthread_t p1,p2;      							
	pthread_create(&p1,NULL,fibo,NULL);  					 
	printf("Enter the number for fibonacci series \n ");	
	pthread_create(&p2,NULL,sequence,NULL);						
	pthread_join(p1,NULL);				
	pthread_join(p2,NULL);				
}
