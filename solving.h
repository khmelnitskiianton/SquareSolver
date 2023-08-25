/*!
  \file 
  \brief Header file of calculations
  This file includes structures for values, constants and functions for process quadratic equation
  */
  
/// \brief Constant for equation of quantity coefficients, in case of quadratic equation = 3 
const int QUANTITY = 3;          

/// \brief Set of possible solutions
enum solutions {
    INF_SOL  = -1,          ///< Value of infinity of solutions
    ZERO_SOL = 0,           ///< Value of zero of solutions
    ONE_SOL  = 1,           ///< Value of one of solutions
    TWO_SOL  = 2,           ///< Value of two of solutions
    UNDEFINED_SOL = 3,      ///< Value of undefined parametr
};

/*!
  \brief The structure for roots

  This structure made for form of saving information
  about roots of quadratic equation and its amount

  */
struct Roots               
{
    int amount;     
    double root1;   
    double root2;    
};
/// \var int Roots::amount
/// \brief The value of amount of roots, can be -1(infinity), 0, 1, 2, 3(for error)
/// \var double Roots::root1
/// \brief The value of first root of quadratic equation, can have value or be NAN(Not A Number) if equation hasn't roots or its infinity
/// \var double Roots::root2
/// \brief The value of second root of quadratic equation, can have value or be NAN(Not A Number) if equation hasn't roots or its only one or its infinity

/*!
  \brief Main function of solving quadratic equation
  \param[in] args Double array of coefficients
  \param[out] sols Structure for writing solutions(structure Roots)

  Here I use formules of solving quadratic equation:

  General form is \f$ ax^2 + bx + c = 0 \f$

  This function return result if \f$ a \neq 0 \f$

  First i calculate discriminant: 
  \f$ D = b^2 - 4ac\f$
  Then I compare it with 0:
  - If \f$ D > 0 \f$ Its two roots, then I use formula:  \f$ x_{1,2} = \frac{-b \pm \sqrt{D}}{2a} \f$ and its values assigned to struct of roots.
  - If \f$ D = 0 \f$ Its one root, then I use formula: \f$ x = \frac{-b}{2a} \f$ and it value assigned to struct of roots, then second root is NAN.
  - If \f$ D < 0 \f$ Its no solution, then 1 and 2 roots are NAN.
*/
void quadratic_solver (Roots *sols, double *args);

/*!
  Additional function for solving special case of linal equation. a = 0.
  \param[in] args Double array of coefficients
  \param[out] sols Structure for writing solutions(structure Roots)

  This function called if \f$ a = 0 \f$

  If \f$ b \neq 0 \f$, then form of equation is \f$ bx + c = 0 \f$ and solution is \f$ x = \frac{-c}{b} \f$

  If \f$ b = 0 \f$, then form of equation is \f$ c = 0 \f$ and case:
  - \f$ c = 0 \f$, then \f$ 0 = 0 \f$ and its infinity of roots.
  - \f$ c \neq 0 \f$, then no roots.
*/
void linal_solver (Roots *sols, double *args);