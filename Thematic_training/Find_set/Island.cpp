/*
Project:		UVA 1665
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-22 11:53:55
Last Modified Time: 2020-01-22 13:55:20
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=1e3+10;
const int maxn=1e5+10;
int n,m,t,T;
int dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int r[maxn],ans[maxn],p[maxm*maxm],mp[maxm][maxm];
struct Node{
	int x,y,h;
	bool operator <(const Node& b) const{
		return h<b.h;
	}
}pit[maxm*maxm];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&mp[i][j]);
				pit[i*m+j].x=i;
				pit[i*m+j].y=j;
				pit[i*m+j].h=mp[i][j];
			}
		}
		sort(pit,pit+n*m);
		memset(p,-1,sizeof(p));
		scanf("%d",&t);
		for(int i=0;i<t;i++) scanf("%d",&r[i]);
		int k=n*m-1,sum=0;
		for(int i=t-1;i>=0;i--){
			while(k>=0&&r[i]<pit[k].h){
				int pos=pit[k].x*m+pit[k].y;
				if(p[pos]==-1) p[pos]=pos,sum++;
				for(int j=0;j<4;j++){
					int nx=pit[k].x+dxy[j][0];
					int ny=pit[k].y+dxy[j][1];
					if(0<=nx&&nx<n&&0<=ny&&ny<m&&mp[nx][ny]>r[i]){
						int npos=nx*m+ny;
						if(p[npos]!=-1){
							int fa=find(p[pos]);
							int nfa=find(p[npos]);
							if(fa!=nfa) p[fa]=nfa,sum--;//连通块减少
						}
					}
				}
				k--;
			}
			if(k<0){
				while(i>=0){
					ans[i]=sum;
					i--;
				}
				break;
			}
			ans[i]=sum;
		}
		for(int i=0;i<t;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}