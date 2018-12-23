#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: opensource
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-22 13:15:48.203509 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */

using ss = unordered_set<string>;
using msi = unordered_map<string, Int>;
using mss = unordered_map<string, string>;

void solve() {
    while(true){
        string s, p;
        ss invalid, projs; mss students;
        while(getline(cin, s) && s!="1" && s!="0"){
            if(isupper(s[0])){
                p = s; projs.insert(p);
            }else{
                if(students.count(s)==0 || students[s]==p){
                    students[s] = p;
                }else{
                    invalid.insert(s);
                }
            }
        }

        if(s=="0"){ break; }

        msi cnt;
        for(let x : projs){
            cnt[x] = 0;
        }

        for(let x : students){
            if(invalid.count(x.first)==0){
                cnt[x.second]++;
            }
        }

        vector<pair<Int, string>> qs;
        for(let x : cnt){
            qs.push_back(make_pair(-x.second, x.first));
        }
        sort(qs.begin(), qs.end());

        for(let x : qs){
            cout << x.second << ' ' << -x.first << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
