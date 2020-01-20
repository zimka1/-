#include <bits/stdc++.h>

#define ii long long
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

//░░▄███▄███▄
//░░█████████
//░░▒▀█████▀░
//░░▒░░▀█▀
//░░▒░░█░
//░░▒░█
//░░░█
//░░█░░░░███████
//░██░░░██▓▓███▓██▒
//██░░░█▓▓▓▓▓▓▓█▓████
//██░░██▓▓▓(◐)▓█▓█▓█
//███▓▓▓█▓▓▓▓▓█▓█▓▓▓▓█
//▀██▓▓█░██▓▓▓▓██▓▓▓▓▓█
//░▀██▀░░█▓▓▓▓▓▓▓▓▓▓▓▓▓█
//░░░░▒░░░█▓▓▓▓▓█▓▓▓▓▓▓█
//░░░░▒░░░█▓▓▓▓█▓█▓▓▓▓▓█
//░▒░░▒░░░█▓▓▓█▓▓▓█▓▓▓▓█
//░▒░░▒░░░█▓▓▓█░░░█▓▓▓█
//░▒░░▒░░██▓██░░░██▓▓██


using namespace std;

vector <pair<ii,ii>> t(400000,{0,0});
void build (ii v,ii vl,ii vr,ii a[])
{
    if (vl==vr)
    {
        t[v].F=a[vl];
        t[v].S=vl;
        return;
    }
    ii mid=vl+(vr-vl)/2;
    build(2*v+1,vl,mid,a);
    build(2*v+2,mid+1,vr,a);
    if (t[2*v+1].F>=t[2*v+2].F)t[v]=t[2*v+1];
    else
        t[v]=t[2*v+2];
//    t[v]=max(t[2*v+1],t[2*v+2]);

}
pair<ii,ii> qe(ii v,ii vl,ii vr,ii l,ii r)
{
if (r<vl||vr<l)
{
    return {-1e9,-1};
}
if (l<=vl&&vr<=r)
{
    return t[v];
}
ii mid =vl+(vr-vl)/2;
pair<ii,ii> ql = qe(2*v+1,vl,mid,l,r);
pair<ii,ii> qr = qe(2*v+2,mid+1,vr,l,r);
if (ql.F>=qr.F)
    return ql;
else
    return qr;

}
void mod (ii v, ii vl, ii vr, ii pos, ii val)
{
    if (vl==vr){
        t[v].F=val;
        return;
    }
    ii mid = vl+(vr-vl)/2;
    if (pos<=mid)
        mod (2*v+1,vl,mid,pos,val);
    else
        mod (2*v+2,mid+1,vr,pos,val);
       if (t[2*v+1].F>=t[2*v+2].F)t[v]=t[2*v+1];
    else
        t[v]=t[2*v+2];

}

int main () {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
ii n;
cin >> n;
ii a[n];
for (ii i = 0; i < n ;i++)
{
    cin >> a[i];
}
build (0,0,n-1,a);
ii q;
cin >> q;
for (ii i = 0; i <q;i++ )
{
    char c;
    cin >> c;
    if (c=='s')
        {
    ii l,r;
    cin >> l >> r;
    l--;
    r--;
        cout<<qe(0,0,n-1,l,r).S+1<<' ';
        }
    else
    {
        ii pos,val;
        cin >> pos>> val;
        pos--;
        mod(0,0,n-1,pos,val);
    }
}
}
