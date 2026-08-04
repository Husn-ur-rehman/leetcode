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

    //Dynamic Programming O(n^2) && O(n^2);
    string DynamicProgrammingApproach(string s){
        int size = s.length(), maxlen = 1, start = 0;;
        vector<vector<bool>> table(size, vector<bool>(size,false));

        // for size 1;
        for(int i = 0; i < size ; i++){
            table[i][i] = true;
        }
        // for size 2;
        for(int i = 0; i < size -1;i++){
            table[i][i+1] = (s[i] == s[i+1]);
            if(table[i][i+1]){
                if(maxlen < 2){
                    maxlen = 2;
                    start = i;
                }
            }
        }
        //For general Case: size >= 3;
        for(int len = 3; len <= size; len++) {
            for(int i = 0; i <= size - len; i++){
                int j = i + len - 1;
                if(s[i] == s[j] && table[i+1][j-1] == true){
                    table[i][j] = true;
                    if(maxlen < j - i +1){
                        maxlen = j - i + 1;
                        start = i;
                    }
                } 
            }

        }
        return s.substr(start,maxlen);


    }
};

int main(){
    vector<string> arr = {"kkkokkk","jkekkl","aheljws", "hammad"};
    Solution obj;

    for(int i = 0 ; i < arr.size(); i++){
        cout<<obj.DynamicProgrammingApproach(arr[i])<<endl;
    }
    
}