#include <iostream> 
#include <map>
#include <chrono>

#define ull unsigned long long

std::map<ull, ull> dp;

ull f(ull n) {
	std::map<ull, ull>::iterator it = dp.find(n);

	if(it != dp.end()) {
		return it->second;
	}


	if(n == 0) {
		return 1;
	}

	if(n == 1) {
		return 1;
	}

	ull q;

	if(n % 2 == 0) {
		q = f(n / 2);
	}

	if(n % 2 == 1) {
		q =  f((n - 1) / 2) + f((n - 1) / 2 - 1);
	}

	dp[n] = q;

	return q;
}

int main() {
	const auto& go = [](ull in)->void {
		const auto&  before = std::chrono::high_resolution_clock::now();
		std::cout << "f(" << in << ") = " << f(in) << std::endl;
		const auto&  after = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> total_time = after - before;
		std::cout << "time: " << total_time.count() * 1000 << "ms" << std::endl;
	};

	go(123456789012345678);
	go(50);
	go(8);
}