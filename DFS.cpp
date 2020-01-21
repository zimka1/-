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
ii n,m,ves;
cin >> n >> m >> ves;
vector <ii> g[n];
for (ii i = 0; i < m;i++)
{
    ii x,y,z;
    cin >> x >> y >> z;
    x--;
    y--;
    if (ves<=z)
    {
    g[x].pb(y);
    g[y].pb(x);
    }
}
//for (ii i = 0; i <n ;i++)
//{
//    for (ii j = 0;j < g[i].size(); j++)
//    {
//        cout<<g[i][j]<<' ';
//    }
//    cout<<endl;
//}
//cout<<endl;
queue <ii> q;
vector <ii> p(n,-1);
ii s = 0, f = n - 1;

q.push(s);
p[s]=0;

while (!q.empty())
{
//    cout<<q.size()<<endl;
    ii v=q.front();
    q.pop();
    for (auto to:g[v])
    {
        if (p[to]==-1)
        {
        p[to]=p[v]+1;
        q.push(to);
        }
    }
}
 if (p[f] == -1) cout << "NO";
    else cout << "YES";
}
