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
    DVector(unsigned int len);
    DVector<T>(const DVector<T>& temp);
    DVector<T> &operator=(const DVector<T>& temp);
    T& operator[](unsigned int x) const;
    void insert(int loc, T val);
    void remove(unsigned int loc);
    void pushback(T val);
    void popback();
    T* getData() const;
    int getSize() const;
    void resize();
    void sortVec();
    void sortManual();
private:
    T* data;
    int capacity;
    int size;
};

#endif // DVECTOR_H
