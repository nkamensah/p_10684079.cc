#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>


using namespace std;

//Student’s Information.
 struct student
{
    //Takes care of student's details.
 string id, firstname, lastname, sex, age, clas;

};

void addstudent() //To obtain student’s data.
{
    char inchoice;
    int i;
    student stu;
    ofstream outputfile;
    cout<< "\nPress 1 again to confirm ADD STUDENT: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tADD STUDENT"<<endl;
    cout<<"\tID number: "; cin>>stu.id;
    cout<<"\tFirst Name: "; cin>>stu.firstname;
    cout<<"\tLast Name: "; cin>>stu.lastname;
    cout<<"\tClass: "; cin>>stu.clas;
    cout<<"\tSex: "; cin>>stu.sex;
    cout<<"\tAge: "; cin>>stu.age;

    //Outputs to student’s file.
    outputfile.open("student.txt",ios::app);
    outputfile<<stu.id<<" "<<stu.firstname<<" "<<stu.lastname<<" "<<stu.clas<<" "<<stu.sex<<" "<<stu.age<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tStudent has been Added!\n";
    cout<<"\n\n\n\nPress 'Y' to add another student or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}


void editstudent()
{
    char inchoice;
    int i;

    cout<< "\nPress 2 again to confirm EDIT STUDENT: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STUDENT"<<endl;
    string id;
    cout<<"\n Enter the student's ID number: ";
    cin>>id;

    student stu;
    fstream intofile ("student.txt");
    fstream temporalfile ("temp.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName:"; cin>>stu.firstname;
            cout<<"LastName:"; cin>>stu.lastname;
            cout<<"Class:"; cin>>stu.clas;
            cout<<"Sex: "; cin>>stu.sex;
            cout<<"Age: "; cin>>stu.age;

            temporalfile<<id<<" "<<stu.firstname<<" "<<stu.lastname<<" "<<stu.clas<<" "<<stu.sex<<" "<<stu.age<<endl;
            cout<<"\nstudent information has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
cout<<"\n\n\n\nPress 'Y' to edit another student or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestudent()
{
    char inchoice;
    int i;

    cout<< "\nPress 3 again to confirm DELETE STUDENT: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STUDENT"<<endl;
    string id;
    cout<<"Enter ID number: ";
    cin>>id;

    student stu;
    fstream intofile ("student.txt");
    fstream temporalfile ("temp.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Student has been successfully deleted! \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
cout<<"\n\n\n\nPress 'Y' to delete another student or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}


void studentslist()
{
    ifstream outputfile("student.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t  ALL STUDENTS \t\t\n\n\n";
    cout << setw(15) <<"ID NUMBER" << setw(15) << "FIRST NAME" << setw(15) << "LAST NAME" <<setw(15) << "CLASS"<<setw(15)<<"SEX"<<setw(15)<<"AGE"<< endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it; //It prints d.

        }
        std::cout << '\n';

    }

cout<< "\n\n\n\nEnter any key to continue to main menu: "; cin>>i;
system("cls");
}




//Staff’s Infromation.
 struct staff
{
 string id, firstname, lastname,sex, age, teachcourse;
};
void addstaff() //To obtain staff’s details.
{
     char inchoice;
    int i;
    staff sta;
    ofstream outputfile;
    cout<< "\nPress 1 again to confirm ADD STAFF: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){


    cout<< "\n\n\t\t\tADD STAFF"<<endl;
    cout<<"\tID number: "; cin>>sta.id;
    cout<<"\tFirst Name: "; cin>>sta.firstname;
    cout<<"\tLast Name: "; cin>>sta.lastname;
    cout<<"\tCourse Taught: "; cin>>sta.teachcourse;
    cout<<"\tSex: "; cin>>sta.sex;
    cout<<"\tAge: "; cin>>sta.age;

   outputfile.open("staff.txt",ios::app);  //This outputs to student file.
    outputfile<<sta.id<<" "<<sta.firstname<<" "<<sta.lastname<<" "<<sta.teachcourse<<" "<<sta.sex<<" "<<sta.age<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tStaff has been successfully added!\n";
    cout<<"\n\n\n\nPress 'Y' to add another staff or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editstaff()
{
    char inchoice;
    int i;

    cout<< "\nPress 2 again to confirm EDIT STAFF: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STAFF"<<endl;
    string id;
    cout<<"\n Enter the staff's ID number: ";
    cin>>id;

    staff sta;
    fstream intofile ("staff.txt");
    fstream temporalfile ("temp1.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName: "; cin>>sta.firstname;
            cout<<"LastName: "; cin>>sta.lastname;
            cout<<"Class: "; cin>>sta.teachcourse;
            cout<<"Sex: "; cin>>sta.sex;
            cout<<"Age: "; cin>>sta.age;

            temporalfile<<id<<" "<<sta.firstname<<" "<<sta.lastname<<" "<<sta.teachcourse<<" "<<sta.sex<<" "<<sta.age<<endl;
            cout<<"\nstaff has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("staff.txt");
    rename("temp1.txt","staff.txt");
cout<<"\n\n\n\n Press 'Y' to edit another staff or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestaff()
{
    char inchoice;
    int i;

    cout<< "\nPress 3 again to confirm delete student: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STAFF"<<endl;
    string id;
    cout<<"Enter ID number: ";
    cin>>id;

    staff sta;
    fstream intofile ("staff.txt");
    fstream temporalfile ("temp1.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Staff has been successfully deleted! \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("staff.txt");
    rename("temp1.txt","staff.txt");

cout<<"\n\n\n\nPress 'Y' to delete another student or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}


void staffslist()
{
    string i;
    ifstream outputfile("staff.txt");
    string content;
    cout<<endl<<"\t\t\t\t  ALL STAFF \t\t\n\n\n";
    cout << setw(15) <<"ID NUMBER" << setw(15) << "FIRST NAME" << setw(15) << "LAST NAME" <<setw(15) << "SUBJECT TAUGHT"<<setw(15)<<"SEX"<<setw(15)<<"AGE"<< endl<<endl;

    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;//It prints d.

        }
        std::cout << '\n';

    }

cout<< "\n\n\n\n Press any key to continue: "; cin>>i;
system("cls");
}



//Course Details.
struct course
{
    string code, title, credithrs, tutor;
};
void addcourse() //get course data.
{
    char inchoice;
    int i;
    course cou[1000];
    ofstream outputfile;
    cout<< "\n Press 1 again to confirm ADD COURSE: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tADD COURSE"<<endl;
    cout<<"\tcourse code: "; cin>>cou[i].code;
    cout<<"\tcourse title: "; cin>>cou[i].title;
    cout<<"\tcredit hours: "; cin>>cou[i].credithrs;
    cout<<"\tcourse tutor: "; cin>>cou[i].tutor;

    //output to student file.
    outputfile.open("course.txt",ios::app);
    outputfile<<cou[i].code<<" "<<cou[i].title<<" "<<cou[i].credithrs<<" "<<cou[i].tutor<<" "<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tCourse has been Added!\n";
    cout<<"\n\n\n\n Press 'Y' to add another course or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editcourse()
{
    char inchoice;
    int i;

    cout<< "\n Press 2 again to confirm EDIT COURSE: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT COURSE"<<endl;
    string code;
    cout<<"\n Enter the course code: ";
    cin>>code;

    course cou;
    fstream intofile ("course.txt");
    fstream temporalfile ("temp2.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && code==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"Course title:"; cin>>cou.title;
            cout<<"Credit hours:"; cin>>cou.credithrs;
            cout<<"Tutor:"; cin>>cou.tutor;

            temporalfile<<code<<" "<<cou.title<<" "<<cou.credithrs<<" "<<cou.tutor<<endl;
            cout<<"\nCourse information has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("course.txt");
    rename("temp.txt","course.txt");
cout<<"\n\n\n\n Press 'Y' to edit another course or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletecourse()
{
    char inchoice;
    int i;

    cout<< "\n Press 3 again to confirm delete course: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE COURSE"<<endl;
    string code;
    cout<<"Enter Course Code: ";
    cin>>code;

    course cou;
    fstream intofile ("course.txt");
    fstream temporalfile ("temp2.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && code==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Course has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("course.txt");
    rename("temp2.txt","course.txt");
cout<<"\n\n\n\n Press 'Y' to delete another course or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}


void courselist()
{
    ifstream outputfile("course.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t  ALL COURSES \t\t\n\n\n";
    cout << setw(15) <<"COURSE CODE" << setw(15) << "COURSE TITLE" << setw(15) << "CREDIT HOURS" <<setw(15) << "COURSE TUTOR"<< endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;//It prints d.

        }
        std::cout << '\n';

    }

cout<< "\n\n\n\n Press any key to continue to main menu: "; cin>>i;
system("cls");
}



struct studentrecord
{
    string id, firstname, lastname;
    float math, sci, soc, eng;
    char mathgrd, scigrd, socgrd, culgrd;
    string mathrem, scirem, socrem, culrem;
};
void addstudentrecord() //get student data.
{
    char inchoice;
    int i;
    studentrecord g;
    ofstream outputfile;
    ofstream outputfile2;
    cout<< "\n Press 1 again to confirm add student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tRECORD STUDENT GRADE"<<endl;
    cout<<"Student ID: ";cin>>g.id;
    cout<<"First name: ";cin>>g.firstname;
    cout<<"Last name: ";cin>>g.lastname;
    cout<<"\n\n\n\t\t\t Enter marks for "<<g.firstname<<" "<<g.lastname<<" ("<<g.id<<")"<<endl;

    cout<<"\t Enter Mathematics mark: ";cin>>g.math;
    if (g.math >= 80) g.mathgrd='A'; else if (g.math>= 70) g.mathgrd='B'; else if (g.math>= 60) g.mathgrd='C'; else if (g.math>= 50) g.mathgrd='D'; else if (g.math>= 40) g.mathgrd='E'; else g.mathgrd='F';
    if (g.math >= 80) g.mathrem="EXCELLENT"; else if (g.math>= 70) g.mathrem="V. GOOD"; else if (g.math>= 60) g.mathrem="GOOD"; else if (g.math>= 50) g.mathrem="CREDIT"; else if (g.math>= 40) g.mathrem="PASS"; else g.mathrem="FAIL";

    cout<<"\t Enter Science mark for: ";cin>>g.sci;
    if (g.sci >= 80) g.scigrd='A'; else if (g.sci>= 70) g.scigrd='B'; else if (g.sci>= 60) g.scigrd='C'; else if (g.sci>= 50) g.scigrd='D'; else if (g.sci>= 40) g.scigrd='E'; else g.scigrd='F';
    if (g.sci >= 80) g.scirem="EXCELLENT"; else if (g.sci>= 70) g.scirem="V. GOOD"; else if (g.sci>= 60) g.scirem="GOOD"; else if (g.sci>= 50) g.scirem="CREDIT"; else if (g.sci>= 40) g.scirem="PASS"; else g.scirem="FAIL";

    cout<<"\tSocial Studies mark: "; cin>>g.soc;
    if (g.soc >= 80) g.socgrd='A'; else if (g.soc>= 70) g.socgrd='B'; else if (g.soc>= 60) g.socgrd='C'; else if (g.soc>= 50) g.socgrd='D'; else if (g.soc>= 40) g.socgrd='E'; else g.socgrd='F';
    if (g.soc >= 80) g.socrem="EXCELLENT"; else if (g.soc>= 70) g.socrem="V. GOOD"; else if (g.soc>= 60) g.socrem="GOOD"; else if (g.soc>= 50) g.socrem="CREDIT"; else if (g.soc>= 40) g.socrem="PASS"; else g.socrem="FAIL";

    cout<<"\tEnglish Language mark: "; cin>>g.eng;
    if (g.eng >= 80) g.culgrd='A'; else if (g.eng>= 70) g.culgrd='B'; else if (g.eng>= 60) g.culgrd='C'; else if (g.eng>= 50) g.culgrd='D'; else if (g.eng>= 40) g.culgrd='E'; else g.culgrd='F';
    if (g.eng >= 80) g.culrem="EXCELLENT"; else if (g.eng>= 70) g.culrem="V. GOOD"; else if (g.eng>= 60) g.culrem="GOOD"; else if (g.eng>= 50) g.culrem="CREDIT"; else if (g.eng>= 40) g.culrem="PASS"; else g.culrem="FAIL";

    //output to student record file.
    outputfile.open("record.txt",ios::app);
    outputfile<<g.id<<" "<<g.firstname<<" "<<g.lastname<<" "<<g.mathgrd<<" "<<g.scigrd<<" "<<g.socgrd<<" "<<g.culgrd<<endl<<endl;
    outputfile2.open("record2.txt",ios::app);
    outputfile2<<g.id<<endl<<g.firstname<<endl<<g.lastname<<endl<<" “<<setw(10)<<g.math<<" "<<setw(10)<<g.mathgrd<<" "<<setw(15)<<g.mathrem<<endl<<setw(10)<<g.sci<<" "<<setw(10)<<g.scigrd<<" "<<setw(15)<<g.scirem<<endl<<setw(10)<<g.soc<<" "<<setw(10)<<g.socgrd<<" "<<setw(15)<<g.socrem<<endl<<setw(10)<<g.eng<<" "<<setw(10)<<g.culgrd<<" "<<setw(15)<<g.culrem"<<endl<<endl;
    outputfile.close();
    outputfile2.close();
    cout<<"\n\n\t\t\tStudent grade has been Added!\n";
    cout<<"\n\n\n\n Press 'Y' to add another student or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editstudentrecord()
{
    char inchoice;
    int i;

    cout<< "\n Press 2 again to confirm edit student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STUDENT"<<endl;
    string id;
    cout<<"\n Enter the student's ID number: ";
    cin>>id;

    studentrecord g;
    fstream intofile ("record.txt");
    fstream temporalfile ("temp8.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
    cout<<"First name: ";cin>>g.firstname;
    cout<<"Last name: ";cin>>g.lastname;
    cout<<"\n\n\n\t\t\t Enter marks for "<<g.firstname<<" "<<g.lastname<<" ("<<id<<")"<<endl;

    cout<<"\t Enter Mathematics mark: ";cin>>g.math;
    if (g.math >= 80) g.mathgrd='A'; else if (g.math>= 70) g.mathgrd='B'; else if (g.math>= 60) g.mathgrd='C'; else if (g.math>= 50) g.mathgrd='D'; else if (g.math>= 40) g.mathgrd='E'; else g.mathgrd='F';
    if (g.math >= 80) g.mathrem="EXCELLENT"; else if (g.math>= 70) g.mathrem="V. GOOD"; else if (g.math>= 60) g.mathrem="GOOD"; else if (g.math>= 50) g.mathrem="CREDIT"; else if (g.math>= 40) g.mathrem="PASS"; else g.mathrem="FAIL";

    cout<<"\t Enter Science mark for: ";cin>>g.sci;
    if (g.sci >= 80) g.scigrd='A'; else if (g.sci>= 70) g.scigrd='B'; else if (g.sci>= 60) g.scigrd='C'; else if (g.sci>= 50) g.scigrd='D'; else if (g.sci>= 40) g.scigrd='E'; else g.scigrd='F';
    if (g.sci >= 80) g.scirem="EXCELLENT"; else if (g.sci>= 70) g.scirem="V. GOOD"; else if (g.sci>= 60) g.scirem="GOOD"; else if (g.sci>= 50) g.scirem="CREDIT"; else if (g.sci>= 40) g.scirem="PASS"; else g.scirem="FAIL";

    cout<<"\tSocial Studies mark: "; cin>>g.soc;
    if (g.soc >= 80) g.socgrd='A'; else if (g.soc>= 70) g.socgrd='B'; else if (g.soc>= 60) g.socgrd='C'; else if (g.soc>= 50) g.socgrd='D'; else if (g.soc>= 40) g.socgrd='E'; else g.socgrd='F';
    if (g.soc >= 80) g.socrem="EXCELLENT"; else if (g.soc>= 70) g.socrem="V. GOOD"; else if (g.soc>= 60) g.socrem="GOOD"; else if (g.soc>= 50) g.socrem="CREDIT"; else if (g.soc>= 40) g.socrem="PASS"; else g.socrem="FAIL";

    cout<<"\tEnglish Language mark: "; cin>>g.eng;
    if (g.eng >= 80) g.culgrd='A'; else if (g.eng>= 70) g.culgrd='B'; else if (g.eng>= 60) g.culgrd='C'; else if (g.eng>= 50) g.culgrd='D'; else if (g.eng>= 40) g.culgrd='E'; else g.culgrd='F';
    if (g.eng >= 80) g.culrem="EXCELLENT"; else if (g.eng>= 70) g.culrem="V. GOOD"; else if (g.eng>= 60) g.culrem="GOOD"; else if (g.eng>= 50) g.culrem="CREDIT"; else if (g.eng>= 40) g.culrem="PASS"; else g.culrem="FAIL";


    temporalfile<<id<<" "<<g.firstname<<" "<<g.lastname<<" "<<g.mathgrd<<" "<<g.scigrd<<" "<<g.socgrd<<" "<<g.culgrd<<endl;

            cout<<"\nstudent record has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("record.txt");
    rename("temp8.txt","record.txt");
cout<<"\n\n\n\n Press 'Y' to edit another student record or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestudentrecord()
{
    char inchoice;
    int i;

    cout<< "\n Press 3 again to confirm delete student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STUDENT"<<endl;
    string id;
    cout<<"Enter ID number: ";
    cin>>id;

    student stu;
    fstream intofile ("record.txt");
    fstream temporalfile ("temp9.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Student record has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("record.txt");
    rename("temp9.txt","record.txt");
cout<<"\n\n\n\n Press 'Y' to delete another student record or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}

void studentsrecordlist()
{
    ifstream outputfile("record.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t\t\t\tALL STUDENT RECORDS \t\t\n\n\n";
    cout <<setw(15) <<"ID"<<setw(15)<<"FIRST NAME"<<setw(15)<<"LAST NAME"<<setw(20)<<"MATHEMATICS"<<setw(15)<<"SCIENCE"<<setw(15)<<"SOCIAL STUDIES"<<setw(15)<<"ENGLISH LANGUAGE"<<endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        std::vector<std::string> arrayTokens(begin, end); //Puts all tokens in vector.

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;//It prints d.

        }
        std::cout << '\n';

    }

cout<< "\n\n\n\n Press any key to continue to main menu: "; cin>>i;
system("cls");
}

void display()
{
int notfound=0,y=1,q,i;
string find, id,firstname,lastname,math,sci,socs,eng;
ifstream f2("record2.txt");
cout<<"Enter ID of student whose record you want to display: ";cin>>find;
cout<<endl;

for(q=0; (q<y)||(!f2.eof()); q++)
{
getline(f2,id);
if (id==find)
{
notfound=1;
cout<<setw(12)<<"ID: "<<id<<endl;
getline(f2,firstname);
cout<<setw(12)<<"First name: "<<firstname<<endl;
getline(f2,lastname);
cout<<setw(12)<<"Last name: "<<lastname<<endl<<endl;
cout<<"\t\t\t\tCOURSES\n\n";
cout<<setw(20)<<"COURSE "<<setw(12)<<"MARK "<<setw(12)<<"GRADE "<<setw(17)<<"REMARK "<<endl<<endl;
getline(f2,math);
cout<<setw(20)<<"Mathematics: "<<math<<endl;
getline(f2,sci);
cout<<setw(20)<<"Science: "<<sci<<endl;
getline(f2,socs);
cout<<setw(20)<<"Social Studies: "<<socs<<endl;
getline(f2,eng);
cout<<setw(20)<<"English Language: "<<eng<<endl;
}
}
if(notfound==0){cout<<"No Record Found"<<endl;}
f2.close();
cout<< "\n\n\n\n Press any key to continue to main menu: "; cin>>i;

}

int main()
{
    int select;
    string find;
    while(1)
    {

            cout <<endl<<endl;
            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM\t\t\t\t"<< endl;
            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
            cout << "\t\t\t\t\t MAIN MENU"<< endl<<endl<<endl;
            cout <<"\tPlease select: "<<endl;
            cout << "\t\t\t1. STUDENT (ADD/EDIT/DELETE/SHOW ALL STUDENTS)"<< endl;
            cout << "\t\t\t2. STAFF (ADD/EDIT/DELETE)"<< endl;
            cout << "\t\t\t3. COURSES (ADD/EDIT/DELETE)"<< endl;
            cout << "\t\t\t4. STUDENT RECORD "<< endl;
            cout << "\t\t\t5. EXIT"<< endl<<endl;
            cout << "Kindy make your choice by entering the corresponding number: ";


            cin>>select;
            system("cls");
            switch(select)
            {
                case 1:
                            int stuselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tSTUDENT "<< endl<<endl;
                            cout << "\t\t\t1. ADD STUDENT"<< endl;
                            cout << "\t\t\t2. EDIT STUDENT"<< endl;
                            cout << "\t\t\t3. DELETE STUDENT"<< endl;
                            cout << "\t\t\t4. SHOW ALL STUDENTS"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "Kindy make your choice by entering the corresponding number: ";
                            cin>>stuselect;
                            switch(stuselect)
                            {
                                case 1:
                                    addstudent();
                                    break;
                                case 2:
                                    editstudent();
                                    break;
                                case 3:
                                    deletestudent();
                                    break;
                                case 4:
                                    studentslist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"Wrong entry. Enter between 1-5.";
                            }

            break;


                case 2:
                            int staffselect;



                             cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tSTAFF "<< endl<<endl;
                            cout << "\t\t\t1. ADD STAFF"<< endl;
                            cout << "\t\t\t2. EDIT STAFF"<< endl;
                            cout << "\t\t\t3. DELETE STAFF"<< endl;
                            cout << "\t\t\t4. SHOW ALL STAFF"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "Kindy make your choice by entering the corresponding number: ";
                            cin>>staffselect;
                            switch(staffselect)
                            {
                                case 1:
                                    addstaff();
                                    break;
                                case 2:
                                    editstaff();
                                    break;
                                case 3:
                                    deletestaff();
                                    break;
                                case 4:
                                    staffslist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"Wrong entry! \n Press any key to continue: ";
                            }

                            break;


                     case 3:
                            int couselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tCOURSES "<< endl<<endl;
                            cout << "\t\t\t1. ADD COURSE"<< endl;
                            cout << "\t\t\t2. EDIT COURSE"<< endl;
                            cout << "\t\t\t3. DELETE COURSE"<< endl;
                            cout << "\t\t\t4. SHOW ALL COURSES"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "Kindy make your choice by entering the corresponding number: ";
                            cin>>couselect;
                            switch(couselect)
                            {
                                case 1:
                                    addcourse();
                                    break;
                                case 2:
                                    editcourse();
                                    break;
                                case 3:
                                    deletecourse();
                                    break;
                                case 4:
                                    courselist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"Wrong entry. Enter between 1-5.";
                            }

                       break;

                         case 4:
                            int recordselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM \t\t\t\t"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\t STUDENT RECORDS "<< endl<<endl;
                            cout << "\t\t\t1. ADD STUDENT RECORD"<< endl;
                            cout << "\t\t\t2. EDIT STUDENT RECORD"<< endl;
                            cout << "\t\t\t3. DELETE STUDENT RECORD"<< endl;
                            cout << "\t\t\t4. SHOW ALL STUDENTS RECORDS"<< endl;
                            cout << "\t\t\t5. FIND AND DISPLAY DETAILED STUDENT RECORD"<< endl;
                            cout << "\t\t\t6. EXIT"<< endl<<endl;
                            cout << "Kindy make your choice by entering the corresponding number: ";
                            cin>>recordselect;
                            switch(recordselect)
                            {
                                case 1:
                                    addstudentrecord();
                                    break;
                                case 2:
                                    editstudentrecord();
                                    break;
                                case 3:
                                    deletestudentrecord();
                                    break;
                                case 4:
                                    studentsrecordlist();
                                    break;
                                case 5:
                                    display();
                                    break;
                                case 6:exit(0);
                                break;
                                default:
                                        cout<<"Wrong entry. Enter between 1-5.";
                            }

                       break;
                       case 5:exit(0);
                        break;
                default:cout<<"Wrong entry. Please re-try!";
            }
            system("cls");
    }

    return 0;
}
