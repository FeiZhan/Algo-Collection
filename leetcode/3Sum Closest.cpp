class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int closest_diff = INT_MAX;
        std::multimap<int, size_t> num_map;
        for (size_t i = 0; i < num.size(); ++ i) {
            num_map.insert(std::make_pair(num[i], 1));
        }
        for (std::multimap<int, size_t>::iterator it = num_map.begin(); it != num_map.end(); ++ it) {
            std::multimap<int, size_t>::iterator it1 = num_map.begin();
            std::multimap<int, size_t>::iterator it2 = num_map.end();
                    if (it1 == it) {
                        ++ it1;
                    }
            -- it2;
                    if (it2 == it) {
                        -- it2;
                    }
            while (it1 != num_map.end() && it2 != num_map.end() && it1 != it2) {
                int diff = it->first + it1->first + it2->first - target;
                //@note abs
                closest_diff = std::abs(closest_diff) > std::abs(diff) ? diff : closest_diff;
                if (diff > 0) {
                    -- it2;
                    if (it2 == it) {
                        -- it2;
                    }
                } else {
                    ++ it1;
                    if (it1 == it) {
                        ++ it1;
                    }
                }
            }
        }
        return target + closest_diff;
    }
};
