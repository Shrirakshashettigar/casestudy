
struct LoginInfo {
    char username[20];
    char password[20];
};

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
