#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ids(n);
    map<int, int> d;
    vector<int> l1;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> ids[i];
    }

    for (const string& id : ids) {
        size_t colonPos = id.find(':');
        try {
            int id_ = stoi(id.substr(0, colonPos));
            int ra = stoi(id.substr(colonPos + 1));
            d[id_] = ra;
            l1.push_back(id_);
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
            // Handle the error as needed
            return 1;  // Exit with an error code
        }
    }

    sort(l1.begin(), l1.end(), [&](int a, int b) {
        return d[a] > d[b];
    });

    int res = d[l1[0]];
    vector<int> k;
    int j = distance(l1.begin(), find(l1.begin(), l1.end(), l1[0])) - 1;
    k.push_back(l1[0]);

    while (j >= 0 && d[l1[j]] < 0) {
        k.push_back(l1[j]);
        j--;
    }

    if (*max_element(k.begin(), k.end()) == l1[0]) {
        res = 1;
    } else {
        res = 0;
    }

    int x = k.size();
    l1.erase(remove(l1.begin(), l1.end(), l1[0]), l1.end());

    for (int i : l1) {
        k.clear();
        j = distance(l1.begin(), find(l1.begin(), l1.end(), i));
        k.push_back(i);

        while (j >= 0 && d[l1[j]] < 0) {
            k.push_back(l1[j]);
            j--;
        }

        x += k.size();

        if (x >= l1.size()) {
            break;
        }

        if (res == 1) {
            res += d[*max_element(k.begin(), k.end())];
        } else {
            res += d[*min_element(k.begin(), k.end())];
        }
    }

    cout << res << endl;

    return 0;
}
