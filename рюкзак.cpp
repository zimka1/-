#include <bits/stdc++.h>
#define ii long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>#define ii long long
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
vector <ii> dp(10000007,MOD);
main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef zimka

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else

        //freopen("input.txt","r",stdin);
       // freopen("output.txt","w",stdout);
#endif
ii n;
ii mv;
cin >> n;
cin >> mv;
vector <pair<ii,ii>> a(n,{0,0});
for (ii i = 0; i <n;i++)
    cin >> a[i].F>>a[i].S;
    dp[0]=0;
    ii m = 1000000;
for (ii i = 0; i <n;i++)
{
    for (ii j=m;j>=0;j--)
    {
        if (j!=MOD)
        dp[j+a[i].S]=min(dp[j+a[i].S],dp[j]+a[i].F);
    }

}

// for (ii i =0 ; i <100;i++)
//    cout<<dp[i]<<' ';
//    cout<<endl;
ii mx=0;

for (ii i = 0; i < m;i++)
{
    if (dp[i]<=mv) mx=max(mx,i);
}
cout<<mx;
}
