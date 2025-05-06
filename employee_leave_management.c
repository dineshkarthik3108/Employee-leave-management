
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct LeaveRequest {
    int empID;
    char name[50];
    int days;
    char status[10];  // "Pending", "Approved", "Rejected"
};

struct LeaveRequest leaveRequests[MAX_EMPLOYEES];
int leaveCount = 0;

void applyLeave() {
    printf("\n--- Apply Leave ---\n");
    struct LeaveRequest req;
    printf("Enter Employee ID: ");
    scanf("%d", &req.empID);
    printf("Enter Name: ");
    scanf("%s", req.name);
    printf("Enter Number of Leave Days: ");
    scanf("%d", &req.days);
    strcpy(req.status, "Pending");
    leaveRequests[leaveCount++] = req;
    printf("Leave request submitted successfully.\n");
}

void showStatus() {
    int id,i;
    printf("\n--- Show Leave Status ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    int found = 0;
    for (i = 0; i < leaveCount; i++) {
        if (leaveRequests[i].empID == id) {
            printf("Name: %s | Days: %d | Status: %s\n",
                   leaveRequests[i].name,
                   leaveRequests[i].days,
                   leaveRequests[i].status);
            found = 1;
        }
    }

    if (!found) {
        printf("No leave request found for this ID.\n");
    }
}

void approveLeave() {
    int id,i;
    char decision[10];
    printf("\n--- Approve/Reject Leave (Admin) ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &id);

    int found = 0;
    for (i = 0; i < leaveCount; i++) {
        if (leaveRequests[i].empID == id && strcmp(leaveRequests[i].status, "Pending") == 0) {
            printf("Leave request found for %s. Days: %d\n", leaveRequests[i].name, leaveRequests[i].days);
            printf("Enter 'approve' or 'reject': ");
            scanf("%s", decision);
            if (strcmp(decision, "approve") == 0)
                strcpy(leaveRequests[i].status, "Approved");
            else if (strcmp(decision, "reject") == 0)
                strcpy(leaveRequests[i].status, "Rejected");
            else
                printf("Invalid input. No changes made.\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No pending request found for this ID.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=== Employee Leave Management ===\n");
        printf("1. Apply for Leave\n");
        printf("2. Show Leave Status\n");
        printf("3. Admin Approve/Reject\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                applyLeave();
                break;
            case 2:
                showStatus();
                break;
            case 3:
                approveLeave();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
