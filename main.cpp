#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float discount;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};

void shopping :: menu(){
    m:
     int choice;
     string email;
     string passwd;

     cout<<"\t\t\t________________________\n";
     cout<<"\t\t\t                        \n";
     cout<<"\t\t\t Super Market Main Menu \n";
     cout<<"\t\t\t                        \n";
     cout<<"\t\t\t________________________\n";
     cout<<"\t\t\t                        \n";
     cout<<"\t\t\t|   1)Administrator    |\n";
     cout<<"\t\t\t|                      |\n";
     cout<<"\t\t\t|   2)Buyer            |\n";
     cout<<"\t\t\t|                      |\n";
     cout<<"\t\t\t|   3)Exit             |\n";
     cout<<"\t\t\t|                      |\n";
     cout<<"\n\t\t Please Select!";
     cin>>choice;

     switch(choice){
        case 1:
        {
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email \n";
            cin>>email;
            cout<<"\t\t\t Enter Password \n";
            cin>>passwd;

            if(email == "nilayshirke52@gmail.com" && passwd == "nilay123"){
                administrator();
            }else{
                cout<<"Invalid Email/Password";
            }
            break;
        }
        
        case 2:{
            buyer();
        }
        case 3:{
            exit(0);
        } 
        default:
            cout<<"Please Select from given Options:";
     }
     goto m;

}

void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|___1)Add the product___|";
    cout<<"\n\t\t\t|                       |";
    cout<<"\n\t\t\t|__2)Modify the product_|";
    cout<<"\n\t\t\t|                       |";
    cout<<"\n\t\t\t|__3)Delete the product_|";
    cout<<"\n\t\t\t|                       |";
    cout<<"\n\t\t\t|__4)Back to main Menu__|";

    cout<<"\n\t\t Please Enter your choice!";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Please Select from given Options:";
    }
    goto m;

}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t Buyer \n";
    cout<<"             \n";
    cout<<"\t\t\t1)Buy product \n";
    cout<<"             \n";
    cout<<"\t\t\t2) Go Back \n";
    cout<<"\t\t\t Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Please Select from given Options:";
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c ;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t Product Code of the product: ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product: ";
    cin>>pname;
    cout<<"\n\n\t Price of the product: ";
    cin>>price;
    cout<<"\n\n\t Discount on the product: ";
    cin>>discount;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1)goto m;
        else{
            data.open("database.txt",ios::app | ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            data.close();
        }
    }
    
    cout<<"\n\n\t\t Record Inserted";

}

void shopping :: edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code: ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\nFile Does'nt exist!";
    }else{
        data1.open("database1.txt", ios::app|ios::out);
    }
}