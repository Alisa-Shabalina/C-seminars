#include "StorageRange.h"

void RangeStorage::add(range r) {
	if (r.first > r.second) r = std::make_pair(r.second, r.first);
	if (!Storage.empty()) {
		if (r.first == r.second) {
			if (find(r.first) == Storage.end()) {
				Storage.insert(r);
				return;
			}
		}
		else {
			if ((r.second < Storage.begin()->first) || ((r.first > std::prev(Storage.end())->second))) {
				Storage.insert(r);
				return;
			}
			else {
				auto iter_left = Storage.upper_bound(r.first);
				auto iter_right = Storage.upper_bound(r.second);

				if (iter_left == iter_right) {
					iter_left--;
					if ((iter_left->second < r.first) && (r.second < iter_right->first)) {
						Storage.insert(r);
						return;
					}
				}
				else {
					if (iter_left == Storage.begin()) {
						range biggest(r.first, std::max(r.second, std::prev(iter_right)->second));
						Storage.erase(Storage.begin(), iter_right);
						Storage.insert(biggest);
					}
					else {
						if (std::prev(iter_left)->second >= r.first) iter_left--;
						range biggest_r(std::min(r.first, iter_left->first), std::max(r.second, std::prev(iter_right)->second));
						Storage.erase(iter_left, iter_right);
						Storage.insert(biggest_r);
					}
				}
			}
		}
	}
	else {
		Storage.insert(r);
	} 
	return;
}

void RangeStorage::add(const std::vector<range>& rs) {
	for (auto r : rs) {
		add(r);
	}
}



void RangeStorage::merge(const RangeStorage& rhs) {
	for (auto item : rhs) {
		add(item);
	}
}

void RangeStorage::print() {
	for (auto item : Storage) {
		std::cout << '{' << item.first << ", " << item.second << '}';
	}
	std::cout << std::endl;
}