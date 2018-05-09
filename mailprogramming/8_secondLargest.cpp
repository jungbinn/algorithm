/* 정수 배열(int array)이 주어지면 두 번째로 큰 값을 프린트하시오. */

#include <vector>
#include <climits>

using namespace std;

void secondLargest (vector<int> numbers)
{
	int first = INT_MIN;
	int second = INT_MIN;

	/* Corner case 1. */
	if (numbers.size() < 2) {
		cout << "두 번째로 큰 값은 없습니다." << endl;
		return;
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] > first) {
			second = first;
			first = numbers[i];
		}
		else if (second < numbers[i] && numbers[i] < first)
			second = numbers[i];
	}

	/* Corner case 2. */
	if (second == INT_MIN) {
		cout << "두 번째로 큰 값은 없습니다." << endl;
		return;
	}

	cout << second << endl;
}
