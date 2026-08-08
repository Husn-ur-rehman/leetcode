#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void backtrack(int i, string s, string& digits,vector<string>& letters, vector<string>& res){

        if(i == digits.size()){
            res.push_back(s);
            return;
        }
        string l = letters[digits[i] - '0'];


        for(int j = 0; j < l.size(); j++){
            s.push_back(l[j]);
            backtrack(i+1, s, digits, letters, res);
            s.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> letter = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;

        if(digits.empty()) return {};
            
        backtrack(0, "",digits, letter, ans);
        return ans;
    }

    void printAns(vector<string> input){
        
        for(int i = 0; i < input.size();i++){
            cout<<input[i]<<" ";
        }
    }

};
int main(){
    Solution obj;
    vector<string> test = obj.letterCombinations("26");
    obj.printAns(test);
}