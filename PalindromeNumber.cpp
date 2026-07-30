#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // brute force Approach O(n)
        if(x < 0) return false;
        string s = to_string(abs(x));

        int size = s.length(), left = 0, right = size-1;

        while(left  < right){
            if(s[left] != s[right]) return false;

            left++;
            right--;
        }
        return true;
    }
};

int main(){

    Solution obj;
    if(obj.isPalindrome(-232)){
        cout<<"Number is a Palindrome"<<endl;

    }
    else cout<<"Number is not a Palindrome"<<endl;
}
