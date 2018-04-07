#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* Given an int array, find the maximum sum of adjacent numbers. */
int LargestAdjacentSum (vector<int> array)
{
	int localMax = array[0];
	int totalMax = array[0];

	for (int i = 1; i < array.size(); i++)
	{
		localMax = max(localMax +  array[i], array[i]);
		totalMax = max(localMax, totalMax);
	}
	return totalMax;
}

int main(void)
{
	vector<int> array = {-1, 3, -1, 5};		// test 1, output: 7
//	vector<int> array = {-5, -3, -1}; 		// test 2, output: -1		
//	vector<int> array = {2, 4, -2, -3, 8};	// test 3, output: 9

	cout << LargestAdjacentSum(array) << endl;
	return 0;
}
