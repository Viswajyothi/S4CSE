// Program: ch09pr04
// Program using Bubble sort

#include <iostream.h>
#include<conio.h>
#include<time.h>
const int MAX = 10000 ;

class array
{
	private :

		int arr[MAX] ;
		int count ;

	public :
		array( ) ;
		void add ( int item ) ;
		void sort( ) ;
		void display( ) ;
} ;

// initialises data member
array :: array( )
{
	count = 0 ;
//    for ( int i = 0 ; i < MAX ; i++ )
  //  	arr[i] = 0 ;
}

// adds a new element to the array
void array :: add ( int item )
{
	if ( count < MAX )
	{
		arr[count] = item ;
		count++ ;
	}
	else
		cout << "\nArray is full" << endl ;
}

void array :: sort( )
{
	int temp ;
	for ( int i = 0 ; i <= count - 2 ; i++ )
	{
		for ( int j = 0 ; j <= count - 2 - i ; j++ )
		{
			if ( arr[j] > arr[j + 1] )
			{
				temp = arr[j] ;
				arr[j] = arr[j + 1] ;
				arr[j + 1] = temp ;
			}
		}
	}
}

void array :: display( )
{
	for ( int i = 0 ; i < count ; i++ )
		cout << arr[i] << "  " ;
    cout << endl ;
}

void main( )
{
	array a ;
	int n,i;
	float f;
time_t t1,t2,t3;
	clrscr();
	cout<<"\nEnter value for n:";
	cin>>n;
	for(i=n;i>0;i--)
	a.add ( i ) ;

	cout << "\nBubble sort.\n" ;
      //	cout << "\nArray before sorting:" << endl ;
    //	a.display( ) ;


time(&t1);
	a.sort( ) ;
	time(&t2);
	f=t2-t1;
	t3=t2-t1;//check for function name

	cout << "\nArray after bubble sorting:" << endl ;
	a.display( ) ;
	cout<<endl;
		cout<<"THE EXECUTION TIME TAKEN IS:"<<t2-t1<<" SECONDS";
	getch();
}
