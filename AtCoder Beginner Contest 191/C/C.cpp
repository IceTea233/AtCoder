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

char table[17][17] = {};
int mask[4][2] = {
    {-1, 0},
    { 0,-1},
    { 1, 0},
    { 0, 1}
};

int32_t main() {
    int i,j;
    int h, w;

    cin >> h >> w;
    for (int i=1; i<=h; i++) {
        scanf("%s", table[i]+1);
    }

    int ans = 0;
    for (int i=2; i<=h-1; i++) {
        for (int j=2; j<=w-1; j++) {
            // printf(">>> (%lld, %lld)\n", i, j);
            if (table[i][j] == '.') {
                for (int k=0; k<4; k++) {
                    int nx = i + mask[k][0];
                    int ny = j + mask[k][1];
                    int mx = i + mask[(k+1)%4][0];
                    int my = j + mask[(k+1)%4][1];
                    if (table[nx][ny] == '#' && table[mx][my] == '#')
                        ans++;
                }
            } else {
                for (int k=0; k<4; k++) {
                    int nx = i + mask[k][0];
                    int ny = j + mask[k][1];
                    int mx = i + mask[(k+1)%4][0];
                    int my = j + mask[(k+1)%4][1];
                    if (table[nx][ny] == '.' && table[mx][my] == '.')
                        ans++;
                }
            }
            // printf("ans = %lld\n", ans);
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
