#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //Two pointer Approach O(n^2) && O(1)'
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closeSum = nums[0]+nums[1] +nums[2];
        int minDiff = abs(closeSum - target);

        
        for(int i = 0; i < size; i++){
            int left = i+1, right = size-1;
            while(left < right){
                int sum = nums[i] + nums[left]+nums[right];
                int currentDiff = abs(sum - target);
                
                if(currentDiff == 0) return sum;
                else if(minDiff > currentDiff ){
                    closeSum = sum;
                    minDiff = currentDiff;
                }
                if(sum < target) left++;
                else right --; 
            }
        }
        return closeSum;
        
    }
};

int main(){

    Solution obj;

    vector<int> testcase = {1,3,4,7,8,9};
    cout<<obj.threeSumClosest(testcase, 15);
}