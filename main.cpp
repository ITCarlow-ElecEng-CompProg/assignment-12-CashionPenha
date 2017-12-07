/**
 * Cashion Penha
 * Lab 12
 * Complex number calculations
 * 04/12/2017
 */

 /**< preprocessor directives / header files*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


using namespace std;/** Includes commonly used tools, such as cout, cin, To prevent typing "std" */

struct com/**< structure for complex number real and imaginary parts */
{
    double re;
    double im;
};

string cplxNo(com No)/// creating a string to print result in appropriate form
{
    char x[50], sgn;
    if (No.im<0) {
        sgn='-';
        No.im*=-1;
    } else
        sgn='+';
    sprintf(x,"%.1f%cj%.1f",No.re,sgn,No.im);

    return x;
}

com cplxAdd (com a, com b)/**< Seperate function to get result of complex numbers addition */
{
    com res;
    res.re=a.re+b.re;
    res.im=a.im + b.im;
    return res;/// return result
}

com cplxSub (com x, com y)/**< Separate function to get result of complex numbers subtraction */
{
    y.re*=-1;
    y.im*=-1;
    return cplxAdd(x,y); /// x-y ==== x + (-y)
}



int main(void)
{
    com no1,no2,res;

    /// Declaring variables
    char s1,op;
    double mag1,angll;
    double mag2,angl2;
    double dresultmag,dresultangle;
    double xresultradius,xresultangle;

    cout <<"Cashion Penha - C00218875 - Lab 12 Complex Number Calculations" << endl;/// lab title

    cout << "\nPlease enter complex number 1 in form (1+j2): ";/// getting user input

    cin >> no1.re >> op >> s1 >> no1.im;///storing user input in its inserted form
        if (op=='-')///if user input is negative for imaginary part, then multiply the imaginary part by - to make it negative
            no1.im*=-1;

    cout << "Please enter complex number 2 in form (1+j2): ";///get second number

    cin >> no2.re >> op >> s1 >> no2.im;
        if (op=='-')
            no2.im*=-1;/// similar to previous if negative then make number negative

    /**< Addition  */
    cout << "\n("<< cplxNo(no1)<<") + ("<< cplxNo(no2) <<")" <<" = " <<  cplxNo(cplxAdd(no1,no2)) << endl;/// printing result of addition

    /**< Subtraction */
    cout << "("<< cplxNo(no1)<<") - ("<< cplxNo(no2) <<")" <<" = " << cplxNo(cplxSub(no1,no2))<< endl;/// printing result of subtraction

    /**< Cartesian to polar *//// to multiply and divide
    mag1 = sqrt(no1.re*no1.re+no1.im*no1.im);
    angll = atan2(no1.im,no1.re);

    mag2 = sqrt(no2.re*no2.re+no2.im*no2.im);
    angl2 = atan2(no2.im,no2.re);

    /**< multiplication*/
    xresultradius = (mag1*mag2);
    xresultangle = angll+angl2;

    /**< Back to cartesian*//// back to cartesian to display result in required form
    res.re= xresultradius*cos(xresultangle);
    res.im= xresultradius*sin(xresultangle);
    cout.precision(2);/// limiting result to 1 decimal place

    cout << "("<< cplxNo(no1)<<") x ("<< cplxNo(no2)<<")" <<" = " << cplxNo(res) <<endl;/// multiplication result

    /**<  Division*/
    dresultmag=(mag1/mag2);
    dresultangle=angll-angl2;

    /**< Back to cartesian*/
    res.re= dresultmag*cos(dresultangle);
    res.im= dresultmag*sin(dresultangle);
    cout.precision(2);

    cout << "("<< cplxNo(no1) << ") / ("<< cplxNo(no2)<<")" <<" = " << cplxNo(res)<<endl;/// division result

    return 0;/// end of program
}
