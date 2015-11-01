#include <iostream>
#include <map>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	void print(void) {
		cout << label << " next: ";
		if (next) {
			cout << next->label;
		}
		else {
			cout << "NULL";
		}
		cout << " random: ";
		if (random) {
			cout << random->label;
		}
		else {
			cout << "NULL";
		}
		cout << endl;
	}
};
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
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
		map<RandomListNode *, RandomListNode *> node_map;
		copyRandomList(head, node_map);
		for (map<RandomListNode *, RandomListNode *>::iterator it = node_map.begin(); it != node_map.end(); ++ it) {
			if (it->second) {
				it->second->random = node_map[it->first->random];
			}
		}
		return node_map[head];
    }
	RandomListNode *copyRandomList(RandomListNode *head, map<RandomListNode *, RandomListNode *> &node_map) {
		if (node_map.end() == node_map.find(head)) {
			if (NULL == head) {
				node_map.insert(make_pair(head, head));
			}
			else {
				RandomListNode *new_node = new RandomListNode(head->label);
				new_node->next = copyRandomList(head->next, node_map);
				node_map.insert(make_pair(head, new_node));
			}
		}
		return node_map[head];
	}
};


int main() {
	// your code goes here
	Solution s;
	//-1->8->7->-3->4->null, [4,-3,null,null,-1]
	RandomListNode *head = new RandomListNode(-1);
	head->next = new RandomListNode(8);
	head->next->next = new RandomListNode(7);
	head->next->next->next = new RandomListNode(-3);
	head->next->next->next->next = new RandomListNode(4);
	head->random = head->next->next->next->next;
	head->next->random = head->next->next->next;
	head->next->next->next->next->random = head;
	s.copyRandomList(head);
	return 0;
}