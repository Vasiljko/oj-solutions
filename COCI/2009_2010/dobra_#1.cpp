#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 105;

int m,n;
int t[N];
ll ans;
bool exist[N];
string s;
vector<int>v;

bool vow(char c){
    return c=='A'||c=='E'||c=='U'||c=='I'||c=='O';
}

void rec(int ind){
    if(ind==v.size()){
        ll res=1;
        bool ok=false,ok2=false;
        bool bad=false;
        for(int i=1;i<=n;i++){
            if(!exist[i]){
                if(t[i]==0)res*=5LL;
                else if(t[i]==1)ok=true;
                else res*=20LL;
            }else{
                if(s[i]=='L')ok2=true;
            }
            if(i>=3){
                if(t[i]==0&&t[i-1]==0&&t[i-2]==0)bad=true;
                else if(t[i]>=1&&t[i-1]>=1&&t[i-2]>=1)bad=true;
            }
        }

        if(bad)return;
        if(ok||ok2)ans+=res;
    }else{
        t[v[ind]]=0;
        rec(ind+1);
        t[v[ind]]=1;
        rec(ind+1);
        t[v[ind]]=2;
        rec(ind+1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.length();
    s="#"+s;
    for(int i=1;i<=n;i++){
        if(s[i]!='_'){
            if(vow(s[i]))t[i]=0;
            else if(s[i]=='L')t[i]=1;
            else t[i]=2;
            exist[i]=true;
        }else{
            v.push_back(i);
        }
    }
    if(v.empty()){
        cout<<1;
        return 0;
    }
    rec(0);

    cout<<ans;
    return 0;
}
