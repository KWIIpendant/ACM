/*
Project:		枚举后逐个Kruskal
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-22 00:06:50
Last Modified Time: 2019-12-22 01:11:56
*/
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=1e3+10;
int n,q,cnt,cost[10];
int p[maxm*maxm];
vector<int> suit[10];
struct NODE{
	int x,y;
}pos[maxm];	
struct EDGE{
	int u,v,w;
	bool operator <(const EDGE b) const{
		return w<b.w;
	}
}edge[maxm*maxm];
int dist(int a,int b){
	int dx=pos[a].x-pos[b].x;
	int dy=pos[a].y-pos[b].y;
	return dx*dx+dy*dy;
}
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
ll Kruskal(int x){
	ll res=0;
	int cnt_=0;
	for(int i=0;i<q;i++){
		if(x&(1<<i)){
			res+=cost[i];
			for(int j=0;j<(int)suit[i].size();j++){
				int tmp=suit[i][j];
				int fa=find(tmp),fb=find(suit[i][0]);
				if(fa==fb) continue;
				else p[fa]=fb,cnt_++;
			}
		}
	}
	for(int i=0;i<cnt&&cnt_<n-1;i++){
		int fa=find(edge[i].u);
		int fb=find(edge[i].v);
		if(fa!=fb){
			cnt_++;
			res+=edge[i].w;
			p[fa]=fb;
		}else continue;
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&q);
		for(int i=0;i<q;i++){
			int x;
			scanf("%d%d",&x,&cost[i]);
			suit[i].clear();
			for(int j=0;j<x;j++) {
				int tmp;
				scanf("%d",&tmp);
				suit[i].push_back(tmp);
			}
		}
		for(int i=1;i<=n;i++) {
			p[i]=i;
			scanf("%d%d",&pos[i].x,&pos[i].y);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edge[cnt].u=i,edge[cnt].v=j;
				edge[cnt++].w=dist(i,j);
			}
		}
		ll ans=1e18+10;
		sort(edge,edge+cnt);
		for(int i=0;i<(1<<q);i++){
			ans=min(ans,Kruskal(i));
			for(int j=0;j<=n;j++)
				p[j]=j;
		}
		printf("%lld\n",ans);
		if(T) printf("\n");
	}
}
