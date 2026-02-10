
#include <iostream>
#include <fstream> //for file Handling
#include <string>
#include <regex>   //for validation
#include <limits>  //for input buffer control
#include <cctype>  // for tolower ()
#include <cstdlib> // for exit()
using namespace std;
struct patient_Auth
{ //  This structure  store only login/authorization data used for registration and login
    string username;
    string password;
};
struct patient_data
{ //  This structure  stores only patient personnal details
    string name, father_name, age, phone, gender;
};
bool is_valid_Name(const string &s)
{                                                 // check whether name contains only letters and spaces
    return regex_match(s, regex("^[A-Za-z ]+$")); // only letters (A-Z,a-z)and spaces are allowed
}
bool is_valid_Phone(const string &s)
{
    return regex_match(s, regex("^[0-9]{10}$")); // only digit allowed,exactly 10 digits
}
bool is_valid_Gender(string s)
{
    for (char &c : s)
        c = tolower(c);                                                            // convert input to  lowercase
    return (s == "m" || s == "male" || s == "f" || s == "female" || s == "other"); // Accepts only Male,female,or other
}
bool is_Valid_Age(const string &s)
{
    if (!regex_match(s, regex("^[0-9]+$")))
        return false; // letter not allowed
    try
    {
        int age = stoi(s); // convert  string to int
        return (age > 0 && age <= 120);
    }
    catch (const std::exception &e)
    { // if conversion fails (number too big),return false
        return false;
    }
}
bool is_Valid_username(const string &s)
{
    return regex_match(s, regex("^[A-Za-z0-9]{3,12}$")); // letters and digits only,atleast 3 characters and atmost 12 character
}
bool is_Valid_password(const string &s)
{
    return regex_match(s, regex("^[A-Za-z0-9]{6,12}$")); // letter  and digits only,atleast 6 characters  and atmost 12 characters
}
bool register_patient()
{
    patient_Auth p; // object for authorized patient data
    string input;
    cout << "\n\t+----------------------------------------+" << endl;
    cout << "\t|              PATIENT REGISTRATION        |" << endl;
    cout << "\t+-------------------------------------------+" << endl;
    while (true)
    {
        cout << "\t Enter Username:" << endl;
        getline(cin, input);
        if (is_Valid_username(input))
        {
            p.username = input;
            break;
        }
        cout << "\t Invalid Username! Must be 3-12 letters/digits" << endl;
    }
    while (true)
    {
        cout << "\t Enter Password:" << endl;
        getline(cin, input);
        if (is_Valid_password(input))
        {
            p.password = input;
            break;
        }
        cout << "\t Invalid password! Must be 6-12 letters/digits" << endl;
    }
    ofstream file("patients_authorization.txt", ios::app);
    if (!file)
    {
        cout << "\t Error opening file!" << endl;
        return false;
    } // stores data in readable format
    file << p.username << " " << p.password << endl;
    file.close();
    cout << "\t Patient registered Sucessfully" << endl;
    return true;
}
bool Patient_data(const string &username)
{
    // Patient Data  function  this run after successful login   and  username is passed by reference  for linking data
    patient_data p;
    string input;
    cout << "\n\t+----------------------------------------" << endl;
    cout << "\t|           ENTER  PATIENT DETAILS         " << endl;
    cout << "\t+------------------------------------------" << endl;
    while (true)
    {
        cout << "\t Enter Name:" << endl;
        getline(cin, input);
        if (is_valid_Name(input))
        {
            p.name = input;
            break;
        }
        cout << "\t Invalid Name!" << endl;
    }
    while (true)
    {
        cout << "\t Enter Father Name:" << endl;
        getline(cin, input);
        if (is_valid_Name(input))
        {
            p.father_name = input;
            break;
        }
        cout << "\t Invalid Name!" << endl;
    }
    while (true)
    {
        cout << "\t Enter Age:" << endl;
        getline(cin, input);
        if (is_Valid_Age(input))
        {
            p.age = input;
            break;
        }
        cout << "\t Invalid Age!" << endl;
    }
    while (true)
    {
        cout << "\t Enter phone number(10 digits):" << endl;
        getline(cin, input);
        if (is_valid_Phone(input))
        {
            p.phone = input;
            break;
        }
        cout << "\t Invalid Phone Number! " << endl;
    }
    while (true)
    {
        cout << "\t Enter Gender(m/f/other):" << endl;
        getline(cin, input);
        if (is_valid_Gender(input))
        {
            p.gender = input;
            break;
        }
        cout << "\t Invalid Gender!" << endl;
    }
    ofstream file("Patients_Data.txt", ios::app);
    if (!file)
    {
        cout << "\t Error Opening File!" << endl;
        return false;
    } // save patient  personal data
    file << "Username = " << username << endl;
    file << "Name = " << p.name << endl;
    file << "Father Name = " << p.father_name << endl;
    file << "Age = " << p.age << endl;
    file << "Phone = " << p.phone << endl;
    file << "Gender = " << p.gender << endl;
    file << "-------------------------------------" << endl;
    file.close();
    cout << "\t Patient details saved successfully!" << endl;
    return true;
}
bool patient_login(string &loggedpatient)
{
    // ask user for their login credentials
    string inputusername, inputpassword;
    cout << "\t Enter Username:";
    getline(cin, inputusername);
    cout << "\t Enter Password:";
    getline(cin, inputpassword);
    // open the file where username or password are stored
    ifstream file("patients_authorization.txt");
    if (!file)
    {
        cout << "\t Error opening File!" << endl;
        return false;
    }
    string fileusername, filepassword;
    bool loginsuccess = false; // it is flag did the user enter correct login info
    // read each line and split usernme and password
    while (file >> fileusername >> filepassword)
    {
        if (fileusername == inputusername && filepassword == inputpassword)
        {
            loginsuccess = true;
            loggedpatient = fileusername; // found a match ,login is successful
            break;                        // exit the loop as we found the user
        }
    }
    file.close();
    // check if login was successful and display appropraite message
    if (loginsuccess)
    {
        cout << "\t Login Successfull! Welcome" << loggedpatient << endl;
        return true; // return true to indicate successful login
    }
    else
    {
        cout << "\t Login Failed! Invalid username or password." << endl;
        return false; // return false if login failed
    }
}
bool book_appointment(const string &username)
{
    string doctor, date, time, reason;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t|               BOOK APPOINTMENT        |" << endl;
    cout << "\t+---------------------------------------+" << endl;
    cout << "\t Enter Doctor Name:";
    getline(cin, doctor);
    cout << "\t Enter Date(DD/MM/YY):";
    getline(cin, date);
    cout << "\t Enter Time(HH:MM):";
    getline(cin, time);
    cout << "\t Enter Reason for appointment:";
    getline(cin, reason);
    ofstream file("Appointment.txt", ios::app);
    if (!file)
    {
        cout << "\t Error Opening file!" << endl;
        return false;
    }
    // store in multiple lines
    file << " +-----------------------Appointment list--------+" << endl;
    file << "Username = " << username << endl;
    file << "Doctor = " << doctor << endl;
    file << "Date = " << date << endl;
    file << "Time = " << time << endl;
    file << "Reason = " << reason << endl;
    file << "Status = Pending" << endl;
    file << "+------------------------------------------------+" << endl;
    file.close();
    cout << "\t Appointment request saved successfully!Waiting for doctor approval." << endl;
    return true;
}
bool cancel_appointment()
{
    string uname, doctor;
    cout << "\t Enter your Username:";
    getline(cin, uname);
    cout << "\t Enter Doctor Name:";
    getline(cin, doctor);
    ifstream file("Appointment.txt");
    if (!file)
    {
        cout << "\t Error Opening file!" << endl;
        return false;
    }
    string line;
    const int maxAppt = 100; // max 100 appointment
    string appt[maxAppt][6]; // username,doctor,date,time,reason,status
    int count = 0;
    // read appointments into 2d array
    while (getline(file, line))
    {
        if (line.find("Username = ") != string::npos)
            appt[count][0] = line.substr(11); // usename
        else if (line.find("Doctor = ") != string::npos)
            appt[count][1] = line.substr(9); // doctor
        else if (line.find("Date = ") != string::npos)
            appt[count][2] = line.substr(7); // date
        else if (line.find("Time = ") != string::npos)
            appt[count][3] = line.substr(7); // time
        else if (line.find("Reason = ") != string::npos)
            appt[count][4] = line.substr(9); // reason
        else if (line.find("Status = ") != string::npos)
        {
            appt[count][5] = line.substr(9); // status
            count++;                         // finished reding one appointment
        }
    }
    file.close();
    bool found = false;
    // search for appointment and cancel
    for (int i = 0; i < count; i++)
    {
        if (appt[i][0] == uname && appt[i][1] == doctor && (appt[i][5] == "Pending" || appt[i][5] == "Approved"))
        {
            appt[i][5] = "Cancelled";
            found = true;
            break;
        }
    }
    // write back to file in same multi_line format
    ofstream out("Appointment.txt");
    if (!out)
    {
        cout << "\t Error opening file!" << endl;
        return false;
    }
    for (int i = 0; i < count; i++)
    {
        out << "+------------------------Appointment list---------------+" << endl;
        out << "Username = " << appt[i][0] << endl;
        out << "Doctor = " << appt[i][1] << endl;
        out << "Date = " << appt[i][2] << endl;
        out << "Time = " << appt[i][3] << endl;
        out << "Reason = " << appt[i][4] << endl;
        out << "Status = " << appt[i][5] << endl;
        out << "+-------------------------------------------------------+" << endl;
    }
    out.close();
    if (found)
        cout << "\t Appointment cancelled successfully!" << endl;
    else
        cout << "\t No pending appointment found." << endl;
    return found;
}
bool reschedule_appointment()
{
    string appt[100][6];            // rows=appointment (100) or column =fields(username,date,etc)(6)
    int count = 0;                  // keep track that how many appointment are read
    ifstream in("Appointment.txt"); // open apointment file for reading
    // if fails to open file
    if (!in)
    {
        cout << "\t Error in opening file!" << endl;
        return false;
    }
    string line;
    // readnfile until eof
    while (getline(in, line))
    {
        /*  line.find ("username = ") searcches the string if found return index(0 or more)
        if not found return string ::npos
        npos means not found*/
        if (line.find("Username = ") != string::npos)
        {
            // substr(11) extrct text after "Username = " as username = has 11character
            appt[count][0] = line.substr(11); // store username
            // read next line (doctor)
            getline(in, line);
            appt[count][1] = line.substr(9);
            getline(in, line);
            appt[count][2] = line.substr(7);
            getline(in, line);
            appt[count][3] = line.substr(7);
            getline(in, line);
            appt[count][4] = line.substr(9);
            getline(in, line);
            appt[count][5] = line.substr(9);
            count++;
        }
    }
    in.close();
    string uname, newdate, newwtime;
    // ask user which appointment to rescheduled
    cout << "\t Enter username:";
    getline(cin, uname);
    bool found = false; // flag to check if appointment exist
    // loop through all stored appointment
    for (int i = 0; i < count; i++)
    {
        // match username and appointment must be pending or approved
        if (appt[i][0] == uname && (appt[i][5] == "Pending" || appt[i][5] == "Approved"))
        {
            // ask for new date and time
            cout << "\t Enter New Date:";
            getline(cin, newdate);
            cout << "\t Enter  New Time:";
            getline(cin, newwtime);
            // appdate the appointment values
            appt[i][2] = newdate;
            appt[i][3] = newwtime;
            // status is set to pending again because the approve rescheduked appointment
            appt[i][5] = "Pending";
            found = true; // appointment found and updated
            break;        // stop searching
        }
    }
    // open file and this time for writing (overwriting)
    ofstream out("Appointment.txt");
    for (int i = 0; i < count; i++)
    {
        out << "+------------------------Appointment list---------------+" << endl;
        out << "Username = " << appt[i][0] << endl;
        out << "Doctor = " << appt[i][1] << endl;
        out << "Date = " << appt[i][2] << endl;
        out << "Time = " << appt[i][3] << endl;
        out << "Reason = " << appt[i][4] << endl;
        out << "Status = " << appt[i][5] << endl;
        out << "+-------------------------------------------------------+" << endl;
    }
    out.close();
    if (found)
        cout << "\t Appointment reschedule  successfully!" << endl;
    else
        cout << "\t No appointment found   to reschedule." << endl;
    return found;
}
bool logout()
{
    cout << "\t+-----------------------------------------------------+" << endl;
    cout << "\t|                  LOGGING OUT                         |" << endl;
    cout << "\t+-----------------------------------------------------+" << endl;
    cout << "\t You have been logged out successfully!" << endl;
    return true; // indicate logout is done
}
bool patient_menu(const string &username)
{
    string input;
    int choice;
    while (true)
    {
        cout << "\t +------------------------------------------------+" << endl;
        cout << "\t|             PATIENT DASHBOARD                   |" << endl;
        cout << "\t+-------------------------------------------------+" << endl;
        cout << "\t|             1. Book Appointment                 |" << endl;
        cout << "\t|             2.Cancel Appointment                |" << endl;
        cout << "\t|             3.Reschedule Appointment            |" << endl;
        cout << "\t|             4.Give personnal  details        |" << endl;
        cout << "\t|             5.       |" << endl;
        cout << "\t|             6.Logout                            |" << endl;
        cout << "\t|+------------------------------------------------|" << endl;
        cout << "\t Enter your choice (1-4): ";
        getline(cin, input);
        // validate the input must be single digit 1-4
        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0] - '0';
            if (choice >= 1 && choice <= 4)
            {
                // valid choice
            }
            else
            {
                cout << "\t Invalid Choice! Please enter 1-4." << endl;
                continue;
            }
        }
        else
        {
            cout << "\t Invalid Choice! Please enter 1-4." << endl;
            continue;
        }
        // execut menu option
        switch (choice)
        {
        case 1:
            book_appointment(username);
            break;
        case 2:
            cancel_appointment();
            break;
        case 3:
            reschedule_appointment();
            break;
        case 4:
            logout();
            return true;
            break;
        default:
            cout << "\t Invalid Choice! Please enter 1-4." << endl;
            break;
        }
    }
}
// structure to store doctor login crediential
struct doctor_auth
{
    string username;
    string password;
};
struct doctor_data
{
    string name, father_name, specialization, phone;
};
bool is_valid_doctor_username(const string &s)
{
    // letters and digits only,3-12 characters
    return regex_match(s, regex("^[A-Za-z0-9]{3,12}$"));
}
bool is_Valid_doctor_password(const string &s)
{
    return regex_match(s, regex("^[A-Za-z0-9]{6,12}$")); // letter  and digits only,atleast 6 characters  and atmost 12 characters
}
bool is_valid_doctor_Name(const string &s)
{                                                 // check whether name contains only letters and spaces
    return regex_match(s, regex("^[A-Za-z ]+$")); // only letters (A-Z,a-z)and spaces are allowed
}
bool is_valid_doctor_Phone(const string &s)
{
    return regex_match(s, regex("^[0-9]{10}$")); // only digit allowed,exactly 10 digits
}
bool is_valid_doctor_specialization(const string &s)
{
    return regex_match(s, regex("^[A-Za-z ]+$")); // only letters and spaces are allowed
}
bool is_valid_availibility(const string &s)
{
    // accepts formats like 9am-5pm or 09:00-16:00,simple check
    return regex_match(s, regex("^[0-9]{1,2}(:[0-9]{2}?(am|pm)?-[0-9]{1,2}(:[0-9]{2}?(am|pm)?$"));
}
bool register_doctor()
{
    doctor_auth d;
    string input;
    cout << "\t+--------------------------------------------------------+" << endl;
    cout << "\t|                   DOCTOR REGISTRATION                  |" << endl;
    cout << "\t+--------------------------------------------------------+" << endl;
    // loop until valid username is entered
    while (true)
    {
        cout << "\t Enter Username:";
        getline(cin, input);
        if (is_valid_doctor_username(input))
        {
            d.username = input;
            break;
        }
        cout << "\t Invalid Username! Must be 3-12 letters/digits" << endl;
    }
    while (true)
    {
        cout << "\t Enter Password:" << endl;
        getline(cin, input);
        if (is_Valid_doctor_password(input))
        {
            d.password = input;
            break;
        }
        cout << "\t Invalid password! Must be 6-12 letters/digits" << endl;
    }
    ofstream file("Doctor_authorization.txt", ios::app);
    if (!file)
    {
        cout << "\t Error opening file!" << endl;
        return false;
    } // stores data in readable format
    file << d.username << " " << d.password << endl;
    file.close();
    cout << "\t Doctor registered Sucessfully" << endl;
    return true;
}
bool doctor_login(string &loggedDoctor)
{
    // ask user for their login credentials
    string inputusername, inputpassword;
    cout << "\t Enter    Doctor Username:";
    getline(cin, inputusername);
    cout << "\t Enter  Doctor Password:";
    getline(cin, inputpassword);
    // open the file where username or password are stored
    ifstream file("Doctor_authorization.txt");
    if (!file)
    {
        cout << "\t Error opening File!" << endl;
        return false;
    }
    string fileusername, filepassword;
    bool loginsuccess = false; // it is flag did the user enter correct login info
    // read each line and split usernme and password
    while (file >> fileusername >> filepassword)
    {
        if (fileusername == inputusername && filepassword == inputpassword)
        {
            loginsuccess = true; // found a match ,login is successful
            loggedDoctor = fileusername;
            break; // exit the loop as we found the user
        }
    }
    file.close();
    // check if login was successful and display appropraite message
    if (loginsuccess)
    {
        cout << "\t Login Successfull! Welcome DR." << loggedDoctor << endl;
        return true; // return true to indicate successful login
    }
    else
    {
        cout << "\t Login Failed! Invalid username or password." << endl;
        return false; // return false if login failed
    }
}

bool add_doctor_data(const string &username)
{
    // doctor Data  function  this run after successful login   and  username is passed by reference  for linking data
    doctor_data d;
    string input, weekdays, weekend;
    cout << "\n\t+----------------------------------------" << endl;
    cout << "\t|           ENTER  DOCTOR DETAILS         " << endl;
    cout << "\t+------------------------------------------" << endl;
    while (true)
    {
        cout << "\t Enter Name:" << endl;
        getline(cin, input);
        if (is_valid_doctor_Name(input))
        {
            d.name = input;
            break;
        }
        cout << "\t Invalid Name!" << endl;
    }
    while (true)
    {
        cout << "\t Enter Father Name:" << endl;
        getline(cin, input);
        if (is_valid_doctor_Name(input))
        {
            d.father_name = input;
            break;
        }
        cout << "\t Invalid Name!" << endl;
    }
    while (true)
    {
        cout << "\t Enter Specialization:" << endl;
        getline(cin, input);
        if (is_valid_doctor_specialization(input))
        {
            d.specialization = input;
            break;
        }
        cout << "\t Invalid Specialization!" << endl;
    }
    while (true)
    {
        cout << "\t Enter phone number(10 digits):" << endl;
        getline(cin, input);
        if (is_valid_doctor_Phone(input))
        {
            d.phone = input;
            break;
        }
        cout << "\t Invalid Phone Number! " << endl;
    }
    // Weekdays availability with validation
    while (true)
    {
        cout << "\t Enter Weekdays Availability (e.g., 9am-5pm or 09:00-17:00):" << endl;
        getline(cin, weekdays);
        if (is_valid_availibility(weekdays))
        {
            break;
        }
        cout << "\t Invalid format! Try again." << endl;
    }
    // Weekend availability with validation
    while (true)
    {
        cout << "\t Enter Weekend Availability (e.g., 10am-2pm or 10:00-14:00):" << endl;
        getline(cin, weekend);
        if (is_valid_availibility(weekend))
        {
            break;
        }
        cout << "\t Invalid format! Try again." << endl;
    }
    ofstream file("Doctor_Data.txt", ios::app);
    if (!file)
    {
        cout << "\t Error Opening File!" << endl;
        return false;
    } // save patient  personal data
    file << "Username = " << username << endl;
    file << "Name = " << d.name << endl;
    file << "Father Name = " << d.father_name << endl;
    file << "specialization = " << d.specialization << endl;
    file << "Phone = " << d.phone << endl;
    file << "Weekdays Availability = " << weekdays << endl;
    file << "Weekend Availability = " << weekend << endl;
    file << "-------------------------------------" << endl;
    file.close();
    cout << "\t Doctor details saved successfully!" << endl;
    return true;
}
bool doctor_approval(string doctorName)
{
    string appt[100][6];             // rows=appointment (100) or column =fields(username,date,etc)(6)
    int count = 0;                   // keep track that how many appointment are read
    ifstream fin("Appointment.txt"); // open apointment file for reading
    // if fails to open file
    if (!fin)
    {
        cout << "\t Error in opening file!" << endl;
        return false;
    }
    string line;
    // readnfile until eof
    while (getline(fin, line))
    {
        /*  line.find ("username = ") searcches the string if found return index(0 or more)
        if not found return string ::npos
        npos means not found*/
        if (line.find("Username = ") != string::npos)
        {
            // substr(11) extrct text after "Username = " as username = has 11character
            appt[count][0] = line.substr(11); // store username
            // read next line (doctor)
            getline(fin, line);
            appt[count][1] = line.substr(9);
            getline(fin, line);
            appt[count][2] = line.substr(7);
            getline(fin, line);
            appt[count][3] = line.substr(7);
            getline(fin, line);
            appt[count][4] = line.substr(9);
            getline(fin, line);
            appt[count][5] = line.substr(9);
            count++;
        }
    }
    fin.close();
    bool found = false;
    // doctor approval process
    for (int i = 0; i < count; i++)
    {
        if (appt[i][1] == doctorName && appt[i][5] == "Pending")
        {
            found = true;
            cout << "+------------------------Appointment  details---------------+" << endl;
            cout << "Username = " << appt[i][0] << endl;
            cout << "Date = " << appt[i][2] << endl;
            cout << "Time = " << appt[i][3] << endl;
            cout << "Reason = " << appt[i][4] << endl;
            string choice;
            // input validation loop
            while (true)
            {
                cout << "\t Enter 1 to approve or 2 to reject:";
                getline(cin, choice);
                if (choice == "1")
                {
                    appt[i][5] = "Approved";
                    cout << "\t Appointment approved" << endl;
                    break;
                }
                else if (choice == "2")
                {
                    appt[i][5] = "Rejected";
                    cout << "\t Appointment rejected:" << endl;
                    break;
                }
                else
                {
                    // if inpput is not 1 or 2
                    cout << "\t Invalid input! Please enter 1 or 2 only" << endl;
                }
            }
        }
    }
    if (!found)
    {
        cout << "\t No pending appointment found." << endl;
    }
    ofstream fout("Appointment.txt");
    for (int i = 0; i < count; i++)
    {
        fout << "+------------------------Appointment list---------------+" << endl;
        fout << "Username = " << appt[i][0] << endl;
        fout << "Doctor = " << appt[i][1] << endl;
        fout << "Date = " << appt[i][2] << endl;
        fout << "Time = " << appt[i][3] << endl;
        fout << "Reason = " << appt[i][4] << endl;
        fout << "Status = " << appt[i][5] << endl;
        fout << "+-------------------------------------------------------+" << endl;
    }
    fout.close();
    return found;
}
bool doctor_menu(const string &doctorUsername)
{
    string input;
    int choice;
    while (true)
    {
        cout << "\t +------------------------------------------------+" << endl;
        cout << "\t|             DOCTOR DASHBOARD                    |" << endl;
        cout << "\t+-------------------------------------------------+" << endl;
        cout << "\t|             1. ADD/UPDATE DOCTOR DETAILS        |" << endl;
        cout << "\t|             2.View or approve Appointment       |" << endl;
        cout << "\t|             3.Logout                            |" << endl;
        cout << "\t|+------------------------------------------------|" << endl;
        cout << "\t Enter your choice (1-3): ";
        getline(cin, input);
        // validate the input must be single digit 1-4
        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0] - '0';
            if (choice < 1 || choice > 3)
            {
                cout << "\t Invalid Choice! Please enter 1-3 only." << endl;
                continue;
            }
        }
        else
        { // handles input like aqwsedrftgyhuj,####@@@
            cout << "\t Invalid Choice! Please enter 1-3." << endl;
            continue;
        }
        // execute menu option
        switch (choice)
        {
        case 1:
            add_doctor_data(doctorUsername);
            break;
        case 2:
            doctor_approval(doctorUsername);
            break;
        case 3:
            logout();
            return true;
        default:
            cout << "\t Invalid Choice! Please enter 1-4." << endl;
        }
    }
}
bool view_patient_data()
{
    ifstream file("Patients_Data.txt");
    if (!file)
    {
        cout << "\t Error opening Patient data.txt file!" << endl;
        return false;
    }
    string line;
    bool isempty = true; // flag to check if file has data
    cout << "\t +-------------------------------------------------+" << endl;
    cout << "\t |               Patient Data list                 |" << endl;
    cout << "\t +-------------------------------------------------+" << endl;
    while (getline(file, line))
    {
        isempty = false;               // file has data
        cout << "\t " << line << endl; // display exactly what is stored
    }
    file.close();
    if (isempty)
    {
        cout << "\t No patient records found!" << endl;
    }
    return true;
}
bool view_doctor_data()
{
    ifstream file("Doctor_Data.txt");
    if (!file)
    {
        cout << "\t Error opening file!" << endl;
    }

    string line;
    bool doctorFound = false; // flag to know when a doctor's info starts
    cout << "\n\t+------------------- Doctor List -------------------+" << endl;

    while (getline(file, line))
    {
        // Skip father name line
        if (line.find("Father Name = ") != string::npos)
            continue;

        // If separator line, treat as end of one doctor's info
        if (line.find("-------------------------------------") != string::npos)
        {
            cout << "+---------------------------------------------------+" << endl;
            cout << "\nPress any key for next doctor or ESC to go back..." << endl;
            char ch;
            std::cin.get(ch); // wait for keypress
            if (ch == 27)
            { // ESC key ASCII = 27
                break;
            }
            continue; // go to next doctor
        }

        // Print doctor's data
        cout << line << endl;
        doctorFound = true;
    }

    file.close();
    return doctorFound;
}
bool admin_menu(const string &doctorUsername)
{
    string input;
    int choice;
    while (true)
    {
        cout << "\t +------------------------------------------------+" << endl;
        cout << "\t|             ADMIN  DASHBOARD                    |" << endl;
        cout << "\t+-------------------------------------------------+" << endl;
        cout << "\t|             1. VIEW   PATIENT   DETAILS         |" << endl;
        cout << "\t|             2.View   Doctor data                |" << endl;
        cout << "\t|             3.Register  new doctor              |" << endl;
        cout << "\t|             4.Logout                            |" << endl;
        cout << "\t|+------------------------------------------------|" << endl;
        cout << "\t Enter your choice (1-4): ";
        getline(cin, input);
        // validate the input must be single digit 1-4
        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0] - '0';
            if (choice < 1 || choice > 4)
            {
                cout << "\t Invalid Choice! Please enter 1-4 only." << endl;
                continue;
            }
        }
        else
        { // handles input like aqwsedrftgyhuj,####@@@
            cout << "\t Invalid Choice! Please enter 1-4." << endl;
            continue;
        }
        // execute menu option
        switch (choice)
        {
        case 1:
            view_patient_data();
            break;
        case 2:
            view_doctor_data();
            break;
        case 3:
            register_doctor();
            break;
        case 4:
            logout();
            return true;
        default:
            cout << "\t Invalid Choice! Please enter 1-4." << endl;
        }
    }
}
bool admin_login()
{
    const string adminpassword = "admin123"; // adminpassword set
    string password;
    int attempts = 3; // total attempt allowed
    while (attempts > 0)
    {
        cout << "\t Enter Admin Password:";
        getline(cin, password);
        if (password == adminpassword)
        {
            cout << "\t Login successfully ! welcome admin." << endl;
            return true;
        }
        else
        {
            attempts--;
            if (attempts > 0)
                cout << "\t Invalid password!" << attempts << "attempt(s) remaining." << endl;
            else
            {
                cout << "\t Too many failed attempts!Access denied." << endl;
                exit(0); // exit the program after the 3 failed attempts
            }
        }
    }
    return false;
}
int main()
{
    string username; // store logged-in patient or doctor username
    while (true)
    {
        cout << "\n\t+--------------------------+" << endl;
        cout << "\t|      HOSPITAL SYSTEM     |" << endl;
        cout << "\t+--------------------------+" << endl;
        cout << "\t| 1. Admin Login           |" << endl;
        cout << "\t| 2. Patient Login         |" << endl;
        cout << "\t| 3. Doctor Login          |" << endl;
        cout << "\t| 4. Patient Registration  |" << endl;
        cout << "\t| 5. Exit                  |" << endl;
        cout << "\t+--------------------------+" << endl;
        cout << "\t Enter your choice (1-5): ";

        string input;
        getline(cin, input);
        int choice;

        // Validate input
        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0] - '0';
        }
        else
        {
            cout << "\t Invalid choice! Please enter 1-4." << endl;
            continue;
        }

        switch (choice)
        {
        case 1: // Admin Login
            if (admin_login())
            {
                admin_menu(""); // call admin menu after successful login
            }
            break;

        case 2: // Patient Login
            if (patient_login(username))
            {                           // username is returned via reference
                patient_menu(username); // directly call patient menu
            }
            break;

        case 3: // Doctor Login
            if (doctor_login(username))
            {                          // username is returned via reference
                doctor_menu(username); // directly call doctor menu
            }
            break;
        case 4:
            register_patient();
            break;
        case 5: // Exit
            cout << "\t Exiting program. Goodbye!" << endl;
            exit(0);

        default:
            cout << "\t Invalid choice! Please enter 1-4." << endl;
        }
    }

    return 0;
}
