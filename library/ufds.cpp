#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;

class UFDS{
    private:
        vector<Int> arr, size;

        Int findSet(Int a){
            vector<Int> path;
            while(arr[a]!=a){
                path.push_back(a);
                a = arr[a];
            }
            for(let x : path){
                arr[x] = a; size[x] = 1;
            }

            return a;
        }

    public:
        UFDS(Int n){
            REP(i, n){
                arr.push_back(i);
                size.push_back(1);
            }
        }

        void unionSet(Int a, Int b){
            a=findSet(a); b=findSet(b);
            if(a!=b){
                if(size[a]<size[b]){
                    arr[a] = b;
                    size[b] += size[a];
                }else{
                    arr[b] = a;
                    size[a] += size[b];
                }
            }
        }

        bool isSameSet(Int a, Int b){
            return findSet(a)==findSet(b);
        }

        Int findSetSize(Int a){
            return size[findSet(a)];
        }
};
