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

struct info {
    int x;
    int y;
    int dir;
};

int mask[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

vector<info> to[4];
int a[3][3];

void prepare() {
    to[0].PB({0, 1, 1}); to[0].PB({0, 1, 2}); to[0].PB({0, 0, 3});
    to[0].PB({1, 0, 3}); to[0].PB({1, 0, 2}); to[0].PB({0, 0, 1});
    to[1].PB({1, 0, 1}); to[1].PB({1, 0, 2}); to[1].PB({0, 0, 3});
    to[1].PB({0,-1, 3}); to[1].PB({0,-1, 2}); to[1].PB({0, 0, 1});
}

int ans;
void dfs(info now, int idx) {
    if (idx == 2) {
        return;
    }
}

int32_t main() {
    int i,j;
    int T;

    cin >> T;
    prepare();
    while(T--) {
        ans = INF;
        dfs({0, 0, 0}, 0);
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
