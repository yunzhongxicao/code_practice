/*
@File  :lianbiao.cpp
@Author:dfc
@Date  :2023/3/26  20:24
@Desc  :
*/
struct ListNode {
int val;
struct ListNode *next;
};
ListNode* reorderList(ListNode* head) {
    // write code here
    ListNode* cur_node=head;
    while(cur_node->next!=nullptr && cur_node->next->next!=nullptr && cur_node->next->next->next!=nullptr){
        int temp1=cur_node->val;
        int temp2 = cur_node->next->next->val;
        cur_node->val=temp2;
        cur_node->next->next->val=temp1;
        int temp3 = cur_node->next->val;
        cur_node->next->val=cur_node->next->next->next->val;
        cur_node->next->next->next->val=temp3;
        ListNode *final_node = cur_node->next->next->next->next;
        if(final_node!=nullptr)
            cur_node=final_node;
        else
            return head;
    }
    ListNode *next_node = cur_node->next;
    if(next_node!=nullptr){
        ListNode *next_next_node =next_node->next;
        if(next_next_node!=nullptr){
            int temp1=cur_node->val;
            int temp2=next_node->val;
            cur_node->val=next_next_node->val;
            cur_node->next->val=temp1;
            cur_node->next->next->val=temp2;
        }
    }
    return head;
}
