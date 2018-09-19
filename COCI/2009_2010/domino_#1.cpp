#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int n;
ll s1,s2;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;

    for(int i=0;i<=n;i++){
        s1+=1LL*(n+1-i)*i;
    }

    for(int i=1;i<=n;i++){
        s2+=1LL*n*(n+1)/2-1LL*i*(i-1)/2;
    }

    cout<<s1+s2+1LL*n*(n+1)/2;

    return 0;
}
