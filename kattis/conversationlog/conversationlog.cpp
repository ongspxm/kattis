#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

using ss = unordered_set<string>;
using mss = unordered_map<string, ss>;
using msi = unordered_map<string, Int>;

using psi = pair<string, Int>;
struct cmp{
    bool operator()(psi& a, psi& b){
        if(a.second == b.second){
            return a.first > b.first;
        }else{
            return a.second < b.second;
        }
    }
};

/**
 * Solution for problem: conversationlog
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-20 12:49:14.265135 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    mss matches; ss users; msi words; string s, t;

    Int n; cin >> n; getline(cin, s);
    REP(i, n){
        getline(cin, s);
        string name; ss ws;
        Int t0=0, t1=s.find(' ');
        while(t1!=s.npos){
            t = s.substr(t0, t1-t0);
            if(t0==0){
                name=t; users.insert(name);
            }else{
                words[t]++; matches[t].insert(name);
            }
            t0 = t1+1; t1=s.find(' ', t0);
        }
        if(t0<s.size()){
            t = s.substr(t0, s.size()-t0);
            words[t]++; matches[t].insert(name);
        }
    }

    priority_queue<psi, vector<psi>, cmp> qs; Int cnt=0;
    for(let word : matches){
        if(word.second.size() == users.size()){
            qs.push(psi(word.first, words[word.first]));
        }
    }

    if(qs.size()==0){
        cout << "ALL CLEAR";
    }else{
        while(qs.size()){
            cout << qs.top().first << endl; qs.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
