#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

/**
 * 邻接表优化的floyd.
 * 每个点存储它的入边和出边。
 * 三重循环遍历的时候，只要遍历入边和出边就好了。
 */

const int MAX_N = 1002;
bool dis[MAX_N][MAX_N];
// nodes[i][0]: 出边、 nodes[i][1]: 入边
vector<int> nodes[MAX_N][2];
int x, y, n, m;



int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        dis[x][y] = true;
        nodes[x][0].push_back(y);
        nodes[y][1].push_back(x);
    }

    for (int k = 1; k <= n; k++) {
        // i, j = i, k + k, j
        for (int i = 0; i < nodes[k][1].size(); i++) {
            for (int j = 0; j < nodes[k][0].size(); j++) {
                x = nodes[k][1][i];
                y = nodes[k][0][j];
                if (!dis[x][y]) {
                    dis[x][y] = true;
                    // 注意要更新x的出边、y的入边
                    nodes[x][0].push_back(y);
                    nodes[y][1].push_back(x);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j]) {
                ans++;
            }
        }
    }

    printf("%d", n * (n - 1) / 2 - ans);


    return 0;
}
