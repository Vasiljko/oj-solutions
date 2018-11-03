#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 50;

int n;
ll m,a[N],b[N],ans;
vector<ll>S1,S2;

void Fill(vector<ll>&S,int ind,int len,ll sum){
    if(ind==len+1){
        S.push_back(sum);
        return;
    }
    Fill(S,ind+1,len,sum);
    if(sum+b[ind]<=m)Fill(S,ind+1,len,sum+b[ind]);
}

void Gen(vector<ll>&S,int len){
    Fill(S,1,len,0);
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(n==1){
        if(a[1]<=m)cout<<2;
        else cout<<1;
        return 0;
    }

    int len=n/2;

    for(int i=1;i<=n/2;i++)b[i]=a[i];
    Fill(S1,1,len,0);
    for(int i=n/2+1;i<=n;i++)b[i-n/2]=a[i];
    Fill(S2,1,n-len,0);

    sort(S1.begin(),S1.end());
    sort(S2.begin(),S2.end());
    reverse(S2.begin(),S2.end());

    int prev=0;
    for(auto e:S2){
        ll val=m-e;
        int l=prev;
        int r=(int)S1.size()-1;
        int sol=0;

        while(l<=r){
            int mid=(l+r)>>1;
            if(S1[mid]<=val){
                sol=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        prev=sol;
        ans+=1LL*(sol+1);
    }

    cout<<ans;
    return 0;
}
