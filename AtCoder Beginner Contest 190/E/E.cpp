#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

vector<int> G[maxn];

int A[maxn], B[maxn];
int C[maxn];
int target[maxn] = {};
bool v[maxn] = {};
int d[20][20] = {};
int dp[1<<20][20] = {};

int32_t main() {
    int i,j;
    int N, M;

    cin >> N >> M;
    for (int i=1; i<=M; i++)
        scanf("%lld %lld", &A[i], &B[i]);
    for (int i=1; i<=M; i++) {
        G[A[i]].PB(B[i]);
        G[B[i]].PB(A[i]);
    }
    int K;
    cin >> K;
    memset(target, -1, sizeof(target));
    for (int i=0; i<K; i++) {
        scanf("%lld", &C[i]);
        target[C[i]] = i;
    }

    for (int i=0; i<K; i++) {
        memset(v, 0, sizeof(v));
        queue<int> que;
        que.push(C[i]);
        v[C[i]] = 1;
        int step = 1;
        while (!que.empty()) {
            int goal = que.size();
            while (goal--) {
                int x = que.front();
                que.pop();
                for (auto y : G[x]) {
                    if (v[y])
                        continue;
                    v[y] = 1;
                    que.push(y);
                    if (target[y] != -1) {
                        d[i][target[y]] = step;
                    }
                }
            }
            step++;
        }
    }

    de(1) {
        for (int i=0; i<K; i++) {
            for (int j=0; j<K; j++) {
                printf("d(%lld, %lld) = %lld\n", i, j, d[i][j]);
            }
        }
    }

    for (int i=0; i<(1<<K); i++) {
        for (int j=0; j<K; j++)
            dp[i][j] = INF;
    }
    for (int i=0; i<K; i++)
        dp[1<<i][i] = 1;
    for (int i=0; i<(1<<K); i++) {
        for (int j=0; j<K; j++) {
            if (i&(1<<j)) {
                for (int k=0; k<K; k++) {
                    if (j == k || !d[j][k])
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + d[k][j]);
                    de(1) printf("dp[%lld][%lld] = %lld\n", i, j, dp[i][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int i=0; i<K; i++)
        ans = min(ans, dp[(1<<K)-1][i]);
    if (ans == INF)
        printf("-1\n");
    else
        printf("%lld\n", ans);

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
