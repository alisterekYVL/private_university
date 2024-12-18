#include "histogram.h"
#include <fstream>
#include <iostream>
#include <algorithm>

namespace ap {
	std::map<std::string, unsigned int> Histogram(const std::string& fileName) {
	std::map<std::string, unsigned int> histogram;
	std::ifstream in(fileName);
	if (in) {
		std::string word;
		while (in >> word) {
			auto it = std::remove_if(word.begin(), word.end(), [](const char c) {return !std::isalpha(c); });
				word.erase(it, word.end());
				++histogram[word];
		}
		in.close();
	}
	return histogram;
}

	std::map<std::pair<std::string, std::string>, unsigned int> PairHistogram(const std::string& fileName) {
		std::map<std::pair<std::string, std::string>, unsigned int> pairHistogram;
		std::ifstream in(fileName);
		if (in) {
			std::string prevWord, currWord;
			while (in >> currWord) {
				auto it = std::remove_if(currWord.begin(), currWord.end(), [](const char c) { return !std::isalpha(c); });
				currWord.erase(it, currWord.end());
				if (!prevWord.empty()) {
					++pairHistogram[{prevWord, currWord}];
				}
				prevWord = currWord;
			}
			in.close();
		}
		return pairHistogram;
	}


	void Show(const std::map<std::string, unsigned int>& histogram) {
		for (const auto& el : histogram) {
			std::cout << "[" << el.first << "]: " << el.second << std::endl;

		}
	}

	void Show(const std::map<std::pair<std::string, std::string>, unsigned int>& histogram) {
		for (const auto& el : histogram) {
			std::cout << "[" << el.first.first << ", " << el.first.second << "]: " << el.second << std::endl;
		}
	}
}