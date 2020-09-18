mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll getRand(ll l, ll r)
{
	uniform_ll_distribution<int> uid(l, r);
	return uid(rng);
}

store[i] = getRand(0, 2e18);