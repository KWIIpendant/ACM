/*
Project:		CF160D
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-22 16:46:34
Last Modified Time: 2019-12-22 19:54:15
*/
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=1e5+10;
int n,m,p[maxm];
int dfn_index=0;
int vis[maxm],dfn[maxm],low[maxm];
int ans[maxm];
struct EDGE{
	int u,v,w,id;
	bool operator <(const EDGE b) const{
		return w<b.w;
	}
}e[maxm];
struct Edge{
	int v,id;
	Edge(){}
	Edge(int v,int id):v(v),id(id){}
};
vector<Edge> edge[maxm];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void tarjan(int u,int fa){
	low[u]=dfn[u]=dfn_index++,vis[u]=1;
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i].v;
		if(vis[v]&&edge[u][i].id!=fa) low[u]=min(low[u],dfn[v]);
		else if(!vis[v]){
			tarjan(v,edge[u][i].id);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) ans[edge[u][i].id]=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		int st=i,ed=i;
		while(ed+1<=m&&e[ed+1].w==e[ed].w) ed++;
		for(int j=st;j<=ed;j++){
			int fa=find(e[j].u);
			int fb=find(e[j].v);
			if(fa!=fb){
				ans[e[j].id]=2;
				edge[fa].push_back(Edge(fb,e[j].id));
				edge[fb].push_back(Edge(fa,e[j].id));
			}
		}
		for(int j=st;j<=ed;j++){
			int fa=find(e[j].u);
			int fb=find(e[j].v);
			if(fa!=fb&&!vis[fa]) tarjan(fa,-1);
			if(fa!=fb&&!vis[fb]) tarjan(fb,-1);
		}
		for(int j=st;j<=ed;j++){
			int u=e[j].u;
			int v=e[j].v;
			int fa=find(u);
			int fb=find(v);
			if(fa!=fb){
				edge[fa].clear();
				edge[fb].clear();
				vis[fa]=vis[fb]=0;
				dfn[fa]=dfn[fb]=0;
				low[fa]=low[fb]=0;
				p[fa]=fb;
			}
		}
		i=ed;
	}
	for(int i=1;i<=m;i++){
		if(ans[i]==0) printf("none\n");
		else if(ans[i]==1) printf("any\n");
		else printf("at least one\n");
	}
}