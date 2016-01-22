#include <bits/stdc++.h>

using namespace std;

const int OFFSET = 2005;
const int MAXN = OFFSET * 2;
typedef long long LL;
int heights[MAXN], leftx, rightx;
int h[MAXN];

bool read() {
    cin >> leftx >> rightx;
    if (leftx == 0 && leftx == rightx) {
        return false;
    }
    for (int i = leftx; i <= rightx; i += 2) {
        cin >> heights[i + OFFSET];
    }
    return true;
}

void work() {
    int lcur = 0 + OFFSET, rcur = 0 + OFFSET;
    memset(h, 0, sizeof(h));
    while (lcur > leftx + OFFSET && rcur < rightx + OFFSET) {
        if (heights[lcur - 1] == heights[rcur + 1]) {
            h[lcur] = h[rcur] = heights[lcur - 1];
        }
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (read()) {
        work();
    }
    return 0;
}