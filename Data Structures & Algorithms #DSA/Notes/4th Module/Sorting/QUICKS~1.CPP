#include<iostream.h>
#include<conio.h>
#include<time.h>
void quicksort(int data[],int left,int right)
{
int mid,temp,i,j;
i=left;
j=right;
mid=data[(left+right)/2];
do
{
while(data[i]<mid)
i++;
while(mid<data[j])
j--;
if(i<=j)
{
temp=data[i];
data[i]=data[j];
data[j]=temp;
i++;
j--;
}
}while(i<=j);
if(left<j)
quicksort(data,left,j);
if(i<right)
quicksort(data,i,right);
}
void main()
{
time_t t1,t2,t3;
int data[10000],n,i;
clrscr();
cout<<"\nHow many data:";
cin>>n;
cout<<"\nEnter Data:";
for(i=n;i>0;i--)
data[i]=i;
time(&t1);
quicksort(data,0,n);
time(&t2);

cout<<"\nThe sorted data is\n";
for(i=0;i<n;i++)
cout<<" "<<data[i];
cout<<endl;
cout<<"THE EXECUTION TIME TAKEN IS :"<<t2-t1<<" SECONDS";
getch();
}


