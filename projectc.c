

//   LINKCODE TECHNOLOGY
//   CLASS MANAGEMENT PROJECT
//  -Done by Akash Gulge

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
// user define data type == student
struct student
{

    char name[20];
    char surname[20];
    int std_id;
    int batch;
    long int mobile_no;
    int fees;

};

// Function for password verification
int pass_verification()
{

    char ID[] = "linkcode", password[] = "123456", id[13], p[13];
    int n = 1, x, y;
    printf("\nVerify Your Login ");

    do
    {
        printf("\nName:");
        scanf("%s", &id);

        printf("\nPassword:");
        scanf("%s", &p);
       

        x = strcmp(id, ID);
        y = strcmp(p, password);

        if (x == 0 && y == 0)
        {   
            printf("\n-------------------------------------------------");
            printf("\nSucessfully Logged In");
            break;
        }
        else
        {
            printf("\nWrong Password, try again");

            n++;
        }

        if (n > 3)
        {
            printf("\nAccess Denied ... Maximum Attempt Reached");

            exit(0);
        }

    } while (n <= 3);
    return 0;

}

// Function to add new student
void new_student()
{
    char new;
    FILE *fp;

    struct student newstd;
    do
    {
        printf("\nAdd new student information ");
        fp = fopen("students.txt", "a");
        printf("\n Enter the name of student: ");
        scanf("%s", &newstd.name);
        printf("\n Enter the surname of student: ");
        scanf("%s", &newstd.surname);
        printf("\n Enter the Student ID of student: ");
        scanf("%d", &newstd.std_id);
        printf("\n Enter the Batch of student: ");
        scanf("%d", &newstd.batch);
        printf("\n Enter the mobile no. of student: ");
        scanf("%ld", &newstd.mobile_no);
        printf("\n Enter the fees paid by the student: ");
        scanf("%d", &newstd.fees);

        if (fp == NULL)
        {
            printf("Error\n");
        }

        else
        {
            printf("\n Record Inserted Successfully");
        }

        fwrite(&newstd, sizeof(struct student), 1, fp);
        fclose(fp);

        printf("\nDo you want to add more students? \n If yes press 1 if no press 0\n");
        scanf("%d", &new);

    } while (new == 1);

}

// Function to dispaly records of students
void display_record()
{

    FILE *fp;
    struct student newstd;
    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("Error\n");
    }

    else
    {
        printf("\n Records ");
    }

    while (fread(&newstd, sizeof(struct student), 1, fp))
    {  

        printf("\n-------------------------------------------------");
        printf("\nStudent Name  : %s %s", newstd.name, newstd.surname);
        printf("\nStudent ID    : %d", newstd.std_id);
        printf("\nStudent Batch : %d", newstd.batch);
        printf("\nSMobile Number: %ld", newstd.mobile_no);
        printf("\nSFees Paid    : %d", newstd.fees);
        printf("\n-------------------------------------------------");

    }
    fclose(fp);
}
// Function to delete any records of students
void delete_record()
{

    FILE *fp, *fp1;
    struct student newstd;
    int std_id, ctr = 0;
    fp = fopen("students.txt", "r");
    fp1 = fopen("students2.txt", "w");
    printf("\n Enter the ID of student: ");
    scanf("%d", &std_id);

    if (fp == NULL)
    {
        printf("Error\n");
    }

    while (fread(&newstd, sizeof(struct student), 1, fp))
    {
        if (newstd.std_id == std_id)
        {
            ctr = 1;
        }
        else
        {
            fwrite(&newstd, sizeof(struct student), 1, fp1);
        }

    }
    fclose(fp);
    fclose(fp1);
    if (ctr)
    {
        remove("students.txt");
        rename("students2.txt", "students.txt");
        printf("\nRecord Deleted Sucessfully");
    }
}

//to search any specific student with id
void searchstudent()
{

    FILE *fp;
    struct student newstd;
    int std_id, found = 0;
    fp = fopen("students.txt", "r");
    printf("\n Enter the student id :");
    scanf("%d", &std_id);

    while (fread(&newstd, sizeof(struct student), 1, fp))
    {
        if(newstd.std_id==std_id)
        {
            found=1;
        printf("\n-------------------------------------------------");
        printf("\nStudent Name  : %s %s", newstd.name, newstd.surname);
        printf("\nStudent ID    : %d", newstd.std_id);
        printf("\nStudent Batch : %d", newstd.batch);
        printf("\nSMobile Number: %ld", newstd.mobile_no);
        printf("\nSFees Paid    : %d", newstd.fees);
        printf("\n-------------------------------------------------");
        }
    }

    if(!found){
        printf("/n No such Student with this id ");
    }

    fclose(fp);
}
// main function
int main()

{
    int x, y = 1;
    int ver;
    char password[] = "123456";
    printf("\n-------------------------------------------------");
    printf("\n           Welcome To Link<ode Technologies  ");
    printf("\n-------------------------------------------------");
    ver = pass_verification();
    
    if (ver != 0)
    {
        exit(0);
    }

    do
    {

        int choice;
        printf("\n-------------------------------------------------");
        printf("\n...Choose among following...\n1)Add Student \n2)Display Students Record \n3)Search Student\n4)Remove Student\n5)Exit ");
        printf("\n-------------------------------------------------\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            new_student();
            break;
        case 2:
            display_record();
            break;
        case 3:
            searchstudent();
            break;
        case 4:
            delete_record();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter right choice \n");
            break;
        }
        printf("\n---------------------------xx----------------------");
        printf("\nDo you want more operations? \n If yes press 1 if no press 0\n");
        scanf("%d", &x);
        if (x == 0)
        {
            printf("Thank You");
            printf("\n---------------------------xx----------------------");
        }
        

    } while (x == y);
    return 0;
}
