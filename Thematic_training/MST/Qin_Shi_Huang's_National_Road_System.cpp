/*
Project:		UVA 1494
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-22 12:40:52
Last Modified Time: 2019-12-22 14:36:49
*/
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=1e3+10;
int n,cnt,now,p[maxm];
bool vis[maxm];
double val[maxm][maxm];
double sum;
struct NODE{
	double x,y;
	int P;
}pos[maxm];
struct EDGE{
	int u,v;
	double w;
	bool operator <(const EDGE b) const{
		return w<b.w;
	}
}edge[maxm*maxm];
struct CEDGE{
	int to;
	double w;
	CEDGE(){}
	CEDGE(int to,double w):to(to),w(w){}
};
vector<CEDGE> e[maxm];
double dist(int a,int b){
	double x1=pos[a].x,y1=pos[a].y;
	double x2=pos[b].x,y2=pos[b].y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
double check(int x,int y){
	double A=pos[x].P+pos[y].P;
	double B=sum-val[x][y];
	return A/B;
}
void dfs(int rt,int u){
	vis[u]=1;
	for(int i=0;i<(int)e[u].size();i++){
		int v=e[u][i].to;
		if(!vis[v]){
			val[rt][v]=max(val[rt][u],e[u][i].w);
			dfs(rt,v);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			e[i].clear();
			p[i]=i;
			scanf("%lf%lf%d",&pos[i].x,&pos[i].y,&pos[i].P);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edge[cnt].u=i,edge[cnt].v=j;
				edge[cnt++].w=dist(i,j);
			}
		}
		sort(edge,edge+cnt);
		now=0,sum=0;
		for(int i=0;i<cnt&&now<n-1;i++){
			int fa=find(edge[i].u),u=edge[i].u;
			int fb=find(edge[i].v),v=edge[i].v;
			if(fa!=fb){
				now++;
				p[fa]=fb;
				sum+=edge[i].w;
				e[u].push_back(CEDGE(v,edge[i].w));
				e[v].push_back(CEDGE(u,edge[i].w));
			}else continue;
		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i,i);
		}
		double ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,check(i,j));
			}
		}
		printf("%.2lf\n",ans);
	}
}