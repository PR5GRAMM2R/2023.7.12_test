#include"vector.h"

template<class T> vector<T>::vector()
	: size{ 0 }, elem{ nullptr }, space{ 0 }
{
	reserve(size);
	for (int i = 0; i < size; i++) elem[i] = 0.0;
}

template<class T> vector<T>::vector(int sz)
	: size{ sz }, elem{ new double[2 * sz] }, space{ 2 * sz }
{
	for (int i = 0; i < size; i++) elem[i] = 0.0;
}

template<class T> vector<T>::vector(initializer_list<T> lst)
	: size{ (int)lst.size() }, elem{ new double[2 * (int)lst.size()] }, space{ 2 * (int)lst.size() }
{
	for (int i = 0; i < size; i++) elem[i] = 0.0;
	copy(lst.begin(), lst.end(), elem);
}

template<class T> vector<T>::vector(const vector& copying)
	: size{ copying.size }, elem{ copying.elem }, space{ copying.space }
{
	for (int i = 0; i < size; i++) elem[i] = copying.elem[i];
}

template<class T> vector<T>::vector(vector&& moving)
	: size{ moving.size }, elem{ moving.elem }, space{ moving.space }
{
	for (int i = 0; i < size; i++) elem[i] = moving.elem[i];
	moving.size = 0;
	moving.space = 0;
	delete[] moving.elem;
}

template<class T> vector<T>::~vector()
{
	delete[] elem;
}

template<class T> vector<T>& vector<T>::operator=(const vector<T>& copying)
{
	size = copying.size;
	space = copying.space;
	delete[] elem;
	elem = new double[space];
	for (int i = 0; i < size; i++) elem[i] = copying.elem[i];
	return *this;
}

template<class T> vector<T>& vector<T>::operator=(vector<T>&& moving)
{
	size = moving.size;
	space = moving.space;
	delete[] elem;
	elem = new double[space];
	for (int i = 0; i < size; i++) elem[i] = moving.elem[i];
	moving.size = 0;
	moving.space = 0;
	delete[] moving.elem;
	moving.elem = nullptr;
	return *this;
}

template<class T> T vector<T>::operator[ ](int location)
{
	if (elem == nullptr)
		throw no_data();
	if (location >= size || location < 0)
		throw vector_overflowed();
	else
		return elem[location];
}

template<class T> int vector<T>::get_size()
{
	return size;
}

template<class T> int vector<T>::get_space()
{
	return space;
}

template<class T> void vector<T>::push_back(T new_num)
{
	resize(size + 1);
	elem[size - 1] = new_num;
	return;
}

template<class T> void vector<T>::reserve(int sz)
{
	if (space == 0) {
		space = INIT_Value;		// 초기 값
		elem = new double[space];
		return;
	}
	else if (sz < space)
		return;
	else {
		space = 2 * sz;									// space와 size 가 같아지면 space를 2배 늘리고 elem 도 space만큼 늘리는 작업.
		double* temp = new double[space];
		for (int i = 0; i < size; i++) temp[i] = elem[i];
		elem = temp;
		delete[] temp;
		return;
	}
}

template<class T> void vector<T>::resize(int sz_)
{
	if (sz_ < size)
		throw resizing_error();
	else {
		size = sz_;
		reserve(size);
	}
	return;
}
