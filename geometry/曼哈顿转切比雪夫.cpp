#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define vst vector<bool>
#define pii pair<long long, long long>
#define ll long long
#define vpi vector<pair<int, int>>
#define vpii vector<vector<pair<int, int>>>
#define eb emplace_back
#define pb push_back
#define ep emplace
#define ps push
#define endl '\n'
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define F(i, a, b) for(int i = a; i <= b; i++)
#define F2(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a, b, c) for(int i = a; i <= b; i+=c)
#define drep(i, a, b, c) for(int i = a; i >= b; i -= c)
#define DF(i, a, b) for(int i = a; i >= b; i--)
#define int long long
using namespace std;
const int N = 2e5+10;
const int inf = 2e9;
const long long llf = 9e18;
int T = 1;
struct SEG {
    #define ls p << 1
    #define rs p << 1 | 1
    pii tr[N << 2]; // min max
    pii merge(pii a, pii b) {
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    void update(int p, int l, int r, int x, int val) {
        if(l == r) {
            tr[p] = {val, val};
            return;
        }
        int mid = l + r >> 1;
        if(x <= mid) update(ls, l, mid, x, val);
        else if(x > mid) update(rs, mid + 1, r, x, val);
        tr[p] = merge(tr[ls], tr[rs]);
    }
    pii query(int p, int l, int r, int L, int R) {
        if(l >= L and r <= R) {
            return tr[p];
        }
        int mid = l + r >> 1;
        if(R <= mid) return query(ls, l, mid, L, R);
        else if(L > mid) return query(rs, mid + 1, r, L, R);
        else return merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
    }
} x, y;
void solve() {
    /*  
        A(x1, y1) B(x2, y2)
        曼哈顿距离dis(A, B) abs(x1 - x2) + abs(y1 - y2)
        那么A(x1, y1)B(x2, y2)的曼哈顿距离 
        就是A'(x1 + y1, x1 - y1) B'(x2 + y2, x2 - y2)的切比雪夫距离 max(abs(A'x - B'x), abs(A'y, B'y))
        主要在于可以消去一个等号
        如果要从1到n求和 dis(a, b) 不好算 那么可以转换成切比雪夫距离看最大值 可以不具体算dis(a,b)
        例题https://atcoder.jp/contests/abc437/tasks/abc437_f
    */

    /*
        该题是求max(从l到r abs(xi - x)+abs(yi-y)))
        转换为切比雪夫
        max(从l到r max(abs(x'i - x), abs(y'i - y)))
        可见 对于每个点 因为x和y是不变的 我只要找出来四个极端情况 因为内层从l到r max只可能在x'i 最小或最大 y'i最小或最大的时候取到
        因为要找的是 xi离x最远的 或者yi离y最远的
        所以 我们维护一下从l到r到x最大最小 y最大最小 点修区查线段树
    */
    int n, q; cin>>n>>q;
    F(i, 1, n) {
        int xx, yy; cin>>xx>>yy;
        int nx = xx + yy;
        int ny = xx - yy;
        xx = nx;
        yy = ny;
        x.update(1, 1, n, i, xx);
        y.update(1, 1, n, i, yy);
    }
    while(q--) {
        int op; cin>>op;
        if(op == 1) {
            int t, xx, yy; cin>>t>>xx>>yy;
            int nx = xx + yy;
            int ny = xx - yy;
            xx = nx;
            yy = ny;
            x.update(1, 1, n, t, xx);
            y.update(1, 1, n, t, yy);
        } else {
            int l, r, xx, yy; cin>>l>>r>>xx>>yy;
            int nx = xx + yy;
            int ny = xx - yy;
            xx = nx;
            yy = ny;
            auto [min_x, max_x] = x.query(1, 1, n, l, r);
            auto [min_y, max_y] = y.query(1, 1, n, l, r);
            cout<<max({abs(min_x - xx), abs(min_y - yy), abs(max_x - xx), abs(max_y - yy)})<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    while(T--) solve();
} 