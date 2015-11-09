#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        for (size_t i = 0; i < k && i < colors.size(); ++ i) {
            if (colors[i] <= 0) {
                continue;
            }
            int current = colors[i];
            colors[i] = 0;
            while (current > 0) {
                int temp = colors[current - 1];
                if (colors[current - 1] > 0) {
                    colors[current - 1] = 0;
                }
                -- colors[current - 1];
                current = temp;
            }
        }
        for (size_t i = k; i < colors.size(); ++ i) {
            -- colors[colors[i] - 1];
        }
        size_t pos = colors.size() - 1;
        for (size_t i = k - 1; i < k && i < colors.size(); -- i) {
            //cout << "debug " << i + 1 << " " << colors[i] << endl;
            for (int j = colors[i]; j < 0; ++ j) {
                colors[pos] = i + 1;
                -- pos;
            }
        }
    }
};

int main() {
	// your code goes here
    Solution s;
    std::vector<int> colors;
    //[2,1,1,2,2], 2
    colors.push_back(2);
    colors.push_back(1);
    colors.push_back(1);
    colors.push_back(2);
    colors.push_back(2);
    s.sortColors2(colors, 2);
	return 0;
}
