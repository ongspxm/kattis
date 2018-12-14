#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: countingstars
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-14 10:42:17.054598 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int h, w, n=0;
    while(cin >> h >> w){
        n++;
        vector<string> grid;

        REP(i, h){
            string row; cin >> row;
            grid.push_back(row);
        }

        Int cnt = 0;
        REP(r, h){
            REP(c, w){
                if (grid[r][c] == '-') {
                    cnt += 1;

                    vi tmp = {r, c}; grid[r][c] = '.';
                    vector<vi> vs; vs.push_back(tmp);
                    while (vs.size() > 0) {
                        tmp = vs.back(); vs.pop_back();
                        Int r2=tmp[0], c2=tmp[1];

                        vi dx = {0, 1, 0, -1};
                        vi dy = {-1, 0, 1, 0};

                        REP(z, 4){
                            Int i=dy[z], j=dx[z];
                            if (i+r2 >= 0 && i+r2 < h
                                    && j+c2 >= 0 && j+c2 < w
                                    && grid[i+r2][j+c2] == '-') {
                                grid[i+r2][j+c2] = '.';
                                tmp = {i+r2, j+c2}; vs.push_back(tmp);
                            }
                        }
                    }
                }
            }
        }

        cout << "Case " << n << ": " << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
