#include <iostream>
#include <memory>

using namespace std;

class Daniel {
private:
	int capacity = 2;
	int _size = 0;
	double* array;

	void resize() {
		double* copy = array;

		array = new double[capacity*2];

		for(int i = 0; i < _size; i++) {
			array[i] = copy[i];
		}

		capacity *= 2;

		delete[] copy;
	}

public:
	Daniel()
	{
		array = new double[capacity];
	}

	// throw a std::out_of_range
	double at(int idx) const {
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
	void put(int idx, double val)
	{
		at(idx);

		array[idx] = val;
	}

	void push_back(double val)
	{
		if(_size >= capacity) {
			resize();
		}

		array[_size] = val;

		_size++;
	}

	double operator[] (int idx) const {
		return array[idx];
	}

	double& operator[] (int idx) {
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

void foo(const Daniel d) {
	cout << d[0] << endl;
	d.size();
}

int main() {

	int* mem = new int;
	unique_ptr<int> mem2 = unique_ptr<int>(new int);
	*mem = 3;
	*mem2 = 6;

	Daniel d;
	d.push_back(1);
	d.push_back(3);

	cout << d[0] << endl;
	cout << d.at(0) << endl;

	d.put(0, 3);
	d[0] = 3;

	vector<int> arr{1,2,3,4,5};


	cout << *mem << endl;
	cout << *mem2 << endl;
}
