/* 정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의
   인덱스를 찾으시오.
   단, 시간복잡도 O(n)이어야 합니다. */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

tuple<int, int> sumIndex (vector<int> arr, int n)
{
	unordered_map<int, int> map;
	tuple<int, int> answer = make_tuple (-1, -1);
		
	for (int i = 0; i < arr.size(); i++)
	{
		int remain = n - arr[i];
		auto search = map.find (remain);  // O(1) time complexity
		if (search != map.end())
		{
			answer = make_tuple (search->second, i);
			return answer;
		}
		map.insert ({arr[i], i});
	}

	return answer;  // no such combination
}

int main ()
{
	/* example 1, answer = [0, 2] */
	vector<int> arr = {2, 5, 6, 1, 10};
	int target = 8;

//	/* example 2, answer = [1, 5] */
//	vector<int> arr = {5, 7, 11, 4, 8, 13};
//	int target = 20;

//	/* example 3, answer = [0, 2] */
//	vector<int> arr = {-2, 6, 7, -3};
//	int target = 5;

	tuple<int, int> answer = sumIndex (arr, target);
	cout << "[" << get<0>(answer) << ", " << get<1>(answer) << "]" << endl;
	return 0;
}
