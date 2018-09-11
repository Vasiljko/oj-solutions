/*
  problem is equivalent to: cover the tree with minimum number of paths from one node to another one
  optimal solution is to connect nodes with degree = 1
  connect leaves i and i+sz/2 where sz is size of set of the leaves
  this works because it is always possible to pick a node such that number of leaves in its subtree is sz/2
  *handle the case when sz is odd
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 5e5+5;

int n;
vector<int>leaf;
vector<int>v[N];

void dfs(int s,int p){
	if(v[s].size()==1){
		leaf.push_back(s);
	}
	for(int i=0;i<v[s].size();i++){
		if(v[s][i]!=p){
			dfs(v[s][i],s);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	int x,y;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1,-1);
	int k=(int)leaf.size();
	if(k%2==0){
		cout<<k/2<<"\n";
		for(int i=0;i<k/2;i++){
			cout<<leaf[i]<<" "<<leaf[i+k/2]<<"\n";
		}
	}else{
		cout<<k/2+1<<"\n";
		for(int i=0;i<k/2;i++){
			cout<<leaf[i]<<" "<<leaf[i+k/2+1]<<"\n";
		}
		cout<<leaf[k/2]<<" "<<1;
	}

	return 0;
}
