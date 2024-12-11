#pragma once
#include <functional>


namespace ap {
	typedef double function1(const double);

	double Integration1(double(*f)(const double x), const double x1, const double x2, const unsigned int n);
	double Integration2(function1* f, const double x1, const double x2, const unsigned int n);
	double Integration3(const std::function<double(const double)>& f, const double x1, const double x2, const unsigned int n);

}