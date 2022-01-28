#include <stdio.h>
#include<stdlib.h>
#define MAX 3

char cq[MAX];
int front = -1, rear = -1;

void insert(char);
void delete();
void display();
void main()
{
             int ch;
             char item;
             while(1)
             {
                            printf("\n\n~~Main Menu~~");
                            printf("\n==> 1. Insertion");
                            printf("\n==> 2. Deletion");
                            printf("\n==> 3. Display");
                            printf("\n==> 4. Exit");
                            printf("\nEnter Your Choice: ");
                            scanf("%d", &ch);
                            //__fpurge(stdin);
                           switch(ch)
                          {
                                           case 1:
                                                             insert(item);
                                                              break;
                                           case 2:        delete();
                                                              break;
                                           case 3:        display();
                                                              break;
                                            case 4:       exit(0);
                                            default:      printf("\n\nPlease enter a valid choice");
                            }
               }
}
int cqFull()
{
	if(front == (rear+1)%MAX)
                 {
                      return 1;        
                 }
	else
	return 0;
}

void insert(char item)
{
	if(cqFull())
                printf("\n\n~~Circular Queue Overflow~~");  
                 else
                 {
                     printf("\n\nEnter the element to be inserted: ");
                                                              scanf(" %c", &item);
                             if(front == -1)
                                             front = rear = 0;
                             else
                                              rear = (rear+1)%MAX;
                             cq[rear] = item;
                  }
}
int cqEmpty()
{
	 if(front == -1)
               	 {
                          return 1;        
                	}
	else
	return 0;
}
void delete()
{
                char item;
	if(cqEmpty())
                printf("\n\n~~Circular Queue Underflow~~");
                else
                {
                               item = cq[front];
                               printf("\n\nDeleted element from the queue is: %c ",item );
                               
                               if(front == rear) //only one element
                                                front = rear = -1;
                               else
                                               front = (front+1)%MAX;
                 }
}


void display ()
{
                   int i ;
                   if(front == -1)
                   {
                                 printf("\n\nCircular Queue Empty");
                   }
                   else
                   {
                                printf("\nCircular Queue contents are:\n");
                                printf("Front[%d]-> ", front);
                               for(i = front; i != rear ; i = (i+1)%MAX)
                               {
                                                   printf(" %c", cq[i]);
                               }
                               printf(" %c", cq[i]);
                               printf(" <-[%d]Rear", rear);
                    }
}
