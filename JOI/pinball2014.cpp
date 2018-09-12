/*
  idea:
  https://github.com/SpeedOfMagic/CompetitiveProgramming/blob/master/JOIOC/14-pinball.cpp
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll INF = 1e18+10;
const int N = 1e5+5;

ll n;
int m,original[3*N];
ll a[N],b[N],c[N],d[N],dpl[N],dpr[N],tree[13*N];
unordered_map<ll,int>mp;
set<ll>s;

void resetTree(){
    for(int i=0;i<13*N;i++)tree[i]=INF;
}

void Set(int c,ll ss,ll se,ll ind,ll val){
    if(ss==se){
        tree[c]=min(tree[c],val);
        return;
    }
    ll mid=(ss+se)>>1LL;
    if(ind<=mid)Set(c<<1,ss,mid,ind,val);
    else Set(c<<1|1,mid+1,se,ind,val);

    tree[c]=min(tree[c<<1],tree[c<<1|1]);
}

ll Get(int c,ll ss,ll se,ll qs,ll qe){
    if(qs>se||qe<ss||ss>se)return INF;
    if(qs<=ss&&se<=qe)return tree[c];

    ll mid=(ss+se)>>1LL;

    return min(Get(c<<1,ss,mid,qs,qe),Get(c<<1|1,mid+1,se,qs,qe));
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        s.insert(a[i]);
        s.insert(b[i]);
        s.insert(c[i]);
    }
    int cnt=0;
    for(auto e:s){
        mp[e]=++cnt;
    }

    ll ans=INF;

    resetTree();
    for(int i=1;i<=m;i++){
        if(a[i]==1){
            dpl[i]=d[i];
            Set(1,1,cnt,mp[c[i]],dpl[i]);
        }else{
            dpl[i]=INF;
            dpl[i]=min(dpl[i],d[i]+Get(1,1,cnt,mp[a[i]],mp[b[i]]));
            Set(1,1,cnt,mp[c[i]],dpl[i]);
        }
    }

    resetTree();

    for(int i=1;i<=m;i++){
        if(b[i]==n){
            dpr[i]=d[i];
            Set(1,1,cnt,mp[c[i]],dpr[i]);
        }else{
            dpr[i]=INF;
            dpr[i]=min(dpr[i],d[i]+Get(1,1,cnt,mp[a[i]],mp[b[i]]));
            Set(1,1,cnt,mp[c[i]],dpr[i]);
        }
    }

    for(int i=1;i<=m;i++)ans=min(ans,dpl[i]+dpr[i]-d[i]);
    if(ans==INF)ans=-1;

    cout<<ans;
    return 0;
}
