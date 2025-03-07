#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){

        int t = l-1;
        while(t <= r-1){
            int re = pow(2,t);
            int a = y & re, b = x & re;
            if(a!=0 && b==0) x+=re;
            t++;
        }
        return x;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;

        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
