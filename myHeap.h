#ifndef _MYHEAP_H_
#define _MYHEAP_H_
#include <vector>

template <class T>
class heap
{
public:
    int size() { return n; }
    int top() { return h[0]; }
    bool empty() { return n == 0; }
    void push(T a)
    {
        h.push_back(a);
        SiftUp(n);
        n++;
    }
    void pop()
    {
        n--;
        std::swap(h[n], h[0]);
        h.pop_back();
        SiftDown(0);
    }
    void clear()
    {
        h.clear();
        n = 0;
    }
    T operator[] (int a)
    {
        return h[a];
    }
   
private:
    std::vector<T> h;
    int n = 0;
    void SiftUp(int a)
    {
        while (a)
        {
            int p = (a - 1) / 2;
            if (h[p] > h[a])
                std::swap(h[p], h[a]);
            else break;
            a--; a /= 2;
        }
    }
    void SiftDown(int a)
    {
        while (2 * a + 1 < n)
        {
            int left = 2 * a + 1;
            int right = 2 * a + 2;
            if (right == n)
            {
                if (h[left] < h[a])
                    std::swap(h[left], h[a]);
                break;
            }
            else if (h[left] <= h[right])
            {
                if (h[left] < h[a])
                {
                    std::swap(h[left], h[a]);
                    a = left;
                }
                else break;
            }
            else if (h[right] < h[a])
            {
                std::swap(h[right], h[a]);
                a = right;
            }
            else break;
        }
    }
};

void heapsort(int* left, int* right)
{
    heap<int> h;
    for (int* i = left; i < right; i++)
        h.push(*i);
    for (int* i = left; i < right; i++)
    {
        *i = h.top();
        h.pop();
    }
}

void heapsort(std::vector<int> &a, int left, int right)
{
    heap<int> h;
    for (int i = 1; i < right; i++)
        h.push(a[i]);
    for (int i = left; i < right; i++)
    {
        a[i] = h.top();
        h.pop();
    }
}

void heapsort(std::vector<int> &a)
{
    heapsort(a, 0, a.size());
}


#endif