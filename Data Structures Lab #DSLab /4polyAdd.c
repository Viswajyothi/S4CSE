#include <stdio.h>
int i, j, k, n1, n2;
struct polynomial{int e, c;}a[50], b[50], c[50];
void display(struct polynomial arr[], int n){
	for(i=0; i<n; i++)
		if(arr[i].c!=0)
			if(arr[i].c==1){
				if(arr[i].e==0)printf((i==n-1)?"1\n":"1 + ");
				else if(arr[i].e==1)printf((i==n-1)?"x\n":"x + ");
				else printf((i==n-1)?"x^%d\n":"x^%d + ", arr[i].e);
			}
			else{
				if(arr[i].e==0)printf((i==n-1)?"%d\n":"%d +", arr[i].c);
				else if(arr[i].e==1)printf((i==n-1)?"%dx\n":"%dx + ", arr[i].c);
				else printf((i==n-1)?"%dx^%d\n":"%dx^%d + ", arr[i].c, arr[i].e);
			}
}

int main(){
	printf("\nEnter the number of terms in the 1st & 2nd polynomial: ");
	scanf("%d %d", &n1, &n2);
	printf("\nEnter the coefficients of the 1st polynomial: ");
	for(i=0; i<n1; i++) scanf("%d", &a[i].c);
	printf("Enter the exponents of the 1st polynomial: ");
	for(i=0; i<n1; i++) scanf("%d", &a[i].e);
	printf("The 1st polynomial is: ");display(a, n1);

	printf("\nEnter the coefficients of the 2nd polynomial: ");
	for(j=0; j<n2; j++) scanf("%d", &b[j].c);
	printf("Enter the exponents of the 2nd polynomial: ");
	for(j=0; j<n2; j++) scanf("%d", &b[j].e);
	printf("The 2nd polynomial is: ");display(b, n2);

	i=0; j=0; k=0;
	while(i<n1 && j<n2){
		if(a[i].e==b[j].e){ c[k].e=a[i].e; c[k++].c = a[i++].c+b[j++].c; }
		else if(a[i].e>b[j].e){ c[k].e=a[i].e; c[k++].c=a[i++].c; }
		else{ c[k].e=b[j].e; c[k++].c=b[j++].c; }
	}
	while(i<n1){ c[k].e=a[i].e; c[k++].c=a[i++].c; }
	while(j<n2){ c[k].e=b[j].e; c[k++].c=b[j++].c; }
	printf("\nThe resultant polynomial is: ");display(c,k);
	return 0;
}