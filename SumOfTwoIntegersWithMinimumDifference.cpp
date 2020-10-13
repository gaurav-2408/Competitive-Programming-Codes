/*Contest : Unknown
  Author : Gaurav Jain
  Date : 13th October 2020
  
  Problem Statement : Given an integer split the given integer into two integer
                      which sums upto given integer which the minimum possible
                      difference value. Also the splitted integers should not contain 
                      the digit 4 in it.

  Problem Constraints : Given an integer N, find 2 integers n1 and n2, where n1+n2=n2
                        n1 and n2 must meet the following conditions:
                        1. Neither n1 or n2 can contain the digit '4'.
                        2. n1-n2 should be minimum as possible.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
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

bool findFour(ll num)
{
    ll rem;
    
    while(num)
    {
        rem = num % 10;
        
        if(rem == 4)
        {
            return true;
            
            break;
        }
        num /= 10;
    }
    
    return false;
}

int main()
{
    ll num, a, b, temp, x, y;
    
    cin>>num;
    
    if(num % 2 == 0)
    {
        temp = num + 2;
        
        a = temp/2;
        
        b = num - a;
    }
    else
    {
        temp = num + 1;
        
        a = temp/2;
        
        b = num - a;
    }
    
    
    x = max(a, b);
    
    y = min(a, b);
    
    while(findFour(x) == true || findFour(y) == true)
    {
        x -= 1;
        
        y += 1;
        
        x = min(x, y);
        
        y = max(x, y);
        
    }
    
    cout<<max(x, y)<<" "<<min(x, y);
    
    return 0;
}