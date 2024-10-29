#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for Student Record 📋
struct Student {
    int id;
    char name[50];
    int age;
    char address[100];
    float grade;
};

// Maximum number of students 📝
#define MAX_STUDENTS 100

// Array of students and count
struct Student students[MAX_STUDENTS];
int student_count = 0;

// Function Prototypes 🎯
void addStudent();
void deleteStudent();
void updateStudent();
void displayStudents();
void searchStudent();
void saveToFile();
void loadFromFile();
void sortByName();
void sortByGrade();
void printLine(char symbol, int length);

// Welcome Message by Valilian Peterson Mwendwa 🌟
void displayWelcomeMessage() {
    printLine('=', 40);
    printf("🎓 Welcome to the Student Record System! 📚\n");
    printf("     Developed by Valilian Peterson Mwendwa ✨\n");
    printLine('=', 40);
}

// Print a Line Divider
void printLine(char symbol, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

// Main Menu 🛠️
void menu() {
    int choice;
    while (1) {
        printf("\n⚙️ Main Menu:\n");
        printf("1️⃣ Add Student Record ➕\n");
        printf("2️⃣ Delete Student Record 🗑️\n");
        printf("3️⃣ Update Student Record ✏️\n");
        printf("4️⃣ Display All Students 📋\n");
        printf("5️⃣ Search Student Record 🔍\n");
        printf("6️⃣ Sort Records by Name 🔤\n");
        printf("7️⃣ Sort Records by Grade 📊\n");
        printf("8️⃣ Save Records to File 💾\n");
        printf("9️⃣ Load Records from File 📂\n");
        printf("0️⃣ Exit 🚪\n");
        printf("👉 Enter your choice (0-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: displayStudents(); break;
            case 5: searchStudent(); break;
            case 6: sortByName(); break;
            case 7: sortByGrade(); break;
            case 8: saveToFile(); break;
            case 9: loadFromFile(); break;
            case 0: printf("👋 Goodbye! Thanks for using the Student Record System! 🌟\n"); exit(0);
            default: printf("⚠️ Invalid choice. Please try again. 🙅‍♂️\n"); break;
        }
    }
}

// Function to Add a Student Record ➕
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("⚠️ Student list is full! Cannot add more students. 😞\n");
        return;
    }

    struct Student newStudent;
    printf("\n🆕 Adding New Student Record:\n");
    newStudent.id = student_count + 1; // Auto-generate ID
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Address: ");
    scanf(" %[^\n]", newStudent.address);
    printf("Enter Grade (0.0 - 100.0): ");
    scanf("%f", &newStudent.grade);

    students[student_count++] = newStudent;
    printf("✅ Student Added Successfully! 🎉\n");
}

// Function to Delete a Student Record 🗑️
void deleteStudent() {
    int id, found = 0;
    printf("\n🗑️ Delete Student Record:\n");
    printf("👉 Enter Student ID to Delete: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("✅ Student Record Deleted Successfully! 🎯\n");
            break;
        }
    }
    if (!found) printf("⚠️ Student ID Not Found! 😕\n");
}

// Function to Update a Student Record ✏️
void updateStudent() {
    int id, found = 0;
    printf("\n✏️ Update Student Record:\n");
    printf("👉 Enter Student ID to Update: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("🔄 Updating Record for %s:\n", students[i].name);
            printf("Enter New Name (or press Enter to keep current): ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter New Age: ");
            scanf("%d", &students[i].age);
            printf("Enter New Address: ");
            scanf(" %[^\n]", students[i].address);
            printf("Enter New Grade (0.0 - 100.0): ");
            scanf("%f", &students[i].grade);
            printf("✅ Student Record Updated Successfully! 🎯\n");
            break;
        }
    }
    if (!found) printf("⚠️ Student ID Not Found! 😕\n");
}

// Function to Display All Students 📋
void displayStudents() {
    printf("\n📋 Student Records:\n");
    printLine('-', 50);
    printf("| ID | Name                | Age | Address          | Grade |\n");
    printLine('-', 50);
    for (int i = 0; i < student_count; i++) {
        printf("| %2d | %-18s | %3d | %-15s | %5.2f |\n",
               students[i].id, students[i].name, students[i].age,
               students[i].address, students[i].grade);
    }
    printLine('-', 50);
}

// Function to Search Student Record 🔍
void searchStudent() {
    char name[50];
    printf("\n🔍 Search Student Record:\n");
    printf("👉 Enter Student Name to Search: ");
    scanf(" %[^\n]", name);

    printf("\n📋 Search Results:\n");
    printLine('-', 50);
    for (int i = 0; i < student_count; i++) {
        if (strstr(students[i].name, name)) {
            printf("| %2d | %-18s | %3d | %-15s | %5.2f |\n",
                   students[i].id, students[i].name, students[i].age,
                   students[i].address, students[i].grade);
        }
    }
    printLine('-', 50);
}

// Function to Save Records to File 💾
void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("⚠️ Error saving records to file! 💥\n");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%d,%s,%d,%s,%.2f\n",
                students[i].id, students[i].name, students[i].age,
                students[i].address, students[i].grade);
    }
    fclose(file);
    printf("✅ Records Saved to 'students.txt'. 💾\n");
}

// Function to Load Records from File 📂
void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("⚠️ No Saved Records Found! 📂\n");
        return;
    }

    student_count = 0;
    while (fscanf(file, "%d,%[^,],%d,%[^,],%f\n",
                  &students[student_count].id, students[student_count].name,
                  &students[student_count].age, students[student_count].address,
                  &students[student_count].grade) == 5) {
        student_count++;
    }
    fclose(file);
    printf("✅ Records Loaded Successfully from 'students.txt'. 📂\n");
}

// Function to Sort Records by Name 🔤
void sortByName() {
    struct Student temp;
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("✅ Records Sorted by Name! 🔤\n");
}

// Function to Sort Records by Grade 📊
void sortByGrade() {
    struct Student temp;
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].grade < students[j].grade) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("✅ Records Sorted by Grade! 📊\n");
}

// Main Function 🚀
int main() {
    displayWelcomeMessage();
    loadFromFile();
    menu();
    return 0;
}
