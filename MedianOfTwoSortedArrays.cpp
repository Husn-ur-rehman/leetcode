#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//Brute Force Method O(m + n)Both time and space;
    double FindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        double res;
        int size =  nums1.size() + nums2.size();
        int ind1 = 0, ind2 = 0, size1 = nums1.size(), size2 = nums2.size();
        //for merging the two arrays
        while(ind1 < size1 && ind2 < size2){
            if(nums1[ind1]<= nums2[ind2]){
                merged.push_back(nums1[ind1]);
                ind1++;
            }
            else {
                merged.push_back(nums2[ind2]);
                ind2++;
            }
        }
        while(ind1 < size1){
            merged.push_back(nums1[ind1]);
            ind1++;
        }
        while(ind2 < size2){
            merged.push_back(nums2[ind2]);
            ind2++;
        }

        int mergeSize = merged.size(); 

        if(!(mergeSize%2)){

            res = (merged[mergeSize/2 -1] + merged[mergeSize /2])/2.0;
        }
        else{
            res = merged[mergeSize/2];
        }
        return res;
        
    }    
    // Linear walk without making space for merged So T = O(m+n), and S = O(1);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {    
        int ind1 = 0, ind2 = 0, size1 = nums1.size(), size2 = nums2.size();
        int totalSize = size1 + size2;
        int midIndex = totalSize / 2;

        int curr = 0, prev = 0;

        for (int i = 0; i <= midIndex; i++) {
            prev = curr;

            if (ind1 < size1 && (ind2 >= size2 || nums1[ind1] <= nums2[ind2])) {
                curr = nums1[ind1];
                ind1++;
            } else {
                curr = nums2[ind2];
                ind2++;
            }
        }
        
        if (totalSize % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
    //Binary search Implementation 0(log(m+n)) complexity;
    double FindMedianSortedArrays3(vector<int>& nums1, vector<int> & nums2){
        
    }
};

int main(){
    Solution Obj;
    vector<int> arr1 = {1,2,4};
    vector<int> arr2 = {3};

    cout<<Obj.findMedianSortedArrays(arr1,arr2);

}