#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100

struct Car {
    char plateNumber[20];
};

struct Car carQueue[MAX_CARS];
int carCount = 0;

void addCar() {
    if (carCount < MAX_CARS) {
        printf("Enter the plate number of the car: ");
        scanf("%s", carQueue[carCount].plateNumber);
        carCount++;
        printf("Car added to the queue.\n");
    } else {
        printf("Queue is full. Cannot add more cars.\n");
    }
}

void removeCar() {
    if (carCount > 0) {
        for (int i = 0; i < carCount - 1; i++) {
            strcpy(carQueue[i].plateNumber, carQueue[i + 1].plateNumber);
        }
        carCount--;
        printf("Car removed from the queue.\n");
    } else {
        printf("Queue is empty. No cars to remove.\n");
    }
}

void listCars() {
    if (carCount > 0) {
        printf("List of cars in the queue:\n");
        for (int i = 0; i < carCount; i++) {
            printf("%d. %s\n", i + 1, carQueue[i].plateNumber);
        }
    } else {
        printf("Queue is empty. No cars to display.\n");
    }
}

void totalCars() {
    printf("Total number of cars in queue: %d\n", carCount);
}

int main() {
    int choice;

    do {
        printf("\n-----------WELCOME TO--------------\n     Car Wash Stimulation System\n-----------------------------------\n");
        printf("  1. Add Car\n");
        printf("  2. Remove Car\n");
        printf("  3. List of Cars to be Washed\n");
        printf("  4. Total Number of Cars\n");
        printf("  5. Quit or LogOut\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                listCars();
                break;
            case 4:
                totalCars();
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
