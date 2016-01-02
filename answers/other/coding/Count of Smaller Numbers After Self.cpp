class Solution {
public:
    struct Node {
        int value;
        int index;
        int count;
        Node (int v, int i) : value(v), index(i), count(0) {}
        bool operator <= (const Node &n) const {
            return value <= n.value;
        }
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<Node> node_list;
        for (size_t i = 0; i < nums.size(); ++ i) {
            node_list.push_back(Node(nums[i], i));
        }
        vector<Node> temp(nums.size(), Node(0, 0));
        mergeSort(node_list, 0, nums.size() - 1, temp);
        vector<int> answer(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); ++ i) {
            answer[node_list[i].index] = node_list[i].count;
        }
        return answer;
    }
    void mergeSort(vector<Node> &nums, size_t begin, size_t end, vector<Node> &temp) {
        if (begin < end && end < nums.size()) {
            size_t middle = (begin + end) / 2;
            mergeSort(nums, begin, middle, temp);
            mergeSort(nums, middle + 1, end, temp);
            combine(nums, begin, middle, end, temp);
        }
    }
    void combine(vector<Node> &nums, size_t begin, size_t middle, size_t end, vector<Node> &temp) {
        size_t left = begin;
        size_t right = middle + 1;
        size_t size = end - begin + 1;
        size_t t = begin;
        while (left <= middle && right <= end) {
            if (nums[left] <= nums[right]) {
                temp[t] = nums[left];
                temp[t].count += right - middle - 1;
                ++ left;
            }
            else {
                temp[t] = nums[right];
                ++ right;
            }
            ++ t;
        }
        while (left <= middle) {
            temp[t] = nums[left];
            temp[t].count += right - middle - 1;
            ++ left;
            ++ t;
        }
        while (right <= end) {
            temp[t] = nums[right];
            ++ right;
            ++ t;
        }
        for (size_t i = 0; i < size; ++ i) {
            nums[end - i] = temp[end - i];
        }
    }
};