/*!
    \file 
    \brief Header file of comparing double numbers functions
*/

/// \brief Constant epsilone for comparing double numbers!
const double EPSILONE = 1e-36;   

/*!
    \brief Function comparing double numbers      
    \param x,y Comparing,double numbers
    \return (bool) 1 if they are equal, 
                   0 if they are not equal

    Function of comparing two double numbers, and return 1 if they are equal(and NAN = NAN), and 0 if not
    
*/
int compare (double x, double y);

/*!
    \brief Function of checking double for NAN or INFINITY      
    \param z Testing number
    \return (bool) 1 if it is not real, 
                   0 if it is real
    Function of testing for not real double 
*/
int check_double (double z);
