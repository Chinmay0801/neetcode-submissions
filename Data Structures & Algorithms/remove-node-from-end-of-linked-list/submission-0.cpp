class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Dummy node handles removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove nth node from the end
        slow->next = slow->next->next;

        return dummy->next;
    }
};