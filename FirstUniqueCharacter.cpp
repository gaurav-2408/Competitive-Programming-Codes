/*
    Author: Gaurav Jain
    date: 9th January 2021
    Contest:Leetcode Problem No.387
    Problem statement: https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

ll firstUniqChar(string s)
{
    ll val, MIN = 10e9, count = 0, res;
	vector <ll>frequencyArray(26, 0);
	vector <ll>indexStore(26, -1);

	for(ll i = 0 ; i < s.length() ; i++)
	{
	    val = s[i] - 97;
	    ++frequencyArray[val];
	    indexStore[val] = i;
	}
	for(ll i = 0 ; i < 26 ; ++i)
	{
	    if(frequencyArray[i] == 1 && indexStore[i] < MIN)
            MIN = indexStore[i];
	    else if(frequencyArray[i] > 1)
            ++count;
	}
	return res = (MIN == 10e9 ? -1 : MIN);
}

//tester
int main()
{
    string s;
    
    cin>>s;
    
    cout<<firstUniqChar(s);
    
	return 0;
}