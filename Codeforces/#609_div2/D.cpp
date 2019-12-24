/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-24 16:37:43
Last Modified Time: 2019-12-24 16:42:39
*/
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=3e5+10;
int n;	
int a[maxm];
ll b[2];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i%2]+=a[i]/2+a[i]%2;
		b[(i+1)%2]+=a[i]/2;
	}
	cout<<min(b[0],b[1])<<endl;
}