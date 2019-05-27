#pragma once

#include "MarkovAlg.h"
#include <string>

using std::string;

template <>
struct Rule<char> {
	string Pattern;
	string Replacement;
	bool Terminated;
};

template <>
class MarkovAlg<char> {
public:
	MarkovAlg() {}

	void addRule(const string& pattern, const string& replacement, const bool& terminated);
	//void addRule(const Rule<T>& rule);

	void setData(const string& expression);
	inline string getData() const& { return Expression; }

	bool isTerminated();
	void step();

	void run();

private:
	string InitialExpression;
	string Expression;
	vector<Rule<char>> Rules;
};

