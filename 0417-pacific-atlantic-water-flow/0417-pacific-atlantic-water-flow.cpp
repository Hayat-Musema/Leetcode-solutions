

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> pac(m, vector<int>(n)), atl(m, vector<int>(n));
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        auto dfs = [&](auto&& self, int r, int c, vector<vector<int>>& ocean) -> void {
            ocean[r][c] = 1;
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr>=0 && nr<m && nc>=0 && nc<n &&
                    !ocean[nr][nc] && h[nr][nc] >= h[r][c]) {
                    self(self, nr, nc, ocean);
                }
            }
        };

        for (int i = 0; i < m; i++) {
            dfs(dfs, i, 0, pac);
            dfs(dfs, i, n-1, atl);
        }
        for (int j = 0; j < n; j++) {
            dfs(dfs, 0, j, pac);
            dfs(dfs, m-1, j, atl);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j])
                    res.push_back({i, j});

        return res;
    }
};
