#include <iostream>
using namespace std;


void FindTriplet (int arr[], int size, int x)
{

  int sum = 0;

  int i, j, k;

  for (i = 0; i < size - 2; i++)

    {

      for (j = i + 1; j < size - 1; j++)

	{

	  for (k = j + 1; k < size; k++)

	    {

	      sum = arr[i] + arr[j] + arr[k];

	      if (sum == x)
		{
		  int a, b, c;

		  a = arr[i];

		  b = arr[j];

		  c = arr[k];

		  if (a > b)
		    {

		      int tmp = a;

		      a = b;

		      b = tmp;

		    }

		  if (a > c)
		    {

		      int tmp = a;

		      a = c;

		      c = tmp;

		    }

		  if (b > c)
		    {

		      int tmp = b;

		      b = c;

		      c = tmp;

		    }

		  cout << a << " " << b << " " << c << endl;


		}

	    }
	}
    }
}



int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}

