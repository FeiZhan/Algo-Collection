//@result 16 / 16 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.58% of cpp submissions.

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int gas_sum = 0;
		int cost_sum = 0;
		for (size_t i = 0; i < gas.size() && i < cost.size(); ++ i) {
			gas_sum += gas[i];
			cost_sum += cost[i];
		}
		if (gas_sum < cost_sum) {
			return -1;
		}
		int remain_gas = 0;
		int start = 0;
		for (size_t i = 0; i < gas.size() && i < cost.size(); ++ i) {
			remain_gas += gas[i] - cost[i];
			if (remain_gas < 0) {
				start = i + 1;
				remain_gas = 0;
			}
		}
		return start;
	}
};
