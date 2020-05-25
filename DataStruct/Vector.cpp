#include <iostream>
#include <vector>
using namespace std;
vector<int> temp;
template <typename T>
class Vector
{
public:
    Vector();
    Vector(int size);
    Vector(int size, T value);
    Vector(const Vector &rhs); // 복사연산자
    Vector& operator=(const Vector &rhs); // 대입연산자

    T push_back(T value);
    T pop_back();
    void erase(int index);
    void insert(int index, T value);
    void clear();
    bool empty() const;
    int size() const;
    T front() const;
    T& operator[](int index);
    
    ~Vector();

private:
    T *arr = nullptr;
    int _index = 0;
    int _size = 0;
    int _real_size = 0;
    const int _d_size = 1000;

    bool isTail(int index) const
    {
        return _size == index + 1;
    }
    void makeBigger()
    {
        T *temp = arr;
        arr = new T[_real_size + 1000];
        for(int i = 0; i < _size; i++)
        {
            arr[i] = temp[i];
        }

        _real_size = _real_size + 1000;
        delete[] temp;
    }
};

template <typename T>
Vector<T>::Vector()
{
    arr = new T[_d_size];
    _index = 0;
    _size = 0;
    _real_size = _d_size;
}
template <typename T>
Vector<T>::Vector(int size) : _size(size)
{
    if (size > _d_size)
    {
        arr = new T[size + 1000];
        _real_size = size + 1000;
        _index = 0;
        fill_n(arr, size, 0);
        return;
    }

    if(size < 0)
    {
        cout << "Can't make minus size Vector\n";
    }    
    
    arr = new T[_d_size];
    fill_n(arr, size, 0);
    _real_size = _d_size;
    _index = 0;
}
template <typename T>
Vector<T>::Vector(int size, T value) : _size(size)
{
    if(size > _d_size)
    {
        arr = new T[size + 1000];
        fill_n(arr, size + 1000, value);
        _real_size = size + 1000;
        _index = size;
        return;
    }

    if(size < 0)
    {
        cout << "Can't make minus size Vector\n";
    }
    arr = new T[_d_size];
    fill_n(arr, size, value);
    _real_size = _d_size;
    _index = size;
}
template <typename T>
Vector<T>::Vector(const Vector &rhs)
{
    if(rhs._size > this->_real_size)
    {
        arr = new T[rhs._real_size];
    }

    for(int i = 0; i < rhs._size; i++)
    {
        arr[i] = rhs.arr[i];
    }
    _index = rhs._index;
    _size = rhs._size;
    _real_size = rhs._real_size;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector &rhs)
{
    if(rhs._size > this->_real_size)
    {
        delete[] arr;
        arr = new T[rhs._real_size];        
    }

    for(int i = 0; i < rhs._size; i++)
    {
        arr[i] = rhs.arr[i];
    }

    _index = rhs._index;
    _size = rhs._size;
    _real_size = rhs._real_size;

    return *this; 
}
template <typename T>
T& Vector<T>::operator[](int index)
{
    if(index >= _size || index < 0)
    {
        cout << "out of bounds. return strange\n";
    }

    return this->arr[index];
}
template <typename T>
T Vector<T>::push_back(T value)
{
    if(_size > _real_size)
    {
        makeBigger();
    }

    arr[_index] = value;
    _index++;
    _size++;
    return arr[_index-1];
}
template <typename T>
T Vector<T>::pop_back()
{
    if(_size == 0)
    {
        cout << "No elements\n" << endl;
        return 0;
    }

    _index--;
    _size--;
    return arr[_index+1];
}
template <typename T>
void Vector<T>::erase(int index)
{
    if(index < 0 || index >= _size)
    {
        cout << "out of bounds\n";
        return;
    }

    if(this->isTail(index-1))
    {
        _size--;
        _index--;
        return;
    }

    for(int i = index - 1; i < _size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    _size--;
    _index--;
}
template <typename T>
void Vector<T>::insert(int index, T value)
{
    if(index < 0)
    {
        cout << "out of bounds\n";
        return;
    }

    if(_size >= _real_size)
    {
        makeBigger();
    }
    _size++;
    _index++;
    T temp = arr[index];
    for(int i = index; i < _size; i++)
    {
        T temp2 = arr[i+1];
        arr[i+1] = temp;
        temp = temp2;
    }
    arr[index] = value;
}
template <typename T>
void Vector<T>::clear()
{
    _size = 0;
    _index = 0;
}
template <typename T>
bool Vector<T>::empty() const
{
    return _size == 0;
}
template <typename T>
int Vector<T>::size() const
{
    return _size;
}
template <typename T>
T Vector<T>::front() const
{
    if(_size == 0)
    {
        cout << "No elements. return 0\n";
        return 0;
    }
    return arr[0];
}
template <typename T>
Vector<T>::~Vector()
{
    delete[] arr;
}

int main(void)
{
    Vector<int> vec;
    for(int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    Vector<int> vec2(1001);
    int count = 0;
    for(int i = 0; i < vec2.size(); i++)
    {
        count++;
    }
    cout << count;
    
    
    system("pause");
    return 0;
}