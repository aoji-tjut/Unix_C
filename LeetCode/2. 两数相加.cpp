class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1)
        {
            return l2;
        }

        if(!l2)
        {
            return l1;
        }

        ListNode* res = new ListNode(NULL);
        int add;
        int flag = 0;
        ListNode* cur = res;

        while(l1 && l2)
        {
            add = l1->val + l2->val + flag;
            flag = add / 10;

            ListNode* temp = new ListNode(add % 10);
            cur->next = temp;

            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }

        while(l1)
        {
            add = l1->val + flag;
            flag = add / 10;

            ListNode* temp = new ListNode(add % 10);
            cur->next = temp;

            l1 = l1->next;
            cur = cur->next;
        }

        while(l2)
        {
            add = l2->val + flag;
            flag = add / 10;

            ListNode* temp = new ListNode(add % 10);
            cur->next = temp;

            l2 = l2->next;
            cur = cur->next;
        }

        if(flag)
        {
            cur->next = new ListNode(1);
        }

        return res->next;
    }
};