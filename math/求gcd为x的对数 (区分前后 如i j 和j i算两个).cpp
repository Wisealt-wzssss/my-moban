#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define vb vector<bool>
#define pii pair<int, int>
#define ll long long
#define eb emplace_back
#define pb push_back
#define endl '\n'
#define F(i, a, b) for(int i = a; i <= b; i++)
#define F2(i, a, b) for(int i = a; i < b; i++)
#define DF(i, a, b) for(int i = a; i >= b; i--)
#define FF(i, a) for(auto &i : a)
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;
const long long llf = 9e18;
int T = 1;
void solve() {
    //先看x的倍数有多少个 记为cnt
    //得到一个 所有gcd肯定包含x的值 (cnt) * (cnt - 1) 记为t
    //但这个t包含的不只有 gcd = x 如 2 4 6 8 10 t还包含了4和8 这个gcd为4的
    //所以求t时 我们要倒叙遍历 因为 包含更小的 肯定需要用到包含更大的之中
    int n, x; cin>>n>>x;
    vi a(n + 1);
    F(i, 1, n) cin>>a[i];

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    while(T--) solve();
} 