//crated by: Redan Ganim
#include "Equation.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

Equation::Equation(double a,double b,double c)
    :m_a{a}
    ,m_b{b}
    ,m_c{c}
    ,solutions{nullptr}
    ,solutions_size{0}
    {
        if(m_a==0.0)
            throw std::invalid_argument("a cant be zero\n");
        double discriminant = m_b*m_b-4.0*m_a*m_c;
        if(discriminant>0.0)//2 solutions
        {
            solutions_size=2;
            solutions=new double[2];
            solutions[0]=(-m_b+ std::sqrt(discriminant))/(2.0*m_a);//(−B + √(B2 − 4AC) )/ 2A
            solutions[1]=(-m_b- std::sqrt(discriminant))/(2.0*m_a);//(−B - √(B2 − 4AC) )/ 2A
        }
        else if(discriminant==0.0){
            solutions_size=1;
            solutions=new double[1];
            solutions[0]=-m_b/(2.0*m_a);
        }
        else{
            solutions_size=0;
            solutions=nullptr;
        }
    }
Equation::~Equation(){
    delete[] solutions;
    solutions=nullptr;
}
Equation::Equation(const Equation& other)
    :m_a{other.m_a}
    ,m_b{other.m_b}
    ,m_c{other.m_c}
    ,solutions_size{other.solutions_size}
    ,solutions{other.solutions? new double[other.solutions_size]:nullptr}
    {
        for (size_t i = 0; i < other.solutions_size; i++)
        {
            solutions[i]=other.solutions[i];
        }
        
    }
Equation::Equation(Equation&& other)noexcept
    :m_a{other.m_a}
    ,m_b{other.m_b}
    ,m_c{other.m_c}
    ,solutions_size{other.solutions_size}
    ,solutions{other.solutions}
{//move
    other.solutions_size=0;
    other.solutions=nullptr;
}
Equation& Equation::operator=(const Equation& other){
    if(this!=&other){
        m_a=other.m_a;
        m_b=other.m_b;
        m_c=other.m_c;
        delete[]solutions;
        solutions_size=other.solutions_size;
        solutions=other.solutions? new double[other.solutions_size]:nullptr;
        for (size_t i = 0; i < other.solutions_size; i++)
        {
            solutions[i]=other.solutions[i];
        }
    }
    return *this;
}
Equation& Equation::operator=(Equation&& other)noexcept{
    if(this!=&other){
        m_a=other.m_a;
        m_b=other.m_b;
        m_c=other.m_c;
        delete[] solutions;
        solutions_size=other.solutions_size;
        solutions=other.solutions;
        other.solutions=nullptr;
        other.solutions_size=0;
    }
    return *this;
}


double Equation::get_a()const{
    return m_a;
}
double Equation::get_b()const{
    return m_b;
}
double Equation::get_c()const{
    return m_c;
}
void Equation::set_a(double number){
    if(number==0.0)
        throw std::invalid_argument("a cant be zero\n");
    else
        m_a=number;
}
void Equation::set_b(double number){
    m_b=number;
}
void Equation::set_c(double number){
    m_c=number;
}
std::size_t Equation::get_solutions_size() const{
    return solutions_size;
}
double const * Equation::get_solutions() const{
    return solutions;
}

Equation Equation::operator+(const Equation& other) const{//for obj+obj
    
}
Equation Equation::operator+(double)  const{//for obj+double
}

Equation operator+(double a,const Equation& q){//for double+obj
}
std::ostream& operator <<(std::ostream& out,const Equation& q){

}