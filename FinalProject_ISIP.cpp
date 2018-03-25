// Michael John Isip
// BSIS Prog1-A
// Finals Activity

#include <iostream>
#include <stdlib.h>
using namespace std;

int pin=123456, balance=1000, maxmoney=10000;

void LogIn();
void CardCaptured();
void MainMenu();
void Balance();
void Withdrawal();
void DepositCash();
void ChangePIN();
void Quit();
void Exit();

int main()
{
    LogIn();
}

void LogIn()
{
    int logpin, i = 0;
    system("color 48");

    while(logpin != pin && i<3)
    {
        system("cls");
        cout << endl << "\t\t   ******************************************";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   *     WELCOME TO LVCC BANKING SYSTEM     *";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   ******************************************" << endl << endl << endl << endl << endl;

        if (logpin != pin && i > 0)
        {
            system("color 04");
            cout << "\t\t     PIN Code is INVALID! Please try again." << endl << endl;
        }

        cout << "\t\t     Please enter your PIN: ";
        cin >> logpin;

        if (i == 2 && logpin != pin)
            CardCaptured();

        if (logpin == pin)
            MainMenu();

        i++;

    }
}

void CardCaptured()
{
    system ("cls");
    system ("color F4");
    cout << endl << endl << "\t\t ************************************************" << endl;
    cout << endl << "    ***********************************************************************" << endl;
    cout << endl << "\t\t      Maximum attempts reached! CARD CAPTURED!" << endl << "\t Please call the LVCC Baking Hotline at <045> 877 7777. Thank you!" << endl;
    cout << endl << "    ***********************************************************************" << endl;
    cout << endl << "\t\t ************************************************" << endl << endl;
}

void MainMenu()
{
    int i = 0;
    char choice;
    system ("color 48");

    while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5')
    {
        system ("cls");
        cout << endl << "\t\t   ******************************************";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   ******************************************" << endl;
        cout << endl << "\t*****************************************************************" << endl;
        cout << endl << "\t\t ----------------------------------------------";
        cout << endl << "\t\t : \t      [1] Balance Inquiry \t      :";
        cout << endl << "\t\t : \t      [2] Withdrawal \t\t      :";
        cout << endl << "\t\t : \t      [3] Deposit Cash \t\t      :";
        cout << endl << "\t\t : \t      [4] Change PIN \t\t      :";
        cout << endl << "\t\t : \t      [5] QUIT \t\t\t      :" << endl;
        cout << endl << "\t\t ----------------------------------------------" << endl;
        cout << endl << "\t*****************************************************************" << endl;

        if (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && i > 0)
            cout << endl << "\t       Input is INVALID. Please enter your choice [1-5]: ";
        else
            cout << endl << "\t\t\t Please enter your choice [1-5]: ";

        cin >> choice;

        switch(choice)
        {
            case '1':
                Balance();
                break;
            case '2':
                Withdrawal();
                break;
            case '3':
                DepositCash();
                break;
            case '4':
                ChangePIN();
                break;
            case '5':
                Quit();
                break;
        }

        i++;
    }
}

void Balance()
{
    char choice;
    system("cls");
    system("color 48");
    cout << endl << "\t\t   ******************************************";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
    cout << endl << "\t\t   *             BALANCE INQUIRY            *";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   ******************************************" << endl << endl << endl << endl;
    cout << endl << "\t\t      You're current balance is Php " << balance << ".00" << endl << endl << endl << endl;
    cout << endl << "\t*****************************************************************" << endl << endl;

    cout << endl << "\t\t Do you wish to have another transaction [y/n]? ";
    cin >> choice;

    switch (choice)
    {
        case 'Y':
        case 'y':
            MainMenu();
            break;
        case 'N':
        case 'n':
            Quit();
            break;
    }

}

void Withdrawal()
{
    int withdrawn, i = 0;

    while (withdrawn > balance)
    {
        system("cls");
        system("color 48");
        cout << endl << "\t\t   ******************************************";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
        cout << endl << "\t\t   *               WITHDRAWAL               *";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   ******************************************" << endl << endl << endl << endl;

        if (i > 0)
        {
            system("color 04");

            if (withdrawn > balance && withdrawn < maxmoney)
                cout << "\t      Please enter amount less than or equal to Php " << balance << ".00" << endl;

            if (withdrawn > maxmoney)
                cout << "\t\t Maximum withdrawal amount is only Php " << maxmoney << ".00" << endl;
        }

        cout << endl << "\t\t   Please enter the amount to be withdrawn: ";
        cin >> withdrawn;

        if (withdrawn <= balance)
        {
            char choice;

            system("color 48");
            balance -= withdrawn;
            cout << endl << endl << "\t\t   You have withdrawn Php " << withdrawn << ".00";
            cout << endl << "\t\t   Your current balance now is Php " << balance << ".00" << endl << endl;
            cout << endl << "\t*****************************************************************" << endl << endl;

            cout << endl << "\t\t Do you wish to have another transaction [y/n]? ";
            cin >> choice;

            switch (choice)
            {
                case 'Y':
                case 'y':
                    MainMenu();
                    break;
                case 'N':
                case 'n':
                    Quit();
                    break;
            }

        }


        i++;
    }
}

void DepositCash()
{
    int deposit, i = 0;

    while(deposit > maxmoney)
    {
        system("cls");
        system("color 48");
        cout << endl << "\t\t   ******************************************";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
        cout << endl << "\t\t   *              DEPOSIT CASH              *";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   ******************************************" << endl << endl << endl << endl;

        if (deposit > maxmoney && i > 0)
        {
            system("color 04");
            cout << "       Maximum amount that can be deposited is only Php " << maxmoney << ".00 at a time." << endl;
        }

        cout << endl << "\t\t   Please enter the amount to be deposited: ";
        cin >> deposit;

        if (deposit <= maxmoney)
        {
            char choice;
            system("color 48");
            balance += deposit;

            cout << endl << endl << "\t\t   You have deposited Php " << deposit << ".00 to your account.";
            cout << endl << "\t\t   Your current balance is now Php " << balance << ".00." << endl << endl;
            cout << endl << "\t*****************************************************************" << endl << endl;

            cout << endl << "\t\t Do you wish to have another transaction [y/n]? ";
            cin >> choice;

            switch (choice)
            {
                case 'Y':
                case 'y':
                    MainMenu();
                    break;
                case 'N':
                case 'n':
                    Quit();
                    break;
            }
        }

        i++;
    }
}

void ChangePIN()
{
    char choice;
    int newpin, sixdigit, confNewpin, confPin, i = 0;
    system("color 48");

    while (confNewpin != newpin || confPin != pin)
    {
        system("cls");
        cout << endl << "\t\t   ******************************************";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
        cout << endl << "\t\t   *               CHANGE PIN               *";
        cout << endl << "   *****************                                        *****************";
        cout << endl << "\t\t   ******************************************" << endl << endl;

        if (confNewpin != newpin && (sixdigit < 10 && sixdigit > 0) && i > 0)
            cout << endl << "\t\t   PIN Code entered don't match." << endl;

        if (confPin != pin && confNewpin == newpin && i > 0)
            cout << endl << "\t\t   PIN Code is INVALID! Please try again." << endl;

        if ((sixdigit == 0 || sixdigit > 10) && i > 0)
        {
            system("color 04");
            cout << endl << "\t  PIN entered is too long or short. Please enter 6 digits only." << endl;
        }

        cout << endl << "\t\t   Please enter new PIN: ";
        cin >> newpin;

        sixdigit = newpin/100000;

        if (sixdigit < 10 && sixdigit > 0)
        {
            cout << endl << "\t\t   Please enter new PIN <Confirmation>: ";
            cin >> confNewpin;

            if (confNewpin == newpin)
            {
                cout << endl << endl << "\t\t   Please enter your current PIN: ";
                cin >> confPin;

                if (confPin == pin)
                {
                    system("color 48");
                    pin = newpin;
                    cout << endl << "\t\t   PIN Code successfully changed." << endl;
                    cout << endl << "\t*****************************************************************" << endl;
                    cout << endl << "\t\t Do you wish to have another transaction [y/n]? ";
                    cin >> choice;

                    switch (choice)
                    {
                        case 'Y':
                        case 'y':
                            MainMenu();
                            break;
                        case 'N':
                        case 'n':
                            Quit();
                            break;
                    }

                }

                if (confPin != pin && i >= 2)
                {
                    CardCaptured();
                    break;
                }
            }
        }
        i++;

    }

}

void Quit()
{
    char choice;
    system("cls");
    system("color 48");
    cout << endl << "\t\t   ******************************************";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   *           LVCC BANKING SYSTEM          *";
    cout << endl << "\t\t   *                  QUIT                  *";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   ******************************************" << endl << endl;

    cout << endl << "\t*****************************************************************" << endl << endl;
    cout << endl << "\t\t Are you sure you really want to exit [y/n]? ";
    cin >> choice;

    switch (choice)
    {
        case 'Y':
        case 'y':
            Exit();
            break;
        case 'N':
        case 'n':
            MainMenu();
            break;
    }
}

void Exit()
{
    char choice;
    system("cls");
    system("color 48");
    cout << endl << "\t\t   ******************************************";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   *           LVCC BANKING SYSTEM           *";
    cout << endl << "\t\t   *               LOGGING OFF               *";
    cout << endl << "   *****************                                        *****************";
    cout << endl << "\t\t   ******************************************" << endl << endl;

    cout << endl << "\t*****************************************************************" << endl << endl;
    cout << endl << "\t\t\t Thank you for banking with us." << endl << endl;
    cout << endl << "\t*****************************************************************" << endl;
}

// MJFI
