#include <bits/stdc++.h>

using i64 = long long;

void solve () {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector <std::vector <std::pair <int, int>>> e(n);
	std::vector <int> ans;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		x--, y--;
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	auto dij = [&](int x) {
		std::cout << "dij:" << x << std::endl;
		std::vector <int> dis(n, 1e9);
		std::vector <bool> vis(n, 0);
		dis[x] = 0;
		std::priority_queue <std::pair <int, int>> q;
		q.push({0, x});
		int cnt = 0;
		while(q.size() && cnt <= k) {
			std::cout << cnt << '\n';
			auto t = q.top();
			q.pop();
			if (vis[t.second]) continue;
			vis[t.second] = true;
			cnt++;
			if (dis[t.second]) {
				ans.push_back(dis[t.second]);
			}
			for (auto i : e[t.second]) {
				if (dis[i.second] > dis[t.second] + i.first) {
					dis[i.second] = dis[t.second] + i.first;
					q.push({-dis[i.second], i.second});
				}
			}
		}
		return;
	};
	for (int i = 0; i < n; i++) dij(i);
	sort(ans.begin(), ans.end());
	std::cout << ans[2 * k - 1] << std::endl;
	return;
}

int main() {
#ifdef qmwneb	
	freopen(".in.txt", "r", stdin);
	freopen(".out.txt", "w", stdout);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
#endif
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
}
