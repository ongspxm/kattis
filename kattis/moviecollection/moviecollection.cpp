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
            if(!idx){ cout << "fenwick 0?" << endl; }
            for(long unsigned int i=idx; i<tree.size(); i+=(i&(-i))){
                tree[i] += val;
            }
        }

        Int sum(Int left, Int right){
            return sum(right) - sum(left-1);
        }
};

/**
 * Solution for problem: moviecollection
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-22 07:03:40.265683 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    Int N; cin >> N;
    REP(n, N){
        Int m, r; cin >> m >> r;
        FenwickTree isthere(m+r); unordered_map<Int, Int> pos;
        REP(i, m){
            isthere.add(i+1, 1); pos[i+1] = m-i;
        }

        Int a, p;
        REP(i, r){
            if(i>0){ cout << ' '; }
            cin >> a; p = pos[a]; isthere.add(p, -1);
            cout << isthere.sum(p, m+i);
            pos[a] = m+1+i; isthere.add(m+1+i, 1);
        }

        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
