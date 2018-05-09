/* 정수 배열(int array)이 주어지면 두 번째로 큰 값을 프린트하시오. */

#include <vector>
#include <algorithm>

using namespace std;

void swap (int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int secondLargest (vector<int> numbers)
{
	int first = 0;
	int second = 0;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] > second) {
			second = numbers[i];
			if (second > first) 
				swap (&first, &second);
		}
	}
	return second;
}
