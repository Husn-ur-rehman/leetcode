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
    //Helper Function (checks whether the substring is palindrome or not)
    bool isPalindrome(const string& s, int left, int right){

        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;

    }
    //Helper Function return length;
    int expand(const string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            right++;
            left--;
        }
        return right - left - 1;
    }
    //Around Center Approach O(n^2) Time complexity and O(1) space complexity
    string AroundCenterApproach(string s){
       int maxlength = 0, size= s.size(), start = 0;
    
       for(int i = 0 ; i < size ; i++ ){
        int len1 = expand(s, i, i); // for odd ones;
        int len2 = expand(s, i, i+1); // for even ones;
            if(max(len1,len2) > maxlength){    
                maxlength = max(len1,len2);
                start = i - (maxlength-1)/2;
            }

       }
       return s.substr(start,maxlength);
       
    }

};

int main(){
    vector<string> arr = {"kkkokkk","jkekkl","aheljws", "hammad"};
    Solution obj;

    for(int i = 0 ; i < arr.size(); i++){
        cout<<obj.AroundCenterApproach(arr[i])<<endl;
    }
    
}