// vector class definition.
#ifndef VECTOR_H
#define VECTOR_H

#include "Iterator.h" // include definition of class Iterator

template< typename T >
class vector
{
public:
	typedef Iterator<T> iterator;

	vector();
	// Constructs a container with n elements. Each element is a copy of val.

	~vector(); // Destroys the container object.

	T &operator[](unsigned int);
	// subscript operator for non-const objects returns modifiable lvalue

	// subscript operator for const objects returns rvalue
	T operator[](unsigned int) const;

	iterator begin() const;
	// Returns a pointer pointing to the first element in the vector.
	// If the container is empty, the returned pointer shall not be dereferenced.

	iterator end() const;
	// Returns an pointer referring to the past-the-end element in the vector container.   
	// The past-the-end element is the theoretical element that would follow the last element in the vector.   
	// It does not point to any element, and thus shall not be dereferenced.   
	// If the container is empty, the returned pointer shall not be dereferenced. 

	unsigned int size() const; // Returns the number of elements in the vector.

	void push_back(const T val);
	// Adds a new element at the end of the vector, after its current last element.
	// The content of val is copied to the new element.   
	// This effectively increases the container size by one,   
	// which causes an automatic reallocation of the allocated storage space   
	// if -and only if- the new vector size surpasses the current vector capacity.

	iterator erase(iterator position);
	// Removes from the vector a single element.   
	// This effectively reduces the container size by one.   
	// Relocates all the elements after the element erased to their new positions.

private:
	unsigned int mySize; // the number of elements in the vector

	T *ptr;
	// points to a dynamically allocated array which is used to store the elements of the vector
}; // end class vector

// constructor
template< typename T >
vector< T >::vector()
: mySize(0),
ptr(new T[0])
{
} // end vector constructor

// destructor
template< typename T >
vector< T >::~vector()
{
	delete[] ptr;
} // end destructor

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
template< typename T >
T &vector< T >::operator[](unsigned int subscript)
{
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= mySize)
	{
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		exit(1); // terminate program; subscript out of range
	} // end if

	return ptr[subscript]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
template< typename T >
T vector< T >::operator[](unsigned int subscript) const
{
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= mySize)
	{
		cerr << "\nError: Subscript " << subscript << " out of range" << endl;
		system("pause");
		exit(1); // terminate program; subscript out of range
	} // end if

	return ptr[subscript]; // returns copy of this element
} // end function operator[]

template< typename T >
Iterator< T > vector< T >::begin() const
{
	return iterator(ptr);
}

template< typename T >
Iterator< T > vector< T >::end() const
{
	return iterator(ptr + mySize);
}

template< typename T >
unsigned int vector< T >::size() const
{
	return mySize;
}

template< typename T >
void vector< T >::push_back(const T val){
	T *arr = new T[mySize + 1];
	iterator it1 = begin();
	for (int i = 0; i < mySize; i++,it1++){//�ƻs��s��
		arr[i] = *it1;
	}
	arr[mySize] = val;
	delete[]ptr;
	ptr = arr;
	mySize++;
}
// Adds a new element at the end of the vector, after its current last element.
// The content of val is copied to the new element.   
// This effectively increases the container size by one,   
// which causes an automatic reallocation of the allocated storage space   
// if -and only if- the new vector size surpasses the current vector capacity.

template< typename T >
Iterator< T > vector< T >::erase(iterator position){
	vector< T >::iterator tmp, tmp1;//�����e�ƻs
	for (tmp = position, tmp1 = position + 1; tmp1 != end(); tmp++, tmp1++){
		tmp = tmp1;
	}
	vector< T >::iterator it1 = begin();
	T *arr = new T[mySize - 1];
	for (int i = 0; i < mySize - 1; i++){//�ƻs��s�� 
		arr[i] = *it1;
	}
	delete[]ptr;//����O����
	ptr = arr;
	mySize--;
	//Reservation
	//resize(reservations.size() - 1);
	return begin();
}
// Removes from the vector a single element.   
// This effectively reduces the container size by one.   
// Relocates all the elements after the element erased to their new positions.

#endif