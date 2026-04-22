struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode();
        ListNode *prev_of_ret = nullptr;
        ListNode *next_of_ret = ret;
        int carry = 0;
        ListNode *first = l1;
        ListNode *second = l2;
        while (first != nullptr || second != nullptr) {
            int firstVal = 0;
            int secondVal = 0;
            /* We always need to check if the pointer exists before derefrencing
             * and using the data! This avoids crashes!*/
            if (first) firstVal = first->val;
            if (second) secondVal = second->val;
            int sum = firstVal + secondVal + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            }
            next_of_ret->val = sum;
            next_of_ret->next = new ListNode();
            prev_of_ret = next_of_ret;
            next_of_ret = next_of_ret->next;
            /* We always need to check if the pointer exists before derefrencing
             * and using the data! This avoids crashes!*/
            if (first) first = first->next;
            if (second) second = second->next;
        }
        if (carry == 1) {
            next_of_ret->val = 1;
        } else {
            delete next_of_ret;
            /* We need a prev pointer exactly for this. After we free the
             * next_of_ret, we leave a dangling pointer, we need to fix tha,
             * because if we don't, the user of the linked list we return is
             * gonna think we have data there, but it's garbage freed data! */
            prev_of_ret->next = nullptr;
        }

        return ret;
    }
};
