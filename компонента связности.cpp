
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
const int N=102;

char p[N][3];
vector <ii> g[N];
bool used[N];
vector<int> comp;
ii n,m;
void  dfs(ii v)
{
    used[v]=true;
    comp.pb(v);
    for (auto to:g[v])
    {
       if (!used[to]) dfs(to);
    }
}
ii find_comp()
{
  for (ii i = 0; i <n ;i++)
  {
      used[i]=false;

  }
  for (ii i = 0; i <n ;i++)
  {
      if (!used[i])
      {
          comp.clear();
          dfs(i);
          return comp.size();
      }
  }
}
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

cin >> n;

cin >> m;
for (ii i = 0; i < m; i++)
{
ii x,y;
cin >> x >> y;
g[x].pb(y);
g[y].pb(x);
}
ii s;
s=find_comp();
cout<<m-n+1+s;
}
