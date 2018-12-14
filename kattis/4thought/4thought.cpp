#include <bits/stdc++.h>
#define let const auto
#define REP(var, i) for (int var = 0; var < i; ++var)
using namespace std;
using Int = int;
//using Int = long long;
using vi = vector<Int>;
using vvi = vector< vector<Int> >;

Int eval(vector<char> str) {
    vi vals = vi();

    for (let val : str) {
        if (val == '4') {
            vals.push_back(4);
        } else {
            Int a, b, c;
            b = vals.back(); vals.pop_back();
            a = vals.back(); vals.pop_back();

            switch (val) {
                case '+': c = a+b; break;
                case '-': c = a-b; break;
                case '*': c = a*b; break;
                case '/': c = a/b; break;
                default: break;
            }

            vals.push_back(c);
        }
    }
    return vals[0];
}

vector<char> postFix(char* ops) {
    vector<char> symbs = {'4'};
    vector<char> signs = vector<char>();

    REP(i, 3) {
        if (ops[i]=='+' || ops[i]=='-') {
            while (signs.size()) {
                symbs.push_back(signs.back());
                signs.pop_back();
            }
        }
        else{
            while (signs.size()>0
                    && (signs.back()=='*' || signs.back()=='/')){
                symbs.push_back(signs.back());
                signs.pop_back();
            }
        }
        symbs.push_back('4');
        signs.push_back(ops[i]);
    }

    while (signs.size()) {
        symbs.push_back(signs.back());
        signs.pop_back();
    }

    return symbs;
}

/**
 * Solution for problem: 4thought
 *
 * Written by: ongspxm
 *
 * Date: 2018-12-13 14:45:39.042243 UTC
 *
 * Lessons learned:
 * - for loop against dynamic size
 */
void solve() {
    vector<string> memo = vector<string>();
    // shifted by 200 for neg nums
    REP(i, 514) {
        memo.push_back("no solution");
    }

    vector<char> signs = {'+', '-', '*', '/'};
    REP(i, 4){
        REP(j, 4){
            REP(k, 4){
                char ops[] = { signs[i], signs[j], signs[k] };
                vector<char> pfix = postFix(ops);
                Int ans = eval(pfix);

                stringstream sstr;
                sstr << "4 " << signs[i] << " 4 " << signs[j];
                sstr << " 4 " << signs[k] << " 4 = " << ans;

                memo[ans+200] = sstr.str();
            }
        }
    }

    Int x, n; cin >> n;
    REP(i, n) {
        cin >> x; x += 200;
        if (x<0 || x>457) {
            cout << "no solution";
        } else {
            cout << memo[x];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
