#pragma once

#include <memory>
#include <ressource.hpp>

class Consommateur {
    private:
        std::shared_ptr<Ressource> _rsrc_ptr{nullptr};
        int _besoin{};
        
    public:
        //? ownership sur valeur -> send param by copy
        //! smart pointers pass by copy
        //? voir effective modern cpp :  annexe passage string, string &, string &&
        Consommateur(int besoin, std::shared_ptr<Ressource> rsrc_ptr):
             _rsrc_ptr(rsrc_ptr), _besoin(besoin) {
        }

        //shouldn't be const method because it modifies _rsrc_ptr
        void puiser() {
            if(!_rsrc_ptr) return;

            if(_rsrc_ptr->getStock() >= 0) {
                _rsrc_ptr->consommer(_besoin);
            } 

            if(_rsrc_ptr->getStock() == 0) {
               _rsrc_ptr = nullptr;
            }
        }

};

using ressources_t = std::vector<std::weak_ptr<Ressource>>; 


//TODO: sortir lambda de l'opérateur
inline std::ostream & operator<<(std::ostream & ss, const ressources_t & ressources) {
    if(ressources.size() == 0) {
        return ss;
    }

    std::stringstream tmp{};
    std::transform(ressources.begin(), ressources.end(), 
                    std::ostream_iterator<std::string>(tmp, " "), 
                    [](std::weak_ptr<Ressource> x) {
                        if(!x.expired()) {
                            auto pw = x.lock();
                            if(pw) {
                                std::string tp_print = std::to_string(pw->getStock());
                                std::cout << tp_print << " ";
                                return "5";
                            } else {
                                return "-";
                            }
                        } else {
                            return "-";
                        }
                    });
    ss << tmp.str();

    return ss;
}