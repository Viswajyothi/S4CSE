#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct stack
{
int data;
struct stack * link;
};
struct queue
{
int data;
struct queue *link;
}*f,*r;
struct stack * push(struct stack *,int);
struct stack * pop(struct stack *);
void display(struct stack *);
struct stack * clear(struct stack *);
void enqueue(int);
void dequeue();
void display_queue();
struct queue* clear_queue();


struct stack * push(struct stack * top,int item)
{
struct stack *newnode;
newnode=(struct stack *)malloc(sizeof(struct stack));
newnode->data=item;
newnode->link=NULL;
if(top==NULL)
   top=newnode;
else
   {
    newnode->link=top;
    top=newnode;
   }
return top;
}
struct stack * pop(struct stack * p)
{
struct stack *temp;
if(p==NULL)
printf("\n\n The Stack is Empty!");
else
{
temp=p;
p=p->link;
free(temp);
}
return p;
}

void display(struct stack * j)
{
 printf("\n\n");
 if(j==NULL)
 printf("\n\nThe Stack is Empty!");
 else
 while(j!=NULL)
 {
 printf("\n\t%d\n",j->data);
 j=j->link;
 }
getch();
}
struct stack * clear(struct stack *c)
{
struct stack *i;
while(c!=NULL)
{
i=c;
c=c->link;
printf("\nDeleting Node%d",i->data);
free(i);
}
getch();
return NULL;
}
struct queue * clear_queue()
{
struct queue *i;
while(f!=NULL)
{
i=f;
f=f->link;
printf("\nDeleting Node%d",i->data);
free(i);
}
getch();
return NULL;
}

void enqueue(int item)
{
 struct queue *node;
 node=(struct queue *)malloc(sizeof(struct queue));
 node->data=item;
 node->link=NULL;
 if(f==NULL)
 {
   f=node;
   r=node;
 }
 else
 {
 r->link=node;
 r=node;
 }
}

void dequeue()
{
struct queue *temp;
if(f==NULL)
{
printf("\nThe Queue is Empty!");
}
else
{
if(f==r)
{
f=NULL;
r=NULL;
}
else
{
temp=f;
f=f->link;
}
free(temp);
}
}
void display_queue()
{
struct queue * y;
y=f;
  if(y==NULL)
 {
 printf("\nThe Queue is Empty!");
 }
 else
 {
 while(y!=NULL)
 {
   printf(" %d ",y->data);
   y=y->link;
 }
 }
 getch();
}
void main()
{
 struct stack *top;
 int ch1=0,ch2=0,ch3=0,item;
 top=(struct stack *)malloc(sizeof(struct stack));
  f=(struct queue *)malloc(sizeof(struct queue));
   r=(struct queue *)malloc(sizeof(struct queue));
 top->data=NULL;
 top->link=NULL;
 top=NULL;
 f->data=NULL;
 f->link=NULL;
 f=NULL;
 r->data=NULL;
 r->link=NULL;
 r=NULL;

while(ch1!=3)
{
 clrscr();
  printf("\n1-Stack\n");
  printf("\n2-Queue\n");
  printf("\n3-Exit\n");
  printf("\nEnter Choice...:");
  scanf("%d",&ch1);
 switch(ch1)
 {
 case 1:
 while(ch2!=4)
 {
  clrscr();
  printf("\n1-PUSH\n");
  printf("\n2-POP\n");
  printf("\n3-DISPLAY\n");
  printf("\n4-EXIT\n");
  printf("\nEnter Choice...:");
  scanf("%d",&ch2);
  switch(ch2)
  {
   case 1:
   printf("\nEnter item to push:");
   scanf("%d",&item);
   top=push(top,item);
   display(top);
   break;
   case 2:
   top=pop(top);
   display(top);
   break;
   case 3:
   display(top);
   break;
  }

 }
 top=clear(top);
 break;
 case 2:
 while(ch3!=4)
 {
  clrscr();
  printf("\n1-Enqueue\n");
  printf("\n2-Dequeue\n");
  printf("\n3-DISPLAY\n");
  printf("\n4-EXIT\n");
  printf("\nEnter Choice...:");
  scanf("%d",&ch3);
  switch(ch3)
  {
   case 1:
   printf("\nEnter item to Enqueue:");
   scanf("%d",&item);
   enqueue(item);
   if(f==NULL)
   printf("f is null");
   display_queue();
   break;
   case 2:
   dequeue(f,r);
      display_queue();
   break;
   case 3:
      display_queue();
   break;
  }

 }
 f=clear_queue();
 break;
 }
 //
}


free(top);
free(f);
free(r);
}
