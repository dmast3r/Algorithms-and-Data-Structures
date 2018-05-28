#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

bool isValidCoordinates(int x, int y, int n, int m) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

void solve() {
    int n, m, sx, sy, dx, dy;
    int x_add[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int y_add[] = {1, -1, 1, -1, 2, -2, 2, -2};
    cin >> n >> m >> sx >> sy >> dx >> dy;

    if(n <= 2 or m <= 2) {
        if(sx == dx and sy == dy)
            cout << 0 << endl;
        else
            cout << -1 << endl;
        return;
    }
    --sx, --sy, --dx, --dy;
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> queue1;
    queue1.push(mp(sx, sy));
    visited[sx][sy] = true;
    distance[sx][sy] = 0;

    while(!queue1.empty()) {
        pair<int, int> coordiantes = queue1.front();
        queue1.pop();

        for(int i = 0; i < 8; ++i) {
            int x = coordiantes.first + x_add[i], y = coordiantes.second + y_add[i];
            if(isValidCoordinates(x, y, n, m )) {
                if(distance[coordiantes.first][coordiantes.second] + 1 <= distance[x][y])
                    distance[x][y] = distance[coordiantes.first][coordiantes.second] + 1;
                if(!visited[x][y]) {
                    visited[x][y] = true;
                    queue1.push(mp(x, y));
                }
            }
        }
    }

    cout << distance[dx][dy] << endl;
}

int main() {
    int test;
    cin >> test;

    while(test--)
        solve();
}
