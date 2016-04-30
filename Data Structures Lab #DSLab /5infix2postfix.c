#include<stdio.h> 

char s[50]; int top = -1; 
void push(char elem){ s[++top] = elem; }
char pop(){ return(s[top--]); }

int pr(char elem) { 
  switch (elem) {
    case '#':return 0;
    case '(':return 1;
    case '+':
    case '-':return 2;
    case '*':
    case '/':return 3;
  }
}

int main() { 
char in[50], po[50]; int i = 0, j = 0;     
printf("Enter Infix expression: "); scanf("%s", in); push('#');
while(in[i++] != '\0'){
  if (in[i] == '(') push(in[i]);
  else if(isalnum(in[i])) po[j++] = in[i];
  else if(in[i] == ')'){ while(s[top] != '(') po[j++] = pop(); } 
  else { 
   while(pr(s[top]) >= pr(in[i])) po[j++] = pop();
   push(in[i]);
  }
 }
 while (s[top] != '#')po[j++] = pop();
 po[j] = '\0'; printf("Postfix expression: %s\n",po);
 return 0;
}
