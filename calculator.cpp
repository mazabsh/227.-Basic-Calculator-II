#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     int calculator(string s){
       vector<int> nums; 
       int num =0; 
       char op ='+'; 
       for(int i=0; i<s.size(); ++i){
         char c = s[i]; 
         if(isdigit(c)) num = num*10+(c-'0'); 

         if(!isdigit(c) && !isspace(c) || i==s.size()-1){
           if(op =='+') nums.push_back(num); 
           else if(op =='-') nums.push_back(-num); 
           else if(op =='*'){
             if(!nums.empty()) {nums.back() *=num; }
             else nums.push_back(num); 
           }
           else if(op=='/'){
             if(!nums.empty()) {nums.back() /=num;}
             else  nums.push_back(num); 
           }
           op = c;
           num =0; 
         }
         
       }
       int res =0; 
       for(auto n :nums){
         res+=n; 
       }
       return res; 
     }
};
int main(){
  string s = "6-4/2"; 
  Solution sol; 
  cout << sol.calculator(s) << endl; 
  return 0; 
}
