// SO Finally I can say The Code is Readyyyyy🐧🎉😎🤩.....

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h> // For sleep function

/*----------------------------------------------------------
    Color Macros
----------------------------------------------------------*/
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_MAGENTA "\033[0;35m"
#define COLOR_CYAN "\033[0;36m"
#define COLOR_BOLD "\033[1m"
// ANSI Escape Codes for Colors and Styles
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"

/*----------------------------------------------------------
    Constants
----------------------------------------------------------*/
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define MAX_RECORDS 100
#define MAX_FACULTY 50
#define MAX_STUDENTS 100
#define MAX_USERS 10

/*----------------------------------------------------------
    Structures
----------------------------------------------------------*/
struct User
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char role[20]; // e.g., "admin", "faculty"
};

struct Student
{
    char studentId[20];
    char name[50];
};

struct Attendance
{
    char faculty[50];
    char studentId[20];
    char name[50];
    char date[20];
    char time[10];
    char status;
};

/*----------------------------------------------------------
    Global Variables
----------------------------------------------------------*/
struct User users[MAX_USERS];
int userCount = 0;

struct Student students[MAX_STUDENTS];
int studentCount = 0;

struct Attendance records[MAX_RECORDS];
int recordCount = 0;

/* Global to hold the logged-in user */
char currentUser[MAX_USERNAME] = "";

/*----------------------------------------------------------
    Function Declarations
----------------------------------------------------------*/
void loadDefaultUsers();
int loadUsersFromFile();
void saveUsersToFile();
int login();
void registerUser();
void addStudents();
void takeBatchAttendance();
void viewAttendance();
void searchByDate();
void searchByStudent();
void generateReport();
void editAttendance();
void deleteAttendance();
void displayJSONData();
void saveToJSONFile(struct Attendance records[], int count); // legacy function
int loadFromJSONFile(struct Attendance records[]);           // legacy function
void saveFacultyJSONFile(const char *faculty, struct Attendance records[], int totalCount, const char *user);
int loadFacultyAttendance(const char *faculty, struct Attendance recordsOut[]);
void clearInputBuffer();
void getCurrentDateTime(char *date, char *currentTime);
void displayMenu();
float calculateAttendancePercentage(char *studentId);
void saveStudentsToFile();
int loadStudentsFromFile();
// Forward declarations
void startAdventure();
void forestPath();
void castlePath();
void cavePath();
void villagePath();
void mountainPath();
void riverPath();
void gameOver();
void victory();
// Utility functions to clear screen and wait for Enter
void clearScreen()
{
    system("cls"); // For Windows; use "clear" for Linux/macOS
}

void pauseForKey()
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ; // Wait until Enter is pressed
}

void loading()
{
    printf(YELLOW "\nReaching There...");
    for (int i = 0; i < 3; i++)
    {
        printf(". ");
        fflush(stdout);
        sleep(1); // Sleep for 1 second
    }
    printf(RESET "\n");
}
void startAdventure()
{
    int choice;
    clearScreen();
    printf(YELLOW BOLD "\n=== Realm of Mysteries ===\n" RESET);
    printf(BLUE "\nYou stand at a mystical crossroads. Which path will you take?\n" RESET);
    printf(GREEN " 1. Jungle maa aghi badhnus (Venture into the Enchanted Forest)\n" RESET);
    printf(MAGENTA " 2. Killa ko najik janu (Approach the Ancient Castle)\n" RESET);
    printf(CYAN " 3. Gupha bhitra pasnu (Explore the Dark Cave)\n" RESET);
    printf(YELLOW " 4. Gaun tira janu (Visit the Friendly Village)\n" RESET);
    printf(GREEN " 5. Danda chadhnu (Climb the Majestic Mountain)\n" RESET);
    printf(MAGENTA " 6. Sital Nadi ko bato apnanu (Follow the Serene River)\n" RESET);

    printf(YELLOW "\nEnter your choice (1-6): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ; // clear invalid input
        choice = 0;
    }
    while (getchar() != '\n')
        ; // flush remaining input

    loading(); // Display loading effect

    switch (choice)
    {
    case 1:
        forestPath();
        break;
    case 2:
        castlePath();
        break;
    case 3:
        cavePath();
        break;
    case 4:
        villagePath();
        break;
    case 5:
        mountainPath();
        break;
    case 6:
        riverPath();
        break;
    default:
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        startAdventure();
    }
}

void forestPath()
{
    int choice;
    clearScreen();
    printf(GREEN BOLD "\n--- Enchanted Forest ---\n" RESET);
    printf(GREEN "\nIn the forest, you see a sparkling stream and a glowing tree.\n" RESET);
    printf(YELLOW " 1. Drink from the stream\n" RESET);
    printf(CYAN " 2. Approach the tree\n" RESET);
    printf(YELLOW " 3. Follow the mysterious sound\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n✨ The water grants you mystical insight!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(RED "\n⚠️ A trap is triggered! Poison darts strike you!\n" RESET);
        pauseForKey();
        gameOver();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(CYAN "\n🔍 You discover a hidden treasure chest!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        forestPath();
    }
}

void castlePath()
{
    int choice;
    clearScreen();
    printf(MAGENTA BOLD "\n--- Ancient Castle ---\n" RESET);
    printf(MAGENTA "\nAt the castle, two doors beckon: one faded, one mysterious.\n" RESET);
    printf(YELLOW " 1. Enter the left door\n" RESET);
    printf(CYAN " 2. Open the right door\n" RESET);
    printf(YELLOW " 3. Climb to the castle tower\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n🎉 You uncover ancient treasures and wisdom!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(RED "\n🔥 A curse awakens a dragon, and you are incinerated!\n" RESET);
        pauseForKey();
        gameOver();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(CYAN "\n🏰 You find a magical artifact in the tower!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        castlePath();
    }
}

void cavePath()
{
    int choice;
    clearScreen();
    printf(CYAN BOLD "\n--- Dark Cave ---\n" RESET);
    printf(CYAN "\nWithin the cave, a glowing artifact and a narrow passage await.\n" RESET);
    printf(YELLOW " 1. Take the artifact\n" RESET);
    printf(MAGENTA " 2. Enter the passage\n" RESET);
    printf(YELLOW " 3. Search for hidden passages\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n💫 The artifact empowers you with magic!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(RED "\n🌀 Lost in the labyrinth of tunnels, darkness consumes you.\n" RESET);
        pauseForKey();
        gameOver();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(CYAN "\n🔦 You find a secret passage leading to freedom!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        cavePath();
    }
}

void villagePath()
{
    int choice;
    clearScreen();
    printf(GREEN BOLD "\n--- Friendly Village ---\n" RESET);
    printf(GREEN "\nIn the village, friendly villagers offer you food and shelter.\n" RESET);
    printf(YELLOW " 1. Share a meal with the villagers\n" RESET);
    printf(CYAN " 2. Ask for directions to the next adventure\n" RESET);
    printf(YELLOW " 3. Trade items with the merchant\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n🍲 The meal restores your strength!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(CYAN "\n🗺️ The villagers give you valuable information about hidden treasures!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(MAGENTA "\n🛍️ You successfully trade for a magical item!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        villagePath();
    }
}

void mountainPath()
{
    int choice;
    clearScreen();
    printf(MAGENTA BOLD "\n--- Majestic Mountain ---\n" RESET);
    printf(MAGENTA "\nThe mountain presents a steep climb and breathtaking views.\n" RESET);
    printf(YELLOW " 1. Climb to the peak\n" RESET);
    printf(CYAN " 2. Look for hidden caves\n" RESET);
    printf(YELLOW " 3. Meditate at the summit\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n🏔️ You reach the peak and are rewarded with a view of a lifetime!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(CYAN "\n🕳️ You discover a hidden cave filled with treasures!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(YELLOW "\n🧘 You gain clarity and strength from the peaceful summit!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        mountainPath();
    }
}

void riverPath()
{
    int choice;
    clearScreen();
    printf(CYAN BOLD "\n--- Serene River ---\n" RESET);
    printf(CYAN "\nThe river flows gently, offering opportunities for exploration.\n" RESET);
    printf(YELLOW " 1. Go fishing\n" RESET);
    printf(MAGENTA " 2. Build a raft\n" RESET);
    printf(CYAN " 3. Search for river stones\n" RESET);
    printf(YELLOW "\nEnter choice (1-3): " RESET);

    if (scanf("%d", &choice) != 1)
    {
        while (getchar() != '\n')
            ;
        choice = 0;
    }
    while (getchar() != '\n')
        ;

    loading(); // Display loading effect

    if (choice == 1)
    {
        clearScreen();
        printf(GREEN "\n🎣 You catch a magical fish that grants you wishes!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 2)
    {
        clearScreen();
        printf(CYAN "\n🛶 You build a sturdy raft and float downstream safely!\n" RESET);
        pauseForKey();
        victory();
    }
    else if (choice == 3)
    {
        clearScreen();
        printf(MAGENTA "\n💎 You discover sparkling river stones that are worth a fortune!\n" RESET);
        pauseForKey();
        victory();
    }
    else
    {
        printf(RED "\n❌ Invalid choice! Try again.\n" RESET);
        pauseForKey();
        riverPath();
    }
}

void gameOver()
{
    char playAgain;
    printf(RED BOLD "\n=== GAME OVER ===\n" RESET);
    printf(RED "\nYour adventure ends in tragedy.\n" RESET);
    printf(YELLOW "\nNaya sahasik katha khelna chahanu huncha? (y/n): " RESET);
    scanf(" %c", &playAgain);
    while (getchar() != '\n')
        ;
    if (playAgain == 'y' || playAgain == 'Y')
    {
        startAdventure();
    }
    else
    {
        printf(YELLOW "\nFarewell, Brave Adventurer.\n" RESET);
        exit(0);
    }
}

void victory()
{
    char playAgain;
    printf(GREEN BOLD "\n=== VICTORY! ===\n" RESET);
    printf(GREEN "\n🎉 Victory! You conquered the adventure like a true hero! Now go grab a snack. 🍕😆\n" RESET);
    printf(YELLOW "\nYou survived this time. But can you do it again? (y/n): " RESET);
    scanf(" %c", &playAgain);
    while (getchar() != '\n')
        ;
    if (playAgain == 'y' || playAgain == 'Y')
    {
        startAdventure();
    }
    else
    {
        printf(YELLOW "\nMay your legends endure, Adventurer.\n" RESET);
        printf(CYAN "\nGame over… but don’t worry, the ghosts will miss you! \n" RESET);
        exit(0);
    }
}

/*----------------------------------------------------------
    Main Function
----------------------------------------------------------*/
int main()
{
    int choice;
    char initialChoice;

    /* Attempt to load persisted users */
    userCount = loadUsersFromFile();
    if (userCount == 0)
    {
        /* No persisted users found; load default admin */
        loadDefaultUsers();
        saveUsersToFile();
    }

    /* Optionally, allow registration of a new user */
    printf(COLOR_YELLOW "Do you want to register a new user? (Y/N): " COLOR_RESET);
    scanf(" %c", &initialChoice);
    clearInputBuffer();
    if (toupper(initialChoice) == 'Y')
    {
        registerUser();
        saveUsersToFile();
    }

    /* Multi-user login */
    if (!login())
    {
        printf("\n" COLOR_RED "[ X ] Login failed! Program terminating." COLOR_RESET "\n");
        return 1;
    }

    /* Ask if user wants to load attendance records for a specific faculty */
    char loadChoice;
    printf(COLOR_YELLOW "\nDo you want to load attendance records for a faculty? (Y/N): " COLOR_RESET);
    scanf(" %c", &loadChoice);
    clearInputBuffer();
    if (toupper(loadChoice) == 'Y')
    {
        char facultyToLoad[MAX_FACULTY];
        printf(COLOR_YELLOW "Enter Faculty/Department name to load: " COLOR_RESET);
        scanf(" %[^\n]s", facultyToLoad);
        clearInputBuffer();
        recordCount = loadFacultyAttendance(facultyToLoad, records);
        if (recordCount > 0)
            printf(COLOR_GREEN "\nLoaded %d attendance record(s) for faculty %s from file.\n" COLOR_RESET, recordCount, facultyToLoad);
        else
            printf(COLOR_YELLOW "\nNo attendance records found for faculty %s. Starting fresh.\n" COLOR_RESET, facultyToLoad);
    }
    else
    {
        recordCount = 0;
    }

    /* Load students from file */
    studentCount = loadStudentsFromFile();
    if (studentCount > 0)
    {
        printf(COLOR_GREEN "\nLoaded %d student(s) from file.\n" COLOR_RESET, studentCount);
    }

    /* Display welcome banner */
    printf("\n" COLOR_CYAN "+--------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "|  Welcome to the Attendance Management Sys  |\n" COLOR_RESET);
    printf(COLOR_CYAN "|         Multi-user Enabled!                |\n" COLOR_RESET);
    printf(COLOR_CYAN "+--------------------------------------------+\n" COLOR_RESET);

    while (1)
    {
        displayMenu();
        printf(COLOR_YELLOW "\n-> Enter your choice: " COLOR_RESET);
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudents();
            break;
        case 2:
            takeBatchAttendance();
            break;
        case 3:
            viewAttendance();
            break;
        case 4:
            searchByDate();
            break;
        case 5:
            searchByStudent();
            break;
        case 6:
            generateReport();
            break;
        case 7:
            editAttendance();
            break;
        case 8:
            deleteAttendance();
            break;
        case 9:
            displayJSONData();
            break;
        case 10:
            printf("\n" COLOR_GREEN "[ ^_^ ] Thank you for using the system! Have an awesome day!\n" COLOR_RESET);
            return 0;
        case 11:
            startAdventure();
            break;
        default:
            printf("\n" COLOR_RED "[ ! ] Invalid choice! Please try again.\n" COLOR_RESET);
        }
    }
    return 0;
}
/*----------------------------------------------------------
    User Persistence Functions
----------------------------------------------------------*/

/**
 * Load default users into the system.
 */
void loadDefaultUsers()
{
    /* Create a default admin user */
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin");
    strcpy(users[0].role, "admin");
    userCount = 1;
}

void displayJSONData()
{
    printf("\n" COLOR_YELLOW "[\n" COLOR_RESET);
    for (int i = 0; i < recordCount; i++)
    {
        printf("  {\n");
        printf("    \"faculty\": \"%s\",\n", records[i].faculty);
        printf("    \"studentId\": \"%s\",\n", records[i].studentId);
        printf("    \"name\": \"%s\",\n", records[i].name);
        printf("    \"date\": \"%s\",\n", records[i].date);
        printf("    \"time\": \"%s\",\n", records[i].time);
        printf("    \"status\": \"%c\"\n", records[i].status);
        if (i == recordCount - 1)
            printf("  }\n");
        else
            printf("  },\n");
    }
    printf("]\n");
}

/**
 * Save the user array to a JSON file (users.json).
 */
void saveUsersToFile()
{
    FILE *file = fopen("users.json", "w");
    if (file == NULL)
    {
        printf("\n" COLOR_RED "[ ! ] Error opening users file for saving data!" COLOR_RESET "\n");
        return;
    }
    fprintf(file, "[\n");
    for (int i = 0; i < userCount; i++)
    {
        fprintf(file, "  {\n");
        fprintf(file, "    \"username\": \"%s\",\n", users[i].username);
        fprintf(file, "    \"password\": \"%s\",\n", users[i].password);
        fprintf(file, "    \"role\": \"%s\"\n", users[i].role);
        if (i == userCount - 1)
            fprintf(file, "  }\n");
        else
            fprintf(file, "  },\n");
    }
    fprintf(file, "]\n");
    fclose(file);
}

/**
 * Load users from the JSON file (users.json) into the users array.
 * Returns the number of users loaded.
 */
int loadUsersFromFile()
{
    FILE *file = fopen("users.json", "r");
    if (file == NULL)
    {
        return 0;
    }
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strchr(line, '{') != NULL)
        {
            struct User temp;
            // Read "username" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"username\": \"%[^\"]\",", temp.username);
            // Read "password" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"password\": \"%[^\"]\",", temp.password);
            // Read "role" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"role\": \"%[^\"]", temp.role);
            // Skip lines until the closing brace
            while (fgets(line, sizeof(line), file))
            {
                if (strchr(line, '}') != NULL)
                    break;
            }
            users[count++] = temp;
            if (count >= MAX_USERS)
                break;
        }
    }
    fclose(file);
    return count;
}

/*----------------------------------------------------------
    Multi-user Login and Registration
----------------------------------------------------------*/

/**
 * Multi-user login function.
 */
int login()
{
    char inputUsername[MAX_USERNAME];
    char inputPassword[MAX_PASSWORD];
    int attempts = 3;

    while (attempts > 0)
    {
        printf("\n" COLOR_BLUE "+----------------------+\n" COLOR_RESET);
        printf(COLOR_BLUE "|       LOGIN          |\n" COLOR_RESET);
        printf(COLOR_BLUE "+----------------------+\n" COLOR_RESET);
        printf(COLOR_YELLOW "Username: " COLOR_RESET);
        scanf("%s", inputUsername);
        printf(COLOR_YELLOW "Password: " COLOR_RESET);
        scanf("%s", inputPassword);
        clearInputBuffer();

        /* Check credentials against all registered users */
        for (int i = 0; i < userCount; i++)
        {
            if (strcmp(users[i].username, inputUsername) == 0 &&
                strcmp(users[i].password, inputPassword) == 0)
            {
                strcpy(currentUser, users[i].username); // store the logged in username
                printf("\n" COLOR_GREEN "[ V ] Login successful! Welcome, %s!" COLOR_RESET "\n", currentUser);
                return 1;
            }
        }

        attempts--;
        printf("\n" COLOR_RED "[ X ] Invalid credentials! You have %d attempt(s) left." COLOR_RESET "\n", attempts);
    }
    return 0;
}

/**
 * Register a new user.
 */
void registerUser()
{
    if (userCount >= MAX_USERS)
    {
        printf("\n" COLOR_RED "[ ! ] User limit reached. Cannot register more users." COLOR_RESET "\n");
        return;
    }
    struct User newUser;
    printf("\n" COLOR_CYAN "=== USER REGISTRATION ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter new username: " COLOR_RESET);
    scanf("%s", newUser.username);
    printf(COLOR_YELLOW "Enter new password: " COLOR_RESET);
    scanf("%s", newUser.password);
    /* Set a default role; you can expand this later */
    strcpy(newUser.role, "faculty");
    users[userCount++] = newUser;
    printf("\n" COLOR_GREEN "[ V ] User registered successfully!" COLOR_RESET "\n");
}

/*----------------------------------------------------------
    Attendance & Student Functions (Persisted via JSON)
----------------------------------------------------------*/

/**
 * Add students to the database.
 */
void addStudents()
{
    char faculty[MAX_FACULTY];
    int n;

    printf("\n" COLOR_CYAN "+-----------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "|      ADD STUDENTS TO DATABASE           |\n" COLOR_RESET);
    printf(COLOR_CYAN "+-----------------------------------------+\n" COLOR_RESET);
    printf(COLOR_YELLOW "Enter Faculty/Department name: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);

    printf(COLOR_YELLOW "Enter number of students to add: " COLOR_RESET);
    scanf("%d", &n);
    clearInputBuffer();

    if (studentCount + n > MAX_STUDENTS)
    {
        printf("\n" COLOR_RED "[ ! ] Cannot add %d students. Maximum limit reached!" COLOR_RESET "\n", n);
        return;
    }

    printf("\n" COLOR_MAGENTA "Enter student details:\n" COLOR_RESET);
    for (int i = 0; i < n; i++)
    {
        struct Student student;
        printf("\n" COLOR_YELLOW "Student %d:\n" COLOR_RESET, i + 1);
        printf(COLOR_YELLOW "ID: " COLOR_RESET);
        scanf("%s", student.studentId);
        printf(COLOR_YELLOW "Name: " COLOR_RESET);
        clearInputBuffer();
        scanf("%[^\n]s", student.name);
        students[studentCount++] = student;
    }

    // Save students to file after adding them
    saveStudentsToFile();
    printf("\n" COLOR_GREEN "[ V ] Added %d student(s) successfully!" COLOR_RESET "\n", n);
}

/**
 * Take batch attendance and save records into a file named after the faculty.
 */
void takeBatchAttendance()
{
    char faculty[MAX_FACULTY];
    char date[20];
    char currentTime[10];
    char status;

    if (studentCount == 0)
    {
        printf("\n" COLOR_RED "[ ! ] No students in database! Please add students first." COLOR_RESET "\n");
        return;
    }

    printf("\n" COLOR_CYAN "+-------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "|         TAKE BATCH ATTENDANCE           |\n" COLOR_RESET);
    printf(COLOR_CYAN "+-------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_YELLOW "Enter Faculty/Department name: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);

    getCurrentDateTime(date, currentTime);
    printf("\n" COLOR_MAGENTA "[ ] Taking attendance for date: %s, time: %s" COLOR_RESET "\n", date, currentTime);

    for (int i = 0; i < studentCount; i++)
    {
        printf("\n" COLOR_YELLOW "Student: %s - %s" COLOR_RESET "\n", students[i].studentId, students[i].name);
        do
        {
            printf(COLOR_YELLOW "Present/Absent (P/A): " COLOR_RESET);
            scanf(" %c", &status);
            status = toupper(status);
        } while (status != 'P' && status != 'A');

        struct Attendance attendance;
        strcpy(attendance.faculty, faculty);
        strcpy(attendance.studentId, students[i].studentId);
        strcpy(attendance.name, students[i].name);
        strcpy(attendance.date, date);
        strcpy(attendance.time, currentTime);
        attendance.status = status;
        records[recordCount++] = attendance;
    }
    /* Save attendance records for this faculty into a file named <faculty>.json */
    saveFacultyJSONFile(faculty, records, recordCount, currentUser);
    printf("\n" COLOR_GREEN "[ V ] Batch attendance recorded successfully!" COLOR_RESET "\n");
}

/**
 * Display attendance records for a specific Faculty/Department from the in-memory array.
 */
void viewAttendance()
{
    char faculty[MAX_FACULTY];

    if (recordCount == 0)
    {
        printf("\n" COLOR_RED "[ ! ] No records found!" COLOR_RESET "\n");
        return;
    }

    printf("\n" COLOR_YELLOW "Enter Faculty/Department to view: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);
    printf("\n" COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "| %-15s %-20s %-15s %-10s %-10s %-10s |\n" COLOR_RESET, "Student ID", "Name", "Date", "Time", "Status", "Faculty");
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].faculty, faculty) == 0)
        {
            printf("| %-15s %-20s %-15s %-10s %-10c %-10s |\n", records[i].studentId, records[i].name, records[i].date, records[i].time, records[i].status, records[i].faculty);
        }
    }
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
}

/**
 * Search and display attendance records by date.
 */
void searchByDate()
{
    char searchDate[20];
    int found = 0;

    printf("\n" COLOR_CYAN "=== SEARCH BY DATE ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter date (DD/MM/YYYY): " COLOR_RESET);
    scanf("%s", searchDate);
    printf("\n" COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "| %-15s %-20s %-15s %-10s %-10s %-10s |\n" COLOR_RESET, "Student ID", "Name", "Date", "Time", "Status", "Faculty");
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].date, searchDate) == 0)
        {
            printf("| %-15s %-20s %-15s %-10s %-10c %-10s |\n", records[i].studentId, records[i].name, records[i].date, records[i].time, records[i].status, records[i].faculty);
            found = 1;
        }
    }
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    if (!found)
    {
        printf("\n" COLOR_RED "[ ! ] No records found for date: %s." COLOR_RESET "\n", searchDate);
    }
}

/**
 * Calculate the attendance percentage for a given student.
 */
float calculateAttendancePercentage(char *studentId)
{
    int totalDays = 0, presentDays = 0;
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].studentId, studentId) == 0)
        {
            totalDays++;
            if (records[i].status == 'P')
            {
                presentDays++;
            }
        }
    }
    return totalDays > 0 ? ((float)presentDays / totalDays) * 100 : 0;
}

/**
 * Search attendance records by student ID.
 */
void searchByStudent()
{
    char searchId[20];
    int found = 0;
    float percentage;

    printf("\n" COLOR_CYAN "=== SEARCH BY STUDENT ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter Student ID: " COLOR_RESET);
    scanf("%s", searchId);
    printf("\n" COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "| %-15s %-20s %-15s %-10s %-10s %-10s |\n" COLOR_RESET, "Student ID", "Name", "Date", "Time", "Status", "Faculty");
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].studentId, searchId) == 0)
        {
            printf("| %-15s %-20s %-15s %-10s %-10c %-10s |\n", records[i].studentId, records[i].name, records[i].date, records[i].time, records[i].status, records[i].faculty);
            found = 1;
        }
    }
    printf(COLOR_CYAN "+---------------------------------------------------------+\n" COLOR_RESET);
    if (found)
    {
        percentage = calculateAttendancePercentage(searchId);
        printf("\n" COLOR_GREEN "[ ] Attendance Percentage: %.2f%%." COLOR_RESET "\n", percentage);
    }
    else
    {
        printf("\n" COLOR_RED "[ ! ] No records found for Student ID: %s." COLOR_RESET "\n", searchId);
    }
}

/**
 * Generate an attendance report for a Faculty/Department.
 */
void generateReport()
{
    char faculty[MAX_FACULTY];
    printf("\n" COLOR_CYAN "=== GENERATE ATTENDANCE REPORT ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter Faculty/Department: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);
    printf("\n" COLOR_MAGENTA "+-----------------------------------------+\n" COLOR_RESET);
    printf(COLOR_MAGENTA "|       ATTENDANCE REPORT FOR %s       |\n" COLOR_RESET, faculty);
    printf(COLOR_MAGENTA "+-----------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "| %-15s %-20s %-10s |\n" COLOR_RESET, "Student ID", "Name", "Attendance %");
    printf(COLOR_CYAN "+-----------------------------------------+\n" COLOR_RESET);
    for (int i = 0; i < studentCount; i++)
    {
        float percentage = calculateAttendancePercentage(students[i].studentId);
        printf("| %-15s %-20s %-10.2f|\n", students[i].studentId, students[i].name, percentage);
    }
    printf(COLOR_CYAN "+-----------------------------------------+\n" COLOR_RESET);
}

/**
 * Edit an existing attendance record.
 */
void editAttendance()
{
    char faculty[MAX_FACULTY], studentId[20], date[20];
    int found = 0;

    printf("\n" COLOR_CYAN "=== EDIT ATTENDANCE ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter Faculty/Department: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);
    printf(COLOR_YELLOW "Enter Student ID: " COLOR_RESET);
    scanf("%s", studentId);
    printf(COLOR_YELLOW "Enter Date (DD/MM/YYYY): " COLOR_RESET);
    scanf("%s", date);
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].faculty, faculty) == 0 &&
            strcmp(records[i].studentId, studentId) == 0 &&
            strcmp(records[i].date, date) == 0)
        {
            char status;
            do
            {
                printf(COLOR_YELLOW "New status (P/A): " COLOR_RESET);
                scanf(" %c", &status);
                status = toupper(status);
            } while (status != 'P' && status != 'A');
            records[i].status = status;
            saveFacultyJSONFile(faculty, records, recordCount, currentUser);
            printf("\n" COLOR_GREEN "[ V ] Record updated successfully!" COLOR_RESET "\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\n" COLOR_RED "[ ! ] Record not found!" COLOR_RESET "\n");
    }
}

/**
 * Delete attendance records for a specific Faculty/Department on a given date.
 */
void deleteAttendance()
{
    char faculty[MAX_FACULTY], date[20];
    int found = 0;
    printf("\n" COLOR_CYAN "=== DELETE ATTENDANCE ===" COLOR_RESET "\n");
    printf(COLOR_YELLOW "Enter Faculty/Department: " COLOR_RESET);
    scanf(" %[^\n]s", faculty);
    printf(COLOR_YELLOW "Enter Date (DD/MM/YYYY): " COLOR_RESET);
    scanf("%s", date);
    for (int i = 0; i < recordCount; i++)
    {
        if (strcmp(records[i].faculty, faculty) == 0 &&
            strcmp(records[i].date, date) == 0)
        {
            for (int j = i; j < recordCount - 1; j++)
            {
                records[j] = records[j + 1];
            }
            recordCount--;
            i--; // Adjust index after shifting records
            found = 1;
        }
    }
    if (found)
    {
        saveFacultyJSONFile(faculty, records, recordCount, currentUser);
        printf("\n" COLOR_GREEN "[ V ] Records deleted successfully!" COLOR_RESET "\n");
    }
    else
    {
        printf("\n" COLOR_RED "[ ! ] No matching records found!" COLOR_RESET "\n");
    }
}

/**
 * (Legacy) Save attendance records to a single JSON file.
 */
void saveToJSONFile(struct Attendance records[], int count)
{
    FILE *file = fopen("attendance.json", "w");
    if (file == NULL)
    {
        printf("\n" COLOR_RED "[ ! ] Error opening file for saving data!" COLOR_RESET "\n");
        return;
    }
    fprintf(file, "[\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "  {\n");
        fprintf(file, "    \"faculty\": \"%s\",\n", records[i].faculty);
        fprintf(file, "    \"studentId\": \"%s\",\n", records[i].studentId);
        fprintf(file, "    \"name\": \"%s\",\n", records[i].name);
        fprintf(file, "    \"date\": \"%s\",\n", records[i].date);
        fprintf(file, "    \"time\": \"%s\",\n", records[i].time);
        fprintf(file, "    \"status\": \"%c\"\n", records[i].status);
        if (i == count - 1)
            fprintf(file, "  }\n");
        else
            fprintf(file, "  },\n");
    }
    fprintf(file, "]\n");
    fclose(file);
}

/**
 * (Legacy) Load attendance records from a single JSON file.
 */
int loadFromJSONFile(struct Attendance records[])
{
    FILE *file = fopen("attendance.json", "r");
    if (file == NULL)
    {
        return 0;
    }
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strchr(line, '{') != NULL)
        {
            struct Attendance temp;
            // Read "faculty" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"faculty\": \"%[^\"]\",", temp.faculty);
            // Read "studentId" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"studentId\": \"%[^\"]\",", temp.studentId);
            // Read "name" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"name\": \"%[^\"]\",", temp.name);
            // Read "date" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"date\": \"%[^\"]\",", temp.date);
            // Read "time" field
            fgets(line, sizeof(line), file);
            sscanf(line, " \"time\": \"%[^\"]\",", temp.time);
            // Read "status" field
            fgets(line, sizeof(line), file);
            char statusChar;
            sscanf(line, " \"status\": \"%c", &statusChar);
            temp.status = statusChar;
            // Skip lines until the closing brace
            while (fgets(line, sizeof(line), file))
            {
                if (strchr(line, '}') != NULL)
                    break;
            }
            records[count++] = temp;
        }
    }
    fclose(file);
    return count;
}

/**
 * Save attendance records for a given faculty to a JSON file whose name is the faculty name.
 * The file begins with a header indicating the faculty and the user who recorded it.
 */
void saveFacultyJSONFile(const char *faculty, struct Attendance records[], int totalCount, const char *user)
{
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.json", faculty);
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf(COLOR_RED "\n[ ! ] Error opening file %s for saving data!" COLOR_RESET "\n", filename);
        return;
    }
    fprintf(file, "{\n");
    fprintf(file, "  \"header\": \"Attendance records for Faculty %s recorded by user %s\",\n", faculty, user);
    fprintf(file, "  \"records\": [\n");
    int firstRecord = 1;
    for (int i = 0; i < totalCount; i++)
    {
        if (strcmp(records[i].faculty, faculty) == 0)
        {
            if (!firstRecord)
                fprintf(file, "    ,\n");
            firstRecord = 0;
            fprintf(file, "    {\n");
            fprintf(file, "      \"studentId\": \"%s\",\n", records[i].studentId);
            fprintf(file, "      \"name\": \"%s\",\n", records[i].name);
            fprintf(file, "      \"date\": \"%s\",\n", records[i].date);
            fprintf(file, "      \"time\": \"%s\",\n", records[i].time);
            fprintf(file, "      \"status\": \"%c\"\n", records[i].status);
            fprintf(file, "    }");
        }
    }
    fprintf(file, "\n  ]\n");
    fprintf(file, "}\n");
    fclose(file);
    printf(COLOR_GREEN "\n[ V ] Attendance records saved to file: %s\n" COLOR_RESET, filename);
}

/**
 * Load attendance records for a given faculty from the corresponding file (<faculty>.json).
 * Returns the number of records loaded.
 */
int loadFacultyAttendance(const char *faculty, struct Attendance recordsOut[])
{
    char filename[100];
    snprintf(filename, sizeof(filename), "%s.json", faculty);
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf(COLOR_YELLOW "\nNo attendance file found for faculty %s.\n" COLOR_RESET, faculty);
        return 0;
    }
    int count = 0;
    char line[256];
    int inRecords = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (!inRecords && strstr(line, "\"records\":") != NULL)
        {
            // Skip the next line which should be the beginning of the array
            fgets(line, sizeof(line), file);
            inRecords = 1;
            continue;
        }
        if (inRecords)
        {
            if (strchr(line, ']') != NULL)
                break;
            if (strchr(line, '{') != NULL)
            {
                struct Attendance temp;
                fgets(line, sizeof(line), file);
                sscanf(line, "      \"studentId\": \"%[^\"]\",", temp.studentId);
                fgets(line, sizeof(line), file);
                sscanf(line, "      \"name\": \"%[^\"]\",", temp.name);
                fgets(line, sizeof(line), file);
                sscanf(line, "      \"date\": \"%[^\"]\",", temp.date);
                fgets(line, sizeof(line), file);
                sscanf(line, "      \"time\": \"%[^\"]\",", temp.time);
                fgets(line, sizeof(line), file);
                char statusChar;
                sscanf(line, "      \"status\": \"%c", &statusChar);
                temp.status = statusChar;
                while (fgets(line, sizeof(line), file))
                {
                    if (strchr(line, '}') != NULL)
                        break;
                }
                recordsOut[count++] = temp;
                if (count >= MAX_RECORDS)
                    break;
            }
        }
    }
    fclose(file);
    return count;
}

/*----------------------------------------------------------
    Utility Functions
----------------------------------------------------------*/

/**
 * Clear the input buffer.
 */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * Get the current date and time.
 */
void getCurrentDateTime(char *date, char *currentTime)
{
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(date, 20, "%d/%m/%Y", tm_info);
    strftime(currentTime, 10, "%H:%M:%S", tm_info);
}

/**
 * Display the main menu.
 */
void displayMenu()
{
    printf("\n" COLOR_CYAN "+-------------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_CYAN "|         ATTENDANCE MANAGEMENT MENU              |\n" COLOR_RESET);
    printf(COLOR_CYAN "+-------------------------------------------------+\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 1.  Add Students to Database                   |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 2.  Take Batch Attendance                      |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 3.  View Attendance                            |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 4.  Search by Date                             |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 5.  Search by Student                          |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 6.  Generate Attendance Report                 |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 7.  Edit Attendance                            |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 8.  Delete Attendance                          |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 9.  Display Data in JSON Format                |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 10. Exit                                       |\n" COLOR_RESET);
    printf(COLOR_YELLOW "| 11. Bored Doing Serious Stuffs TRY THIS!!      |\n" COLOR_RESET);
    printf(COLOR_CYAN "+-------------------------------------------------+\n" COLOR_RESET);
}

/**
 * Save students to a JSON file (students.json)
 */
void saveStudentsToFile()
{
    FILE *file = fopen("students.json", "w");
    if (file == NULL)
    {
        printf("\n" COLOR_RED "[ ! ] Error opening students file for saving data!" COLOR_RESET "\n");
        return;
    }
    fprintf(file, "[\n");
    for (int i = 0; i < studentCount; i++)
    {
        fprintf(file, "  {\n");
        fprintf(file, "    \"studentId\": \"%s\",\n", students[i].studentId);
        fprintf(file, "    \"name\": \"%s\"\n", students[i].name);
        if (i == studentCount - 1)
            fprintf(file, "  }\n");
        else
            fprintf(file, "  },\n");
    }
    fprintf(file, "]\n");
    fclose(file);
}

/**
 * Load students from the JSON file (students.json)
 * Returns the number  * of students loaded.
 */
int loadStudentsFromFile()
{
    FILE *file = fopen("students.json", "r");
    if (file == NULL)
    {
        return 0;
    }
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strchr(line, '{') != NULL)
        {
            struct Student temp;
            // Read "studentId" field
            fgets(line, sizeof(line), file);
            sscanf(line, "    \"studentId\": \"%[^\"]\",", temp.studentId);
            // Read "name" field
            fgets(line, sizeof(line), file);
            sscanf(line, "    \"name\": \"%[^\"]", temp.name);
            // Skip lines until the closing brace
            while (fgets(line, sizeof(line), file))
            {
                if (strchr(line, '}') != NULL)
                    break;
            }
            students[count++] = temp;
            if (count >= MAX_STUDENTS)
                break;
        }
    }
    fclose(file);
    return count;
}