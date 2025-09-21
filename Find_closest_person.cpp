#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int diff(int j,int i){
        if(j > i){
            return j-i;
        }
        if(i > j ){
            return i-j;
        }
        return 0;
    }
    int findClosest(int x, int y, int z) {
        int xdis = diff(x,z);
        int ydis = diff(y,z);
        if(xdis == ydis){
            return 0;
        }
        if(xdis > ydis){
            return 2;
        }
        if(ydis > xdis){
            return 1;
        }
        return 0;
    }
};

int main (){
    
}