class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows=grid.size();
        int columns=grid[0].size();
        queue<pair<int,int>>q;
        for(int i =0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        } 
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;

            for(int i =0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];

                if(nc<0||nr>=rows||nr<0||nc>=columns)
                continue;
                 // Skip if not INF
                if(grid[nr][nc] != 2147483647)
                    continue;

                // Update distance
                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};
