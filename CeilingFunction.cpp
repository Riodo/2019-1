#include <bits/stdc++.h>
using namespace std;

struct nodo{

	nodo* l;
	nodo* r;
	int num;
	nodo(int a){
		num = a;
		l = NULL;
		r = NULL;
	}
	nodo(){
		;
	}
};

int n;
int k;

vector<nodo*> tree;

void insert(nodo *nod, int num){
	if(num<nod->num){
		if(nod->l == NULL)
			nod->l = new nodo(num);
		else insert(nod->l,num);
	}
	if(num>nod->num){
		if(nod->r == NULL)
			nod->r = new nodo(num);
		else insert(nod->r,num);
	}
}

bool cmp(nodo* a, nodo* b){
	if(a == NULL){
		if(b == NULL){
			return true;
		}
		else return false;
	}
	if(b == NULL) return false;
	if(!cmp(a->l,b->l)) return false;
	if(!cmp(a->r,b->r)) return false;
	return true;

}

int main(){

	while(scanf("%d %d",&n,&k)==2){
		tree.clear();
		tree.resize(n);
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			tree[i] = new nodo(a);
			for(int j=1;j<k;j++){
				scanf("%d",&a);
				insert(tree[i],a);
			}
		}
		vector<bool> used(n,false);
		int cont = 0;
		for(int i=0;i<n;i++){
			if(used[i]) continue;
			cont++;
			for(int j=i+1;j<n;j++){
				if(used[j]) continue;
				if(cmp(tree[i],tree[j]))
					used[j] = true; 
			}
		}
		printf("%d\n",cont);
	}

	return 0;
}