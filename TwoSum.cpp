#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//    Brute Force Method Complexity O(n^2)
    vector<int> TwoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> result;
        for ( int i = 0; i<size; i++ ){
            for(int j = i+1; j < size; j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                } 
            }
        }
        return result;
    }
  //  For Sorted Array Complexity O(n);
    vector<int> twosum(vector<int>& nums, int target){
        vector<int> result;
        int size = nums.size();
        int left = 0;
        int right = size-1;
        while(left < right){
            if(nums[left]+ nums[right] == target) return {left,right};

            if(nums[left] + nums[right] < target) left++;
            if(nums[left] + nums[right] > target) right--;

        }
        return result;
    }
//   Hash Table Approach Complexity  T = O(1), S = O(n);
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> map;
        int size = nums.size();

        for(int i = 0; i < size; i++){
            int diff = target - nums[i];

            if(map.find(diff) != map.end()) return {map[diff],i};
            else
            map[nums[i]] = i; // value,key
        
        }
    return{};
   }
};

int main(){
    Solution obj;
    vector<int> arr = {2,4,14,5,6};
    vector<int> result = obj.twoSum(arr, 18);
    for (int index : result) {
    cout << index << " ";
}
}