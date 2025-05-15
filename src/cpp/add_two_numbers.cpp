#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// Create a placeholder head node.
		ListNode* headPl = new ListNode(0);

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
			int sum = x + y + carry;
			carry = sum / 10;

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
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(5);

	ListNode* l2 = new ListNode(7);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(2);

	Solution s;
	ListNode* sum = s.addTwoNumbers(l1, l2);

	cout << "Result: ";
	for (ListNode* p = sum; p != nullptr; p = p->next) {
		cout << p->val;
		if (p->next)
			cout << ", ";
	}

	cout << endl;
	return 0;
}