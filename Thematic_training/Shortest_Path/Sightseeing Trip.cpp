/*
Project:		POJ 1734
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-13 12:05:14
Last Modified Time: 2020-01-13 16:09:31
*/
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=100+10;
const int INF=1e8;
int dis[maxm][maxm],mp[maxm][maxm],path[maxm],pre[maxm][maxm];
int n,m,minn,tot;
void floyd(){
	minn=INF;
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(dis[i][j]+mp[i][k]+mp[k][j]<minn){
					minn=dis[i][j]+mp[i][k]+mp[k][j];//最短距离+两条边
					tot=0;
					int tmp=j;
					path[tot++]=j;
					while(tmp!=i){
						tmp=pre[i][tmp];
						path[tot++]=tmp;
					}
					path[tot++]=k;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					pre[i][j]=pre[k][j];
				}
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=mp[i][j]=INF;
			pre[i][j]=i;//前驱
		}
	}
}
int main(){
	while(~scanf("%d",&n)&&n!=-1){
		init();
		scanf("%d",&m);
		int u,v,w;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(w<mp[u][v]){
				mp[u][v]=mp[v][u]=dis[u][v]=dis[v][u]=w;
			}
		}
		floyd();
		if(minn==INF) printf("No solution.\n");\
		else{
			for(int i=0;i<tot;i++){
				if(!i) printf("%d",path[i]);
				else printf(" %d",path[i]);
			}
			printf("\n");
		}
	}
}