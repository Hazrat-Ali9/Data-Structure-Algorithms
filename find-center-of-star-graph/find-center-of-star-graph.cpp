class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];
        return (firstEdge[0]==secondEdge[0] || firstEdge[0]==secondEdge[1]) ? firstEdge[0] : firstEdge[1];
    }
};