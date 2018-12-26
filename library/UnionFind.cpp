#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;

class UnionFind {
private:
    vi p, rank, setSize;
    Int numSets;
public:
    UnionFind(Int N) {
        setSize.assign(N, 1); numSets = N;
        rank.assign(N, 0); p.assign(N, 0);
        for (Int i = 0; i < N; i++) p[i] = i;
    }

    Int findSet(Int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(Int i, Int j) { return findSet(i) == findSet(j); }

    void unionSet(Int i, Int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            Int x = findSet(i), y = findSet(j);

            if (rank[x] > rank[y]) {
                p[y] = x; setSize[x] += setSize[y];
            } else {
                p[x] = y; setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};
