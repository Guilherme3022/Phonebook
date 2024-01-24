// main.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>  // Include the necessary header for system() function
using namespace std;

// Product structure
struct Product {
    int code;
    string name;
    float price;
    Product *next;
};

// Linked list structure
struct LinkedList {
    Product *start;
};

#include "bib.h" // Include the header file "bib.h" that contains utility functions.

// Function to read product information from the user.
void readProduct(Product &x) {
    cout << "Enter the code.\n";
    cin >> x.code;
    cout << "Enter the name.\n";
    cin >> x.name;
    cout << "Enter the price.\n";
    cin >> x.price;
}

// Function to print details of a product.
void writeProduct(Product *x) {
    cout << "Code: " << x->code << "\n";
    cout << "Name: " << x->name << "\n";
    cout << "Price: " << x->price << "\n";
}

// Function to print all products in a list.
void writeList(Product *prod, int i) {
    if (prod != NULL) {
        cout << "Product " << i << ":\n";
        writeProduct(prod);
        cout << "------------------------------------------------------------------" << endl;
        writeList(prod->next, i + 1);
    }
}

// Function to print the product at a specific position in the list.
bool writeProductPosition(Product *prod, int limit, int start) {
    if (limit == start) {
        writeProduct(prod);
        return true;
    }
    if (prod != NULL)
        return writeProductPosition(prod->next, limit, start + 1);
    else
        return false;
}

// Function to read products from a file and insert them into the list.
void readProductsFromFile(LinkedList &list) {
    ifstream file("list.txt");
    if (!file.is_open()) {
        cout << "Error opening the file.\n";
        return;
    }
    Product newProduct;
    while (file >> newProduct.code >> newProduct.name >> newProduct.price) {
        insert(list, newProduct);  // Calls the insert function to add the product to the list.
    }
    file.close();
}

// Function to write the products from the list to a file.
void writeListToFile(LinkedList &list) {
    ofstream file("list.txt");
    if (!file.is_open()) {
        cout << "Error opening the file.\n";
        return;
    }
    Product *nav = list.start;
    while (nav != NULL) {
        file << " " << nav->code << " " << nav->name << " " << nav->price << "\n";
        nav = nav->next;
    }
    file.close();
}

int main() {
    LinkedList market;
    int choice, givenCode;
    Product givenProduct;
    bool finished = false;

    initializeList(market);  // Initializes the linked list.

    readProductsFromFile(market);  // Reads products from the file and adds them to the list.

    do {
        clear();  // Clears the console screen.
        cout << "1 - Insert product into the list;\n2 - Remove product from the list;\n3 - Consult price of a product in the list by code;\n4 - Exit.\n";
        cout << "------------------------------------------------------------------" << endl;
        writeList(market.start, 1);  // Prints the list of products.
        cin >> choice;
        clear();  // Clears the console screen.
        switch (choice) {
            case 1:
                readProduct(givenProduct);  // Reads a new product from the user.
                insert(market, givenProduct);  // Adds the product to the list.
                break;
            case 2:
                cout << "Enter the product code.\n";
                cin >> givenCode;
                clear();  // Clears the console screen.
                if (remove(market, givenCode))
                    cout << "Product removed successfully.\n";
                else
                    cout << "Product not found in the list.\n";
                pause();  // Pauses the execution until the user presses a key.
                break;
            case 3: {
                cout << "Enter the product code.\n";
                cin >> givenCode;
                clear();  // Clears the console screen.
                int position = queryPos(market, givenCode);  // Queries the position of the product in the list.
                if (position != 0)
                    if (writeProductPosition(market.start, position, 1))
                        cout << "\nProduct found successfully!\n";
                    else
                        cout << "\nProduct not found in the list.\n";
                else
                    cout << "\nProduct not found in the list.\n";
                pause();  // Pauses the execution until the user presses a key.
                break;
            }
            case 4:
                writeListToFile(market);  // Writes the list of products to the file.
                finished = true;
                break;
            default:
                cout << "\nInvalid value. Enter a valid option.\n";
        }
    } while (!finished);
}
