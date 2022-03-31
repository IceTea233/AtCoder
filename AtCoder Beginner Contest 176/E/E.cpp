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

int h[300007] = {};
int w[300007] = {};

int cal_h[300007] = {};
int cal_w[300007] = {};

unordered_map<int,bool> mp[300007];

main() {
    int i,j;
    int H,W,M;

    cin >> H >> W >> M;

    for(i=1; i<=M; i++) {
        cin >> h[i] >> w[i];
        cal_h[ h[i] ]++;
        cal_w[ w[i] ]++;
        mp[ h[i] ][ w[i] ] = 1;
    }

    int maxi_h = 0;
    int maxi_w = 0;
    for (i=1; i<=H; i++) {
        maxi_h = max(maxi_h, cal_h[i]);
    }
    for (i=1; i<=W; i++) {
        maxi_w = max(maxi_w, cal_w[i]);
    }
    int ans = maxi_h + maxi_w - 1;

    vector<int> keep;
    for (i=1; i<=W; i++) {
        if (cal_w[i] == maxi_w)
            keep.push_back(i);
    }

    bool flag = 0;
    for (i=1; i<=H; i++) {
        if (cal_h[i] == maxi_h) {
            for (auto it: keep) {
                de(1) printf(">>> %lld %lld\n", i, it);
                if ( !mp[i][it]) {
                    flag = 1;
                    ans = maxi_h + maxi_w;
                    break;
                }
            }
        }
        if (flag)
            break;
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
