#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* cur = head;

    while (cur && cur->next)
    {
        if (cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return head;
}

void push_back(ListNode** head_ref, int new_data)
{
    ListNode** current = head_ref;
    while (*current != nullptr) 
    { 
        current = &(*current)->next;
    }
    *current = new ListNode(new_data);
}

void printList(ListNode* node)
{
    while (node != NULL)
    {
        cout << " " << node->val;
        node = node->next;
    }
}

int main()
{
    ListNode* head = nullptr;

    push_back(&head, 1);
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 3);

    deleteDuplicates(head);

    printList(head);

    return 0;
} 
