/*
Project:		
Problem_type:	G++不能用%lf,要用%f,C++可以
Author: 		kawaii_pendant
Date:   		2019-12-23 12:19:05
Last Modified Time: 2019-12-23 13:59:54
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=5e5+10;
int n,m;
int p[maxm];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
struct EDGE{
	int u,v;
	double w;
	EDGE(){}
	EDGE(int u,int v,double w):u(u),v(v),w(w){}
	bool operator<(const EDGE b) const{
		return w<b.w;
	}
}e[maxm];
struct NODE{
	double x,y;
}node[505];
double dist(int x,int y){
	double x1=node[x].x,y1=node[x].y;
	double x2=node[y].x,y2=node[y].y;
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n*n;i++) p[i]=i;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				e[cnt++]=EDGE(i,j,dist(i,j));
			}
		}
		sort(e,e+cnt);
		double ans[maxm]={0};
		int ans_cnt=0;
		for(int i=0;i<cnt;i++){
			int u=e[i].u,v=e[i].v;
			int fa=find(u),fb=find(v);
			if(fa!=fb){
				p[fa]=fb;
				ans[ans_cnt++]=e[i].w;
			}
		}
		printf("%.2lf\n",ans[ans_cnt-m]);
	}
}
