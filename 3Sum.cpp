#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        for(int i = 0; i < size-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = size-1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1])left++;
                    while(left < right && nums[right] == nums[right-1])right--;
                    left++;
                    right--;
                }
                else if(sum > 0) right--;
                else        left++;
            }
        }
        return res;
    }
    void printResult(vector<vector<int>>& res) {
    for(auto& triplet : res){
        cout << "[";
        for(int i = 0; i < triplet.size(); i++){
            cout << triplet[i];
            if(i != triplet.size()-1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
}
};

int main(){
    Solution obj;
    vector<vector<int>> test_cases = {{1,2,4,-4,-2,-1},{0,0,1,3,-4,-5,2,3,1,5,0},{9,4,1,-3,2,-4,-7,12,2}};
    vector<vector<int>> ans;
    for(int i = 0; i <test_cases.size();i++ ){
        ans = obj.threeSum(test_cases[i]);
        obj.printResult(ans);
    }
    
}