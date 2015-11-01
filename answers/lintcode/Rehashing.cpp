//@level Medium 
//@type LintCode Copyright Hash Table
//@result Accepted Total Runtime: 54 ms 100% test cases passed.

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
		vector<ListNode*> hash(hashTable.size() * 2, NULL);
		for (size_t i = 0; i < hashTable.size(); ++ i) {
			ListNode *current = hashTable[i];
			while (current) {
				int new_val = current->val;
				while (new_val < 0) {
					new_val += hash.size();
				}
				new_val %= hash.size();
				//cout << "test " << current->val << " % " << hash.size() << " == " << (current->val % hash.size()) << " -> " << new_val << endl;
				if (NULL == hash[new_val]) {
					hash[new_val] = new ListNode(current->val);
				}
				else {
					ListNode *new_node = hash[new_val];
					while (new_node && new_node->next) {
						new_node = new_node->next;
					}
					new_node->next = new ListNode(current->val);
				}
				current = current->next;
			}
		}
		return hash;
    }
};

int main() {
	// your code goes here
	Solution s;
	vector<ListNode*> hashTable(5, NULL);
	//[null,null,42->32->null,-7->null,null]
	hashTable[2] = new ListNode(42);
	hashTable[2]->next = new ListNode(32);
	hashTable[3] = new ListNode(-7);
	s.rehashing(hashTable);
	return 0;
}