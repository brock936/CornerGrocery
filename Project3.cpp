// Developer : Burak Tutkavul
// Date : 06/16/2025
// Description : This program tracks item purchase frequencies from a file, allowing users to search for specific items, print all frequencies, and display a histogram of item frequencies.

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

// Class for track and manage item frequencies
class ItemTracker {
private:
    map<string, int> itemFrequency;

    // Load data from input file into the Map
    void loadItemsFromFile(const string& filename) {
        ifstream inputFile(filename);
        string item;

        if (!inputFile) {
            cerr << "Error: Could not open " << filename << endl;
            return;
        }

        while (inputFile >> item) {
            itemFrequency[item]++;
        }

        inputFile.close();
    }

    // Helper to write data to frequency.dat
    void writeFrequencyFile(const string& filename) {
        ofstream outputFile(filename);
        for (const auto& pair : itemFrequency) {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
    }

public:
    // Constructor loads data and writes backup
    ItemTracker(const string& inputFileName, const string& backupFileName) {
        loadItemsFromFile(inputFileName);
        writeFrequencyFile(backupFileName);
    }

    // 1: Find frequency of a specific item
    int getItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            return it->second;
        }
        else {
            return 0;
        }
    }

    // 2: Print all items with their frequencies
    void printItemFrequencies() const {
        cout << "\nItem Purchase Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << pair.second << endl;
        }
    }

    // 3: Print histogram of item frequencies
    void printHistogram() const {
        cout << "\nItem Frequency Histogram:\n";
        for (const auto& pair : itemFrequency) {
            cout << left << setw(15) << pair.first << string(pair.second, '*') << endl;
        }
    }
};

// Show menu options
void printMenu() {
    cout << "\n--- Corner Grocer Item Tracker ---\n"
        << "1. Search for item frequency\n"
        << "2. Print all item frequencies\n"
        << "3. Print item histogram\n"
        << "4. Exit\n"
        << "Choose an option: ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    int choice;
    string item;

    while (true) {
        printMenu();
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " was purchased " << tracker.getItemFrequency(item) << " time(s).\n";
            break;
        case 2:
            tracker.printItemFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please select between 1 and 4.\n";
        }
    }

    return 0;
}
