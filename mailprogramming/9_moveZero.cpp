/* 정수 배열(int array)이 주어지면 0이 아닌 정수 순서를 유지하며 모든 0을
   배열 오른쪽 끝으로 옮기시오.
   단, 시간복잡도는 O(n), 공간복잡도는 O(1)이어야 합니다. */

#include <vector>

using namespace std;

vector<int> moveZero (vector<int> vec)
{
	/* First, get the number of zeros. */
	int count = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0)
			count ++;
	}

	/* Then, move nonzero numbers. */
	int cur = 0;
	for (int i = 0; cur < vec.size() - count; i++) {
		if (vec[i] == 0)
			continue;
		vec[cur] = vec[i];
		cur++;
	}

	/* Finally, append zeros at the back. */
	for (int i = vec.size()-count; i < vec.size(); i++)
		vec[i] = 0;

	return vec;
}
