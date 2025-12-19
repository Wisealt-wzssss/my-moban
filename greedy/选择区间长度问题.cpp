#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define vst vector<bool>
#define pii pair<int, int>
#define ll long long
#define vpi vector<pair<int, int>>
#define vpii vector<vector<pair<int, int>>>
#define eb emplace_back
#define pb push_back
#define ep emplace
#define ps push
#define fi first
#define se second
#define endl '\n'
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define F(i, a, b) for(int i = a; i <= b; i++)
#define F2(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a, b, c) for(int i = a; i <= b; i+=c)
#define drep(i, a, b, c) for(int i = a; i >= b; i -= c)
#define DF(i, a, b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;
const long long llf = 9e18;
int T = 1;
void solve() {
    /*
        题目给定n个点 要求选择以每个点为圆心的半径 这些圆只能相切 不能有任何面积重叠
        半径只能从正数中选择 可以重复 并且不一定是整数 选出相切的最大个数
        因为只在x轴上操作 所以可以不看做圆 只看对于一个点左右的区间 并不是计算几何问题
        主要问题是 这个r半径 如何选择 注意题目要求半径选择可以重复
        也就是说 对于两个点 ai ai+1 记di+1为两点之间的距离ai+1 - ai
        那么假如ai这个点的半径以及有了为ri ri+1想要被计数就只能选择di+1 - ri 但是不只是要考虑ri和ri+1之间的距离
        题目还要求不能重叠 所以 我们要对di+2-1 取一个 min

        之前我们是假设ri已经确定 但是这个题是无法确定一个准确的数字的 r1也没有给我们 所以 我们将以上所有操作转变为区间操作即可
        即 ri = [l, r] ri+1 = [di+1 - r, di+1 - l]
        最后再取min ri+1 = [max(di+1-r, 0), min(di+1 - l, di+2)]
    */
   //例题 https://codeforces.com/contest/2180/problem/D
   int n; cin>>n;
   vi a(n + 1);
   F(i, 1, n) cin>>a[i];
//    int d = a[2] - a[1];
   int l = 0;
   int r=  a[2] - a[1];
   int ans = 0;
   F(i, 1, n - 1) {
        //确认i和i + 1 是不是能满足
        int d = a[i + 1] - a[i];
        int nd = inf;
        if(i + 2 <= n) nd = a[i + 2] - a[i + 1];
        int nl = max(0, d - r);
        int nr = min(d - l, nd);
        if(nl < nr) {
            ans++;
            l = nl;
            r = nr;
        } else {
            l = 0;
            r = nd;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) solve();
} 