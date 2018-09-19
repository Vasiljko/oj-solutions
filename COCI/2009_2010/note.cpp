#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 10;

int a[N];
bool des,inc;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<=8;i++)cin>>a[i];

    for(int i=2;i<=8;i++){
        if(a[i]>a[i-1])inc=true;
        else if(a[i]<a[i-1])des=true;
    }

    if(inc&&des)cout<<"mixed";
    else if(inc)cout<<"ascending";
    else cout<<"descending";

    return 0;
}
