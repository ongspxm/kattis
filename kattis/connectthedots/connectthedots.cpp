#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

Int getInt(char c){
    if (c-'0' < 10) {
        return c-'0';
    }

    if (c-'A' < 27) {
        return (c-'A')+36;
    }

    if (c-'a' < 27) {
        return (c-'a')+10;
    }

    return 0;
}

/**
 * Solution for problem: connectthedots
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-18 16:31:22.155847 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    string l;
    while(1==1){
        if(!getline(cin, l)){ break; }

        vector<string> ls; vvi pos;
        REP(i, 10+26+26){
            vi tmp = {-1, -1};
            pos.push_back(tmp);
        }

        Int vv = 0;
        while(l.size() > 0){
            REP(i, l.size()){
                if(l[i] != '.'){
                    Int v = getInt(l[i]);
                    if (v > vv) { vv = v; }

                    vi tmp = {ls.size(), i};
                    pos[v] = tmp;
                }
            }

            ls.push_back(l);
            getline(cin, l);
        }

        REP(i, vv){
            Int x1=pos[i][0], y1=pos[i][1];
            Int x2=pos[i+1][0], y2=pos[i+1][1];

            if (x1==x2) {
                Int m = min(y1, y2);
                REP(j, abs(y2-y1)){
                    if (ls[x1][m+j]=='|') {
                        ls[x1][m+j] = '+';
                    }
                    if (ls[x1][m+j]=='.') {
                        ls[x1][m+j] = '-';
                    }
                }
            } else {
                Int m = min(x1, x2);
                REP(j, abs(x2-x1)){
                    if (ls[m+j][y1]=='-') {
                        ls[m+j][y1] = '+';
                    }
                    if (ls[m+j][y1]=='.') {
                        ls[m+j][y1] = '|';
                    }
                }
            }
        }

        REP(i, ls.size()){
            cout << ls[i] << endl;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
