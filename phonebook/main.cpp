#include "bib.h" // Includes the header file "bib.h" which contains function and structure definitions.

struct Personal { // Defines a structure named "Personal" to store personal information.
    string id, cpf, name, phone; // Declares structure member variables.
};

struct Business { // Defines a structure named "Business" to store business information.
    string id, cnpj, companyName, businessPhone; // Declares structure member variables.
};

istream& operator>>(istream &is, Personal &contact) { // Overloads the extraction operator (>>) to add a contact to the personal agenda.
    cout << "ID: ";
    cin >> contact.id;
    cout << "\nCPF: ";
    cin >> contact.cpf;
    cout << "\nName: ";
    cin >> contact.name;
    cout << "\nPhone: ";
    cin >> contact.phone;
}

istream& operator>>(istream &is, Business &contact) { // Overloads the extraction operator (>>) to add a contact to the business agenda.
    cout << "ID: ";
    cin >> contact.id;
    cout << "\nCNPJ: ";
    cin >> contact.cnpj;
    cout << "\nCompany Name: ";
    cin >> contact.companyName;
    cout << "\nBusiness Phone: ";
    cin >> contact.businessPhone;
}

void sortByname(Agenda<Personal> &agenda) { // Defines a function to sort a personal contacts agenda by name.
    int numContacts = agenda.quantity; // Gets the number of items in the agenda.

    for (int i = 0; i < numContacts - 1; i++) { // Outer loop to iterate through the items in the agenda.
        for (int j = 0; j < numContacts - i - 1; j++) { // Inner loop to perform comparisons and swaps.
            if (agenda.items[j].name > agenda.items[j + 1].name) { // Compares the names of two contacts.
                Personal temp = agenda.items[j]; // Temporarily stores the current contact in "temp".
                agenda.items[j] = agenda.items[j + 1]; // Replaces the current contact with the next one in the sorting.
                agenda.items[j + 1] = temp; // Stores the temporary contact in place of the next one.
            }
        }
    }
}

void sortByCompanyName(Agenda<Business> &agenda) { // Defines a function to sort a business contacts agenda by company name.
    int numContacts = agenda.quantity; // Gets the number of items in the agenda.

    for (int i = 0; i < numContacts - 1; i++) { // Outer loop to iterate through the items in the agenda.
        for (int j = 0; j < numContacts - i - 1; j++) { // Inner loop to perform comparisons and swaps.
            if (agenda.items[j].companyName > agenda.items[j + 1].companyName) { // Compares the names of two companies.
                Business temp = agenda.items[j]; // Temporarily stores the current contact in "temp".
                agenda.items[j] = agenda.items[j + 1]; // Replaces the current contact with the next one in the sorting.
                agenda.items[j + 1] = temp; // Stores the temporary contact in place of the next one.
            }
        }
    }
}

ostream& operator<<(ostream &os, const Agenda<Personal> &agenda) { // Overloads the insertion operator (<<) for the personal contacts agenda.
    for (int i = 0; i < agenda.quantity; i++) { // Loop to print the contacts in the agenda.
        cout << "ID: " << agenda.items[i].id << endl;
        cout << "CPF: " << agenda.items[i].cpf << endl;
        cout << "Name: " << agenda.items[i].name << endl;
        cout << "Phone: " << agenda.items[i].phone << endl;
        cout << "______________________________________________________________" << endl;
    }
}

ostream& operator<<(ostream &os, const Agenda<Business> &agenda) { // Overloads the insertion operator (<<) for the business contacts agenda.
    for (int i = 0; i < agenda.quantity; i++) { // Loop to print the contacts in the agenda.
        cout << "ID: " << agenda.items[i].id << endl;
        cout << "CNPJ: " << agenda.items[i].cnpj << endl;
        cout << "Company Name: " << agenda.items[i].companyName << endl;
        cout << "Business Phone: " << agenda.items[i].businessPhone << endl;
        cout << "______________________________________________________________" << endl;
    }
}

int selectPersonalOrBusiness() { // Function to allow the user to select between personal and business agendas.
    int choice = 0;
    while (choice != 1 && choice != 2) { // Loop to ensure a valid choice.
        cout << "1 - Personal.\n2 - Business.\n";
        cin >> choice; // Reads the user's choice.
        if (choice != 1 && choice != 2) // Checks if the choice is valid.
            cout << "Invalid value. Enter 1 for Personal or 2 for Business.";
    }
    return choice; // Returns the user's choice (1 for Personal, 2 for Business).
}

int locate(Agenda<Personal> &agenda, string data) { // Function to locate a personal contact by ID or name.
    for (int i = 0; i < agenda.quantity; i++) { // Loop to iterate through the contacts in the agenda.
        if (agenda.items[i].id == data || agenda.items[i].name == data) { // Compares the ID or name of the contact with the given value.
            return i; // Returns the position of the contact in the agenda.
        }
    }
    return -1; // Returns -1 if the contact is not found.
}

int locate(Agenda<Business> &agenda, string &data) { // Function to locate a business contact by ID or company name.
    for (int i = 0; i < agenda.quantity; i++) { // Loop to iterate through the contacts in the agenda.
        if (agenda.items[i].id == data || agenda.items[i].companyName == data) { // Compares the ID or company name with the given value.
            return i; // Returns the position of the contact in the agenda.
        }
    }
    return -1; // Returns -1 if the contact is not found.
}

int main() { // Main function.
    Personal personalContact; // Declares a variable for a personal contact.
    Business businessContact; // Declares a variable for a business contact.
    Agenda<Personal> personalAgenda; // Declares a personal contacts agenda.
    personalAgenda.maxSize = 10; // Sets the maximum size of the agenda.
    personalAgenda.quantity = 0; // Initializes the quantity of contacts in the agenda.
    personalAgenda.items = new Personal[personalAgenda.maxSize]; // Allocates memory for personal contacts.
    initializeAgenda(personalAgenda, 10); // Initializes the personal contacts agenda.
    Agenda<Business> businessAgenda; // Declares a business contacts agenda.
    businessAgenda.maxSize = 10; // Sets the maximum size of the agenda.
    businessAgenda.quantity = 0; // Initializes the quantity of contacts in the agenda.
    businessAgenda.items = new Business[businessAgenda.maxSize]; // Allocates memory for business contacts.
    initializeAgenda(businessAgenda, 10); // Initializes the business contacts agenda.
    int choice; // Variable to store the user's choice.
    bool finished = false; // Variable to control program exit.

    while (!finished) { // Main program loop.
        cout << "1 - Insert a new item into the agenda.\n2 - Remove an item from the agenda (by ID or name).\n";
        cout << "3 - Search for an item in the agenda (by ID or name).\n4 - Sort the agenda by name.\n";
        cout << "5 - Show all items in the agenda.\n6 - End the program.\n";
        cin >> choice; // Reads the user's choice.
        switch (choice) { // Switch to execute the corresponding action based on the choice.
            case 1: { // Case 1: Insert a new contact into the agenda.
                if (selectPersonalOrBusiness() == 1) { // Checks if the user chose the personal agenda.
                    Personal personalContact;
                    cin >> personalContact; // Reads the information for the personal contact.
                    insert(personalAgenda, personalContact); // Inserts the contact into the personal agenda.
                    cout << "\nContact added\n";
                    system("pause");
                    system("cls");
                } else { // Otherwise, the user chose the business agenda.
                    Business businessContact;
                    cin >> businessContact; // Reads the information for the business contact.
                    insert(businessAgenda, businessContact); // Inserts the contact into the business agenda.
                    cout << "\nContact added\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 2: { // Case 2: Remove an item from the agenda.
                string data;
                if (selectPersonalOrBusiness() == 1) { // Checks if the user chose the personal agenda.
                    cout << "Enter the name/ID of the contact you want to remove\n";
                    cin >> data;
                    int pos = locate(personalAgenda, data); // Locates the contact in the personal agenda.
                    if (pos != -1) { // Checks if the contact was found.
                        remove(personalAgenda, pos); // Removes the contact from the personal agenda.
                        cout << "\nContact removed\n";
                    } else {
                        cout << "Contact not found. Nothing was removed.\n";
                    }
                    system("pause");
                    system("cls");
                } else { // Otherwise, the user chose the business agenda.
                    cout << "Enter the name/ID of the contact you want to remove\n";
                    cin >> data;
                    int pos = locate(businessAgenda, data); // Locates the contact in the business agenda.
                    if (pos != -1) { // Checks if the contact was found.
                        remove(businessAgenda, pos); // Removes the contact from the business agenda.
                        cout << "\nContact removed\n";
                    } else {
                        cout << "Contact not found. Nothing was removed.\n";
                    }
                    system("pause");
                    system("cls");
                }
                clear();
                break;
            }
            case 3: { // Case 3: Search for an item in the agenda.
                int auxPos;
                string data;
                if (selectPersonalOrBusiness() == 1) { // Checks if the user chose the personal agenda.
                    cout << "Enter the name/ID of the contact you want to locate\n";
                    cin >> data;
                    int pos = locate(personalAgenda, data); // Locates the contact in the personal agenda.
                    if (pos != -1) { // Checks if the contact was found.
                        auxPos = locate(personalAgenda, data);
                        system("cls");
                        cout << "ID: " << personalAgenda.items[auxPos].id << endl; // Displays the information for the personal contact.
                        cout << "CPF: " << personalAgenda.items[auxPos].cpf << endl;
                        cout << "Name: " << personalAgenda.items[auxPos].name << endl;
                        cout << "Phone: " << personalAgenda.items[auxPos].phone << endl;
                        system("pause");
                        system("cls");
                    } else {
                        cout << "Contact not found. Nothing was located.\n";
                        system("pause");
                        system("cls");
                    }
                } else { // Otherwise, the user chose the business agenda.
                    cout << "Enter the name/ID of the contact you want to locate\n";
                    cin >> data;
                    int pos = locate(businessAgenda, data); // Locates the contact in the business agenda.
                    if (pos != -1) { // Checks if the contact was found.
                        auxPos = locate(personalAgenda, data);
                        system("cls");
                        cout << "ID: " << businessAgenda.items[auxPos].id << endl; // Displays the information for the business contact.
                        cout << "CNPJ: " << businessAgenda.items[auxPos].cnpj << endl;
                        cout << "Company Name: " << businessAgenda.items[auxPos].companyName << endl;
                        cout << "Phone: " << businessAgenda.items[auxPos].businessPhone << endl;
                        system("pause");
                        system("cls");
                    } else {
                        cout << "Contact not found. Nothing was located.\n";
                        system("pause");
                        system("cls");
                    }
                }
                break;
            }
            case 4: { // Case 4: Sort the agenda by name.
                if (selectPersonalOrBusiness() == 1) { // Checks if the user chose the personal agenda.
                    sortByname(personalAgenda); // Calls the function to sort the personal agenda by name.
                    cout << "Personal Agenda sorted by name.\n";
                    system("pause");
                    system("cls");
                } else { // Otherwise, the user chose the business agenda.
                    sortByCompanyName(businessAgenda); // Calls the function to sort the business agenda by company name.
                    cout << "Business Agenda sorted by company name.\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 5: { // Case 5: Show all items in the agenda.
                if (selectPersonalOrBusiness() == 1) { // Checks if the user chose the personal agenda.
                    cout << personalAgenda; // Calls the output function to display personal contacts.
                    system("pause");
                    system("cls");
                } else { // Otherwise, the user chose the business agenda.
                    cout << businessAgenda; // Calls the output function to display business contacts.
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 6: // Case 6: End the program.
                cout << "Program terminated";
                finished = true; // Sets the "finished" variable to true to exit the loop.
                break;
            default: // Default case: Invalid
                cout << "Invalid value, choose an available option.\n";
                break;

        }
    }
    delete[] personalAgenda.items; // Frees the memory allocated for the personal contacts agenda.
    delete[] businessAgenda.items; // Frees the memory allocated for the business contacts agenda.
    return 0; // Returns 0 to indicate the successful completion of the program.
}

