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

char s[2][maxn] = {};

char battle(char a, char b) {
    if (a == 'R') {
        if (b == 'P')
            return b;
        else
            return a;
    } else if (a == 'P') {
        if (b == 'S')
            return b;
        else
            return a;
    } else if (a == 'S') {
        if (b == 'R')
            return b;
        else
            return a;
    }
    return 0;
}

int32_t main() {
    int i,j;
    int n,k;

    cin >> n >> k;
    scanf("%s", s[0]);
    for (i=0; i<k; i++) {
        for (int j=0; j<n; j++) {
            s[(i+1)&1][j] = battle(s[i&1][(j*2)%n], s[i&1][(j*2+1)%n]);
        }
        // printf("%s\n", s[(i+1)&1]);
    }
    printf("%c\n", s[i&1][0]);

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
