/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if (NULL == head) {
			return NULL;
		}
		RandomListNode *new_head = new RandomListNode(INT_MAX), *trash = new RandomListNode(INT_MAX);
		// point trash to facilite deletion. Don't point to itself, leetcode will TLE
		new_head->next = trash;
		new_head->random = trash;
		for (RandomListNode *it = head, *it1 = new_head; it && it1; it = it->next, it1 = it1->next) {
			it1->label = it->label;
			node_map.insert(std::make_pair(it, it1));
			it1->next = new RandomListNode(INT_MAX);
			it1->next->next = trash;
			it1->next->random = trash;
		}
		for (RandomListNode *it = head, *it1 = new_head; it && it1; it = it->next, it1 = it1->next) {
			if (it1->next && INT_MAX == it1->next->label && it1->next->next == trash && it1->next->random == trash) {
				delete it1->next;
				it1->next = NULL;
			}
			std::map<RandomListNode *, RandomListNode *>::iterator map_it = node_map.find(it->random);
			if (NULL == it->random || node_map.end() == map_it) {
				it1->random = NULL;
			} else {
				it1->random = map_it->second;
			}
		}
		return new_head;
    }
	std::map<RandomListNode *, RandomListNode *> node_map;
};
