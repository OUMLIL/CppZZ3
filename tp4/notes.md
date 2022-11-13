### Questions
-----------------------


- La suppression de la construction par copie et affectation par copie m'oblige de créer explicitement un constructeur par défaut ?
    ```cpp
        // error: no matching function for call to ‘UsineCarte::UsineCarte()’
        //  24 |  UsineCarte usine;
        UsineCarte(UsineCarte & inUsineCarte) = delete;
        UsineCarte & operator=(UsineCarte & inUsineCarte) = delete;
    ```

    ```cpp
        UsineCarte() {}
    ```