#pragma once
#include <string>
#include <map>
namespace ap {
	std::map<std::string, unsigned int> Histogram(const std::string&);
	std::map<std::pair <std::string, std::string>, unsigned int> PairHistogram(const std::string&);


	void Show(const std::map<std::string, unsigned int>& histogram);
	void Show(const std::map<std::pair <std::string, std::string>, unsigned int>& histogram);


}