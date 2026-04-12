#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
    float tax;
    float netSalary;
};

int main() {
    int n, i;

    printf("Enter number of employees:\n ");
    scanf("%d", &n);

    struct Employee emp[n];

    for(i = 0; i < n; i++) {
        printf("\n--- Enter details for Employee %d ---\n", i + 1);

        printf("Enter ID:\n ");
        scanf("%d", &emp[i].id);

        printf("Enter Name:\n ");
        scanf("%s", emp[i].name);

        printf("Enter Basic Salary:\n ");
        scanf("%f", &emp[i].basicSalary);

        // Allowances
        emp[i].hra = 0.20 * emp[i].basicSalary; // 20% HRA
        emp[i].da  = 0.10 * emp[i].basicSalary; // 10% DA

        // Gross Salary
        emp[i].grossSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;

        // Tax Calculation
        if(emp[i].grossSalary > 50000)
            emp[i].tax = 0.10 * emp[i].grossSalary; // 10% tax
        else
            emp[i].tax = 0.05 * emp[i].grossSalary; // 5% tax

        // Net Salary
        emp[i].netSalary = emp[i].grossSalary - emp[i].tax;
    }

    // Display Results
    printf("\n\n===== Employee Payroll Details =====\n");

    for(i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Basic Salary: %.2f\n", emp[i].basicSalary);
        printf("HRA: %.2f\n", emp[i].hra);
        printf("DA: %.2f\n", emp[i].da);
        printf("Gross Salary: %.2f\n", emp[i].grossSalary);
        printf("Tax: %.2f\n", emp[i].tax);
        printf("Net Salary: %.2f\n", emp[i].netSalary);
    }

    return 0;
}
