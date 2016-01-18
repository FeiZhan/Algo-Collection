//@result 102 / 102 test cases passed. Status: Accepted Runtime: 260 ms Submitted: 0 minutes ago You are here! Your runtime beats 29.46% of cpp submissions.

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> max_num;
        // note boundary
        for (size_t i = 0; i <= nums1.size() && i <= k; ++ i) {
            vector<int> sub1 = maxSub(nums1, i);
            vector<int> sub2 = maxSub(nums2, k - i);
            if (sub1.size() + sub2.size() < k) {
                continue;
            }
            vector<int> temp;
            size_t j = 0;
            size_t k = 0;
            int flag = 0;
            while (j < sub1.size() || k < sub2.size()) {
                // if equal
                if (j < sub1.size() && k < sub2.size() && sub1[j] == sub2[k]) {
                    size_t m = j;
                    size_t n = k;
                    while (m < sub1.size() && n < sub2.size() && sub1[m] == sub2[n]) {
                        ++ m;
                        ++ n;
                    }
                    if (n >= sub2.size() || (m < sub1.size() && sub1[m] > sub2[n])) {
                        temp.push_back(sub1[j]);
                        ++ j;
                    }
                    else {
                        temp.push_back(sub2[k]);
                        ++ k;
                    }
                }
                else if (k >= sub2.size() || (j < sub1.size() && sub1[j] > sub2[k])) {
                    temp.push_back(sub1[j]);
                    ++ j;
                }
                else {
                    temp.push_back(sub2[k]);
                    ++ k;
                }
                // compare result
                if (0 == flag) {
                    if (max_num.size() < temp.size()) {
                        flag = 1;
                    }
                    else if (max_num[temp.size() - 1] < temp.back()) {
                        flag = 1;
                    }
                    else if (max_num[temp.size() - 1] > temp.back()) {
                        flag = -1;
                        break;
                    }
                }
            }
            if (1 == flag) {
                max_num = temp;
            }
        }
        return max_num;
    }
    vector<int> maxSub(const vector<int> nums, int size) {
        vector<int> sub;
        if (0 == size || size > nums.size()) {
            return sub;
        }
        for (size_t i = 0; i < nums.size(); ++ i) {
            // note size
            while (sub.size() && sub.back() < nums[i] && sub.size() + nums.size() - i > size) {
                sub.pop_back();
            }
            sub.push_back(nums[i]);
        }
        while (sub.size() > size) {
            sub.pop_back();
        }
        return sub;
    }
};
