// Online C compiler to run C program online
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

// Structure to hold customer details
struct Customer {
    char name[50];
    char address[100];
    char phone[15];
};

// Structure to hold login information
struct LoginInfo {
    char username[20];
    char password[20];
};

// Function to display menu
void displayMenu() {
    printf("Welcome to the grocery store!\nMenu:\n");
    for (int i = 0; i < NUM_ITEMS; ++i) {
        printf("%d. %s - %.2f rupees/unit\n", i + 1, GroceryItemNames[i], itemPrices[i]);
    }
}

// Function to get customer details
void getCustomerDetails(struct Customer *customer) {
    printf("Enter your name: ");
    scanf("%s", customer->name);
    printf("Enter your address: ");
    scanf(" %[^\n]", customer->address);

    while (1) {
        printf("Enter your phone number: ");
        scanf("%s", customer->phone);
        if (strlen(customer->phone) < 10) {
            printf("Invalid phone number. Please enter a valid phone number with at least 10 digits.\n");
        } else {
            break;
        }
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

// Function to perform login
int login(struct LoginInfo *loginInfo) {
    char username[20], password[20];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    if (strcmp(username, loginInfo->username) == 0 && strcmp(password, loginInfo->password) == 0) {
        return 1; // Authentication successful
    } else {
        printf("Invalid username or password.\n");
        return 0; // Authentication failed
    }
}

int main() {
    struct Customer customer;
    struct LoginInfo loginInfo = {"admin", "password"};
    int quantities[NUM_ITEMS] = {0};
    int choice, quantity;

    if (!login(&loginInfo)) {
        printf("Login failed.\n");
        return 1;
    }

    getCustomerDetails(&customer);

    displayMenu();

    printf("\nEnter the item name and quantity in units (0 to finish):\n");
    char itemName[50];
    while (1) {
        printf("Item name: ");
        scanf("%s", itemName);
        if (strcmp(itemName, "0") == 0)
            break;
        printf("Quantity in units: ");
        scanf("%d", &quantity);
        if (quantity < 0) {
            printf("Invalid quantity. Please enter a non-negative value.\n");
            continue;
        }
        int index = matchItemName(itemName);
        if (index == -1) {
            printf("Item not found. Please enter a valid item name.\n");
            continue;
        }
        quantities[index] += quantity;
    }

    printf("\nCustomer Name: %s\nAddress: %s\nPhone Number: %s\nItems purchased:\n", customer.name, customer.address, customer.phone);
    for (int i = 0; i < NUM_ITEMS; ++i) {
        if (quantities[i] > 0) {
            printf("- %d units of %s\n", quantities[i], GroceryItemNames[i]);
        }
    }

    return 0;
}
