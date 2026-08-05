#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        //For mapping the romman digits to integer;
        vector<pair<int,string>> arr={
            {1000,"M"},{900,"CM"},
            {500,"D"}, {400,"CD"},
            {100,"C"}, {90, "XC"},
            {50, "L"}, {40, "XL"},
            {10, "X"}, {9,  "IX"},
            {5,  "V"}, {4,  "IV"},
            {1,  "I"}
        };

        int temp = num, i = 0;
        string ans;
        while(temp !=0 ){
            if(arr[i].first <= temp){
                temp -= arr[i].first;
                ans += arr[i].second;
            }
            else{
                i++;
            }
        }
        return ans;

    }
};

int main(){
    Solution obj;
    vector<int> test_cases = {4021,643,2134,6643,3646,1452,655,776};

    for(int i = 0; i < test_cases.size(); i++){
        cout<<obj.intToRoman(test_cases[i])<<endl;
    }
}