//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> mat1(row,vector<int>(col,1));
        vector<vector<int>> visited(row,vector<int>(col,0));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mat[i][j] == 0)
                {
                    for(int k = 0; k < 4; k++)
                    {
                        int nr = dr[k] + i;
                        int nc = dc[k] + j;
                        if(nr >= 0 && nr < row && nc >=0 && nc < col)
                        {
                            mat1[nr][nc] = 0;
                        }
                    }
                }
            }
        }
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i < row; i++)
        {
            if(mat1[i][0] == 1)
                q.push({1,{i,0}});
        }
        while(q.size())
        {
            auto temp = q.front();
            q.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            int dist = temp.first;
            visited[i][j]=1;
            if(j == col - 1)
                return dist;
            for(int k = 0; k < 4; k++)
            {
                int nr = dr[k] + i;
                int nc = dc[k] + j;
                if(nr >= 0 && nr < row && nc >=0 && nc < col && mat1[nr][nc] == 1 && visited[nr][nc] == 0)
                {
                    q.push({dist+1,{nr,nc}});
                }
            }
            
        }
        return -1;
       // code here
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends