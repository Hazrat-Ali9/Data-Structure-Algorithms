
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int is_bleak(int n)
	{

	    int j = log2(n) + 1;
	    for(int i=n-j; i<n; i++){
	        if(i + __builtin_popcount(i) == n) return 0;
	    }
	    return 1;
	}
};



int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

