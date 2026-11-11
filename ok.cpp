#include <bits/stdc++.h>
using namespace std;

int a[10005];
int n = 0;

// Read numbers from file into array
void loadFile()
{
    ifstream fin("numbers.txt");
    n = 0;
    int x;
    while (fin >> x)
    {
        n++;
        a[n] = x;
    }
    fin.close();
}

// Write array into file
void saveFile()
{
    ofstream fout("numbers.txt");
    for (int i = 1; i <= n; i++)
    {
        fout << a[i] << " ";
    }
    fout.close();
}

// Bubble sort
void sortArray()
{
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Generate random numbers (4000-5000), sort and store in file
void generateNumbers()
{
    cout << "How many numbers do you want to generate? ";
    cin >> n;
    if (n < 1 || n > 5000)
    {
        cout << "Invalid! Enter 1 to 5000." << endl;
        n = 0;
        return;
    }
    srand(time(0));
    for (int i = 1; i <= n; i++)
    {
        a[i] = 4000 + rand() % 1001;
    }
    sortArray();
    saveFile();
    cout << n << " numbers generated, sorted and saved in file." << endl;
}

// Binary search: returns position or -1
int binarySearch(int search)
{
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == search)
        {
            return mid;
        }
        else if (search < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Insert by number (keeps array sorted)
void insertNumber()
{
    if (n >= 10000)
    {
        cout << "Array is full." << endl;
        return;
    }
    int value;
    cout << "Enter number to insert: ";
    cin >> value;
    loadFile();
    int i = n;
    while (i >= 1 && a[i] > value)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = value;
    n++;
    saveFile();
    cout << value << " inserted successfully." << endl;
}

// Delete by number
void deleteNumber()
{
    int value;
    cout << "Enter number to delete: ";
    cin >> value;
    loadFile();
    int position = binarySearch(value);
    if (position == -1)
    {
        cout << "Number not found." << endl;
        return;
    }
    for (int i = position; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    saveFile();
    cout << value << " deleted successfully." << endl;
}

// Search using binary search
void searchNumber()
{
    int value;
    cout << "Enter number to search: ";
    cin >> value;
    loadFile();
    int position = binarySearch(value);
    if (position != -1)
    {
        cout << "Element found at position " << position << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
}

// Display all numbers from file
void displayNumbers()
{
    loadFile();
    if (n == 0)
    {
        cout << "File is empty." << endl;
        return;
    }
    cout << "Numbers in file (" << n << "):" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    generateNumbers();
    int choice;
    while (true)
    {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            insertNumber();
        }
        else if (choice == 2)
        {
            deleteNumber();
        }
        else if (choice == 3)
        {
            searchNumber();
        }
        else if (choice == 4)
        {
            displayNumbers();
        }
        else if (choice == 5)
        {
            cout << "Program ended." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}