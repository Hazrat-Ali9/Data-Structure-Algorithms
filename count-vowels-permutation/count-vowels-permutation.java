class Solution {
    public int countVowelPermutation(int n) {
        int mod = (int)1e9+7;
        long a = 1, e = 1, i = 1, o = 1, u = 1, aNew, eNew, iNew, oNew, uNew;
        for(int k=2; k<=n; k++){
            aNew = e;
            eNew = (a+i)%mod;
            iNew = (a+e+o+u)%mod;
            oNew = (i+u)%mod;
            uNew = a;
            a = aNew;
            e = eNew;
            i = iNew;
            o = oNew;
            u = uNew;
        }
        return (int)((a+e+i+o+u)%mod);
    }
}