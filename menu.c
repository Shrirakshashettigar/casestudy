#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ITEMS 8

// Define grocery item names and prices
const char* GroceryItemNames[NUM_ITEMS] = {
    "Rice", "Pasta", "Milk", "Eggs", "Bread",
    "Cheese", "Chicken", "Fish"
};

float itemPrices[NUM_ITEMS] = {60.0, 45.5, 25.75, 20.25, 30.0, 55.0, 150.0, 40.0};
// Function to display menu
void displayMenu() {
    printf("Welcome to the grocery store!\nMenu:\n");
    for (int i = 0; i < NUM_ITEMS; ++i) {
        printf("%d. %s - %.2f rupees/unit\n", i + 1, GroceryItemNames[i], itemPrices[i]);
    }
}
// Function to match item name
int matchItemName(const char *itemName) {
    for (int i = 0; i < NUM_ITEMS; ++i) {
        if (strcmp(itemName, GroceryItemNames[i]) == 0) {
            return i;
        }
    }
    return -1; // Item not found
}

