class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<size_t> split;
        set<string> addresses;
        restoreIpAddresses(0, split, s, addresses);
        return vector<string> (addresses.begin(), addresses.end());
    }
    void restoreIpAddresses(size_t begin, vector<size_t> &split, const string &s, set<string> &addresses) {
        if (begin >= s.length()) {
            if (split.size() >= 4) {
                string address(s);
                for (size_t i = 0; i + 1 < split.size(); ++ i) {
                    address.insert(split[i] + i, 1, '.');
                }
                addresses.insert(address);
            }
            return;
        }
        else if (split.size() >= 4) {
            return;
        }
        for (size_t i = begin; i < s.length(); ++ i) {
            if ('0' == s[begin] && i > begin) {
                break;
            }
            int num = atoi(s.substr(begin, i - begin + 1).c_str());
            //cout << "debug " << begin << " " << i << " " << s.substr(begin, i - begin + 1) << " " << num << endl;
            if (num >= 0 && num <= 255) {
                split.push_back(i + 1);
                restoreIpAddresses(i + 1, split, s, addresses);
                split.pop_back();
            }
            if (num > 255) {
                break;
            }
        }
    }
};