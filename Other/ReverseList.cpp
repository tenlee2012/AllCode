/*
链表的反转
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre;
        ListNode* now = NULL;
        while(pHead != NULL)
        {
            if(now == NULL)
            {
                now = (ListNode*)malloc(sizeof(ListNode));
                now->val = pHead->val;
                now->next = NULL;
                pre = now;
            }
            else
            {
                now = (ListNode*)malloc(sizeof(ListNode));
                now->val = pHead->val;
                now->next = pre;
                pre = now;
            }
            pHead = pHead->next;
        }
        return now;
 
    }
};
