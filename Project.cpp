#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Doctor {
public:
    string name;
    string specialization;
    string timing;

    Doctor() {}
    Doctor(string n, string s, string t) : name(n), specialization(s), timing(t) {}

    void display() const {
        cout << " Name : " << name << endl;
        cout << " Specialization : " << specialization << endl;
        cout << " Timing : " << timing << endl;
    }
};

void saveDoctorToFile(const Doctor& doctor) {
    ofstream outFile("doctors.txt", ios::app);
    outFile << doctor.name << "," << doctor.specialization << "," << doctor.timing << endl;
    outFile.close();
}

void loadDoctors() {
    ifstream inFile("doctors.txt");
    string line;
    cout <<endl;
    system("cls");
    cout <<endl;
    cout << " \t\t\t\t------------------ Doctors List -------------------" << endl <<endl;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, specialization, timing;
        if (getline(ss, name, ',') && getline(ss, specialization, ',') && getline(ss, timing)) {
            Doctor doctor(name, specialization, timing);
            doctor.display();
         cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    inFile.close();
}

void addNewDoctor() {
    string name, specialization, timing;
     system("cls");
     cout <<endl;
    cout << " Enter Doctor Name : ";
    getline(cin, name);
    cout << " Enter Specialization : ";
    getline(cin, specialization);
    cout << " Enter Available Timing : ";
    getline(cin, timing);
    Doctor doctor(name, specialization, timing);
    saveDoctorToFile(doctor);
    cout << " Doctor Added " <<endl;
}

void deleteDoctorRecord() {
    string nameToDelete; 
    system("cls");
    cout <<endl;
    cout << " Enter Doctor Name to Delete : ";
    getline(cin, nameToDelete);

    ifstream inFile("doctors.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(nameToDelete) != 0) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove("doctors.txt");
    rename("temp.txt", "doctors.txt");

    if (found)
        cout << " Doctor Record deleted " <<endl;
    else
        cout << " Doctor Not found "<<endl;
}

void searchDoctorBySpecialization() {
    string spec; 
    cout << " Enter Specialization to search : ";
    getline(cin, spec);

 system("cls"); cout <<endl;cout <<endl;
    ifstream inFile("doctors.txt");
    string line;
    bool found = false;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, specialization, timing;
        getline(ss, name, ',');
        getline(ss, specialization, ',');
        getline(ss, timing);

        if (specialization == spec) {
            Doctor doctor(name, specialization, timing);
            doctor.display();
           cout << "-----------------------------------------------------------------------------------------------------------------------" << endl <<endl;
            found = true;
        }
    }
    if (!found) cout << " No Doctor found with such Specialization " <<endl;
    inFile.close();
}

class Patient {
public:
    string name;
    int age;
    string disease;

    Patient() {}
    Patient(string n, int a, string d) : name(n), age(a), disease(d) {}
 
    void display() const {
        cout << " Name : " << name << "\n Age : " << age << "\n Disease : " << disease << endl;
    }
};

void savePatientToFile(const Patient& patient) {
    ofstream outFile("patients.txt", ios::app);
    outFile << patient.name << "," << patient.age << "," << patient.disease << endl;
    outFile.close();
}

void loadPatients() {
    ifstream inFile("patients.txt");
    string line;
    system("cls");
    cout <<endl;
    cout << "\t\t\t\t-------------------- Patient Records -----------------------" << endl <<endl;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, disease;
        int age;
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, disease);
        Patient patient(name, age, disease);
        patient.display();
       cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    inFile.close();
}

void addNewPatient() {
    string name, disease;
    int age;
    system("cls");
    cout <<endl;
    cout << " Enter Patient Name : ";
    getline(cin, name);
    cout << " Enter Patient Age : ";
    cin >> age;
    cin.ignore();
    cout << " Enter Patient Disease : ";
    getline(cin, disease);
    Patient patient(name, age, disease);
    savePatientToFile(patient);
    cout << " Patient Added Successfully "<<endl;
}

void deletePatientRecord() {
    string nameToDelete;
    cout << " Enter Patient Name to delete : ";
    getline(cin, nameToDelete);

    ifstream inFile("patients.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(nameToDelete) != 0) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found)
        cout << " Patient Record Deleted "<<endl;
    else
        cout << " Patient not Found "<<endl;
}


class Appointment {
public:
    string patientName;
    string doctorName;
    string date;
    int patientAge;
    string patientDisease;

    Appointment() {}

    Appointment(string p, string d, string dt, int age, string dis)
        : patientName(p), doctorName(d), date(dt), patientAge(age), patientDisease(dis) {}

    void display() const {
    	
    	cout <<endl;

        cout << " Patient : " << patientName << "\n Age : " << patientAge
             << "\n Disease : " << patientDisease << "\n Doctor : " << doctorName
             << "\n Date : " << date << endl;
    }
};

void saveAppointmentToFile(const Appointment& appointment) {
    ofstream outFile("appointments.txt", ios::app);
    outFile << appointment.patientName << "," << appointment.doctorName << "," << appointment.date << ","
            << appointment.patientAge << "," << appointment.patientDisease << endl;
    outFile.close();
}

void getAppointment() {
    string patientName, doctorName, date, patientDisease;
    int patientAge;
    system("cls");
    cout << " Enter Patient Name : ";
    getline(cin, patientName);
    cout << " Enter Patient Age : ";
    cin >> patientAge;
    cin.ignore();
    cout << " Enter Patient Disease : ";
    getline(cin, patientDisease);
    cout << " Enter Doctor Name : ";
    getline(cin, doctorName);
    cout << " Enter Appointment Date : ";
    getline(cin, date);
    Appointment appt(patientName, doctorName, date, patientAge, patientDisease);
    saveAppointmentToFile(appt);
    cout << " Appointment Booked "<<endl;
}

void viewAppointments() {
    ifstream inFile("appointments.txt");
    string line;
    cout <<endl;
    system("cls");
    cout << "\t\t\t\t------------------ Appointments --------------------" << endl <<endl;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string pname, dname, date, disease;
        int age;
        getline(ss, pname, ',');
        getline(ss, dname, ',');
        getline(ss, date, ',');
        ss >> age;
        ss.ignore();
        getline(ss, disease);
        Appointment a(pname, dname, date, age, disease);
        a.display();
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    inFile.close();
}

void deleteAppointment() {
    string pname;
    cout << " Enter Patient Name to delete Appointment : ";
    getline(cin, pname);

    ifstream inFile("appointments.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(pname) != 0) {
            tempFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();
    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");

    if (found)
        cout << " Appointment Deleted " <<endl;
    else
        cout << " No appointment found for that patient " <<endl;
}

int main() {
    int roleChoice;

    do {
    	cout<<endl;
        cout<<"___________________________________________________________________________________________________________________________________________________________"<<endl<<endl;
        cout << "                                                      Hospital Management System " << endl;
        cout<<"                                                      ----------------------------"<<endl;
        cout<<"___________________________________________________________________________________________________________________________________________________________"<<endl <<endl;
        cout << "1:  Admin" << endl;
        cout << "2:  User" << endl;
        cout << "3:  Exit" << endl;
        cout << " Enter your Role : ";
        cin >> roleChoice;
        cin.ignore();

        if (roleChoice == 1) {  
            string password;
            cout << " Enter Password For ADMIN : ";
            getline(cin, password);

            if (password == "key") {
                int adminChoice;
                system("cls");
                do {
                	cout <<endl; 
    	cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
                    cout << " \t\t\t\t\t\t Admin Menu " << endl;
                     cout<<"\t\t\t\t\t-------------------------------"<<endl;
        cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
                    
                    cout << "1:  View Doctors " << endl;
                    cout << "2:  Add New Doctor " << endl;
                    cout << "3:  View Patients " << endl;
                    cout << "4:  Add New Patient " << endl;
                    cout << "5:  View All Appointments " << endl;
                    cout << "6:  Delete a Doctor Record " << endl;
                    cout << "7:  Delete a Patient Record " << endl;
                    cout << "8:  Delete an Appointment " << endl;
                    cout << "9:  Logout " << endl;
                    cout << "  Enter your choice : ";
                    cin >> adminChoice;
                    cin.ignore();

                switch (adminChoice) {
    case 1: loadDoctors(); break;
    case 2: addNewDoctor(); break;
    case 3: loadPatients(); break;
    case 4: addNewPatient(); break;
    case 5: viewAppointments(); break;
    case 6: deleteDoctorRecord(); break;
    case 7: deletePatientRecord(); break;
    case 8: deleteAppointment(); break;
    case 9: cout << " Logging Out " << endl; break;
    default: cout << " Invalid choice " << endl;
}
                } while (adminChoice != 9);
            } else {
                cout << " Incorrect Password Access Denied " <<endl;
            }

          } else if (roleChoice == 2) {  
            int userChoice;
            system("cls");
            do {
            	
				cout<<endl;
		cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
                cout << "  \t\t\t\t\t\t User Menu " << endl;
                   cout<<"\t\t\t\t\t-------------------------------"<<endl;
        cout<<"_______________________________________________________________________________________________________________________"<<endl<<endl;
                cout << "1: View Doctors " << endl;
                cout << "2: Get Appointment " << endl;
                cout << "3: Search Doctor by Specialization " << endl;
                cout << "4: Logout" << endl;
                cout << " Enter your Choice : ";
                cin >> userChoice;
                cin.ignore();

                switch (userChoice) {
                    case 1: loadDoctors(); break;
                    case 2: getAppointment(); break;
                    case 3: searchDoctorBySpecialization(); break;
                    case 4: cout << " Logging Out " << endl; break;
                    default: cout << " Invalid choice " << endl;
                }
            } while (userChoice != 4);;

        } else if (roleChoice == 3) {
            cout << " Exiting System " << endl;
        } else {
            cout << " Invalid Role. Try again Please " << endl;
        }

    } while (roleChoice != 3);

    return 0;
}
