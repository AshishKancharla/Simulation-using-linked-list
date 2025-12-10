#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;  
int n = 0;                 

void display() {
    if (head == NULL) {
        printf("\nList is Empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertBeginning() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;
    n++;

    printf("\nInserted at Beginning Successfully.\n");
}

void insertEnd() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    n++;

    printf("\nInserted at End Successfully.\n");
}

void insertPosition() {
    int pos, value;
    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("\nInvalid Position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // Insert at beginning
    if (pos == 1) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("\nMemory Allocation Failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        n++;
        printf("\nInserted at Position %d Successfully.\n", pos);
        return;
    }

    // Insert at given position (not 1)
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed!\n");
        return;
    }
    newNode->data = value;

    struct Node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nUnexpected Error! Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    n++;

    printf("\nInserted at Position %d Successfully.\n", pos);
}

void deleteBeginning() {
    if (head == NULL) {
        printf("\nList is Empty! Cannot Delete.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nDeleted %d from Beginning.\n", temp->data);

    head = head->next;
    free(temp);
    n--;
}

void deleteEnd() {
    if (head == NULL) {
        printf("\nList is Empty! Cannot Delete.\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        printf("\nDeleted %d from End.\n", head->data);
        free(head);
        head = NULL;
        n--;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("\nDeleted %d from End.\n", temp->data);
    prev->next = NULL;
    free(temp);
    n--;
}

void deletePosition() {
    if (head == NULL) {
        printf("\nList is Empty! Cannot Delete.\n");
        return;
    }

    int pos;
    printf("Enter position (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("\nInvalid Position!\n");
        return;
    }

    // Delete first node
    if (pos == 1) {
        struct Node *temp = head;
        printf("\nDeleted %d from Position %d.\n", temp->data, pos);
        head = head->next;
        free(temp);
        n--;
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    int i;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nUnexpected Error! Position out of range.\n");
        return;
    }

    printf("\nDeleted %d from Position %d.\n", temp->data, pos);
    prev->next = temp->next;
    free(temp);
    n--;
}

void freeList() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
    n = 0;
}

int main() {
    int choice, initialCount, value;

    printf("\n===== LINKED LIST SIMULATION PROJECT =====\n");

    // Take initial linked list input from user
    printf("Enter initial number of elements: ");
    scanf("%d", &initialCount);

    if (initialCount < 0) {
        printf("Invalid Size! Setting size to 0.\n");
        initialCount = 0;
    }

    if (initialCount > 0) {
        printf("Enter %d elements:\n", initialCount);
        for (int i = 0; i < initialCount; i++) {
            scanf("%d", &value);

            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("\nMemory Allocation Failed while creating initial list!\n");
                break;
            }
            newNode->data = value;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                struct Node *temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
            n++;
        }
    }

    while (1) {
        printf("\n-------------------------------------\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Specific Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Specific Position\n");
        printf("8. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: display(); break;
            case 2: insertBeginning(); break;
            case 3: insertEnd(); break;
            case 4: insertPosition(); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8:
                printf("\nThank You! Exiting...\n");
                freeList();
                exit(0);
            default:
                printf("\nInvalid Choice! Try Again.\n");
        }
    }

    return 0;
}