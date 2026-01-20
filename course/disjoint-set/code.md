## DSU with size functionality
- Data structure which stores disjoint sets. 
- **Usage**: When connectivity problem is to be solved in efficient manner.
- 


```cpp
class DSU {
	int n;
	vt<int> par;
	vt<int> siz;
	public:
		DSU(int sz){
			n= sz;
			par.resize(n); siz.resize(n);
			
			iota(par.begin(), par.end(), 0);
			fill(siz.begin(),siz.end(),1);
		}
		
		int findPar(int a){
			if(par[a]==a) return a;
			
			// Path compression
			return par[a] = findPar(par[a]); 
		}
		
		int findSiz(int a){
			return siz[findPar(a)];
		}
		void unite(int a, int b){
			int arp = findPar(a), brp = findPar(b);
			
			// this is to prevent overflow
			if(arp==brp) return;
				
			// selecting the parent with larger set size to be the merged parent
			if(siz[arp]<siz[brp]) swap(arp,brp);
			par[brp] = arp;
			siz[arp] += siz[brp];
		}
}
```