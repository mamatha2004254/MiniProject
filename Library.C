#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    int id;
};

// Function to add a book
void addBook() {
    struct Book b;
    FILE *file = fopen("library.dat", "ab");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);

    fwrite(&b, sizeof(b), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

// Function to display books
void displayBooks() {
    struct Book b;
    FILE *file = fopen("library.dat", "rb");

    if (!file) {
        printf("No books available!\n");
        return;
    }
