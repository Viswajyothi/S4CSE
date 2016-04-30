#include <stdio.h>
int i, choice, item, size, cq[50], front=-1, rear=-1;
void mainMenu(); void display();
void mainMenu(){
	printf("\n\n\tCIRCULAR QUEUE\n1.Enqueue  2.Dequeue  3.Display");
	printf("  4.Exit\nEnter your choice: "); scanf("%d", &choice);
	switch(choice){
		case 1: 
			if(front==(rear+1)%size) printf("\nThe Circular Queue is Full!\n");
			else {
				printf("\nEnter the item: "); scanf("%d", &item);
				rear=(rear+1)%size; cq[rear]=item;
				if(front==-1)front=0;
			}
			display(); break;
		case 2: 
			if(front!=-1 && rear!=-1){
				if(front==rear)front=rear=-1;
				else front = (front+1)%size;
			}
			display(); break;
		case 3: display(); break;
		case 4: break;
		default: printf("\n!!INVALID CHOICE!!\n"); mainMenu();
	}
}

void display(){
	printf("\nThe current Circular Queue is: ");
	if(front==-1 && rear==-1) printf("Empty\n");
	else if(front<=rear) for(int i=front; i<=rear; i++) printf("%d  ", cq[i]);
	else {
		for(i=front; i<=size-1; i++) printf("%d  ", cq[i]);
		for(int i=0; i <=rear; ++i) printf("%d  ", cq[i]);
	}
	mainMenu();
}

int main(){
	printf("Enter the size: "); scanf("%d", &size);
	mainMenu();	return 0;
}
