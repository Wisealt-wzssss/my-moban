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
#define Fc(i, a, b, c) for(int i = a; i <= b; i += c)
#define F2(i, a, b) for(int i = a; i < b; i++)
#define DF(i, a, b) for(int i = a; i >= b; i--)
#define Fa(i, a) for(auto &i : a)
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;
const long long llf = 9e18;
int T = 1;
void solve() {
    //先看x的倍数有多少个 记为cnt
    //得到一个 所有gcd肯定包含x的值 (cnt) * (cnt - 1) 记为t
    //但这个t包含的不只有 gcd = x 如 2 4 6 8 10 t还包含了4和8 这个gcd为4的
    //之后就是容斥原理 只要2的就减去其他的倍数的
    // 如果只要8的 就减去8的其他倍数的
    //所以求t时 我们要倒序遍历 因为 只包含更小需要只包含更大的来更新
    int n, x; cin>>n>>x;
    vi a(n + 1);
    vi cnt(n + 1, 0);
    F(i, 1, n) cin>>a[i], cnt[a[i]]++;
    vl gcd_cnt(n + 1, 0);
    F(i, 1, n) {
        Fc(j, i, n, i) {
            gcd_cnt[i] += cnt[j];
        }
    }
    F(i, 0, n) {
        gcd_cnt[i] = gcd_cnt[i] * (gcd_cnt[i] - 1);
    }
    DF(i, n, 1) {
        Fc(j, i * 2, n, i) {
            gcd_cnt[i] -= gcd_cnt[j];
        }
    }
    // F(i, 1, n) {
    //     cout<<gcd_cnt[i]<<" ";
    // }
    // cout<<endl;
    cout<<gcd_cnt[x]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    while(T--) solve();
} 