#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
class Book
{
private:
    int bookid;
    char title[100];
    float price;
    char author[60];
public:
    void inputBook();
    void showBook();
    void storeBook();
    void viewAllBooks();
};
void Book::inputBook()
{
    cout<<"\nEnter the Bookid,Name,Price and Author";
    cin>>bookid;
    cin.ignore();
    cin.getline(title,100);
    if(!cin)
    {
        cin.clear();
        cin.ignore(256,'\n');
    }
    cin>>price;
    cin.getline(author,60);
    if(!cin)
    {
        cin.clear();
        cin.ignore(256,'\n');
    }
    cin>>price;
}
void Book::showBook()
{
    cout<<endl<<bookid<<" "<<title<<" "<<price<<" "<<author;
}
void Book::storeBook()
{
    ofstream dout;
    dout.open("Library.txt",ios::app);
    dout.write((char*)this,sizeof(*this));
    dout.close();
}
void Book::viewAllBooks()
{
    Book b;
    ifstream din;
    din.open("Library.txt",ios::in);
    if(!cin)
        cout<<"\nFile not Found";
    else
    {
        din.read((char*)&b,sizeof(b));
        while(!din.eof())
        {
            b.showBook();
            din.read((char*)&b,sizeof(b));
        }
    }
    din.close();
}
int main()
{
    int choice;
    Book b1;
    cout<<"\nWELCOME TO THE LIBRARY MANAGEMENT SYSTEM";
    while(1)
    {
    cout<<"\n1.Store New Book Record";
    cout<<"\n2.View all Book Records";
    cout<<"\n3.Clear Screen";
    cout<<"\n4.Exit";
    cout<<"\nEnter your Choice";
    cin>>choice;
    switch(choice)
    {
    case 1:
        b1.inputBook();
        b1.storeBook();
        break;
    case 2:
        cout<<"BOOKID"<<" "<<"TITLE"<<" "<<"PRICE"<<" "<<"AUTHOR";
        b1.viewAllBooks();
        break;
    case 3:
        system("cls");
        break;
    case 4:
        exit(0);
    default:
        cout<<"\nInvalid Choice";
    }
}
getch();
 return 0;

}

