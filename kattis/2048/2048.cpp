#include <bits/stdc++.h>

#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

vvi complete(vvi grid) {
    vvi grid2 = vvi();

    REP(r, 4) {
        vi row2 = vi();
        vi row = grid[r];

        bool merged = false;
        REP(i, 4) {
            if (row[i] > 0) {
                if (row2.size() > 0 && row2.back() == row[i] && !merged) {
                    row[i] *= 2;
                    row2.pop_back();
                    merged = true;
                } else {
                    merged = false;
                }
                row2.push_back(row[i]);
            }
        }

        while (row2.size() != 4) {
            row2.push_back(0);
        }

        grid2.push_back(row2);
    }
    return grid2;
}

vvi transpose(vvi grid) {
    vvi grid2 = vvi();
    REP(i, 4) {
        vi row = vi();
        REP(j, 4) {
            row.push_back(grid[j][i]);
        }
        grid2.push_back(row);
    }
    return grid2;
}

vvi reverse(vvi grid) {
    REP(i, 4) {
        reverse(grid[i].begin(), grid[i].end());
    }
    return grid;
}

vvi process(vvi grid, Int step) {
    switch (step) {
        case 1:
        case -1:
            grid = transpose(grid);
            break;
        case 2:
        case -2:
            grid = reverse(grid);
            break;
        case 3:
            grid = reverse(transpose(grid));
            break;
        case -3:
            grid = transpose(reverse(grid));
            break;
        default: break;
    }

    return grid;
}

/**
 * Solution for problem: 2048
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-13 12:57:36.444341 UTC
 *
 * Lessons learned: TEXTTEXTTEXT
 */
void solve() {
    vvi grid = vvi();
    REP(r, 4){
        grid.push_back(vi());
        REP(c, 4){
            Int i; scanf("%d", &i);
            grid[r].push_back(i);
        }
    }

    Int step; scanf("%d", &step);

    grid = process(grid, step);
    grid = complete(grid);
    grid = process(grid, step*-1);

    REP(r, 4) {
        printf("%d %d %d %d\n",
                grid[r][0], grid[r][1],
                grid[r][2], grid[r][3]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
