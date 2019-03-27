#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &clouds, int index, int count) {
    if (index == clouds.size() - 1) return count;
    if (index == clouds.size() - 2) return count + 1;

    int minimum = 100;
    if (clouds[index + 1] == 0)
        minimum = min(minimum, jump(clouds, index + 1, count + 1));
    if (clouds[index + 2] == 0)
        minimum = min(minimum, jump(clouds, index + 2, count + 1));
    return minimum;
}

int main() {
    int n;
    cin >> n;

    vector<int> clouds;
    for (int i = 0; i < n; i++) {
        int cloud;
        cin >> cloud;
        clouds.push_back(cloud);
    }

    cout << jump(clouds, 0, 0) << endl;
    return 0;
}