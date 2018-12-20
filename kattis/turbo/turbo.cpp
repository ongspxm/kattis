#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

class FenwickTree{
    private:
        vector<Int> tree;

        int sum(Int upto){
            Int sum = 0;
            for(long unsigned int i=upto; i>0; i-=(i&(-i))){
                sum += tree[i];
            }

            return sum;
        }

    public:
        FenwickTree(Int size){
            tree.resize(size+1);
        }

        void add(Int idx, Int val){
            for(long unsigned int i=idx; i<tree.size(); i+=(i&(-i))){
                tree[i] += val;
            }
        }

        Int sum(Int left, Int right){
            return sum(right) - sum(left-1);
        }
};

/**
 * Solution for problem: turbo
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-19 23:20:01.654113 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int x, n; cin >> n;

    vi pos(n+1); FenwickTree isthere(n);

    REP(i, n){
        cin >> x; pos[x] = i+1;
        isthere.add(i+1, 1);
    }

    Int m1=1, m2=n;
    REP(i, n){
        if(i%2 == 0){
            cout << isthere.sum(1, pos[m1]-1) << endl;
            isthere.add(pos[m1],-1); m1++;
        } else {
            cout << isthere.sum(pos[m2]+1, n) << endl;
            isthere.add(pos[m2],-1); m2--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
