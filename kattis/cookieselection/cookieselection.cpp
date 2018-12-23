#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
// using Int = int;
using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: cookieselection
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-23 02:08:39.723459 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */

void solve() {
    Int n = 600000;
    set<Int> cs;

    string s; Int idx=0, mid=0;
    while(cin >> s){
        idx++;

        if(s=="#"){
            Int tmp = mid;
            cout << tmp/n << endl;

            if(cs.size()%2){
                mid = *(++cs.find(tmp));
            }else{
                mid = *(--cs.find(tmp));
            }
            cs.erase(tmp);
        }else{
            Int x = stoll(s)*n + idx;
            cs.insert(x);
            if(mid<x && cs.size()%2==0){
                mid = *(++cs.find(mid));
            }
            else if(mid>x && cs.size()%2==1){
                mid = *(--cs.find(mid));
            }

            if(cs.size()==1){
                mid = *(cs.begin());
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
