/*
    Contest: July Long Challange(Chefina and Swaps)
    
    Problem Statement:
    
    Chefina has two sequences A1,A2,…,AN and B1,B2,…,BN. She views two sequences with length N as identical if, after they are sorted in non-decreasing order, the i-th element of one sequence is equal to the i-th element of the other sequence for each i (1≤i≤N).

To impress Chefina, Chef wants to make the sequences identical. He may perform the following operation zero or more times: choose two integers i and j (1≤i,j≤N) and swap Ai with Bj. The cost of each such operation is min(Ai,Bj).

You have to find the minimum total cost with which Chef can make the two sequences identical.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output
For each test case, print a single line containing one integer ― the minimum cost, or −1 if no valid sequence of operations exists.

Constraints
1 ≤ T ≤ 2,000
1 ≤ N ≤ 2⋅105
1 ≤ Ai,Bi ≤ 109 for each valid i
the sum of N over all test cases does not exceed 2⋅106

*/



#include <bits/stdc++.h>
#define pb push_back
#define ll long double 
using namespace std;

int main()
{
    ll n, i, val, tc, sum, sum1, sum2, sum3 ;
    cin>>tc;
    while(tc--)
    {
        sum = 0;
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        cin>>n;
        vector <ll>v1(n);
	    vector <ll>v2(n);

        for(i = 0 ; i < n ; i++)
        {
		    cin>>v1[i];
        }
        for(i = 0 ; i < n ; i++)
        {
            cin>>v2[i];
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<ll> inter;
        set_intersection(v1.begin(), v1.end(),v2.begin(), v2.end(),back_inserter(inter));
        v1.erase(set_difference(v1.begin(), v1.end(),inter.begin(), inter.end(),v1.begin()),v1.end());
        v2.erase(set_difference(v2.begin(), v2.end(),inter.begin(), inter.end(),v2.begin()), v2.end());
        sort(v2.begin(),v2.end(),greater<ll>());
        for(i = 0 ; i < v1.size() ; i++)
        {
            if((unsigned long int)i%2 == 0)
            {
                sum += min(v1[i],v2[i]);
                sum2 += max(v1[i],v2[i]);
            }
            else
            {
                sum1 += min(v1[i],v2[i]);
                sum3 += max(v1[i],v2[i]);
            }
        }
        
        if(sum == sum1 && sum2 == sum3)
        cout<<sum<<"\n";
        else
        cout<<"-1\n";
        v1.clear();
        v2.clear();
        inter.clear();
    }
	return 0;
}
