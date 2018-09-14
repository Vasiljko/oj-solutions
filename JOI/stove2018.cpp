#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e5+5;

int n,k;
ll t[N];
vector<ll>v;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }

    ll ans=t[n]+1-t[1];

    for(int i=2;i<=n;i++){
        v.push_back(t[i]-t[i-1]-1);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    k--;
    for(auto e:v){
        if(k){
            k--;
            ans-=e;
        }
    }

    cout<<ans;
    return 0;
}
