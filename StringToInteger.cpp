#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int len = s.length(), i = 0 ;
        long long ans = 0;
        bool flag = false;

        while(i < len && isspace(s[i])){
            i++;
        }

        if(i < len && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') flag = true;

            i++;
        }

        while(i < len && isdigit(s[i])){
            int digit = s[i] -'0';
            ans = (ans*10) + digit;
            if(ans > INT_MAX){ 
                if(flag) return INT_MIN;
                return INT_MAX;

            }
            if( flag &&  -ans < INT_MIN) return INT_MIN;
  

            i++;
        }


        if(flag) return ans * -1;
        else return ans;
    }
};

int main(){
    Solution obj;
    cout<< obj.myAtoi("123324");
    cout<< obj.myAtoi("       -32=42");
    cout<< obj.myAtoi("-123-03123");

}