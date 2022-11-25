## sets
---------------------
- why set stores const elements only ?
    ```
    A set is like a map with no values, only keys. Since those keys are used for a tree that accelerates operations on the set, they cannot change. Thus all elements must be const to keep the constraints of the underlying tree from being broken.
    ```

## gdb 
--------------------
``` cpp
bt                  // backtrace
up <numfunction>
p <variable>        // print
ptype <variable>    // find type of value 
break filename:line

//know that gdb is smart he can get data inside iterator so ptype can be usefull


```

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


## other:
```cpp
//! comparison object must be invocable as const
        bool operator()(const TypeToCompare & c1, const TypeToCompare & c2) const {
            return c1.getQuantite() < c2.getQuantite();
        }
```