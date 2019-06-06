#include "MarkovAlgString.h"

void MarkovAlg<char>::addRule(const string& pattern, const string& replacement, const bool& terminated) {
	Rules.push_back(Rule<char>{pattern, replacement, terminated});
}

void MarkovAlg<char>::setData(const string& expression) {
	InitialExpression = expression;
	Expression = expression;
}

void MarkovAlg<char>::step() {
	for (const auto& item : Rules)
	{
		auto pos = Expression.find(item.Pattern);
		if (pos >= 0)
		{
			Expression.replace(pos, item.Pattern.size(), item.Replacement);
			break;
		}
	}
}


void MarkovAlg<char>::run() {
	auto iter = Rules.begin();
	while (iter != Rules.end())
	{
		auto pos = Expression.find(iter->Pattern);
		if (pos >= 0)
		{
			Expression.replace(pos, iter->Pattern.size(), iter->Replacement);
			iter = Rules.begin();
		}
		else {
			++iter;
		}
	}
}

bool MarkovAlg<char>::isTerminated() {
	auto iter = Rules.begin();
	while (iter != Rules.end()) {
		auto pos = Expression.find(iter->Pattern);
		if (pos >= 0)
		{
			//Expression.replace(pos, iter->Pattern.size(), iter->Replacement);
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