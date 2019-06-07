#include "Time.h"

using std::cout;

int main() {

	Time t1(Hours(1), Minutes(23), Day(31), Month(1), Year(2005));
	TimeInterval t_i(Hours(1), Minutes(20), Day(1), Month(10), Year(2000));
	cout << t1;
	t1.ForwardSwitch();
	cout << t1;
	t1.ReverseSwitch();
	cout << t1 << t_i;

//	cout << t1 + t_i;
//	cout << t1 - t_i;

	return 0;
}