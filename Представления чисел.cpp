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
    ii n;
    cin >> n;
    ii d;
    cin >> d;
    ii x=n;
    ii t=0;
    if (d==1) {
        d=2;
        t=1;
    }
    string s="";
    while (x!=0) {
        s+=to_string(x%d);
        x/=d;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    string ans="";
    string s2="";
    for (ii i = 0 ; i < s.size(); i++) {
        string s1="";
        s1+=s[i];
        ii y=atoi(s1.c_str());
        if (i==s.size()-1)
            continue;
        if (t==1)
            d=1;
        if (i==0) {
            if (t==1) {
                ans += '(';
                ans += to_string(d);
                ans += '+';
                ans += to_string(d);
                ans += ')';
            } else
                ans+=to_string(d);

        } else {
            if (t==1) {
                ans += '*';
                ans += '(';
                ans += to_string(d);
                ans += '+';
                ans += to_string(d);
                ans += ')';
            } else {
                ans +='*';
                ans += to_string(d);
            }
            while (y != 0) {
                if (t==1) {
                    ans += '+';
                    ans += '(';
                    ans += to_string(d);
                    ans += '+';
                    ans += to_string(d);
                    ans += ')';
                }

                else {
                    ans +='+';
                    ans += to_string(d);
                }
                y--;
            }
        }
        ans += ')';

        s2+='(';
    }
    cout<<s2+ans;
    if (t==1&&n%2!=0)
        cout<<"+1";
}
