#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;
using vvs = vector< vector<string> >;

int order;

vvs merge(vvs l1, vvs l2){
    vvs l; Int i1=0, i2=0;
    REP(i, l1.size()+l2.size()){
        if(!(i1<l1.size()) || (i2<l2.size() && l2[i2][order]<l1[i1][order])){
            l.push_back(l2[i2++]);
        }else {
            l.push_back(l1[i1++]);
        }
    }
    return l;
}

vvs msort(vvs list){
    if (list.size()==1) { return list; }
    Int s = list.size()/2;

    vvs l1(list.begin(), list.begin()+s);
    vvs l2(list.begin()+s, list.end());
    return merge(msort(l1), msort(l2));
}

/**
 * Solution for problem: musicyourway
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-20 01:15:33.951371 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    unordered_map<string, Int> attrs; Int an=0;
    string s, as; getline(cin, s); as = s;

    Int t = s.find(' '), t2=0;
    while(t<s.size()){
        attrs[s.substr(t2, t-t2)] = an++;
        t2 = t+1; t = s.find(' ', t2);
    }
    attrs[s.substr(t2, s.size()-t2)] = an++;

    vvs songs, songs2;
    Int n; cin >> n; REP(i, n){
        vector<string> song;
        REP(j, an){
            cin >> s; song.push_back(s);
        }
        songs.push_back(song);
    }

    cin >> n; REP(i, n){
        if (i>0) { cout << endl; }

        cin >> s; order = attrs[s];
        songs = msort(songs);

        cout << as << endl;
        for(let x : songs){
            REP(j, an){
                if (j>0) { cout << ' '; }
                cout << x[j];
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
