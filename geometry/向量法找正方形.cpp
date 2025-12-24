#include<bits/stdc++.h>
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define vst vector<bool>
#define pii pair<int, int>
#define ll long long
#define vpi vector<pair<long long, long long>>
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
    int n; cin>>n;
    vpi a(n);
    for(auto &[x, y] : a) {
        cin>>x>>y;
    }
    set<pii> st(a.begin(), a.end());
    int res = 0;
    F(i, 0, n - 1) {
        F(j, i + 1, n - 1) { // 为了枚举 ab 后不再枚举 ba 所以从i + 1 开始 
                             // 如果从0开始 答案就要 res / 8; 
            auto [x1, y1] = a[i];
            auto [x2, y2] = a[j];
            ll dx = x2 - x1;
            ll dy = y2 - y1;
            // (dx, dy)逆时针时针旋转90 => (-dy , dx). 顺时针旋转90 (dy, -dx) 

            //之后求 cd点 将a看做原点 最后加上a点偏移量即可
            /*
            已知 A(x1, y1) 和 B(x2, y2)，向量 AB = (dx, dy)，其中 dx = x2 - x1, dy = y2 - y1。
            利用向量旋转 90 度寻找正方形另外两点。
            */

            // 情况一：正方形在向量 AB 左侧（逆时针旋转 90 度）
            // 向量 AD 是 AB 逆时针旋转 90 度得到：AD = (-dy, dx)
            
            // 1. 求 D 点坐标 (A + AD):
            // Dx = x1 + (-dy) = x1 - dy
            // Dy = y1 + dx
            // -> 对应代码：st.find({x1 - dy, y1 + dx})
            
            // 2. 求 C 点坐标 (B + AD，即 A + AB + AD):
            // Cx = x1 + dx + (-dy) = x1 + dx - dy
            // Cy = y1 + dy + dx    = y1 + dx + dy
            // -> 对应代码：st.find({x1 + dx - dy, y1 + dx + dy})

            // x1 + dx = x2   y1 + dy = y2 代码中作了简化
            if(st.find({x1 - dy, y1 + dx}) != st.end() and st.find({x2 - dy, y2 + dx}) != st.end()) res++;
            
            // 情况二：正方形在向量 AB 右侧（顺时针旋转 90 度）
            // 向量 AD' 是 AB 顺时针旋转 90 度得到：AD' = (dy, -dx)
            
            // 1. 求第一个点坐标 (A + AD'):
            // x = x1 + dy
            // y = y1 + (-dx) = y1 - dx
            // -> 对应代码：st.find({x1 + dy, y1 - dx})
            
            // 2. 求第二个点坐标 (B + AD'):
            // x = (x1 + dx) + dy = x1 + dx + dy
            // y = (y1 + dy) + (-dx) = y1 + dy - dx
            // -> 对应代码：st.find({x1 + dx + dy, y1 + dy - dx})

            // x1 + dx = x2   y1 + dy = y2 代码中作了简化
            if(st.find({x1 + dy, y1 - dx}) != st.end() and st.find({x2 + dy, y2 - dx}) != st.end()) res++;
        }
    }
    cout<<res / 4<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>T;
    while(T--) solve();
} 