

#include <bits/stdc++.h>
using namespace std;
// for boosting the I/O time taken
// using ll = long long;
// using ull = unsigned long long;
// using ld = long double;

// static constexpr size_t mxal = alignof(max_align_t);
// alignas(mxal) static unsigned char buf[256 * 1024 * 1024];
// static size_t pos = 0;

// void* operator new(size_t sz) {
//     size_t pad = (mxal - (pos % mxal)) % mxal;
//     pos += pad + sz;
//     return (void*)(&buf[pos - sz]);
// }

// void* operator new[](size_t sz) { return operator new(sz); }

// void operator delete(void*) noexcept {}
// void operator delete[](void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}
// void operator delete[](void*, size_t) noexcept {}


 struct ListNode {
    int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    
    // Optimized Solution O(n)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(0);
        ListNode* tail = dummy;
        int carry=0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;
            if(l1!=nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            int digit = sum%10;

            tail->next = new ListNode(digit);
            tail = tail->next;

        }
        ListNode* result = dummy->next;
        delete dummy; 
        
        return result;
    }
        
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (int num : nums) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


// inline bool isDigit(const char c) { return (c >= '0') && (c <= '9'); }

// void parse_and_solve(const string& s1, const string& s2, ofstream& out) {
//     int S1 = s1.size(), S2 = s2.size();
//     if (S1 < S2) {
//         parse_and_solve(s2, s1, out);
//         return;
//     }
//     int carry = 0, i = 0, j = 0;
//     while (i < S1 - 1) {
//         while (i < S1 && !isDigit(s1[i]))
//             ++i;
//         while (j < S2 && !isDigit(s2[j]))
//             ++j;
//         int n1 = s1[i] - '0';
//         int n2 = (j < S2) ? (s2[j] - '0') : 0;
//         int n = carry + n1 + n2;
//         carry = n / 10;
//         out << (n % 10);
//         if (i < S1 - 2)
//             out << ",";
//         ++i;
//         ++j;
//     }
//     if (carry > 0)
//         out << "," << carry;
// }

// // // Local testing harness
// static bool Solve = []() {
//     ofstream out("user.out");
//     string s1, s2;
//     while (getline(cin, s1) && getline(cin, s2)) {
//         out << "[";
//         parse_and_solve(s1, s2, out);
//         out << "]\n";
//     }
//     out.flush();
//     exit(0);
//     return true;
// }();

// int speedUp = [] {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

int main() {
    // Optimize standard I/O operations for speed
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;

    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}