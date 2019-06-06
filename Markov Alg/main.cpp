#include "MarkovAlg.h"
#include "MarkovAlgString.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& t) {
	for (auto item : t)
		stream << item << " ";
	stream << "\n";
	return stream;
}

int main() {
	setlocale(LC_ALL, "Russian"); 

	//MarkovAlg<char> Test1;
	//Test1.addRule({ '1' }, { '0', '|' }, false);
	//Test1.addRule({ '|', '0' }, { '0', '|', '|' }, false);
	//Test1.addRule({ '0' }, {}, false);
	//Test1.setData({ '1', '0', '1' });
	//Test1.run();
	//cout << Test1.getData() << std::endl;


	//MarkovAlg<char> Test2;
	//Test2.addRule({ '|', 'b' }, { 'b', 'a', '|' }, false);
	//Test2.addRule({ 'a', 'b' }, { 'b', 'a' }, false);
	//Test2.addRule({ 'b' }, {}, false);
	//Test2.addRule({ '*', '|' }, { 'b', '*' }, false);
	//Test2.addRule({ '*' }, { 'c' }, false);
	//Test2.addRule({ '|', 'c' }, { 'c' }, false);
	//Test2.addRule({ 'a', 'c' }, { 'c', '|' }, false);
	//Test2.addRule({ 'c' }, { '.' }, true);
	//Test2.setData({ '|', '*', '|', '|' });
	//Test2.run();
	//cout << Test2.getData() << std::endl;

	MarkovAlg<char> Test;
	Test.addRule("A", "apple", false);
	Test.addRule("B", "bag", false);
	Test.addRule("S", "shop", false);
	Test.addRule("T", "the", false);
	Test.addRule("the shop", "my brother", false);
	Test.addRule("a never used", ".", true);
	Test.setData("I bought a B of As from T S.");
	Test.run();
	cout << Test.getData() << std::endl;
	
	return 0;
}