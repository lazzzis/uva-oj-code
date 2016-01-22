/**
 * AC @ Oct 1st 2015
 * Run Time : 0.046s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 50;
struct Node {
    int dp_value, to;
}nodes[MAXN][MAXN];
int grids[MAXN][MAXN]; // row ,col
int row, col;

void read() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> grids[i][j];
        }
    }
}

void work() {
    read();
    for (int i = 0; i < row; ++i) {
        nodes[i][col - 1].dp_value = grids[i][col - 1];
    }

    for (int c = col - 2; c >= 0; --c) {
        for (int r = 0; r < row; ++r) {
            int tmp_row[3];
            tmp_row[0] = r;
            tmp_row[1] = r == 0 ? row - 1 : r - 1;
            tmp_row[2] = r == row - 1 ? 0 : r + 1;
            int tmp_ans = nodes[tmp_row[0]][c + 1].dp_value;
            for (int i = 0; i < 3; ++i) {
                tmp_ans = min(tmp_ans, nodes[tmp_row[i]][c + 1].dp_value);
            }
            nodes[r][c].dp_value = tmp_ans + grids[r][c];
            nodes[r][c].to = -1;
            for (int i = 0; i < 3; ++i) {
                if(tmp_ans == nodes[tmp_row[i]][c + 1].dp_value) {
                    nodes[r][c].to = nodes[r][c].to == -1 ? tmp_row[i] : min(nodes[r][c].to, tmp_row[i]);
                }
            }
        }
    }
    int ans = nodes[0][0].dp_value;
    for (int i = 0; i < row; ++i) {
        ans = min(ans, nodes[i][0].dp_value);
    }
    int pos;
    for (int i = 0; i < row; ++i) {
        if (nodes[i][0].dp_value == ans) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < col - 1; ++i) {
        cout << pos + 1 << " ";
        pos = nodes[pos][i].to;
    }
    cout << pos + 1 << endl;
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> row >> col) {
        work();
    }
    return 0;
}