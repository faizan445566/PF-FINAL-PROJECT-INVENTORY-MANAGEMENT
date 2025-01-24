#include<iostream>
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


