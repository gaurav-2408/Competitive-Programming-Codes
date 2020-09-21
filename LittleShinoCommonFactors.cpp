/*Platform: HackerEarth
  Question: Little Shino and common factors
  
  
  Problem Statement:
  
    Little Shino loves maths. Today her teacher gave her two integers. Shino is now wondering how many integers can divide both the numbers. She is busy with her assignments. Help her to solve the problem.

    Input:
    First line of the input file contains two integers, a and b.
    
    Output:
    Print the number of common factors of a and b.


*/


#include <bits/stdc++.h> 
#define ll long long
using namespace std; 

// Function to calculate gcd of two numbers 
ll gcd(ll a, ll b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

ll commDiv(ll a, ll b) 
{ 
	ll n = gcd(a, b); 

	// Count divisors of n. 
	ll result = 0; 
	for (ll i = 1; i <= sqrt(n); i++) { 
		if (n % i == 0) { 
			if (n / i == i) 
				result += 1; 
			else
				result += 2; 
		} 
	} 
	return result; 
} 

int main() 
{ 
    ll a, b;
    cin>>a>>b;
	cout << commDiv(a, b); 
	return 0; 
} 
