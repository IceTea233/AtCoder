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
const int maxn = 2e2 + 7;

int N;
char S[maxn][maxn] = {};
char T[maxn][maxn] = {};

void move(char m[maxn][maxn]) {
    bool flag = true;
    while (flag) {
        for (int i=1; i<=N; i++) {
            if (m[1][i] == '#') {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i=1; i<=N-1; i++) {
                for (int j=1; j<=N; j++) {
                    m[i][j] = m[i+1][j];
                }
            }
            for (int i=1; i<=N; i++) {
                m[N][i] = '.';
            }
        }
    }

    flag = true;
    while (flag) {
        for (int i=1; i<=N; i++) {
            if (m[i][1] == '#') {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i=1; i<=N-1; i++) {
                for (int j=1; j<=N; j++) {
                    m[j][i] = m[j][i+1];
                }
            }
            for (int i=1; i<=N; i++) {
                m[i][N] = '.';
            }
        }
    }
}

void rotate(char m[maxn][maxn]) {
    int tmp[maxn][maxn] = {};
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            tmp[i][j] = m[j][N-i+1];
        }
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            m[i][j] = tmp[i][j];
        }
    }
}

bool same(char m1[maxn][maxn], char m2[maxn][maxn]) {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (m1[i][j] != m2[i][j])
                return false;
        }
    }
    return true;
}

void display(char m[maxn][maxn]) {
    printf("display:\n");
    for (int i=1; i<=N; i++)
        printf("%s\n", m[i]+1);
    printf("\n");
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> N;
    for (int i=1; i<=N; i++) {
        scanf("%s", S[i]+1);
    }
    for (int i=1; i<=N; i++) {
        scanf("%s", T[i]+1);
    }

    move(S);
    // display(S);
    bool ans = false;
    for (int i=0; i<4; i++) {
        move(T);
        if (same(S, T))
            ans = true;
        // display(T);
        rotate(T);
    }

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");

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
