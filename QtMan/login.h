#ifndef LOGIN_H
#define LOGIN_H

//Last feature to implement
//Would be a QDialog window
//We show a QBoxMessage in the case of invalid input
//If faregh chghol we seperate the login-in and signing-up logics by checking if the username and password already exist in the database and load data accordingly (in order not to mixup different user sessions and data)
//Check Mohanned's login logic (just a on_button_pushed() slot that would validate the inputs and login if valid, shows a Qmessagebox else, and quit if pressed on exit button) and implement it in the WCS.

//If the file containing the user's data exists, we basically construct the Library object with that data, in a new log in senario, we default construct it .

class Login
{
public:
    Login();
};

#endif // LOGIN_H
