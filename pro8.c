#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int ssn;
    char name[50], dept[20], desg[20];
    float sal;
    unsigned long long int phno;
    struct node *llink, *rlink;
};

struct node *first = NULL, *last = NULL;
int count = 0;

void create();
void insert_front();
void insert_rear();
void display();
void delete_front();
void delete_rear();

int main() {
    int ch;
    while (1) {
        printf("\n1. Create\n2. Insert at Front\n3. Insert at Rear\n4. Display\n5. Delete from Front\n6. Delete from Rear\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                insert_front();
                break;
            case 3:
                insert_rear();
                break;
            case 4:
                display();
                break;
            case 5:
                delete_front();
                break;
            case 6:
                delete_rear();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void create() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->llink = temp->rlink = NULL;
    printf("Enter SSN, Name, Dept, Designation, Salary, and Phone Number: ");
    scanf("%d %s %s %s %f %llu", &temp->ssn, temp->name, temp->dept, temp->desg, &temp->sal, &temp->phno);
    if (first == NULL) {
        first = last = temp;
    } else {
        last->rlink = temp;
        temp->llink = last;
        last = temp;
    }
    count++;
}

void insert_front() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    create();
    if (first == NULL) {
        first = last = temp;
    } else {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    }
}

void insert_rear() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    create();
    if (first == NULL) {
        first = last = temp;
    } else {
        last->rlink = temp;
        temp->llink = last;
        last = temp;
    }
}

void display() {
    struct node *p = first;
    if (p == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("SSN\tName\tDept\tDesignation\tSalary\tPhone\n");
    while (p != NULL) {
        printf("%d\t%s\t%s\t%s\t%.2f\t%llu\n", p->ssn, p->name, p->dept, p->desg, p->sal, p->phno);
        p = p->rlink;
    }
    printf("Total number of employees: %d\n", count);
}

void delete_front() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = first;
    if (first->rlink == NULL) {
        first = last = NULL;
    } else {
        first = first->rlink;
        first->llink = NULL;
    }
    printf("Deleted data: %d\t%s\t%s\t%s\t%.2f\t%llu\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}

void delete_rear() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = last;
    if (first->rlink == NULL) {
        first = last = NULL;
    } else {
        last = last->llink;
        last->rlink = NULL;
    }
    printf("Deleted data: %d\t%s\t%s\t%s\t%.2f\t%llu\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
    free(temp);
    count--;
}
