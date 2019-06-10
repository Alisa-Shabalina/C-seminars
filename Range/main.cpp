#include "StorageRange.h"

int main() {
	RangeStorage rs;
	rs.add({ 1, 42 });
	rs.add({ 60, 70 });
	rs.find(4);
	rs.find(55);
	rs.print();
}

