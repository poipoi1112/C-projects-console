#include <iostream>
#include <string>
using namespace std;

bool login() {
    cout << "======= Cinema Reservation System =======" << endl;
    string correctUsername = "poipoiCodes";
    string correctPassword = "crsByP000y";

    string username;
    string password;
    
    while(true){
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        if(username == correctUsername && password ==correctPassword) {
            cout << "Login succesful" << endl;
            return true;
        } else {
            cout << "Try again" << endl;
        }
    }
}

bool chooseMovie(string &movie, int &price) {

    cout << "=========== Movies Available ============" << endl;
    cout << "1. Hacksaw Ridge = 300  (9:00 - 11:30AM)" << endl;
    cout << "2. CHEF = 250           (1:00 - 2:30PM)" << endl;
    cout << "3. Forrest Gump = 300   (3:00 - 5:30PM)" << endl;
    cout << "=========================================" << endl;

    string movie1 = "1";
    string movie2 = "2";
    string movie3 = "3";

    string choice;

    while(true) {

        cout << "Choose a movie no.: ";
        cin >> choice;

        if(choice == movie1) {

            movie = "Hacksaw Ridge";
            price = 300;

            cout << "You chose Hacksaw Ridge!" << endl;
            return true;

        } else if(choice == movie2) {

            movie = "CHEF";
            price = 250;

            cout << "You chose CHEF!" << endl;
            return true;

        } else if(choice == movie3) {

            movie = "Forrest Gump";
            price = 300;

            cout << "You chose Forrest Gump!" << endl;
            return true;

        } else {
            cout << "INVALID MOVIE!" << endl;
        }
    }
}

void customerDetails(string &customerName, int &age) {
    cout << "=========== Customer Details ===========" << endl;
    cout << "Enter customer name: ";
    cin >> customerName;
    cout << "Enter customer age: ";
    cin >> age;

    if(age >= 13) {
        cout << "Customer can watch the movie." << endl;
    } else {
        cout << "Movie is for 13 years old above only." << endl;
    }
}

char seats[8][8];

void initializeSeats(char seats[8][8]) {
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            seats[row][col] = 'O';
        }
    }
}

void displaySeats(char seats[8][8]) {

    cout << "========== Seats Availability ==========" << endl;

    int seatNumber = 1;

    for(int row = 0; row < 8; row++) {

        for(int col = 0; col < 8; col++) {

            cout << seatNumber << " " << seats[row][col] << "\t";

            seatNumber++;
        }

        cout << endl;
    }
}

void reserveSeat(char seats[8][8], int &seatNumber) {

    cout << "Enter seat number (1-64): ";
    cin >> seatNumber;

    if(seatNumber < 1 || seatNumber > 64) {
        cout << "Invalid seat number!" << endl;
        return;
    }

    int arrayRow = (seatNumber - 1) / 8;
    int arrayCol = (seatNumber - 1) % 8;

    if(seats[arrayRow][arrayCol] == 'O') {

        seats[arrayRow][arrayCol] = 'X';

        cout << "Seat is reserved successfully!" << endl;

    } else {

        cout << "Seat not available!" << endl;
    }
}

void bookingDetails(string customerName, int age, string movie, int price, int seatNumber) {
    cout << "============ BOOKING DETAILS ============" << endl;
    cout << "Customer name: " << customerName << endl;
    cout << "Customer age: " << age << endl;
    cout << "Movie: " << movie << endl;
    cout << "Ticket price: " << price << " pesos" << endl;
    cout << "Seat number: " << seatNumber << endl;
    cout << "=========================================" << endl;
}

bool bookingConfirmation() {

    char confirmed = 'Y';
    char notConfirmed = 'N';

    char confirm;

    while(true) {

        cout << "Confirm booking? (Y/N): ";
        cin >> confirm;

        if(confirm == confirmed) {

            cout << "Confirmation successful!" << endl;
            return true;

        } else if(confirm == notConfirmed) {

            cout << "Confirmation not successful!" << endl;
            return false;

        } else {

            cout << "INVALID!" << endl;
        }
    }
}

int main() {

    string customerName;
    int age = 0; 
    string movie;
    int price;
    int seatNumber;

    if(login()) {
        system("pause");
        system("cls");
        chooseMovie(movie, price);
        system("pause");
        system("cls");
        customerDetails(customerName, age);
        system("pause");
        system("cls");
        char seats[8][8];
        initializeSeats(seats);
        displaySeats(seats);
        reserveSeat(seats, seatNumber);
        system("pause");
        system("cls");
        displaySeats(seats);
        system("pause");
        system("cls");
        bookingDetails(customerName, age, movie, price, seatNumber);
        bookingConfirmation();
    }

    return 0;
}