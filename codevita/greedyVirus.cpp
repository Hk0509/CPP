#include <bits/stdc++.h>
using namespace std;

double max_efficiency(const string& numbers) {
    istringstream iss(numbers);
    vector<int> nums;

    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    int n = nums.size();
    double max_efficiency = numeric_limits<double>::lowest();
    double product = 1.0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        product *= nums[right];

        while (product < 0) {
            product /= nums[left];
            ++left;
        }

        max_efficiency = max(max_efficiency, product);
    }

    return max_efficiency;
}

int main() {
    string numbers;
    getline(cin, numbers);

    double result = max_efficiency(numbers);

    result = max(0.0, result);

    cout << result << endl;

    return 0;
}
