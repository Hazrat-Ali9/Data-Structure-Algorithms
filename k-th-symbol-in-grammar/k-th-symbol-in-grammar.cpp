class Solution {
public:
    int kthGrammar(int n, int k) {
        return dfs(n, k, 0);
    }
    int dfs(int n, int k, int rootVal){
        if(n == 1) return rootVal;
        int totalNodes = pow(2, n-1);
        if(k > (totalNodes/2)){
            int nxtRootVal = rootVal == 0 ? 1 : 0;
            return dfs(n-1, k-(totalNodes/2), nxtRootVal);
        }
        else{
            int nxtRootVal = (rootVal == 0) ? 0 : 1;
            return dfs(n-1, k, nxtRootVal);
        }
    }
};