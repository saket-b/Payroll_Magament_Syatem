#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <time.h>
#include <unistd.h>

using namespace std;

void gotoxy(int x, int y)
{
    // COORD c;
    // c.X = x;
    // c.Y = y;
    // SetConsoleCursorPosition(GetStdHandle(STD_OUT_HANDLE), c);
   // std::cout << "\033[2J" << std::flush;
}
class Lines
{
public:
    void line_hor(int, int, int, char);
    void line_ver(int, int, int, char);
    void box(int, int, int, int, char);
    void clear_up();
    void clear_down();
};

class Menu
{
private:
    void edit_menu();
    void introduction();

public:
    void main_menu();
};

class Employee
{
private:
    void add_record(int, char[], char[], char[], int, int, int, char[], char, char, char, float, float);
    void modify_record(int, char[], char[], char[], char[], char, char, char, float, float);
    void delete_record(int);
    int last_code();
    int code_found(int);
    int record_no(int);
    void display_record(int);
    int valid_date(int, int, int);

    int dd, mm, yyyy, code;
    char name[26], address[31], phone[10], design[16];
    char grade, house, convense;
    float loan, basic;

public:
    void new_Employee();
    void modification();
    void deletion();
    void display();
    void list();
    void salary_slip();
};

void Menu ::main_menu()
{

    char ch;
    cout<<"hello "<<endl;
    Lines l;

    l.clear_up();
    cout<<"hello2 "<<endl;

    while (1)
    {
//system("cls");
        gotoxy(14, 3);
        cout << " Payroll Management System : ";
        l.box(27, 7, 56, 9, 218);
        l.box(27, 7, 56, 9, 218);
        l.box(27, 7, 56, 9, 218);

        gotoxy(29, 8);

        cout << "\n \tPayroll Management System \t\n";
        gotoxy(30, 11);

        cout << "\t\t 1 : New Employee" << endl;
        gotoxy(30, 12);
        cout << "\t\t 2 : Display Employee " << endl;
        gotoxy(30, 11);

        cout << "\t\t 3: List of Employee " << endl;
        gotoxy(30, 11);

        cout << "\t\t 4 : salary Slip " << endl;
        gotoxy(30, 11);

        cout << "\t\t 5 : Edit" << endl;
        gotoxy(30, 11);

        cout << "\t\t 0 : Quit" << endl;
        gotoxy(30, 11);

        cout << "\t\t Enter your Choice :";
        gotoxy(30, 11);

        ch = getchar();
        Employee E;

        if (ch == 27 || ch == '0')
            break;
        else if (ch == '1')
            E.new_Employee();
        else if (ch == '2')
            E.display();
        else if (ch == '3')
            E.list();
        else if (ch == '4')
            E.salary_slip();
        else if (ch == '5')
            edit_menu();
        else
            cout << "\t\t \n Wrong input" << endl;
    }
    l.clear_up();
}

void Menu ::edit_menu()
{
    char ch;
    Lines l;
    l.clear_down();

    while (1)
    {
        system("clear");
        l.box(38, 8, 9, 10, 218);
        l.box(38, 8, 9, 10, 218);
        l.box(38, 8, 9, 10, 218);
        gotoxy(10, 3);

        cout << "\n\t Edit Menu " << endl;
        gotoxy(30, 3);

        cout << "\t\t 1: Delete Record" << endl;
        gotoxy(30, 3);

        cout << "\t\t 2: Modify Record :" << endl;
        gotoxy(30, 3);

        cout << "\t\t 0 : Exit " << endl;
        gotoxy(30, 3);

        ch = getchar();
        Employee E;

        if (ch == 27 || ch == '0')
            break;
        else if (ch == '1')
            E.deletion();
        else if (ch == '2')
            E.modification();
    }

    l.clear_down();
}

// this function for clearing the screen

void Lines ::clear_up()
{
    // for (int i = 25; i >= 1; i--)
    // {
    //     // sleep(20);
    //     // gotoxy(i, 1);
    //     std::cout << "\033[1D";
    // }
}

void Lines::clear_down()
{
    // for (int i = 1; i <= 25; i++)
    // {
    //     sleep(20);
    //     gotoxy(1, i);
    //     std::cout << "\033[1D";
    // }
}

void Lines::line_hor(int column1, int column2, int row, char c)
{
    for (column1; column1 <= column2; column1++)
    {
        gotoxy(column1, row);
        cout << c;
    }
}

void Lines::line_ver(int row1, int row2, int column, char c)
{
    for (row1; row1 <= row2; row1++)
    {
        gotoxy(column, row1);
        cout << c;
    }
}

void Lines::box(int column1, int row1, int column2, int row2, char c)
{
    // char ch = 218;
    // char c1, c2, c3, c4;
    // char l1 = 196, l2 = 179;
    // if (c == ch)
    // {
    //     c1 = 218;
    //     c2 = 191;
    //     c3 = 192;
    //     c4 = 217;
    //     l1 = 196;
    //     l2 = 179;
    // }
    // else
    // {
    //     c1 = c;
    //     c2 = c;
    //     c3 = c;
    //     c4 = c;
    //     l1 = c;
    //     l2 = c;
    // }
    // gotoxy(column1, row1);
    // cout << c1;
    // gotoxy(column2, row1);
    // cout << c2;
    // gotoxy(column1, row2);
    // cout << c3;
    // gotoxy(column2, row2);
    // cout << c4;
    // column1++;
    // column2--;
    // line_hor(column1, column2, row1, l1);
    // line_ver(column1, column2, row2, l1);
    // column1--;
    // column2++;
    // row1++;
    // row2--;
    // line_ver(row1, row2, column1, l2);
    // line_ver(row1, row2, column2, l2);
}

// this function do add given data in Employee file

void Employee ::add_record(int ecode, char ename[26], char eaddress[31], char ephone[10], int d, int m, int y, char edesign[16], char egrade,
                           char ehouse, char econv, float eloan, float ebasic)
{
    fstream file;
    file.open("Employee.Data");

    code = ecode;
    strcpy(name, ename);
    strcpy(address, eaddress);
    strcpy(phone, ephone);

    dd = d;
    mm = m;
    yyyy = y;

    strcpy(design, edesign);
    grade = egrade;
    house = ehouse;
    convense = econv;
    loan = eloan;
    basic = ebasic;
    file.write((char *)this, sizeof(Employee));
    file.close();
}

// this function modify the given data in the Employee's file

void Employee ::modify_record(int ecode, char ename[26], char eaddress[31], char ephone[10], char edesig[16],
                              char egrade, char ehouse, char econv, float eloan, float ebasic)

{
    int recno;
    int location;
    fstream file;
    recno = record_no(ecode);

    file.open("Employee.Data", ios::out | ios::ate);

    strcpy(name, ename);
    strcpy(address, eaddress);
    strcpy(phone, ephone);
    strcpy(design, edesig);

    grade = egrade;
    house = ehouse;
    convense = econv;
    loan = eloan;
    basic = ebasic;

    grade = egrade;
    house = ehouse;
    convense = econv;
    loan = eloan;
    basic = ebasic;

    location = (recno - 1) * sizeof(Employee);

    file.seekp(location);
    file.write((char *)this, sizeof(Employee));
    file.close();
}

void Employee ::delete_record(int ecode)
{
    fstream file;
    fstream temp;

    file.open("Employee.Data", ios::in);

    temp.open("temp.Data", ios::out);
    file.seekg(0, ios::beg);

    while (!file.eof())
    {
        file.read((char *)this, sizeof(Employee));
        if (file.eof())
            break;
        if (code != ecode)
            temp.write((char *)this, sizeof(Employee));
    }

    file.close();
    temp.close();
}

// thsi function give emplyee's code
int Employee::last_code()
{
    fstream file;

    file.open("Employee.Data", ios::in);
    file.seekg(0, ios::beg);

    int count = 0;

    while (file.read((char *)this, sizeof(Employee)))
        count = code;
    file.close();
    return count;
}

// this function found code 1-> true 0->false;

int Employee ::code_found(int ecode)
{
    fstream file;
    int found = 0;
    file.open("Employee.Data", ios::in);
    file.seekg(0, ios::beg);

    while (file.read((char *)this, sizeof(Employee)))
    {
        if (code == ecode)
        {
            found = 1;
            break;
        }
    }

    file.close();
    return found;
}

// Ths function find record number of Employee

int Employee ::record_no(int ecode)
{
    fstream file;

    file.open("Employee.Data", ios::in);
    file.seekg(0, ios::beg);

    int recno = 0;

    while (file.read((char *)this, sizeof(Employee)))
    {
        recno++;
        if (code == ecode)
            break;
    }

    file.close();
    return recno;
}

// list fo Employee

void Employee ::list()
{
    system("cls");

    int row = 6, found = 0, flag = 0;
    char ch;
    gotoxy(31, 2);
    cout << "\n\t List of Employee :" << endl;
    gotoxy(30, 3);
    cout << "\n________________________________\n";
    gotoxy(1, 4);
    cout << "\nCODE      NAME        PHONE    DOJ       DESIGNATION    GRADE  SALARY\n";
    gotoxy(1, 5);
    cout << "\n_________________________________________________\n";
    fstream file;
    file.open("Employee.Data", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)this, sizeof(Employee)))
    {
        flag = 0;
        sleep(20);
        found = 1;
        gotoxy(2, row);
        cout << code;
        gotoxy(6, row);
        cout << name;
        gotoxy(31, row);
        cout << phone;
        gotoxy(40, row);
        cout << dd << "/" << mm << "/" << yyyy;
        gotoxy(52, row);
        cout << design;
        gotoxy(69, row);
        cout << grade;
        if (grade != 'E')
        {
            gotoxy(74, row);
            cout << basic;
        }
        else
        {
            gotoxy(76, row);
            cout << "-";
        }
        if (row == 23)
        {
            flag = 1;
            row = 6;
            gotoxy(1, 25);
            cout << "Press any key to continue or Press <ESC> to exit";
            ch = getchar();
            if (ch == 27)
                break;
            system("cls");
            gotoxy(31, 2);
            cout << "LIST OF EmployeeS";
            gotoxy(30, 3);
            cout << "~~~~~~~~~~~~~~~~~~~";
            gotoxy(1, 4);
            cout << "CODE NAME                     PHONE    DOJ         DESIGNATION    GRADE  SALARY";
            gotoxy(1, 5);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        }
        else
            row++;
    }
    if (!found)
    {
        gotoxy(5, 10);
        cout << "\7Records not found";
    }
    if (!flag)
    {
        gotoxy(1, 25);
        cout << "Press any key to continue...";
        getchar();
    }

    file.close();
}

// THIS FUNCTION DISPLAYS THE RECORD OF THE EMPLOYEES

void Employee::display_record(int ecode)
{
    fstream file;
    file.open("EMPLOYEE.DATA", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)this, sizeof(Employee)))
    {
        if (code == ecode)
        {
            gotoxy(5, 5);
            cout << "Employee Code # " << code;
            gotoxy(5, 6);
            cout << "~~~~~~~~~~~~~";
            gotoxy(5, 7);
            cout << "Name         : " << name;
            gotoxy(5, 8);
            cout << "Address      : " << address;
            gotoxy(5, 9);
            cout << "Phone no.    : " << phone;
            gotoxy(5, 11);
            cout << "JOINING DATE";
            gotoxy(5, 12);
            cout << "~~~~~~~~~~~~";
            gotoxy(5, 13);
            cout << "Day   : " << dd;
            gotoxy(5, 14);
            cout << "Month : " << mm;
            gotoxy(5, 15);
            cout << "Year  : " << yyyy;
            gotoxy(5, 17);
            cout << "Designation  : " << design;
            gotoxy(5, 18);
            cout << "Grade        : " << grade;
            if (grade != 'E')
            {
                gotoxy(5, 19);
                cout << "House (y/n)    : " << house;
                gotoxy(5, 20);
                cout << "Convense (y/n) : " << convense;
                gotoxy(5, 22);
                cout << "Basic Salary   : " << basic;
            }
            gotoxy(5, 21);
            cout << "Loan           : " << loan;
        }
    }
    file.close();
}

void Employee::new_Employee(void)
{
   // system("cls");
   cout<<"new employee"<<endl;
    char ch, egrade, ehouse = 'N', econv = 'N';
    char ename[26], eaddress[31], ephone[10], edesig[16], t1[10];
    float t2 = 0.0, eloan = 0.0, ebasic = 0.0;
    int d, m, y, ecode, valid;
    
    gotoxy(72, 2);
    cout << "<0>=EXIT"<<endl;
   cout<<"new employee2"<<endl;

    gotoxy(2, 3);
    cout << "\nADDITION OF NEW Employee"<<endl;
    gotoxy(5, 5);
    cout << "Employee Code # "<<endl;
    gotoxy(5, 6);
    cout << "~~~~~~~~~~~~~"<<endl;
    gotoxy(5, 7);
    cout << "Name         : "<<endl;
    gotoxy(5, 8);
    cout << "Address      : "<<endl;
    gotoxy(5, 9);
    cout << "Phone no.    : "<<endl;
    gotoxy(5, 11);
    cout << "JOINING DATE"<<endl;
    gotoxy(5, 12);
    cout << "~~~~~~~~~~~~"<<endl;
    gotoxy(5, 13);
    cout << "Day   : "<<endl;
    gotoxy(5, 14);
    cout << "Month : "<<endl;
    gotoxy(5, 15);
    cout << "Year  : "<<endl;
    gotoxy(5, 17);
    cout << "Designation  : "<<endl;
    gotoxy(5, 18);
    cout << "Grade        : "<<endl;
    gotoxy(5, 21);
    cout << "Loan           : \t\n\n"<<endl;

    ecode = last_code() + 1;
    if (ecode == 1)
    {
        add_record(ecode, "null", "null", "null", 0, 0, 0, "null", 'n', 'n', 'n', 0.0, 0.0);
        delete_record(ecode);
    }
    gotoxy(21, 5);
    cout << ecode;
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "\n\tEnter the name of the Employee\t";
        gotoxy(20, 7);
        std::cout << "\033[1D";
        cin >> ename;

        if (ename[0] == '0')
            return;
        if (strlen(ename) < 1 || strlen(ename) > 25)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly (Range: 1..25)";
            getchar();
        }
    } while (!valid);
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Address of the Employee";
        gotoxy(20, 8);
        std::cout << "\033[1D";
        cin >> eaddress;
        //  (eaddress);
        if (eaddress[0] == '0')
            return;
        if (strlen(eaddress) < 1 || strlen(eaddress) > 30)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly (Range: 1..30)";
            getchar();
        }
    } while (!valid);
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Phone no. of the Employee or Press <ENTER> for none";
        gotoxy(20, 9);
        std::cout << "\033[1D";
        cin >> ephone;
        if (ephone[0] == '0')
            return;
        if ((strlen(ephone) < 7 && strlen(ephone) > 0) || (strlen(ephone) > 9))
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly";
            getchar();
        }
    } while (!valid);
    if (strlen(ephone) == 0)
        strcpy(ephone, "-");
    char tday[3], tmonth[3], tyear[5];
    int td;
    do
    {
        valid = 1;
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER DAY OF JOINING";
            gotoxy(13, 13);
            std::cout << "\033[1D";
            cin >> tday;
            td = atoi(tday);
            d = td;
            if (tday[0] == '0')
                return;
        } while (d == 0);
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER MONTH OF JOINING";
            gotoxy(13, 14);
            std::cout << "\033[1D";
            cin >> tmonth;
            td = atoi(tmonth);
            m = td;
            if (tmonth[0] == '0')
                return;
        } while (m == 0);
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER YEAR OF JOINING";
            gotoxy(13, 15);
            std::cout << "\033[1D";
            cin >> tyear;
            td = atoi(tyear);
            y = td;
            if (tyear[0] == '0')
                return;
        } while (y == 0);
        if (d > 31 || d < 1)
            valid = 0;
        else if (((y % 4) != 0 && m == 2 && d > 28) || ((y % 4) == 0 && m == 2 && d > 29))
            valid = 0;
        else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
            valid = 0;
        else if (y < 1990 || y > 2020)
            valid = 0;
        if (!valid)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly";
            getchar();
            gotoxy(13, 14);
            std::cout << "\033[1D";
            gotoxy(13, 15);
            std::cout << "\033[1D";
        }
    } while (!valid);
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Designation of the Employee";
        gotoxy(20, 17);
        std::cout << "\033[1D";
        cin >> edesig;

        if (edesig[0] == '0')
            return;
        if (strlen(edesig) < 1 || strlen(edesig) > 15)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7\nEnter correctly (Range: 1..15)";
            getchar();
        }
    } while (!valid);
    do
    {
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Grade of the Employee (A,B,C,D,E)";
        gotoxy(20, 18);
        std::cout << "\033[1D";
        egrade = getchar();
        egrade = toupper(egrade);
        if (egrade == '0')
            return;
    } while (egrade < 'A' || egrade > 'E');
    if (egrade != 'E')
    {
        gotoxy(5, 19);
        cout << "House (y/n)    : ";
        gotoxy(5, 20);
        cout << "Convense (y/n) : ";
        gotoxy(5, 22);
        cout << "Basic Salary   : ";
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER IF HOUSE ALLOWANCE IS ALLOTED TO Employee OR NOT";
            gotoxy(22, 19);
            std::cout << "\033[1D";
            ehouse = getchar();
            ehouse = toupper(ehouse);
            if (ehouse == '0')
                return;
        } while (ehouse != 'Y' && ehouse != 'N');
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER IF CONVENCE ALLOWANCE IS ALLOTED TO Employee OR NOT";
            gotoxy(22, 20);
            std::cout << "\033[1D";
            econv = getchar();
            econv = toupper(econv);
            if (econv == '0')
                return;
        } while (econv != 'Y' && econv != 'N');
    }
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "ENTER LOAN AMOUNT IF ISSUED";
        gotoxy(22, 21);
        std::cout << "\033[1D";
        cin >> t1;
        t2 = atof(t1);
        eloan = t2;
        if (eloan > 50000)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7SHOULD NOT GREATER THAN 50000";
            getchar();
        }
    } while (!valid);
    if (egrade != 'E')
    {
        do
        {
            valid = 1;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\nENTER BASIC SALARY OF THE Employee\t";
            gotoxy(22, 22);
            std::cout << "\033[1D";
            cin >> t1;
            t2 = atof(t1);
            ebasic = t2;
            if (t1[0] == '0')
                return;
            if (ebasic > 50000)
            {
                valid = 0;
                gotoxy(5, 25);
                std::cout << "\033[1D";
                cout << "\7SHOULD NOT GREATER THAN 50000\t";
                getchar();
            }
        } while (!valid);
    }
    gotoxy(5, 25);
    std::cout << "\033[1D";
    do
    {
        gotoxy(5, 24);
        std::cout << "\033[1D";
        cout << "\nDo you want to save (y/n) \t";
        ch = getchar();
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
        return;
    add_record(ecode, ename, eaddress, ephone, d, m, y, edesig, egrade, ehouse, econv, eloan, ebasic);
}

// THIS FUNCTION GIVE CODE FOR THE DISPLAY OF THE RECORD

void Employee::display()
{
    system("cls");
    char t1[10];
    int t2, ecode;
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(5, 5);
    cout << "\n\tEnter code of the Employee  :\t";
    cin >> t1;
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
        return;
    system("cls");
    if (!code_found(ecode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found:\t";
        getchar();
        return;
    }
    display_record(ecode);
    gotoxy(5, 25);
    cout << "\nPress any key to continue..\t";
    getchar();
}

/* THIS FUNCTION GIVE DATA FOR THE MODIFICATION OF THE
   Employee RECORD
*/

void Employee::modification(void)
{
    system("cls");
    char ch, egrade, ehouse = 'N', econv = 'N';
    char ename[26], eaddress[31], ephone[10], edesig[16], t1[10];
    float t2 = 0.0, eloan = 0.0, ebasic = 0.0;
    int ecode, valid;
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(5, 5);
    cout << "Enter code of the Employee  ";
    cin >> t1;
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
        return;
    system("cls");
    if (!code_found(ecode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found";
        getchar();
        return;
    }
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(22, 3);
    cout << "MODIFICATION OF THE Employee RECORD";
    display_record(ecode);
    do
    {
        gotoxy(5, 24);
        std::cout << "\033[1D";
        cout << "Do you want to modify this record (y/n) ";
        ch = getchar();
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
        return;
    system("cls");
    fstream file;
    file.open("EMPLOYEE.DATA", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)this, sizeof(Employee)))
    {
        if (code == ecode)
            break;
    }
    file.close();
    gotoxy(5, 5);
    cout << "Employee Code # " << ecode;
    gotoxy(5, 6);
    cout << "~~~~~~~~~~~~~";
    gotoxy(40, 5);
    cout << "JOINING DATE : ";
    gotoxy(40, 6);
    cout << "~~~~~~~~~~~~~~";
    gotoxy(55, 5);
    cout << dd << "/" << mm << "/" << yyyy;
    gotoxy(5, 7);
    cout << "Name         : ";
    gotoxy(5, 8);
    cout << "Address      : ";
    gotoxy(5, 9);
    cout << "Phone no.    : ";
    gotoxy(5, 10);
    cout << "Designation  : ";
    gotoxy(5, 11);
    cout << "Grade        : ";
    gotoxy(5, 14);
    cout << "Loan           : ";
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter the name of the Employee or <ENTER> FOR NO CHANGE";
        gotoxy(20, 7);
        std::cout << "\033[1D";
        cin >> ename;
        (ename);
        if (ename[0] == '0')
            return;
        if (strlen(ename) > 25)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly (Range: 1..25)";
            getchar();
        }
    } while (!valid);
    if (strlen(ename) == 0)
    {
        strcpy(ename, name);
        gotoxy(20, 7);
        cout << ename;
    }
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Address of the Employee or <ENTER> FOR NO CHANGE";
        gotoxy(20, 8);
        std::cout << "\033[1D";
        cin >> eaddress;

        if (eaddress[0] == '0')
            return;
        if (strlen(eaddress) > 30)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly (Range: 1..30)";
            getchar();
        }
    } while (!valid);
    if (strlen(eaddress) == 0)
    {
        strcpy(eaddress, address);
        gotoxy(20, 8);
        cout << eaddress;
    }
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Phone no. of the Employee or or <ENTER> FOR NO CHANGE";
        gotoxy(20, 9);
        std::cout << "\033[1D";
        cin >> ephone;
        if (ephone[0] == '0')
            return;
        if ((strlen(ephone) < 7 && strlen(ephone) > 0) || (strlen(ephone) > 9))
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly";
            getchar();
        }
    } while (!valid);
    if (strlen(ephone) == 0)
    {
        strcpy(ephone, phone);
        gotoxy(20, 9);
        cout << ephone;
    }
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Designation of the Employee or <ENTER> FOR NO CHANGE";
        gotoxy(20, 10);
        std::cout << "\033[1D";
        cin >> edesig;

        if (edesig[0] == '0')
            return;
        if (strlen(edesig) > 15)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7Enter correctly (Range: 1..15)";
            getchar();
        }
    } while (!valid);
    if (strlen(edesig) == 0)
    {
        strcpy(edesig, design);
        gotoxy(20, 10);
        cout << edesig;
    }
    do
    {
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "Enter Grade of the Employee (A,B,C,D,E) or <ENTER> FOR NO CHANGE";
        gotoxy(20, 11);
        std::cout << "\033[1D";
        egrade = getchar();
        egrade = toupper(egrade);
        if (egrade == '0')
            return;
        if (egrade == 13)
        {
            egrade = grade;
            gotoxy(20, 11);
            cout << grade;
        }
    } while (egrade < 'A' || egrade > 'E');
    if (egrade != 'E')
    {
        gotoxy(5, 12);
        cout << "House (y/n)    : ";
        gotoxy(5, 13);
        cout << "Convense (y/n) : ";
        gotoxy(5, 15);
        cout << "Basic Salary   : ";
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ALLOTED HOUSE ALLOWANCE ? or <ENTER> FOR NO CHANGE";
            gotoxy(22, 12);
            std::cout << "\033[1D";
            ehouse = getchar();
            ehouse = toupper(ehouse);
            if (ehouse == '0')
                return;
            if (ehouse == 13)
            {
                ehouse = house;
                gotoxy(22, 12);
                cout << ehouse;
            }
        } while (ehouse != 'Y' && ehouse != 'N');
        do
        {
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ALLOTED CONVENCE ALLOWANCE or <ENTER> FOR NO CHANGE";
            gotoxy(22, 13);
            std::cout << "\033[1D";
            econv = getchar();
            econv = toupper(econv);
            if (econv == '0')
                return;
            if (econv == 13)
            {
                econv = convense;
                gotoxy(22, 13);
                cout << econv;
            }
        } while (econv != 'Y' && econv != 'N');
    }
    do
    {
        valid = 1;
        gotoxy(5, 25);
        std::cout << "\033[1D";
        cout << "ENTER LOAN AMOUNT or <ENTER> FOR NO CHANGE";
        gotoxy(22, 14);
        std::cout << "\033[1D";
        cin >> t1;
        t2 = atof(t1);
        eloan = t2;
        if (eloan > 50000)
        {
            valid = 0;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "\7SHOULD NOT GREATER THAN 50000";
            getchar();
        }
    } while (!valid);
    if (strlen(t1) == 0)
    {
        eloan = loan;
        gotoxy(22, 14);
        cout << eloan;
    }
    if (egrade != 'E')
    {
        do
        {
            valid = 1;
            gotoxy(5, 25);
            std::cout << "\033[1D";
            cout << "ENTER BASIC SALARY or <ENTER> FOR NO CHANGE";
            gotoxy(22, 15);
            std::cout << "\033[1D";
            cin >> t1;
            t2 = atof(t1);
            ebasic = t2;
            if (t1[0] == '0')
                return;
            if (ebasic > 50000)
            {
                valid = 0;
                gotoxy(5, 25);
                std::cout << "\033[1D";
                cout << "\7SHOULD NOT GREATER THAN 50000";
                getchar();
            }
        } while (!valid);
        if (strlen(t1) == 0)
        {
            ebasic = basic;
            gotoxy(22, 15);
            cout << ebasic;
        }
    }
    gotoxy(5, 25);
    std::cout << "\033[1D";
    do
    {
        gotoxy(5, 18);
        std::cout << "\033[1D";
        cout << "Do you want to save (y/n) ";
        ch = getchar();
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
        return;
    modify_record(ecode, ename, eaddress, ephone, edesig, egrade, ehouse, econv, eloan, ebasic);
    gotoxy(5, 23);
    cout << "\7Record Modified";
    gotoxy(5, 25);
    cout << "Press any key to continue...";
    getchar();
}

/* THIS FUNCTION GIVE CODE NO. FOR THE DELETION OF THE
   Employee RECORD */

void Employee::deletion(void)
{
    system("cls");
    char t1[10], ch;
    int t2, ecode;
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(5, 5);
    cout << "\nEnter code of the Employee \t ";
    cin >> t1;
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
        return;
    system("cls");
    if (!code_found(ecode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found";
        getchar();
        return;
    }
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(24, 3);
    cout << "DELETION OF THE Employee RECORD";
    display_record(ecode);
    do
    {
        gotoxy(5, 24);

        cout << "Do you want to delete this record (y/n) ";
        ch = getchar();
        ch = toupper(ch);
        if (ch == '0')
            return;
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'N')
        return;
    delete_record(ecode);
    Lines L;
    L.clear_down();
    gotoxy(5, 23);
    cout << "\7Record Deleted";
    gotoxy(5, 25);
    cout << "Press any key to continue...";
    getchar();
}

// THIS FUNCTION RETURN 0 IF THE GIVEN DATE IS INVALID

int Employee::valid_date(int d1, int m1, int y1)
{
    int valid = 1;
    if (d1 > 31 || d1 < 1)
        valid = 0;
    else if (((y1 % 4) != 0 && m1 == 2 && d1 > 28) || ((y1 % 4) == 0 && m1 == 2 && d1 > 29))
        valid = 0;
    else if ((m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) && d1 > 30)
        valid = 0;
    return valid;
}

// THIS FUNCTION PRINTS THE SALARY SLIP FOR THE EMPLOYEE

void Employee::salary_slip(void)
{
    system("cls");
    char t1[10];
    int t2, ecode, valid;
    gotoxy(72, 2);
    cout << "<0>=EXIT";
    gotoxy(5, 5);
    cout << "Enter code of the Employee  ";
    cin >> t1;
    t2 = atoi(t1);
    ecode = t2;
    if (ecode == 0)
        return;
    system("cls");
    if (!code_found(ecode))
    {
        gotoxy(5, 5);
        cout << "\7Record not found";
        getchar();
        return;
    }
    fstream file;
    file.open("EMPLOYEE.DATA", ios::in);
    file.seekg(0, ios::beg);
    while (file.read((char *)this, sizeof(Employee)))
    {
        if (code == ecode)
            break;
    }
    file.close();
    int d1, m1, y1;
    // struct date d;
    // getdate(d);
    // d1 = d.da_day;
    // m1 = d.da_mon;
    // y1 = d.da_year;
    string mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December"};
    Lines L;
    L.box(2, 1, 79, 25, 219);
    gotoxy(31, 2);
    cout << "NADEEM AKHTAR, PGDBA - 200754667";
    L.line_hor(3, 78, 3, 196);
    gotoxy(34, 4);
    cout << "SALARY SLIP";
    gotoxy(60, 4);
    // cout << "Date: " << d1 << "/" << m1 << "/" << y1;
    // gotoxy(34, 5);
    // cout << mon[m1 - 1] << ", " << y1;
    L.line_hor(3, 78, 6, 196);
    gotoxy(6, 7);
    cout << "Employee Name : " << name;
    gotoxy(6, 8);
    cout << "Designation   : " << design;
    gotoxy(67, 8);
    cout << "Grade : " << grade;
    L.box(6, 9, 75, 22, 218);
    L.line_hor(10, 71, 20, 196);
    int days, hours;
    if (grade == 'E')
    {
        do
        {
            valid = 1;
            gotoxy(10, 21);
            cout << "ENTER NO. OF DAYS WORKED IN THE MONTH ";
            gotoxy(10, 11);
            cout << "No. of Days   : ";
            cin >> t1;
            t2 = atof(t1);
            days = t2;
            if (!valid_date(days, m1, y1))
            {
                valid = 0;
                gotoxy(10, 21);
                cout << "\7ENTER CORRECTLY                       ";
                getchar();
                gotoxy(10, 11);
                cout << "                    ";
            }
        } while (!valid);
        do
        {
            valid = 1;
            gotoxy(10, 21);
            cout << "ENTER NO. OF HOURS WORKED OVER TIME   ";
            gotoxy(10, 13);
            cout << "No. of hours  : ";
            cin >> t1;
            t2 = atof(t1);
            hours = t2;
            if (hours > 8 || hours < 0)
            {
                valid = 0;
                gotoxy(10, 21);
                cout << "\7ENTER CORRECTLY                     ";
                getchar();
                gotoxy(10, 13);
                cout << "                    ";
            }
        } while (!valid);
        gotoxy(10, 21);
        cout << "                                               ";
        gotoxy(10, 11);
        cout << "                        ";
        gotoxy(10, 13);
        cout << "                        ";
    }
    gotoxy(10, 10);
    cout << "Basic Salary         : $ ";
    gotoxy(10, 12);
    cout << "ALLOWANCE";
    if (grade != 'E')
    {
        gotoxy(12, 13);
        cout << "HRA  : $ ";
        gotoxy(12, 14);
        cout << "CA   : $ ";
        gotoxy(12, 15);
        cout << "DA   : $ ";
    }
    else
    {
        gotoxy(12, 13);
        cout << "OT   : $ ";
    }
    gotoxy(10, 17);
    cout << "DEDUCTIONS";
    gotoxy(12, 18);
    cout << "LD   : $ ";
    if (grade != 'E')
    {
        gotoxy(12, 19);
        cout << "PF   : $ ";
    }
    gotoxy(10, 21);
    cout << "NET SALARY           : $ ";
    gotoxy(6, 24);
    cout << "CASHIER";
    gotoxy(68, 24);
    cout << "EMPLOYEE";
    float HRA = 0.0, CA = 0.0, DA = 0.0, PF = 0.0, LD = 0.0, OT = 0.0, allowance, deduction, netsalary;
    if (grade != 'E')
    {
        if (house == 'Y')
            HRA = (5 * basic) / 100;
        if (convense == 'Y')
            CA = (2 * basic) / 100;
        DA = (5 * basic) / 100;
        PF = (2 * basic) / 100;
        LD = (15 * loan) / 100;
        allowance = HRA + CA + DA;
        deduction = PF + LD;
    }
    else
    {
        basic = days * 30;
        LD = (15 * loan) / 100;
        OT = hours * 10;
        allowance = OT;
        deduction = LD;
    }
    netsalary = (basic + allowance) - deduction;
    gotoxy(36, 10);
    cout << basic;
    if (grade != 'E')
    {
        gotoxy(22, 13);
        cout << HRA;
        gotoxy(22, 14);
        cout << CA;
        gotoxy(22, 15);
        cout << DA;
        gotoxy(22, 19);
        cout << PF;
    }
    else
    {
        gotoxy(22, 13);
        cout << OT;
    }
    gotoxy(22, 18);
    cout << LD;
    gotoxy(33, 15);
    cout << "$ " << allowance;
    gotoxy(33, 19);
    cout << "$ " << deduction;
    gotoxy(36, 21);
    cout << netsalary;
    gotoxy(2, 1);
    getchar();
}

int main()
{
    Menu menu;
    menu.main_menu();

    return (0);
}