#include <iostream>
using namespace std;

// struct to represent each product in the inventory
struct Product {
    int id;             // Identification number
    string name;        // Name of the product
    int quantity;       // Quantity of the product in stock
};

// array of Products to represent the inventory
Product inventory[5] = {
    {1, "Motherboards", 50},
    {2, "Hard disk", 50},
    {3, "Diskette", 50},
    {4, "Compact disk", 50},
    {5, "Memory Cards", 50}
};

// Function to display the inventory
void displayInventory() {
    cout << "\nIdentification Number\tProduct\t\tQuantity\n";
    for (int i = 0; i < 5; i++) {
        cout << "\t" << inventory[i].id << "\t\t" 
		<< inventory[i].name << "\t" << inventory[i].quantity << "\n";
    }
}

// Function to add items to the inventory
void addItems() {
    int id, quantity;
    cout << "Enter the identification number of the product to be added: ";
    cin >> id;
    for (int i = 0; i < 5; i++) {
        if (inventory[i].id == id) {
            cout << "Number of units to add: ";
            cin >> quantity;
            inventory[i].quantity += quantity;
            cout << "\n" << quantity << " " << inventory[i].name 
			<< " added to the inventory.\n";
            return;
        }
    }
    cout << "\nInvalid product identification number.\n";
}

// Function to remove items from the inventory
void removeItems() {
    int id, quantity;
    cout << "Enter the identification number of the product to be removed: ";
    cin >> id;
    for (int i = 0; i < 5; i++) {
        if (inventory[i].id == id) {
            cout << "Number of units to remove: ";
            cin >> quantity;
            if (quantity <= inventory[i].quantity) {
                inventory[i].quantity -= quantity;
                cout << "\n" << quantity << " " << inventory[i].name 
				<< " removed from the inventory.\n";
            }
            else {
                cout << "\nInsufficient quantity to remove from the inventory.\n";
            }
            return;
        }
    }
    cout << "\nInvalid product identification number.\n";
}
int main() {
    int choice;
    do {
        displayInventory();
        cout << "\nChoices\n";
        cout << "1. Add Items\n";
        cout << "2. Remove Items\n";
        cout << "3. Quit\n\n";
        cout << "Choose an operation to perform (1-3): ";
        cin >> choice;
        switch (choice) {
            case 1:
                addItems();
                break;
            case 2:
                removeItems();
                break;
            case 3:
                cout << "Program Terminated...\n";
                break;
            default:
                cout << "\nInvalid choice. Please choose again.\n";
                break;
        }
    } while (choice != 3);
    return 0;
}


