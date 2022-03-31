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


int32_t main() {
    int i,j;
    double X, Y, R;

    cin >> X >> Y >> R;
    int x = (int)(X * 10000 + 0.1);
    int y = (int)(Y * 10000 + 0.1);
    int r = (int)(R * 10000 + 0.1);

    int ans = 0;
    int now = (x - r) - (x-r) % 10000;
    while (now <= x + r) {
        // printf("now = %lld\n", now);
        int dx = abs(now - x);
        double dy = r*r - dx*dx;
        if (dy > 0)
            dy = sqrt(dy);
        // printf("raw: d = %.6f, u = %.6f\n", (y-dy)/10000, (y+dy)/10000);
        // printf("tuned: d = %.6f, u = %.6f\n", ceil((y-dy)/10000), floor((y+dy)/10000));
        int u = (int)floor((y+dy)/10000);
        int d = (int)ceil((y-dy)/10000);
        // printf("(%lld, %lld)\n", d, u);
        ans += (u - d + 1);
        now += 10000;
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
