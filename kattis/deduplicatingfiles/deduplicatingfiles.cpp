#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: deduplicatingfiles
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-23 00:34:22.610392 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */

using mci = unordered_map<char, Int>;
using msi = unordered_map<string, Int>;
using mcsi = unordered_map<char, msi>;

char h(string s){
    char c = '\0';
    REP(i, s.size()){ c ^= s[i]; }

    return c;
}

void solve() {
    Int n;
    while(cin >> n){
        if(n==0){ break; }

        string s; getline(cin, s);

        mcsi hashes; mci cnt;
        REP(nn, n){
            getline(cin, s); char hs = h(s);
            hashes[hs][s]++;
            cnt[hs]++;
        }

        Int coll=0, uniq=0;
        for(let x : hashes){
            Int tot=cnt[x.first], ext=0;
            for(let y : x.second){
                REP(i, y.second){
                    ext += i;
                }
            }

            coll += ((tot*(tot-1))/2)-ext;
            uniq += x.second.size();
        }

        cout << uniq << ' ' << coll << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
