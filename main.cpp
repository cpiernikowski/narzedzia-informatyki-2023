#include <cmath>
#include <iostream>
#include <numeric>
#include <fstream>
#include <string>
#include <vector>

// https://pl.wikipedia.org/wiki/%C5%9Aredni_b%C5%82%C4%85d_%C5%9Bredniej

int main() {
	std::ifstream ifs("dane");
	std::vector<double> dane;

	for (std::string line; std::getline(ifs, line);) {
		dane.push_back(std::stod(line));
	}

	ifs.close();

	const double srednia = std::accumulate(std::begin(dane), std::end(dane), 0.0) / std::size(dane);
	const double mianownik = std::size(dane) * (std::size(dane) - 1);
	double wynik{};

	for (std::size_t i{}; i < std::size(dane); ++i) {
		wynik += std::pow(dane[i] - srednia, 2.0);
	}

	wynik = std::sqrt(wynik / mianownik);

	std::cout << wynik;
	return 0;
}
