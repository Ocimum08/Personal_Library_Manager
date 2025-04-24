#include<iostream>
#include<unordered_map>
#include<stack>
#include<string>
#include<queue>
using namespace std;

struct Book{
    string title;
    string author;
    string genre;
    int year;
    bool isRead;

    Book() {}
    Book(string t, string a , string g, int y): title(t), author(a), genre(g), year(y), isRead(false) {}
};

unordered_map<string, Book> library;
stack<string> recentlyRead;
queue<string> toBeRead;

void addBook(){
    string title, author, genre;
    int year;
    cout<<"Enter title: ";
    cin.ignore();
    getline(cin, title);
    cout<<"Enter author: ";
    getline(cin, author);
    cout<<"Enter genre: ";
    getline(cin, genre);
    cout<<"Enter Year: ";
    cin>>year;

    if(library.count(title)){
        cout<<"Book already exists.\n";
        return;
    }

    Book book(title, author, genre, year);
    library[title] = book;
    toBeRead.push(title); // adding to reading queue
    cout<<"Book added successfully!\n";
}

void removeBook(){
    string title;
    cout<<"Enter title to Remove: ";
    cin.ignore();
    getline(cin, title);

    if(library.erase(title)){
        cout<<"Book removed.\n";
    }else{
        cout<<"Book not found.\n";
    }
}

void searchBook(){
    string title;
    cout<<"Enter title to Search: ";
    cin.ignore();
    getline(cin, title);

    if(library.count(title)){
        Book book = library[title];
        cout << "\nTitle: " << book.title << "\nAuthor: " << book.author
             << "\nGenre: " << book.genre << "\nYear: " << book.year
             << "\nStatus: " << (book.isRead ? "Read" : "Unread") << "\n";
    } else {
        cout<<"Book not found.\n";
    }
}

void markAsRead(){
    string title;
    cout<<"Enter Title to Mark as Read: ";
    cin.ignore();
    getline(cin, title);

    if(library.count(title)){
        library[title].isRead = true;
        recentlyRead.push(title);
        cout<<"Book marked as read.\n";
    } else {
        cout<<"Book not found.\n";
    }
}

void showRecentlyRead(){
    if(recentlyRead.empty()){
        cout<<"No recently read books.\n";
        return;
    }

    cout<<"Recently Read Books:\n";
    stack<string> temp = recentlyRead;
    while (!temp.empty()) {
        cout << "- " << temp.top() << endl;
        temp.pop();
    }
}

void showToBeRead(){
    if(toBeRead.empty()){
        cout<<"No books in To-Be-Read list.\n";
        return;
    }

    cout<<"To-Be-Read Books:\n";
    queue<string> temp = toBeRead;
    while(!temp.empty()){
        cout<<"- "<< temp.front() << endl;
        temp.pop();
    }
}

void listAllBooks(){
    if(library.empty()){
        cout<<"Library is empty.\n";
        return;
    }

    cout << "\nAll Books in Library:\n";
    for(auto &entry : library) {
        Book book = entry.second;
        cout << "--------------------------------\n";
        cout << "Title: " << book.title << "\nAuthor: " << book.author
             << "\nGenre: " << book.genre << "\nYear: " << book.year
             << "\nStatus: " << (book.isRead ? "Read" : "Unread") << "\n";
    }
    cout << "--------------------------------\n";
}

void menu(){
    int choice;
    do {
        cout << "\n====== Personal Library Manager ======\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Mark Book as Read\n";
        cout << "5. Show Recently Read Books\n";
        cout << "6. Show To-Be-Read List\n";
        cout << "7. List All Books\n";
        cout << "8. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: removeBook(); break;
            case 3: searchBook(); break;
            case 4: markAsRead(); break;
            case 5: showRecentlyRead(); break;
            case 6: showToBeRead(); break;
            case 7: listAllBooks(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 8);
}

int main(){
    menu();
    return 0;
}