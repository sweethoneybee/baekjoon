#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
    char *studentID;
    char *firstName;
    char *lastName;
}Student;

int list_size = 0;
typedef struct List
{
    Student student;
    struct List *next;
}List;


void insert(Student data, List *L);
void delete(char *id, List *L);
int positionFind(char *id, List *L);
void printList(List *L);
List* makeEmpty();
void deleteList(List *L);

void add(List *L, FILE *fp);
void del(List *L, FILE *fp);
void find(List *L, FILE *fp);
void printing(List *L);

FILE *file_pointer;
FILE *new_file;
int main(void)
{
    file_pointer = fopen("input.txt", "r");
    new_file = fopen("output.txt", "w");
    List *head = makeEmpty();
    char fuc[2];
    while(fscanf(file_pointer, "%s", fuc) != EOF)
    {
        fscanf(file_pointer, "%s", fuc);
        if(fuc[0] == 'i')
        {
            add(head, file_pointer);
        }
        else if(fuc[0] == 'd')
        {
            del(head, file_pointer);
        }
        else if(fuc[0] == 'f')
        {
            find(head, file_pointer);
        }
        else if(fuc[0] == 'p')
        {
            printing(head);
        }
    }
    fclose(file_pointer);
    fclose(new_file);
    deleteList(head);
    system("pause");
    return 0;
}

void insert(Student data, List *L)
{
    List *tmp = L->next;
    List *input = (List*)malloc(sizeof(List));
    input->next = NULL;
    input->student.studentID = (char*)malloc(sizeof(char) * strlen(data.studentID) + 1);
    input->student.firstName = (char*)malloc(sizeof(char) * strlen(data.firstName) + 1);
    input->student.lastName = (char*)malloc(sizeof(char) * strlen(data.lastName) + 1);
    strcpy(input->student.studentID, data.studentID);
    strcpy(input->student.firstName, data.firstName);
    strcpy(input->student.lastName, data.lastName);

    if(tmp == NULL)
    {
        L->next = input;
        tmp = L->next;
        fprintf(new_file, "Insertion Success : %s\n", input->student.studentID);
        fprintf(new_file, "Current List > ");
        fprintf(new_file, "%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        printf("Insertion Success : %s\n", input->student.studentID);
        printf("Current List > ");
        printf("%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        return;
    }

    List *prevTmp;
    prevTmp = L;
    while(tmp->next != NULL && strcmp(tmp->student.studentID, data.studentID) < 0)
    {
        prevTmp = tmp;
        tmp = tmp->next;
    }

    if(strcmp(tmp->student.studentID, data.studentID) == 0)
    {
        fprintf(new_file, "Insertion Failed. ID %s already exists.\n", data.studentID);
        printf("Insertion Failed. ID %s already exists.\n", data.studentID);
        free(input->student.studentID);
        free(input->student.firstName);
        free(input->student.lastName);
        free(input);
        return;
    }


    if(strcmp(tmp->student.studentID, data.studentID) < 0)
    {
        input->next = tmp->next;
        tmp->next = input;
    }
    else if(strcmp(tmp->student.studentID, data.studentID) > 0)
    {
        prevTmp->next = input;
        input->next = tmp;
    }


    
    fprintf(new_file, "Insertion Success : %s\n", input->student.studentID);
    fprintf(new_file, "Current List > ");
    printf("Insertion Success : %s\n", input->student.studentID);
    printf("Current List > ");
    tmp = L->next;
    while(tmp->next != NULL)
    {
        fprintf(new_file, "%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        printf("%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        tmp = tmp->next;
    }
    fprintf(new_file, "%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
    printf("%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
    return;
}
void delete(char *id, List *L)
{
    List *prevTmp = L;
    List *tmp = L->next;
    if(tmp == NULL)
    {
        printf("Deletion Failed. There's no element to delete.\n");
        return;
    }
    while(tmp->next != NULL)
    {
        if(strcmp(tmp->student.studentID, id) == 0)
        {
            prevTmp->next = tmp->next;
            free(tmp->student.studentID);
            free(tmp->student.firstName);
            free(tmp->student.lastName);
            free(tmp);
            fprintf(new_file, "Deletion Success : %s\n", id);
            printf("Deletion Success : %s\n", id);

            tmp = L->next;
            fprintf(new_file, "Current List > ");
            printf("Current List > ");
            while(tmp->next != NULL)
            {
                fprintf(new_file, "%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
                printf("%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
                tmp = tmp->next;
            }
            if(tmp != NULL)
            {
                fprintf(new_file, "%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
                printf("%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
            }
            return;
        }
        prevTmp = tmp;
        tmp = tmp->next;
    }

    if(strcmp(tmp->student.studentID, id) == 0)
    {
        prevTmp->next = NULL;
        free(tmp->student.studentID);
        free(tmp->student.firstName);
        free(tmp->student.lastName);
        free(tmp);
        fprintf(new_file, "Deletion Success : %s\n", id);
        printf("Deletion Success : %s\n", id);
        tmp = L->next;
        fprintf(new_file, "Current List > ");
        printf("Current List > ");
        while(tmp->next != NULL)
        {
            fprintf(new_file, "%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
            printf("%s %s %s-", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
            tmp = tmp->next;
        }
        if(tmp != NULL)
        {
            fprintf(new_file, "%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
            printf("%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        }
        return;
    }
    else
    {
        fprintf(new_file, "Deletion Failed. Student ID %s is not in the list.\n", id);
        printf("Deletion Failed. Student ID %s is not in the list.\n", id);
        return;
    }
}
int positionFind(char *id, List *L)
{
    List *tmp = L->next;
    while(tmp != NULL && strcmp(tmp->student.studentID, id) != 0)
    {
        tmp = tmp->next;
    }

    if(tmp != NULL)
    {
        fprintf(new_file, "Find Success : %s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        printf("Find Success : %s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        return 1;
    }
    else
    {
        fprintf(new_file, "Find %s Failed. There is no student ID\n", id);
        printf("Find %s Failed. There is no student ID\n", id);
        return 0;
    }
}
void printList(List *L)
{
    List* tmp = L->next;
    fprintf(new_file, "-----LIST-----\n");
    printf("-----LIST-----\n");
    while(tmp != NULL)
    {
        fprintf(new_file, "%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        printf("%s %s %s\n", tmp->student.studentID, tmp->student.firstName, tmp->student.lastName);
        tmp = tmp->next;
    }
    fprintf(new_file, "--------------\n");
    printf("--------------\n");
    return;
}

List* makeEmpty()
{
    List *tmp = (List*)malloc(sizeof(List));
    tmp->next = NULL;
    tmp->student.firstName = NULL;
    tmp->student.lastName = NULL;
    tmp->student.studentID = NULL;

    return tmp;
}

void add(List *L, FILE *fp)
{
    Student tmp;
    char id[20];
    char first[30];
    char last[30];
    fscanf(fp, "%s", id);
    fscanf(fp, "%s", first);
    fscanf(fp, "%s", last);

    tmp.studentID = (char*)malloc(sizeof(char) * strlen(id) + 1);
    tmp.firstName = (char*)malloc(sizeof(char) * strlen(first) + 1);
    tmp.lastName = (char*)malloc(sizeof(char) * strlen(last) + 1);
    strcpy(tmp.studentID, id);
    strcpy(tmp.firstName, first);
    strcpy(tmp.lastName, last);

    insert(tmp, L);

    free(tmp.studentID);
    free(tmp.firstName);
    free(tmp.lastName);
    return;
}
void del(List *L, FILE *fp)
{
    char id[20];
    fscanf(fp, "%s", id);

    delete(id, L); 
}
void find(List *L, FILE *fp)
{
    char id[20];
    fscanf(fp, "%s", id);

    positionFind(id, L);
    return;
}
void printing(List *L)
{
    printList(L);
}


void deleteList(List *L)
{
    List *tmp = L;
    if(tmp != NULL)
    {
        deleteList(tmp->next);
        free(tmp->student.studentID);
        free(tmp->student.firstName);
        free(tmp->student.lastName);
        free(tmp);
    }
}