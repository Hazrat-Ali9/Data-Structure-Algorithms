#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

    void booleanMatrix(vector<vector<int> > &matrix){
        // code here
        int n = matrix.size(), m =matrix[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1) q.push({i, j});
            }
        }
        while(!q.empty()){
            auto x = q.front(); q.pop();
            int r = x.first, c = x.second;
            for(int i=0; i<m; i++){
                if(matrix[r][i] != 1) matrix[r][i] = 1;
            }
            for(int i=0; i<n; i++){
                if(matrix[i][c] != 1) matrix[i][c] = 1;
            }
        }
    }
};



int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row);
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



