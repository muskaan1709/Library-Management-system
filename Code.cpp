#include<iostream>
#include<cstring>
#include<cstring>

using namespace std;

struct Date
{
    int d;
    int m;
    int y;
};

struct Checkout
{
    char name[50];
    char address[50];
    long int phone;
    int bno;
    Date checkout;
    Date ret;
};

struct Book
{
   int bno;
   char title[50];
   char author[50];
   char publisher[50];
   int year;
   char subject[50];
   struct Checkout chkout;
};

void PrintBook(Book *lib, int n)
{
    cout<<"Book number:"<<lib[n].bno<<endl;
    cout<<"Book title:"<<lib[n].title<<endl;
    cout<<"Author's name:"<<lib[n].author<<endl;
    cout<<"Publisher:"<<lib[n].publisher<<endl;
    cout<<"Year of publish:"<<lib[n].year<<endl;
    cout<<"Subject:"<<lib[n].subject<<endl;
}

void AddBook(Book *lib, int *nBooks)
{
    cout<<"Enter year of publish:";
    cin>>lib[*nBooks].year;
    if(lib[*nBooks].year < 2005)
    {
        cout<<"ERROR: Book is outdated and cannot be added."<<endl;
        return;
    }
    cout<<"Enter book number:";
    cin>>lib[*nBooks].bno;
    cout<<"Enter book title:";
    cin>>lib[*nBooks].title;
    cout<<"Enter author's name:";
    cin>>lib[*nBooks].author;
    cout<<"Enter publisher:";
    cin>>lib[*nBooks].publisher;
    cout<<"Enter subject:";
    cin>>lib[*nBooks].subject;
    lib[*nBooks].chkout.bno=-1;
    cout<<"Book added!\n";
    (*nBooks)++;
}

void Search(Book *lib, int nBooks)
{
    int option, found=0, i, b;
    char bk[50];
    cout<<"Search book by:\n";
    cout<<"1.Book Number\n";
    cout<<"2.Author\n";
    cout<<"3.Title\n";
    cout<<"4.Subject\n";
    cout<<"Enter option:";
    cin>>option;
    switch(option)
    {
        case 1:
            cout<<"Enter book number:";
            cin>>b;
            for(i=0; i<nBooks; i++)
            {
                if(lib[i].bno==b)
                {
                    PrintBook(lib, i);
                    found++;
                }
            }
            break;
        case 2:
            cout<<"Enter author's name: ";
            cin>>bk;
            for(i=0; i<nBooks; i++)
            {
                if(strcmp(bk,lib[i].author)==0)
                {
                    PrintBook(lib, i);
                    found++;
                }
            }
            break;
        case 3:
            cout<<"Enter book title:";
            cin>>bk;
            for(i=0; i<nBooks; i++)
            {
                if(strcmp(bk,lib[i].title)==0)
                {
                    PrintBook(lib, i);
                    found++;
                }
            }
            break;
        case 4:
            cout<<"Enter subject:";
            cin>>bk;
            for(i=0; i<nBooks; i++)
            {
                if(strcmp(bk,lib[i].subject)==0)
                {
                    PrintBook(lib, i);
                    found++;
                }
            }
            break;
        default:
            cout<<"ERROR: Invalid option\n";
    }
    if(!found)
        cout<<"ERROR: Book not found!\n";
}

void Checkout(Book *lib, int nBooks)
{
    int b, i, found=0;
    cout<<"Enter book number:";
    cin>>b;
	for(i=0; i<nBooks; i++)
	{
		if(lib[i].bno==b)
        {
            found++;
            if(lib[i].chkout.bno!=-1)
            {
                cout<<"ERROR: Book has already been checked out\n";
            }
            else
            {
                lib[i].chkout.bno=lib[i].bno;
                cout<<"Enter your name:"<<endl;
                cin>>lib[i].chkout.name;
                cout<<"Enter your address:"<<endl;
                cin>>lib[i].chkout.address;
                cout<<"Enter your phone number:";
                cin>>lib[i].chkout.phone;
                cout<<"Enter date (dd mm yy):"<<endl;
                cin>>lib[i].chkout.checkout.d>>lib[i].chkout.checkout.m>>lib[i].chkout.checkout.y;
                cout<<"Book has been checked out.\n";
                break;
            }
        }
	}
    if(!found)
        cout<<"ERROR: Book not found!\n";
}

void ReturnBook(Book *lib, int nBooks)
{
	int b, i, found;
    cout<<"Enter book number:";
    cin>>b;
    for(i=0; i<nBooks; i++)
    {
        if(lib[i].bno==b)
        {
            found++;
            lib[i].bno=-1;
            cout<<"Enter date (dd mm yy):"<<endl;
            cin>>lib[i].chkout.ret.d>>lib[i].chkout.ret.m>>lib[i].chkout.ret.y;
        }
    }
    if(!found)
        cout<<"ERROR: Book not found!\n";
}

int main()
{
    Book library[2700];
    int books=0, option;
    do
    {
        cout<<"~~~~~~~~~~~~LIBRARY MENU~~~~~~~~~~~~~"<<endl;
        cout<<"1.Add new book"<<endl;
        cout<<"2.Search book"<<endl;
        cout<<"3.Checkout book"<<endl;
        cout<<"4.Return book"<<endl;
        cout<<"5.Exit\nSelect Option:";
        cin>>option;
        switch(option)
        {
            case 1:
                AddBook(library,&books);
                cout<<"Total nubmer of books in library:"<<books<<endl;
                break;
            case 2:
                Search(library,books);
                break;
            case 3:
                Checkout(library,books);
                break;
            case 4:
                ReturnBook(library,books);
                break;
            case 5:
                exit(0);
            default:
                cout<<"You have entered a wrong choice :(";
        }
    } while(option<=4);
    return 0;
}


