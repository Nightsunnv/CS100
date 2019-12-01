#ifndef CUSTOMSET_H
#define CUSTOMSET_H
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>
#include<iterator>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
template <typename T>
class CustomSet
{
public:
	// Constructors and destructor:
	CustomSet() {
		m_size=0;
		cset.clear();
	};
	// Default constructor

	CustomSet(const CustomSet& other) {
		m_size=other.size();
		cset=other.cset;
	};
	// Copy constructor. Should construct a copy of "other".

	CustomSet(T arr[], int size) {
		cset.clear();
		m_size=0;
        for(int i=0;i<size;i++){
        	add(arr[i]);
		}
	};
	// Constructor using an array. 
	// Note that if there are duplicates in the array, you should ignore them.
	// And then the size of your "CustomSet" will be different from the "size" given!

	~CustomSet() {};
	// Destructor. Pay attention to memory leaks!

// Other member functions:
	int size() const{
		return m_size;
	};
	// Returns the size of the set.

	bool add(const T& item) {
        if(lookFor(item))return false;
        cset.push_back(item);
        m_size++;
		sortSet();
        return true;
	};
	// If "item" is already in the set, return false. 
	// Otherwise, add it to the set and return true.
    bool lookFor(const T& item){
    	for (typename vector<T>::iterator iter = cset.begin(); iter != cset.end(); ++iter) {
			if (*iter == item)return true;
		}
		return false;
	}
	T* find(const T& item) {
		for (typename vector<T>::iterator iter = cset.begin(); iter != cset.end(); ++iter) {
			if (*iter == item)return &(*iter);
		}
		return nullptr;
	};

	// If an object in the set equals "item", return a pointer to it.
	// If "item" is not found, return nullptr(NULL).

	bool erase(const T& item) {
		for (typename vector<T>::iterator iter = cset.begin(); iter != cset.end(); ++iter) {
			if (*iter == item) {
				cset.erase(iter);
				m_size--;
				return true;
			}
		}
		return false;
	};
	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.

/*	CustomSet intersection(const CustomSet& other) {
		CustomSet intersectiono;int i;
		for (i = 0; i < m_size; i++) {
			for (int j = 0; j < other.size(); j++) {
				if (cset[i] == other.cset[j]) {
					intersectiono.add(other.cset[j]);
				}
				continue;
			}
		}
		return intersectiono;
	};
*/
CustomSet intersection(const CustomSet& other) {
		CustomSet intersectiono;unsigned int i;
		for (i = 0; i < this->cset.size(); i++) {
			for (unsigned int j = 0; j < other.cset.size(); j++) {
				if (this->cset[i] == other.cset[j]) {
					intersectiono.cset.push_back(other.cset[j]); break;
				}
			}
		}
		return intersectiono;
	};
	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.

	void sortSet() {
		sort(cset.begin(), cset.end());return;
	};
	// This function sorts the objects in the set in ascending order.
	// Directly using (std::)sort is enough, if you are using an STL container.

	void printSet() {
		if(m_size==0){
			cout<<"{}"<<endl;
			return;
		}
		cout << "{"<<cset[0];
		for(int i=1;i<m_size;i++)cout<<", "<<cset[i];
		cout<<"}"<<endl;
		return;
	};
	// This function prints the set, seperating elements by { , , , }.
	// It's safe to assume that it supports operator<< of ostream (cout).
	// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
	// This function will print: "{2, 4, -2, 800}\n"
	// Note that there are spaces between a comma(,) and the next object.
	// Print a newline at the end. (indicated by the '\n' above)

// Operators:
	CustomSet operator+ (const T& item) {
		CustomSet oo(*this);
		oo.add(item);
		return oo;
	};
	CustomSet operator+ (const CustomSet& that) {
		CustomSet oo(*this);
		for (typename vector<T>::const_iterator iter = that.cset.begin(); iter != that.cset.end(); ++iter) {
			oo.add(*iter);
		}
		return oo;
	};
	CustomSet& operator+= (const T& item) {
		add(item);
		return *this;
	};
	CustomSet& operator+= (const CustomSet& that) {
		for (typename vector<T>::const_iterator iter = that.cset.begin(); iter != that.cset.end(); ++iter) {
			add(*iter);
		}
		return *this;
	};
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item. 
	// A set "plus" a set means taking the union of two sets.
	// However, the difference between + and += is not written here.
	// Try to figure out on your own!

	CustomSet operator- (const T& item) {
		CustomSet oo(*this);
		oo.erase(item);
		return oo;
	};
	CustomSet operator- (const CustomSet& that) {
		CustomSet oo(*this);
		for (typename vector<T>::const_iterator iter = that.cset.begin(); iter != that.cset.end(); ++iter) {
			oo.erase(*iter);
		}
		return oo;
	};
	CustomSet& operator-= (const T& item) {
		erase(item);
		return *this;
	};
	CustomSet& operator-= (const CustomSet& that) {
		for (typename vector<T>::const_iterator iter = that.cset.begin(); iter != that.cset.end(); ++iter) {
			erase(*iter);
		}
		return *this;
	};
	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item. 
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	// However, the difference between - and -= is not written here.
	// Try to figure out on your own!


	CustomSet<pair<T, T>> operator* (const CustomSet& that) {
		CustomSet<pair<T,T>> a;
		for(int m=0;m<m_size;m++){
			for(int n=0;n<that.m_size;n++){
				a.add(make_pair(cset[m],that.cset[n]));
			}
		}
		return a;
	};
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!

    vector<T>cset;int m_size; 
};
#endif
