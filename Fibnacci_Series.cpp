#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
/*
Ques : Fibnacci series using the all the dp Ways.
Time and Space complexity are given below :
 tc, sc  - using recursion - O(Exponential) , o(n)
 tc , sc - using tabulation - O(n), o(1)
 tc , sc - using memorization - O(n) , O(n)
*/
class Solution {
    int memorization( int n , vector<int> & dp )
    {
        if( n ==0 )
            return 0 ; 
        if( n ==1 )
            return 1 ; 
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = memorization( n -1 , dp ) + memorization(n-2 , dp ); 
        return dp[n]; 
    }
    int recursive_fib(int n)
    {
        if( n ==0 )
            return 0 ; 
        if( n ==1 )
            return 1 ; 
        
        return recursive_fib(n-1) + recursive_fib(n-2); 
    }
    int tabulation( int n )
    {
     
        int ptr1 = 0 ; 
        int ptr2 = 1 ;
        if( n ==0 )
            return 0 ; 
        if( n ==1 )
            return 1 ; 
       for( int  i = 2 ; i <= n ; i++)
       {
           int sum = ptr1 + ptr2; 
           ptr1 = ptr2 ; 
           ptr2 = sum; 
       }
    
       return ptr2 ; 
    }
    public : 
    int fib(int n) {
        int ans = tabulation( n ); 
        //we can call any of the above fxn to find the answer
        return ans ;
    }
};
int main()
{
  int n = 5 ; 
  Solution obj ;
  cout<<obj.fib(n);    
 return 0;
}

