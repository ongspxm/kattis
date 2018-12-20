#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;

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
