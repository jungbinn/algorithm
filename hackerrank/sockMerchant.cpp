#include <iostream>
#include <vector>
#include <set>
using namespace std;

int matchSocks(vector<int> socks) {
    int count = 0;
    set<int> socksSet;
    for (int i = 0; i < socks.size(); i++) {
        if (socksSet.find(socks[i]) == socksSet.end()) {
            socksSet.insert(socks[i]);
        } else {
            socksSet.erase(socks[i]);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> socks;
    for (int i = 0; i < n; i++) {
        int sock;
        cin >> sock;
        socks.push_back(sock);
    }

    cout << matchSocks(socks) << endl;
    return 0;
}