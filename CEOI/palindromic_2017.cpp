#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int t;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;

    while(t--){
        cin>>s;
        int i=0;
        int j=(int)s.size()-1;
        int ans=0;

        while(i<=j){
            ll hash1=0,hash2=0;
            ll p=31;
            ll pp=1;
            int ok=-1;
            for(int len=1;i+len-1<j-len+1;len++){
                hash1+=pp*(s[i+len-1]-'a')%MOD;
                hash1%=MOD;
                hash2*=p;
                hash2+=(s[j-len+1]-'a');
                hash2%=MOD;
                pp*=p;
                pp%=MOD;
                if(hash1==hash2){
                    ok=len;
                    break;
                }
            }
            if(ok==-1){
                ans++;
                break;
            }else{
                ans+=2;
            }
            i+=ok;
            j-=ok;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
