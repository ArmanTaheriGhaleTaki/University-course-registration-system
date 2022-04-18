#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
const int tuition_per_coefficient = 1000;
struct lession
{
    std::string lession_name1;
    std::string lession_name2;
    int lession_id;
    int lession_Coefficient;
    struct lession *next;
};
struct infoStudent
{
    int student_id;
    std::string student_firstname;
    std::string student_lastname;
    int university_tuition;
    int Amount_of_lessions;
    lession *lession_list;
    infoStudent *next;
};
void show_lession_by_id(struct lession *lessionw, int lession_id)
{
    struct lession *ptr = lessionw;
    while (ptr != NULL)
    {
        if (ptr->lession_id == lession_id)
        {
            std::cout << ptr->lession_name1 << " ";
            std::cout << ptr->lession_id << " ";
            std::cout << ptr->lession_Coefficient << " ";
            return;
        }
        ptr = ptr->next;
    }

    std::cout << "lession id is not valid" << std::endl;
}
void rewrite(struct infoStudent *head, int &Amount_of_students)
{
    std::ofstream outfile("students.txt");
    outfile << Amount_of_students << std::endl;
    struct infoStudent *ptr = head;
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
void delete_lession_by_id(struct lession **head_ref, int id)
{
    struct lession *temp = *head_ref, *prev;
    if (temp != NULL && temp->lession_id == id)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->lession_id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}
int tuition(infoStudent head, int student_id)
{
    int tuition = 0;
    infoStudent *ptr = &head;
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

int index_id(struct infoStudent *head, int id)
{
    struct infoStudent *ptr = head;
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
void add_lession_at_end(struct infoStudent **head, struct lession *temp, int queue)
{
    infoStudent *temp1 = *head;
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
void add_student_at_end(struct infoStudent **head, struct infoStudent *temp, int &Amount_of_students)
{
    Amount_of_students++;
    if (*head == 0)
    {
        *head = temp;
    }
    else
    {
        infoStudent *temp2 = *head;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}
void add_new_lession(struct infoStudent *head, struct infoStudent *node)
{
    system("cls");
    struct lession *temp = new lession;
    temp->next = NULL;
    std::cout << "Enter lession's id: ";
    std::cin >> temp->lession_id;
    std::cout << "Enter lession's : ";
    getline(std::cin, temp->lession_name1);
    temp->lession_name2="";
    std::cout << "Enter lession's Coefficient: ";
    std::cin >> temp->lession_Coefficient;
    add_lession_at_end(&head, temp, index_id(head, node->student_id));
}
bool check_id(struct infoStudent *head, int id)
{
    struct infoStudent *ptr;
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
void edit_student_lession(struct infoStudent *head, int &Amount_of_students)
{
    system("cls");
    int studentID;
    std::cout << "enter student id" << std::endl;
    std::cin >> studentID;
    if (index_id(head, studentID) == -1)
    {
        std::cout << "student not found" << std::endl;
        getch();
        system("cls");
        return;
    }
    else
    {
        int choice = 0;
        while (choice != 3)
        {
            infoStudent *ptr0;
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
                        std::cout << temp->lession_id << " ";
                        std::cout << temp->lession_Coefficient << "\n";
                        temp = temp->next;
                    }
                    break;
                }
                ptr0 = ptr0->next;
            }
            std::cout << "1. delete lession \n";
            std::cout << "2. add lession \n";
            std::cout << "3. back to menu \n";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::cout << "Enter the lession id you want to delete: " << std::endl;
                int lession_id_delete;
                std::cin >> lession_id_delete;
                system("cls");
                show_lession_by_id(ptr0->lession_list, lession_id_delete);
                bool confirm = false;
                std::cout << "\nAre you sure you want to delete this lession?" << std::endl;
                std::cout << "1. Yes" << std::endl;
                std::cout << "2. No" << std::endl;
                std::cin >> confirm;
                if (confirm == 1)
                {
                    show_lession_by_id(ptr0->lession_list, lession_id_delete);
                    std::cout << "lession deleted" << std::endl;
                    getch();
                    system("cls");
                    delete_lession_by_id(&ptr0->lession_list, lession_id_delete);
                    ptr0->Amount_of_lessions--;
                    ptr0->university_tuition = tuition(*head, studentID);
                    rewrite(head, Amount_of_students);
                }
                system("cls");
                break;
            }
            case 2:
            {
                add_new_lession(head, ptr0);
                ptr0->university_tuition = tuition(*head, ptr0->student_id);
                rewrite(head, Amount_of_students);
                break;
            }
            case 3:
            {
                system("cls");
                break;
            }
            }
        }
    }
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
    system("cls");
    std::cout << "1. Add new lession" << std::endl;
    std::cout << "2. back to main menu" << std::endl;
}
void display(struct infoStudent *head)
{
    struct infoStudent *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        std::cout << ptr->student_id << " ";
        ptr = ptr->next;
    }
}
void showStudentinfo(struct infoStudent *head, int id)
{
    system("cls");
    struct infoStudent *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->student_id == id)
        {
            lession *temp = ptr->lession_list;
            std::cout << ptr->student_id << "\n";
            std::cout << ptr->student_firstname << " ";
            std::cout << ptr->student_lastname << "\n";
            std::cout << ptr->university_tuition << "\n";
            std::cout << ptr->Amount_of_lessions << "\n";
            while (temp != NULL)
            {
                std::cout << temp->lession_name1 << " ";
                std::cout << temp->lession_id << " ";
                std::cout << temp->lession_Coefficient << "\n";
                temp = temp->next;
            }
            std::cout << std::endl;
            getch();
            system("cls");
            return;
        }
        ptr = ptr->next;
    }
    std::cout << "student not found\n";
    getch();
    system("cls");
}
void add_new_student(struct infoStudent **head, int &Amount_of_students)
{
    system("cls");
    struct infoStudent *temp = new infoStudent;
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
        add_student_at_end(head, temp, Amount_of_students);
        rewrite(*head, Amount_of_students);
        std::cout << "Student added successfully\n";
        getch();
        system("cls");
        int choice = 0;
        while (choice != 2)
        {
            showaddstudentmenu();
            std::cin >> choice;
            system("cls");
            if (choice == 1)
            {
                add_new_lession(*head, temp);
                std::cout << "lession added successfully\n";
                getch();
                system("cls");
                temp->university_tuition = tuition(**head, temp->student_id);
                rewrite(*head, Amount_of_students);
            }
        }
    }
    else
    {
        std::cout << "student already exist" << std::endl;
        getch();
        system("cls");
    }
    system("cls");
}