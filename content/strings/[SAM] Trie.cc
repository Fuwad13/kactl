/**
 * Author: Sarowar Alam Minhaj
 * Description:
 * Time: O(n)
 */
struct trie {
	struct node {
		array<node*, 26> next{};
		int leaf = 0, prefix = 0;
		node() {
			for (auto& i : next) i = nullptr;
			leaf = 0, prefix = 0;
		}
	};
	node root;
	void add(const string& s) {
		node* cur = &root;
		for (auto i : s) {
			if (cur->next[i - 'a'] == nullptr) cur->next[i - 'a'] = new node();
			cur->prefix += 1;
			cur = cur->next[i - 'a'];
		}
		cur->leaf += 1;
		cur->prefix += 1;
	}
	void erase(const string& s) {
		node* cur = &root;
		for (auto i : s) {
			if (cur->next[i - 'a'] == nullptr) return;
			cur->prefix -= 1;
			cur = cur->next[i - 'a'];
		}
		cur->leaf -= 1;
		cur->prefix -= 1;
	}
	int count(const string& s) {
		node* cur = &root;
		for (auto i : s) {
			if (cur->next[i - 'a'] == nullptr) return 0;
			cur = cur->next[i - 'a'];
		}
		return cur->leaf;
	}
	int count_prefixes(const string& s) {
		node* cur = &root;
		for (auto i : s) {
			if (cur->next[i - 'a'] == nullptr) return 0;
			cur = cur->next[i - 'a'];
		}
		return cur->prefix;
	}
	bool contains(const string& s) {
		node* cur = &root;
		for (auto i : s) {
			if (cur->next[i - 'a'] == nullptr) return false;
			cur = cur->next[i - 'a'];
		}
		return cur->leaf;
	};
	void del_all(node* cur, vector<node*>& ad) {
		for (auto& i : cur->next) {
			if (i == nullptr) continue;
			ad.push_back(i);
			del_all(i, ad);
		}
	}
	void destroy() {
		vector<node*> ad;
		del_all(&root, ad);
		for (auto& u : ad) {
			delete[] u;
		}
	}
	~trie() { destroy(); }
};
