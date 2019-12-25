/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-24 21:45:25
Last Modified Time: 2019-12-24 22:52:03
*/
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
int a,b,c,radius;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cin>>a>>b>>c>>radius;
		int l=c-radius,r=c+radius;
		if(a>b) swap(a,b);
		if(l>b||r<a) printf("%d\n",b-a);
		else if(l<a&&r>b) printf("%d\n",0);
		else if(a<=l&&l<=b&&r>b){
			printf("%d\n",b-a-(b-l));
		}else if(a<=l&&r<=b){
			printf("%d\n",(b-a)-(r-l));
		}else if(l<a&&r>=a&&r<=b){
			printf("%d\n",(b-a)-(r-a));
		}
	}
}