#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct dll
{
int data;
struct dll *ll,*rl;
};
struct dll * insert_f(struct dll *,int);
struct dll * insert_r(struct dll *,int);
struct dll * insert_any(struct dll *,int,int);
struct dll * delete_f(struct dll *);
struct dll * delete_r(struct dll *);
struct dll * delete_any(struct dll *,int);
struct dll * free_nodes(struct dll *);

void display(struct dll *);

struct dll * insert_f(struct dll * header,int data)
{
 struct dll *newnode;
 newnode=(struct dll *)malloc(sizeof(struct dll));
 newnode->data=data;
 newnode->ll=NULL;
 newnode->rl=NULL;
 if(header->rl==NULL)
 {
  header->rl=newnode;
  newnode->ll=header;
 }
 else
 {
  newnode->rl=header->rl;
  newnode->rl->ll=newnode;
  header->rl=newnode;
 }
 return header;
}
struct dll * insert_r(struct dll * header,int data)
{
 struct dll *newnode,*ptr;
 newnode=(struct dll *)malloc(sizeof(struct dll));
 newnode->data=data;
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
  while(ptr->rl!=NULL)
  {
  ptr=ptr->rl;
  }
  newnode->ll=ptr;
  ptr->rl=newnode;
 }
 return header;
}
struct dll * insert_any(struct dll * header,int data,int pos)
{
 int count=0;
 struct dll *newnode,*ptr;
 ptr=header->rl;

 newnode=(struct dll *)malloc(sizeof(struct dll));
 newnode->data=data;
 newnode->ll=NULL;
 newnode->rl=NULL;
 if(pos==1)
 {
  newnode->ll=header;
  newnode->rl=header->rl;
  header->rl->ll=newnode;
  header->rl=newnode;
 }
 else
 {
 while(count+1!=pos)
 {
 ptr=ptr->rl;
 count++;
 }
 if(ptr==NULL)
 printf("\n\nNo such position in this list!");
 else
 {
   newnode->ll=ptr->ll;
   newnode->rl=ptr;
   ptr->ll->rl=newnode;
   ptr->ll=newnode;

 }
 }
 return header;
}
struct dll * delete_f(struct dll * header)
{
struct dll *ptr;
ptr=header->rl;
header->rl=ptr->rl;
ptr->rl->ll=header;
free(ptr);
return header;
}
struct dll * delete_r(struct dll * header)
{
struct dll *ptr;
ptr=header->rl;
while(ptr->rl!=NULL)
{
ptr=ptr->rl;
}
ptr->ll->rl=NULL;
free(ptr);
return header;
}
struct dll * delete_any(struct dll * header,int data)
{
int flag=0;
struct dll *ptr;
ptr=header->rl;
while((ptr!=NULL)&&(flag==0))
{
if(ptr->data==data)
flag=1;
else
ptr=ptr->rl;
}
if(ptr==NULL)
printf("No such element exists!");
else
{
ptr->ll->rl=ptr->rl;
ptr->rl->ll=ptr->ll;
free(ptr);
}
return header;
}

void display(struct dll * j)
{
struct dll *temp;
if(j!=NULL)
{
printf("\n\n Display in Forward Direction\n\n");
while(j!=NULL)
{
printf("%d->",j->data);
temp=j;
j=j->rl;
}
printf("\n\n Display in Reverse Direction\n\n");
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->ll;
}
}
else
printf("\n\nEmpty List!");
getch();
}
struct dll * free_nodes(struct dll * header)
{
struct dll * temp;
while(header!=NULL)
{
temp=header;
header=header->rl;
free(temp);
}
return header;
}
void main()
{
 int ch=0,data,pos;
 struct dll *header;
 header=(struct dll *)malloc(sizeof(struct dll));
 header=NULL;
 header->rl=NULL;
 header->ll=NULL;
 while(ch!=8)
  {
    clrscr();
    printf("\n1-Insert @ front");
    printf("\n2-Insert @ rear");
    printf("\n3-Insert @ any");
    printf("\n4-Delete @ front");
    printf("\n5-Delete @ rear");
    printf("\n6-Delete  any");
    printf("\n7-Display\n");
    printf("\n8-Exit\n");
    scanf("%d",&ch);
    switch(ch)
     {
     case 1:
     printf("\n\nEnter Data");
     scanf("%d",&data);
     header=insert_f(header,data);
     display(header->rl);
     break;
     case 2:
     printf("\n\nEnter Data");
     scanf("%d",&data);
     header=insert_r(header,data);
     display(header->rl);
     break;
     case 3:
     printf("\n\nEnter Data");
     scanf("%d",&data);
     printf("\n\nEnter Position");
     scanf("%d",&pos);

     header=insert_any(header,data,pos);
     display(header->rl);
     break;
     case 4:
     header=delete_f(header);
     display(header->rl);
     break;
     case 5:
     header=delete_r(header);
     display(header->rl);
     break;
     case 6:
     printf("Enter elemnt to be deleted:");
     scanf("%d",&data);
     header=delete_any(header,data);
     display(header->rl);
     break;
     case 7:
     display(header->rl);
     break;

     }
  }

free(free_nodes(header->rl));
}