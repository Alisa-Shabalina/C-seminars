#include "Time.h"

using std::cout;

int main() {

	Time t1(Hours(1), Minutes(23), Day(31), Month(1), Year(2005));
	Time t2(Hours(2), Minutes(40), Day(30), Month(10), Year(1996));
	TimeInterval t_i(Hours(1), Minutes(20), Day(1), Month(10), Year(2000));
	TimeInterval t_i_1(Hours(2), Minutes(45), Day(10), Month(5), Year(1836));
	cout << t1;
	t1.Switch();
	cout << t1;
	t1.Switch();
	cout << t1 << t2 << t_i << endl;

	cout << t1 << t_i;
	cout << t1 + t_i;
	cout << t1 - t_i << endl;
	cout << t1 << t2;
	cout << t1 - t2 << endl;
	//cout << t1 + t2;
	cout << t_i << t_i_1;
	cout << t_i + t_i_1;
	cout << t_i - t_i_1;

	return 0;
}