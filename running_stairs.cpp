#include<iostream>
#include<vector>
using namespace std;

/// @brief 
/// @param n 
/// @return 
long long climbStairs(int n) {
    vector<long long> nums;
    nums.push_back(1);
    nums.push_back(2);
    for(int i = 2 ; i < n; i++){
        nums.push_back(nums[i-1]+nums[i-2]);
    }
    return nums[n-1];
}
int main(){
    cout<<climbStairs(78);
}