#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> cycle;
        while(head){
            if(cycle.count(head)){
                return head;
            }
            cycle.insert(head);
            head = head->next;
            

        }
        return nullptr;
    }
};
int main(){
    
}