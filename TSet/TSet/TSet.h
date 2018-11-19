#pragma once
#include <set>
#include <algorithm>
using namespace std;

template <class T>
class TSet {
private:
	set<T> container;
public:
	void clear();
	void add(T newElem);
	void del(T toDelElem);
	bool isClear();
	bool isContains(T elem);
	TSet<T> addition(const TSet<T> &otherSet);
	TSet<T> subtraction(const TSet<T> &otherSet);
	TSet<T> multiply(const TSet<T> &otherSet);
	int count();
	T elem(int elemNumber);
	TSet();
	~TSet();
};

template<class T>
void TSet<T>::clear() {
	container.clear();
}

template<class T>
void TSet<T>::add(T newElem) {
	container.insert(newElem);
}

template<class T>
void TSet<T>::del(T toDelElem) {
	if (container.count(toDelElem))
		container.erase(toDelElem);
}

template<class T>
bool TSet<T>::isClear() {
	if (container.size() == 0)
		return true;
	else
		return false;
}

template<class T>
bool TSet<T>::isContains(T elem) {
	return container.count(elem);
}

template<class T>
TSet<T> TSet<T>::addition(const TSet<T> &otherSet) {
	TSet<T> result = *this;
	for (const T &elem : otherSet.container)
		result.add(elem);
	return result;
}

template<class T>
TSet<T> TSet<T>::subtraction(const TSet<T> &otherSet) {
	TSet<T> result = *this;
	for (const T &elem : otherSet.container)
		if (result.container.count(elem))
			result.del(elem);
	return result;
}

template<class T>
TSet<T> TSet<T>::multiply(const TSet<T> &otherSet) {
	TSet<T> result;
	for (const T &elem : otherSet.container)
		if (container.count(elem))
			result.add(elem);
	return result;
}

template<class T>
int TSet<T>::count() {
	return container.size();
}

template<class T>
T TSet<T>::elem(int elemNumber) {
	if (elemNumber < 0 || elemNumber >= container.size()) {
		T toReturn;
		return toReturn;
	}
	auto it = container.begin();
	advance(it, elemNumber);
	return *it;
}

template<class T>
TSet<T>::TSet() {
}

template<class T>
TSet<T>::~TSet() {
	container.clear();
}