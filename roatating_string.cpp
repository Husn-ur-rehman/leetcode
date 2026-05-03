#include <iostream>
#include<algorithm>
#include<vector>



class Solution{
    public:
        bool rotateString(std::string s, std::string goal) {
        if( s.size() != goal.size()) return false;
        std::string doubled = s + s;
        return doubled.find(goal) != std::string::npos;
    }
};

int main(){
    std::string s = "abcd";
    std::string goal = "bcda";
    Solution a;
    std::cout<<a.rotateString(s,goal);
}