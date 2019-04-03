#include <bits/stdc++.h>
using namespace std;
vector<int> nhijos;
vector<vector<pair<int,bool> > > graph;
int resp = 0;
int nes[] = {1,3,0,2};
vector<bool> cabeza;
//parte 0 = cabeza, 1 = pecho, 2 = brazo/pierna, 3 = tula
bool ua(int nodo, int parte){
	//printf(" INICIO NODO: %d, PARTE %d\n",nodo,parte);
	if(nhijos[nodo] == 0){
		if(parte == 2) return true;
		return false;
	}
	for(int i=0;i<graph[nodo].size();i++){
		if(graph[nodo][i].second == false) continue;
		if(cabeza[graph[nodo][i].first] == true) continue;
		cabeza[graph[nodo][i].first]=true;
		if(ua(graph[nodo][i].first,0)){
			/*graph[nodo][i].second = false;
			//resp++;
			nhijos[nodo]--;*/
		}
	}
	bool si = false;
	int a=0,b=0;
	vector<pair<int,int> > us;
	if(parte == 2) return true;
	if(nhijos[nodo]>=nes[parte]){
		for(int i=0;i<graph[nodo].size();i++){
			if(graph[nodo][i].second == false) continue;

			if(parte == 0){
				if(ua(graph[nodo][i].first,1)){
					//printf("NODO: %d, PARTE %d\n",nodo,parte);
					graph[nodo][i].second = false;
					resp++;
					nhijos[nodo]--;
					//return true;
				}
			}
			if(parte == 1){
				if( a<1 && ua(graph[nodo][i].first,3)){
					graph[nodo][i].second = false;
					//resp++;
					a++;
					us.push_back(make_pair(nodo,i));
					nhijos[nodo]--;
					//return true;
				}
				else if(b<2 && ua(graph[nodo][i].first,2)){
					graph[nodo][i].second = false;
					//resp++;
					b++;
					us.push_back(make_pair(nodo,i));
					nhijos[nodo]--;
				}
			}
			if(parte == 3){
				//printf("NODO: %d, PARTE %d\n",nodo,parte);
				return true;
			}

		}
	}
	else return false;
	if(parte == 1){
		if( a <1 || b < 2){
			for(int i=0;i<us.size();i++){
				graph[us[i].first][us[i].second].second = true;
				nhijos[us[i].first]++;
			}
			return false;
		}
		//printf("NODO: %d, PARTE %d\n",nodo,parte);
		return true;
	}
}

int main(){

	int n;
	scanf("%d",&n);
	nhijos.resize(n+1,0);
	graph.resize(n+1);
	cabeza.resize(n+1,false);
	for(int i=2;i<=n;i++){
		int a;
		scanf("%d",&a);
		graph[a].push_back(make_pair(i,true));
		nhijos[a]++;
	}
	ua(1,0);
	printf("%d\n",resp);

	return 0;
}