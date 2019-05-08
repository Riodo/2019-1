#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

int main(){
	double p,a,b,c,d;
	int n;
	while(scanf("%lf %lf %lf %lf %lf %d",&p,&a,&b,&c,&d,&n)==6){
		vector<double> price(n);
		double mdif = 0;
		double m = 0;
		for(int i=1;i<=n;i++){
			price[i-1] = p*(sin((a*i+b))+cos((c*i+d))+2);
			mdif = max(mdif,m-price[i-1]);
			m = max(m,price[i-1]); 
		}
		printf("%.7lf\n",mdif);
	}



}