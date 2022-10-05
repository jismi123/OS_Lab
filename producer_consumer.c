#include <stdio.h>
#include <stdlib.h>

void producer();
void consumer();
int wait(int s);
int signal(int s);
 
int mutex=1,full=0,empty=5,x=0,ch;
int main()
{
     printf("1.Producer\n2.Consumer\n3.Exit");
     do
     {
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if((mutex==1) && (empty!=0))
                    producer();
                else
                    printf("Buffer is full");
                break;
            
            case 2:
                if((mutex==1) && (full!=0))
                    consumer();
                else
                    printf("Buffer is empty");
                break;
            
            case 3:
                printf("Going to exit");
                break;
                
            default:
                printf("Invalid Entry");
        }
        
     } while(ch!=3);
}
 
int wait(int s)
 {  
     return(--s);
 }
 
 int signal(int s)
 {  
     return(++s);
 }
 
 void producer()
 {
     mutex=wait(mutex);
     full=signal(full);
     empty=wait(empty);
     x++;
     printf("Producer produces item %d",x);
     mutex=signal(mutex);
 }
 
 void consumer()
 {
     mutex=wait(mutex);
     full=wait(full);
     empty=signal(empty);
     printf("Consumer consumes item %d",x);
     x--;
     mutex=signal(mutex);
 }
