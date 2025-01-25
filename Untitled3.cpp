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
