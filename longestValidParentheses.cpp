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

bool areBracketsBalanced(string expr) 
{   
    stack<char> s; 
    char x; 
    for (int i = 0; i < expr.length(); i++)  
    { 
        if (expr[i] == '(')  
        { 
            s.push(expr[i]); 
            continue; 
        } 
        if (s.empty()) 
            return false; 
  
        switch (expr[i]) { 
        case ')': 
            x = s.top(); 
            s.pop(); 
            break; 
        } 
    } 
    return (s.empty()); 
} 
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll i, l, r, len, maximum = -1; string s, helperString;
	cin>>s;
	len = s.length(); l = 0; r = len - 1;
	if(s[0] == ')')
	{
	    ++l;
	    goto label;
	}
	else
	{
	    label:
	    {
	        helperString.clear();
	        if(r - l == 0)
	        {
	            cout<<"\n"<<maximum;
	            exit(0);
	        }
	        for(i = l ; i <= r ; ++i)
	        {
	            helperString.pb(s[i]);
	        }
	        //copy(s.begin() + l, s.begin() + r+ 1, helperString.begin());
	        if(areBracketsBalanced(helperString))
	        {
	            maximum = max((r - l + 1), maximum);
	            cout<<r - l + 1<<"\n";
	            l = r;
	            r = len - 1;
	            goto label;
	        }
	        else
	        {
	            r--;
	            if(r - l == 0)
	            {
	                ++l;
	                r = len - 1;
	                goto label;
	            }
	            goto label;
	        }
	    }
	 }
	return 0;
}