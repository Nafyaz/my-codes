#include<bits/stdc++.h>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
ListNode* insert(ListNode* head, ListNode* node, ListNode *list)
{
    if(head == NULL)
    {
        head = list;
        node = head;            
    }
    else
    {
        node -> next = list;
        node = node -> next;
    }
    
    return node;
}
    
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head, *node, *temp;
    
    while(list1 != NULL || list2 != NULL)
    {
        if(list1 != NULL && list2 != NULL)
        {
            if(list1 -> val < list2 -> val)                
            {
                temp = list1 -> next;
                node = insert(head, node, list1);                 
                list1 = temp;
            }
            
            else                
            {
                temp = list2 -> next;
                node = insert(head, node, list2);                 
                list2 = temp;
            }
        }
        
        else if(list1 != NULL)            
        {
            temp = list1 -> next;
            node = insert(head, node, list1);                 
            list1 = temp;
        }
        
        else
        {
            temp = list2 -> next;
            node = insert(head, node, list2);                 
            list2= temp;
        }
    }
    
    return head;
}

int main()
{
  ListNode *list1 = &ListNode(1), *list2 = &ListNode(1), *final;
  
  list1 -> next = &ListNode(2); list1 -> next = &ListNode(4);
  list2 -> next = &ListNode(3); list2 -> next = &ListNode(4);
  
  final = mergeTwoLists(list1, list2);
}