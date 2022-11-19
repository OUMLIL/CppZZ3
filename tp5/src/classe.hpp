#pragma once


class Classe {
    private:
        double _borne_inf;
        double _borne_sup;
        unsigned _quantite;
    public:
        Classe(double inf, double sup):_borne_inf(inf), _borne_sup(sup) {
            _quantite = 0u;
        }

        double getBorneInf() const {
            return _borne_inf;
        }

        double getBorneSup() const {
            return _borne_sup;
        }

        double getQuantite() const {
            return _quantite;
        }

        void setBorneInf(double inf) {
            _borne_inf = inf;
        }

        void setBorneSup(double sup) {
            _borne_sup = sup;
        }

        void setQuantite(unsigned qte) {
            _quantite = qte;
        }


        void ajouter() {
            _quantite++;
        }



};