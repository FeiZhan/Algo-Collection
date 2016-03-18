//@result TLE

#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int first_num = 0;
    cin >> first_num;
    vector<int> first_list;
    for (int i = 0; i < first_num; ++ i) {
    	int num = 0;
    	cin >> num;
    	first_list.push_back(num);
    }
    sort(first_list.begin(), first_list.end());
    int second_num = 0;
    cin >> second_num;
    vector<int> second_list;
    for (int i = 0; i < second_num; ++ i) {
    	int num = 0;
    	cin >> num;
    	second_list.push_back(num);
    }
    sort(second_list.begin(), second_list.end());
    set<int> missing_list;
    for (size_t i = 0, j = 0; i < first_list.size() || j < second_list.size(); ++ i, ++ j) {
    	if (j >= second_list.size() || first_list[i] < second_list[j]) {
    		missing_list.insert(first_list[i]);
    		-- j;
    	}
    	if (i >= first_list.size() || first_list[i] > second_list[j]) {
    		missing_list.insert(second_list[j]);
    		-- i;
    	}
    }
    for (set<int>::iterator it = missing_list.begin(); it != missing_list.end(); ++ it) {
    	cout << (missing_list.begin() == it ? "" : " ") << *it;
    }
    cout << endl;
    return 0;
}
