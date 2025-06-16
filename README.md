
# 🛒 Corner Grocer Item Tracking Program

## Overview
This C++ program was developed for **Chada Tech** as part of a project to support the **Corner Grocer** in optimizing its produce layout. The program analyzes customer purchase data from a daily transaction log and provides frequency insights into which items are bought most often.

## 📌 Features
- ✅ Track how many times a specific item was purchased
- ✅ View a full list of all purchased items with their frequencies
- ✅ Generate a histogram to visualize item popularity
- ✅ Automatically save data to a backup file `frequency.dat`
- ✅ Menu-driven interface with input validation
- ✅ Efficient and well-documented code using C++ STL (`std::map`)

## 📁 Input
The program reads from `CS210_Project_Three_Input_File.txt`, a plain text file containing a list of purchased items (one per line).

**Example Input:**

Apples
Zucchini
Cranberries

## 💡 Output Example
### Option 2 – Frequency List:

Apples 4
Zucchini 8
Cranberries 9

### Option 3 – Histogram:

Apples ****
Zucchini ********
Cranberries *********

### Backup File:
A file named `frequency.dat` is generated automatically on launch:

Apples 4
Zucchini 8
Cranberries 9



