#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 
/*
Ques Link : https://www.codingninjas.com/codestudio/problems/dice-throws_799924?topList=top-dynamic-programming-questions&leftPanelTab=0
*/
#define mod 1000000007
int solve( int dice , int face , int target, vector<vector<int> > &dp)
{
    if( target==0 && dice ==0)
        return 1 ; 
    if( dice == 0)
        return 0 ; 
    if ( target <  0)
        return 0 ; 
    if(dp[dice][target] != -1)
        return dp[dice][target]; 
    int way =0 ; 
    for(int i = 1 ; i <=face; i++ )
    {
        way = (way + solve(dice-1 ,face , target-i, dp))%mod;
    }
    dp[dice][target]= way%mod ; 
    return way%mod; 
}
int diceThrows(int d, int f, int s) {
     vector<vector<int>> dp( d+1 , vector<int> (s+1, -1)); 
    int ans = solve( d , f , s,dp); 
    return ans ; 
}
int main()
{
 int dice , face , sum ; 
 cout<<"Enter the number of dices : " ; 
 cin>>dice ; 
 cout<<"Enter the number of  faces on each dice : " ; 
 cin>>face ; 
 cout<<"Enter the sum to form : "; 
 cin>>sum ; 
cout<<diceThrows(dice ,face , sum)<<"  ways are there to form the given sum using the given dices" <<endl; 
}