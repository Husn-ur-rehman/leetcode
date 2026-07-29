#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
// Brute Force 0(n^3) Complexity
    string LongestPalindromicSubstring(string s){
        int size = s.size(), longestSPalindromeSubstring = 1 , start = 0;
        for(int i = 0; i < size; i++){
            for(int j = i; j < size; j++ ){
                if(isPalindrome(s,i,j) && longestSPalindromeSubstring < j - i + 1){
                    longestSPalindromeSubstring = j -i +1;
                    start = i;
                }
            }
        }
        return s.substr(start,longestSPalindromeSubstring);
        
    }

    bool isPalindrome(const string& s, int left, int right){

        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;

    }

};

int main(){
    vector<string> arr = {"kkkokkk","jkekkl","aheljws", "hammad"};
    Solution obj;

    for(int i = 0 ; i < arr.size(); i++){
        cout<<obj.LongestPalindromicSubstring(arr[i])<<endl;
    }
    
}