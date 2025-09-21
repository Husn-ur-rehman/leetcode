#include<bits/stdc++.h>
using namespace std;

vector<int> getNoZeroIntegers(int n) {       
    int b = 0;
    for(int i = 1 ; i < n;i++ ){
        b = n - i;
        if((to_string(i)).find('0') == string::npos && (to_string(b)).find('0') == string::npos){
            return {i,b};
        }
    }
        return {};
}

int main(){
    vector<int> prac = getNoZeroIntegers(1000);
    for(int x : prac){
        cout<< x <<" ";
    }
    return 0;
}