### virtual destructors
----------------------------
    -   A should be virtual because:
```cpp
    A * b = new B();
    delete b; //if ~A() not virtual it'll call A's destructor
```
    -   Solution:
```cpp
    class A : {
        virtual ~A();
    };
    class B : public A {
        ~B();
    };
```

### fonction convertir
---------------------------
testing

