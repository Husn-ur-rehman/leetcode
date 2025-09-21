#include<bits/stdc++.h>
using namespace std;
vector<int> sumZero(int n) {

    vector<int> ans;
    if(n%2 == 0){
        for(int i = 1; i <= n/2;i++){
            ans.push_back(i*-1);
            ans.push_back(i);
        }
        return ans;    
    }
    if(n%2 != 0){
        for(int  i = 1; i <= n/2; i++){
            ans.push_back(i*-1);
            ans.push_back(i);
        }
        ans.push_back(0);
        return ans;
    }
    return ans;    
}
int main(){
    
}