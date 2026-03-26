#include <stdio.h>
#include <string.h>
struct Employee {
    char name[50];
    char department[50];
    float salary;
};
void getDetails(struct Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);
        printf("Department: ");
        scanf(" %[^\n]", emp[i].department);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
}
void displayDetails(struct Employee emp[], int n) {
    printf("\n--- Employee List ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Name: %s\n", emp[i].name);
        printf("Department: %s\n", emp[i].department);
        printf("Salary: %.2f\n", emp[i].salary);
    }
}
void updateSalary(struct Employee emp[], int n) {
    char searchName[50];
    int found = 0;
    printf("Enter employee name to update salary: ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].name, searchName) == 0) {
            printf("Current Salary: %.2f\n", emp[i].salary);
            printf("Enter new salary: ");
            scanf("%f", &emp[i].salary);
            printf("Salary updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee not found!\n");
    }
}
int main() {
    struct Employee emp[100];
    int n, choice;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    do {
        printf("\n--- MENU ---\n");
        printf("1. Set Employee Details\n");
        printf("2. Display Employee Details\n");
        printf("3. Update Employee Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getDetails(emp, n);
                break;
            case 2:
                displayDetails(emp, n);
                break;
            case 3:
                updateSalary(emp, n);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    return 0;
}