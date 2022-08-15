#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

class shopping
{
private:
    int productCode;
    float price;
    float discount;
    string productname;

public:
    void menu();
    void admistrator();
    void buyer();
    void addProduct();
    void removeProduct();
    void edit();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t__________________________________________\n";
    cout << "\t\t\t\t                                          \n";
    cout << "\t\t\t\t                                          \n";
    cout << "\t\t\t\t           SuperMarket Main Menu          \n";
    cout << "\t\t\t\t                                          \n";
    cout << "\t\t\t\t__________________________________________\n";

    cout << "\n\t\t\t\t| 1) Admistrator    |";
    cout << "\n\t\t\t\t| 2) Buyer          |";
    cout << "\n\t\t\t\t| 3) Product List   |";
    cout << "\n\t\t\t\t| 4) Exit           |";
    cout << "\n\n\t\tPlease Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\t\t Enter Email : ";
        cin >> email;
        cout << "\n\t\t Enter Password: ";
        cin >> password;
        if (email == "ish@gmail.com" && password == "11223344")
        {
            admistrator();
        }
        else
        {
            cout << "\n\t\t\t\t Invalid User Name Or Password" << endl;
        }
        break;
    case 2:
        buyer();
        break;
    case 3:
        list();
        menu();
        break;
    case 4:
        exit(0);
        // break;
    default:
        cout << "\n\t\t Invalid Choice. Please Select From The Given Option" << endl;
        // break;
    }
    goto m;
}

void shopping ::admistrator()
{
m:
    int choice;
    cout << "\n\t\t\t\t_______________________________\n";
    cout << "\t\t\t\t                                \n";
    cout << "\t\t\t\t      Admistrator Menu          \n";
    cout << "\t\t\t\t                                \n";
    cout << "\t\t\t\t_______________________________\n";

    cout << "\n\t\t\t| 1)      Add Product       |";
    cout << "\n\t\t\t| 2)      Modify Product    |";
    cout << "\n\t\t\t| 3)      Delete Product    |";
    cout << "\n\t\t\t| 4)      Product List      |";
    cout << "\n\t\t\t| 5)      Back to Main Menu |";
    cout << endl;
    cout << "\n\t\tPlease Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        addProduct();
        break;
    case 2:
        edit();
        break;
    case 3:
        removeProduct();
        break;
    case 4:
        list();
        admistrator();
        break;
    case 5:
        menu();
        break;
    default:
        cout << "\t\t\t\tPlease select From the given Option\n";
        // break;
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\n\t\t\t\t_______________________________\n";
    cout << "\t\t\t\t                                \n";
    cout << "\t\t\t\t           Buyer Menu           \n";
    // cout<<"\t\t\t\t                                \n";
    cout << "\t\t\t\t_______________________________\n";

    cout << "\n\t\t\t| 1)      Buy Product       |";
    cout << "\n\t\t\t| 2)      Back to Main Menu |";
    cout << endl;
    cout << "\n\t\tPlease Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "\t\t\t\tInvalid Choice. Please select From the given Option\n";
        // break;
    }
    goto m;
}

void shopping ::addProduct()
{
m:
    int pCode;
    float cost;
    float dis;
    string pName;
    int token = 0;

    fstream data;

    cout << endl;
    cout << "\t\t\t\t_______________________________\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t          Add Product           \n";
    cout << "\t\t\t\t_______________________________\n";

    cout << "\n\t\t Enter Product Code : ";
    cin >> productCode;
    cout << "\n\t\t Enter Product Name : ";
    cin >> productname;
    cout << "\n\t\t Enter Product Price : ";
    cin >> price;
    cout << "\n\t\t Enter Discount On The Product : ";
    cin >> discount;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << "\t" << productCode << "\t" << productname << "\t" << price << "\t" << discount << endl;
        data.close();
    }

    else
    {
        // Try this with do while loop as well

        data >> pCode >> pName >> cost >> dis;
        while (!data.eof())
        {
            if (pCode == productCode)
            {
                token++;
            }
            data >> pCode >> pName >> cost >> dis;
        }
        data.close();

        if (token > 0)
        {
            cout << "\n\t\t Duplicate Product Code. Please Enter Again...";
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << "\t" << productCode << "\t" << productname << "\t" << price << "\t" << discount << endl;
            data.close();
        }
    }
    cout << "\n\n\t Record Of The Product Inserted" << endl;
}

void shopping ::removeProduct()
{
    fstream data, data1;
    int pcode;
    string pName;
    float cost, dis;
    bool flag = true;

    cout << endl;
    cout << "\t\t\t\t_______________________________\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t        Remove Product         \n";
    cout << "\t\t\t\t_______________________________\n";

    cout << "\n\t\t Enter Product Code: ";
    cin >> pcode;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t File Doesn't Exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> productCode >> productname >> price >> discount;
        while (!data.eof())
        {
            if (productCode == pcode)
            {
                cout << "\n\tProduct removed Succesfully\n";
                flag = false;
            }
            else
            {
                data1 << "\t" << productCode << "\t" << productname << "\t" << price << "\t" << discount << endl;
            }

            data >> productCode >> productname >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (flag)
        {
            cout << "\n\t\t Record Not Found\n";
        }
    }
}

void shopping ::edit()
{
    fstream data, data1;
    int pcode;
    string pName;
    float cost, dis;
    int token = 0;

    cout << endl;
    cout << "\t\t\t\t_______________________________\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t        Modify Product         \n";
    cout << "\t\t\t\t_______________________________\n";

    cout << "\n\t\t Enter Product Code: ";
    cin >> pcode;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t File Doesn't Exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> productCode >> productname >> price >> discount;
        while (!data.eof())
        {
            if (productCode == pcode)
            {
                cout << "\n\t\t Enter New Product Code: ";
                cin >> pcode;
                cout << "\n\t\t Enter Product Name: ";
                cin >> pName;
                cout << "\n\t\t Enter product Price: ";
                cin >> cost;
                cout << "\n\t\t Enter Discount On The Product: ";
                cin >> dis;

                data1 << "\t" << pcode << "\t" << pName << "\t" << cost << "\t" << dis << endl;
                cout << "\n\t\t\t Record Modified" << endl;
                token++;
            }
            else
            {
                data1 << "\t" << productCode << "\t" << productname << "\t" << price << "\t" << discount << endl;
            }

            data >> productCode >> productname >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\t\t Record Not Found\n";
        }
    }
}

void shopping ::list()
{
    fstream data;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t File Doesn't Exist\n";
    }
    else
    {
        cout << "\n\t\t-----------------------------------";
        cout << "\n\t\t         Product List              ";
        cout << "\n\t\t-----------------------------------";
        cout << "\nProduct Code\t Product Name\t     Price(per Unit)\t Discount\n";

        data >> productCode >> productname >> price >> discount;
        while (!data.eof())
        {
            cout << "  " << productCode << "\t\t   " << productname << "\t\t" << price << "\t\t  " << discount << "\n";
            data >> productCode >> productname >> price >> discount;
        }
        data.close();
    }
}

void shopping ::receipt()
{
    int arrCodes[100];
    int arrQuantity[100];
    float amount = 0;
    float dis = 0;
    float total = 0;
    char choice;
    int cnt = 0;

    fstream data;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t Empty Database\n";
    }
    else
    {
        data.close();
        list();
        cout << "\n\t\t-----------------------------------------";
        cout << "\n\t\t             Place Your Order            ";
        cout << "\n\t\t-----------------------------------------";
        do
        {
        m:
            cout << "\nEnter Product Code: ";
            cin >> arrCodes[cnt];
            cout << "Enter Product Quantity: ";
            cin >> arrQuantity[cnt];

            for (auto i = 0; i < cnt; i++)
            {
                if (arrCodes[i] == arrCodes[cnt])
                {
                    cout << "\n\t\t Already Entered \n";
                    goto m;
                }
            }
            cnt++;
            cout << "\n\t Do you want to buy another product? if yes then press Y else N" << endl;
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        
        cout << "\n\t-------------------------------------------";
        cout << "\n\t                Receipt                    ";
        cout << "\n\t-------------------------------------------";

        cout << "\n\n"
             << "\tProduct Code\t Product name\tProduct Quantity    Price (per Unit)\tAmount\t  Amount with Discount" << endl;

// Below code have some bug issue . please fix that;
// after only one iteration of for loop doesn't work 
        for(int i=0; i<cnt; i++)
        {
            data.open("database.txt", ios::in);
            data >> productCode >> productname >> price >> discount;
            
            while (!data.eof())
            {
                if (productCode == arrCodes[i])
                {
                    amount = (arrQuantity[i] * price);
                    dis = amount - (amount * (discount / 100));
                    total = total + dis;
                    cout << "\n\t  " << productCode << "\t\t  " << productname << "\t\t" << arrQuantity[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;

                }
                
                data >> productCode >> productname >> price >> discount;
            }
           
        }
        data.close();
    }
    cout << "\n\n____________________________________________________________" << endl;
    cout << "Total Amount : " << total << endl;
}

int main()
{
    shopping customer1;
    // customer1.list();
    // customer1.receipt();
    customer1.menu();
}