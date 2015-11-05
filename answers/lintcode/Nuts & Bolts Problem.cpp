//@result TLE, correct in ideone

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Comparator {
public:
    int cmp(string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a > b ? 1 : (a < b ? -1 : 0);
    }
};
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        sortNutsAndBolts(0, nuts.size() - 1, nuts, bolts, compare);
    }
    void sortNutsAndBolts(size_t begin, size_t end, vector<string> &nuts, vector<string> &bolts, Comparator &compare) {
        if (begin >= end || end >= nuts.size()) {
            return;
        }
        size_t pivot = begin;
        size_t left = begin + 1;
        size_t right = end;
        while (left < right && right <= end) {
            if (1 == compare.cmp(nuts[left], bolts[pivot]) && compare.cmp(nuts[right], bolts[pivot]) <= 0) {
                string temp = nuts[left];
                nuts[left] = nuts[right];
                nuts[right] = temp;
            }
            if (compare.cmp(nuts[left], bolts[pivot]) <= 0) {
                ++ left;
            }
            if (1 == compare.cmp(nuts[right], bolts[pivot])) {
                -- right;
            }
        }
        pivot = left - 1;
        left = begin;
        right = end;
        while (left < right && right <= end) {
            if (1 == compare.cmp(bolts[left], nuts[pivot]) && compare.cmp(bolts[right], nuts[pivot]) <= 0) {
                string temp = bolts[left];
                bolts[left] = bolts[right];
                bolts[right] = temp;
            }
            if (compare.cmp(bolts[left], nuts[pivot]) <= 0) {
                ++ left;
            }
            if (1 == compare.cmp(bolts[right], nuts[pivot])) {
                -- right;
            }
        }
        sortNutsAndBolts(begin, left - 1, nuts, bolts, compare);
        sortNutsAndBolts(left, end, nuts, bolts, compare);
    }
};


int main() {
    // your code goes here
    Solution s;
    vector<string> nuts;
    //["ab","bc","dd","gg"]
    nuts.push_back("ab");
    nuts.push_back("bc");
    nuts.push_back("dd");
    nuts.push_back("gg");
    vector<string> bolts;
    //["AB","GG","DD","BC"]
    bolts.push_back("AB");
    bolts.push_back("GG");
    bolts.push_back("DD");
    bolts.push_back("BC");
    Comparator compare;
    s.sortNutsAndBolts(nuts, bolts, compare);
    for (size_t i = 0; i < nuts.size(); ++ i) {
        cout << nuts[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < bolts.size(); ++ i) {
        cout << bolts[i] << " ";
    }
    cout << endl;
    return 0;
}