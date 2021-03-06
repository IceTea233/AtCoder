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
const int maxn = 2e5 + 7;

struct SGT {
    int tree[maxn * 4];
    int tag[maxn * 4];

    int LC(int i) {return i * 2;}
    int RC(int i) {return i * 2 + 1;}

    void push(int l, int r, int i) {
        tree[LC(i)] += tag[i];
        tree[RC(i)] += tag[i];
        tag[LC(i)] += tag[i];
        tag[RC(i)] += tag[i];
        tag[i] = 0;
    }
    void pull(int l, int r, int i) {
        tree[i] = min(tree[LC(i)], tree[RC(i)]);
    }
    void build(vector<int> &arr, int l, int r, int i=1) {
        if (l == r) {
            tree[i] = arr[l];
            tag[i] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, LC(i));
        build(arr, m+1, r, RC(i));
        pull(l, r, i);
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] += d;
            tag[i] += d;
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d,     l, m, LC(i));
        if (m + 1 <= x2)
            upd(x1, x2, d, m + 1, r, RC(i));
        pull(l, r, i);
    }
    int query(int x1, int x2, int l, int r, int i = 1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        push(l, r, i);
        int ret = INF;
        if (x1 <= m)
            ret = min(ret, query(x1, x2,     l, m, LC(i)));
        if (m + 1 <= x2)
            ret = min(ret, query(x1, x2, m + 1, r, RC(i)));

        return ret;
    }
} seg;

int32_t main() {
    cin.tie(0);
    int i,j;
    int N;
    vector<int> A(N);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    seg.build(A, 0, N-1);
    for (int i=0; i<N; i++) {
        
    }

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
