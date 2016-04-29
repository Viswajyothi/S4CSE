
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct poly
{
int c,e;
struct poly * link;
};
void create_list(struct poly *);
void display_list(struct poly *);
void poly_add(struct poly *, struct poly *, struct poly *);
void poly_mul(struct poly *, struct poly *, struct poly *);
struct poly * free_nodes(struct poly *);
void sort(struct poly *);
struct poly * free_nodes(struct poly * header)
{
struct poly * temp;
while(header!=NULL)
{
temp=header;
header=header->link;
free(temp);
}
return header;
}

void create_list(struct poly *header)
{
 struct poly *p,*temp;
 char ch;
 printf("\nDo you want to create a node:(y/n)");
 fflush(stdin);
 scanf("%c",&ch);
 header->c=NULL;
 header->e=NULL;
 header->link=NULL;
 while(ch!='n')
 {
  p=(struct poly *)malloc(sizeof(struct poly));
  printf("\n\nEnter Coefficient:");
  scanf("%d",&p->c);
  printf("\n\nEnter Exponent:");
  scanf("%d",&p->e);

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
void display_list(struct poly *k)
{
 printf("\n\n");
 while(k!=NULL)
  {
  printf("%dX^%d + ",k->c,k->e);
  k=k->link;
  }
 // getch();
}
void poly_add(struct poly *p, struct poly *q,struct poly *r)
{
struct poly *newnode,*temp;
r->link=NULL;
while((p!=NULL)&&(q!=NULL))
{
 newnode=(struct poly *)malloc(sizeof(struct poly));
 newnode->c=NULL;
 newnode->e=NULL;
 newnode->link=NULL;

 if(p->e==q->e)
  {
    newnode->c=p->c+q->c;
    newnode->e=p->e;
    p=p->link;
    q=q->link;

  }
  else if(p->e>q->e)
  {
    newnode->c=p->c;
    newnode->e=p->e;
    p=p->link;
  }
  else
  {
    newnode->c=q->c;
    newnode->e=q->e;
    q=q->link;

  }

  if(r->link==NULL)
  {
  r->link=newnode;
  temp=newnode;
  }
  else
  {
  temp->link=newnode;
  temp=newnode;
  }
}
while(p!=NULL)
{
 newnode=(struct poly *)malloc(sizeof(struct poly));
 newnode->c=NULL;
 newnode->e=NULL;
 newnode->link=NULL;
 newnode->c=p->c;
 newnode->e=p->e;
 temp->link=newnode;
 temp=newnode;
 p=p->link;
}
while(q!=NULL)
{
 newnode=(struct poly *)malloc(sizeof(struct poly));
 newnode->c=NULL;
 newnode->e=NULL;
 newnode->link=NULL;
 newnode->c=q->c;
 newnode->e=q->e;
 temp->link=newnode;
 temp=newnode;
 q=q->link;
}
}
void poly_mul(struct poly *p, struct poly *q, struct poly * s)
{
   int flag=0;
 struct poly *newnode,*temp,*ss,*qq;
  s->link=NULL;

 qq=q;
 while(p!=NULL)
 {
  q=qq;
  while(q!=NULL)
  {
    newnode=(struct poly *)malloc(sizeof(struct poly));
    newnode->link=NULL;

    newnode->c=p->c*q->c;
    newnode->e=p->e+q->e;
//    printf("\n Multiplied %dX^%d", newnode->c,newnode->e);

    if(s->link==NULL)
     {
      s->link=newnode;
      temp=newnode;
     }
    else
    {

      ss=s->link;
      flag=0;
      while(ss!=NULL)
      {
       //	printf("\n Comparing %dX^%d and %dX^%d",ss->c,ss->e,newnode->c,newnode->e);
	if(ss->e==newnode->e)
	{
	 ss->c=ss->c+newnode->c;
	 flag=1;
	}
       ss=ss->link;

      }
      if((ss==NULL)&&(flag==0))
      {
       temp->link=newnode;
       temp=newnode;
      }

    }
    q=q->link;
    //printf("\n\n The polynomial is \n\n");
   // display_list(s->link);
   // getch();
  }
  p=p->link;
 }
    clrscr();
    printf("\n\n The polynomial is \n\n");
    display_list(s->link);
    getch();
}
void sort(struct poly * i)
{
struct poly *j,*temp;
int c,e;
temp=i;
while(i!=NULL)
{
 j=i->link;
 while(j!=NULL)
 {
//   printf("\n Comparing %dX^%d and %dX^%d",i->c,i->e,j->c,j->e);
   //getch();

   if(i->e<j->e)
   {
     c=i->c;
     e=i->e;
     i->c=j->c;
     i->e=j->e;
     j->c=c;
     j->e=e;
   }
 j=j->link;
 }
 i=i->link;
}
//display_list(temp);
}
void main()
{
   struct poly *p=NULL,*q=NULL,*r=NULL,*s=NULL;
   clrscr();
   p=(struct poly *)malloc(sizeof(struct poly));
   q=(struct poly *)malloc(sizeof(struct poly));
   r=(struct poly *)malloc(sizeof(struct poly));
   s=(struct poly *)malloc(sizeof(struct poly));
     create_list(p);
     create_list(q);
     display_list(p->link);
     printf("\n\n");
     display_list(q->link);
     printf("\n\n");
     poly_add(p->link,q->link,r);
     sort(r->link);
     display_list(r->link);
     getch();
     poly_mul(p->link,q->link,s);
     sort(s->link);
     display_list(s->link);
     p=free_nodes(p);
     q=free_nodes(q);
     r=free_nodes(r);
     s=free_nodes(s);
     free(p);
     free(q);
     free(r);
     free(s);
   getch();
}
