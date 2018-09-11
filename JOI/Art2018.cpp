/*
   if arts are sorted by A value, then if we take some indexes i and j such that A[i]=Amax and A[j]=Amin then we will take all arts with
   sizes between A[i] and A[j] , so values of that is P[i]-P[j-1] where P[] is array of partial sums
   we can find optimal j with set structure or something else

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 5e5+5;

ll a[N],p[N];
int n;
set<ll>s;

struct art{
    ll A,B;
    bool operator < (const art &rhs) const{
        return A<rhs.A;
    }
}d[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i].A>>d[i].B;

    sort(d+1,d+1+n);

    s.insert(-d[1].A);
    ll ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,d[i].B);
        p[i]=p[i-1]+d[i].B;
    }

    for(int i=2;i<=n;i++){
        ll val=*(s.begin());
        ans=max(ans,p[i]-d[i].A-val);
        s.insert(p[i-1]-d[i].A);
    }
    cout<<ans;
    return 0;
}
