#include<stdio.h> 
#include<stdlib.h> 
struct node
{
	char ssn[20],name[20],department[20],designation[20]; 
	long int phno,sal;
	struct node *llink,*rlink;
};
typedef struct node *NODE; 
NODE start = NULL;
NODE createnode(); 
NODE insertfront(); 
NODE deletefront(); 
NODE insertend();
NODE deleteend();
void display(); 
void dqueuedemo();
void main ()
{
	int choice,n,i; 
	while(1)
	{
		printf("\n---MENU---\n"); printf("\n1.create DLL"); 
		printf("\n2.display status of DLL"); 
		printf("\n3.insertion at front of DLL"); 
		printf("\n4.deletion at front of DLL"); 
		printf("\n5.insertion at end of DLL"); 
		printf("\n6.deletion at end of DLL"); 
		printf("\n7.dqueue demo");
		printf("\n8.exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: printf("\nEnter no. of employee:"); 
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				start = insertend();
			}
			break;
			case 2: display();
			break;
			case 3: start =insertfront(); 
			break;
			case 4: start = deletefront(); 
			break;
			case 5: start = insertend(); 
			break;
			case 6: start = deleteend(); 
			break;
			case 7: dqueuedemo();
			break;
			case 8: exit(0);
			default : printf("\nEnter a valid choice!!!");
		}
	}
}
NODE createnode()
{
	NODE cnode;
	cnode =(NODE)malloc(sizeof(struct node)); 
	if(cnode==NULL)
	{
		printf("\nInsufficient memory!!!"); 
		exit(0);
	}
	printf("\nEnter employee details ssn,name,department,designation,salary,phno\n");
	scanf("%s%s%s%s%ld%ld",cnode->ssn,cnode->name,cnode->department,(cnode->designation),&(cnode->sal),&(cnode->phno)); 
	cnode->llink=NULL;
	cnode->rlink=NULL; 
	return(cnode);
}
NODE insertfront()
{
	NODE temp;
	temp =createnode(); 
	if(start==NULL) 
	start=temp;
	else
	{
		temp->rlink=start; 
		start->llink=temp; 
		start=temp;
	}
	return(start);
}
NODE insertend()
{
	NODE temp,cur; 
	temp=createnode(); 
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		cur=start;
		while(cur->rlink!=NULL)
		{
			cur=cur->rlink;
		}
		cur->rlink=temp; 
		temp->llink=cur;
	}
	return(start);
}
NODE deletefront()
{
	NODE temp; 
	if(start==NULL)
	{
		printf("\nEmpty list"); 
		return(NULL) ;
	}
	temp=start; 
	start=start->rlink;
	printf("\ndeleting node with employee ssn %s",temp->ssn); 
	free(temp);
	return(start);
}
NODE deleteend()
{
	NODE cur,prev; 
	if(start==NULL)
	{
		printf("\nEmpty list"); 
		return NULL;
	}
	if(start->rlink==NULL)
	{
		printf("\nDeleting node with employee ssn%s",start->ssn); 
		free(start);
		return NULL;
	}
	cur=start; 
	prev=NULL;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	prev=cur->llink; 
	prev->rlink = NULL;
	printf("\nDeleting node with employee ssn %s",cur->ssn); 
	free(cur);
	return (start);
}
 void display()
 {
	int count=0; 
	NODE temp; 
	if(start==NULL)
	{
		printf("\nEmpty list");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		count++;
		printf("\nemployee %d =>|ssn:%s|name:%s|department:%s|Designation:%s|Salary:%ld|Phoneno:%ld|",count,temp->ssn,temp->name,temp->department,temp->designation,temp->sal,temp->phno); 
		temp=temp->rlink;
	}
	printf("\nNo. of nodes in DLL is %d",count);
}
void dqueuedemo()
{
	int choice; 
	while(1)
	{
		printf("\n-----Double ended queue demo---------------------- ");
		printf("\n1.insertfront\n2.deletefront\n3.insertend\n4.deleteend\n5.exit"); printf("\nEnter your choice:");
		scanf("%d",&choice); 
		switch(choice)
		{
			case 1: start=insertfront(); 
			display();
 			break;
			case 2:start=deletefront(); 
			display();
 			break;
			case 3:start=insertend();
			display();
 			break;
			case 4:start=deleteend();
			display();
		 	break;
			case 5:return;
		}
	}
}
