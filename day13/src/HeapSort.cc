#include <queue>
#include <iostream>
#include <array>

using namespace std;

template <typename T, typename Compare = std::less<T> >
class HeapSort
{
public:
    void operator()(T* beg, T* end)
    {
        _it = beg;
        _size = end - beg;
        heapAdjust();
        sort();
    }
    void heapAdjust();
    void sort();
private:
    T* _it;
    int _size;
    priority_queue<T, vector<T>, Compare> _heap;
};

template <typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust()
{
    for (int i = 0; i < _size; ++i)
    {
        _heap.push(*(_it + i));
    }
}

template <typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
    for (int i = 0; i < _size; ++i)
    {
        *(_it + i) = _heap.top();
        _heap.pop();
    }
}

int main()
{
    std::array<int, 5> a = {4, 3 ,4, 5, 2};
    HeapSort<int> x;
    x(a.begin(), a.end());
    for (auto i = a.begin(); i != a.end(); i++)
    {
        printf("%d\n", *i);
    }
    
    return 0;
}