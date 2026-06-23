//crated by: Redan Ganim
#include "Equation.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iomanip>
/*private helper function that update and recalculate the root soloution*/
void Equation::update_solutions(){
    double discriminant = m_b*m_b-4.0*m_a*m_c;
    if(discriminant>0.0)//2 solutions
    {
        solutions_size=2;
        solutions[0]=(-m_b+ std::sqrt(discriminant))/(2.0*m_a);//(−B + √(B2 − 4AC) )/ 2A
        solutions[1]=(-m_b- std::sqrt(discriminant))/(2.0*m_a);//(−B - √(B2 − 4AC) )/ 2A
    }
    else if(discriminant==0.0){// 1sloution
        solutions_size=1;
        solutions[0]=-m_b/(2.0*m_a);
    }
    else{//no real sloution
        solutions_size=0;
    }
}

Equation::Equation(double a,double b,double c)
    :m_a{a}
    ,m_b{b}
    ,m_c{c}
    ,solutions_size{0}
    ,solutions{nullptr}
    {
        if(m_a==0.0)
            throw std::invalid_argument("a cant be zero\n");
        solutions=new double[2];//allocate 2 doubles. its user responsibility to check the size of the array before accessing it
        update_solutions();
    }
Equation::~Equation(){
    delete[] solutions;
    solutions=nullptr;
}
Equation::Equation(const Equation& other)//copy ctor
    :m_a{other.m_a}
    ,m_b{other.m_b}
    ,m_c{other.m_c}
    ,solutions_size{other.solutions_size}
    ,solutions{new double[2]}
{
    solutions[0]=other.solutions[0];//copy the solutions
    solutions[1]=other.solutions[1];
}
Equation::Equation(Equation&& other)noexcept//move ctor
    :m_a{other.m_a}
    ,m_b{other.m_b}
    ,m_c{other.m_c}
    ,solutions_size{other.solutions_size}
    ,solutions{other.solutions}
{
    other.solutions_size=0;
    other.solutions=nullptr;
}
Equation& Equation::operator=(const Equation& other){   //copy assignment
    if(this!=&other){
        m_a=other.m_a;
        m_b=other.m_b;
        m_c=other.m_c;

        solutions_size=other.solutions_size;
        //object always 2 doubles allocated so we just overwrite
        //no point to delete and reallocate memory with same size
        solutions[0]=other.solutions[0];
        solutions[1]=other.solutions[1];
    }
    return *this;
}
Equation& Equation::operator=(Equation&& other)noexcept{    //move assignment
    if(this!=&other){
        m_a=other.m_a;
        m_b=other.m_b;
        m_c=other.m_c;
        delete[] solutions;//delete and steal the memory from other
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
    m_a=number;
    update_solutions(); //update the object
}
void Equation::set_b(double number){
    m_b=number;
    update_solutions();
}
void Equation::set_c(double number){
    m_c=number;
    update_solutions();
}
std::size_t Equation::get_solutions_size() const{
    return solutions_size;
}
double const * Equation::get_solutions() const{
    return solutions;
}

Equation Equation::operator+(const Equation& other) const{//for obj+obj
    return Equation(other.m_a+m_a,other.m_b+m_b,other.m_c+m_c);
}
Equation Equation::operator+(double c)  const{//for obj+double
    return Equation(m_a,m_b,m_c+c);
}

Equation operator+(double c,const Equation& other){//for double+obj
    return other+c;
}

std::ostream& operator <<(std::ostream& out,const Equation& q){
    return out<<std::fixed <<std::setprecision(1)<<q.m_a<<" X^2 + "<<q.m_b<<" X + "<<q.m_c<<" = 0";
}