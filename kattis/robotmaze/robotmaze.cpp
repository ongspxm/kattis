#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

/**
 * Soluvion for problem: robotmaze
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-25 23:52:49.196368 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
vector<string> grid; Int r, c;

// {r, c, dirTaken, steps}, {up, left, down, right}
vi getStep(vi step, Int dir){
    vi step2 = {step[0], step[1], dir, 1}, err={-1, -1, -1, -1};
    if(dir == step[2]){
        if(step[3]>1){ return err; }
        step2[3] = 2;
    }

    switch(dir){
        case 0:
            step2[0]--; break;
        case 1:
            step2[1]++; break;
        case 2:
            step2[0]++; break;
        case 3:
            step2[1]--; break;
        default:
            return err;
    }

    if(step[0]<0 || step[0]>=r
            || step[1]<0 || step[1]>=c
            || step2[0]<0 || step2[0]>=r
            || step2[1]<0 || step2[1]>=c
            || (grid[step2[0]][step2[1]]=='B')
            || (step[2]%2==step2[2]%2 && step[2]!=step2[2])){
        return err;
    }

    return step2;
}

void solve() {
    Int T; cin >> T;
    REP(t, T){
        cin >> r >> c;
        grid.clear(); string s;
        Int sr, sc, er, ec;

        REP(i, r){
            cin >> s; grid.push_back(s);
            REP(j, c){
                if(grid[i][j]=='R'){
                    sr = i; sc = j;
                }
                if(grid[i][j]=='D'){
                    er = i; ec = j;
                }
            }
        }

        vector<vector<vector<vector<bool>>>> visited;
        REP(i, r){
            visited.push_back(vector<vector<vector<bool>>>(c));
            REP(j, c){
                visited[i][j] = vector<vector<bool>>(4);
                REP(k, 4){
                    visited[i][j][k] = vector<bool>(2);
                }
            }
        }

        queue<pair<vi, Int>> qs; vi state={sr, sc, -1, 1};
        qs.push(make_pair(state, 0));

        Int steps = -1;
        while(qs.size()>0){
            pair<vi, Int> curr = qs.front(); qs.pop();

            /*
            REP(i, 4){
                cout << curr.first[i] << ' ';
            }
            cout << "- " << curr.second;*/

            REP(i, 4){
                vi step2 = getStep(curr.first, i);
                if(step2[0]>-1 && !visited[step2[0]][step2[1]][step2[2]][step2[3]]){
                    if(step2[0]==er && step2[1]==ec){
                        steps=curr.second+1; break;
                    }

                    qs.push(make_pair(step2, curr.second+1));
                    visited[step2[0]][step2[1]][step2[2]][step2[3]] = true;
                    // cout << "- " << step2[0] << ' ' << step2[1] << ' ' << step2[2];
                }
            }
            // cout << endl;
            if(steps>0){ break; }
        }

        cout << steps << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
