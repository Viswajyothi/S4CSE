      /*Infix to Postfix Conversion*/
 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>

 char inf[50],pof[50],opstk[30],opr;
 int i=0,j=0,a,b,l,top=-1;
 int pre();
 void posteval();
 void push(char c)
  {opstk[++top]=c;}
 char pop()
   {  return opstk[top--];
   }

 void main()
 {
  clrscr();
  printf("\n\n\t\t ENTER THE EXPRESSION : ");
  gets(inf);
  l=strlen(inf);
  inf[l]=')';
  inf[++l]='\0';
  opstk[++top]='(';
  for(i=0;i<l;i++)
  {
  /*transfer all the characters of the operand to the pof array*/
  if(isalnum(inf[i]))
   {
    pof[j++]=inf[i];
     if(!isalnum(inf[i+1]))
	pof[j++]=' ';
   }
  else
  {
   switch(inf[i])
   {
   case '*':
   case  '+':
   case '-':
   case '^':
   case '/':
    if(top!=-1)
      {opr=pop();
      printf("\nstack opr=%c",opr);
      a=priority(opr);
      b=priority(inf[i]);
      printf(" stackp%d ,inp%d",a,b);
      printf(" top=%d",top);

      while((top>=0) && (priority(opr)>=priority(inf[i])))
	 {
	 pof[j++]=opr;
	   opr=pop();
	 }
      push(opr);
      push(inf[i]);
     }
    else /*if stack has no contents*/
      push(inf[i]);
   break;

   /*if the incoming character is not an operator*/
  case '(':
		push(inf[i]);
		break;
 case ')':
	     opr=pop();
	while(opr!='(')
       {
	 pof[j++]=opr;
	 opr=pop();
       }
	break;
  }//switch
  }//else
  }//for
 /*When the input is fully traversed and there are elements
 int the stack,pop the contents */
   while(top!=-1)
   {
    pof[j++]=opstk[top--];
    pof[j++]=' ';
   }
 printf("\n\n\t\t  THE POSTFIX EXPRESSION IS: ");
 puts(pof);
  top=-1;
 posteval();
 getch();
}
 void posteval()
 {
  int i=0,k=0,l=-1;
  char eval[100];
   //char a='9';
   //int z=a-48;
  // z++;
  // printf("\nz=%d",z);
  while(pof[i]!='\0')
  {
  if(isalnum(pof[i]))
  {
     l=-1;
     while(pof[k]!='\0')
     {
       if(k!=0)
       {
	  if(pof[k]==pof[i])
	   l=1;
       }
     }
     scanf("%c",eval[i]);
  }
  else

  }
 }

 /* This function returns 1 when the stack contents are to be popped out*/
 int priority(char c)
 {
   if(c=='^') return 3;
   if(c=='*' ||c=='/'||c=='%') return 2;
   if(c=='+'||c=='-') return 1;
   else return 0;

 }