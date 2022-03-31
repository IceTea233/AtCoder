#include<bits/stdc++.h>
#define int long long
#define d lld
#define pii pair<int,int>
#define fst first
#define sec second
#define ULTRA 2134567890
#define de(x) if(x!=0 && MODE==x)
#define MODE 0
using namespace std;

int H,W;
int C[2];
int D[2];
bool v[3007][3007] = {};
bool tp[3007][3007] = {};
char S[3007][3007] = {};
int mask[4][2] = {
    { 1, 0},
    { 0, 1},
    {-1, 0},
    { 0,-1}
};

bool ok(int r, int c) {
    return (1 <= r && r <= H && 1 <= c && c <= W) && S[r][c] == '.';
}

queue<pii> que;
void dfs(int r, int c) {
    v[r][c] = 1;
    for (int i=0; i<4; i++) {
        int n_r = r + mask[i][0];
        int n_c = c + mask[i][1];
        if (ok( n_r, n_c) && !v[n_r][n_c]) {
            dfs( n_r, n_c);
        }
    }
    for (int i=-2; i<=2; i++) {
        for (int j=-2; j<=2; j++) {
            int n_r = r + i;
            int n_c = c + j;
            if (ok( n_r, n_c) && !v[n_r][n_c] && !tp[n_r][n_c]) {
                tp[n_r][n_c] = 1;
                que.push({n_r, n_c});
            }
        }
    }
}

main() {
    int i,j;

    cin >> H >> W;
    cin >> C[0] >> C[1];
    cin >> D[0] >> D[1];

    for (i=1; i<=H; i++) {
        scanf("%s", S[i]+1);
    }

    que.push({ C[0], C[1]});
    int step = 0;
    while (!que.empty() && !v[ D[0] ][ D[1] ]) {
        int goal = que.size();
        while (goal--) {
            pii now = que.front();
            que.pop();
            if (!v[now.fst][now.sec]) {
                dfs( now.fst, now.sec);
            }
        }
        de(1) {
            for (i=1; i<=H; i++) {
                for (j=1; j<=W; j++) {
                    printf("%d", v[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        step++;
    }

    if( v[ D[0] ][ D[1] ])
        printf("%lld\n", step-1);
    else
        printf("-1\n");

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
