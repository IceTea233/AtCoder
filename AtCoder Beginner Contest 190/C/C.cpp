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
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e2 + 7;

int A[maxn];
int B[maxn];
int ball[maxn][2] = {};
bool v[maxn];

int32_t main() {
    int i,j;
    int N, M;

    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A[i] >> B[i];
    }
    int K;
    cin >> K;
    for (int i=0; i<K; i++) {
        cin >> ball[i][0] >> ball[i][1];
    }

    int ans = 0;
    for (int i=0; i<(1<<K); i++) {
        memset(v, 0, sizeof(v));
        for (int j=0; j<K; j++) {
            v[ ball[j][(i>>j)&1] ] = 1;
        }

        int cnt = 0;
        for (int i=0; i<M; i++) {
            if (v[A[i]] && v[B[i]])
                cnt++;
        }
        ans = max(ans, cnt);
    }
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
