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

char table[1007][1007] = {};

int N;
bool ans = false;

bool legal(int r, int c) {
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

bool chk(int r, int c) {
    int cnt = 0;
    for (int i=0; i<6; i++) {
        int cur_r = r + i;
        int cur_c = c;
        if (legal(cur_r, cur_c)) {
            if (table[cur_r][cur_c] == '.') {
                cnt ++;
            }
        } else {
            cnt = -1;
            break;
        }
    }

    if (cnt != -1 && cnt <= 2) {
        return true;
    }
    // ---
    cnt = 0;
    for (int i=0; i<6; i++) {
        int cur_r = r;
        int cur_c = c + i;
        if (legal(cur_r, cur_c)) {
            if (table[cur_r][cur_c] == '.') {
                cnt ++;
            }
        } else {
            cnt = -1;
            break;
        }
    }

    if (cnt != -1 && cnt <= 2) {
        return true;
    }

    // ---
    cnt = 0;
    for (int i=0; i<6; i++) {
        int cur_r = r + i;
        int cur_c = c + i;
        if (legal(cur_r, cur_c)) {
            if (table[cur_r][cur_c] == '.') {
                cnt ++;
            }
        } else {
            cnt = -1;
            break;
        }
    }

    if (cnt != -1 && cnt <= 2) {
        return true;
    }

    // ---
    cnt = 0;
    for (int i=0; i<6; i++) {
        int cur_r = r + i;
        int cur_c = c - i;
        if (legal(cur_r, cur_c)) {
            if (table[cur_r][cur_c] == '.') {
                cnt ++;
            }
        } else {
            cnt = -1;
            break;
        }
    }

    if (cnt != -1 && cnt <= 2) {
        return true;
    }

    return false;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> N;
    for (int i=1; i<=N; i++) {
        scanf("%s", table[i] + 1);
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (chk(i, j)) {
                ans = true;
                break;
            }
        }
        if (ans)
            break;
    }

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");


    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
