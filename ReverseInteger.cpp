#include<iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int temp = x;
        int res = 0;
        while(temp != 0){
            if((res > INT_MAX/10 || (res == INT_MAX/10 && temp%10 > 7)) || (res < INT_MIN/10 || (res == INT_MIN/10 && temp%10 < -8))) return 0;
                res = res*10 + temp%10; 
                temp = temp/10;
        }
        return res;
    }
};
int main(){
    Solution obj;
    cout<<obj.reverse(98);
}