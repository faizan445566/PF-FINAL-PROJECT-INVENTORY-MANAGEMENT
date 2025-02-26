#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

struct Product{
	int id;
	string name;
	int quantity;
	double price;
};
vector<Product> inventory;

void addProduct();
void showInventory();
void editProduct();
void saveToFile();
void loadFromFile();

int parseInt(const string& str);
double parseDouble(const string& str);

int main(){
loadFromFile();

int choice;
do{
	cout<<"\n=====INVENTORY MANAGEMENT=====";
	cout<<"\n1. Add New Product";
	cout<<"\n2. Show Products";
	cout<<"\n3. Edit Product";
	cout<<"\n4. Save and Exit";
	cout<<"\n Enter Your Choice: ";
	if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
	switch(choice){
		case 1: addProduct();
		break;
		case 2: showInventory();
		break;
		case 3: editProduct();
		break;
		case 4: saveToFile();
		break;
		default:
			cout<<"Enter Correct Choice";
	}
} while(choice!=4);
return 0;
}
void addProduct() {
    Product p;
    cout << "Enter product ID: ";
    while (!(cin >> p.id)) {
        cout << "Invalid ID. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter product quantity: ";
    while (!(cin >> p.quantity)) {
        cout << "Invalid quantity. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cout << "Enter product price: ";
    while (!(cin >> p.price)) {
        cout << "Invalid price. Please enter a numeric value: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    inventory.push_back(p);
    cout << "Product added successfully.\n";
}
void showInventory() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "ID\tName\t\tQuantity\tPrice\n";
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].id << "\t" << inventory[i].name<< "\t" << "\t"<<inventory[i].quantity<< "\t\t" << inventory[i].price << "\n";
    }
}
void editProduct() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Nothing to edit.\n";
        return;
    }

    int id;
    cout << "Enter the product ID to edit: ";
    while (!(cin >> id)) {
        cout << "Invalid ID. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].id == id) {
            cout << "Product found. Enter new details:\n";
            cout << "Enter new name (current: " << inventory[i].name << "): ";
            cin.ignore();
            getline(cin, inventory[i].name);
            cout << "Enter new quantity (current: " << inventory[i].quantity << "): ";
            while (!(cin >> inventory[i].quantity)) {
                cout << "Invalid quantity. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            cout << "Enter new price (current: " << inventory[i].price << "): ";
            
			while (!(cin >> inventory[i].price)) {
                cout << "Invalid price. Please enter a numeric value: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
            cout << "Product updated successfully.\n";
            return;
        }
    }
    cout << "Product with ID " << id << " not found.\n";
}
void saveToFile() {
    ofstream file("inventory.txt");
    if (!file) {
        cout << "Error saving file.\n";
        return;
    }

    for (size_t i = 0; i < inventory.size(); ++i) {
    file << inventory[i].id << ',' << inventory[i].name << ',' << inventory[i].quantity << ',' << inventory[i].price << '\n';
}

    file.close();
    cout << "Inventory saved to file.\n";

   cout << "ID\tName\t\tQuantity\tPrice\n";
    for (int i = 0; i < inventory.size(); i++) {
        cout << inventory[i].id << "\t" << inventory[i].name<< "\t" << "\t"<<inventory[i].quantity<< "\t\t" << inventory[i].price << "\n";
    }
}
   
void loadFromFile() {
    ifstream file("inventory.txt");
    if (!file) {
        cout << "No file found. Starting fresh.\n";
        return;
    }
string line;
    while (getline(file, line)) {
        Product p;
        size_t pos =0;
        pos = line.find(',');
        p.id = parseInt(line.substr(0, pos));
        line.erase(0, pos + 1);

        pos = line.find(',');
        p.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(',');
        p.quantity = parseInt(line.substr(0, pos));
        line.erase(0, pos + 1);

        p.price = parseDouble(line);

        inventory.push_back(p);
    }
    
    file.close();
    cout << "Inventory loaded from file.\n";
}
int parseInt(const string& str) {
    int result = 0;
    for (size_t i = 0; i < str.size(); i++) {
        result = result *10  + (str[i] - '0');
    }
    return result;
}
double parseDouble(const string& str) {
    double result = 0.0, factor = 1.0;
    bool isFraction = false;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            isFraction = true;
            continue;
        }
        if (!isFraction) {
            result = result * 10.0 + (str[i] - '0');
        } else {
            factor *= 0.1;
            result += (str[i] - '0') * factor;
        }
    }
    return result;
}
