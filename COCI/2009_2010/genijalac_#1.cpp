#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 5e+5;

int n,c,d;
int cyc[N],perm[N];
bool vis[N];
ll a,b;

int  dfs(int s,int len){
    if(vis[s])return len-1;
    vis[s]=true;
    cyc[s]=dfs(perm[s],len+1);
    return cyc[s];
}

ll gcd(ll a,ll b){
    while(b){
        ll tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

ll lcm(ll fi,ll se){
    return fi/gcd(fi,se)*se;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>a>>b>>c>>d;
    for(int i=1;i<=n;i++)cin>>perm[i];

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,1);
        }
    }

    ll val=1;
    for(int i=c+1;i<=n-d;i++){
        val = lcm(val,cyc[i]);
    }
    ll up=(b-1)/val;
    ll down=(a-1+val-1)/val;

    cout<<max(0LL,up-down+1LL);
    return 0;
}
