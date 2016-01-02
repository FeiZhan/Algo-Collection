//@result TLE

class Solution {
public:
    class Compare
    {
    public:
        bool operator() (pair<int,size_t> n1, pair<int,size_t> n2) {
            return n1.first > n2.first;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<pair<int, size_t>, vector<pair<int, size_t> >, Compare> ugly_list;
        ugly_list.push(make_pair(1, primes.size() - 1));
        int prev = 0;
        while (n > 0) {
            pair<int, size_t> current = ugly_list.top();
            //cout << "debug " << n << " " << current.first << " " << current.second << endl;
            ugly_list.pop();
            if (prev != current.first) {
                -- n;
            }
            prev = current.first;
            ugly_list.push(make_pair(current.first * primes[0], 0));
            if (current.second + 1 < primes.size()) {
                ugly_list.push(make_pair(current.first / primes[current.second] * primes[current.second + 1], current.second + 1));
            }
        }
        return prev;
    }
};
