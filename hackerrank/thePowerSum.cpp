#include <iostream>
#include <cmath>
using namespace std;

int powerSum(int x, int n, int sum, int currentNum) {
    int newSum = sum + pow(currentNum, n);
    
    if (newSum > x) return 0;
    else if (newSum == x) return 1;
    else return powerSum(x, n, sum, currentNum + 1) + powerSum(x, n, newSum, currentNum + 1);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << powerSum(x, n, 0, 1) << endl;
    return 0;
}