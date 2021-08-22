// Problem Link - https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
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
class Node {
public:
	ll data;
	Node* left, *right;
	Node(ll d)
	{
		data = d;
		left = right = NULL;
	}
};
struct info
{
	bool balance;
	ll height;
};
info heightBalanceCheck(Node* root)
{
	if (root == NULL)return {true, 0};
	info l = heightBalanceCheck(root->left);
	info r = heightBalanceCheck(root->right);
	if (l.balance and r.balance and abs(l.height - r.height) <= 1)
	{
		info res;
		res.balance = true;
		res.height = 1 + max(l.height, r.height);
		return res;
	}
	else
	{
		info res;
		res.balance = false;
		res.height = 1 + max(l.height, r.height);
		return res;
	}
}
void solve()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	// root->right->left = new Node(6);
	root->left->left->left = new Node(8);

	cout << heightBalanceCheck(root).balance << '\n';
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