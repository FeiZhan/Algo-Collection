#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_num = 0;
    cin >> num_num;
    vector<int> nums;
    unordered_set<int> num_set;
    for (size_t i = 0; i < num_num; ++ i) {
        int num = 0;
        cin >> num;
        nums.push_back(num);
        // find if the number occurred before
        if (num_set.end() == num_set.find(num)) {
            num_set.insert(num);
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
    cout << endl;
    num_set.clear();
    vector<bool> after_list;
    for (size_t i = nums.size() - 1; i < nums.size(); -- i) {
        // find if the number occurred after
        if (num_set.end() == num_set.find(nums[i])) {
            num_set.insert(nums[i]);
            after_list.push_back(false);
        }
        else {
            after_list.push_back(true);
        }
    }
    // output in reverse order
    for (size_t i = after_list.size() - 1; i < after_list.size(); -- i) {
        cout << after_list[i];
    }
    cout << endl;
    return 0;
}
// time complexity: O(n)
// space complexity: O(n)


/*
 * Complete the function below.
 */
vector < int > DistinctRegions(vector < int > nvalues) {
    vector<int> answers;
    for (size_t i = 0; i < nvalues.size(); ++ i) {
        // sum up from zero to number. don't forget the initial region (+1). set it as int64
        long long answer = (long long)(0 + nvalues[i]) * (nvalues[i] + 1) / 2 + 1;
        answers.push_back(answer % 1000000000);
    }
    return answers;
}
// for each number
// time complexity: O(1)
// space complexity: O(1)
