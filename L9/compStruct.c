#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMP (struct employee)
#define PAD {'0', '0', '0'}

// Struct for Employees
struct employee
{
    char name[20];
    int salary;
    bool isJunior;
    char pad[3]; // total 28 byets 
};

void printEmployee(const struct employee);

int main(void)
{
    //Printing Employee Details
    printEmployee(EMP{"Sami", 400000, false, PAD});
    printEmployee(EMP{"Armaan", 400000, false, PAD});
    printEmployee(EMP{"Btw Arch", 50000, true, PAD});

    return EXIT_SUCCESS;
}

void printEmployee(const struct employee emp)
{
    printf("Name: %.19s\nSalary: %i\nIsJunior: %s\n\n",
        emp.name, 
        emp.salary, 
        (emp.isJunior) ? "True" : "False"
    );
}
