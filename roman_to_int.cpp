#include <iostream>
#include <unordered_map>
using namespace std;
  
class Solution {
    public:
            unordered_map<char,int> romanmap{
                {'I',1},
                {'V',5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000}
    
            };
    
        int romanToInt(string s) {
    
            int result_2 = 0;
            for(int i=0;i<s.length();i++){
    
    
                if(i+1 < s.length() && romanmap[s[i]] < romanmap[s[i+1]]){
                    result_2 -= romanmap[s[i]] ;
                }    
                else{
                    result_2 += romanmap[s[i]];
                }
                
            }
            return result_2;
        }
    };

        int main() {
            Solution sol;
            
            string roman = "XIV";
            int result = sol.romanToInt(roman);
        
            cout << "The integer value of " << roman << " is: " << result << endl;
        
            return 0;
        }
    