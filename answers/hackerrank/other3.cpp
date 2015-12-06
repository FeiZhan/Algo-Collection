#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long quantile = 0;
    long long pair_num = 0;
    cin >> quantile >> pair_num;
    // a map with <value, count>
    map<long long, long long> num_map;
    for (long long i = 0; i < pair_num; ++ i) {
        long long value = 0;
        long long count = 0;
        cin >> value >> count;
        num_map[value] += count;
    }
    // convert to a map with <all count, value>
    map<long long, long long> count_map;
    long long all_count = 0;
    for (map<long long, long long>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
        // accumulate counts
        all_count += it->second;
        count_map.insert(make_pair(all_count, it->first));
    }
    for (long long i = 1; i < quantile; ++ i) {
        long long ceiling = ceil(double(all_count) * i / quantile);
        // find the value with target count
        map<long long, long long>::iterator lower = count_map.lower_bound(ceiling);
        if (count_map.end() != lower) {
            cout << lower->second << endl;
        }
    }
    return 0;
}
// time complexity: O(N logN)
// space complexity: O(N)
