#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstddef>
#include <conio.h>
int Amount_of_students = 0;
const int tuition_per_coefficient = 1000;
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
void rewrite(struct infoSudent *head)
{
    std::ofstream outfile("students.txt");
    outfile << Amount_of_students << std::endl;
    struct infoSudent *ptr = head;
    while (ptr != NULL)
    {
        outfile << ptr->student_id << "\n";
        outfile << ptr->student_firstname << " ";
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
int tuition(infoSudent head, int student_id)
{
    int tuition = 0;
    infoSudent *ptr = &head;
    while (ptr != NULL)
    {
        if (ptr->student_id == student_id)
        {
            lession *temp = ptr->lession_list;

            if (temp == NULL)
            {
                return 0;
            }
            else
            {
                while (temp != NULL)
                {
                    tuition += temp->lession_Coefficient * tuition_per_coefficient;
                    temp = temp->next;
                }
            }
            return tuition;
        }
        ptr = ptr->next;
    }
    return tuition;
}
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
void add_lession_at_end(struct infoSudent **head, struct lession *temp, int queue)
{
    infoSudent *temp1 = *head;
    for (int i = 0; i < queue; i++)
    {
        temp1 = temp1->next;
    }
    temp1->Amount_of_lessions += 1;
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
    Amount_of_students++;
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

            lession *temp = ptr->lession_list;
            std::cout << ptr->student_id << " ";
            std::cout << ptr->student_firstname << " ";
            std::cout << ptr->student_lastname << " ";
            std::cout << ptr->university_tuition << " ";
            std::cout << ptr->Amount_of_lessions << " ";
            while (temp != NULL)
            {
                std::cout << std::endl;
                std::cout << temp->lession_name1 << " ";
                std::cout << temp->lession_name2 << " ";
                std::cout << temp->lession_id << " ";
                std::cout << temp->lession_Coefficient << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "student not found\n";
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
void delete_lession_by_id(struct lession **head_ref, int id)
{
    struct lession *temp = *head_ref, *prev;
    if (temp != NULL && temp->lession_id == id)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Find the id to be deleted
    while (temp != NULL && temp->lession_id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    // If the id is not present
    if (temp == NULL)
        return;
    // Remove the node
    prev->next = temp->next;
    free(temp);
}
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
        show_lession_by_id(ptr0->lession_list, lession_id_delete);
        bool confirm = false;
        std::cout << "\nAre you sure you want to delete this lession?" << std::endl;
        std::cout << "1. Yes" << std::endl;
        std::cout << "2. No" << std::endl;
        std::cin >> confirm;
        if (confirm == 1)
        {
            delete_lession_by_id(&ptr0->lession_list, lession_id_delete);
            ptr0->Amount_of_lessions--;
            ptr0->university_tuition = tuition(*head, studentID);
            rewrite(head);
        }
        else
        {
            return;
        }
    }
}
void show_student_lessions(struct infoSudent *head)
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
    }
}
void add_new_lession(struct infoSudent *head, struct infoSudent *node)
{
    struct lession *temp = new lession;
    temp->next = NULL;
    std::cout << "Enter lession's id: ";
    std::cin >> temp->lession_id;
    std::cout << "Enter lession's name1: ";
    std::cin >> temp->lession_name1;
    std::cout << "Enter lession's name2: ";
    std::cin >> temp->lession_name2;
    std::cout << "Enter lession's Coefficient: ";
    std::cin >> temp->lession_Coefficient;
    add_lession_at_end(&head, temp, index_id(head, node->student_id));
}
void add_new_student(struct infoSudent **head)
{
    struct infoSudent *temp = new infoSudent;
    temp->next = NULL;
    temp->lession_list = NULL;
    std::cout << "Enter student's id: ";
    std::cin >> temp->student_id;
    if (check_id(*head, temp->student_id) == 0)
    {
        std::cout << "Enter student's firstname: ";
        std::cin >> temp->student_firstname;
        std::cout << "Enter student's lastname: ";
        std::cin >> temp->student_lastname;
        temp->university_tuition = tuition(**head, temp->student_id);
        temp->Amount_of_lessions = 0;
        add_sudent_at_end(head, temp);
        rewrite(*head);
        int choice = 0;
        while (choice != 2)
        {
            showaddstudentmenu();
            std::cin >> choice;
            if (choice == 1)
            {
                add_new_lession(*head, temp);
                temp->university_tuition = tuition(**head, temp->student_id);
                rewrite(*head);
            }
        }
    }
    else
    {
        std::cout << "student already exist" << std::endl;
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
    Head = NULL;
    int temp_Amount_of_students = Amount_of_students;
    for (int queue = 0; queue < temp_Amount_of_students; queue++)
    {
        infoSudent *student_temp = new infoSudent;
        student_temp->next = NULL;
        student_temp->lession_list = NULL;
        studentsFile >> student_temp->student_id;
        studentsFile >> student_temp->student_firstname;
        studentsFile >> student_temp->student_lastname;
        studentsFile >> student_temp->university_tuition;
        studentsFile >> student_temp->Amount_of_lessions;
        int temp = student_temp->Amount_of_lessions;
        student_temp->Amount_of_lessions = 0;
        add_sudent_at_end(&Head, student_temp);
        for (int i = 0; i < temp; i++)
        {
            lession *temp = new lession;
            temp->next = 0;
            studentsFile >> temp->lession_name1;
            studentsFile >> temp->lession_name2;
            studentsFile >> temp->lession_id;
            studentsFile >> temp->lession_Coefficient;
            add_lession_at_end(&Head, temp, queue);
        }
    }
    Amount_of_students -= temp_Amount_of_students;
    int choice = 0;
    while (choice != 4)
    {
        showmainmenu();
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
            std::cout << "Enter student's id: \n";
            int id;
            std::cin >> id;
            showStudentinfo(Head, id);
            getch();
            break;
        case 4:
            return 0;
        }
    }
}
