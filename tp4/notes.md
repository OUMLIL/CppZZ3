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
- shared_ptr can't be initialized with nullptr ?
    ```cpp
        std::shared_ptr<Ressource> _rsrc_ptr{nullptr}; //OK
        std::shared_ptr<Ressource> _rsrc_ptr(nullptr); //NOK

        std::unique_ptr<Carte> p(nullptr); //OK?
    ```
- reset bug
    ```cpp
        rsrc_ptr.reste(nullptr); //NOK
    ```
    