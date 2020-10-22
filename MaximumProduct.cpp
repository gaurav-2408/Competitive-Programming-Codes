/*
    Author : Gaurav Jain
    Date : 22 October 2020
    Contest : Unknown
    Problem Statement:
    Given an number n, the task is to broken in such a way that multiplication of its parts is maximized.
    
    Input : n = 10
            Output : 36
            10 = 4 + 3 + 3 and 4 * 3 * 3 = 36
            is maximum possible product.
            
            Input : n = 8
            Output : 18
            8 = 2 + 3 + 3 and 2 * 3 * 3 = 18
            is maximum possible product.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())

ld MaxProduct(ll n)
{
    ll count2 = 1, count3 = 1;
    
    ll rem, sum = 5;
    
    rem = n - sum;
    
    if(n < 5)
    return n;
    else
    {
        while(rem)
        {
            if(rem % 3 == 0)
            {
                rem -= 3;
                
                count3++;
            }
            else if(rem % 2 == 0)
            {    
                rem -= 2;
                
                count2++;
            }
            else
            {
                if(rem == 1)
                {
                    count2--;
                    
                    rem += 2;
                    
                }
                else if(rem > 3)
                {
                    rem -= 3;
                    
                    count3++;
                }
                else
                {
                    rem -= 2;
                    
                    count2++;
                }
            }
        }
        
        return pow(2, count2)*pow(3, count3);
    }
    
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll n;
	
	cin>>n;
	
	cout<<MaxProduct(n);
	
	return 0;
}