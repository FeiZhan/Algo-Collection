//WA
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(start);
        dict.insert(end);
        vector<string> word_list(dict.begin(), dict.end());
        map<size_t, unordered_set<size_t> > word_map;
        map<size_t, int> length_map;
        size_t start_index = 0;
        size_t end_index = 0;
        for (size_t i = 0; i < word_list.size(); ++ i) {
            length_map.insert(make_pair(i, INT_MAX));
            if (word_list[i] == start) {
                start_index = i;
            }
            if (word_list[i] == end) {
                end_index = i;
            }
            for (size_t j = i + 1; j < word_list.size(); ++ j) {
                int count = 0;
                for (size_t k = 0; k < word_list[i].length() && k < word_list[j].length(); ++ k) {
                    count += word_list[i][k] != word_list[j][k];
                    if (count > 1) {
                        break;
                    }
                }
                if (1 == count) {
                    word_map[i].insert(j);
                    word_map[j].insert(i);
                }
            }
        }
        length_map[start_index] = 0;
        queue<size_t> word_que;
        word_que.push(start_index);
        while (! word_que.empty()) {
            size_t current = word_que.front();
            word_que.pop();
            for (unordered_set<size_t>::iterator it = word_map[current].begin(); it != word_map[current].end(); ++ it) {
                if (length_map[*it] > length_map[current] + 1) {
                    length_map[*it] = length_map[current] + 1;
                    word_que.push(*it);
                }
            }
        }
        return length_map[end_index];
    }
};
