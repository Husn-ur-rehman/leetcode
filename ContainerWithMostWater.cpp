#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Two Pointer Approach O(n) && O(1);
    int maxArea(vector<int>& height) {
        int maxArea = 0, l = 0, size = height.size(), r = size-1;
        while(l < r){
            int currentArea = min(height[l], height[r]) * (r-l);
            if(maxArea < currentArea){
                maxArea = currentArea;
            }
            if(height[l] < height[r]){
                l++;
            }
            else if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        return maxArea;
    }
};

int main(){

    Solution obj;
    vector<vector<int>> test_cases = {{4,5,2,7,8,2,9,},{5,3,7,9,1,8,6,5,8,1,3,},{9,0,1,2,3,6,8,3,2,8,4,6}};
    for(int i = 0; i < test_cases.size(); i++){
        cout<<obj.maxArea(test_cases[i])<< endl;
    }
}