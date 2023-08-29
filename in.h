/*!
    \file 
    \brief Header file of input
    It includes functions of input, entering
*/

/*!
    \brief Function of cleaning buffer of input   
    From book of Prata its a way of cleaning rubbish from buffer line in input 
*/
void clean_buffer (void);

/*!
    \brief Function of correct entering one double number     
    \return entering double number
    it includes security from words or big numbers
*/
double enter_double (void);

/*!
    \brief Function of entering main coefficients  
    \param args double array of coefficients
    It includes friendly outout and fuction if entering solo argument
*/
void input_args (double *args);

/*!
    \brief Function of connection to user  
    \return 1 if user wants to continue hand entering
            0 if user dont want hand entering
    First its welcome message
    Then user can press Y for auto testing from txt file or N and continue
    Then user can press Y for hand testing if he wants to enter coefficients or N and then programm ends
*/
int welcome (void);

/*!
    \brief Function of filling double array      
    \param args double array  of coefficients
*/
void filler_coeffs (double *args);

/*!
    \brief Function of choice Y or N
    \return int(char) Y or N symbols
    This function take Y or N from user - choice, if user write something else, he will swear 
*/
int user_choice (void);

/*!
    \brief Function of posting foto of my unifersity logo MIPT RT
*/
void rtrtrt(void);

/*!
    \brief Function of posting foto of my unifersity logo MIPT 
*/
void mipt(void);