
                                    /*   Information Management system
                                         Code Written By: Farhan Ishtiyak Sezar */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
//#include <string_view>
#include <regex>
#include <stdio.h>
using namespace std;
class information
{
private:
    string name, relative, city, email_id, contact_no;


public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void information::menu()
{
    StartAgain:
    int choice;
    char x;
    system("cls");



    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t| INFORMATION MANAGEMENT SYSTEM (INITIALIZING)|" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\tAdd Another Student Record (Y,N): ";
            cin >> x;
            cout<<endl<<"Press Any Key To Continue...";
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto StartAgain;
}
void information::insert() // add student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Saving Contact Information To File ----------------------------" << endl;
    cout <<   "-----------------------------------------------------------------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin.ignore();
    getline(cin,name);
    cout << "\t\t\tEnter Relative Name: ";
    cin.ignore();
    getline(cin,relative);
    cout << "\t\t\tEnter City Name: ";
    cin >> city;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    file.open("InformationRecord.txt", ios::app | ios::out);
    file << " " << name << " " <<relative << " " << city << " " << email_id << " " << contact_no << "\n";
    file.close();

}

void information::display()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout <<   "-------------------------------- Reading Contact Information From File --------------------------------" << endl;
    cout <<   "-------------------------------------------------------------------------------------------------------" << endl;
    file.open("InformationRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present..."<<endl;
        file.close();
    }
    else
    {
        file >> name >> relative >> city >> email_id >> contact_no ;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Person Number: " << total++ << endl;
            cout << "\t\t\t  Name: " << name << endl;
            cout << "\t\t\t  Relative: " << relative << endl;
            cout << "\t\t\t  City: " << city << endl;
            cout << "\t\t\t  Email Id.: " << email_id << endl;
            cout << "\t\t\t  Contact No.: " << contact_no << endl;
            file >> name >> relative >> city >> email_id >> contact_no ;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
    cout<<endl<<"Press Any Key To Continue...";
}
void information::modify() // Modify Students Details
{
    system("cls");
    fstream file, file1;
    string name1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout <<   "------------------------------------- Modify Information Of A Person  ---------------------------------" << endl;
    cout <<   "-------------------------------------------------------------------------------------------------------" << endl;
    file.open("InformationRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Name of the person which you want to Modify: ";
        cin >> name1;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> relative >> city >> email_id >> contact_no ;
        while (!file.eof())
        {
            if (name1 != name)

                file1 << " " << name << " " << relative << " " << city << " " << email_id << " " << contact_no <<  "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Relative: ";
                cin >> relative;
                cout << "\t\t\tEnter City: ";
                cin >> city;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;

                file1 << " " << name << " " << relative << " " << city << " " << email_id << " " << contact_no <<  "\n";
                found++;
            }
            file >> name >> relative >> city >> email_id >> contact_no;
            if (found == 0)
            {
                cout << "\n\n\t\t\tInformation Details Not Found...."<<endl;
            }
        }
        file1.close();
        file.close();
        remove("InformationRecord.txt");
        rename("record.txt", "InformationRecord.txt");
    }
    cout<<endl<<"Press Any Key To Continue...";
}
void information::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("InformationRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout <<  "------------------------ Displaying List of those Persons who lives in A Given City --------------------" << endl;
        cout <<  "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string city1;
         cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout <<    "------------------------ Displaying List of those Persons who lives in A Given City -------------------" << endl;
        cout <<    "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n Enter the city name of those persons Which You Want to Search: ";
        cin >> city1;
        file >> name >> relative >> city >> email_id >> contact_no;
        while (!file.eof())
        {
            if (city1 == city)
            {
                cout<<endl;
                cout << "\t\t\t  Name: " << name << endl;
                cout << "\t\t\t  Relative: " << relative << endl;
                cout << "\t\t\t  city: " << city << endl;
                cout << "\t\t\t  Email Id.: " << email_id << endl;
                cout << "\t\t\t  Contact No.: " << contact_no << endl;
                found++;
            }
            file >> name >> relative >> city >> email_id >> contact_no ;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Not Found...";
            cout<<endl;
        }
        file.close();
    }
    cout<<endl<<"Press Any Key To Continue...";
}
void information::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string name1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout <<   "---------------------------- Removing Information Of A Person From Phone Book -------------------------" << endl;
    cout <<   "-------------------------------------------------------------------------------------------------------" << endl;
    file.open("InformationRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present.."<<endl;
        file.close();
    }
    else
    {
        cout << "\nEnter Name of the person which you want Delete Data: ";
        cin >> name1;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> relative >> city >> email_id >> contact_no;
        while (!file.eof())
        {
            if (name1 != name)
            {
                file1 << " " << name << " " << relative << " " << city << " " << email_id << " " << contact_no << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tData Successfully Deleted. "<<endl<<endl;
            }
            file >> name >> relative >> city >> email_id >> contact_no;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t  Not Found....";
            cout<<endl;
        }
        file1.close();
        file.close();
        remove("InformationRecord.txt");
        rename("record.txt", "InformationRecord.txt");
        cout<<endl<<"Press Any Key To Continue...";
    }
}
main()
{
    information project;
    project.menu();
    return 0;
}
