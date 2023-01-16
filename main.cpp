#include <cmath>
#include <iostream>
#include <numeric>

// https://pl.wikipedia.org/wiki/%C5%9Aredni_b%C5%82%C4%85d_%C5%9Bredniej

int main() {
	static constexpr double dane[] = {
		#include "dane"
	};

	constexpr auto srednia = std::accumulate(std::begin(dane), std::end(dane), 0.0) / std::size(dane);
	constexpr auto mianownik = static_cast<double>(std::size(dane) * (std::size(dane) - 1));
	auto wynik = 0.0;

	for (auto i = 0u; i < std::size(dane); ++i) {
		wynik += std::pow(dane[i] - srednia, 2.0);
	}

	wynik /= mianownik;
	wynik = std::sqrt(wynik);

	std::cout << wynik;
	return 0;
}
