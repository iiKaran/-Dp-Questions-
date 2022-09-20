#include <iostream>
using namespace std;
/*
Ques :Minimize the cost, Source : code studio , leet code.
*/
int recursive(int n  , int k , int a , int b, int cost)
{
    if(n == k)
    {
        return cost ; 
    }
    if(2 * k > n && k +1 > n)
    {
        // nothing can do
        return 0 ; 
    }
  if( 2*k > n || k==0 )
  {
      return recursive(n,k+1 , a , b , cost + a);
  }
  else{
      return min(recursive(n,k+1 , a , b , cost + a) , recursive(n , 2*k , a,b, cost + b)); 
  }
}
int minCostToBuyN(int n, int a, int b)
{
   int cost = 0 ; 
   int ans = recursive(n , 0 , a  , b , cost); 
    return ans ;
}
int main()
{
 
 cout<<minCostToBuyN(100 ,1000, 1000);
 return 0;
}