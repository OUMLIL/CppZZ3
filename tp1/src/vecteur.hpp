#pragma once

#include <iostream>
#include <cassert>

class vecteur {

    private:
        int _capacity{-1}; 
        int _nbelements{0};
        int * _array{nullptr};

        void alloc(int capacite) {
            if(capacite) {
                try {
                    _array = new int[capacite];
                } catch(std::bad_alloc &e) {
                    e.what();
                    delete[] _array;
                    _capacity = -1;
                    _nbelements = 0;
                    _array = nullptr;
                    throw;
                }
            }
        }
    
    public:
        //constructeur defaut
        vecteur(int cap=10):_capacity(cap), _nbelements(0) {
            alloc(cap);
        }

        //constructeur copie
        vecteur(const vecteur & v) {
            _capacity = v._capacity;
            _nbelements = v._nbelements;
            alloc(_capacity);
            std::copy(v._array, v._array+_nbelements, _array);
        }
        
        //destructeur 
        ~vecteur() {
            delete[] _array;
        }

         //exception
        class OutOfRangeException : public std::out_of_range {
            public:
                OutOfRangeException(std::string s=""): std::out_of_range(s){};
                const char * what() const noexcept {
                    const char * err = "out of range exception";
                    return err;
                }
        };

        //operateur copie
        vecteur & operator=(const vecteur & v) {
            if(&v != this) {
                this->~vecteur();
                _capacity = v._capacity;
                _nbelements = v._nbelements;
                alloc(v._capacity);
                std::copy(v._array, v._array+_nbelements, _array);
            }            
            return *this; 
        }

        size_t size() const {
            return _nbelements;
        }

        int capacity() const {
            return _capacity;
        }


        //operateurs
            //lecture
        int operator[](int id) const {
            if(id < 0 || id > _nbelements) {
                throw OutOfRangeException();
            } 
            return _array[id];
        }   
            //lecture_ecriture
        int & operator[](int id) {
            if(id < 0 || id > _nbelements) {
                throw OutOfRangeException();
            } 
            return _array[id];
        }

        //begin, end
        const int * begin() const {
            return _array;
        }

        const int * end() const {
            return _array + _nbelements;
        }

        //add
        // void push_back(int element) {
        //     if(_nbelements == _capacity) {
        //         //exception ?? //alloc ok ??
        //         void * tmp = std::realloc(_array, (_capacity * 2) * sizeof(int));
        //         _array = static_cast<int*>(tmp);
        //         _capacity = _capacity * 2;
        //     }
        //     _array[_nbelements] = element;
        //     _nbelements++;
        // }

        void push_back(int element) {
            if(_nbelements == _capacity) {
                //exception ?? //alloc ok ??
                int * tmp = new int[2*_capacity];
                std::copy(begin(), end(), tmp);
                delete[] _array;
                _array = static_cast<int*>(tmp);
                _capacity = _capacity * 2;
            }
            _array[_nbelements] = element;
            _nbelements++;
        }
    friend vecteur operator+(vecteur & v1, vecteur & v2);
    friend int operator*(const vecteur & v1, const vecteur & v2);
};

std::ostream & operator<<(std::ostream & ss, const vecteur & v);
