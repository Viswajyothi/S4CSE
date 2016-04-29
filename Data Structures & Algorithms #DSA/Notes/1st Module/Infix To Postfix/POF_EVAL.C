/*                       TITLE :POSTFIX EVALUATION               */
/*****************************************************************/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int pop(void);
void push(int);
int top=0,a[50];
void main()
{ char str[100],item,op;
  int i=0,n,x,y,t;
  clrscr();
  printf("\nenter the postfix expression\n");
  gets(str);
   while((item=str[i])!='\0')
 {
	if(((item>='a')&&(item<='z'))||((item>='A')&&(item<='Z')))
		{
		printf("\nenter the value of %c=",str[i]);
		scanf("%d",&n);
		push(n);
		}
	    else
	    { op=item;
	      y=pop();
	      x=pop();
	      if(op=='+')
	      {t=x+y;
	       push(t);
	      }
	      if(op=='-')
	      {t=x-y;
	       push(t);
		  }
	      if(op=='/')
	      {t=x/y;
	       push(t);
	      }
	      if(op=='*')
	      {t=x*y;
	       push(t);
	      }
	      if(op=='^')
	      {t=pow(x,y);
	       push(t);
	      }
	    }
	    i++;
}
 x=pop();
 printf("\npostfix evaluation=%d",x);
  getch();
  }

 int pop(void)
 {
   int h;
   h=a[top];
   top--;
  return(h);
  }
 void push(int n)
 { top++;
   a[top]=n;

 }