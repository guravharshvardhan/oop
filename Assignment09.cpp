#include <iostream>
using namespace std;

// Template function to find maximum
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template class for Calculator
template <typename T>
class Calculator {
    T num1, num2;

public:
    Calculator(T a, T b) {
        num1 = a;
        num2 = b;
    }

    T add() {
        return num1 + num2;
    }

    T subtract() {
        return num1 - num2;
    }

    T multiply() {
        return num1 * num2;
    }

    T divide() {
        return num1 / num2;
    }
};

int main() {
    // Using template function
    cout << "Max of 5 and 10 is: " << findMax(5, 10) << endl;

   cout<<"\nInteger operations"<<endl;
    Calculator<int> intCalc(5, 10);
    cout << "1) Addition : " << intCalc.add() << endl;
    cout << "2) Subtraction : " << intCalc.subtract() << endl;
     
    cout<< "\nFloat operations"<<endl;
    Calculator<float> floatCalc(3.5f, 2.0f);
    cout << "1) Multiplication : " << floatCalc.multiply() << endl;
    cout << "2) Division : " << floatCalc.divide() << endl;

    cout<<"\nDouble operations"<<endl;
    Calculator<double> doubleCalc(7.25, 2.5);
    cout << "1) Addition : " << doubleCalc.add() << endl;
    cout << "2) Subtraction : " << doubleCalc.subtract() << endl;
    cout << "3) Multiplication : " << doubleCalc.multiply() << endl;
    cout << "4) Division : " << doubleCalc.divide() << endl;

    return 0;
}
