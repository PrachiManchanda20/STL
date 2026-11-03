#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cctype>
using namespace std;

    
class BooK
{

public:
    int book_id;
    string title;
    string author;
    int number_of_copies_Available;
    int books_stock;
    int user_No_of_Books;
    int book_Price;

    BooK(int book_id, string title, string author, int number_of_copies_Available, int books_stock, int book_Price)
    {
        this->book_id = book_id;
        this->title = title;
        this->author = author;
        this->number_of_copies_Available = number_of_copies_Available;
        this->books_stock = books_stock;
        this->user_No_of_Books  = 0;
        this->book_Price = book_Price;
    };

    void display_All_Books()
    {

        cout << "\n";
        cout << "book_id : " << book_id << "\n";
        cout << "title : " << title << "\n";
        cout << "author : " << author << "\n";
        cout << "number_of_copies : " << number_of_copies_Available << "\n";
        cout << "books_stock : " << books_stock << "\n";
        cout << "book Price : "<< book_Price <<"\n";
        cout << "\n";
    }
};

class Admin : public BooK
{
public:
    string name;
    int member_id;
};

class register_Member
{
public:
    string name;
    int member_id;

    register_Member(string name, int member_id)
    {
        this->name = name;
        this->member_id = member_id;
    }

    void view_Member_Details()
    {
        cout << "\n";
        cout << "Name : " << name << endl;
        cout << "Member Id : " << member_id << endl;
    }
};

class issue_Book
{ // member and books

private:
    int book_id;
    int member_id;

    int issue_year;
    int issue_date;
    int issue_month;

    int due_date;

public:
    void getter(int member_id, int book_id)
    {

        this->member_id = member_id;
        this->book_id = book_id;
    }

    int getMemberId()
    {
        return member_id;
    }

    int getBookId()
    {
        return book_id;
    }

    void setIssueDate()
    {

        time_t now = time(0);
        tm *currentDate = localtime(&now);

        issue_date = currentDate->tm_mday;
        issue_month = currentDate->tm_mon + 1;
        issue_year = currentDate->tm_year + 1900;
    }

    void setDueDate(){
        time_t now = time(0);
        tm *currDate = localtime(&now);

        due_date = currDate->tm_mday;

    }
    int getIssuedDate(){
        return issue_date;
    }

    int getDueDate(){
        return due_date;
    }
};

    issue_Book issue;

    vector<BooK> books;
    vector<issue_Book> issuedBooks;

    vector<register_Member> registered;


int validate_Member(int member_id, string name){

    bool isString = false;
    for( char ch : name){
        if(!isalpha(ch)){
            isString = false;
        }
        else{
            isString = true;
        }
    }
    if(!isString){
        cout<<"ENter Valid Author Name"<<endl;
    }

    if(member_id <= 0){
        cout<<"Wrong Member Id"<<endl;

    }

    for(register_Member rg : registered){

        if(member_id == rg.member_id){
            cout<<"can't add Duplicate Members"<<endl;
            break;
        }

    }
    return 100;
}

int Validate_Book(int book_id, int copies, int stock, int bookPrice , string author){

   bool isString = false;
    for( char ch : author){
        if(!isalpha(ch)){
            isString = false;
        }
        else{
            isString = true;
        }
    }
    if(!isString){
        cout<<"ENter Valid Author Name"<<endl;
        return 100;
    }

    if(book_id <= 0 || copies <= 0 || stock <= 0 || bookPrice <= 0 ){
        cout<<"Wrong Member Id"<<endl;
        // break;
        return 100;
    }

    for(BooK rg : books){

        if(book_id == rg.book_id){
            cout<<"can't add Duplicate Members"<<endl;
            return 100;
        }
        
    }
return 1;
}


int main()
{

  
    int choice;
    cout << " LIBRARY MANAGEMENT SYSTEM" << endl;

    while (1)
    {

        cout << "PRESS 1 TO ADD A BOOK" << "\n";
        cout << "PRESS 2 TO  Register a Member" << "\n";
        cout << "PRESS 3 TO Display All Books" << "\n";
        cout << "PRESS 4 TO Search for a Book" << "\n";
        cout << "PRESS 5 Issue a Book" << "\n";
        cout << "PRESS 6  Return a Book" << "\n";
        cout << "PRESS 7  View Member Details" << "\n";
        cout << "PRESS 8 Calculate Fine" << "\n";

        cout << "PRESS 9 TO Exit" << "\n";

        cout << "\n"
             << "Enter Your Choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        { // Add book
            cout << "Add the book by Entering the details: " << endl;

            int id, copies, stock, book_Price;
            string author, title;
            cout << "Enter book ID" << endl;
            cin >> id;
            
            cout << "Enter Number of Copies" << endl;
            cin >> copies;
            cout << "Enter stock" << endl;
            cin >> stock;
            cout << "Enter book author" << endl;
            cin >> author;
            cout << "Enter title" << endl;
            cin >> title;
            cout<<"Enter Book Price"<<endl;
            cin>> book_Price;

            // if(id<=0 || copies <= 0 || stock <= 0 || book_Price<=0 ){
            //     cout<<"Wrong Id"<<endl;
            //     break;
            // }

           int invalid = Validate_Book(id, copies, stock, book_Price, author);
            if(invalid == 100){
                cout<<"Data can't be negative !"<<endl;
                return 0;
            }

            books.push_back(BooK(id, title, author, copies, stock, book_Price));

            cout << "BOOK SAVED!" << endl;
            break;
        }

        case 2:
        { // register member
            cout << "Enter your details to register : " << endl;

            string name;
            int member_id;
            cout << "Enter Your Name" << endl;
            cin >> name;

            cout << "Enter Member_id" << endl;
            cin >> member_id;

            // if(member_id <= 0){
            //     cout<< "Wrong Member Id"<<endl;
            //     break;
            // }

            validate_Member(member_id , name);

            registered.push_back(register_Member(name, member_id));

            cout << "REGISTERED!" << endl;
            break;
        }

        case 3:
        { // display all books

            for (BooK b : books)
            {
                cout << "\n";
                cout << "book_id : " << b.book_id << "\n";
                cout << "title : " << b.title << "\n";
                cout << "author : " << b.author << "\n";
                cout << "number_of_copies : " << b.number_of_copies_Available << "\n";
                cout << "books_stock : " << b.books_stock << "\n";
                cout << "book Price : " <<b.book_Price << "\n";
                cout << "\n";
            }

            break;
        }

        case 4:
        { // search for a book

            cout << "SEARCH A BOOK : " << endl;
            int book_id;
            string title;

            cout << "ENter Book id :" << endl;
            cin >> book_id;

            cout << "Enter Book title :" << endl;
            cin >> title;

            int isBook = 0;
            for (BooK b : books)
            {

                if (b.book_id == book_id && b.title == title)
                {
                    isBook = 1;
                    cout << "\n";
                    cout << "book_id : " << b.book_id << "\n";
                    cout << "title : " << b.title << "\n";
                    cout << "author : " << b.author << "\n";
                    cout << "number_of_copies : " << b.number_of_copies_Available << "\n";
                    cout << "books_stock : " << b.books_stock << "\n";
                    cout << "book Price : "<< b.book_Price <<endl; 
                    cout << "\n";
                }
            }
            if(isBook == 0){
                cout<<"Book doesn't exist!"<<endl;
            }

            break;
        }

        case 5:
        { // issue a book

            int member_id, book_id;
            cout << "ENTRE THE MEMBER ID :" << endl;
            cin >> member_id;

            cout << "ENTER YOUR PRODUCT ID :" << endl;
            cin >> book_id;


            int member_Exist = 0;

            for (register_Member b : registered)
            {

                if (b.member_id == member_id)
                {
                    member_Exist = 1;
                    break;
                }
            }
            if (member_Exist == 0)
            {
                cout << "MEMBER ID DOESN'T EXIST !" << endl
                     << "REGISTER TO ISSUE A BOOK !" << endl;
                break;
            }

            int book_Exist = 0;

            for (BooK &bk : books)
            {

                if (book_id == bk.book_id)
                {

                    book_Exist = 1;

                    if (bk.number_of_copies_Available <= 0)
                    {

                        cout << "BOOK OUT OF STOCK !" << endl;
                        break;
                    }

                    issue.getter(member_id, book_id);

                    issue.getMemberId();

                    issue.getBookId();

                    issue.setIssueDate();

                    issuedBooks.push_back(issue);

                    bk.user_No_of_Books++;
                    bk.number_of_copies_Available--;

                    cout << "BOOK ISSUED SUCCESSFULLY!" << endl;
                }

                break;
            }
            if (book_Exist == 0)
            {
                cout << "WRONG BOOK ID !" << endl;
            }
            break;
        }

        case 6:
        { // return a book

             int member_id, book_id;
            cout << "ENTRE THE MEMBER ID :" << endl;
            cin >> member_id;

            cout << "ENTER YOUR PRODUCT ID :" << endl;
            cin >> book_id;

            //store issued book date !!!! LEFT!!!!

            int found = 0;
            
          for(int i = 0; i < issuedBooks.size(); i++){
            if(issuedBooks[i].getMemberId() == member_id && issuedBooks[i].getBookId() == book_id){

                for(int j = 0; j<books.size();j++){
                    if(books[j].book_id == book_id){
                        books[j].number_of_copies_Available++;
                        books[j].user_No_of_Books--;
                        break;
                    }
                }

                found = 1;
                issuedBooks.erase(issuedBooks.begin() + i);
                issue.setDueDate();
                 cout << "BOOK RETURNED SUCCESSFULLY!" << endl;

            }

          }

          if(found == 0){
            cout<<"NOT FOUND !"<<endl;
          }
            

            break;
        }
        case 7:
        { // view member details

            for (register_Member b : registered)
            {
                cout << "\n";
                cout << "Member_id : " << b.member_id << "\n";
                cout << "Name : " << b.name << "\n";

                cout << "\n";
            }
            break;
        }

        case 8:
        { // calculate fine
            // int issueDate = issue.getIssuedDate();
            // int due_Date = issue.getDueDate();
            // int fine = 0;

            // if(issueDate - due_Date > 0 && issueDate - due_Date < 14){
            //     fine = book_Charge + 20;
            // }
            // else if(days <= 30 && days>14){
            //     fine = book_Charge + 60;
            // }
            // break; 
        }
        case 9:
        { // exit
            cout<<" THANLKYOU !!"<<endl;
            break;
        }
        default:
        {
            cout << "Wrong Choice !"<<endl;
            break;
        }
        }
        if(choice == 9 || choice > 9 || choice <= 0){
            break;
        }
        
    }
    return 0;
}

// }


// class due_Book
// { // member and books

// private:
//     int book_id;
//     int member_id;

//     int due_year;
//     int due_date;
//     int due_month;

//     int due_date;

// public:
//     void getter(int member_id, int book_id)
//     {

//         this->member_id = member_id;
//         this->book_id = book_id;
//     }

//     int getMemberId()
//     {
//         return member_id;
//     }

//     int getBookId()
//     {
//         return book_id;
//     }

//     void dueDate()
//     {

//         time_t now = time(0);
//         tm *currentDate = localtime(&now);

//         due_date = currentDate->tm_mday;
//         due_month = currentDate->tm_mon + 1;
//         due_year = currentDate->tm_year + 1900;
//     }
// };