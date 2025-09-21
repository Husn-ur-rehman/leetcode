#include<iostream>
#include<stack>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            if(s.size()!=0){
                stack<char> s1;
                for(int i=0;i<s.size();i++){
    
                    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                        s1.push(s[i]);
                    }
                    else if(s[i] == ')' && !s1.empty() && s1.top() == '('){
                        s1.pop();

                    }
                    else if(s[i] == '}' && !s1.empty() && s1.top() == '{'){
                        s1.pop();
                    }
                    else if(s[i] == ']' && !s1.empty() && s1.top() == '['){
                        s1.pop();
                    }
                    else{
                        return false;
                    }
    
                }
            if( s1.empty()==true){
                    return true;
            }
            else{
                return false;
            }     
            }
            else{
                return false;
            }
        }
};
int main() {
    Solution sol;

    string test1 = "{[()()]()}";
    string test2 = "{[(])}";
    string test3 = "}";
    string test4 = ""; 

    return 0;
}