/*
Project:		UVA 10801
Problem_type:	分层图
Author: 		kawaii_pendant
Date:   		2020-01-14 15:56:36
Last Modified Time: 2020-01-15 11:19:40
*/
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
const int INF=1e9;
const int maxn=100+10;
const int maxm=10000+10;
using namespace std;
int n,k;
int dis[maxm],vis[maxm],T[maxn];
struct NODE{
	int v,dis;
	NODE(int v,int dis):v(v),dis(dis){}
	bool operator <(const NODE &b)const{
		return dis>b.dis;
	}
};
struct EDGE{
	int to,w;
	EDGE(int to,int w):to(to),w(w){}
};
vector<EDGE> edge[maxm];
int Dijk(int s,int t){
	priority_queue<NODE> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(NODE(s,dis[0]));
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<(int)edge[u].size();i++){
			int to=edge[u][i].to,w=edge[u][i].w;
			if(dis[to]>dis[u]+w){
				dis[to]=dis[u]+w;
				q.push(NODE(to,dis[to]));
			}
		}
	}
	return dis[t];
}
int main(){
	while(~scanf("%d%d",&n,&k)){
		for(int i=0;i<maxm;i++) edge[i].clear();
		for(int i=1;i<=n;i++) scanf("%d",&T[i]);
		for(int i=1;i<=n;i++){
			char ch='\0';
			int now=0,pre=0;
			for(int j=1;ch!='\n';j++){
				scanf("%d%c",&now,&ch);
				if(j!=1){
					edge[i*100+pre].push_back(EDGE(i*100+now,T[i]*(now-pre)));//同一台电梯往前往后建双向边
					edge[i*100+now].push_back(EDGE(i*100+pre,T[i]*(now-pre)));
				}
				pre=now;
			}
		}
		for(int i=0;i<=99;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					edge[j*100+i].push_back(EDGE(k*100+i,60));//同一层不同电梯建边
				}
			}
		}
		int ans=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=min(ans,Dijk(i*100,j*100+k));//从第i台电梯出发到第j台电梯的k层
			}
		}
		if(ans!=INF) printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
}