#include <iostream>
#include <vector>
using namespace std;

//Maximum sum for a 1-demensional array
//Accepts: input - the array of numbers
//         n - the size of input
//         max - what is your current max (only relevant for 2d arrays)
int kadane(int input[], int n, int max = -100000000)
{
   	int cur, i;
   	cur = max = 0;
   	for(int i = 0; i<n; i++)
   	{
       		cur = cur+input[i];
       		if(cur > max)
       		{
           		max = cur;
       		}
       		if (cur < 0)
       		{
           		cur = 0;
       		}
	}

	return max;
}

int main()
{
	int n,i,j,k;
	vector<vector<int> > array;
	while(cin >> n)
	{
		for(i = 0; i<n; i++)
		{
			vector<int> temp_vector;
			for(j = 0; j<n; j++) 
			{
				int temp;
				cin >> temp;
				temp_vector.push_back(temp);
			}
			array.push_back(temp_vector);
		} 
		
		//Algorithm adapted from http://tech-queries.blogspot.com/2010/05/find-max-sum-in-2d-array.html
		int temporary_array[100], current_max, maximum_sum;
   		maximum_sum = current_max = -128;

   		for (i=0; i<n; i++)
   		{
       			for(k=0; k<n; k++)
           			temporary_array[k] = 0;

       			for (j=i; j<n; j++)
       			{
				for(k=0; k<n; k++)
               				temporary_array[k] += array[j][k];
           			current_max = kadane(temporary_array, n, current_max);

           			if (current_max > maximum_sum)
           				maximum_sum = current_max;
       			}
   		}
		cout << maximum_sum << endl;
	}
	return 0;
}
