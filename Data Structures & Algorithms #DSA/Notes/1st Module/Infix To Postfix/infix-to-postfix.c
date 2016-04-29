/// This program is a implementation of shunting yard algorithm to convert an infix expression to post fix expression, This is a extension of the stack 
//program published earlier
/*   * While there are tokens to be read:

        * Read a token.
        * If the token is a number, then add it to the output queue.
        * If the token is a function token, then push it onto the stack.
        * If the token is a function argument separator (e.g., a comma):

            * Until the topmost element of the stack is a left parenthesis, pop the element from the stack and push it onto the output queue.
	      If no left parentheses are encountered, either the separator was misplaced or parentheses were mismatched.

        * If the token is an operator, o1, then:

            * while there is an operator, o2, at the top of the stack, and either

                    o1 is associative or left-associative and its precedence is less than (lower precedence) or equal to that of o2, or
                    o1 is right-associative and its precedence is less than (lower precedence) that of o2,

                pop o2 off the stack, onto the output queue;

            * push o1 onto the stack.

        * If the token is a left parenthesis, then push it onto the stack.
        * If the token is a right parenthesis:

            * Until the token at the top of the stack is a left parenthesis, pop operators off the stack onto the output queue.
            * Pop the left parenthesis from the stack, but not onto the output queue.
            * If the token at the top of the stack is a function token, pop it and onto the output queue.
            * If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.

    * When there are no more tokens to read:

        * While there are still operator tokens in the stack:

            * If the operator token on the top of the stack is a parenthesis, then there are mismatched parenthesis.
            * Pop the operator onto the output queue.

    * Exit.

*/
//Program downloaded from GeeksPlanet.net
//http://geeksplanet.net/2008/10/c-programming/program-to-convert-infix-expression-to-postfix-in-c-shunting-yard-algorithm/
#include<stdio.h>
#include<string.h>
#define size 10
char stack[size];
int tos=0,ele;
void push();
char pop();
void show();
int isempty();
int isfull();
char infix[30],output[30];
int prec(char);

int main()
{
		int i=0,j=0,k=0,length;
		char temp;
		printf("\nEnter an infix expression:");
		scanf("%s",infix);
		printf("\nThe infix expresson is %s",infix);
		length=strlen(infix);
		for(i=0;i<length;i++)
		{
			//Numbers are added to the out put QUE
			if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!=')' && infix[i]!='(' )
			{
			output[j++]=infix[i];
			printf("\nThe element added to Q is:%c",infix[i]);
			}
			//If an operator or a bracket is encountered...
			else
			{
				if(tos==0) //If there are no elements in the stack, the operator is added to it
				{
				push(infix[i]);
				printf("\nThe pushed element is:%c",infix[i]);
				}
				else 
				{       //Operators or pushed or poped based on the order of precedence
					if(infix[i]!=')' && infix[i]!='(')
					{
						if(    prec(infix[i]) <= prec(stack[tos-1])  )
						{
						temp=pop();
						printf("\n the poped element is :%c",temp);
						output[j++]=temp;
						push(infix[i]);
						printf("\n The pushed element is :%c",infix[i]);
						show();
						}
						else
						{
						push(infix[i]);
						printf("\nThe pushed element is:%c",infix[i]);
						show();
						}
					}
					else
					{
						if(infix[i]=='(')
						{
						push(infix[i]);
						printf("\nThe pushed-- element is:%c",infix[i]);
						}
						if(infix[i]==')')
						{
						temp=pop();
						while(temp!='(')
						{output[j++]=temp;
						printf("\nThe element added to Q is:%c",temp);
						//temp=pop();
						printf("\n the poped element is :%c",temp);
						temp=pop();}
						}
					}

				}
					
			}	
	
 printf("\nthe infix expression is: %s",output);

		}
		while(tos!=0)
		{
			output[j++]=pop();
		}
 printf("the infix expression is: %s\n",output);

}
//Functions for operations on stack
void push(int ele)
{
	stack[tos]=ele;
	tos++;
}
char pop()
{
	tos--;
	return(stack[tos]);
}
void show()
{
	int x=tos;	
	printf("--The Stack elements are.....");
	while(x!=0)
	printf("%c, ",stack[--x]);
}
//Function to get the precedence of an operator
int prec(char symbol)
{

if(symbol== '(')
return 0;
if(symbol== ')')
return 0;
if(symbol=='+' || symbol=='-')
return 1;
if(symbol=='*' || symbol=='/')
return 2;
if(symbol=='^')
return 3;
return 0;
}


