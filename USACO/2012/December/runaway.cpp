#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 2e5+5;
const int LOG = 18;

int n,a[N],par[N][LOG];
ll k,d[N];
vector<pair<int,ll> >v[N];

void dfs(int s,int p,ll dep){
    par[s][0]=p;
    d[s]=dep;
    for(int i=1;i<LOG;i++)if(par[s][i-1]!=-1)par[s][i]=par[par[s][i-1]][i-1];
    for(auto e:v[s]){
        if(e.first!=p){
            dfs(e.first,s,dep+e.second);
        }
    }
}

void dfs2(int s,int p){
    for(auto e:v[s]){
        if(e.first!=p){
            dfs2(e.first,s);
            a[s]+=a[e.first];
        }
    }
}

int main()
{
    ifstream fin("runaway.in");
    ofstream fout("runaway.out");

    memset(par,-1,sizeof(par));
    fin>>n>>k;
    int x;
    ll y;

    for(int i=1;i<=n-1;i++){
        fin>>x>>y;
        v[i+1].push_back({x,y});
        v[x].push_back({i+1,y});
    }

    dfs(1,-1,0);

    for(int i=1;i<=n;i++){
        int anc=i;
        ll prevsum=0;
        for(int j=LOG-1;j>=0;j--){
            if(par[anc][j]==-1)continue;
            if(d[i]-d[par[anc][j]]<=k)anc=par[anc][j];
        }
        a[i]++;
        if(par[anc][0]!=-1)a[par[anc][0]]--;
    }

    dfs2(1,-1);
    for(int i=1;i<=n;i++)fout<<a[i]<<"\n";
    return 0;
}
