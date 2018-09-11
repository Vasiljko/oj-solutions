/*
  http://hsin.hr/coci/archive/2006_2007/
  idea is same as in the solution from link above
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

stack<pair<int,int> >S;
int n;
int x;
ll ans;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        pair<int,int>el={x,1};
        while(!S.empty()&&x>=S.top().first){
            ans+=S.top().second;
            if(S.top().first==x)el.second+=S.top().second;
            S.pop();
        }
        if(!S.empty())ans++;
        S.push(el);
    }

    cout<<ans;
    return 0;
}
