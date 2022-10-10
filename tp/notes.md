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

### Fonction convertir
---------------------------
forward declaration : need .cpp or put everything in the same header

### Iterator STL/C++
--------------------------
https://gist.github.com/jeetsukumaran/307264
https://segmentfault.com/a/1190000040879971/en

    -   barycentre getX / getY should be virtual ??
        //use convertir to convert every element to calculate after the barycentre
    -   iterator à revoir, any remarks?


### Exo2 vecteurs
----------------------------
    -   delete on C alloc vs delete on std::realloc ??