/* 정수(int)가 주어지면, 팰린드롬(palindrome)인지 알아내시오.
   팰린드롬이란, 앞에서부터 읽으나 뒤에서부터 읽으나 같은 단어를
   말합니다. 단, 정수를 문자열로 바꾸면 안됩니다. */

#include <iostream>
#include <vector>

using namespace std;

bool palindrome (int n)
{
	if (n < 0)  return false;

	/* Split given number into digits. */
	vector<int> digits;
	while (n > 0)
	{
		int digit = n % 10;
		n /= 10;
		digits.push_back(digit);
	}

	/* Compare each digits. */
	int size = digits.size();
	for (int i = 0; i < size / 2; i++)
	{	
		int front = digits[i];
		int back = digits[size - 1 - i];
		if (front != back)
			return false;
	}
	return true;
}

int main ()
{
	int n;
	cin >> n;
	
	bool isPalindrome = palindrome (n);
	if (isPalindrome)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}
