/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-23 16:02:11
Last Modified Time: 2019-12-23 16:43:01
*/
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+10;
const int maxm=1e5+10;
int n,m,q;
int p[maxn],dep[maxn];
int st[maxn][24],gw[maxn][24];
struct EDGE{
	int u,v;
	ll w;
	bool operator<(const EDGE b)const{
		return w<b.w;
	}
}e[maxm];
struct Edge{
	int to;
	ll w;
	Edge(){}
	Edge(int to,ll w):to(to),w(w){}
};
vector<Edge> edges[maxn];
void dfs(int u,int fa,int dis){
	dep[u]=dep[fa]+1;
	gw[u][0]=dis,st[u][0]=fa;
	for(int i=1;(i<<i)<=dep[u];i++){
		st[u][i]=st[st[u][i-1]][i-1];
		gw[u][i]=max(gw[u][i-1],gw[st[u][i-1]][i-1]);
	}
	for(int i=0;i<(int)edges[u].size();i++){
		int v=edges[u][i].to;
		if(v!=fa) dfs(v,u,edges[u][i].w);
	}
}
int LCA(int u,int v){
	int res=-1;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=21;i>=0;i--){
		if(dep[st[u][i]]>=dep[v]){
			res=max(res,gw[u][i]);
			u=st[u][i];
		}
	}
	if(u==v) return res;
	for(int i=21;i>=0;i--){
		if(st[u][i]==st[v][i]) continue;
		res=max(res,gw[u][i]);
		res=max(res,gw[v][i]);
		u=st[u][i],v=st[v][i];
	}
	return max(max(gw[u][0],res),gw[v][0]);
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
	int T=0;
	while(~scanf("%d%d",&n,&m)){
		if(T++) printf("\n");
		memset(dep,0,sizeof(dep));
		for(int i=1;i<=n;i++) edges[i].clear(),p[i]=i;
		for(int i=0;i<m;i++){
			scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e,e+m);
		int now=0;
		for(int i=0;i<m&&now<n-1;i++){
			int fa=find(e[i].u),fb=find(e[i].v);
			int u=e[i].u,v=e[i].v;
			ll w=e[i].w;
			if(fa!=fb){
				p[fa]=fb;
				edges[u].push_back(Edge(v,w));
				edges[v].push_back(Edge(u,w));
				now++;
			}
		}	
		for(int i=1;i<=n;i++) if(!dep[i]) dfs(i,0,0);
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			if(find(u)!=find(v)) printf("-1\n");
			else printf("%d\n",LCA(u,v));
		}
	}
}