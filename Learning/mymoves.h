#pragma once
#include <vector>

using namespace std;

// make our own version of std::vector with copying disabled
template<class T> class MyVector : public vector<T> {
public:

    // implement the same constructors as vector defines
    MyVector() :vector<T>() {}
    MyVector(int size) :vector<T>(size) {}
    MyVector(std::initializer_list<T> l) :vector<T>(l) {}
    MyVector( MyVector&& v) :vector<T>(v) {} // don't forget the move constructor!
   
private:

    // disable copying
    MyVector(const MyVector& v) :vector<T>(v) {}
    MyVector& operator=(const MyVector& v) { vector<T>(v); }
};

class MoveSemanticsTest {
public:
    static void doTests() {
        vector<vector<int>>   vv1;
        vector<MyVector<int>> vv2;

        vv1.push_back({ 1,2,3,4 }); // this works with std::vector, using move constructor
        vv2.push_back({ 1,2,3,4 }); // this works with MyVector, using move constructor

        vector<int>   v1{ 1,2,3,4 };
        MyVector<int> v2{ 1,2,3,4 };

        vv1.push_back(v1); // this works with std::vector, but will be doing a full copy!
        vv2.push_back(std::move(v2)); // this gives a compile error with MyVector, as we've disabled copying!
    }
};