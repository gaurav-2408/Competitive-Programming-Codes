/*
  Author : Gaurav Jain
  Date : 2nd October 2020
  Contest : NCR codewars 2020 
  Question : Encrypting a code
    A system gives a password for email IDs in the form of a code and you have to encrypt it, now the code is divided into  parts and is represented as an array the number of parts of the code is the size of  the array.
    Now, you are required to convert each part of code into a number and then you must combine the parts of the array in the numerical form In such a way that the final number obtained after merging all element of the array is the maximum possible number that can be formed  from them.
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
// const int M = 2e5+5;
// int a[M];

ll valueString (string s){
   
    ll i, sum = 0;
    
    ll len = s.length();
    
    for(i = 0 ; i < s.length() ; i++)
    {
        sum += int(s[i] - 64)*pow(26, (len - i - 1));    
    }
    
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll n, i;
	
	cin>>n;
	
	vector <ll>v(n);
	
	string s[n];
	
	for(i = 0 ; i < n ; i++)
	{
	    cin>>s[i];
	    
	    v[i] = valueString(s[i]);
	}
	
	sort(v.begin(), v.end());
	
	for(i = n - 1 ; i >= 0 ; i--)
	{
	    cout<<v[i];
	}
	return 0;
}
