# Auto_value

I originally wrote **Auto_value** about 2001/2002. I then fell into a tarpit of
Java for a few years and was forgotten about until I needed it again.

## The problem

Consider this toy class:

    class Foo {
        bool    my_flag;
        int     my_i;
        double  my_d;
    public:
        Foo()         : my_flag(false), my_i(0), my_d(0.0)  {}
        Foo(bool b)   : my_flag(b),     my_i(0), my_d(0.0)  {}
        Foo(int n)    : my_flag(false), my_i(n), my_d(0.0)  {}
        Foo(double d) : my_flag(false), my_i(0), my_d(d)    {}
        //...
    };

For each constructor, I have to initialize all the members of built-in types.
This is fragile and error prone.

The **Auto_value** template improves things.

## What is Auto_value?

**Auto_value** is a simple template. It takes a type and a default value. It is
implicitly convertible to and from the type. If not explicitly initialized,
it will be initialized with the default value.

Some types, however, cannot be template parameters. (Like float.) If the type
can be initialized with a literal zero, however, you can at least use the
**Auto_zero** template to make sure they are initialized to zero.

## The fix

    class Foo {
        Auto_value<bool, false> my_flag;
        Auto_value<int, 0>      my_i;
        Auto_zero<double>       my_d;
    public:
        Foo()                       {}
        Foo(bool b)   : my_flag(b)  {}
        Foo(int n)    : my_i(n)     {}
        Foo(double d) : my_d(d)     {}
        //...
    };

Now, all my member variables get initialized automatically. In my ctor
initialization lists, I only have to mention the ones I want to give a
different value.

