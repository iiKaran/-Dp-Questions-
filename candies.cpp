#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Ques link : https://www.codingninjas.com/codestudio/problems/candies_893290?topList=top-dynamic-programming-questions&leftPanelTab=0
*/

void solve(vector<int> &marks, vector<int> &candies, int i, int n)
{
 if (i >= n || i < 0)
  return;
 cout<<endl;

  if ( i-1 >=0 && marks[i] > marks[i - 1] && candies[i] <= candies[i - 1])
  {
   candies[i] = (candies[i-1]+candies[i]) + 1;
  }
  if ( i+1 < n && marks[i] > marks[i + 1] && candies[i] <= candies[i + 1])
  {
   candies[i] = candies[i + 1] - candies[i] + 1;
  }
 solve(marks, candies, i + 1, n);
  if (  i-1 >=0  && marks[i] > marks[i - 1] && candies[i] <= candies[i - 1])
  {
   candies[i] = (candies[i-1]+candies[i]) + 1;
  }
 

  if (  i+1 < n && marks[i] > marks[i + 1] && candies[i] <= candies[i + 1])
  {
   candies[i] = (candies[i + 1] - candies[i]) + 1;
  }
}

int main()
{
 vector<int> marks;
 int n;
  marks.push_back(1);
  marks.push_back(5);  
  marks.push_back(3); 
  marks.push_back(4);
  marks.push_back(2); 
   marks.push_back(2); 
  marks.push_back(5); 

 n = marks.size(); 
 vector<int> cand(n, 0);
 solve(marks, cand, 0, n);
cout<<"final ans "; 
 for( int i =0 ; i < cand.size() ; i++)
 cout<<cand[i]<<" ";

 return 0;
}