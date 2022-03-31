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
#define MODE 0

#define r F
#define c S

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

bool wall[27][27][4]; // {D, R, U, L}
const int mask[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

const int D = 0;
const int R = 1;
const int U = 2;
const int L = 3;

int sr, sc;
int tr, tc;
double p;

int dis[20][20] = {};

void input() {
    cin >> sr >> sc >> tr >> tc >> p;

    de(1) printf("#1 OK\n");

    for (int i=0; i<20; i++) {
        string row;
        cin >> row;
        wall[i][0][L] = true;
        for (int j=0; j<20; j++) {
            if (j == 19) {
                wall[i][j][R] = true;
            } else {
                int h = row[j] - '0';
                // cin >> h;
                if (h) {
                    wall[i][j][R] = true;
                    wall[i][j+1][L] = true;
                }
            }
        }
    }

    de(1) printf("#2 OK\n");

    for (int i=0; i<20; i++) {
        string row;
        if (i < 19)
            cin >> row;

        for (int j=0; j<20; j++) {
            if (i == 0)
                wall[i][j][U] = true;

            if (i == 19) {
                wall[i][j][D] = true;
            } else {
                int v = row[j] - '0';
                // cin >> v;
                if (v) {
                    wall[i][j][D] = true;
                    wall[i+1][j][U] = true;
                }
            }
        }
    }

    de(1) {
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                printf("(%lld, %lld): wall(%lld, %lld, %lld, %lld)\n", i, j,
                    (int) wall[i][j][D], (int) wall[i][j][R], (int) wall[i][j][U], (int) wall[i][j][L]);
            }
        }
    }
}

bool legal(int r, int c) {
    return (0 <= r && r < 20 && 0 <= c && c < 20);
}

void prepare() {
    bool vis[20][20] = {};
    int p[20][20] = {};

    queue<pii> que;
    que.push((pii) {tr, tc});
    vis[tr][tc] = true;

    // de(1) printf("#3 OK\n");

    int step = 1;
    while (que.size()) {
        int goal = que.size();
        while (goal--) {
            pii cur = que.front();
            que.pop();

            for (int i=0; i<4; i++) {
                if (wall[cur.r][cur.c][i])
                    continue;

                int nr = cur.r + mask[i][0];
                int nc = cur.c + mask[i][1];

                if (!vis[nr][nc]) {
                    vis[nr][nc] = true;
                    dis[nr][nc] = step;
                    // printf("dis[%lld][%lld] = %lld\n", nr, nc, step);
                    que.push({nr, nc});
                }
            }
        }

        // de (1) printf("\n");
        step++;
    }
}

void display(vector<vector<double>> &table) {
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            printf("%4.2f ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double heu(vector<vector<double>> &table) {
    double val = 0;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            val += table[i][j] * log(dis[i][j] + 1) * 400;
        }
    }

    return val * (1 - table[tr][tc]);
}

void trans(vector<vector<double>> &table, int cmd) {
    vector<vector<double>> nxt(20, vector<double> (20, 0));

    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            if (i == tr && j == tc) {
                nxt[i][j] += table[i][j];
                continue;
            }
            int nr = i + mask[cmd][0];
            int nc = j + mask[cmd][1];

            if (legal(nr, nc) && !wall[i][j][cmd]) {
                nxt[nr][nc] += table[i][j];
            } else {
                nxt[i][j] += table[i][j];
            }
        }
    }

    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            table[i][j] = table[i][j] * p + nxt[i][j] * (1 - p);
        }
    }
}

char cmd2ch(int cmd) {
    if (cmd == D) return 'D';
    if (cmd == R) return 'R';
    if (cmd == U) return 'U';
    if (cmd == L) return 'L';

    return '\0';
}

string solve() {
    bool vis[27][27] = {};
    int p[27][27] = {};

    string ans;

    vector<vector<double>> table(20, vector<double>(20, 0));
    vector<pair<string, vector<vector<double>>>> keep;
    table[sr][sc] = 1;

    for (int i=0; i<200; i++) {
        double val[4] = {INF, INF, INF, INF};
        for (int j=0; j < 4; j++) {
            auto it = table;
            trans(it, j);
            for (int k=0; k < 4; k++) {
                auto it2 = it;
                trans(it2, k);
                for (int h=0; h < 4; h++) {
                    auto it3 = it2;
                    trans(it3, h);
                    val[j] = min(val[j],heu(it3));
                }
            }
        }

        vector<pair<double, int>> keep = {{val[0], 0}, {val[1], 1}, {val[2], 2}, {val[3], 3}};
        sort(all(keep));
        int nxt = keep[0].S;
        ans.PB(cmd2ch(nxt));
        trans(table, nxt);
        // printf("step = %lld, heu = %6.3f\n", nxt, keep[0].F);
        // display(table);
        // system("PAUSE");
    }

    return ans;
}

int ch2cmd(char ch) {
    if (ch == 'D') return 0;
    if (ch == 'R') return 1;
    if (ch == 'U') return 2;
    if (ch == 'L') return 3;

    return -1;
}

int32_t main() {
    cin.tie(0);
    int i,j;

    input();
    prepare();
    // string ans1 = presolve();
    string ans = solve();

    cout << ans << "\n";

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
