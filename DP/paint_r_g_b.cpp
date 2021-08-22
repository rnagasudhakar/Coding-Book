// Problem Link -
/* By Bhanu Prakash */
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9 + 7)
#define inf 1e18
#define fr(i, x, y) for (ll i = x; i < y; i++)
#define dr(i, x, y) for (ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define mapcl map<char, ll>
#define mapll map<ll, ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string, ll>
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define vii vector<pii>
#define vvi vector<vi>
#define vvii vector<vii>
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
const ll N = (ll)(1 * 1e6 + 5);

void solve()
{
    ll n;
    cin >> n;
    ll a[n][3];
    fr(i, 0, n)
    {
        fr(j, 0, 3)
        {
            cin >> a[i][j];
        }
    }
    ll dp[n][3];
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    fr(i, 1, n)
    {
        dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}

signed main()
{
    fast();
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t = 1;
    //cin >> t;
    fr(i, 0, t)
    {
        solve();
    }
}