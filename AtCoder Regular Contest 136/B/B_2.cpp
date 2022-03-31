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
const int maxn = 5e3 + 7;

int A[maxn] = {};
int B[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }
    for (int i=1; i<=N; i++) {
        cin >> B[i];
    }

    bool ans = true;
    for (int i=1; i<=N-3; i++) {
        for (j=i; j<=N && B[j] != A[i]; j++);
        if (j > N) {
            ans = false;
            break;
        }

        while (j != i) {
            if (j == N) {
                swap(B[j-1], B[j]);
                swap(B[j-2], B[j]);
            } else {
                swap(B[j-1], B[j]);
                swap(B[j+1], B[j]);
            }
            j --;
        }
    }

    bool chk = false;
    for (int i=0; i<3; i++) {
        bool flag = false;
        for (int j = N - 2; j <= N; j++) {
            if (A[j] != B[j]) {
                flag = true;
            }
        }

        if (!flag) {
            chk = true;
        }

        swap(B[N-2], B[N-1]);
        swap(B[N-1], B[N]);
    }

    if (!chk)
        ans = false;

    // for (int i=1; i<=N; i++)
    //     printf("%lld ", B[i]);
    //
    // printf("\n");

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
