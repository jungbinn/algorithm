/* String이 주어지면, 중복된 char가 없는 가장 긴 substring의 길이를 찾으시오. */

#include <string>
#include <set>
#include <algorithm>

using namespace std;

int nonDupSubstr (string s)
{
	int count = 0;

	for (int i = 0; i < s.length(); i++) {
		set<char> letters;
		int c = 0;
		for (int j = 0; j < s.length() - i; j++) {
			if (letters.find (s[i+j]) != letters.end()) {
				count = max (count, c);
				break;
			}
			letters.insert (s[i+j]);
			c++;
		}
	}
	return count;
}
