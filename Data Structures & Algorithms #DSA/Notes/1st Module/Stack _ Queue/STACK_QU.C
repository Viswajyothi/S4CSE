#include<stdio.h>
#include<conio.h>
int push(int,int,int[]);
int pop(int);
void display(int,int []);
void enqueue(int *,int *,int,int []);
void dequeue(int *,int *);
void show(int *,int *,int []);
int push(int item,int top,int s[])
{
top=top+1;
s[top]=item;
return top;
}

int pop(int top)
{
if(top>-1)
return --top;
else
printf("Stack is Empty");
return top;
}

void display(int top, int s[])
{
int i=0;
printf("\n\n");
for(i=top;i>=0;i--)
printf(" %d \n",s[i]);
}
void enqueue(int *f,int *r,int item,int q[100])
{
if((*f==-1)&&(*r==-1))
{
*f=*r=0;
q[*r]=item;
}
else
{
*r=*r+1;
q[*r]=item;
}
}

void dequeue(int *f,int *r)
{
if( (*f==0)&&(*r==0) || (*f==*r))
{
*f=-1;
*r=-1;
}
else
*f=*f+1;

}

void show(int *f,int *r,int q[100])
{
int i;
if(*f==-1)
printf("Queue is Empty!");
else
for(i=*f;i<=*r;i++)
printf(" %d ",q[i]);
}

void main()
{

int s[100],q[100],top=-1,item,ch1=0,ch2=0,ch3=0,maxs,maxq,front=-1,rear=-1;
while(ch1!=3)
{
 clrscr();
 printf("\n\t\tSTACK AND QUEUE");
 printf("\n\t\t***************\n\n");
 printf("\n1. STACK");
 printf("\n2. QUEUE");
 printf("\n3. EXIT");
 printf("\nEnter Choice to continue...");
 scanf("%d",&ch1);
 switch(ch1)
 {
  case 1:
	printf("Enter the size of the stack:");
	scanf("%d",&maxs);
	while(ch2!=4)
	{
	 clrscr();
	 printf("\n1. PUSH");
	 printf("\n2. POP");
	 printf("\n3. DISPLAY");
	 printf("\n4. EXIT TO MAIN MENU");
	 printf("\nEnter Choice to continue...");
	 scanf("%d",&ch2);
	 switch(ch2)
	  {
	    case 1:
	    printf("\nEnter Item to be pushed:");
	    scanf("%d",&item);
	    if(top<maxs-1)
	    top=push(item,top,s);
	    else
	    printf("Stack is full!");
	    printf("\n\nNow the stack is ");
	    display(top,s);
	    getch();
	    break;
	    case 2:
	    top=pop(top);
	    printf("\n\nNow the stack is ");
	    display(top,s);
	    getch();
	    break;
	    case 3:
	    display(top,s);
	    getch();
	    break;
	    default:
	    printf("Inavlid Choice!");
	  }
	 }
     break;
     case 2:
	printf("Enter the size of the queue:");
	scanf("%d",&maxq);
	while(ch3!=4)
	{
	 clrscr();
	 printf("\n1. ENQUEUE");
	 printf("\n2. DEQUEUE");
	 printf("\n3. DISPLAY");
	  printf("\n4. EXIT TO MAIN MENU");
	 printf("\nEnter Choice to continue...");
	 scanf("%d",&ch3);
	 switch(ch3)
	  {
	    case 1:
	    printf("\nEnter Item to be Enqueued:");
	    scanf("%d",&item);
	    if(rear<maxq-1)
	    {
	    enqueue(&front,&rear,item,q);
	    //printf("\n front=%d rear=%d",front,rear);

	    }
	    else
	    printf("Queue is full!");
	    printf("\nNow the Queue is \n");
	    show(&front,&rear,q);
	    getch();
	    break;
	    case 2:
	    if((front!=-1)&&(rear!=-1))
	    {
	    dequeue(&front,&rear);
	    //printf("\n front=%d rear=%d",front,rear);
	     }
	    else
	    printf("\nQueue is empty!");
	    printf("\nNow the Queue is \n");
	    show(&front,&rear,q);
	    getch();
	    break;
	    case 3:
	    show(&front,&rear,q);
	    getch();
	    break;
	    default:
	    printf("Inavlid Choice!");
	  }
	 }
     break;

  }
}
}