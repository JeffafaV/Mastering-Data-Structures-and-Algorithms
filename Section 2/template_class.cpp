#include <iostream>

using namespace std;

// template class
// templates allows the user to insert different data types
template <class T> // add this above class and all functions that uses T
class Arithmetic
{
	private:
    T a; // change data type to T
    T b;
    
	public:
    Arithmetic(T a, T b); // contructor with parameters
    
    T add(); // returning addition of type T
    T sub(); // returning subtraction of type T
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a; // set variable in class to parameter with same name using this pointer
    this->b = b;
}

template <class T>
T Arithmetic<T>::add() // add the <T> to class function headers
{
    T c;
    c = a + b;
    return c;
}

template <class T>    
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
	// insert <> with data type in it
    Arithmetic<double> ar = Arithmetic<double>(5.55, 3.33);
    
    cout << "Add " << ar.add() << endl;
    cout << "Subtract " << ar.sub() << endl;
    
    return 0;
}
