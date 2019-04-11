#include "PList.h"

void PrintValue(const Value& v) {
	v.Print();
}

void PList::Print() {
	for (auto v : ListOfValues) {
		PrintValue(*v);
		//v.Print();
		std::cout << '\n';
	}
	std::cout << std::endl;
}

void PList::Add(shared_ptr<Value> value) { ListOfValues.push_back(value); }

void PList::Has(shared_ptr<Value> value) {
	auto it = find(begin(ListOfValues), end(ListOfValues), value);
	if (it != end(ListOfValues)) {
		std::cout << "List has ";
		PrintValue(*value);
		std::cout << '\n';
	}
	else {
		std::cout << "List has not ";
		PrintValue(*value);
		std::cout << '\n';
	}
}

void PList::Drop(shared_ptr<Value> value) {
	auto it = find(begin(ListOfValues), end(ListOfValues), value);
	ListOfValues.erase(it);
}