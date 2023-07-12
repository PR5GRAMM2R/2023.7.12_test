#ifndef vector_h
#define vector_h

#pragma once

#include<stdio.h>
#include<initializer_list>
#include<algorithm>

using namespace std;

enum { INIT_Value = 8 };	// default vector 세팅 시 초기 space 값 및 elem 크기

template<class T> class vector {
	int size;
	T* elem;
	int space;

public:
	vector();		// default vector

	vector(int sz);
	
	vector(initializer_list<T> lst);

	vector(const vector& copying);

	vector(vector&& moving);

	~vector();

	vector& operator=(const vector<T>& copying);

	vector& operator=(vector<T>&& moving);

	T operator[ ](int location);

	int get_size();

	int get_space();

	void push_back(T new_num);

	void reserve(int sz);

	void resize(int sz_);

	class resizing_error {};
	class no_data {};
	class vector_overflowed {};
};

#endif
