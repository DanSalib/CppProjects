/**
 * daniel.hpp
 * 
 * \author Daniel Salib * \date Wed 16 May 16:50:06 2018
 *
 */

#ifndef DANIEL_HPP
#define DANIEL_HPP

template<typename T>
class Daniel {
private:
	int capacity = 2;
	int _size = 0;
	T* array;

	void resize() {
		T* copy = array;

		array = new T[capacity*2];

		for(int i = 0; i < _size; i++) {
			array[i] = copy[i];
		}

		capacity *= 2;

		delete[] copy;
	}

public:
	Daniel()
	{
		array = new T[capacity];
	}

	// throw a std::out_of_range
	T at(int idx) const {
		if(idx >= _size || idx < 0) {
			throw out_of_range("this is out of range");
		}

		return array[idx];
	}

	// Daniel d; []
	// d.push_back(1); [1, , ]
	// d.push_back(2); [1,2, ]
	// d.put(0, 24); [24, 2, ]
	// d.put(1, 25); [24, 25, ]
	// d.put(2, 26); // out_of_range
	// throw a std:out_of_range if index does not exit
	void put(int idx, T val)
	{
		at(idx);

		array[idx] = val;
	}

	void push_back(T val)
	{
		if(_size >= capacity) {
			resize();
		}

		array[_size] = val;

		_size++;
	}

	T operator[] (int idx) const {
		return array[idx];
	}

	T& operator[] (int idx) {
		return array[idx];
	}

	int size() const
	{
		return _size;
	}

	~Daniel()
	{
		delete[] array;
	}

};

#endif /* DANIEL_HPP */
