
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    char name[30];
    float cgpa;
};

int main() {
    Student *s = NULL, temp;
    int n = 0, ch, key;

    do {
        cout << "\n1.Add Student  2.Display";
        cout << "\n3.Linear Search  4.Binary Search";
        cout << "\n5.Sort Name  6.CGPA Ascending";
        cout << "\n7.CGPA Descending  8.Compare Search";
        cout << "\n0.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            // Expand memory for new student
            Student *p = (Student*)realloc(s, (n+1)*sizeof(Student));
            if (p == NULL) {
                cout << "Memory allocation failed!";
                break;
            }
            s = p;

            cout << "Enter ID: ";
            cin >> s[n].id;
            cout << "Enter Name: ";
            cin.ignore();
            cin.getline(s[n].name, 30);
            cout << "Enter CGPA: ";
            cin >> s[n].cgpa;
            n++;
        }

        else if (ch == 2) {
            for (int i = 0; i < n; i++)
                cout << s[i].id << " " << s[i].name
                     << " " << s[i].cgpa << endl;
        }

        else if (ch >= 3 && ch <= 4 || ch == 8) {
            cout << "Enter ID: ";
            cin >> key;

            int pos = -1, count = 0;

            // Linear Search
            for (int i = 0; i < n; i++) {
                count++;
                if (s[i].id == key) {
                    pos = i;
                    break;
                }
            }

            if (ch == 3 || ch == 8) {
                cout << "Linear comparisons: " << count << endl;
                if (pos != -1)
                    cout << "Found: " << s[pos].name << endl;
                else
                    cout << "Not Found\n";
            }

            if (ch == 4 || ch == 8) {
                // Sort IDs before Binary Search
                for (int i = 0; i < n-1; i++)
                    for (int j = 0; j < n-i-1; j++)
                        if (s[j].id > s[j+1].id)
                            swap(s[j], s[j+1]);

                int low = 0, high = n-1, mid;
                pos = -1;
                count = 0;

                // Binary Search
                while (low <= high) {
                    mid = (low+high)/2;
                    count++;

                    if (s[mid].id == key) {
                        pos = mid;
                        break;
                    }
                    else if (s[mid].id < key)
                        low = mid+1;
                    else
                        high = mid-1;
                }

                cout << "Binary comparisons: " << count << endl;
                if (pos != -1)
                    cout << "Found: " << s[pos].name << endl;
                else
                    cout << "Not Found\n";
            }
        }

        else if (ch >= 5 && ch <= 7) {
            if (ch == 5) {
                // Bubble Sort by Name
                for (int i = 0; i < n-1; i++)
                    for (int j = 0; j < n-i-1; j++)
                        if (strcmp(s[j].name, s[j+1].name) > 0)
                            swap(s[j], s[j+1]);
            }
            else {
                // Selection Sort by CGPA
                for (int i = 0; i < n-1; i++) {
                    int pos = i;

                    for (int j = i+1; j < n; j++) {
                        if ((ch == 6 && s[j].cgpa < s[pos].cgpa) ||
                            (ch == 7 && s[j].cgpa > s[pos].cgpa))
                            pos = j;
                    }
                    swap(s[i], s[pos]);
                }
            }
            cout << "Sorting completed!\n";
        }

    } while (ch != 0);

    free(s);  // Release allocated memory
    return 0;
}
