/*
Project:		UVA 1001
Problem_type:	
Author: 		kawaii_pendant
Date:   		2020-01-12 19:06:42
Last Modified Time: 2020-01-12 19:46:20
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
int n;
const int maxm=1e3;
struct node{
	int x,y,z,r;
};
node a[maxm];
double dis[maxm][maxm];
double dist(int x,int y){
	double dx=a[x].x-a[y].x;
	double dy=a[x].y-a[y].y;
	double dz=a[x].z-a[y].z;
	double dis=sqrt((dx*dx)+(dy*dy)+(dz*dz));
	if(dis<=a[x].r+a[y].r) return 0;
	return dis-a[x].r-a[y].r;
}
int main(){
	int kase=0;
	while(~scanf("%d",&n)&&n!=-1){
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
		}
		a[0].r=a[n+1].r=0;
		scanf("%d%d%d",&a[0].x,&a[0].y,&a[0].z);
		scanf("%d%d%d",&a[n+1].x,&a[n+1].y,&a[n+1].z);
		for(int i=0;i<=n+1;i++){
			for(int j=i+1;j<=n+1;j++){
				dis[i][j]=dis[j][i]=dist(i,j);
			}
		}
		for(int k=0;k<=n+1;k++){
			for(int i=0;i<=n+1;i++){
				for(int j=0;j<=n+1;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		printf("Cheese %d: Travel time = %.0f sec\n",++kase,dis[0][n+1]*10);
	}	
}