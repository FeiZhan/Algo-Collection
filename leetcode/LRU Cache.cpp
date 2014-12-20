// correct but inefficient

class LRUCache{
public:
	class CacheNode {
	public:
		CacheNode(int k, int v) : key(k), value(v) {}
		int key;
		int value;
	};

    LRUCache(int capacity) {
		this->capacity = capacity;
    }
    
    int get(int key) {
		if (cache_map.end() != cache_map.find(key)) {
			cache_list.erase(cache_it_map[key]);
			cache_list.push_front(key);
			cache_it_map[key] = cache_list.begin();
			return cache_map[key];
		} else {
			return -1;
		}
    }
    
    void set(int key, int value) {
		cache_map[key] = value;
		std::unordered_map<int, std::list<int>::iterator>::iterator it = cache_it_map.find(key);
		if (cache_it_map.end() != it) {
			cache_list.erase(it->second);
		}
		cache_list.push_front(key);
		cache_it_map[key] = cache_list.begin();
		if (cache_list.size() > capacity) {
			cache_map.erase(cache_list.back());
			cache_it_map.erase(cache_list.back());
			cache_list.pop_back();
		}
    }
    int capacity;
    std::map<int, int> cache_map;
    std::unordered_map<int, std::list<int>::iterator> cache_it_map;
    std::list<int> cache_list;
};
