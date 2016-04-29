#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct bt
{
int data;
struct bt * lc,*rc;
}*root,*search,*pa;
int flag=0;
static int X=0;
void build_tree(struct bt *);
void inorder(struct bt *);
void preorder(struct bt *);
void postorder(struct bt *);
void delete_node(struct bt *);
void search_node(struct bt *,int);
void insert_leaf(int);
void search_parent(struct bt *,int);
void  mirror(struct bt *);
void display(int level,struct bt *ptr);
void mirror(struct bt * temp)
{
struct bt * u;
if(temp!=NULL)
{
 mirror(temp->lc);
 mirror(temp->rc);
 u=temp->lc;
 temp->lc=temp->rc;
 temp->rc=u;
}
}
void display(int level,struct bt *ptr)
{
 if(ptr!=NULL)
 {
   display(level+4,ptr->lc);
   X+=2;
   gotoxy(X,level);
   clreol(); /*clreol clears all characters from the cursor
position to the end of the line within the current text window,
without moving the cursor.*/

   printf("%d ",ptr->data);
   display(level+4,ptr->rc);
 }
}
void main()
{
int ch,item,parent;
clrscr();
root=(struct bt *)malloc(sizeof(struct bt));
fflush(stdin);
printf("\n\nEnter item:");
scanf("%d",&root->data);
build_tree(root);
printf("\n\n");
clrscr();
while(ch!=7)
{
clrscr();
printf("\n1-Search");
printf("\n2-Insert");
printf("\n3-Delete");
printf("\n4-Mirror");
printf("\n5-Traversal");
printf("\n6-Search parent");
printf("\n7-Exit");
printf("\n\nEnter Choice to continue...");
fflush(stdin);
scanf("%d",&ch);
switch(ch)
{
case 1:
search=NULL;
printf("\nEnter item to be searched:");
scanf("%d",&item);
flag=0;
search_node(root,item);
if(search==NULL)
printf("\n\n%d doesnot exist in the tree!",item);
else
printf("\n\n%d Found at Adrees Location %d",search->data,search);
getch();
break;
case 2:
search=NULL;
printf("\n\nEnter item to be inserted");
scanf("%d",&item);
printf("\n\nEnter the parent:");
scanf("%d",&parent);
flag=0;
search_node(root,parent);
if(search==NULL)
printf("\n\nThere is no such node!");
else
{
insert_leaf(item);
printf("\n\n");
getch();
}
clrscr();
	gotoxy(1,12);
	X=1;
	display(wherey(),root);
       gotoxy(1,29);
	getch();

break;
case 3:
printf("\n\nEnter item to be deleted:");
scanf("%d",&item);

pa=NULL;
flag=0;
search_parent(root,item);
if(pa==NULL)
printf("\n\nThere is no such node!");
else
{
printf("\n\nParent is %d ",pa->data);
if(pa->lc->data==item)
pa->lc=NULL;
else
pa->rc=NULL;
}
getch();
clrscr();
	gotoxy(1,12);
	X=1;
	display(wherey(),root);
       gotoxy(1,29);
	getch();

break;
case 4:
mirror(root);
break;
case 5:
clrscr();
	gotoxy(1,12);
	X=1;
	display(wherey(),root);
       gotoxy(1,29);
	getch();
	printf("\n\nPREORDER TRAVERSAL:");

	preorder(root);
	printf("\n\nINORDER TRAVERSAL:");

	inorder(root);
	printf("\n\nPOSTORDER TRAVERSAL:");

	postorder(root);

	break;
case 6:
printf("\n\nEnter the item:");
scanf("%d",&item);
pa=NULL;
flag=0;
search_parent(root,item);
if(pa==NULL)
printf("\n\nThere is no such node!");
else
{
printf("\n\nParent is %d ",pa->data);
}
getch();
break;




}
}

delete_node(root);
free(root);
getch();
}
void search_parent(struct bt * p,int item)
{
struct bt *ptr1,*ptr2;
if(p!=NULL)
{
if((p->lc->data==item) || (p->rc->data==item))
{
pa=p;
}
else
{
  ptr1=p->lc;
  ptr2=p->rc;
  search_parent(ptr1,item);
  search_parent(ptr2,item);
}
}
}
void insert_leaf(int item)
{
 char ch;
 struct bt * newnode;
 if(search!=NULL)
 {
   fflush(stdin);
   printf("\n\nInsert %d as (l/r) child? :",search->data);
   scanf("%c",&ch);
   if(ch=='l')
   {
    if(search->lc==NULL)
      {
	newnode=(struct bt *)malloc(sizeof(struct bt));
	newnode->data=item;
	newnode->lc=NULL;
	newnode->rc=NULL;
	search->lc=newnode;
      }
    else
       printf("\n\nInsertion not posible as left child!");
   }
   else if(ch=='r')
   {
   if(search->rc==NULL)
      {
	newnode=(struct bt *)malloc(sizeof(struct bt));
	newnode->data=item;
	newnode->lc=NULL;
	newnode->rc=NULL;
	search->rc=newnode;
      }
    else
       printf("\n\nInsertion not posible as right child!");

    }
    else
 printf("\n\nInvalid Choice!");

 }

}
void search_node(struct bt * s,int item)
{
 if((s!=NULL)&&(flag==0))
 {
   if(s->data==item)
   {
     flag=1;
     search=s;
   }
   else
   {
    search_node(s->lc,item);
    search_node(s->rc,item);
   }
 }
}
void build_tree(struct bt * ptr)
{
 struct bt *lcptr,*rcptr;
 char ch;
 if(ptr!=NULL)
 {
  fflush(stdin);
  printf("\n\nDo you want to create left child for %d:", ptr->data);
  scanf("%c",&ch);
  lcptr=(struct bt *)malloc(sizeof(struct bt));
  if(ch=='y')
  {
     fflush(stdin);
   printf("\n\nEnter Data:");
   scanf("%d", &lcptr->data);
   lcptr->lc=NULL;
   lcptr->rc=NULL;
   ptr->lc=lcptr;
   build_tree(lcptr);
  }
  else
  {
  lcptr=NULL;
  ptr->lc=NULL;
  build_tree(lcptr);
  }
    fflush(stdin);
  printf("\n\nDo you want to create right child for %d:", ptr->data);
  scanf("%c",&ch);
  rcptr=(struct bt *)malloc(sizeof(struct bt));
  if(ch=='y')
  {
   fflush(stdin);
   printf("\n\nEnter Data:");
   scanf("%d", &rcptr->data);
   rcptr->lc=NULL;
   rcptr->rc=NULL;
   ptr->rc=rcptr;
   build_tree(rcptr);
  }
  else
  {
  rcptr=NULL;
  ptr->rc=NULL;
  build_tree(rcptr);
  }

 }
}
void inorder(struct bt * ptr1)
{
if(ptr1!=NULL)
{
inorder(ptr1->lc);
printf(" %d ",ptr1->data);
inorder(ptr1->rc);
}
}
void preorder(struct bt * ptr1)
{
if(ptr1!=NULL)
{
printf(" %d ",ptr1->data);
inorder(ptr1->lc);

inorder(ptr1->rc);
}
}
void postorder(struct bt * ptr1)
{
if(ptr1!=NULL)
{
inorder(ptr1->lc);
inorder(ptr1->rc);
printf(" %d ",ptr1->data);
}
}

void delete_node(struct bt * ptr2)
{
struct bt * temp;
if(ptr2!=NULL)
{

delete_node(ptr2->lc);
delete_node(ptr2->rc);
printf("\n\nDeleting %d",ptr2->data);
temp=ptr2;
free(temp);

}
}