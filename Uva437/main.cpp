/**
 * AC @ Sep 30th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30 * 3 + 5;

struct Block {
    int length, width, height;
}blocks[MAXN];

int N, end_cur;
int dp[MAXN];

bool operator != (Block& a, Block& b) {
    return a.length != b.length || a.width != b.width || a.height != b.height;
}

bool cmp(Block& a, Block& b) {
    if (a.length != b.length) {
        return a.length < b.length;
    } else if (a.width != b.width) {
        return a.width < b.width;
    }
    return a.height < b.height;
}

void read() {
    int len[3];
    for (int i = 0; i < N; ++i) {
        cin >> len[0] >> len[1] >> len[2];
        sort(len, len + 3);
        blocks[end_cur].length = len[2];
        blocks[end_cur].width = len[1];
        blocks[end_cur ++].height = len[0];

        blocks[end_cur].length = len[1];
        blocks[end_cur].width = len[0];
        blocks[end_cur].height = len[2];
        if (blocks[end_cur] != blocks[end_cur - 1]) {
            end_cur ++;
        }

        blocks[end_cur].length = len[2];
        blocks[end_cur].width = len[0];
        blocks[end_cur].height = len[1];
        if ( end_cur <=1 && blocks[end_cur] != blocks[end_cur - 1]) {
            end_cur ++;
        } else if (end_cur > 1 && blocks[end_cur] != blocks[end_cur - 1] && blocks[end_cur] != blocks[end_cur - 2]) {
            end_cur ++;
        }
    }
}

int Case = 0;
void work() {
    end_cur = 0;
    read();
    sort(blocks, blocks + end_cur, cmp);
    int ans = -1;
    for (int i = 0; i < end_cur; ++i) {
        int maxHeight = 0;
        for (int j = 0; j < i; ++j) {
            if (blocks[i].length > blocks[j].length && blocks[i].width > blocks[j].width) {
                maxHeight = max(maxHeight, dp[j]);
            }
        }
        dp[i] = maxHeight + blocks[i].height;
        ans = max(ans, dp[i]);
    }
    cout << "Case " << (++Case) << ": maximum height = " << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        work();
    }
    return 0;
}