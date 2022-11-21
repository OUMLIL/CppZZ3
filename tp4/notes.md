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
    Solution -> mettre le = default;

- shared_ptr can't be initialized with nullptr ?
    ```cpp
        std::shared_ptr<Ressource> _rsrc_ptr{nullptr}; //OK
        std::shared_ptr<Ressource> _rsrc_ptr(nullptr); //NOK
        //doc: section  standard 11.4.1.7.5 

        std::unique_ptr<Carte> p(nullptr); //OK?
    ```
- reset bug
    ```cpp
        rsrc_ptr.reset(nullptr); //NOK 
        rsrc_ptr = nullptr;
    ```

- std::transform
    ```cpp
        tr(begin, eng, out, d)
        d: U(ensemble des pointeurs uniques) -> Z(ensemble des entier)
        o = d(begin --> end) //so o will take in ints as input
    ```

- some usefill flags
    ```cpp 
        -fmax-errors = 2 //au bout de 2 erreurs compilo arrête
        -Wfatal-errors //only errors pas de notes
        //some commands
        !m -> make
        !gd -> gdb
        !t -> exec
    ```