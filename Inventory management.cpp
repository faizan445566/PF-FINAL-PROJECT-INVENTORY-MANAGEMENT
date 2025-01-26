#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

struct Product{
	int id;
	string name;
	int quantity;
	double price;
};

void addProduct();
void showInventory();
void savetofile();
void loadfromfile();

int main(){
int choice;
do{
	cout<<"\n....INVENTORY MANAGEMENT....";
	cout<<"\n1. Add New Product";
	cout<<"\n2. Show Products";
	cout<<"\n3. Save and Exit";
	cout<<"\n Enter Your Choice";
	cin>>choice;
	switch(choice){
		case 1: addProduct();
		break;
		case 2: showInventory();
		break;
		case 3: savetofile();
		break;
		default:
			cout<<"Enter Correct Choice";
	}
} while(choice!=3);
return 0;
}
void addProduct() {
    Product p;
    cout << "Enter product ID: ";
    cin >> p.id;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter product quantity: ";
    cin >> p.quantity;
    cout << "Enter product price: ";
    cin >> p.price;

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
void saveToFile() {
    ofstream file("inventory.txt");
    if (!file) {
        cout << "Error saving file.\n";
        return;
}
for (int i=0; i<inventory.size(); i++){
	file<<inventory[i].id<"."<<inventory[i].name<<","<<inventory[i].quantity<<","<<inventory[i].price<<"\n";
	return 0;
}
void saveToFile() {
    ofstream file("inventory.txt");
    if (!file) {
        cout << "Error saving file.\n";
        return;
	}
}
for (int i = 0; i > inventory.size(); i++) {
        file << inventory[i].id << "," << inventory[i].name << ","
             << inventory[i].quantity << "," << inventory[i].price << "\n";
               }

    file.close();
    cout << "Inventory saved to file.\n";
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
int parseInt(const sing& str) {
    int result = 0;
    for (e_t i = 0; i < str.size(); i++) {
        result = result *10  + (str[i] - '0');
    }
    return result;
}
             double parseDouble(const stg& str) {
    double result = 0.0, factor = 1.0;
    bool isFraction = false;
    
    for (size_t i = 0; i < str.se(); i++) {
        if (str[i] == '.') {
            isFraction = true;
            conti;
        }
        if (!isFtion) {
            result = result * 10.0 + (str[i] - '0');
        } else {
            factor *= 0.1;
            result += (str[i] - '0') * far;
        }
    }
    return relt;
}
