# include <stdio.h>
# include <conio.h>

struct element
   {
    int coeff;
    int exp;
   };


void main()
{
struct element p[10],q[10],c[10];
int i,j,k,n1,n2;
clrscr();
printf("enter the no of terms in first and second polynomial\n");
scanf("%d %d",&n1,&n2);
printf("\nPOLYNOMIAL P:\n");
for (i=0;i<n1;i++)
     {
     printf("\nCoefficient & Exponent of P:\n");
     scanf("%d",&p[i].coeff);
     scanf("%d",&p[i].exp);
     }
printf("\nPOLYNOMIAL Q:\n");

for (i=0;i<n2;i++)
     {
     printf("\nCoefficient & Exponent of Q:\n");
     scanf("%d",&q[i].coeff);
     scanf("%d",&q[i].exp);
     }


i=0;j=0;k=0;
while((i<n1)&&(j<n2))
	  {if (p[i].exp==q[j].exp)
	      {  c[k].exp=p[i].exp;
		 c[k].coeff=p[i].coeff+q[j].coeff;
		 k++;
		 j++;
		 i++;
	       }
	       else if(p[i].exp>q[j].exp)
	      {
	      c[k].exp=p[i].exp;
		 c[k].coeff=p[i].coeff;
		 k++;
		 i++;
	      }
	      else
	 {if(p[i].exp<q[j].exp);
	      {  c[k].exp=q[j].exp;
		 c[k].coeff=q[j].coeff;
		 k++;
		 j++;
	      }  }
	 }
 while(i<n1)
		    {  c[k].exp=p[i].exp;
		      c[k].coeff=p[i].coeff;
		      k++;
		      i++;
		     }
while(j<n2)
		    {c[k].exp=q[j].exp;
		     c[k].coeff=q[j].coeff;
		     k++;
		     j++;
		    }
printf ("\n\nThe resultant polynomial is\n\n\n");
for(i=0;i<k;i++)
		    {if(c[i].exp!=0)
		      {printf("%dx^%d+ ",c[i].coeff,c[i].exp);
		      }
else
		       {printf("%d",c[i].coeff);
		       }
		      }
getch();

}
