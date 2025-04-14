#include <iostream>
#include <stdexcept>
#include <limits>

template <typename T>
class GenericArray 
{
private:
    T* data;
    int length;

public:
    GenericArray() : data(nullptr), length(0) {}

    ~GenericArray() 
    {
        delete[] data;
    }

    void addElement(T value) 
    {
        T* new_data = new T[length + 1];
        for (int i = 0; i < length; ++i) 
        {
            new_data[i] = data[i];
        }
        new_data[length] = value;
        delete[] data;
        data = new_data;
        ++length;
    }

    T at(int index) const 
    {
        if (index < 0 || index >= length) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int size() const 
    {
        return length;
    }

    T sum() const 
    {
        T total = 0;
        for (int i = 0; i < length; ++i) 
        {
            total += data[i];
        }
        return total;
    }

    T max() const 
    {
        if (length == 0) throw std::runtime_error("Array is empty");
        T maximum = data[0];
        for (int i = 1; i < length; ++i) 
        {
            if (data[i] > maximum) 
            {
                maximum = data[i];
            }
        }
        return maximum;
    }

    T min() const 
    {
        if (length == 0) throw std::runtime_error("Array is empty");
        T minimum = data[0];
        for (int i = 1; i < length; ++i) 
        {
            if (data[i] < minimum) 
            {
                minimum = data[i];
            }
        }
        return minimum;
    }

    T* slice(int begin, int end) const 
    {
        if (begin < 0 || end >= length || begin > end) 
        {
            throw std::out_of_range("Invalid slice range");
        }
        int new_size = end - begin + 1;
        T* new_array = new T[new_size];
        for (int i = 0; i < new_size; ++i) 
        {
            new_array[i] = data[begin + i];
        }
        return new_array;
    }
};
int main() 
{
    GenericArray<int> int_array;
    int_array.addElement(0);
    int_array.addElement(2);
    int_array.addElement(4);
    int_array.addElement(6);
    int_array.addElement(8);
    int_array.addElement(10);
    int_array.addElement(12);

    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is " << int_array.max()
              << "\t" << int_array.min() << std::endl;

    try 
    {
        int* sliced_array = int_array.slice(2, 4);
        std::cout << "Sliced array (2 to 4): ";
        for (int i = 0; i <= 4 - 2; ++i) 
        {
            std::cout << sliced_array[i] << " ";
        }
        std::cout << std::endl;
        delete[] sliced_array;
    } catch (std::exception& e) 
    {
        std::cerr << "Slice error: " << e.what() << std::endl;
    }

    return 0;
}
