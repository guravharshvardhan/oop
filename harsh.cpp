#include <iostream>
#include <cstring>
#include <stdexcept>

class Book {
private:
    char* title;
    char* author;
    int pageCount;
    bool isHardcover;
    float* chapterPages;
    int numChapters;

public:
    // Default constructor
    Book() {
        title = new char[1];  // Empty string
        title[0] = '\0';
        author = new char[1];  // Empty string
        author[0] = '\0';
        pageCount = 0;
        isHardcover = false;
        chapterPages = nullptr;
        numChapters = 0;
    }

    // Parameterized constructor
    Book(const char* bookTitle, const char* bookAuthor, int bookPageCount, bool bookIsHardcover, int chapters)
        : pageCount(bookPageCount), isHardcover(bookIsHardcover), numChapters(chapters) {
        
        // Dynamically allocate memory for title and author
        title = new char[strlen(bookTitle) + 1];
        strcpy(title, bookTitle);

        author = new char[strlen(bookAuthor) + 1];
        strcpy(author, bookAuthor);

        // Dynamically allocate memory for chapterPages array
        chapterPages = new float[numChapters];
        for (int i = 0; i < numChapters; i++) {
            chapterPages[i] = bookPageCount / static_cast<float>(numChapters); // Even distribution
        }
    }

    // Copy constructor (deep copy)
    Book(const Book& other) {
        // Allocate memory for title and author
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);

        // Copy numeric values
        pageCount = other.pageCount;
        isHardcover = other.isHardcover;
        numChapters = other.numChapters;

        // Deep copy chapterPages array
        if (other.chapterPages != nullptr) {
            chapterPages = new float[numChapters];
            for (int i = 0; i < numChapters; i++) {
                chapterPages[i] = other.chapterPages[i];
            }
        } else {
            chapterPages = nullptr;
        }
    }

    // Destructor
    ~Book() {
        delete[] title;
        delete[] author;
        delete[] chapterPages;
    }

    // Method to modify chapter pages
    void modifyChapterPages(int chapter, float newPageCount) {
        if (chapter < 1 || chapter > numChapters) {
            throw std::out_of_range("Invalid chapter index.");
        }
        chapterPages[chapter - 1] = newPageCount;
    }

    // Method to display book details
    void display() const {
        std::cout << "Book Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Page Count: " << pageCount << std::endl;
        std::cout << "Format: " << (isHardcover ? "Hardcover" : "Paperback") << std::endl;
        std::cout << "Number of Chapters: " << numChapters << std::endl;
        
        std::cout << "Chapter Page Counts: ";
        for (int i = 0; i < numChapters; i++) {
            std::cout << chapterPages[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Demonstrating Default Constructor
    Book book1;
    book1.display();

    // Demonstrating Parameterized Constructor
    Book book2("C++ Programming", "John Doe", 400, true, 10);
    book2.display();

    // Demonstrating Copy Constructor
    Book book3 = book2;
    book3.display();

    // Modifying a chapter page count
    try {
        book3.modifyChapterPages(5, 35.0);
        std::cout << "\nAfter modifying chapter 5's page count:\n";
        book3.display();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
