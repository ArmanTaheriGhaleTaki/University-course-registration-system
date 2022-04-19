#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "editing.h"
int Amount_of_students = 0;
infoStudent *Head;
int main()
{
    std::ifstream studentsFile("students.txt");
    studentsFile >> Amount_of_students;
    Head = NULL;
    int temp_Amount_of_students = Amount_of_students;
    for (int queue = 0; queue < temp_Amount_of_students; queue++)
    {
        infoStudent *student_temp = new infoStudent;
        student_temp->next = NULL;
        student_temp->lession_list = NULL;
        studentsFile >> student_temp->student_id;
        studentsFile >> student_temp->student_firstname;
        studentsFile >> student_temp->student_lastname;
        studentsFile >> student_temp->university_tuition;
        studentsFile >> student_temp->Amount_of_lessions;
        int temp = student_temp->Amount_of_lessions;
        student_temp->Amount_of_lessions = 0;
        add_student_at_end(&Head, student_temp, Amount_of_students);
        for (int i = 0; i < temp; i++)
        {
            lession *temp = new lession;
            temp->next = 0;
            studentsFile >> temp->lession_name1;
            studentsFile >> temp->lession_name2;
            temp->lession_name1 = temp->lession_name1 + " " + temp->lession_name2;
            temp->lession_name2 = " ";
            studentsFile >> temp->lession_id;
            studentsFile >> temp->lession_Coefficient;
            add_lession_at_end(&Head, temp, queue);
        }
    }
    Amount_of_students -= temp_Amount_of_students;
    int choice = 0;
    while (choice != 4)
    {
        system("cls");
        showmainmenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            add_new_student(&Head, Amount_of_students);
            break;
        case 2:
            edit_student_lession(Head, Amount_of_students);
            break;
        case 3:
            system("cls");
            std::cout << "Enter student's id: \n";
            int id;
            std::cin >> id;
            showStudentinfo(Head, id);
            break;
        case 4:
            return 0;
        }
    }
}