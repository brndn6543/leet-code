#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	explicit ListNode(const int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Frees an entire list node by node. This corrects a memory
// leak that leet code does not complain about, but exists.
void deleteList(const ListNode* head) {
	while (head) {
		ListNode* next = head->next;
		delete head;
		head = next;
	}
}

class Solution {
public:
	static ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2) {
		// Create a placeholder head node.
		auto* headPl = new ListNode(0);

		// Tail is initially head.
		ListNode* tail = headPl;
		int carry = 0;

		while (l1 || l2 || carry) {
			int x;
			if (l1 != nullptr) {
				x = l1->val;
			} else {
				x = 0;
			}

			int y;
			if (l2 != nullptr) {
				y = l2->val;
			} else {
				y = 0;
			}

			// Tally.
			const int sum = x + y + carry;
			carry = sum / 10;

			// tail always starts out pointing to the head
			// placeholder.
			tail->next = new ListNode(sum % 10);
			tail = tail->next;

			// Advance.
			if (l1) {
				l1 = l1->next;
			}

			if (l2) {
				l2 = l2->next;
			}
		}
		ListNode* head = headPl->next;
		delete headPl; // Delete placeholder head.
		return head;
	}
};


int main() {
	auto* l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);

	auto* l2 = new ListNode(7);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(2);

	Solution s;
	ListNode* sum = Solution::addTwoNumbers(l1, l2);

	cout << "Result: ";
	for (ListNode* p = sum; p != nullptr; p = p->next) {
		cout << p->val;
		if (p->next)
			cout << ", ";
	}

	cout << endl;

	// Clean up the nodes to avoid leaks.
	deleteList(sum);
	deleteList(l1);
	deleteList(l2);

	return 0;
}