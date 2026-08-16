#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void headerDesign () {
    cout << "=========================================" << endl;
    cout << "====        POI'S TAPSILOGAN         ====" << endl;
    cout << "=========================================" << endl;
}

struct Product{
    int id;
    string productName;
    int price;
};

struct Order {
    string productName;
    int price;
    int quantity;
    int subtotal;
};

void displayProducts(vector<Product> products) {

    cout << left
         << setw(8) << "ID"
         << setw(20) << "Product"
         << setw(10) << "Price" << endl;

    cout << "-----------------------------------------" << endl;

    for (Product product : products) {
        cout << left
             << setw(8) << product.id
             << setw(20) << product.productName
             << setw(10) << product.price << endl;
    }
}

int main(){
    vector<Order> orders;

    vector<Product> products = {
    {1, "Tapsilog", 150},
    {2, "Spamsilog", 120},
    {3, "Tocilog", 120},
    {4, "Liemsilog", 180},
    {5, "Bottled water", 25},
    {6, "Nestea", 35},
    {7, "Coca-Cola", 30},
    {8, "Mountain Dew", 30}
};

    headerDesign();
    displayProducts(products);

    int choice;
    int quantity;
    int payment;
    int total = 0;
    char add ='y';
    while (add == 'y' || add == 'Y') {

        bool found = false;

        cout << endl;

        cout << "Enter product ID: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        for (Product product : products) {
            if (product.id == choice) {
                found = true;

                cout << "Product: " << product.productName << endl;
                cout << "Price: " << product.price << " pesos" << endl;

                cout << endl;

                cout << "Enter quantity: ";
                cin >> quantity;

                if (cin.fail()) {
                    cout << "Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    continue;
                }

                int subtotal = product.price * quantity;

                total += subtotal;

                Order order;

                order.productName = product.productName;
                order.price = product.price;
                order.quantity = quantity;
                order.subtotal = subtotal;

                orders.push_back(order);

                cout << "Subtotal: " << subtotal << " pesos" << endl;
            }
        }

        if (!found) {
        cout << "Invalid product ID." << endl;
        continue;
        }

        cout << "Current total: " << total << " pesos" << endl;

        cout << endl;
        cout << "Add another product? (y/n): ";
        cin >> add;
    }

    cout << endl;
    cout << "=========================================" << endl;
    cout << "Total: " << total << " pesos" << endl;

    cout << endl;

    cout << "Enter payment: ";
    cin >> payment;

    if (payment < total) {
        cout << "Insufficient payment!" << endl;
    } 

    int change = payment - total;

    system("pause");
    system("cls");

    cout << endl;
    cout << "=========================================" << endl;
    cout << "          POI'S TAPSILOGAN" << endl;
    cout << "=========================================" << endl;

    for (Order order : orders) {
        cout << order.productName
            << " x" << order.quantity
            << " = " << order.subtotal
            << " pesos" << endl;
    }

    cout << "-----------------------------------------" << endl;
    cout << "Total: " << total << " pesos" << endl;
    cout << "Payment: " << payment << " pesos" << endl;
    cout << "Change: " << change << " pesos" << endl;

    cout << "=========================================" << endl;
    cout << "             MATSALA!!!" << endl;
    cout << "=========================================" << endl;
}