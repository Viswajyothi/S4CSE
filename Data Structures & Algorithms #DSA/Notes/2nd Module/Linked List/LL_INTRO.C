#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct ll
{
int data;
struct ll * link;
};
void create_list();
void display_list(struct ll *);
void create_infinite(struct ll *);

void create_list(struct ll *header)
{
 struct ll *p,*temp;
 char ch;
 printf("\nDo you want to create a node:(y/n)");
 scanf("%c",&ch);
 header->data=NULL;
 header->link=NULL;
 while(ch!='n')
 {
  p=(struct ll *)malloc(sizeof(struct ll));
  printf("\n\nEnter Data:");
  scanf("%d",&p->data);
  p->link=NULL;

  if(header->link==NULL)
   {
   header->link=p;
   temp=p;
   }
  else
   {
   temp->link=p;
   temp=p;
   }
  fflush(stdin);
  printf("\n\nDo you want to create a node:(y/n)");
 scanf("%c",&ch);

 }
}
void display_list(struct ll *k)
{
// clrscr();
 printf("\n\n");
 while(k!=NULL)
  {
  printf("%d -> ",k->data);
  k=k->link;
  }
}

void main()
{
   struct ll *header=NULL;
   int data,pos;
   clrscr();
   header=(struct ll *)malloc(sizeof(struct ll));
   //create_list(header);
   //display_list(header->link);
   //getch();
   clrscr();
   create_infinite(header);
   clrscr();
   display_list(header->link);
   getch();
}
void create_infinite(struct ll *header)
{
 struct ll *p,*temp;
 int ch,i=1;
 printf("\nHow many nodes to create:");
 scanf("%d",&ch);
 header->data=NULL;
 header->link=NULL;
  fflush(stdin);
 i=1;
 printf("%d",i);
 clrscr();
 getch();
 i=1;
 while(i<=ch)
 {
  p=(struct ll *)malloc(sizeof(struct ll));
  p->data=i;
  p->link=NULL;
  if(header->link==NULL)
   {
   header->link=p;
   temp=p;
   }
  else
   {
   temp->link=p;
   temp=p;
   }
 i++;
 }
 clrscr();
printf("\n\n\n LINK LIST OF NODES FROM 1 TO %d", ch);
//display_list(header->link);
}
