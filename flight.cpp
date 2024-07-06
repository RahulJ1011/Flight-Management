#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Details {
public:
    static string name, gender;
    static int customerId;
    int phNumber, age;
    string add;

    void information() {
        cout << "\nEnter the Customer ID:";
        cin >> customerId;
        cout << "\nEnter the name :";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, name); // Use getline to capture full name
        cout << "\nEnter the age:";
        cin >> age;
        cout << "\nAddress:";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, add); // Use getline to capture address
        cout << "\nGender:";
        cin >> gender;
        cout << "Your details are saved with us\n" << endl;
    }
};

int Details::customerId;
string Details::name;
string Details::gender;

class Registration {
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void showFlights() {
        string flights[] = {"India", "England", "Malaysia", "Singapore"};
        for (int a = 0; a < sizeof(flights)/sizeof(flights[0]); a++) {
            cout << (a + 1) << ". Flight to " << flights[a] << endl;
        }
    }

    void bookFlight() {
        cout << "\nWelcome to the Airlines" << endl;
        cout << "Press the number of the country of which you want to book the flights:";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "__________________________Welcome to India superjet_____________\n" << endl;
                cout << "Your comfort is our priority. Enjoy the journey!" << endl;
                cout << "Following are the Flights \n" << endl;
                cout << "1. Ind - 998" << endl;
                cout << "\t10-06-2024 5:00PM 10hrs Rs.14000" << endl;
                cout << "2. Ind - 458" << endl;
                cout << "\t10-06-2024 7:00PM 9hrs Rs.14660" << endl;
                cout << "3. Ind - 928" << endl;
                cout << "\t10-06-2024 8:00PM 12hrs Rs.12000" << endl;
                cout << "\nSelect the flight you want to book:" << endl;
                cin >> choice1;

                if (choice1 == 1 || choice1 == 2 || choice1 == 3) {
                    charges = (choice1 == 1) ? 14000 : ((choice1 == 2) ? 14660 : 12000);
                    cout << "\nYou have successfully booked the flight Ind-" << (choice1 == 1 ? 998 : (choice1 == 2 ? 458 : 928)) << endl;
                    cout << "You can go back to the menu and take the ticket" << endl;
                } else {
                    cout << "Invalid Input, shifting to the main menu!" << endl;
                }
                break;
            }
            case 2: {
                cout << "__________________________Welcome to England superjet_____________\n" << endl;
                cout << "Your comfort is our priority. Enjoy the journey!" << endl;
                cout << "Following are the Flights \n" << endl;
                cout << "1. UK - 598" << endl;
                cout << "\t11-06-2024 10:00PM 20hrs Rs.10000" << endl;
                cout << "2. UK - 958" << endl;
                cout << "\t11-06-2024 11:00PM 19hrs Rs.12660" << endl;
                cout << "3. UK - 918" << endl;
                cout << "\t11-06-2024 12:00PM 21hrs Rs.12300" << endl;
                cout << "\nSelect the flight you want to book:" << endl;
                cin >> choice1;

                if (choice1 == 1 || choice1 == 2 || choice1 == 3) {
                    charges = (choice1 == 1) ? 10000 : ((choice1 == 2) ? 12660 : 12300);
                    cout << "\nYou have successfully booked the flight UK-" << (choice1 == 1 ? 598 : (choice1 == 2 ? 958 : 918)) << endl;
                    cout << "You can go back to the menu and take the ticket" << endl;
                } else {
                    cout << "Invalid Input, shifting to the main menu!" << endl;
                }
                break;
            }
            case 3: {
                cout << "__________________________Welcome to Malaysia superjet_____________\n" << endl;
                cout << "Your comfort is our priority. Enjoy the journey!" << endl;
                cout << "Following are the Flights \n" << endl;
                cout << "1. ML - 798" << endl;
                cout << "\t10-06-2024 5:00PM 10hrs Rs.24000" << endl;
                cout << "2. ML - 458" << endl;
                cout << "\t10-06-2024 10:00PM 9hrs Rs.19660" << endl;
                cout << "3. ML - 928" << endl;
                cout << "\t10-06-2024 8:00PM 12hrs Rs.20000" << endl;
                cout << "\nSelect the flight you want to book:" << endl;
                cin >> choice1;

                if (choice1 == 1 || choice1 == 2 || choice1 == 3) {
                    charges = (choice1 == 1) ? 24000 : ((choice1 == 2) ? 19660 : 20000);
                    cout << "\nYou have successfully booked the flight ML-" << (choice1 == 1 ? 798 : (choice1 == 2 ? 458 : 928)) << endl;
                    cout << "You can go back to the menu and take the ticket" << endl;
                } else {
                    cout << "Invalid Input, shifting to the main menu!" << endl;
                }
                break;
            }
            case 4: {
                cout << "__________________________Welcome to Singapore superjet_____________\n" << endl;
                cout << "Your comfort is our priority. Enjoy the journey!" << endl;
                cout << "Following are the Flights \n" << endl;
                cout << "1. SP - 698" << endl;
                cout << "\t10-06-2024 5:00PM 24hrs Rs.34000" << endl;
                cout << "2. SP - 758" << endl;
                cout << "\t10-06-2024 10:00PM 19hrs Rs.18060" << endl;
                cout << "3. SP - 1028" << endl;
                cout << "\t10-06-2024 11:00PM 12hrs Rs.12000" << endl;
                cout << "\nSelect the flight you want to book:" << endl;
                cin >> choice1;

                if (choice1 == 1 || choice1 == 2 || choice1 == 3) {
                    charges = (choice1 == 1) ? 34000 : ((choice1 == 2) ? 18060 : 12000);
                    cout << "\nYou have successfully booked the flight SP-" << (choice1 == 1 ? 698 : (choice1 == 2 ? 758 : 1028)) << endl;
                    cout << "You can go back to the menu and take the ticket" << endl;
                } else {
                    cout << "Invalid Input, shifting to the main menu!" << endl;
                }
                break;
            }
            default: {
                cout << "Invalid Input, shifting to the main menu!" << endl;
                break;
            }
        }
    }
};

float Registration::charges;
int Registration::choice;

class Ticket : public Registration, Details {
public:
    void bill() {
        string destination = "";
        ofstream outf("records.txt", ios::app); // Open file in append mode
        if (!outf) {
            cout << "File error!" << endl;
            return;
        }

        outf << "__________________ABC Airlines______________" << endl;
        outf << "__________________Ticket_____________________" << endl;
        outf << "______________________________________________" << endl;
        outf << "Customer ID:" << Details::customerId << endl;
        outf << "Customer Name:" << Details::name << endl;
        outf << "Customer Gender:" << Details::gender << endl;
        outf << "\tDescription" << endl << endl;

        if (Registration::choice == 1) {
            destination = "India";
        } else if (Registration::choice == 2) {
            destination = "England";
        } else if (Registration::choice == 3) {
            destination = "Malaysia";
        } else if (Registration::choice == 4) {
            destination = "Singapore";
        }

        outf << "Destination\t\t" << destination << endl;
        outf << "Flight cost \t\t" << Registration::charges << endl;
        outf.close();
    }

    void display() {
        ifstream ifs("records.txt");
        if (!ifs) {
            cout << "File error!" << endl;
            return;
        }

        string line;
        while (getline(ifs, line)) {
            cout << line << endl;
        }

        ifs.close();
    }
};

void mainMenu() {
    int lchoice;
    int back;
    cout << "\t ABC Airlines \n" << endl;
    cout << "\t___________________________Main Menu_________________" << endl;
    cout << "\t_____________________________" << endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "\t\t Press 1 to add the customer details            \t" << endl;
    cout << "\t\t Press 2 for flight Registration                \t" << endl;
    cout << "\t\t Press 3 for Ticket and charges                  \t" << endl;
    cout << "\t\t Press 4 for exit                                \t" << endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "t____________________________________________________________________" << endl;
    cout << "Enter the choice:" << endl;
    cin >> lchoice;

    Details d;
    Registration r;
    Ticket t;

    switch (lchoice) {
        case 1: {
            cout << "_______Customers___________\n" << endl;
            d.information();
            cout << "Press any key to go back to Main menu";
            cin.ignore(); // Ignore any leftover newline characters
            cin.get();    // Wait for user to press a key
            mainMenu();
            break;
        }
        case 2: {
            cout << "______________Book a flight using this system___________\n" << endl;
            r.showFlights();
            r.bookFlight();
            mainMenu();
            break;
        }
        case 3: {
            cout << "___________Get Your Ticket_____________\n" << endl;
            t.bill();
            cout << "Your ticket is printed, you can collect it \n" << endl;
            cout << "Press 1 to display your ticket" << endl;
            cin >> back;
            if (back == 1) {
                t.display();
                cout << "Press any key to go back to main menu" << endl;
                cin.ignore(); // Ignore any leftover newline characters
                cin.get();    // Wait for user to press a key
                mainMenu();
            } else {
                mainMenu();
            }
            break;
        }
        case 4: {
            cout << "\n\n\n\t____________Thank You________" << endl;
            break;
        }
        default: {
            cout << "Invalid Input, please try again \n" << endl;
            mainMenu();
            break;
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
