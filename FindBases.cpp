#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Ques : To find all the possible ways of making the number "n" using the digits from 1 to n  
note : The permutation of any of the possible answer should not be repeated. 
*/
unordered_map<string , bool> permu ; 
void solve( int n , string temp, vector<string> &ans)
{
  if(n==0)
  {
   sort(temp.begin(),temp.end()); 
   if(!permu[temp])
   {
   ans.push_back(temp); 
   permu[temp]=1 ; 
   }
   return ; 
  }
   if(n<0)
   {
      return ; 
   }

  for( int i = 1 ; i <= n ; i++)
  {
     
   temp = temp + to_string(i); 
   solve(n-i, temp , ans); 
   temp.pop_back();
  }
      

  }
int main()
{
 vector<string>ans ; 
 string temp = ""; 
 int n = 4; 
 for( int i =1 ; i < n ; i++)
 {
  temp = temp + to_string(i); 
   solve(n-i, temp , ans); 
   temp.pop_back();
 } 

 sort(ans.begin(), ans.end());
 for(int i =0 ; i < ans.size(); i++)
 {
  cout<<ans[i]<<endl;
 }
 return 0;
}