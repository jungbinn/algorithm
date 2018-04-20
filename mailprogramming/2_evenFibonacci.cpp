/* 피보나치 배열은 0과 1로 시작하며, 다음 피보나치 수는 바로 앞의 두 
   피보나치 수의 합이 된다. 정수 N이 주어지면, N보다 작은 모든 짝수
   피보나치 수의 합을 구하여라. */

#include <iostream>

using namespace std;

int fibonacci (int a, int b, int n, int sum)
{
	if (b > n)
		return sum;

	if (b % 2 == 0)
		sum += b;

	return fibonacci (b, a + b, n, sum);
}

int main ()
{
	int N;
	cin >> N;
	cout << fibonacci (0, 1, N, 0);
	return 0;
}
