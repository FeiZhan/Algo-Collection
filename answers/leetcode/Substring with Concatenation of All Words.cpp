class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		int m = S.size(), n = L.size(), len = L[0].size();
		map<string, int> ids;
		vector<int> need(n, 0);
		for (int i = 0; i < L.size(); ++ i) {
			if (! ids.count(L[i])) {
				ids[L[i]] = i;
			}
			need[ids[L[i]]] ++;
		}
		vector<int> s(m, -1);
		for (int i = 0; i + len < m + 1; ++ i) {
			string key = S.substr(i, len);
			s[i] = ids.count(key) ? ids[key] : -1;
		}
		vector<int> ret;
		for (size_t offset = 0; offset < len; ++ offset) {
			vector<int> found(L.size(), 0);
			int count = 0, begin = offset;
			for (size_t i = offset; i + len < S.size() + 1; i += len) {
				if (s[i] < 0) {
					begin = i + len;
					count = 0;
					found.clear();
					found.resize(L.size(), 0);
				}
				else {
					int id = s[i];
					found[id] ++;
					if (need[id] && found[id] <= need[id]) {
						++ count;
					}
					if (count == L.size()) {
						ret.push_back(begin);
					}
					if ((i - begin) / len + 1 == L.size()) {
						id = s[begin];
						if (need[id] && found[id] == need[id]) {
							--count;
						}
						--found[id];
						begin += len;
					}
				}
			}
		}
		return ret;
	}
};