#pragma once

#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>

using std::map;
using range = std::pair<long long int, long long int>;

class RangeStorage {
public:
	void add(range r);
	void add(const std::vector<range>& rs);
	

	void merge(const RangeStorage& rhs);
	inline auto begin() const { return Storage.begin(); }
	inline auto end() const { return Storage.end(); }
	
	void print();

	auto find(long long int num) const {
		auto iter = Storage.upper_bound(num);

		if (iter == Storage.begin()) {
			return Storage.end();
		}
		else {
			iter--;
			if ((iter->first <= num) && (iter->second >= num))
				return iter;
		}
		return Storage.end();
	}
private:
	map<long long int, long long int> Storage;
};