#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Patient {
    string patientID;
    string firstName;
    string lastName;
    int age;
    string gender;
    string contact;
    string address;
    string doctor;
    string room;
    string admissionDate;
    bool admitted;
};

struct Doctor {
    string doctorID;
    string name;
    string specialization;
};

struct MedicalRecord {
    string patientID;
    string diagnosis;
    string treatment;
    string notes;
};

struct Consultation {
    string patientID;
    string doctorID;
    string date;
    string time;
    string reason;
};

struct Surgery {
    string patientID;
    string doctorID;
    string surgeryName;
    string date;
    string time;
};

struct Room {
    int roomNumber;
    int totalBeds;
    int occupiedBeds;
};

vector <Patient> patients;
vector <Doctor> doctors;
vector <MedicalRecord> medicalRecords;
vector <Consultation> consultations;
vector <Surgery> surgeries;
vector <Room> rooms;

void pauseScreen() {
    cout << endl;
    cout << "PRESS ENTER TO CONTINUE...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
    cout << endl;
    cout << endl;
    cout << endl;
}

int findPatient(string patientID) {
    for(int i =0; i < patients.size(); i++) {
        if(patients[i].patientID == patientID) {
            return i;
        }
    }
    return -1;
}

int findDoctor(string doctorID) {
    for(int i = 0; i < doctors.size(); i++) {
        if(doctors[i].doctorID == doctorID) {
            return i;
        }
    }
    return -1;
}

void registerPatient() {
    Patient p;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==          REGISTER NEW PATIENT            ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> p.patientID;

    if(findPatient(p.patientID) != -1) {
        cout << endl;
        cout << "Patient ID already exists." << endl;
        return;
    }

    cout << "First Name: ";
    cin >> p.firstName;

    cout << "Last Name: ";
    cin >> p.lastName;

    cout << "Age: ";
    cin >> p.age;

    cout << "Gender: ";
    cin >> p.gender;

    cout << "Contact Number: ";
    cin >> p.contact;

    cin.ignore();

    cout << "Address: ";
    getline(cin, p.address);

    cout << "Doctor: ";
    getline(cin, p.doctor);

    cout << "Room: ";
    cin >> p.room;

    cout << "Admission Date: ";
    cin >> p.admissionDate;

    p.admitted = true;

    patients.push_back(p);

    cout << endl;
    cout << "Patient registered successfully!" << endl;
}

void searchPatient() {
    string id;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==             SEARCH PATIENT               ==" << endl;
    cout << "==============================================" << endl;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = findPatient(id);

    if(index == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    Patient p = patients[index];

    cout << endl;

    cout << "Patient Found!" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Patient ID:      " << p.patientID << endl;
    cout << "Name:            " << p.firstName << " " << p.lastName << endl;
    cout << "Age:             " << p.age << endl;
    cout << "Gender:          " << p.gender << endl;
    cout << "Contact:         " << p.contact << endl;
    cout << "Address:         " << p.address << endl;
    cout << "Doctor:          " << p.doctor << endl;
    cout << "Room:            " << p.room << endl;
    cout << "Admission Date:  " << p.admissionDate << endl;
    cout << "Status:          "
         << (p.admitted ? "Admitted" : "Discharged") << endl;
}

void viewPatient() {
    string id;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==              VIEW PATIENT                ==" << endl;
    cout << "==============================================" << endl;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = findPatient(id);

    if (index == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    Patient p = patients[index];
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==            PATIENT INFORMATION           ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID:      " << p.patientID << endl;
    cout << "First Name:      " << p.firstName << endl;
    cout << "Last Name:       " << p.lastName << endl;
    cout << "Age:             " << p.age << endl;
    cout << "Gender:          " << p.gender << endl;
    cout << "Contact:         " << p.contact << endl;
    cout << "Address:         " << p.address << endl;
    cout << "Doctor:          " << p.doctor << endl;
    cout << "Room:            " << p.room << endl;
    cout << "Admission Date:  " << p.admissionDate << endl;
    cout << "Status:          "
         << (p.admitted ? "Admitted" : "Discharged") << endl;
}

void updatePatient() {
    string id;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==             UPDATE PATIENT               ==" << endl;
    cout << "==============================================" << endl;

    cout << "Enter Patient ID: ";
    cin >> id;

    int index = findPatient(id);

    if(index == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    Patient &p = patients[index];
    cout << endl;
    cout << "Enter new information." << endl;

    cout << "First Name: ";
    cin >> p.firstName;

    cout << "Last Name: ";
    cin >> p.lastName;

    cout << "Age: ";
    cin >> p.age;

    cout << "Gender: ";
    cin >> p.gender;

    cout << "Contact Number: ";
    cin >> p.contact;

    cin.ignore();

    cout << "Address: ";
    getline(cin, p.address);

    cout << "Doctor: ";
    getline(cin, p.doctor);

    cout << "Room: ";
    cin >> p.room;

    cout << endl;
    cout << "Patient updated successfully!" << endl;
}

void listPatients() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==              ALL PATIENTS                ==" << endl;
    cout << "==============================================" << endl;

    if(patients.empty()) {

        cout << "No patients registered." << endl;
        return;
    }

    cout << left
         << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(8) << "Age"
         << setw(15) << "Gender"
         << setw(15) << "Status"
         << endl;

    cout << "--------------------------------------------------------------"
         << endl;

    for(Patient p : patients) {

        string fullName = p.firstName + " " + p.lastName;

        cout << left
             << setw(12) << p.patientID
             << setw(20) << fullName
             << setw(8) << p.age
             << setw(15) << p.gender
             << setw(15)
             << (p.admitted ? "Admitted" : "Discharged")
             << endl;
    }
}

void patientManagement() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==           PATIENT MANAGEMENT             ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Register New Patient                 ==" << endl;
        cout << "== [2] Search Patient                       ==" << endl;
        cout << "== [3] View Patient                         ==" << endl;
        cout << "== [4] Update Patient                       ==" << endl;
        cout << "== [5] List All Patients                    ==" << endl;
        cout << "== [6] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            registerPatient();
            pauseScreen();
            break;

        case 2:
            searchPatient();
            pauseScreen();
            break;

        case 3:
            viewPatient();
            pauseScreen();
            break;

        case 4:
            updatePatient();
            pauseScreen();
            break;

        case 5:
            listPatients();
            pauseScreen();
            break;

        case 6:
            cout << endl;
            cout << "Returning to Main Menu..." << endl;
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 6);
}

void addMedicalRecord() {
    MedicalRecord record;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==          ADD MEDICAL RECORD              ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> record.patientID;

    if(findPatient(record.patientID) == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    cin.ignore();

    cout << "Diagnosis: ";
    getline(cin, record.diagnosis);

    cout << "Treatment: ";
    getline(cin, record.treatment);

    cout << "Notes: ";
    getline(cin, record.notes);

    medicalRecords.push_back(record);

    cout << endl;
    cout << "Medical record added successfully!" << endl;
}

void viewMedicalRecords() {
    string id;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "==              PATIENT CHART               ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> id;

    bool found = false;

    for(MedicalRecord record : medicalRecords) {
        if(record.patientID == id) {
            found = true;

            cout << endl;
            cout << "Diagnosis: " << record.diagnosis << endl;
            cout << "Treatment: " << record.treatment << endl;
            cout << "Notes:     " << record.notes << endl;
            cout << "----------------------------------------------"
                 << endl;
        }
    }

    if (!found) {
        cout << endl;
        cout << "No medical records found." << endl;
    }
}

void patientCharting() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==             PATIENT CHARTING             ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Add Medical Record                   ==" << endl;
        cout << "== [2] View Medical Records                 ==" << endl;
        cout << "== [3] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            addMedicalRecord();
            pauseScreen();
            break;

        case 2:
            viewMedicalRecords();
            pauseScreen();
            break;

        case 3:
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 3);
}

void bookConsultation() {
    Consultation c;

    cout << endl;
    cout << "==============================================" << endl;
    cout << "==          CONSULTATION BOOKING            ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> c.patientID;

    if(findPatient(c.patientID) == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    cout << "Doctor ID: ";
    cin >> c.doctorID;

    if(findDoctor(c.doctorID) == -1) {
        cout << endl;
        cout << "Doctor not found." << endl;
        return;
    }

    cout << "Date: ";
    cin >> c.date;

    cout << "Time: ";
    cin >> c.time;

    cin.ignore();

    cout << "Reason for Consultation: ";
    getline(cin, c.reason);

    consultations.push_back(c);

    cout << endl;
    cout << "Consultation booked successfully!" << endl;
}

void listConsultations() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==             CONSULTATIONS                ==" << endl;
    cout << "==============================================" << endl;

    if (consultations.empty()) {

        cout << "No consultations booked." << endl;
        return;
    }

    for (Consultation c : consultations) {
        cout << endl;
        cout << "Patient ID: " << c.patientID << endl;
        cout << "Doctor ID:  " << c.doctorID << endl;
        cout << "Date:       " << c.date << endl;
        cout << "Time:       " << c.time << endl;
        cout << "Reason:     " << c.reason << endl;

        cout << "----------------------------------------------"
             << endl;
    }
}

void consultBooking() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==             CONSULT BOOKING              ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Book Consultation                    ==" << endl;
        cout << "== [2] View Consultations                   ==" << endl;
        cout << "== [3] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bookConsultation();
            pauseScreen();
            break;

        case 2:
            listConsultations();
            pauseScreen();
            break;

        case 3:
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 3);
}

void bookSurgery() {
    Surgery s;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==             SURGERY BOOKING              ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> s.patientID;

    if (findPatient(s.patientID) == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    cout << "Doctor ID: ";
    cin >> s.doctorID;

    if (findDoctor(s.doctorID) == -1) {
        cout << endl;
        cout << "Doctor not found." << endl;
        return;
    }

    cin.ignore();

    cout << "Surgery Name: ";
    getline(cin, s.surgeryName);

    cout << "Date: ";
    cin >> s.date;

    cout << "Time: ";
    cin >> s.time;

    surgeries.push_back(s);
    cout << endl;
    cout << "Surgery booked successfully!" << endl;
}

void listSurgeries() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==               SURGERIES                  ==" << endl;
    cout << "==============================================" << endl;

    if (surgeries.empty()) {

        cout << "No surgeries booked." << endl;
        return;
    }

    for (Surgery s : surgeries) {
        cout << endl;
        cout << "Patient ID:  " << s.patientID << endl;
        cout << "Doctor ID:   " << s.doctorID << endl;
        cout << "Surgery:     " << s.surgeryName << endl;
        cout << "Date:        " << s.date << endl;
        cout << "Time:        " << s.time << endl;

        cout << "----------------------------------------------"
             << endl;
    }
}

void surgeryBooking() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==             SURGERY BOOKING              ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Book Surgery                         ==" << endl;
        cout << "== [2] View Surgeries                       ==" << endl;
        cout << "== [3] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bookSurgery();
            pauseScreen();
            break;

        case 2:
            listSurgeries();
            pauseScreen();
            break;

        case 3:
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 3);
}

void addDoctor() {
    Doctor d;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==               ADD DOCTOR                 ==" << endl;
    cout << "==============================================" << endl;

    cout << "Doctor ID: ";
    cin >> d.doctorID;

    if (findDoctor(d.doctorID) != -1) {
        cout << endl;
        cout << "Doctor ID already exists." << endl;
        return;
    }

    cin.ignore();

    cout << "Doctor Name: ";
    getline(cin, d.name);

    cout << "Specialization: ";
    getline(cin, d.specialization);

    doctors.push_back(d);

    cout << endl;
    cout << "Doctor added successfully!" << endl;
}

void listDoctors() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==                DOCTORS                   ==" << endl;
    cout << "==============================================" << endl;

    if (doctors.empty()) {

        cout << "No doctors registered." << endl;
        return;
    }

    for (Doctor d : doctors) {
        cout << endl;
        cout << "Doctor ID:       " << d.doctorID << endl;
        cout << "Name:            " << d.name << endl;
        cout << "Specialization:  " << d.specialization << endl;

        cout << "----------------------------------------------"
             << endl;
    }
}

void doctorManagement() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==            DOCTOR MANAGEMENT             ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Add Doctor                           ==" << endl;
        cout << "== [2] List Doctors                         ==" << endl;
        cout << "== [3] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addDoctor();
            pauseScreen();
            break;

        case 2:
            listDoctors();
            pauseScreen();
            break;

        case 3:
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 3);
}

void addRoom() {
    Room r;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==                 ADD ROOM                 ==" << endl;
    cout << "==============================================" << endl;

    cout << "Room Number: ";
    cin >> r.roomNumber;

    cout << "Number of Beds: ";
    cin >> r.totalBeds;

    r.occupiedBeds = 0;

    rooms.push_back(r);

    cout << endl;
    cout << "Room added successfully!" << endl;
}

void listRooms() {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==             ROOM / BED STATUS            ==" << endl;
    cout << "==============================================" << endl;

    if (rooms.empty()) {

        cout << "No rooms registered." << endl;
        return;
    }

    cout << left
         << setw(15) << "Room"
         << setw(15) << "Total Beds"
         << setw(15) << "Occupied"
         << setw(15) << "Available"
         << endl;

    cout << "------------------------------------------------------------"
         << endl;

    for (Room r : rooms) {

        cout << left
             << setw(15) << r.roomNumber
             << setw(15) << r.totalBeds
             << setw(15) << r.occupiedBeds
             << setw(15) << r.totalBeds - r.occupiedBeds
             << endl;
    }
}

void roomManagement() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==            ROOM/BED MANAGEMENT           ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Add Room                             ==" << endl;
        cout << "== [2] List Rooms                           ==" << endl;
        cout << "== [3] Back to Main Menu                    ==" << endl;
        cout << "==============================================" << endl;

        cout << "\nEnter your number of choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addRoom();
            pauseScreen();
            break;

        case 2:
            listRooms();
            pauseScreen();
            break;

        case 3:
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 3);
}

void dischargePatient() {
    string id;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==            DISCHARGE PATIENT             ==" << endl;
    cout << "==============================================" << endl;

    cout << "Patient ID: ";
    cin >> id;

    int index = findPatient(id);

    if(index == -1) {
        cout << endl;
        cout << "Patient not found." << endl;
        return;
    }

    if(!patients[index].admitted) {
        cout << endl;
        cout << "Patient is already discharged." << endl;
        return;
    }

    patients[index].admitted = false;
    cout << endl;
    cout << "Patient "
         << patients[index].firstName
         << " "
         << patients[index].lastName
         << " has been discharged." << endl;
}

void reports() {
    int admitted = 0;
    int discharged = 0;

    for(Patient p : patients) {

        if (p.admitted) {
            admitted++;
        }
        else {
            discharged++;
        }
    }
    cout << endl;
    cout << "==============================================" << endl;
    cout << "==                REPORTS                   ==" << endl;
    cout << "==============================================" << endl;

    cout << "Total Patients:       " << patients.size() << endl;
    cout << "Admitted Patients:    " << admitted << endl;
    cout << "Discharged Patients:  " << discharged << endl;
    cout << "Total Doctors:        " << doctors.size() << endl;
    cout << "Consultations:        " << consultations.size() << endl;
    cout << "Surgeries:            " << surgeries.size() << endl;
    cout << "Rooms:                " << rooms.size() << endl;
}

int main() {
    int choice;

    do {

        clearScreen();

        cout << "==============================================" << endl;
        cout << "==       HOSPITAL MANAGEMENT SYSTEM         ==" << endl;
        cout << "==============================================" << endl;
        cout << "== [1] Patient Management                   ==" << endl;
        cout << "== [2] Patient Charting                     ==" << endl;
        cout << "== [3] Consult Booking                      ==" << endl;
        cout << "== [4] Surgery Booking                      ==" << endl;
        cout << "== [5] Doctor Management                    ==" << endl;
        cout << "== [6] Room/Bed Management                  ==" << endl;
        cout << "== [7] Discharge Patient                    ==" << endl;
        cout << "== [8] Reports                              ==" << endl;
        cout << "== [9] Exit                                 ==" << endl;
        cout << "==============================================" << endl;

        cout << endl;
        cout << "Enter your number of choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            patientManagement();
            break;

        case 2:
            patientCharting();
            break;

        case 3:
            consultBooking();
            break;

        case 4:
            surgeryBooking();
            break;

        case 5:
            doctorManagement();
            break;

        case 6:
            roomManagement();
            break;

        case 7:
            dischargePatient();
            pauseScreen();
            break;

        case 8:
            reports();
            pauseScreen();
            break;

        case 9:
            cout << endl;
            cout << "Exiting Hospital Management System..." << endl;
            break;

        default:
            cout << endl;
            cout << "Invalid choice!" << endl;
            pauseScreen();
        }

    } while (choice != 9);

    cout << endl;
    cout << "Thank you for using the Hospital Management System." << endl;

    return 0;
}