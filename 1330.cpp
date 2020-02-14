#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ii long long


#define pb push_back
#define pii pair<char,ii>
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
vector <vector<pii>> a(250,vector<pii>(250, {' ',-1}));
vector <ii> g[10015];
void sos(ii i,ii j)
{
    if (a[i][j+1].F!='1'&&a[i][j+1].S!=-1)
    {
        g[a[i][j].S].pb(a[i][j+1].S);
    }
    if (j!=0 && a[i][j-1].F!='1'&&a[i][j-1].S!=-1)
    {
        g[a[i][j].S].pb(a[i][j-1].S);
    }
    if (i!=0 && a[i-1][j].F!='1'&&a[i-1][j].S!=-1)
    {
        g[a[i][j].S].pb(a[i-1][j].S);
    }
    if (a[i+1][j].F!='1'&&a[i+1][j].S!=-1)
    {
        g[a[i][j].S].pb(a[i+1][j].S);
    }
}


ii k=-1;
ii BFS (ii s,ii f)
{
    queue <ii> q;
    vector <ii> p(k+1,-1);


    q.push(s);
    p[s]=0;

    while (!q.empty())
    {
//    cout<<q.size()<<endl;

        ii v=q.front();
        q.pop();
        if (g[v].size()!=0)
        for (auto to:g[v])
        {

            if (p[to]==-1)
            {
                p[to]=p[v]+1;
                q.push(to);
            }
        }
    }

    if (p[f]==-1)
        return MOD;
    else
        return p[f];


}
ii n,m;
ii BFS1 (ii s,ii f)
{
    queue<int> q;
q.push (s);
vector<bool> used (k+1);
vector<int> d (k+1), p (k+1);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
	int v = q.front();
	q.pop();
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			used[to] = true;
			q.push (to);
			d[to] = d[v] + 1;
			p[to] = v;
		}
	}
}
if (!used[f])
	cout << "-1";
else {
	vector<int> path;
	for (int v=f; v!=-1; v=p[v])
		path.pb(v);
	reverse (path.begin(), path.end());
	cout<<path.size()-1<<endl;
	for (size_t o=1; o<path.size(); ++o)
		{
		    ii f1=0;
		     for (ii i = 0 ; i < n; i++){
        for (ii j =0 ; j < m; j++)
        {
            if (a[i][j].S==path[o]){cout<<i+1<<' '<<j+1<<endl;f1=1;break;}
        }
        if (f1==1)break;
		     }
		}
}
}






main ()
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef zimka

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else

// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif

    cin >> n;

    cin >> m;
    ii f=0;
    for (ii i = 0 ; i < n; i++)
        for (ii j =0 ; j < m; j++)
        {
            k++;
            cin >> a[i][j].F;
            a[i][j].S=k;
            if (a[i][j].F=='*')
                f=k;
        }
//cout<<f<<endl;
//for (ii i = 0 ;i < n; i++){
//    for (ii j =0 ;j < m;j++)
//{
//    cout<<a[i][j].F<<'/'<<a[i][j].S<<' ';
//}
//cout<<endl;
//}
    for (ii i = 0 ; i < n; i++)
        for (ii j =0 ; j < m; j++)
        {
            if (a[i][j].F!='1')
                sos(i,j);
        }
//    for (ii i = 0 ; i < k; i++)
//    {
//        cout<<i+1<<':'<<' ';
//        for (ii j =0 ; j < g[i].size(); j++)
//        {
//            cout<<g[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    ii h;
    cin >> h;

    pair<ii,pair<ii,ii>> ans={MOD,{0,0}};
    for (ii i = 0; i < h; i++)
    {
        ii x,y;
        cin >> x >> y;
        x--;
        y--;
         ii t=BFS(a[x][y].S,f);
        if (min(ans.F,t)!=ans.F){ans.F=t;ans.S.F=x;ans.S.S=y;}
//cout<<a[x][y].S<<endl;
    }

  BFS1(a[ans.S.F][ans.S.S].S,f);

}

