#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pi 3.14159265359
using namespace std;

int main(){
	int n,s;
	while(scanf("%d %d",&n,&s)==2){


		vector<pair<int,int> > holes(n);
		double total = 100.0*100.0*100.0;
		for(int i=0;i<n;i++){
			int r,x,z;
			scanf("%d %d %d %d",&r,&x,&x,&z);
			holes[i] = mp(z,r);
			double rad = (double)r/1000.0;
			total-=(4.0/3.0)*pi*rad*rad*rad;
		}
		double thic = total/(double)s;
		double pos = 0.0;
		//printf("THIC: %.3lf TOTAL: %.3lf\n",thic,thic*(double)s);
		//double asd = 0;
		for(int i=0;i<s;i++){
			double l = pos;
			double r = 100.0;
			int k=0;
			while(k<50){
				double mid = (l+r)/2;
				double ar = 100.0*100.0*(mid-pos);
				for(int j=0;j<n;j++){
					double rad = (double)holes[j].s/1000.0;
					double z =(double)holes[j].f/1000.0;
					if(mid>z+rad){
						if(pos<z-rad)
							ar-=(4.0/3.0)*pi*rad*rad*rad;
						else if(pos>z+rad){
							continue;
						}
						else{
							double h = z+rad-pos;
							ar-=(pi/3.0)*h*h*(3.0*rad-h);
						}
					}
					else if(mid<z-rad){
						continue;
					}
					else{
						if(pos<z-rad){
							double h = mid-(z-rad);
							ar-=(pi/3.0)*h*h*(3.0*rad-h);
						}
						else{
							double h = z+rad-pos;
							ar-= (pi/3.0)*h*h*(3.0*rad-h);
							h = z+rad-mid;
							ar+= (pi/3.0)*h*h*(3.0*rad-h);
						}
						
						
					}

				}
				//printf("AR: %.3lf\n",ar);
				if(ar<thic){
					l=mid;
				}
				else r=mid;
				k++;
			//	if(k==50) printf("AR: %.7lf ",ar);
			}
			printf("%.7lf\n",-pos+l);
			pos = l;

		}
		//printf("FP: %.7lf\n",pos);
	}
	return 0;
}