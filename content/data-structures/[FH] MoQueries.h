/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: me
 * Description: Mo's algorithm for offline range queries. Make sure to sort the queries first.
 * Implement add(), remove() and get() functions accordingly.
 * Time: O((N+Q)F\sqrt N) where O(F) is add()/remove()/get() complexity.
 * Status: stress-tested
 */

const int B = 450; // sqrt(Q)
vector<array<int, 4>> queries; // {l/B, r, l, id}
sort(all(queries));
int left = 0, right = -1;
for(auto [_, r, l, id, k]: queries){
	while(right < r) add(++right);
	while(right > r) remove(right--);
	while(left < l) remove(left++);
	while(left > l) add(--left);
	ans[id] = get(k);
}

 
