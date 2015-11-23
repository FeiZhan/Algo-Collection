#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int list_size = 0;
    while (cin >> list_size) {
        multimap<int, string> text_map;
        for (int i = 0; i < list_size; ++ i) {
            int num = 0;
            string text;
            cin >> num >> text;
            if (i < list_size / 2) {
                text = "-";
            }
            text_map.insert(make_pair(num, text));
        }
        string output;
        for (multimap<int, string>::iterator it = text_map.begin(); it != text_map.end(); ++ it) {
            output += it->second + string(" ");
        }
        if (output.length() > 0 && output.back() == ' ') {
            output.erase(output.length() - 1);
        }
        cout << output << endl;
    }
    return 0;
}
