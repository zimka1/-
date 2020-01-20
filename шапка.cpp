
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ii long long
#define ld long double
#define pb push_back
#define pii pair<ii,ii>
#define check find_by_order
#define orok order_of_key
#define F first
#define S second
#define MOD 1000000007
using namespace std;

using namespace __gnu_pbds;

typedef tree<
ii,
null_type,
less<ii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=1e5 +100;

char p[N][3];

main () {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef zimka

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else

    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
#endif
