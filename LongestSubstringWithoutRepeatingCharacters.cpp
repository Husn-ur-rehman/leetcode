#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//Sliding Window Technique O(n)
    int LengthOfLongestSubstring(string s) {
        unordered_set<char> repeated;
        int left = 0, right = 0, maxlength = 0;
        
        while(right < s.length()){
            if(!repeated.contains(s[right])){
                repeated.insert(s[right]);
                int size = right - left + 1;
                if(size > maxlength) maxlength = size;

                ++right;
            }
            else{
                repeated.erase(s[left]);
                left++;
            }
        }
        return maxlength;      
    }
    // Optimized Sliding Window, O(n)
    int lengthOfLongestSubstring(string s){
        int arr[256]; // tot  characters
        fill(begin(arr),end(arr),-1); // for filling the values

        int right = 0, left = 0, maxlength = 0, size = s.length();

        while(right < size){
            if(arr[s[right]] >= left){
                left = arr[s[right]] + 1;
    
            }
            arr[s[right]] = right;

            maxlength = max(maxlength, right - left + 1);
            right++;

        }
        return maxlength;

    }
};

int main() {
 
    Solution obj;

    vector<string> testCases = {
        "abcabcbb", // Expected output: 3 ("abc")
        "bbbbb",    // Expected output: 1 ("b")
        "pwwkew",   // Expected output: 3 ("wke")
        "abba",     // Expected output: 2 ("ab" or "ba")
        ""          // Expected output: 0 (Empty string)
    };

    // running test cases
    for (const string& testStr : testCases) {
        int result = obj.LengthOfLongestSubstring(testStr);
        cout << "String: \"" << testStr << "\" -> Longest Unique Substring Length: " << result << "\n";
    }

    return 0;
}