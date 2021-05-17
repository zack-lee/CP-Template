/**
 * Description: for each prefix, stores link to max length suffix which is also a prefix
 * Source: https://ideone.com/0cMjZJ
 * Verification: 
	* Kattis stringmultimatching
 */

struct ACunfixed { 
	struct node {
		map<char,int> to;
		int link;
	};
	vector<node> d;
	ACunfixed() { d.emplace_back(); }
	
	int add(string s) { // add word
		int v = 0;
		trav(c,s) {
			if (!d[v].to.count(c)) {
				d[v].to[c] = sz(d);
				d.emplace_back();
			}
			v = d[v].to[c];
		}
		return v;
	}

	int nex(int j, char c) { // state after adding character
		while (j != -1 && !d[j].to.count(c)) j = d[j].link;
		return j == -1 ? 0 : d[j].to[c]; 
	}
	void init() { // generate links
		d[0].link = -1;
		queue<int> q; q.push(0);
		while (sz(q)) {
			int v = q.front(); q.pop();
			trav(it,d[v].to) {
				char c = it.f; int u = it.s;
				d[u].link = nex(d[v].link,c); 
				q.push(u); 
			}
		}
	}
};