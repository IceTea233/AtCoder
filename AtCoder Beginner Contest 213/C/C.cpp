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
const int maxn = 1e5 + 7;

int A[maxn], B[maxn];

int32_t main() {
    cin.tie(0);
    int i,j;
    int H, W, N;

    cin >> H >> W >> N;
    for (int i=1; i<=N; i++) {
        scanf("%lld %lld", &A[i], &B[i]);
    }
    vector<int> R;
    vector<int> C;
    for (int i=1; i<=N; i++) {
        R.PB(A[i]);
        C.PB(B[i]);
    }
    sort(all(R));
    sort(all(C));
    R.resize(unique(all(R)) - begin(R));
    C.resize(unique(all(C)) - begin(C));

    for (int i=1; i<=N; i++) {
        int r = lower_bound(all(R), A[i]) - begin(R) + 1;
        int c = lower_bound(all(C), B[i]) - begin(C) + 1;
        printf("%lld %lld\n", r, c);
    }

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
