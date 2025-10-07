#ifndef classes_hpp
#define classes_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

class student {
    string name;
    string surname;

public:
    student(string n = "", string sn = "") {
        name = n;
        surname = sn;
    }

    void add_student() {
        ofstream Data("Data.txt", ios::app);

        if (Data.is_open()) {
            cout << "\nPlease insert name of student: ";
            cin >> name;
            cout << "\nPlease insert surname of student: ";
            cin >> surname;

            Data << name << " " << surname << endl;
            Data.close();
            cout << "Save succeeded !" << endl;
        }
        else {
            cout << "Error, try again :( " << endl;
        }
    }


    void display_data() {
        ifstream Data("Data.txt", ios::in);
        if (Data.is_open()) {
            string line;
            int counter = 1;
            while (getline(Data, line)) {
                cout << counter << ". " << line << endl;
                counter++;
            }
            Data.close();
        }
        else {
            cout << "Error opening file!" << endl;
        }
    }

    void remove_data(){
    ifstream Data("Data.txt");
    string line;
    int counter = 1;
    vector<string> lines;

    cout << "Students list:\n";
    while (getline(Data, line)) {
        cout << counter << ". " << line << endl;
        lines.push_back(line);
        counter++;
    }
    Data.close();

    if (lines.empty()) {
        cout << "Data is already empty!" << endl;
        return;
    }

    int to_remove;
    cout << "Choose student's number to remove: ";
    cin >> to_remove;

    if (to_remove < 1 || to_remove > lines.size()) {
        cout << "Wrong number!" << endl;
        return;
    }
    ofstream Temp("Temp.txt");
    for (int i = 0; i < lines.size(); i++) {
        if (i != to_remove - 1)
            Temp << lines[i] << endl;
    }
    Temp.close();

    remove("Data.txt");
    rename("Temp.txt", "Data.txt");

    cout << "Removed student number: " << to_remove << "!" << endl;
}
  

~student() {};


};

#endif
