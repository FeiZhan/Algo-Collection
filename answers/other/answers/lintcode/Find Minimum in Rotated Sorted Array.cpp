class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        size_t left = 0;
        size_t right = num.size() - 1;
        int min_num = num[0];
        while (left <= right && right < num.size()) {
            size_t middle = (left + right) / 2;
            if (num[left] < num[middle]) {
                min_num = min(min_num, num[left]);
                left = middle + 1;
            }
            else if (num[left] > num[middle]) {
                min_num = min(min_num, num[middle]);
                right = middle - 1;
            }
            else {
                ++ left;
            }
            //cout << "test " << middle << " " << min_num << endl;
        }
        min_num = min(min_num, min((left < num.size() ? num[left] : INT_MAX), (right < num.size() ? num[right] : INT_MAX)));
        return min_num;
    }
};
