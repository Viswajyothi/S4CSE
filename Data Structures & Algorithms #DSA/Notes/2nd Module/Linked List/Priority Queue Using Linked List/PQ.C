#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct pq
{
int data,p;
struct pq *ll,*rl;
};

struct pq * enqueue(struct pq *,int,int);
struct pq * dequeue(struct pq *,int);
void display(struct pq *);
struct pq * clear(struct pq *);
struct pq * clear(struct pq *header)
{
struct pq *k;
while(header!=NULL)
{
k=header;
header=header->rl;
free(k);
}
return header;
}
void display(struct pq * j)
{
if(j!=NULL)
{
printf("\n\n");
while(j!=NULL)
{
printf("%d(%d) - ",j->data,j->p);
j=j->rl;
}
//getch();
}
}
struct pq * enqueue(struct pq *header,int data ,int p)
{
 struct pq *newnode,*ptr,*ptr1;
 newnode=(struct pq *)malloc(sizeof(struct pq));
 newnode->data=data;
 newnode->p=p;
 newnode->ll=NULL;
 newnode->rl=NULL;
 if(header->rl==NULL)
 {
 header->rl=newnode;
 newnode->ll=header;
 }
 else
 {
  ptr=header->rl;
  while((ptr->rl!=NULL) &&(ptr->p<=p))
  {
  ptr=ptr->rl;
  }
   if((ptr->rl==NULL) &&(ptr->p<=p))
   {
    ptr->rl=newnode;
    newnode->ll=ptr;
   }
   else
   {
    newnode->ll=ptr->ll;
    ptr->ll->rl=newnode;
    newnode->rl=ptr;
    ptr->ll=newnode;
   }
 }
return header;
}
struct pq * dequeue(struct pq *header,int p)
{
 struct pq *ptr;
 ptr=header->rl;
 if(ptr==NULL)
 {
 printf("\nList is Empty!");
 }
 else
 {
  while((ptr->p!=p)&&(ptr!=NULL))
  {
  ptr=ptr->rl;
  }
  if(ptr==NULL)
  printf("\nList contains no elements with priority %d!",p);
  else
  {
    ptr->ll->rl=ptr->rl;
    ptr->rl->ll=ptr->ll;
    free(ptr);
  }
 }
return header;
}
void main()
{
int ch=0,item,p;
struct pq *header;
header=(struct pq *)malloc(sizeof(struct pq));
header=NULL;
header->rl=NULL;
while(ch!=4)
{
clrscr();
display(header->rl);
printf("\n\n\n\n1- ENQUEUE");
printf("\n\n2- DEQUEUE");
printf("\n\n3- DISPLAY");
printf("\n\n4- EXIT\n");
printf("\n\nEnter choice to continue....");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter element to be enqueued:");
scanf("%d",&item);
printf("\nEnter priority of the element:");
scanf("%d",&p);
header=enqueue(header,item,p);
//display(header->rl);
break;
case 2:
printf("\nEnter priority of the element:");
scanf("%d",&p);
header=dequeue(header,p);
//display(header->rl);
break;

}

}
header=clear(header->rl);
free(header);
}