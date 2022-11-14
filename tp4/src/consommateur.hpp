#pragma once

#include <iostream>
#include <memory>
#include <ressource.hpp>

class Consommateur {
    private:
        std::shared_ptr<Ressource> _rsrc_ptr;
        int _besoin;
        
    public:
        Consommateur(int besoin, std::shared_ptr<Ressource> & rsrc_ptr):
             _rsrc_ptr(rsrc_ptr), _besoin(besoin) {

        }

        void puiser() const {
            std::cout << "stock " << _rsrc_ptr->getStock() << "besoin " << _besoin << std::endl;
            if(_rsrc_ptr->getStock() > 0) {
                _rsrc_ptr->consommer(_besoin);
            } else {
               std::cout << "get c" << _rsrc_ptr.use_count() << std::endl;
            }
        }

};