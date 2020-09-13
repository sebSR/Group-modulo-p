#ifndef library_hpp
#define library_hpp
#include <iostream>


const int moduloInteger = 11;


class Modulo{
  private:
    int rest;
  public:
    static const std::string error[2];
    
    Modulo();
    Modulo(int n);
    ~Modulo();

    void set_rest(int n) noexcept;

    int extendedEuclidean(int a, int b) noexcept;
    int inverseElement() noexcept;

    friend std::ostream & operator<<(std::ostream &out, Modulo k) noexcept;
    friend std::istream & operator>>(std::istream &in, Modulo &k) noexcept;
    Modulo operator++() noexcept;
    Modulo operator--() noexcept;
    Modulo operator+(const Modulo &k) noexcept;
    Modulo operator-(const Modulo &k) noexcept;
    Modulo operator*(const Modulo &k) noexcept;
    Modulo operator/(const Modulo &k) noexcept(false);
    Modulo & operator=(const Modulo &k) noexcept;
    bool operator>(const Modulo &k) noexcept;
    bool operator<(const Modulo &k) noexcept;
    bool operator>=(const Modulo &k) noexcept;
    bool operator<=(const Modulo &k) noexcept;
    bool operator==(const Modulo &k) noexcept;
    bool operator!=(const Modulo &k) noexcept;
};

#endif
