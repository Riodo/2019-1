#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
using namespace std;
struct FenwickTree {
  vector<int> ft;
  FenwickTree(){}  
  FenwickTree(int n){
    ft.assign(n + 1, 0);
  }

  int query(int b) {
    int sum = 0;
    for (; b; b -= b&(-b)) sum += ft[b];
    return sum;
  }

  int query(int a, int b) { //RSQ
    return query(b) - (a == 1 ? 0 : query(a - 1));
  }

  void update(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += k&(-k)) ft[k] += v;
  }
};

vector<int> isprime;
vector<int> primes;
int c;
void sieve(int n) {
	isprime.assign(n + 1,0);
	
	isprime[1] = 1; isprime[2] = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime[i]==0) {
			isprime[i] = i;
			for (int j = i;  j < n; j+=i) {
					isprime[j] = i;
			}
		}
	}
	/*for (int i = 2; i < n; i++) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}*/
	return;
}

int main(){
	int q;
	scanf("%d",&q);
	FenwickTree ft(1e5+10);
	vector<pair<pair<int,int>,int> > query(q);
	sieve(100010);
	c = 2;
	for(int i=0;i<q;i++){
		int n,k;
		scanf("%d %d",&n,&k);
		query[i] = mp(mp(n,k),i);
	}
	//ft.update(2,1);
	sort(query.begin(), query.end());
	vector<pair<int,int> > resp(q);
	for(int i=0;i<query.size();i++){
		while(c<=query[i].f.f){
			ft.update(isprime[c],1);
			c++;
		}
		resp[i] = mp(query[i].s,ft.query(query[i].f.s));
	}
	sort(resp.begin(),resp.end());
	for(int i=0;i<q;i++){
		printf("%d\n",resp[i].s);
	}
	return 0;
}