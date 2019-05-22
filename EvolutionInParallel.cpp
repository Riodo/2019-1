#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
	return a.size()<b.size();
}
vector<string> fosil;
vector<int> r1;
vector<int> r2;
int n;
bool solve(int i){
	if(i == n)
		return true;
	string a = fosil[r1.back()];
	string b = fosil[i];
	//cout << fosil[i]<<endl;
	bool ret = false;
	int j=0,k=0;
	while(j<a.size() && k<b.size()){
		if(a[j] == b[k]){
			j++;
		}
		k++;
	}
	if(j==a.size()){
		r1.push_back(i);
		ret = solve(i+1);
		if(ret) return true;
		r1.pop_back();
	}
	if(r2.size()==0){
		r2.push_back(i);
		ret = solve(i+1);
	}		
	else{
		a = fosil[r2.back()];
		j=0;
		k=0;
		while(j<a.size() && k<b.size()){
			if(a[j] == b[k]){
				j++;
			}
			k++;
		}
		if(j==a.size()){
			r2.push_back(i);
			ret = solve(i+1);
			if(ret) return true;
			r2.pop_back();
		}
		else{
			return false;
		}
	}
	



	return ret;
}

int main(){

	
	while(cin >> n){

		string current;
		cin >> current;
		fosil.resize(n);
		for(int i=0;i<n;i++){
			cin >> fosil[i];
		}
		sort(fosil.begin(),fosil.end(),cmp);

		r1.clear();
		r2.clear();
		r1.push_back(0);
		bool imp = !solve(1);
		/*for(int i=1;i<n;i++){
			string a = fosil[r1.back()];
			string b = fosil[i];
			cout << fosil[i]<<endl;
			int j=0,k=0;
			while(j<a.size() && k<b.size()){
				if(a[j] == b[k]){
					j++;
				}
				k++;
			}
			if(j==a.size()){
				r1.push_back(i);
			}
			else{
				if(r2.size()==0){
					r2.push_back(i);
				}
				else{
					a = fosil[r2.back()];
					j=0;
					k=0;
					while(j<a.size() && k<b.size()){
						if(a[j] == b[k]){
							j++;
						}
						k++;
					}
					if(j==a.size())
						r2.push_back(i);
					else{
						imp = true;
						break;
					}
				}
			}
		}
		cout<<fosil[r1.back()]<<endl;
		cout<<fosil[r2.back()]<<endl; 
		cout << r1.size()<<" "<<r2.size()<<endl;
		*/
		string a = fosil[r1.back()];
		string b = current;
		int j=0,k=0;
		while(j<a.size() && k<b.size()){
			if(a[j] == b[k]){
				j++;
			}
			k++;
		}
		if(j!=a.size()){
			imp = true;
		}
		if(r2.size()!=0){
			a = fosil[r2.back()];
			b = current;
			j=0,k=0;
			while(j<a.size() && k<b.size()){
				if(a[j] == b[k]){
					j++;
				}
				k++;
			}
			if(j!=a.size()){
				imp = true;
			}
		}
		if(imp)
			cout<<"impossible"<<endl;
		else{
			cout<<r1.size()<<" "<<r2.size()<<endl;
			for(int i=0;i<r1.size();i++){
				cout << fosil[r1[i]]<<endl;
			}
			for(int i=0;i<r2.size();i++){
				cout << fosil[r2[i]]<<endl;
			}
		}
	}


}