#pragma once


class Carte {
    private:
        static int _construction_deconstruction_counter;
        int _valeur_carte{};
        Carte() { //default constructor
            _construction_deconstruction_counter++;
        } 
        Carte(int v): _valeur_carte(v) { //constructor using value
            _construction_deconstruction_counter++;
        }; 
    public:

        Carte(Carte & inCarte) = delete;
        Carte & operator=(Carte & inCarte) = delete;

        int getValeur() const {
            return _valeur_carte;
        }

        static int getCompteur() {
            return _construction_deconstruction_counter;
        }

        ~Carte() {
            _construction_deconstruction_counter--;
        }
        friend class UsineCarte;
};