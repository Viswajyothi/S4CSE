
      /*Infix to Postfix Conversion*/

 #include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>

 char inf[50],pof[50],opstk[30];
 int i=0,j=0,l,top=-1;
 int pre();
 void main()
 {
  clrscr();
  printf("\n\n\t\t ENTER THE EXPRESSION : ");
  gets(inf);
  l=strlen(inf);
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
   while(top!=-1 &&pre())
   {
    pof[j++]=opstk[top--];
    pof[j++]=' ';
   }
   if(inf[i]!=')')
    opstk[++top]=inf[i];
   else  /*if input array has ')'*/
   top--;
  }
 }
 /*When the input is fully traversed and there are elements
 int the stack,pop the contents */
   while(top!=-1)
   {
    pof[j++]=opstk[top--];
    pof[j++]=' ';
   }
 printf("\n\n\t\t  THE POSTFIX EXPRESSION IS: ");
 puts(pof);
 getch();
}

 /* This function returns 1 when the stack contents are to be popped out*/
 int pre()
 {
  int x=0;
  /* If the input array is ')', pop out the contents of the stack
  till '(' in the stack top*/
  if(opstk[top]!='(' && inf[i]==')')
     x=1;
  if((opstk[top]=='/' || opstk[top]=='*') && inf[i]!='(' )
      x=1;
   /*if the stack top is + or -, and the input character is / or *,
    since / and * has higher precedence, the new input has to be pushed*/
    if(opstk[top]=='+' || opstk[top]=='-')
       if(inf[i]!='/' && inf[i]!='*' && inf[i]!='(')
	x=1;
   return(x);
 }