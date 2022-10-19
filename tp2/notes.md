#### templates
----------------------

fichier .hxx pour les templates

pour l'inter dépendance : utiliser un fichier annexe pour declarer les templates

- never use "T *" in templates
- templates avec interdépendance ?
- https://www.geeksforgeeks.org/template-specialization-c/


- questions templates:
    - Sur-échantillonnage ?

    -  ```cpp 
        //c'étais un indice ? pour template Container STL ?
        namespace std {
            template<typename, typename>
            class vector;
        }
        ```
    - ```cpp
        template<template<typename ...> class Container, 
                typename Point>
        Point barycentre_v2(const Container<Point> & n) {
            //calcul
        }
        ```
    - ```cpp
        //why does this one work also ?
        //how to map it to the types ?
        template<template<typename ...> class Container, 
                typename Point,
                typename ... Args>
        Point barycentre_v2(const Container<Point, Args ...> & n) {
            //calcul
        }
        ```





- To do Bonus :   
rendre le conteneur de la class Nuage template, n'avoir qu'une seul méthode (pas fonction) barycentre et réussir à l'initialiser nuage comme ça:
```cpp
    Nuage<typename, std::vector<typename> > n;
    Nuage<typename, std::list<typename> > n_n;
```