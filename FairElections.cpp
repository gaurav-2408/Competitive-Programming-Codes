/*
    Author : Gaurav Jain
    Date : 4th January 2021
    Contest : CodeChef Long Challenge January 2021
    Problem Statement : 
    Elections are coming soon. This year, two candidates passed to the final stage. One candidate is John Jackson and his opponent is Jack Johnson.
During the elections, everyone can vote for their favourite candidate, but no one can vote for both candidates. Then, packs of votes which went to the same candidate are formed. You know that for John Jackson, there are NN packs containing A1,A2,…,ANA1,A2,…,AN votes, and for Jack Johnson, there are MM packs containing B1,B2,…,BMB1,B2,…,BM votes.
The winner is the candidate that has strictly more votes than the other candidate; if both have the same number of votes, there is no winner. You are a friend of John Jackson and you want to help him win. To do that, you may perform the following operation any number of times (including zero): choose two packs of votes that currently belong to different candidates and swap them, i.e. change the votes in each of these packs so that they would go to the other candidate.
You are very careful, so you want to perform as few swaps as possible. Find the smallest number of operations you need to perform or determine that it is impossible to make John Jackson win.


    
    
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

ll vecSum(vector<ll>&v)
{
    ll sum = accumulate(v.begin(), v.end(), 0);
    
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll tc, n, m, i, j, suma, sumb, count, flag;
	
	cin>>tc;
	
	while(tc--)
	{
	    cin>>n>>m;
	    
	    count = 0, flag = 0;
	    
	    vector<ll>a(n);
	    vector<ll>b(m);
	    
	    for(i = 0 ; i < n ; i++)cin>>a[i];
	    for(i = 0 ; i < m ; i++)cin>>b[i];
	    
	    suma = vecSum(a);
	    sumb = vecSum(b);
	    
	    sort(begin(a), end(a));
	    sort(begin(b), end(b), greater<ll>());
	    
	    if(suma > sumb)
	    cout<<"0\n";
	    else if(suma == sumb)
	    cout<<"-1\n";
	    else
	    {
    	    for(i = 0, j = 0; i < n, j < m ; i++, j++)
    	    {
    	        if(suma < sumb)
    	        {
    	            ++count;
    	            
    	            flag = 1;
    	   
    	            suma -= a[i];
    	            suma += b[j];
    	            
    	            sumb -= b[j];
    	            sumb += a[i];
    	            
    	            swap(a[i], b[j]);
    	            
    	        }
    	        else if(count == max(m, n) && flag != 1)
    	        {
    	            cout<<"-1\n";
    	            break;
    	        }
    	        else
    	        {
    	            cout<<count<<"\n";
    	            break;
    	        }
    	    }
	    }
	    a.clear();
	    b.clear();
	}
	return 0;
}