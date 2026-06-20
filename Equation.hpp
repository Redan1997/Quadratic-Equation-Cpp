//crated by: Redan Ganim
#ifndef EQUATION_HPP
#define EQUATION_HPP

#include <cstddef>
#include <iostream>
class Equation {
    double a;//should not be zero at anycost
    double b;
    double c;
    double *solutions;
    std::size_t solutions_size;
public:
    double get_a()const;
    double get_b()const;
    double get_c()const;
    void set_a(double number);
    void set_b(double number);
    void set_c(double number);
    std::size_t get_solutions_size() const;
    double const * get_solutions() const;// - returns solutions

    Equation(double a,double b,double c);
    ~Equation();
    Equation(const Equation& other);//copy
    Equation(Equation&& other)noexcept;//move
    Equation & operator=(const Equation& other);//assignment
    Equation & operator=(Equation&& other)noexcept;//move assignment

    friend std::ostream& operator <<(std::ostream& out,const Equation& q);

    Equation operator+(const Equation& other) const;//for obj+obj
    Equation operator+(double)  const;//for obj+double

    friend Equation operator+(double a,const Equation& q);//for double+obj
};

#endif // EQUATION_HPP