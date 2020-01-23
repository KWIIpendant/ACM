/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-22 20:32:17
Last Modified Time: 2019-12-22 21:18:43
*/
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>	
#define ll long long
using namespace std;
const int maxm=1e4+10;	
int n,m;
int p[maxm],vis[maxm],dvis[maxm];
struct EDGE{
	int u,v,w;
	bool operator<(const EDGE b){
		return w<b.w;
	}
}e[maxm];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
struct Edge{
	int to,w;
	Edge(){}
	Edge(int to,int w):to(to),w(w){}
};
vector<Edge> edge[maxm];
int val[maxm][maxm];
void dfs(int rt,int u){
	dvis[u]=1;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i].to;
		if(!dvis[v]){
			val[rt][v]=max(val[rt][u],edge[u][i].w);
			dfs(rt,v);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		memset(val,0,sizeof(val));
		memset(dvis,0,sizeof(dvis));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			p[i]=i;
			edge[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e,e+m);
		int ans1=0;
		int now=0;
		for(int i=0;i<m&&now<n-1;i++){
			int u=e[i].u,v=e[i].v;
			int fa=find(u),fb=find(v);
			if(fa!=fb){
				now++;
				edge[u].push_back(Edge(v,e[i].w));
				edge[v].push_back(Edge(u,e[i].w));
				vis[i]=1;
				p[fa]=fb;
				ans1+=e[i].w;
			}
		}
		// for(int i=1;i<=n;i++){
		// 	memset(dvis,0,sizeof(dvis));
		// 	dfs(i,i);
		// }
		int ans2=1e9+10;
		for(int i=0;i<m;i++){
			if(!vis[i]) {
				memset(dvis,0,sizeof(dvis));
				dfs(e[i].u,e[i].u);
				ans2=min(ans2,ans1-val[e[i].u][e[i].v]+e[i].w);
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
}