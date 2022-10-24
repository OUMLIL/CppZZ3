#pragma once

#include <demangle.hpp>
#include <exception>
#include <typeinfo>
#include <sstream>
#include <iomanip>




class ExceptionChaine : public std::exception {
    private:
    const std::type_info & _type_info;
    std::string _type_info_name;
    public:
        
        //constructor
        template<typename Unsupported_type>
        ExceptionChaine(Unsupported_type _T): _type_info(typeid(_T)) { 
            std::ostringstream oss;
            oss << "Conversion en chaine impossible pour '" 
                << demangle(typeid(_T).name()) 
                << "'";
            _type_info_name = oss.str();
        }

        //what
        const char * what() const noexcept override{
            return _type_info_name.c_str();
        }

        const std::type_info & get_type_info() const {
            return _type_info;
        }

};

template<typename Type_to_convert>
std::string chaine(Type_to_convert obj) {
    std::string res{};
    throw ExceptionChaine {obj};
    return res;
} 


template<>
std::string chaine<>(std::string input) {
    return input;
}

template<>
std::string chaine(int input) {
    std::ostringstream oss;
    oss << std::to_string(input);
    return oss.str();
}

template<>
std::string chaine(double input) {
    std::ostringstream oss;
    oss << std::to_string(input);
    return oss.str();
}