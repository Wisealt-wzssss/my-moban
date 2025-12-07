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
    vl lcm_cnt(n + 1, 0);
    F(i, 1, n) {
        Fc(j, i, n, i) {
            gcd_cnt[i] += cnt[j];
            lcm_cnt[j] += cnt[i];
        }
    }
    F(i, 0, n) {
        gcd_cnt[i] = gcd_cnt[i] * (gcd_cnt[i] - 1);
        lcm_cnt[i] = lcm_cnt[i] * (lcm_cnt[i] - 1);
    }
    DF(i, n, 1) {
        Fc(j, i * 2, n, i) {
            gcd_cnt[i] -= gcd_cnt[j];
        }
    }
    //求lcm_cnt的时候 就不需要倒序号 因为所有的都反过来了 现在是大的需要小的来更新(关系在于倍数数量)
    F(i, 1, n) {
        Fc(j, i * 2, n, i) {
            lcm_cnt[j] -= lcm_cnt[i];
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
/*
    example question:
    https://codeforces.com/gym/106241/problem/F

    主要解决如何计算出 gcd和lcm等于x的对数 同时还需要x的倍数和因数出现了多少次
    之后再通过容斥原理 就可以统计处 使得ijkt gcd lcm相等的下标
    这个题主要难点在于 ijkt下标不能重复 所以我们统计处gcd lcm 的cnt后不能直接用 因为还有可能有等于x的数字 这样会导致ijkt重复
    所以我们先去掉ijkt 之后再手动计算 有0个x 有1个x... 的时候

    void solve() {
    int n; cin>>n;
    vi a(n + 1), cnt(n + 1, 0);
    F(i, 1, n) cin>>a[i], cnt[a[i]]++;
    vl gcd_cnt(n + 1, 0), lcm_cnt(n + 1, 0);
    F(i, 1, n) {
        FC(j, i, n, i) {
            gcd_cnt[i] += cnt[j];
            lcm_cnt[j] += cnt[i];
        }
    }
    vl fac_cnt = gcd_cnt, times_cnt = lcm_cnt;
    F(i, 1, n) {
        gcd_cnt[i] = gcd_cnt[i] * (gcd_cnt[i] - 1);
        lcm_cnt[i] = lcm_cnt[i] * (lcm_cnt[i] - 1);
    }
    DF(i, n, 1) {
        FC(j, i * 2, n, i) {
            gcd_cnt[i] -= gcd_cnt[j];
        }
    }
    F(i, 1, n) {
        FC(j, i * 2, n, i) {
            lcm_cnt[j] -= lcm_cnt[i];
        }
    }
    F(i, 1, n) {
        fac_cnt[i] -= cnt[i];
        times_cnt[i] -= cnt[i];

        gcd_cnt[i] = (gcd_cnt[i] - ((fac_cnt[i] * cnt[i] % mod) * 2 % mod) - (cnt[i] * (cnt[i] - 1) % mod) + mod) % mod;
        lcm_cnt[i] = (lcm_cnt[i] - ((times_cnt[i] * cnt[i] % mod) * 2 % mod) - (cnt[i] * (cnt[i] - 1) % mod) + mod) % mod;
    }
    int ans = 0;
    F(i, 1, n) {
        ans += gcd_cnt[i] * lcm_cnt[i];
        ans %= mod;
        ans += (cnt[i] * fac_cnt[i] % mod)* lcm_cnt[i] % mod * 2 % mod;
        ans %= mod;
        ans += gcd_cnt[i] * (cnt[i] * times_cnt[i] % mod) % mod * 2 % mod;
        ans %= mod;
        ans += cnt[i] * (cnt[i] - 1) % mod * lcm_cnt[i] % mod;
        ans %= mod;
        ans += cnt[i] * (cnt[i] - 1) % mod * gcd_cnt[i] % mod;
        ans %= mod;
        ans += cnt[i] * fac_cnt[i] % mod * (cnt[i] - 1) * times_cnt[i] % mod * 4 % mod;
        ans %= mod;
        ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * fac_cnt[i] % mod * 2 % mod;
        ans %= mod;
        ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * times_cnt[i]  % mod * 2 % mod;
        ans %= mod;
        ans += cnt[i] * (cnt[i] - 1) % mod * (cnt[i] - 2) % mod * (cnt[i] - 3) % mod;
        ans %= mod;
    }
    cout<<ans<<endl;
}
*/