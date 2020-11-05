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

vector <ii> t(4000000);
//void build (ii v,ii vl,ii vr,ii a[])
//{
//    if (vl==vr)
//    {
//        t[v]=a[vl];
//        t[v]%=1337;
//        return;
//    }
//    if (vl > vr) return ;
//    ii mid=vl+(vr-vl)/2;
//    build(2*v+1,vl,mid,a);
//    build(2*v+2,mid+1,vr,a);
//    t[v] = t[v*2 + 2] + t[v*2+1];
//    t[v]%=1337;
////    t[v]=max(t[2*v+1],t[2*v+2]);
//
//}
ii sum(ii v,ii vl,ii vr,ii l,ii r)
{
    if (r<vl||vr<l || vl > vr)
    {
        return 0;
    }
    if (l<=vl&&vr<=r)
    {
        return t[v];
    }
    ii mid =(vl + vr)/2;
    return (sum(v*2,vl,mid,l,r) + sum(v*2+1,mid+1,vr,l,r))%1337;

}
void upd (ii v, ii val)
{
    t[v] = val;
    v /= 2;
    while(v){
        t[v] = t[v * 2] + t[v * 2 + 1];
        v /= 2;
    }

}

int main ()
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ii n;
    cin >> n;
    ii q;
    cin >> q;
    ii a[n];
    ii st = 1;
    while (st < n)
    {
        st*=2;
    }
    for (ii i = 0; i < n ; i++)
    {
        cin >> a[i];
        t[i+st] = a[i];
    }
    for (ii i = st - 1; i >= 0; i--)
    {
        t[i] = t[i*2] + t[i*2+1];
        t[i]%=1337;
    }
    for (ii i = 0; i <q; i++)
    {
        string c;
        cin >> c;
        if (c=="sum")
        {
            ii l,r;
            cin >> l >> r;
            l--;
            r--;
            ii s = sum(1,0,st-1,l,r);
            cout<<(((s*(s+1))/2)%1337)*(((s*(s+1))/2)%1337) % 1337<<endl;
        }
        else
        {
            ii pos,val;
            cin >> pos>> val;
            pos--;
            upd(pos + st, val);
        }
    }
}
