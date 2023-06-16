#include<bits/stdc++.h>
using namespace std;

class Lines
{   
    public:
    void line_hor(int, int, int , char);
    void line_ver(int, int, int , char);
    void box(int, int , int , int , char);
    void clear_up();
    void clear_down();

};

class Menu 
{
    private :
    void edit_menu();
    void introduction();
    public :
    void main_menu();

};

class Employee 
{
    private:
    void add_record(int , char[], char [], char[], int ,int, int, char [], char, char, char, float, float);
    void modify_record(int, char[], char[], char[], char[], char, char, char, float, float);
    void delete_record(int);
    void last_code();
    void code_found(int);
    void record_no(int);
    void display_record(int);
    int valid_date(int, int , int);
    
    int dd, mm, yyyy, code;
    char name[26], address[31], phone[10], design[16];
    char grade, house, convence;
    float loan, basic;

    public :
    void new_employee();
    void modification();
    void deletion();
    void display();
    void list();
    void salary_slip();

};


int main()
{


    return (0);
}