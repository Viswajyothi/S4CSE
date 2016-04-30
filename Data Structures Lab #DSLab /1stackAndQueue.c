#include <stdio.h>
int choice, item, i, stack[50], queue[50], size, top=-1, front=-1, rear=-1;
void mainMenu(); void stackMenu(); void displayStack();
void queueMenu(); void displayQueue();

void mainMenu(){
	printf("\n\tMAIN MENU\n1.Stack  2.Queue  3.Exit\n");
	printf("Enter your choice: "); scanf("%d", &choice);
	switch(choice){
		case 1: stackMenu(); break;
		case 2: queueMenu(); break;
		case 3: break;
		default: printf("\t!!!INVALID CHOICE!!!\n"); mainMenu(); break;
	}
}

void stackMenu(){
	printf("\n\n\tSTACK MENU\n1.Push  2.Pop  3.Display 4.Exit to Main Menu");
	printf("\nEnter your choice: "); scanf("%d", &choice);
	switch(choice){
		case 1: 
			if(top>=size-1) printf("\nStack Overflow!\n");
			else{
				printf("\nEnter the item: ");scanf("%d", &item);stack[++top]=item;
			}
			displayStack(); break;
		case 2: 
			if(top!=-1)top--;
			displayStack(); break;
		case 3: displayStack(); break;
		case 4: mainMenu(); break;
		default: printf("\t!!!INVALID CHOICE!!!\n"); stackMenu(); break;
	}
}

void displayStack(){
	printf("\nThe current Stack is: ");
	if(top==-1) printf("Empty!\n");
	else for(i=0; i<=top; i++) printf("%d  ", stack[i]);
	stackMenu();
}

void queueMenu(){
	printf("\n\n\tQUEUE MENU\n1.Enqueue  2.Dequeue  3.Display 4.Exit to Main Menu");
	printf("\nEnter your choice: "); scanf("%d", &choice);
	switch(choice){
		case 1: 
			if(rear==size-1) printf("\nQUEUE FULL!\n");
			else{
				printf("\nEnter the item: "); scanf("%d", &item);
				if(front==-1 && rear==-1) front=0;
				queue[++rear]=item;
			}
			displayQueue(); break;
		case 2: 
			if(front!=-1 && rear!=-1)
				if(front==rear)front=rear=-1;
				else front++;
			displayQueue(); break;
		case 3: displayQueue(); break;
		case 4: mainMenu(); break;
		default: printf("\t!!!INVALID CHOICE!!!\n"); queueMenu(); break;
	}
}

void displayQueue(){
	printf("\nThe current Queue is: ");
	if(rear==-1) printf("Empty\n");
	else for(i=front; i<=rear; i++) printf("%d ", queue[i]);
	queueMenu();
}

int main(){ 
	printf("\nEnter the size of the Array: \n"); scanf("%d", &size);
	mainMenu(); return 0;
}
