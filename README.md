# Movie Rental System

## Overview

The **Movie Rental System** is a simple, C-based program designed to manage movie rentals in a small-scale rental store or system. The application allows customers to rent and return movies, track their rental history, and calculate rental fees based on the movie’s price and rental period.

This system is built using **arrays** and **structs** in C to manage the collection of **movies** and **customers**. The `movies` array holds the data about available movies, while the `customers` array stores customer information, including rental details. The program includes basic features such as displaying available movies, renting and returning movies, and viewing customer details.

### **Key Features**

1. **Display Available Movies**: The system displays a list of movies that are currently available for rent.
2. **Rent a Movie**: A customer can rent a movie by selecting it from the available options, providing their customer ID and rental duration.
3. **Return a Movie**: After renting, a customer can return the movie, and the system calculates the rental fee based on the number of days rented.
4. **Customer Details**: Displays customer-specific details such as rented movies and rental days.

### **Libraries Used**

- **stdio.h**: This is the standard input/output library in C. It is used for handling user input and displaying outputs such as movie listings, customer details, and rental information.
- **string.h**: This library provides functions for string manipulation, which is essential when handling text-based data like movie titles, customer names, and contact numbers.

### **Data Structures**

#### **Movie Struct**

The `Movie` struct is used to represent each movie in the system. It holds the movie’s unique identifier, title, genre, rental price, and availability status.

```c
struct Movie {
    int movieID;
    char title[50];
    char genre[30];
    float rentalPrice;
    int isAvailable;  // 1 if the movie is available, 0 if it's rented
};
