class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int fullMask = (1 << cnt) - 1;

        if (fullMask == 0)
            return 0;

        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << cnt, -1))
        );

        // x, y, mask, energy
        queue<array<int, 4>> q;

        q.push({sx, sy, 0, energy});
        best[sx][sy][0] = energy;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y, mask, e] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    int nmask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << id[nx][ny]);
                    }

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    if (nmask == fullMask)
                        return steps + 1;

                    // Dominated state
                    if (best[nx][ny][nmask] >= ne)
                        continue;

                    best[nx][ny][nmask] = ne;

                    q.push({nx, ny, nmask, ne});
                }
            }

            steps++;
        }

        return -1;
    }
};