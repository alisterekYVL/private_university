#include "int.h"

namespace ap {
	double Integration1(double(*f)(const double x), const double x1, const double x2, const unsigned int n) {
		double sum = 0.0;
		double dx = (x2 - x1) / n;
		for (double x = x1; x < x2; x += dx) {
			sum += f(x);
		}
		return sum * dx;
	}

	double Integration2(function1* f, const double x1, const double x2, const unsigned int n) {
		double sum = 0.0;
		double dx = (x2 - x1) / n;
		for (double x = x1; x < x2; x += dx) {
			sum += f(x);
		}
		return sum * dx;
	}

	double Integration3(const std::function<double(const double)>& f, const double x1, const double x2, const unsigned int n) {
		double sum = 0.0;
		double dx = (x2 - x1) / n;
		for (double x = x1; x < x2; x += dx) {
			sum += f(x);
		}
		return sum * dx;
	}
}