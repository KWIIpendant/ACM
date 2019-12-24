/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-23 21:26:14
Last Modified Time: 2019-12-23 21:26:18
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxm=2e5+10;
struct EDGE{
	int u,v;
	ll w;
	bool operator<(const EDGE b) const{
		return w>b.w;
	}
}e[maxm];
int p[maxm],num[maxm];
int n;
ll sum[maxm];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<n;i++){
			scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
		}
		sort(e+1,e+n);
		for(int i=1;i<=n;i++) p[i]=i,num[i]=1,sum[i]=0;
		for(int i=1;i<n;i++){
			int fa=find(e[i].u);
			int fb=find(e[i].v);
			ll w=e[i].w;
			ll sum1=sum[fa]+num[fb]*w;
			ll sum2=sum[fb]+num[fa]*w;
			if(sum1>sum2){
				p[fb]=fa;
				num[fa]+=num[fb];
				sum[fa]=sum1;
			}else {
				p[fa]=fb;
				num[fb]+=num[fa];
				sum[fb]=sum2;
			}
		}
		printf("%lld\n",sum[find(1)]);
	}
	return 0;
}