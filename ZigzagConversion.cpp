#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
  
    string convert(string s, int numRows) {
        if(numRows > s.length() || numRows == 1) return s;
        int n = s.length();
        string res(n, ' ');
        int zigzag = 2 * numRows - 2;
        int downidx = 0;
        for(int k =0; k < numRows; k++){
            for( int i = k; i < n; i += zigzag){
                res[downidx++] = s[i];
                int diagonalIdx = i + zigzag - 2 * k;
                if( k != 0 && k != numRows - 1 && diagonalIdx < n ){
                    res[downidx++] = s[diagonalIdx];
                }

            }
        }
        return res;
    }
    
};
int main(){
    Solution obj;
    cout<<obj.convert("idkwhattowritehere",4);

}