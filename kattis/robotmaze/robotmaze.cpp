#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Solution for problem: robotmaze
 *
 * Written by: ZZZ
 *
 * Date: 2018-12-24 02:24:23.962048 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
vector<string> grid;
set<Int> visited;
Int r, c;

Int toVal(Int i, Int j, Int d){
    return (i*c + j)*4 + d;
}

Int getD(Int x){ return x%4; }
Int getR(Int x){ return x/(4*c); }
Int getC(Int x){ return (x/4)%c; }

bool isValid(Int x1, Int x2){
    Int r1=getR(x1), c1=getC(x1), d1=getD(x1);
    Int r2=getR(x2), c2=getC(x2), d2=getD(x2);

    if((grid[r2][c2]=='B')
        || r2<0 || r2>=r
        || c2<0 || c2>=c
        || grid[r1][c1]=='B'
        || r1<0 || r1>=r
        || c1<0 || c1>=c){
        return false;
    };

    if((d2==0 && r1==0)
            || (d2==1 && c1==c-1)
            || (d2==2 && r1==r-1)
            || (d2==3 && c1==0)){
        return false;
    }

    if(x1/4 == x2/4 || x1%2 == x2%2){
        return false;
    };
    return true;
}

void solve() {
    Int T; cin >> T;
    REP(t, T){
        grid.clear(); visited.clear();
        cin >> r >> c;

        Int bs, be; string s;
        REP(i, r){
            cin >> s; grid.push_back(s);
            REP(j, c){
                if(s[j]=='R'){
                    bs = i*c+j;
                }
                if(s[j]=='D'){
                    be = i*c+j;
                }
            }
        }

        queue<pair<Int, Int>> tovisit;
        vector<Int> dir = {-c,1,c,-1};
        REP(i, 4){
            Int tmp1=bs*4+(1-i%2), tmp2=(bs+dir[i])*4+i, tmp3=tmp2+(dir[i]*4);
            if(visited.count(tmp2)==0 && isValid(tmp1, tmp2)){
                tovisit.push(make_pair(tmp2,1)); visited.insert(tmp2);
                if(visited.count(tmp3)==0 && isValid(tmp2, tmp3)){
                    tovisit.push(make_pair(tmp3,1)); visited.insert(tmp3);
                }
            }
        }

        bool canDo=true; Int steps=0;
        while(true){
            if(tovisit.size()==0){
                canDo=false; break;
            }
            pair<Int, Int> curr = tovisit.front(); tovisit.pop();
            cout << endl << curr.first/4 << ' ';

            REP(i, 4){
                if(i%2 == curr.first%2){ continue; }

                Int tmp2=(((curr.first/4)+dir[i])*4 + i), tmp3=tmp2+(dir[i]*4);
                cout << i << '-' << tmp2/4 << ' ' << tmp3/4 << ' ';
                if(visited.count(tmp2)==0 && isValid(curr.first, tmp2)){
                    if(tmp2/4 == be){ steps = curr.second+1; continue; }
                    tovisit.push(make_pair(tmp2, curr.second+1)); visited.insert(tmp2);
                    cout << tmp2/4 << ". ";

                    if(visited.count(tmp3)==0 && isValid(tmp2, tmp3)){
                        if(tmp3/4 == be){ steps = curr.second+2; continue; }
                        tovisit.push(make_pair(tmp3, curr.second+2)); visited.insert(tmp3);
                        cout << tmp3/4 << ". ";
                    }
                }
            }
        }
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
