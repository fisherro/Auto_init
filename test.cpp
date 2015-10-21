#include "Auto_init.hpp"
#include <iostream>
#include <sstream>

class Auto_init_test {
    Auto_init<bool, true>   bool_true;
    Auto_init<bool, false>  bool_false;
    Auto_init<int, 0>       int_zero;
    Auto_init<int, INT_MAX> int_max;
    Auto_init<int, INT_MIN> int_min;
    Auto_zero<double>       double_zero;
    Auto_zero<const char*>  ptr_null;

public:
    Auto_init_test() {}
    Auto_init_test(bool bt): bool_true(bt) {}
    Auto_init_test(int imax): int_max(imax) {}
    Auto_init_test(double d): double_zero(d) {}
    Auto_init_test(const char* p): ptr_null(p) {}

    void test()
    {
        std::ostringstream oss;
        if (bool_true != true)
            oss << "bool_true " << (bool_true? "true": "false") << '\n';
        if (bool_false != false) oss << "bool_false " << bool_false << '\n';
        if (int_zero != 0) oss << "int_zero " << int_zero << '\n';
        if (int_max != INT_MAX) oss << "int_max " << int_max << '\n';
        if (int_min != INT_MIN) oss << "int_min " << int_min << '\n';
        if (double_zero != 0) oss << "double_zero " << double_zero << '\n';
        if (ptr_null != NULL)
            oss << "ptr_null " << (ptr_null? "not null": "null") << '\n';
        if (oss.str().empty()) oss << "ALL GOOD\n";
        std::cout << oss.str();
    }
};

int main()
{
    Auto_init_test test;
    test.test();
    Auto_init_test test2(false);
    test2.test();
    Auto_init_test test3(42);
    test3.test();
    Auto_init_test test4(3.14);
    test4.test();
    Auto_init_test test5("Hello");
    test5.test();
}
