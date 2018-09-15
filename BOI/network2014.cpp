/*
  iterate over distance to b and check if current node and last one are adjacent
*/

#include <bits/stdc++.h>
#include "network.h"
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1005;

vector<int>v[N];

void findRoute(int n,int a,int b){
    int dist=ping(a,b);

    for(int i=1;i<=n;i++){
        if(i!=a&&i!=b)v[ping(i,b)].push_back(i);
    }
    int cur=a;
    dist--;
    while(dist>=0){
        int i=0;
        while(ping(v[dist][i],cur)!=0)i++;

        cur=v[dist][i];
        dist--;
        travelTo(cur);
    }
    travelTo(b);
}
