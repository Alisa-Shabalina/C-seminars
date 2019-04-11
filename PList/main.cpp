#include "Value.h"
#include "PList.h"

using std::make_shared;

int main() {
	PList list;
	shared_ptr<Value> val1, val2, val3, val4;
	val1 = make_shared<Integer>(1);
	val2 = make_shared<Double>(2.3);
	val3 = make_shared<Complex>(1, 2);
	val4 = make_shared<Complex>(2, 2);

	list.Add(val1);
	list.Add(val2);
	list.Add(val3);
	list.Print();

	list.Has(val2);
	list.Has(val4);

	list.Drop(val2);
	list.Print();

	return 0;
}