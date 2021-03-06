#ifndef DVECTOR_H
#define DVECTOR_H
#include <utility>

using namespace std;



template <class T>
class DVector
{
public:
    DVector();
    ~DVector();
    DVector<T>(unsigned int len);
    T& operator[](unsigned int x) const;
    void insert(int loc, T val);
    void remove(unsigned int loc);
    void pushback(T val);
    void popback();
    T* getData() const;
    int getSize() const;
    void resize();
    void sortVec();
private:
    T* data;
    int capacity;
    int size;
};

#endif // DVECTOR_H
