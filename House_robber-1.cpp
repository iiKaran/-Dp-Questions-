#include<vector> 
#include<bits/stdc++.h>
using namespace std;
/*
Ques Link : https://www.codingninjas.com/codestudio/problems/loot-houses_630510?topList=top-dynamic-programming-questions&leftPanelTab=0
*/
int maxloot( int index , vector<int> & house , int n)
{
    if( index >= n )
        return 0 ;
    int taking = house[index] +maxloot(index+2, house , n);  
    int leaving = maxloot(index+1 , house , n); 
    return max(taking , leaving ); 
}
int maxlootDp( int index , vector<int> & house , int n, vector<int> &dp)
{
    if( index >= n )
        return 0 ;
    if(dp[index] != -1 )
        return dp[index];
    int taking = house[index] + maxlootDp(index+2, house , n,dp);  
    int leaving = maxlootDp(index+1 , house , n , dp); 
    dp[index] = max(taking , leaving ); 
    return max(taking , leaving ); 
}
int maxMoneyLooted(vector<int> &houses, int n)
{
       vector<int> dp(n+1 , -1); 
//     int ans = maxloot(0, houses , n);
    int ans = maxlootDp(0 , houses , n , dp); 
    return ans; 
}
int main()
{
 vector<int> houses ; 
 // 9583 8878 3709 6449 6541 6394 376 3126 5077 964 
 houses.push_back(9583); 
 houses.push_back(8878); 
 houses.push_back(3709); 
 houses.push_back(6449);  
 houses.push_back(6541); 
 houses.push_back(6394);  
 houses.push_back(376); 
 houses.push_back(3126);  
 houses.push_back(5077); 
 houses.push_back(964); 
 int n = houses.size();
 int ans = maxMoneyLooted(houses , n); 
 cout<<ans ; 
}

