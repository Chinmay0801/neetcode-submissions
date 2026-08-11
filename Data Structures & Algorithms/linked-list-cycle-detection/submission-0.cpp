class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // They meet -> cycle exists
            if (slow == fast)
                return true;
        }

        // Fast reached the end -> no cycle
        return false;
    }
};