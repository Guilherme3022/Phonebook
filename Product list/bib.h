#include <iostream>
#include <stdlib.h>

using namespace std;

// Function to clear the console screen.
void clear() {
    system("cls");
}

// Function to pause the execution until the user presses a key.
void pause() {
    system("pause");
}

// Function to initialize the linked list.
bool initializeList(LinkedList &list) {
    list.start = NULL;
    return true;
}

// Function to insert a product into the list.
bool insert(LinkedList &list, Product &prod) {
    // Check if a product with the same code already exists
    Product *current = list.start;
    while (current != nullptr) {
        if (current->code == prod.code) {
            cout << "Error: Product with the same code already exists. Cannot insert.\n";
            return false;
        }
        current = current->next;
    }

    // If no product with the same code exists, proceed with insertion
    Product *aux = new Product(prod);
    aux->next = list.start;
    list.start = aux;
    return true;
}

// Function to remove a product from the list based on the code.
bool remove(LinkedList &list, int comparison) {
    Product *anterior = NULL;
    Product *atual = list.start;

    while (atual != NULL) {
        if (atual->code == comparison) {
            if (anterior == NULL)
                list.start = atual->next;
            else
                anterior->next = atual->next;
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->next;
    }
    return false;
}

// Function to query the position of a product in the list based on the code.
int queryPos(LinkedList list, int givenCode) {
    Product *nav = list.start;
    int i = 1;
    while (nav != NULL) {
        if (nav->code == givenCode)
            return i;
        else {
            nav = nav->next;
            i++;
        }
    }
    return 0;
}
