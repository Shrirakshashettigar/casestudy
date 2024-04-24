// Structure to hold customer details
struct Customer {
    char name[50];
    char address[100];
    char phone[15];
};
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
