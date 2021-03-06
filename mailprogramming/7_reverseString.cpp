#include <string>
#include <algorithm>

using namespace std;

string reverseString (string s)
{
	string reversed = "";

	/* Parse, split and reverse the string. */
	int start = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			string sub = s.substr(start, i - start);
			reverse (sub.begin(), sub.end());
			reversed += sub + " ";
			start = i + 1;
		}
		else if (i == s.length() - 1) {
			string sub = s.substr(start, i - start + 1);
			reverse (sub.begin(), sub.end());
			reversed += sub;
		}
	}
	return reversed;
}
