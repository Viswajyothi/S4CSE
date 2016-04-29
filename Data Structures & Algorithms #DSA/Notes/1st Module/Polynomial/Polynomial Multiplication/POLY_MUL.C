# include <stdio.h>
# include <conio.h>
struct element
   {int coeff;
    int exp;
   };
//struct  element *  getdata(struct element [],int);
//struct element * getdata(struct element a[],int b)
//{
//return a;
//}
void main()
{
struct element p[20],q[20],c[20];
int i,j,k,n1,n2,temp_coeff,temp_exp,count=0,g,loc=0,cof,ex,u,temp=0,ii,jj;
clrscr();
printf("enter the no of terms in first and second polynomial\n");
scanf("%d %d",&n1,&n2);
printf("\nenter the coefficient & exponent of the  first polynomial\n");
for (i=0;i<n1;i++)
     {scanf("%d",&p[i].coeff);
     scanf("%d",&p[i].exp);
     }

printf("\nenter the coefficient & exponent of the  second polynomial\n");
for (i=0;i<n2;i++)
     {scanf("%d",&q[i].coeff);
     scanf("%d",&q[i].exp);
     }

i=0;j=0;k=0;
while(i<n1)
{
  while(j<n2)
  {
   cof=p[i].coeff*q[j].coeff;
   ex=p[i].exp+q[j].exp;
//   printf("\nNow:%dX%d",cof,ex);
   if(count==0)
   {
   c[k].coeff=cof;
   c[k].exp=ex;
   }
   else
   {
   for(g=0;g<k;g++)
    {
     if(ex==c[g].exp)
      {
  //    printf("Adding %dX%d and %d to location %d",c[g].coeff,c[g].exp,ex,g);
      c[g].coeff=cof+c[g].coeff;
      k--;
	  loc=1;

      }
    }
      if(loc==0)
      {
      c[k].coeff=cof;
      c[k].exp=ex;
      }
      loc=0;


   temp=0;
   }
   j++;
   k++;
   count++;
   temp++;
   }
j=0;
i++;
}
//printf("\n\nk=%d\n\n",k);
ii=n1;
jj=n2;
i=0;j=0;
for(i=k;i>0;i--)
for(j=0;j<i;j++)
{
if(c[j].exp<c[j+1].exp)
{
temp_coeff=c[j+1].coeff;
temp_exp=c[j+1].exp;
c[j+1].coeff=c[j].coeff;
c[j+1].exp=c[j].exp;
c[j].coeff=temp_coeff;
c[j].exp=temp_exp;
}
}
getch();

printf ("the resultant polynomial is\n");
for(i=0;i<ii;i++)
		    {if(p[i].exp!=0)
		      {printf(" %dx^%d +",p[i].coeff,p[i].exp);
		      }
else
		       {printf("%d",p[i].coeff);
		       }
		      }
		      printf("  X\n");

for(i=0;i<jj;i++)
		    {if(q[i].exp!=0)
		      {printf(" %dx^%d +",q[i].coeff,q[i].exp);
		      }
else
		       {printf("%d",q[i].coeff);
		       }
		      }

printf("\n*******************************\n\n");
for(i=0;i<k;i++)
		    {if(c[i].exp!=0)
		      {printf(" %dx^%d +",c[i].coeff,c[i].exp);
		      }
else
		       {printf("%d",c[i].coeff);
		       }
		      }
getch();

}
