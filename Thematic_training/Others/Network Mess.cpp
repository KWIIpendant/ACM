/*
Project:		UVA 1667
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-22 22:23:15
Last Modified Time: 2020-01-22 23:08:12
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn=2e3+5;
int n,dis[maxn][maxn],a[maxn][maxn];
int idx,id[maxn],deg[maxn];	
void build(){
	id[1]=++idx;
	dis[1][1]=0;
	for(int i=2;i<=n;i++){
		int u,last,tmp;
		for(int j=1;j<=idx;j++){
			tmp=a[i][1]-dis[j][1];
			int flag=0;
			for(int k=2;k<i;k++){
				if(a[i][k]-dis[j][id[k]]!=tmp){
					flag=1;
					break;
				}
			}
			if(!flag){
				last=j;
				break;
			}
		}
		for(int j=1;j<=tmp;j++,last=u){
			u=++idx;
			deg[u]=0,dis[u][u]=0;
			++deg[last],++deg[u];
			for(int k=1;k<idx;k++)
				dis[u][k]=dis[k][u]=dis[k][last]+1;
		}
		id[i]=idx;
	}
}
int main(){
	while(~scanf("%d",&n)&&n){
		idx=0;
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		build();
		sort(deg+1,deg+idx+1);
		int flag=0;
		for(int i=1;i<=idx;i++){
			if(deg[i]==1) continue;
			if(!flag) printf("%d",deg[i]),flag=1;
			else printf(" %d",deg[i]);
		}
		printf("\n");
	}
}