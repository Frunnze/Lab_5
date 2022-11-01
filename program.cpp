#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <cmath>

using namespace std;

// The root class.
class Bank
{
private:
    string Name;
    string Location;
    bool Open;

public:
    void setName(string name)
    {
        Name = name;
    }

    string getName()
    {
        return Name;
    }
};

// For person superclass.
class Person : public Bank
{
private:
    string Gender;

public:
    void setGender(string gen)
    {
        Gender = gen;
    }

    string getGender()
    {
        return Gender;
    }
};

class Customer : public Person
{
public:
    void enterBank()
    {
        cout << "- Customer " << getName() << " enters the bank.";
    }

    void goToReception()
    {
        cout << "\n- Customer: Goes to the Reception.";
    }

    void introduceYourself(string employeeGender)
    {
        if (employeeGender == "male")
        {
            cout << "\n- Customer: Hello, sir, how can I";
        }
        else if (employeeGender == "female")
        {
            cout << "\n- Customer: Hello, ma'am, how can I";
        }
    }

    int speakToReception(int id)
    {
        srand(id);
        int option = 1 + (rand() % 6);
        switch (option)
        {
        case 1: cout << " exchange some money?"; break;
        case 2: cout << " transfer some money?"; break;
        case 3: cout << " sign up for an insurance?"; break;
        case 4: cout << " take a credit?"; break;
        case 5: cout << " invest here?"; break;
        case 6: cout << " withdraw some money?"; break;
        }
        return option;
    }

    void goToATM()
    {
        cout << "\n- Customer: Goes to the ATM.";
        cout << "\n- Customer: Waits in the queue.";
    }

    void introduceOption(int amount)
    {
        cout << "\n- Customer: Introduces " << amount << " to withdraw.";
    }

    void goToTicketMachine()
    {
        cout << "\n- Customer: Goes to the queue ticket Machine.";
    }

    void goToExchangeWindow(string Gender)
    {
        cout << "\n- Customer: Goes to the exchange Window.";
        if (Gender == "male")
        {
            cout << "\n- Customer: Waits his turn.";
        }
        else if (Gender == "female")
        {
            cout << "\n- Customer: Waits her turn.";
        }
    }

    void askingToChange(int amount)
    {
        cout << "\n- Customer: Hi, I would like to change " << amount << " euro in lei.";
    }

    void waitInQueue(int number)
    {
        cout << "\n- Customer: Waits in line until ticket number " << number << " comes up.";
    }

    void choose()
    {
        cout << "\n- Customer: Chooses and does the business.";
    }

    void leaveBank()
    {
        cout << "\n- Customer: Leaves the bank.";
    }
};

class Employee : public Person
{
private:
    string JobTitle;

public:
    void setJobTitle(string title)
    {
        JobTitle = title;
    }

    string getJobTitle()
    {
        return JobTitle;
    }

    void introduceYourself()
    {
        cout << "\n- Employee: Hello, my name is " << getName() << ". I am the " << getJobTitle() << ".";
    }
};

// For department superclass.
class Department : public Bank
{
protected:
    string Option1;
    string Option2;

public:
    void tellOptions()
    {
        cout << "\n- Options: ";
    }
};

class customerDepartment : public Department
{
public:
    void tellOptions()
    {
        cout << "\n- Options: ";
        cout << "\n" << Option1;
        cout << "\n" << Option2;
    }

    customerDepartment(string option1, string option2)
    {
        Option1 = option1;
        Option2 = option2;
    }
};

class insuranceDepartment : public Department
{
public:
    void tellOptions()
    {
        cout << "\n- Options: ";
        cout << "\n" << Option1;
        cout << "\n" << Option2;
    }

    insuranceDepartment(string option1, string option2)
    {
        Option1 = option1;
        Option2 = option2;
    }
};

class creditDepartment : public Department
{
public:
    void tellOptions()
    {
        cout << "\n- Options: ";
        cout << "\n" << Option1;
        cout << "\n" << Option2;
    }

    creditDepartment(string option1, string option2)
    {
        Option1 = option1;
        Option2 = option2;
    }
};

class investmentDepartment : public Department
{
public:
    void tellOptions()
    {
        cout << "\n- Options: ";
        cout << "\n" << Option1;
        cout << "\n" << Option2;
    }

    investmentDepartment(string option1, string option2)
    {
        Option1 = option1;
        Option2 = option2;
    }
};

// For machine superclass.
class Machine : public Bank
{
private:
    int AmountOfMachines;
    bool broken;

public:
    void brokenMachine(bool Broken)
    {
        if (Broken == true)
        {
            cout << "\n- Sign: The machine is broken, wait for the repairement.";
            cout << "\n- Customer: Waits.";
        }
    }

    virtual void showOptions()
    {
        cout << "1. Start; 2. Stop";
    }
};

class ATM : public Machine
{
private:
    float AmountToWithdraw;

public:
    void setAmount(float amount, bool Broken)
    {
        if (Broken == true)
        {
            cout << "\n- ATM: ATM is broken, wait for the repairment.";
            cout << "\n- Customer: Waits.";
        }
        else if (Broken == false)
        {
            AmountToWithdraw = amount;
        }
    }

    void showOptions()
    {
        cout << "\n- ATM: Introduce the amount to withdraw.";
    }

    int getAmount()
    {
        return AmountToWithdraw;
    }

    void giveMoney(bool Broken)
    {
        if (Broken == false)
        {
            cout << "\n- ATM: Out " << AmountToWithdraw << " lei.";
        }
    }
};

class QueueTicketMachine : public Machine
{
private:
    string Category1;
    string Category2;
    string Category3;
    string Category4;

public:
    int giveTicket()
    {
        srand(time(0));
        return 1 + (rand() % 1000);
    }

    void showOptions()
    {
        cout << "\n- Options:";
        cout << "\n" << Category1;
        cout << "\n" << Category2;
        cout << "\n" << Category3;
        cout << "\n" << Category4;
    }

    void showChosenCategory(int choice)
    {
        cout << "\n- Customer chose: ";
        if (choice == 2) cout << Category1;
        if (choice == 3) cout << Category2;
        if (choice == 4) cout << Category3;
        if (choice == 5) cout << Category4;
    }

    QueueTicketMachine(string c1, string c2, string c3, string c4)
    {
        Category1 = c1;
        Category2 = c2;
        Category3 = c3;
        Category4 = c4;
    }
};

// For window superclass.
class Window : public Bank
{
protected:
    bool PrecenseOfEmplyee;
};

class CurrencyExchangeWindow : public Window
{
private:
    float EuroBuy;
    float EuroSell;
    float DollarBuy;
    float DollarSell;

public:
    CurrencyExchangeWindow(float e1, float e2, float d1, float d2)
    {
        EuroBuy = e1;
        EuroSell = e2;
        DollarBuy = d1;
        DollarSell = d2;
    }

    void exchangeMoney(float amount, string currency, string action, bool employee)
    {
        if (employee == true)
        {
            if (currency == "euro")
            {
                if (action == "sell")
                {
                    cout << "\n- Employee: Here is " << EuroSell * amount << " lei.";
                }
            }
        }
        else if (employee == false)
        {
            cout << "\n- Customer: Waits for the employee.";
        }
    }
};

class Reception : public Window
{
public:
    void speakToCustomer(string name, bool employee)
    {
        if (employee == true)
        {
            cout << "\n- Employee: Hello, " << "my name is " << name << " what can I help you with?";
        }
        else if (employee == false)
        {
            cout << "\n- Customer: Waits for the employee.";
        }
    }

    void indicateExchangeWindow()
    {
        cout << "\n- Employee: There is the currency exchange Window.";
    }

    void indicateTicketMachine()
    {
        cout << "\n- Employee: You go to the queue ticket machine and choose the corresponding option";
        cout << " and then wait for your turn.";
    }

    void indicateATM()
    {
        cout << "\n- Employee: You can use the ATM, there it is.";
    }
};

int main()
{
    // Defining the objects of class employee.
    Employee employee1;
    employee1.setName("Ada"); employee1.setJobTitle("Receptionist"); employee1.setGender("female");
    Employee employee2; employee2.setName("Eva"); employee2.setJobTitle("Exchanger"); employee2.setGender("female"); 
    Employee employee3; employee3.setName("Rick"); employee3.setJobTitle("Customer worker"); employee3.setGender("female");
    Employee employee4; employee4.setName("Tom"); employee4.setJobTitle("Insurance analyst"); employee4.setGender("male");
    Employee employee5; employee5.setName("Mircea"); employee5.setJobTitle("Credit giver"); employee5.setGender("male");
    Employee employee6; employee6.setName("Velior"); employee6.setJobTitle("Investment analyst"); employee6.setGender("male");

    // Defining the objects of class CurrencyExchangeWindow.
    CurrencyExchangeWindow window1 = CurrencyExchangeWindow(19.5, 19.0, 18.5, 18.1);

    // Defining the objects of class QueueTicketMachine.
    QueueTicketMachine qtm1 = QueueTicketMachine("Customer Department", "Insurance Department", "Credit Department", "Investment Department");

    // Defining the objects of the Department classes.
    customerDepartment customerDepartment1 = customerDepartment("transfers", "payment card");
    insuranceDepartment insuranceDepartment1 = insuranceDepartment("life insurance", "house insurance");
    creditDepartment creditDeparment1 = creditDepartment("house credit", "business credit");
    investmentDepartment investmentDepartment1 = investmentDepartment("stocks", "bonds");

    int identifier = 1, mCustomers = 0, wCustomers = 0, cdamount = 0, idamount = 0, crdamount = 0, invdamount = 0;
    float hours = 8, minutes = 0, TotalHours = 0, MoneyFromATM = 0, ExchangedMoney = 0;
    while (1)
    {
        // Creating the clock.
        minutes += 1;
        if (minutes == 60)
        {
            minutes = 0;
            hours += 1;
            TotalHours += 1;
        }

        if (hours == 24) hours = 8;

        // Break;
        if (TotalHours == 100) break;

        int slowingSimulation = 0;
        while (slowingSimulation < pow(10, 8))
             slowingSimulation += 1;

        int r = 1 + rand() % 100;
        if (hours >= 8  && hours < 12 && r <= 30 ||
            hours >= 12 && hours < 14 && r <= 40 ||
            hours >= 14 && hours < 17 && r <= 50)
        {
            // Showing the time at which the customer enters the bank;
            cout << "Time: " << hours << ":" << (int)minutes << "\n";

            // Defining the objects of the ATM class.
            ATM atm1;
            srand(identifier);

            // Defining the objects of the customer class.
            Customer customer1;
            customer1.setName(to_string(identifier));

            int genderNum = 1 + (rand() % 2);
            if (genderNum == 1)
            {        
                customer1.setGender("female");
                wCustomers += 1;
            } else
            {
                customer1.setGender("male");
                mCustomers += 1;
            }

            // Identifing the next customer.
            identifier += 1;

            // Beginning the scenarios.
            customer1.enterBank();
            int option = 1 + (rand() % 3);
            switch (option)
            {
                // The customer goes first to the Reception for indication.
                case 1:
                {
                    customer1.goToReception();
                    Reception ReceptionEmployee;
                    if (1 + (rand() % 2) == 1)
                    {
                        ReceptionEmployee.speakToCustomer(employee1.getName(), false);
                        ReceptionEmployee.speakToCustomer(employee1.getName(), true);
                    }
                    else
                    {
                        ReceptionEmployee.speakToCustomer(employee1.getName(), true);
                    }

                    customer1.introduceYourself(employee1.getGender());
                    int question_option = customer1.speakToReception(identifier);

                    if (question_option == 1)
                    {
                       int amount_to_change = 1 + (rand() % 800);
                       ReceptionEmployee.indicateExchangeWindow();
                       customer1.goToExchangeWindow(customer1.getGender());
                       window1.exchangeMoney(amount_to_change, "euro", "sell", false);
                       customer1.askingToChange(amount_to_change);
                       employee2.introduceYourself();
                       window1.exchangeMoney(amount_to_change, "euro", "sell", true);
                       customer1.leaveBank();

                       ExchangedMoney += amount_to_change;
                    }

                    if (question_option == 2 || question_option == 3 || question_option == 4 || question_option == 5)
                    {
                        ReceptionEmployee.indicateTicketMachine();
                        customer1.goToTicketMachine();
                        if (1 + (rand() % 100) <= 30)
                            qtm1.brokenMachine(true);
                        qtm1.showOptions();
                        qtm1.showChosenCategory(question_option);
                        int ticket_number = qtm1.giveTicket();
                        customer1.waitInQueue(ticket_number);
                        if (question_option == 2)
                        {
                            employee3.introduceYourself();
                            customerDepartment1.tellOptions();
                            cdamount += 1;
                        }
                        if (question_option == 3)
                        {
                            employee4.introduceYourself();
                            insuranceDepartment1.tellOptions();
                            idamount += 1;
                        }
                        if (question_option == 4)
                        {
                            employee5.introduceYourself();
                            creditDeparment1.tellOptions();
                            crdamount += 1;
                        }
                        if (question_option == 5)
                        {
                            employee6.introduceYourself();
                            investmentDepartment1.tellOptions();
                            invdamount += 1;
                        }
                        customer1.choose();
                        customer1.leaveBank();
                    }

                    if (question_option == 6)
                    {
                        ReceptionEmployee.indicateATM();
                        customer1.goToATM();
                        if (1 + (rand() % 100) <= 20)
                        {
                            atm1.setAmount(1 + (rand() % 1000), true);
                        } else
                        {
                            atm1.setAmount(1 + (rand() % 1000), false);
                        }
                        atm1.showOptions();
                        customer1.introduceOption(atm1.getAmount());
                        atm1.giveMoney(true);
                        customer1.leaveBank();

                        MoneyFromATM += atm1.getAmount();
                    }
                    break;
                }

                // The customer goes right away to the ATM.
                case 2:
                {
                    customer1.goToATM();
                    if (1 + (rand() % 100) <= 20)
                    {
                        atm1.setAmount(1 + (rand() % 1000), true);
                    } else
                    {
                        atm1.setAmount(1 + (rand() % 1000), false);
                    }
                    atm1.showOptions();
                    customer1.introduceOption(atm1.getAmount());
                    atm1.giveMoney(false);
                    customer1.leaveBank();

                    MoneyFromATM += atm1.getAmount();
                    break;
                }

                // The customer goes straight away to the currency exchange Window.
                case 3:
                {
                    int amount_to_change = 1 + (rand() % 800);
                    customer1.goToExchangeWindow(customer1.getGender());
                    customer1.askingToChange(amount_to_change);
                    employee2.introduceYourself();
                    window1.exchangeMoney(amount_to_change, "euro", "sell", true);
                    customer1.leaveBank();

                    ExchangedMoney += amount_to_change;
                    break;
                }
            }
            cout << "\n\n\n\n";
        }
    }

    // Insights
    cout << "Insights: " << "\n";
    cout << "Simulation running total time: " << TotalHours << " hours" << "\n";
    cout << "The number of customers: " << identifier - 1 << "\n";
    cout << "The number of men customers: " << mCustomers << "\n";
    cout << "The number of women customers: " << wCustomers << "\n";
    cout << "The number of customers for customer department: " << cdamount << "\n";
    cout << "The number of customers for insurance department: " << idamount << "\n";
    cout << "The number of customers for credit department: " << crdamount << "\n";
    cout << "The number of customers for investment department: " << invdamount << "\n";
    cout << "Amount of lei taken from the ATM: " << MoneyFromATM << "\n";
    cout << "Amount of euros exchanged: " << ExchangedMoney << "\n";
    return 0;
}