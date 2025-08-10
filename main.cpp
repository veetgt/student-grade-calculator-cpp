#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_GRADES 10

int studentCount = 0;

// Defines the data structure to store the information for each student.
struct student {
	char name[50];
	double grades[MAX_GRADES];
	double average;
	char status[20];
	char sex;
};

int main() {
	// Declaration of the array that will store all students.
	struct student students[100];
	char proceed;
	double approvalAvg;
	int gradeCount; 
	int maleApproved = 0, maleFailed = 0; 
	int femaleApproved = 0; 
	int femaleFailed = 0; 
	int totalMales = 0, totalFemales = 0;
	
	// --- INITIAL SETUP SECTION ---
	printf("--- Class Setup ---\n");
	printf("Enter the passing average: ");
	scanf("%lf", &approvalAvg);

	printf("Enter the number of grades per student (max %d): ", MAX_GRADES);
    scanf("%d", &gradeCount);
    
    // Validation to ensure the number of grades is valid.
    if (gradeCount < 1) {
        printf("Invalid number of grades. Exiting.\n");
        return 1;
    }
    
	do {
		// --- DATA COLLECTION SECTION ---
		printf("\n--- Inserting Student %d ---\n", studentCount+1);

		printf("Name: ");
		scanf("%s", students[studentCount].name);
		
		// Small loop to ensure the sex is 'M' or 'F'.
		do {
		printf("Sex (M/F): ");
		scanf(" %c", &students[studentCount].sex);
		} while (students[studentCount].sex != 'M' && students[studentCount].sex != 'm' && students[studentCount].sex != 'F' && students[studentCount].sex != 'f');
		
		double gradesSum = 0.0;
        for (int i = 0; i < gradeCount; i++) {
            printf("Grade %d: ", i + 1);
            scanf("%lf", &students[studentCount].grades[i]); 
            gradesSum += students[studentCount].grades[i];
        }

        students[studentCount].average = gradesSum / gradeCount;
        
		// --- STATISTICS CALCULATION SECTION ---
		if (students[studentCount].average >= approvalAvg) {
			strcpy(students[studentCount].status, "Approved");
			
			if (students[studentCount].sex == 'M' || students[studentCount].sex == 'm') {
            totalMales++; maleApproved++;
			} else if (students[studentCount].sex == 'F' || students[studentCount].sex == 'f') {
            totalFemales++; femaleApproved++;
			}
			
			
		} else {
			strcpy(students[studentCount].status, "Failed");
			
			if (students[studentCount].sex == 'M' || students[studentCount].sex == 'm') {
            totalMales++; maleFailed++;
			} else if (students[studentCount].sex == 'F' || students[studentCount].sex == 'f') {
            totalFemales++; femaleFailed++;
			}
		}
		
		studentCount++;
		
		// Asks the user if they want to continue adding students.
		printf("Do you want to add another student? [Y/N]: ");
		scanf(" %c", &proceed);
	} while ( studentCount<=100 &&proceed == 'Y' || proceed == 'y' );

	// --- FINAL REPORTS SECTION ---
	printf("\n--- Final Report of %d Students---", studentCount);
	for (int i = 0; i < studentCount; i++) {
		printf("\n\nStudent: %s \nAverage: %.2lf\nStatus: %s\n Sex: %c", students[i].name, students[i].average, students[i].status, students[i].sex);
	}
	
	// Prints the class statistics report.
	printf("\n\n--- Approval Statistics by Sex ---\n");
    printf("Males (%d total):\n", totalMales);
    printf("  - Approved: %d\n", maleApproved);
    printf("  - Failed: %d\n", maleFailed);
    printf("\nFemales (%d total):\n", totalFemales);
    printf("  - Approved: %d\n", femaleApproved);
    printf("  - Failed: %d\n", femaleFailed);
    printf("----------------------------------\n");
	return 0;
}

