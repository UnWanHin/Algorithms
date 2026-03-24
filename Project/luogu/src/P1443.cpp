#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

int n, m, sx, sy;
int dist[MAXN][MAXN];  // 到 (i,j) 的最少步數，初始 -1
bool vis[MAXN][MAXN];

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };  // 馬的8個方向
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

struct Node {
    int x, y, step;
};

void bfs() {
    queue<Node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, step = cur.step;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]) {
                vis[nx][ny] = true;
                dist[nx][ny] = step + 1;
                q.push({nx, ny, step + 1});
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);

    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", dist[i][j]);  // 左對齊，寬5格，美觀輸出
        }
        printf("\n");
    }

    return 0;
}