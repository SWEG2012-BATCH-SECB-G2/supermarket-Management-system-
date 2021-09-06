
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

// Global Variables
float Quantity[100],TotalPrice = 0,Cash;
int NumberofBoughtItems,ProductNo[100],amount,Location[100];
bool ProductFound;
int NumberOfProducts = 63, FlagDelete = 0, FlagEdit = 0;

// Resizes the console window
void ResizeWindow()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1600, 800, TRUE);
}
struct Date
{
    int Day,Month,Year;
};

struct Product
{
    int ProductNumber;
    string ProductName;
    string Category;
    string ProductType;
    Date ProductionDate;
    Date ExpireDate;
    float Quantity;
    string MeasurementUnit;
    float UnitPrice;
    float Rating;
    int Sales = 0;
} Products[9999];
int MainMenu(void);
void PrintTableDividers()
{
    cout << setw(2) << " +---------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(24) << "--------------------------+";
    cout << setw(15) << "-----------------+";
    cout << setw(15) << "-----------------+";
    cout << setw(8) << "----------+";
    cout << setw(16) << "------------------+";
    cout << setw(10) << "------------+";
    cout << setw(6) << "--------+";
    cout << setw(5) << "-------+";
    cout << endl;
}
void PrintTableHeader()
{
    // Table Headers
    cout << setw(2) << " | Serial Number" << " | ";
    cout << setw(24) << "Product Name" << " | ";
    cout << setw(24) << "Category" << " | ";
    cout << setw(24) << "Product Type" << " | ";
    cout << setw(15) << "Production Date" << " | ";
    cout << setw(15) << "Expire Date" << " | ";
    cout << setw(8) << "Quantity" << " | ";
    cout << setw(16) << "Measurement Unit" << " | ";
    cout << setw(10) << "Unit Price" << " | ";
    cout << setw(6) << "Rating" << " | ";
    cout << setw(5) << "Sales" << " | ";
    cout << endl;
}

void PrintInItemValue(Product Item)
{
    // Table Values
    string ProductionDate = to_string(Item.ProductionDate.Day) + "/" + to_string(Item.ProductionDate.Month) + "/" + to_string(Item.ProductionDate.Year);
    cout << " | " << setw(13) << Item.ProductNumber << " | ";
    cout << setw(24) << Item.ProductName << " | ";
    cout << setw(24) << Item.Category << " | ";
    cout << setw(24) << Item.ProductType << " | ";
    cout << setw(15) << ProductionDate << " | ";
    cout << setw(15) << ProductionDate << " | ";
    cout << setw(8) << Item.Quantity << " | ";
    cout << setw(16) << Item.MeasurementUnit << " | ";
    cout << setw(10) << Item.UnitPrice << " | ";
    cout << setw(6) << Item.Rating << " | ";
    cout << setw(5) << Item.Sales << " | ";
    cout << endl;
}

void welcomeScreen()
{
    cout << R"(



                        ,ad8888ba,                                     ad88888ba   88
                       d8"'    `"8b                            ,d     d8"     "8b  88
                      d8'                                      88     Y8,          88
                      88             ,adPPYYba,  8b,dPPYba,  MM88MMM  `Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,
                      88             ""     `Y8  88P'   "Y8    88       `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a
                      Y8,            ,adPPPPP88  88            88             `8b  88       88  8b       d8  88       d8
                       Y8a.    .a8P  88,    ,88  88            88,    Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"
                        `"Y8888Y"'   `"8bbdP"Y8  88            "Y888   "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"'
                                                                                                             88
                                                                                                             88

    )" << endl;
    cout << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << endl;
    system("pause");
    system("cls");
}

void PrintInTableFormat()
{
    // Initialization
    //ResizeWindow();
    // Print Full Table For reference to edit
    cout << endl << " Here's a list of all products... " << endl << endl;
    // Print In Table Format Function
    PrintTableDividers();
    PrintTableHeader();
    // Loop Through the samples to print the details in table format
    for(int i = 0; i < NumberOfProducts; i++)
    {
        PrintTableDividers();
        PrintInItemValue(Products[i]);
    }
    PrintTableDividers();
}
void PrintReceipt()
{
    system("cls");
    cout<<setfill(' ')<<setw(30)<<"Receipt\n";
    cout<<setfill(' ')<<"Item No"<<setw(15)<<"Name \t"<<setw(8)<<"Quantity"<<setw(8)<<"Price"<<setw(10)<<"Amount\n";
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        cout<<setfill(' ')<<"Item "<<i+1<<": "<<setw(15)<<Products[N].ProductName<<setw(8)<<Quantity[i]<<setw(8)<<Products[N].UnitPrice<<setw(10)<<Quantity[i]*Products[N].UnitPrice<<endl;
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        TotalPrice=TotalPrice+(Quantity[i]*Products[N].UnitPrice);
    }

    cout<<setfill(' ')<<setw(47)<<"Txbl   "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Tax(15%)   "<<0.15*TotalPrice<<endl;
    TotalPrice=1.15*TotalPrice;
    cout<<setfill(' ')<<setw(47)<<"TotalPrice  "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Cash: ";
    cin>>Cash;
    cout<<setfill(' ')<<setw(47)<<"Change: "<<Cash-TotalPrice<<endl;
    cout<<setfill(' ')<<setw(30)<<"Thank You For Your Purchase" << endl;
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        Products[N].Quantity=Products[N].Quantity-Quantity[i];
        Products[N].Sales = Products[N].Sales + Quantity[i];
    }
    system("pause");
    system("cls");
    MainMenu();
}

void CashierAccount()
{
    //ProductSampleData();
    cout<<setfill(' ') << setw(50) <<"Welcome to CartShop\n\n";
    amount=1000;
    cout<<"\tEnter The Details of The Items Below \n \tIf You Finish Your Purchase  at Any Time Enter 0 \n";
    for(int i=0; i<amount; i++)
    {
        ProductFound=false;
MainMenu:
        cout<<"Item "<<i+1<<":\n";
ProductNum:
        cout<<"\tProduct Number: ";
        cin>>ProductNo[i];
        for(int j=0; j<500; j++)
        {
            switch(ProductNo[i])
            {
            case 0:
                char opt;
Finish:
                NumberofBoughtItems=i;
                PrintReceipt();
                cout<<"\tHave You Finished Your Purchase(Y/N)\n";
                cin>>opt;
                opt=(char)toupper(opt);
                switch(opt)
                {
                case 'N':
                    system("pause");
                    goto MainMenu;
                    break;
                case 'Y':
                    system("pause");
                    PrintReceipt();
                    break;
                default:
                    cout<<"\t Error: Invalid Input Try again\n";
                    goto Finish;
                    break;
                }
            case 1 ... 9999:
                if(ProductNo[i]==Products[j].ProductNumber)
                {
                    Location[i]=j;
                    ProductFound=true;
                    NumberofBoughtItems=i+1;
                }
                break;
            default :
                cout<<"\tInvalid Number. Try Again!\n";
                goto ProductNum;
                break;
            }
        }
        if(ProductFound==false)
        {
            cout<<"\tCouldn't Find The Product. Try Again!\n";
            goto ProductNum;
        }
        cout<<"\t\t Quantity: ";
        cin>>Quantity[i];
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
    }
}

void Search(int SearchedProduct)
{

    int i;
    for( i = 1; i<9999; i++)
    {

        if( SearchedProduct == Products[i].ProductNumber && Products[i].ProductNumber != 0)
        {
            cout<<endl<<endl;
            PrintTableHeader();
            PrintTableDividers();
            PrintInItemValue(Products[i]);
            cout<<endl<<endl;
            i = 9999;
        }
        else if(Products[i].ProductNumber == 0)
        {
            i = 9999;
            FlagDelete = 1;
            FlagEdit = 1;
            cout<<"\n**********Product Not found**********\n"<<endl;
        }
    }

}

void EditItem()
{
    // Print Full Table For reference to edit
    //PrintInTableFormat();
    // Enter Serial Number of a product to edit
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to edit: ";

    while(!(cin>>SerialNumber))
    {
        cout<< "\n**********Invalid input.**********\n";
        cout << endl << " Serial Number : ";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if(!(FlagEdit))
    {
        Product *Item = &Products[SerialNumber];
        // List of options to edit
        int EditChoice;
edit:
        cout << endl << " What would you like to edit?" << endl;
        cout << "  1. Product Name" << "\t\t  6. Quantity" << endl;
        cout << "  2. Product Category" << "\t\t  7. Measurement Unit" << endl;
        cout << "  3. Product Type" << "\t\t  8. Unit Price" << endl;
        cout << "  4. Production Date" << "\t\t  9. Rating" << endl;
        cout << "  5. Expire Date" << "\t\t 10. Sales" << endl;
        cout << endl << " Edit Choice: ";

        while(!(cin>>EditChoice))
        {
            cout<< "\n**********Invalid input.**********\n";
            cout << endl << " Enter Choice( 1 - 10): ";
            cin.clear();
            cin.ignore(20, '\n');
        }
        if(EditChoice> 10 || EditChoice<1)
        {
            cout<<" Enter Choice( 1 - 10): ";
            goto edit;
        }
        cout << endl;
        // Accept new values based on choice
        switch(EditChoice)
        {
        case 1:
            cout << " Enter New Product Name: ";
            cin >> Item->ProductName;
            break;
        case 2:
            cout << " Enter New Product Category: ";
            cin >> Item->ProductName;
            break;
        case 3:
            cout << "Enter New Product Type: ";
            cin >> Item->ProductName;
            break;
        case 4:
date:
            cout << " Enter New Production Date" << endl;
            cout << "\t New Day: ";
            while(!( cin >> Item->ProductionDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Day>30 || Item->ProductionDate.Day<1)
            {
                cout<<" **********Invalid Day.********** \n";
                goto date;
            }

            cout << "\t New Month: ";
            cin >> Item->ProductionDate.Month;
            while(!( cin >> Item->ProductionDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\nInvalid input.\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Month<1 || Item->ProductionDate.Month>12)
            {
                cout<<" Invalid Day. \n";
                goto date;
            }
            cout << "\t New Year: ";
            while(!( cin >> Item->ProductionDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ProductionDate.Year<2015 || Item->ProductionDate.Year>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }
            break;
        case 5:
            cout << " Enter New Expire Date: ";
            cout << "\t New Day: ";
            cin >> Item->ExpireDate.Day;
            while(!( cin >> Item->ExpireDate.Day))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Day<2015 || Item->ExpireDate.Day>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Month: ";
            while(!( cin >> Item->ExpireDate.Month))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Month<2015 || Item->ExpireDate.Month>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            cout << "\t New Year: ";
            while(!( cin >> Item->ExpireDate.Year))   // INPUT VALIDATION FOR DATE EDITING
            {
                cout<< "\n**********Invalid input.**********\n";
                cin.clear();
                cin.ignore(20, '\n');
                goto date;
            }
            if( Item->ExpireDate.Year<2015 || Item->ExpireDate.Year>2021)
            {
                cout<<"**********Invalid Day.**********\n";
                goto date;
            }

            break;
        case 6:
            cout << " Enter New Quantity: ";
            cin >> Item->Quantity;
            break;
        case 7:
            cout << " Enter New Measurement Unit: ";
            getline(cin,Item->MeasurementUnit);
            break;
        case 8:
            cout << " Enter New Unit Price: ";
            while(!(cin>>Item->UnitPrice))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Unit Price: ";
                cin.clear();
                cin.ignore(20, '\n');

            }

            break;
        case 9:
            cout << " Enter New Rating: ";
            while(!(cin>>Item->Rating))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }
            break;
        case 10:
            cout << " Enter New Sale ";
            while(!(cin>>Item->Sales))
            {
                cout<< "**********Invalid Day.**********\n";
                cout << " Enter New Rating: ";
                cin.clear();
                cin.ignore(20, '\n');

            }

            break;
        }
        system("color 0A");
        cout << endl << " \t ---- \t Item Edited Successfully! \t ----" << endl << endl;
    }
    FlagEdit = 0;
    system("pause");
    system("color 0F");
    system("cls");

}

// This function asks for a serial number of an item and then it allows you to delete it from the stock
void DeleteItem()
{
    system("cls");
    // Print Full Table For reference to edit
    //PrintInTableFormat();
    // Enter Serial Number of a product to edit
AskDeletion:
    int SerialNumber;
    cout << endl << " Enter Serial Number Of Item you want to delete: ";

    while(!(cin>>SerialNumber))    // INPUT VALIDATION FOR
    {
        cout<< "\nInvalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
    }
    Search(SerialNumber);

    if( !(FlagDelete))
    {
        Product *Item = &Products[SerialNumber];
        cout << endl << " Are you sure you want to delete this item? (Y/N): ";
        cout<< endl << "1. Yes.";
        cout<< endl << "2. No."<<endl;
        system("color 0C");
        int ConfirmDeletion;
        while(!(cin>>ConfirmDeletion))    // INPUT VALIDATION FOR
        {
            cout<< "\nInvalid input.\n\n";
            cin.clear();
            cin.ignore(20, '\n');
        }
        if(ConfirmDeletion == 1)
        {
            for(int i = SerialNumber; i < NumberOfProducts - 1; i++)
            {
                Products[i] = Products[i+1];
            }
            NumberOfProducts--;
            for(int i = 0; i < NumberOfProducts; i++)
            {
                Item = &Products[i];
                Item->ProductNumber = i;
            }
            system("color 0A");
            cout << endl << " \t ---- \t Item Deleted Successfully! \t ----" << endl << endl;
            system("pause");
            system("cls");
        }
        else if (ConfirmDeletion == 2)
        {
            system("color 0E");
            //goto AskDeletion;
        }
    }
    FlagDelete = 0;
    system("color 0F");
}

bool CompareUsingUnitPriceAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.UnitPrice < SecondProduct.UnitPrice)
        return 1;
    else
        return 0;
}

//Used to Compare products using there unit price in descending order
bool CompareUsingUnitPriceDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.UnitPrice > SecondProduct.UnitPrice)
        return 1;
    else
        return 0;
}

//Used to Compare products using there rating in ascending order
bool CompareUsingRatingAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Rating < SecondProduct.Rating)
        return 1;
    else
        return 0;
}

//Used to Compare products using there rating in descending order
bool CompareUsingRatingDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Rating > SecondProduct.Rating)
        return 1;
    else
        return 0;
}

//Used to Compare products using there production date in ascending order
bool CompareUsingProductionDateAscending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ProductionDate.Year < SecondProduct.ProductionDate.Year)||((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month < SecondProduct.ProductionDate.Month))||(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&&(FirstProduct.ProductionDate.Day < SecondProduct.ProductionDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there production date in descending order
bool CompareUsingProductionDateDescending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ProductionDate.Year > SecondProduct.ProductionDate.Year)||((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month > SecondProduct.ProductionDate.Month))||(((FirstProduct.ProductionDate.Year == SecondProduct.ProductionDate.Year)&&(FirstProduct.ProductionDate.Month == SecondProduct.ProductionDate.Month))&&(FirstProduct.ProductionDate.Day > SecondProduct.ProductionDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in ascending order
bool CompareUsingExpirationDateAscending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ExpireDate.Year < SecondProduct.ExpireDate.Year)||
            ((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&
             (FirstProduct.ExpireDate.Month < SecondProduct.ExpireDate.Month))||
            (((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&
              (FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&&
             (FirstProduct.ExpireDate.Day < SecondProduct.ExpireDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there expiration date in descending order
bool CompareUsingExpirationDateDescending( Product FirstProduct, Product SecondProduct)
{
    if((FirstProduct.ExpireDate.Year > SecondProduct.ExpireDate.Year)||((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month > SecondProduct.ExpireDate.Month))||(((FirstProduct.ExpireDate.Year == SecondProduct.ExpireDate.Year)&&(FirstProduct.ExpireDate.Month == SecondProduct.ExpireDate.Month))&&(FirstProduct.ExpireDate.Day > SecondProduct.ExpireDate.Day)))
        return 1;
    else
        return 0;
}

//Used to Compare products using there quantity in ascending order
bool CompareUsingQuantityAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Quantity < SecondProduct.Quantity)
        return 1;
    else
        return 0;
}

//Used to Compare products using there quantity in descending order
bool CompareUsingQuantityDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Quantity > SecondProduct.Quantity)
        return 1;
    else
        return 0;
}

//Used to Compare products using there sales in ascending order
bool CompareUsingSalesAscending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Sales < SecondProduct.Sales)
        return 1;
    else
        return 0;
}

//Used to Compare products using there sales in descending order
bool CompareUsingSalesDescending( Product FirstProduct, Product SecondProduct)
{
    if(FirstProduct.Sales > SecondProduct.Sales)
        return 1;
    else
        return 0;
}

void ProductSampleData()
{
//Initializing Bread and Bakery sample data
    Products[1] = {1,"Banana Bread ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs ",22,4.9 };
    Products[2] = {2,"Whole Wheat ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200,"Loafs",3,2.5 };
    Products[3] = {3,"Sourdough ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs",4,4.7 };
    Products[4] = {4,"Baguette ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200,"Loafs",10,3 };
    Products[5] = {5,"Difo Dabo ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",20,4.9 };
    Products[6] = {6,"White Bread ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200,"Loafs",3,2.8 };
    Products[7] = {7,"Carrot Cake ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21},200,"Loafs",20,4.1 };
    Products[8] = {8,"Bagels ", "Bread and Bakery", "Bread ",{6,9,21}, {10,9,21}, 200," Loafs",12,3.9 };
    Products[9] = {9,"Chocolate Chip ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21},200,"Kilogram ",30,4.8 };
    Products[10] = {10,"Shortbread Cookie ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21}, 200,"Kilogram ",28,4 };
    Products[11] = {11,"Peanut Butter ", "Bread and Bakery", "Cookies ",{6,9,21}, {10,9,21},200,"Kilogram ",28,2.5 };

//Initializing Pasta and rice sample data
    Products[12] = {12,"Short Pasta ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25,4.3 };
    Products[13] = {13,"Long Pasta ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",25,4.3 };
    Products[14] = {14,"Macaroni ", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",24,4 };
    Products[15] = {15,"Fettuccine", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21},100,"Kilogram ",28,2.5 };
    Products[16] = {16,"Lasagna", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100,"Kilogram ",32,5 };
    Products[17] = {17,"Spaghetti", "Pasta and Rice", "Pasta ",{6,9,21}, {10,9,21}, 100," Kilogram",30,4.9 };
    Products[18] = {18,"Brown Rice ", "Pasta and Rice", "Rice ",{6,9,21}, {10,9,21}, 100,"Kilogram ",30,4.7 };
    Products[19] = {19,"White Rice ", "Pasta and Rice", "Rice ",{6,9,21}, {10,9,21},100," Kilogram",27,2.5 };

//Initializing Dairy and meat sample data
    Products[20] = {20,"Beef ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100,"Kilogram ",250,4.9 };
    Products[21] = {21,"Pork ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100,"Kilogram ", 200,2.5 };
    Products[22] = {22,"Mutton ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100,"Kilogram ",260, 4.4};
    Products[23] = {23,"Chicken ", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100,"Kilogram ",300,4.9 };
    Products[24] = {24,"Turkey", "Dairy and Meat", "Meat ",{6,9,21}, {10,9,21},100,"Kilogram ",280,3.9 };
    Products[25] = {25,"Butter ", "Dairy and Meat", "Dairy ",{6,9,21}, {10,9,21},100,"Kilogram ",450,5 };
    Products[26] = {26,"Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21}, 100,"Liters ",40,4.9 };
    Products[27] = {27,"Mozzarella ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100,"Kilogram ",320,4.5 };
    Products[28] = {28,"Cheddar ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100,"Kilogram ",300,4.9 };
    Products[29] = {29,"Parmesan ", "Dairy and Meat", "Cheese ",{6,9,21}, {10,9,21},100,"Kilogram ",360,4.4 };
    Products[30] = {30,"Gouda ", "Dairy and Meat ", "Cheese ",{6,9,21}, {10,9,21},100,"Kilogram ",380,5 };
    Products[31] = {31,"Yoghurt ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100,"Liters ",60,4.9 };
    Products[32] = {32,"Powdered Milk ", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100,"Kilogram ",1200,4.6 };
    Products[33] = {33,"Ice Cream", "Dairy and Meat ", "Dairy ",{6,9,21}, {10,9,21},100,"Kilogram ",300,5 };

//Initializing Beverages and Drinkssample data
    Products[34] = {34,"Beer ", "Beverages and Drinks", "Beverage ",{6,9,21}, {0,0,0},103,"Milliliter ", 200,2.5 };
    Products[35] = {35,"Cider ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,21},103,"Milliliter ",260, 4.4};
    Products[36] = {36,"Hard Soda ", "Beverages and Drinks", "Beverage ",{3,12,21}, {10,9,21},100,"Milliliter ",300,4.9 };
    Products[37] = {37,"Wine", "Beverages and Drinks", "Beverage ",{10,12,21}, {10,9,21},102,"Milliliter ",280,3.9 };
    Products[38] = {38,"Barley ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,26},101,"Milliliters ",450,5 };
    Products[39] = {39,"Turkish ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,27}, 106,"Liters ",40,4.9 };
    Products[40] = {40,"Moka ", "Beverages and Drinks", "Beverage ",{6,9,21}, {10,9,25},100,"Milliliter ",320,4.5 };
    Products[41] = {41,"Kamora ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},107,"Milliliter ",300,4.9 };
    Products[42] = {42,"Amarula ", "Beverages and Drinks", "Soft Drinks ",{6,9,20}, {10,9,21},108,"Milliliter ",360,4.4 };
    Products[43] = {43,"Carolans ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},109,"Milliliter ",380,5 };
    Products[44] = {44,"Rosolio ", "Beverages and Drinks", "Soft Drinks ",{3,9,21}, {10,9,21},234,"Litres ",60,4.9 };
    Products[45] = {45,"Aurum ", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},257,"Milliliter ",1200,4.6 };
    Products[46] = {46,"Cointreau", "Beverages and Drinks", "Soft Drinks ",{6,9,21}, {10,9,21},234,"Milliliter ",300,5};
//Initializing Snacks sample data
    Products[47] = {47,"Milky Way ", "Snack ", "Snack ",{6,9,21}, {10,9,17},100,"Milliliter ", 270,2.5 };
    Products[48] = {48,"Sun Chips ", "Snack ", "Snack ",{1,9,21}, {10,9,21},100,"Milliliter ",290, 4.4};
    Products[49] = {49,"Suncake ", "Snack ", "Snack ",{6,9,20}, {10,9,15},100,"Milliliter ",700,4.9 };
    Products[50] = {50,"Vadai", "Snack ", "Snack ",{6,9,19}, {10,9,21},100,"Milliliter ",340,3.9 };
    Products[51] = {51,"Popcorn ", "Snack ", "Snack ",{10,9,17}, {10,9,13},100,"Milliliters ",240,5 };
    Products[52] = {52,"Candy ", "Snack ", "Snack ",{6,9,19}, {10,9,24}, 100,"Liters ",40,4.9 };
    Products[53] = {53,"Fruit ", "Snack ", "Snack ",{6,9,18}, {10,9,21},100,"Milliliter ",30,4.5 };
    Products[54] = {54,"Pretzels ", "Snack ", "Snack ",{7,9,21}, {10,9,21},100,"Milliliter ",10,4.9 };
    Products[55] = {55,"Doughnuts ", "Snack ", "Snack ",{6,9,21}, {10,9,15},100,"Milliliter ",30,4.4 };
    Products[56] = {56,"Peanuts ", "Snack ", "Snack ",{6,9,21}, {10,9,16},100,"Milliliter ",40,5 };
    Products[57] = {57,"Poha ", "Snack ", "Snack ",{2,9,21}, {10,9,20},100,"Litres ",60,4.9 };
    Products[58] = {58,"Momos ", "Snack ", "Snack ",{9,9,21}, {10,9,21},100,"Milliliter ",120,4.6 };
    Products[59] = {59,"Khaman", "Snack ", "Snack ",{8,9,21}, {10,9,21},100,"Milliliter ",15,5 };

//Utensils
    Products[60] = {60,"Spoon","Kitchen Utensils","Spoon",{10,11,17},{14,10,20},40,"Items",30.45,2.5};
    Products[61] = {61,"Napkins","Sanitary","Baby Wipes",{20,12,18},{15,11,21},12,"Packages",40.00,4.5};
    Products[62] = {62,"Lotion","Health And Bodycare","Nivea",{30,10,19},{16,12,22},10,"Bottle",99.39,5.0};

}
int MainMenu()
{
    system("cls");
    int Choice, InvalidChoiceCounter= 0;

Menu:
    cout<<"1. Print all Products. "<<endl;
    cout<<"2. Search for product. "<<endl;
    cout<<"3. Delete Item from Stock. "<<endl;
    cout<<"4. Edit a Product "<<endl;
    cout<<"5. Sorting Functions "<<endl;
    cout<<"6. Sales. "<<endl;
    cout<<"7. Exit "<<endl;
    cout<<"Choice: ";

    while(!(cin>>Choice))
    {
        cout<< "Invalid input.\n\n";
        cin.clear();
        cin.ignore(20, '\n');
        goto Menu;
    }

    switch(Choice)
    {
    case 1:
        system("cls");
        PrintInTableFormat();
        cout<<endl<<endl<<endl;
        goto Menu;
    case 2:
        system("cls");
        int ProductNumberSearch;//Search Key
        cout<<"Enter the Product number of the item you would like to search."<<endl;
        cout<<"Product Number: ";

        while(!(cin>>ProductNumberSearch))
        {
            cout<< "\nInvalid input.\n\n";
            cin.clear();
            cin.ignore(20, '\n');
            cout<<"Re-enter Product Number: ";

            InvalidChoiceCounter++;
            if(InvalidChoiceCounter >= 3)
            {
                InvalidChoiceCounter = 0;
                goto Menu;//We can make it go to the main menu when we merge it all
            }
        }

        Search(ProductNumberSearch);//Calling Search function
        goto Menu;
        break;

    case 3:
        DeleteItem();
        goto Menu;

    case 4:
        system("cls");
        EditItem();
        goto Menu;
    case 5:
        system("cls");
ReturnToChoice:
        cout<<"Choose how you want to sort: "<<endl;
        cout<<"1. Unit Price"<<endl;
        cout<<"2. Rating"<<endl;
        cout<<"3. Production date"<<endl;
        cout<<"4. Expire date"<<endl;
        cout<<"5. Quantity"<<endl;
        cout<<"6. Sales"<<endl;
        int Choice,OrderChoice;
        cout<<"Your choice: ";
        cin>>Choice;
ReturnToOrderChoice:
        cout<<"Choose Order"<<endl;
        cout<<"1. Ascending Order"<<endl;
        cout<<"2. Descending Order"<<endl;
        cout<<"Your choice: ";
        cin>>OrderChoice;
        switch(Choice)
        {
        case 1:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingUnitPriceAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingUnitPriceDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 2:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingRatingAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingRatingDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 3:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingProductionDateAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingProductionDateDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 4:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingExpirationDateAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingExpirationDateDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 5:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingQuantityAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingQuantityDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        case 6:
            if(OrderChoice == 1)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingSalesAscending);
                PrintInTableFormat();
            }
            else if(OrderChoice == 2)
            {
                sort(Products, Products+NumberOfProducts, CompareUsingSalesDescending);
                PrintInTableFormat();
            }
            else
            {
                cout<<"Invalid Choice! Try Again";
                goto ReturnToOrderChoice;
            }
            break;
        default:
            cout<<"Invalid Choice! Try Again";
            system("cls");
            goto ReturnToChoice;
        }
        goto Menu;

    case 6:
        CashierAccount();

    case 7:
        return 0;//We can make it go to the main menu when we merge it all
        break;
    default:
        cout<<"\nInvalid Choice."<<endl;
        system("pause");
        system("cls");
        goto Menu;
    }
}

int main()
{
    welcomeScreen();
    ProductSampleData();
    MainMenu();
}
