#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
int Amount_of_students = 0;
struct lession
{
    std::string lession_name1;
    std::string lession_name2;
    int lession_id;
    int lession_Coefficient;
    struct lession *next;
};
struct infoSudent
{
    int student_id;
    std::string student_firstname;
    std::string student_lastname;
    int university_tuition;
    int Amount_of_lessions;
    lession *lession_list;
    infoSudent *next;
    // infoSudent *prev;
};
// infoSudent *Head;
void showmainmenu()
{
    std::cout << "1. Add new student" << std::endl;
    std::cout << "2. edit student's lessions" << std::endl;
    std::cout << "3. show student's lessions" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: " << std::endl;
}
void showaddstudentmenu()
{
    std::cout << "1. Add new lession" << std::endl;
    std::cout << "2. back to main menu" << std::endl;
}
void add_lession_at_end(struct infoSudent *head, struct lession *temp, int queue)
{
    infoSudent *temp1 = head;
    for (int i = 0; i < queue; i++)
    {
        temp1 = temp1->next;
    }
    if (temp1->lession_list == 0)
    {
        temp1->lession_list = temp;
    }
    else
    {
        lession *temp2 = temp1->lession_list;
        if (temp2 == 0)
        {
            temp2 = temp;
        }
        else
        {
            while (temp2->next != 0)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }
}
void add_sudent_at_end(struct infoSudent **head, struct infoSudent *temp)
{
    if (*head == 0)
    {
        *head = temp;
    }
    else
    {
        infoSudent *temp2 = *head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
void display(struct infoSudent *head)
{
    struct infoSudent *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->student_id << " ";
        ptr = ptr->next;
    }
}
void showStudentinfo(struct infoSudent *head, int id)
{
    struct infoSudent *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->student_id == id)
        {
            // lession *temp = ptr->lession_list;
            std::cout << ptr->student_id << " ";
            std::cout << ptr->student_firstname << " ";
            std::cout << ptr->student_lastname << " ";
            std::cout << ptr->university_tuition << " ";
            std::cout << ptr->Amount_of_lessions << " ";
            for (int i = 0; i < ptr->Amount_of_lessions; i++)
            {
                std::cout << std::endl;
                std::cout << ptr->lession_list->lession_name1 << " ";
                std::cout << ptr->lession_list->lession_name2 << " ";
                std::cout << ptr->lession_list->lession_id << " ";
                std::cout << ptr->lession_list->lession_Coefficient << " ";
                ptr->lession_list = ptr->lession_list->next;
            }
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "student not found";
}
bool check_id(struct infoSudent *head, int id)
{
    struct infoSudent *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->student_id == id)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}
// void delete_lession(* head, int lession-id-temp )
// {
//     struct
// }
void shows_student_lessions(struct infoSudent **head, int id)
{
    struct infoSudent *ptr;
    ptr = *head;
    while (ptr != NULL)
    {
        lession *temp = ptr->lession_list;
        if (ptr->student_id == id)
        {
            lession *temp = ptr->lession_list;
            std::cout << ptr->student_id << "\n";
            std::cout << ptr->student_firstname << "\n";
            std::cout << ptr->student_lastname << "\n";
            std::cout << ptr->university_tuition << "\n";
            std::cout << ptr->Amount_of_lessions << "\n";
            for (int i = 0; i < ptr->Amount_of_lessions; i++)
            {
                std::cout << std::endl;
                std::cout << ptr->lession_list->lession_name1 << " ";
                std::cout << ptr->lession_list->lession_name2 << " ";
                std::cout << ptr->lession_list->lession_id << " ";
                std::cout << ptr->lession_list->lession_Coefficient << "\n";
                ptr->lession_list = ptr->lession_list->next;
            }
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "student not found" << std::endl;
}
int index_id(struct infoSudent *head, int id)
{
    struct infoSudent *ptr = head;
    int index = 0;
    while (ptr != NULL)
    {
        if (ptr->student_id == id)
        {
            return index;
        }
        ptr = ptr->next;
        index++;
    }
    return -1;
}
void show_lession_by_id(struct lession *lessionw, int lession_id)
{
    struct lession *ptr = lessionw;
    while (ptr != NULL)
    {
        if (ptr->lession_id == lession_id)
        {
            std::cout << ptr->lession_name1 << " ";
            std::cout << ptr->lession_name2 << " ";
            std::cout << ptr->lession_id << " ";
            std::cout << ptr->lession_Coefficient << " ";
            return;
        }
        ptr = ptr->next;
    }

    std::cout << "lession id is not valid" << std::endl;
}
void edit_student_lession(struct infoSudent *head)
{
    int studentID;
    std::cout << "enter student id" << std::endl;
    std::cin >> studentID;
    if (index_id(head, studentID) == -1)
    {
        std::cout << "student not found" << std::endl;
        return;
    }
    else
    {
        infoSudent *ptr0;
        ptr0 = head;
        while (ptr0 != NULL)
        {
            lession *temp = ptr0->lession_list;
            if (ptr0->student_id == studentID)
            {
                lession *temp = ptr0->lession_list;
                std::cout << ptr0->student_id << "\n";
                std::cout << ptr0->student_firstname << "\n";
                std::cout << ptr0->student_lastname << "\n";
                std::cout << ptr0->university_tuition << "\n";
                std::cout << ptr0->Amount_of_lessions << "\n";
                for (int i = 0; i < ptr0->Amount_of_lessions; i++)
                {
                    std::cout << std::endl;
                    std::cout << temp->lession_name1 << " ";
                    std::cout << temp->lession_name2 << " ";
                    std::cout << temp->lession_id << " ";
                    std::cout << temp->lession_Coefficient << "\n";
                    temp = temp->next;
                }
                break;
            }
            ptr0 = ptr0->next;
        }
        std::cout << "Enter the lession id you want to delete: " << std::endl;
        int lession_id_delete;
        std::cin >> lession_id_delete;
        // lession *temp = head->lession_list;
        // show_lession_by_id(head->lession_list, lession_id_delete);
        struct lession *ptr = head->lession_list;
        while (ptr != NULL)
        {
            if (ptr->lession_id == lession_id_delete)
            {
                std::cout << ptr->lession_name1 << " ";
                std::cout << ptr->lession_name2 << " ";
                std::cout << ptr->lession_id << " ";
                std::cout << ptr->lession_Coefficient << " ";
            }
            ptr = ptr->next;
        }
    }
}
void rewrite(struct infoSudent *head)
{
    std::ofstream outfile("tqrw.txt");
    outfile << "hello mate " << std::endl;
    outfile << Amount_of_students << std::endl;
    struct infoSudent *ptr = head;
    while (ptr != NULL)
    {
        outfile << Amount_of_students;
        outfile << ptr->student_id << "\n";
        outfile << ptr->student_firstname << "\n";
        outfile << ptr->student_lastname << "\n";
        outfile << ptr->university_tuition << "\n";
        outfile << ptr->Amount_of_lessions << "\n";
        lession *temp = ptr->lession_list;
        while (temp != NULL)
        {
            outfile << temp->lession_name1 << " ";
            outfile << temp->lession_name2 << " ";
            outfile << temp->lession_id << " ";
            outfile << temp->lession_Coefficient << "\n";
            temp = temp->next;
        }
        ptr = ptr->next;
    }
}
void add_new_student(struct infoSudent **head)
{
    struct infoSudent *temp = new infoSudent;
    temp->next = NULL;
    temp->lession_list = NULL;
    std::cout << "Enter student's id: ";
    std::cin >> temp->student_id;
    if (check_id == 0)
    {
        std::cout << "Enter student's firstname: ";
        std::cin >> temp->student_firstname;
        std::cout << "Enter student's lastname: ";
        std::cin >> temp->student_lastname;
        std::cout << "Enter student's university tuition: ";
        std::cin >> temp->university_tuition;
        std::cout << "Enter student's Amount of lessions: ";
        std::cin >> temp->Amount_of_lessions;
        add_sudent_at_end(head, temp);
        Amount_of_students++;
        rewrite(*head);
        showaddstudentmenu();
        // add_new_lession(head);
    }
    else
    {
        std::cout << "student already exist";
    }
}
// add_new_lession(structhead)
// {
//     struct lession *temp = new lession;
//     temp->next = NULL;
//     std::cout << "Enter lession's id: ";

// }
infoSudent *Head;
int main()
{
    std::ifstream studentsFile("students.txt");
    studentsFile >> Amount_of_students;
    std::cout << Amount_of_students << std::endl;
    Head = NULL;
    for (int queue = 0; queue < Amount_of_students; queue++)
    {
        infoSudent *student_temp = new infoSudent;
        student_temp->next = NULL;
        student_temp->lession_list = NULL;
        studentsFile >> student_temp->student_id;
        studentsFile >> student_temp->student_firstname;
        studentsFile >> student_temp->student_lastname;
        studentsFile >> student_temp->university_tuition;
        studentsFile >> student_temp->Amount_of_lessions;
        add_sudent_at_end(&Head, student_temp);
        for (int i = 0; i < student_temp->Amount_of_lessions; i++)
        {
            lession *temp = new lession;
            temp->next = 0;
            studentsFile >> temp->lession_name1;
            studentsFile >> temp->lession_name2;
            studentsFile >> temp->lession_id;
            studentsFile >> temp->lession_Coefficient;
            add_lession_at_end(Head, temp, queue);
        }
    }
    showmainmenu();
    int choice;
    rewrite(Head);
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        add_new_student(&Head);
        break;
    case 2:
        edit_student_lession(Head);
        break;
    case 3:

        break;
    case 4:

        break;
    }
}
// void rewrite(struct infoSudent *head)
// {
//     std::ofstream outfile;
//     outfile.open("student.txt");
//     struct infoSudent *ptr = head;
//     while (ptr != NULL)
//     {
//         outfile << Amount_of_students;
//         outfile << ptr->student_id << "\n";
//         outfile << ptr->student_firstname << "\n";
//         outfile << ptr->student_lastname << "\n";
//         outfile << ptr->university_tuition << "\n";
//         outfile << ptr->Amount_of_lessions << "\n";
//         for (int i = 0; i < ptr->Amount_of_lessions; i++)
//         {
//             lession *temp = ptr->lession_list;
//             outfile << std::endl;
//             outfile << temp->lession_name1 << " ";
//             outfile << temp->lession_name2 << " ";
//             outfile << temp->lession_id << " ";
//             outfile << temp->lession_Coefficient << " ";
//             temp = temp->next;
//         }
//         ptr = ptr->next;
//     }
//     outfile.close();
// }