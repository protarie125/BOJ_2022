#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	double x, y, c;
	cin >> x >> y >> c;

	auto l = double{ 0 };
	auto r = x < y ? x : y;
	auto m = (l + r) / 2;
	while (true) {
		const auto& e1 = m * c / sqrt(x * x - m * m);
		const auto& e2 = m * c / sqrt(y * y - m * m);

		const auto& d = e1 + e2;
		if (abs(d - m) < 1E-6) {
			break;
		}

		if (d < m) {
			l = m;
		}
		else {
			r = m;
		}

		m = (l + r) / 2;
	}

	cout << fixed << setprecision(3) << m;

	return 0;
}