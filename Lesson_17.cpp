/* Lesson 17 Notes:

Each inventory item represents an individual item in an inventory.

Just going to store a description (c-string) and quantity (int).
*/

#include <iostream>
#include <cstring>
using namespace std;
// don't but this in a header file


int main() {
    InventoryItem item1;
    InventoryItem item2("hammer");

    cout << "item1 is " << item1 << endl;
    cout << "item2 is " << item1 << endl;

    item1.setInfo("screwdriver", 5);
    item2.setUnits(9);

    cout << "item1 is " << item1 << endl;
    cout << "item2 is " << item1 << endl << endl;

    item1 = item2;
    cout << "After item1 = item2, " << endl;
    cout << "item1 is " << item1 << endl;
    cout << "item2 is " << item2 << endl;

    item2.setInfo("lawn mower", 14);
    cout << "After item2.setinfo(\"lawn mower\", 14), " << endl;
    cout << "item1 is " << item1 << endl;
    cout << "item2 is " << item2 << endl;
}


//Constructor:
InventoryItem::InventoryItem(const char* inDescription) {
    units = 0;
    description = new char[strlen(inDescription) + 1];
    strcpy(description, inDescription);
}

//Default Constructor
InventoryItem::InventoryItem() {
    units = 0;
    description = new char[1];
    strcpy(description, "");
}


void InventoryItem::setInfo(const char* inDescription, int inUnits) {

    units = inUnits;
    delete[] description;
    description = new char[strlen(inDescription) + 1];
    strcpy(description, inDescription);
}

// need to dealocate memory basically whenever it is not a constructor (always need to delete if it is already pointing at something)

void InventoryItem::setUnits(int inUnits) {
    units = inUnits;
}

ostream& operator<<(ostream& out, const InventoryItem& source) {
    out << source.units << " " << source.description;
    return out;
}

