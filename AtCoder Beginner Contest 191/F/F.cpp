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

int A[maxn] = {};

int32_t main() {
    int i,j;
    int N;

    cin >> N;
    queue<int> keep;
    set<int> board;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        keep.push(A[i]);
        board.insert(A[i]);
    }
    sort(A+1, A+N+1);
    int ans = 1;
    while (!keep.empty()) {
        int now = keep.front();
        keep.pop();
        for (int i=1; i<=N; i++) {
            int gcd = __gcd(now, A[i]);
            if (board.find(gcd) == board.end()) {
                if (gcd <= A[1])
                    ans++;
                board.insert(gcd);
                keep.push(gcd);
            }
        }
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
