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


// http://fisherlei.blogspot.ca/2013/11/leetcode-lru-cache-solution.html
class LRUCache{
public:
	struct CacheEntry {
	public:
		int key;
		int value;
		CacheEntry(int k, int v) : key(k), value(v)
		{}
	};
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (cache_map.end() == cache_map.find(key)) {
			return -1;
		}
		moveToHead(key);
		return cache_map[key]->value;
	}

	void set(int key, int value) {
		if (cache_map.end() == cache_map.find(key)) {
			CacheEntry new_cache(key, value);
			if (cache_list.size() >= capacity) {
				cache_map.erase(cache_list.back().key);
				cache_list.pop_back();
			}
			cache_list.push_front(new_cache);
			cache_map[key] = cache_list.begin();
		} else {
			cache_map[key]->value = value;
			moveToHead(key);
		}
	}
	void moveToHead(int key) {
		CacheEntry entry = *cache_map[key];
		cache_list.erase(cache_map[key]);
		cache_list.push_front(entry);
		cache_map[key] = cache_list.begin();
	}
	unordered_map<int, list<CacheEntry>::iterator> cache_map;
	list<CacheEntry> cache_list;
	int capacity;
};
