/*
Project:		
Problem_type:	
Author: 		kawaii_pendant
Date:   		2019-12-21 17:08:57
Last Modified Time: 2019-12-21 19:11:53
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;
const int maxm=1e9+10;
bool is_prime(int n){
	if(n==2) return true;
	else if(n%2==0) return false;
	for(int i=3;i<=sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int a=2,b=2+n;
	while(1){
		if(!is_prime(a)&&!is_prime(b)){
			break;
		}else{
			a++,b++;
		}
	}
	cout<<b<<" "<<a<<endl;
}