#pragma once

class Ressource {

    private:
        int _stock;

    public:
        Ressource(int s=0): _stock(s) {}

        void consommer(int besoin){
            int tmp = _stock - besoin;
            if(tmp > 0) {
                _stock = _stock - besoin;
            } else {
                _stock = _stock - (besoin + tmp);
            }
        }

        int getStock() const {
            return _stock;
        }
};