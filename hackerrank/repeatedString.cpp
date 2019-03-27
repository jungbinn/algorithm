#include <iostream>
#include <string>
using namespace std;

long long countA(string s, long long n) {
    int aCount = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') aCount++;
    }

    long long count = n / s.length() * aCount;
    for (int i = 0; i < n % s.length(); i++) {
        if (s[i] == 'a') count++;
    }
    return count;
}

int main() {
    string s;
    cin >> s;

    long long n;
    cin >> n;

    cout << countA(s, n) << endl;
    return 0;
}