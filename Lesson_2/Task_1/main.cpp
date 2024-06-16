#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    // Initialization of bank for no unexpected behaviour
    float bank[10];
    cout << fixed << setprecision(2);
    for(int i_number_of_bank_account = 0;i_number_of_bank_account<10;i_number_of_bank_account++){
        bank[i_number_of_bank_account] = i_number_of_bank_account*20;
    }

    // Asking input for number of bank account
    int number_of_bank_account;
    cout << "Enter the desired bank account number(1-10): ";
    cin >> number_of_bank_account;

    // Asking input for deposit or withdrawal if number of bank account is in boundaries of array
    if(number_of_bank_account > 0 && number_of_bank_account < 11){

        // First menu for operations with one concrete bank account
        char choice_symbol;
        cout << "Do you want check balance, deposit or withdraw money?(c / d / w): ";
        cin >> choice_symbol;
        switch(choice_symbol){

        // Check balance
        case 'c':
            cout << "Your current balance on bank account " << number_of_bank_account
                 << " is: " << bank[number_of_bank_account-1] << endl;
            break;

        // Deposit
        case 'd':
            float deposit_money_amount;
            cout << "How much do you want to deposit?" << endl;
            cin >> deposit_money_amount;
            if(deposit_money_amount < 0){
                cout << "You can't deposit negative sum of money, sorry for the inconvinience." << endl;
                break;
            }
            bank[number_of_bank_account-1] += deposit_money_amount;
            cout << "Operation successful, your current balance on bank account "
                 << number_of_bank_account << " is: "
                 << bank[number_of_bank_account-1] << endl;
            break;

        // Withdraw
        case 'w':
            float withdrawal_money_amount;
            cout << "How much money do you want to withdraw?" << endl;
            cin >> withdrawal_money_amount;
            if(withdrawal_money_amount < 0 || withdrawal_money_amount > bank[number_of_bank_account-1]){
                cout << "You can't withdraw negative sum of money or more than balance amount, sorry for the inconvinience." << endl;
                break;
            }
            bank[number_of_bank_account-1] -= withdrawal_money_amount;
            cout << "Operation successful, your current balance on bank account "
                 << number_of_bank_account << " is: "
                 << bank[number_of_bank_account-1] << endl;
            break;

        // Wrong symbol
        default:
            cout << "There is no such operation" << endl;
            break;
        }
    }

    // Second menu for operations with all bank accounts
    char choice_symbol;
    cout << "Do you want to see the minimum/maximum of all your accounts or sum of all your accounts?(m / s / n): ";
    cin >> choice_symbol;
    switch (choice_symbol) {

        // Max and min balance
        case 'm': {
            float min_balance = bank[0];
            float max_balance = bank[0];
            for(int i_number_of_bank_account = 1; i_number_of_bank_account<10; i_number_of_bank_account++){
                if(bank[i_number_of_bank_account] < min_balance){
                    min_balance = bank[i_number_of_bank_account];
                } else if(bank[i_number_of_bank_account] > max_balance){
                    max_balance = bank[i_number_of_bank_account];
                }
            }
            cout << "Your maximum balance is " << max_balance
                 << ", your minimum balance is " << min_balance << endl;
            break;
        }

        // Sum of all bank account's balances
        case 's':
            float full_balance;
            for(int i_number_of_bank_account = 0; i_number_of_bank_account<10; i_number_of_bank_account++){
                full_balance += bank[i_number_of_bank_account];
            }
            cout << "Sum of all bank account's balances is: " << full_balance << endl;
            break;
    }

    cout << "Goodbye!" << endl;
    system("pause");
}
