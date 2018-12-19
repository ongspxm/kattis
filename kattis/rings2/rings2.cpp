#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

void p(Int v, Int m){
    cout << '.';
    if(m>=10 && v<10){
        cout << '.';
    }

    if(v>0){
        cout << v;
    } else {
        cout << '.';
    }
}

/**
 * Solution for problem: rings2
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 11:06:41.036297 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int R, C; cin >> R >> C;
    vvi vs;

    REP(r, R){
        vi tmp; char z;
        REP(c, C){
            cin >> z;
            switch(z){
                case '.': tmp.push_back(0); break;
                default: tmp.push_back(100); break;
            }
        }
        vs.push_back(tmp);
    }

    bool changed = true; Int curr=0, m=0;
    while(changed) {
        changed = false;

        REP(r, R){
            REP(c, C){
                if (vs[r][c]<=curr) { continue; }

                vi dr = {1,0,-1,0};
                vi dc = {0,1,0,-1};

                Int t = vs[r][c] - 1;
                REP(i, 4){
                    Int r2=r+dr[i], c2=c+dc[i];
                    if(r2>=0 && r2<R && c2>=0 && c2<C){
                        t = min(t, vs[r2][c2]);
                    }else{
                        t = 0; break;
                    }
                }
                if (t < vs[r][c]-1 && t<99){
                    vs[r][c] = t+1;
                    m = max(m, t+1);
                    changed = true;
                }
            }
        }

        if (changed) { curr++; }
    }

    REP(r, R){
        REP(c, C){
            p(vs[r][c], m);
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
