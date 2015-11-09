class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) : count(0) {
        // write your code here
        this->capacity = capacity;
    }

    // @return an integer
    int get(int key) {
        // write your code here
        if (cache_map.end() == cache_map.find(key)) {
            return -1;
        }
        else {
            count_map.erase(cache_map[key].second);
            cache_map[key].second = count;
            ++ count;
            count_map.insert(make_pair(cache_map[key].second, key));
            return cache_map[key].first;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (cache_map.end() == cache_map.find(key)) {
            cache_map[key] = make_pair(value, count);
        }
        else {
            cache_map[key].first = value;
            count_map.erase(cache_map[key].second);
            cache_map[key].second = count;
        }
        count_map.insert(make_pair(cache_map[key].second, key));
        ++ count;
        while (cache_map.size() > capacity) {
            //cout << "test " << count_map.begin()->first << " " << count_map.begin()->second << " " << cache_map[count_map.begin()->second].first << endl;
            cache_map.erase(count_map.begin()->second);
            count_map.erase(count_map.begin());
        }
    }
    int capacity;
    int count;
    unordered_map<int, pair<int, int> > cache_map;
    map<int, int> count_map;
};
