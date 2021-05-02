#include "MyArr.h"
#include <iostream>

using namespace std;

void MyArr::expand(int size)
{
    if(max == size) return;
    if(size < len)
        len = size;
    double *temp = new double[size];
    for(int i = 0; i < len; i++)
    {
        temp[i] = arr[i];
    }
    delete [] arr;
    arr = temp;
}

MyArr::MyArr(const MyArr &a)
{
    max = a.max;
    len = a.len;
    arr = new double[max];
    for(int i = 0; i < len; i++)
    {
        arr[i] = a.arr[i];
    }
}

MyArr::MyArr(int n=256)
{
    max = n; len=0;
    arr = new double[max];
}

MyArr::MyArr(int n, double x)
{
    max = len = n;
    arr = new double[max];
    for(int i = 0; i < len; i++)
    {
        arr[i] = x;
    }
}

MyArr::~MyArr()
{
    delete[] arr;
}

MyArr &MyArr::operator=(const MyArr &a)
{
    if(this != &a)
    {
        max = a.max;
        len = a.len;
        delete[] arr;
        arr = new double[max];
        for(int i = 0; i < len; i++)
        {
            arr[i] = a.arr[i];
        }
    }   
    return *this;
}

double& MyArr::operator[](int i)
{
    if(i < 0 || i >= len)
    {
        cerr << "\n class MyArr: Out of range! ";
        exit(1);
    }
    return arr[i];
}

double MyArr::operator[](int i) const
{
    return arr[i];
}


void MyArr::append(double x)
{
    if(len >= max)
        expand(max + 1);
    arr[len++] = x;
}

void MyArr::append(const MyArr &a)
{
    if(a.len + len > max)
        expand(a.len + len);
    for(int i = 0; i < a.len; i++)
        arr[len++] = a[i];
}

bool MyArr::remove(int pos)
{
    if(pos < 0 || pos >= len)
        return false;

    for(int i = pos; i < len - 1; i++)
        arr[i] = arr[i + 1];
    --len;
    return true;
}

bool MyArr::insert(double x, int pos)
{
    return insert(MyArr(1, x), pos);
}

bool MyArr::insert(const MyArr &a, int pos)
{
    if(pos < 0 || pos > len) return false;
    if(max < len + a.len)
        expand(len + a.len);
    
    for(int i = len - 1; i >= pos; i--)
        arr[i + a.len] = arr[i];
    
    for(int i = 0; i < a.len; i++)
        arr[i + pos] = a.arr[i];
    
    len = len + a.len;
    return true;
}