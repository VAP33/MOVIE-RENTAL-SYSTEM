#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 50
#define MAX_CUSTOMERS 20

// Define a structure for Movie
struct Movie {
    int movieID;
    char title[50];
    char genre[30];
    float rentalPrice; // price per day
    int isAvailable; // 1 if available, 0 if rented
};

// Define a structure for Customer
struct Customer {
    int customerID;
    char name[50];
    char contactNumber[15];
    int rentedMovieID; // -1 if no movie rented
    int rentalDays;
};

// Function to display all movies
void displayMovies(struct Movie movies[], int n) {
    printf("\n=================================== Available Movies ===================================\n");
    printf("ID\tTitle\t\t\t\tGenre\t\tPrice\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (movies[i].isAvailable) {
            printf("%d\t%-25s\t%-15s\t%.2f\n", movies[i].movieID, movies[i].title, movies[i].genre, movies[i].rentalPrice);
        }
    }
    printf("=======================================================================================\n");
}

// Function to rent a movie to a customer
void rentMovie(struct Movie movies[], struct Customer customers[], int movieCount, int customerCount) {
    int movieID, customerID;
    printf("Enter Customer ID: ");
    while (scanf("%d", &customerID) != 1 || customerID < 1 || customerID > customerCount) {
        printf("Invalid input! Please enter a valid Customer ID (1-%d): ", customerCount);
        while(getchar() != '\n');  // clear the buffer
    }

    printf("Enter Movie ID to rent: ");
    while (scanf("%d", &movieID) != 1 || movieID < 1 || movieID > movieCount || !movies[movieID - 1].isAvailable) {
        printf("Invalid movie ID or movie is not available! Please try again: ");
        while(getchar() != '\n');  // clear the buffer
    }

    // Rent the movie
    printf("Enter rental period (in days): ");
    while (scanf("%d", &customers[customerID - 1].rentalDays) != 1 || customers[customerID - 1].rentalDays < 1) {
        printf("Invalid input! Please enter a positive number for rental days: ");
        while(getchar() != '\n');  // clear the buffer
    }

    // Mark movie as rented
    customers[customerID - 1].rentedMovieID = movieID;
    movies[movieID - 1].isAvailable = 0;
    printf("Movie rented successfully!\n");
}

// Function to return a rented movie
void returnMovie(struct Movie movies[], struct Customer customers[], int movieCount, int customerCount) {
    int customerID;
    printf("Enter Customer ID: ");
    while (scanf("%d", &customerID) != 1 || customerID < 1 || customerID > customerCount) {
        printf("Invalid input! Please enter a valid Customer ID (1-%d): ", customerCount);
        while(getchar() != '\n');  // clear the buffer
    }

    if (customers[customerID - 1].rentedMovieID == -1) {
        printf("Customer has not rented any movie.\n");
        return;
    }

    int rentedMovieID = customers[customerID - 1].rentedMovieID;
    printf("Movie returned successfully! Rental days: %d\n", customers[customerID - 1].rentalDays);

    // Calculate rental fee
    float rentalFee = movies[rentedMovieID - 1].rentalPrice * customers[customerID - 1].rentalDays;
    printf("Rental fee: %.2f\n", rentalFee);

    // Mark movie as available
    movies[rentedMovieID - 1].isAvailable = 1;
    customers[customerID - 1].rentedMovieID = -1; // Reset rented movie
    customers[customerID - 1].rentalDays = 0; // Reset rental days
}

// Function to display customer details and rented movie
void displayCustomerDetails(struct Customer customers[], struct Movie movies[], int customerCount) {
    int customerID;
    printf("Enter Customer ID to view details: ");
    while (scanf("%d", &customerID) != 1 || customerID < 1 || customerID > customerCount) {
        printf("Invalid input! Please enter a valid Customer ID (1-%d): ", customerCount);
        while(getchar() != '\n');  // clear the buffer
    }

    if (customers[customerID - 1].rentedMovieID == -1) {
        printf("Customer has not rented any movie.\n");
    } else {
        int movieID = customers[customerID - 1].rentedMovieID;
        printf("\n====================== Customer Details ======================\n");
        printf("Customer: %-15s | Contact: %-15s\n", customers[customerID - 1].name, customers[customerID - 1].contactNumber);
        printf("Rented Movie: %-25s | Genre: %-15s\n", movies[movieID - 1].title, movies[movieID - 1].genre);
        printf("Rental Days: %-5d | Rental Fee: %.2f\n", customers[customerID - 1].rentalDays, movies[movieID - 1].rentalPrice * customers[customerID - 1].rentalDays);
        printf("==============================================================\n");
    }
}

int main() {
    struct Movie movies[MAX_MOVIES] = {
        {1, "Inception", "Sci-Fi", 5.0, 1},
        {2, "Titanic", "Romance", 4.5, 1},
        {3, "The Matrix", "Action", 6.0, 1},
        {4, "The Godfather", "Crime", 5.5, 1}
    };

    struct Customer customers[MAX_CUSTOMERS] = {
        {1, "Alice", "1234567890", -1, 0},
        {2, "Bob", "0987654321", -1, 0},
        {3, "Charlie", "1122334455", -1, 0}
    };

    int movieCount = 4;
    int customerCount = 3;
    int choice;

    while (1) {
        printf("\n==================== Movie Rental System ====================\n");
        printf("1. Display Available Movies\n");
        printf("2. Rent Movie\n");
        printf("3. Return Movie\n");
        printf("4. Display Customer Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input! Please enter a valid choice (1-5): ");
            while(getchar() != '\n');  // clear the buffer
        }

        switch (choice) {
            case 1:
                displayMovies(movies, movieCount);
                break;
            case 2:
                rentMovie(movies, customers, movieCount, customerCount);
                break;
            case 3:
                returnMovie(movies, customers, movieCount, customerCount);
                break;
            case 4:
                displayCustomerDetails(customers, movies, customerCount);
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                return 0;
            default:
                break;
        }
    }

    return 0;
}
