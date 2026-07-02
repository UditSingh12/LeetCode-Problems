class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        // Binary search on the safeness factor
        int lo = 0, hi = 2 * (n - 1); //  manhattan distance
        int ans = 0;
        
        auto canReach = [&](int S) -> bool {
            if (dist[0][0] < S || dist[n-1][n-1] < S) return false;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int,int>> bq;
            bq.push({0, 0});
            visited[0][0] = true;
            while (!bq.empty()) {
                auto [r, c] = bq.front(); bq.pop();
                if (r == n-1 && c == n-1) return true;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && 
                        !visited[nr][nc] && dist[nr][nc] >= S) {
                        visited[nr][nc] = true;
                        bq.push({nr, nc});
                    }
                }
            }
            return false;
        };
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};