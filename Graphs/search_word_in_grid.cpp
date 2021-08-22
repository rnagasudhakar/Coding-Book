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
string str, path = "", ans = "";
bool vis[1000][1000];
ll dx[4] = {0, 1, -1, 0};
ll dy[4] = {1, 0, 0, -1};
bool isValid(ll r, ll c, ll n, vector<vector<char>> &grid, char ch)
{
	return (r<n and r >= 0 and c<n and c >= 0 and vis[r][c] == false and grid[r][c] == ch);
}
void dfs(ll x, ll y, ll n, ll len, ll idx, string word, vector<vector<char>> &grid)
{

	ans += grid[x][y];
	//cout << ans << '\n';
	path += to_string(x + 1) + to_string(y + 1);
	vis[x][y] = true;
	if (idx == len - 1)
	{
		// cout << "yes ";
		// cout << path << '\n';
		return;
	}
	fr(i, 0, 4)
	{
		ll X = x + dx[i];
		ll Y = y + dy[i];
		if (isValid(X, Y, n, grid, word[idx + 1]))dfs(X, Y, n, len, idx + 1, word, grid);
	}
}
void solve()
{
	ll n;
	cin >> n;
	string str;
	cin >> str;
	vector<vector<char>> s(n, vector<char>(n));
	fr(i, 0, n)
	{
		fr(j, 0, n)cin >> s[i][j];
	}

	fr(i, 0, n)
	{
		fr(j, 0, n)
		{
			if (s[i][j] == str[0])dfs(i, j, n, str.S, 0, str, s);
		}
	}
	if (ans != str)cout << "no";
	else
	{
		cout << "yes ";
		cout << path << '\n';
	}
}

signed main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
	ll t = 1;
//	cin >> t;
	fr(i, 0, t)
	{
		solve();
	}
}