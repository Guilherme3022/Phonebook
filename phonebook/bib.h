#include <iostream>
#include <string>

using namespace std;

/// Function to clear the console screen.
void clear() {
    system("cls");
}

/// Function to pause and wait for user action.
void pause() {
    system("pause");
}

/// Template structure representing an agenda to store items of type TYPE.
template <typename TYPE>
struct Agenda {
    TYPE* items;         /// Pointer to an array of items of type TYPE.
    int quantity;        /// Current number of items in the agenda.
    int maxSize;         /// Maximum size of the agenda.
};

/// Template function to remove an item from the agenda at a specific position.
template <typename TYPE>
bool remove(Agenda<TYPE> &agenda, int position) {
    if (position < 0 || position >= agenda.quantity) {
        return false;
    }

    for (int i = position; i < agenda.quantity - 1; i++) {
        agenda.items[i] = agenda.items[i + 1];
    }

    agenda.quantity--;
    return true;
}

/// Template function to initialize an agenda with a specified maximum size.
template <typename TYPE>
void initializeAgenda(Agenda<TYPE> &agenda, int maxSize) {
    agenda.maxSize = maxSize;
    agenda.quantity = 0;
    agenda.items = new TYPE[agenda.maxSize];
}

/// Template function to insert an item into the agenda.
template <typename TYPE>
bool insert(Agenda<TYPE> &agenda, TYPE data) {
    if (agenda.quantity >= agenda.maxSize) {
        return false;
    }

    agenda.items[agenda.quantity] = data;
    agenda.quantity++;
    return true;
}
