#pragma once

#include "Value.h"
#include <vector>
#include <memory>
#include <algorithm>

using std::shared_ptr;

void PrintValue(const Value& v);

class PList {
public:
	PList() {};
	void Print();
	void Add(shared_ptr<Value> value);
	void Has(shared_ptr<Value> value);
	void Drop(shared_ptr<Value> value);
private:
	std::vector<shared_ptr<Value>> ListOfValues;
};