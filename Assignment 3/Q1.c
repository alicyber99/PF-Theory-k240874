#include <stdio.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining; 
};
void assignValues(struct Employee *emp) {
    printf("Enter Employee Code: ");
    scanf("%d", &emp->employeeCode);
    printf("Enter Employee Name: ");
    scanf("%s", emp->employeeName);
    printf("Enter Date of Joining (YYYYMMDD): ");
    scanf("%d", &emp->dateOfJoining);
}
void calculateTenure(struct Employee emp[], int size) {
    int currentDate;
    printf("Enter Current Date (YYYYMMDD): ");
    scanf("%d", &currentDate);   
    int count = 0;
    printf("Employees with tenure more than three years:\n");
    for (int i = 0; i < size; i++) {
        int tenure = (currentDate - emp[i].dateOfJoining) / 10000;
        if (tenure > 3) {
            printf("Employee Code: %d, Name: %s, Date of Joining: %d\n", emp[i].employeeCode, emp[i].employeeName, emp[i].dateOfJoining);
            count++;
        }
    }
    printf("Total number of employees with tenure more than three years: %d\n", count);
}
int main() {
    struct Employee employees[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        assignValues(&employees[i]);
    }
    calculateTenure(employees, 4);
    return 0;
}

