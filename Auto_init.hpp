#pragma once

template<class T, T default_value>
class Auto_init {
    T t;
public:
    Auto_init(): t(default_value) {}
    Auto_init(T value): t(value) {}
    operator T() const { return t; }
};

template<class T>
class Auto_zero {
    T t;
public:
    Auto_zero(): t(0) {}
    Auto_zero(T value): t(value) {}
    operator T() const { return t; }
};

//Some predefined Auto_value types.
typedef Auto_init<bool, true> Auto_bool_true;
typedef Auto_init<bool, false> Auto_bool_false;
typedef Auto_init<char, '\0'> Auto_char;
typedef Auto_init<signed char, '\0'> Auto_schar;
typedef Auto_init<unsigned char, '\0'> Auto_uchar;
//Identifiers ending in _t are reserved.
typedef Auto_init<wchar_t, 0> Auto_wchar;
typedef Auto_init<short, 0> Auto_short;
typedef Auto_init<int, 0> Auto_int;
typedef Auto_init<long, 0> Auto_long;
typedef Auto_init<unsigned short, 0> Auto_ushort;
typedef Auto_init<unsigned int, 0> Auto_uint;
typedef Auto_init<unsigned long, 0> Auto_ulong;
//Float values cannot be template parameters. So we use Auto_zero instead.
typedef Auto_zero<float> Auto_float;
typedef Auto_zero<double> Auto_double;
typedef Auto_zero<long double> Auto_ldouble;

