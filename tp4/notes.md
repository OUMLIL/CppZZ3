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
        rsrc_ptr.reste(nullptr); //NOK 
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
        -Wfatal-errors //only errors pas de not
        //some commands
        !m -> make
        !gd -> gdb
        !t -> exec
    ``` 

    ```shell
    gdb tp4_test 
GNU gdb (Debian 10.1-1.7) 10.1.90.20210103-git
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from tp4_test...
(gdb) r
Starting program: /mnt/local.isima.fr/aboumil/CppZZ3/CppZZ3/tp4/build/tp4_test 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 

Program received signal SIGSEGV, Segmentation fault.
0x00005555557a9310 in Ressource::getStock (this=0x0) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/src/ressource.hpp:21
21                  return _stock;
(gdb) bt
#0  0x00005555557a9310 in Ressource::getStock (this=0x0) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/src/ressource.hpp:21
#1  0x00005555557a9406 in Consommateur::puiser (this=0x5555558430b0) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/src/consommateur.hpp:20
#2  0x00005555557a7c52 in C_A_T_C_H_T_E_S_T_20 () at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/tp4_test.cpp:227
#3  0x00005555556ff91a in Catch::TestInvokerAsFunction::invoke (this=0x5555558419f0) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:14332
#4  0x00005555556fec81 in Catch::TestCase::invoke (this=0x555555849400) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:14171
#5  0x00005555556f99b3 in Catch::RunContext::invokeActiveTestCase (this=0x7fffffffd550) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13027
#6  0x00005555556f9737 in Catch::RunContext::runCurrentTest (this=0x7fffffffd550, redirectedCout="", redirectedCerr="") at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13000
#7  0x00005555556f83ce in Catch::RunContext::runTest (this=0x7fffffffd550, testCase=...) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:12761
#8  0x00005555556fb0df in Catch::(anonymous namespace)::TestGroup::execute (this=0x7fffffffd540) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13354
#9  0x00005555556fc340 in Catch::Session::runInternal (this=0x7fffffffd850) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13564
#10 0x00005555556fc089 in Catch::Session::run (this=0x7fffffffd850) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13520
#11 0x0000555555736169 in Catch::Session::run<char> (this=0x7fffffffd850, argc=1, argv=0x7fffffffdae8) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:13238
#12 0x0000555555711053 in main (argc=1, argv=0x7fffffffdae8) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/test/catch.hpp:17537
(gdb) up
#1  0x00005555557a9406 in Consommateur::puiser (this=0x5555558430b0) at /home/local.isima.fr/aboumil/shared/CppZZ3/CppZZ3/tp4/src/consommateur.hpp:20
20                  if(_rsrc_ptr->getStock() >= 0) {
(gdb) list
15
16              }
17
18              //shouldn't be const method because it modifies _rsrc_ptr
19              void puiser() {
20                  if(_rsrc_ptr->getStock() >= 0) {
21                      _rsrc_ptr->consommer(_besoin);
22                  } 
23
24                  if(_rsrc_ptr->getStock() == 0) {
(gdb) b Conso

    ```


