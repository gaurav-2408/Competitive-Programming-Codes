/*
    Author : Gaurav Jain
    Problem Name : Longest Palindromic Substring
    Source: leetcode => https://leetcode.com/problems/longest-palindromic-substring/
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

bool isPalin(string s)
{
    if(s == string(s.rbegin(), s.rend()))
        return true;
    else 
        return false;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	clock_t start, end;     //datatype to deal with time
	ll i, l ,r, len;
	string s, helperString, finalString;
	vector <string>collectionOfStrings;
	cin>>s;
	start = clock();
	len = s.length();
	l = 0; r = len - 1;
	if(len == 1)    //if length of string is 1
	{
	    cout<<s;
	    exit(0);
	}
	else
	{
    	label:
    	{
    	    if((r - l) == 0)
    	    {//termination statement-when left reaches near right
    	        if(collectionOfStrings.size() != 0)
    	            goto label3;
    	        else
    	        {
    	            cout<<s[0];
    	            exit(0);
    	        }
    	    }
    	    helperString.clear();
            for(i = l ; i <= r ; ++i)
        	{
        	    helperString.pb(s[i]);
        	}
        	if(isPalin(helperString))
        	{
        	    collectionOfStrings.pb(helperString);
        	}
        	else
        	{
        	    r--;
        	    if(r - l  == 0)//when right reaches near to left
        	        goto label1;
        	    else
        	        goto label;
        	}
        	label1:
        	{ 
        	    ++l;
        	    r = len - 1;
        	    goto label;
        	}
    
    	}
    }
	label3:
	{
	    finalString = collectionOfStrings[0];
	    for(i = 0 ; i < collectionOfStrings.size() ; ++i)//this is for getting the string with longest length
	    {
	        if(collectionOfStrings[i].length() >= finalString.length())
	            finalString = collectionOfStrings[i];
	    }
	    cout<<finalString;//Final Output->longest-palindromic-substring
	    end = clock();
	    cout<<"\n"<<double(end - start)/CLOCKS_PER_SEC;//to know the run time of the code 
	    
	    cout<<"\n";
	    for(i = 0 ; i < collectionOfStrings.size() ; ++i)//this for loop is just to dispaly all the Palindromic substring
	    cout<<collectionOfStrings[i]<<"\n";
	}
	return 0;
}