#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()

    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    void Resize(int NewSize)
    {

        if (NewSize < 0)
        {
            NewSize = 0;
        };

        _TempArray = new T[NewSize];

        //limit the original size to the new size if it is less.
        if (NewSize < _Size)
            _Size = NewSize;

        //copy all data from original array until the size
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize;

        delete[] OriginalArray;
        OriginalArray = _TempArray;

    }

    T GetItem(int Index)
    {
        if (Index < 0 || Index >= _Size)
        {
            return 0;
        }

        return OriginalArray[Index];
    }

    void Reverse()
    {
        _TempArray = new T[_Size];
        int temp = _Size-1;
        for (int i = 0 ; i < _Size ; i++)
        {
            _TempArray[i] = OriginalArray[temp--];
        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;

    }

    void Clear()
    {
        delete[] OriginalArray;
        OriginalArray = nullptr;
        _Size = 0;
    }

    bool DeleteItemAt(int index)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        _Size--;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        //copy all after index
        for (int i = index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);

    }

    bool DeleteLastItem()
    {
        return DeleteItemAt(_Size - 1);
    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
                return i;

        }
            return -1;
    }

    bool DeleteItemByValue(T Value)
    {
        int Index = Find(Value);

        if (Index != -1)
        {
            return DeleteItemAt(Index);
        }
        return false;
    }

    bool InsertAt(T index, T value) {

        if (index > _Size || index < 0)
        {
            return false;
        }

        _Size++;

        _TempArray = new T[_Size];

        //copy all before index
        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _TempArray[index] = value;

        //copy all after index
        for (int i = index; i < _Size - 1; i++)
        {
            _TempArray[i + 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    bool InsertAtBeginning(T Value)
    {
        return InsertAt(0, Value);
    }

    bool InsertBefore(int Index, T Value)
    {
        return InsertAt(Index - 1, Value);
    }

    bool InsertAfter(int Index, T Value)
    {
        return InsertAt(Index + 1, Value);
    }

    bool InsertAtEnd(T Value)
    {
        return InsertAt(_Size, Value);
    }
};


