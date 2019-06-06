#pragma once

#include <vector>
#include <algorithm>

using std::vector;


template <typename T>
struct Rule {
	vector<T> Pattern;
	vector<T> Replacement;
	bool Terminated;
	Rule(vector<T> pattern, vector<T> replacement, bool terminated) : Pattern(pattern), Replacement(replacement), Terminated(terminated) {}
};

template <typename T>
class MarkovAlg {
public:
	MarkovAlg() {}

	void addRule(const vector<T>& pattern, const vector<T>& replacement, const bool& terminated);
	void addRule(const Rule<T>& rule);

	void setData(const vector<T>& expression);
	inline vector<T> getData() const& { return Expression; }

	bool isTerminated();
	void step();

	void run();

private:
	vector<T> InitialExpression;
	vector<T> Expression;
	vector<Rule<T>> Rules;
	
	//bool isTerm = false;
};

template <typename T>
void MarkovAlg<T>::addRule(const Rule<T>& rule) {
	Rules.push_back(rule);
}

template <typename T>
void MarkovAlg<T>::addRule(const vector<T>& pattern, const vector<T>& replacement, const bool& terminated) {
	Rules.push_back(Rule<T>{pattern, replacement, terminated});
}

template <typename T>
void MarkovAlg<T>::setData(const vector<T>& expression) {
	InitialExpression = expression;
	Expression = expression;
}

template <typename T>
bool MarkovAlg<T>::isTerminated() {
	auto iter = Rules.begin();
	while (iter != Rules.end()) {
		auto pos = search(Expression.begin(), Expression.end(), iter->Pattern.begin(), iter->Pattern.end());
		if (pos != Expression.end()) {
			//std::replace(begin(Expression), end(Expression), pos, iter->Replacemant);
			if (iter->Terminated) return true;
			iter = Rules.begin();
		}
		else {
			++iter;
			if (iter == Rules.end()) return true;
		}
	}
	return false;
}

template <typename T>
void MarkovAlg<T>::step() {

	for (const auto& item : Rules)
	{
		auto pos = search(Expression.begin(), Expression.end(), item.Pattern.begin(), item.Pattern.end());
		if (pos != Expression.end())
		{
			auto pos_end = pos;
			for (int i = 0; i < item.Pattern.size(); ++i)
				pos_end++;
			pos = Expression.erase(pos, pos_end);
			Expression.insert(pos, item.Replacement.begin(), item.Replacement.end());
			break;
		}
	}

}

template <typename T>
void MarkovAlg<T>::run() {

	auto iter = Rules.begin();
	while (iter != Rules.end())
	{
		auto pos = search(Expression.begin(), Expression.end(), iter->Pattern.begin(), iter->Pattern.end());
		if (pos != Expression.end())
		{
			auto pos_end = pos;
			for (int i = 0; i < iter->Pattern.size(); ++i)
				pos_end++;
			pos = Expression.erase(pos, pos_end);
			Expression.insert(pos, iter->Replacement.begin(), iter->Replacement.end());
			//break;
			iter = Rules.begin();
		}
		else {
			++iter;
		}

	}
}
