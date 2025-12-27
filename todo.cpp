#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> tasks;   // store tasks

void addTask() {
    cout << "Enter task: ";
    cin.ignore();
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

void viewTasks() {
    if(tasks.empty()) {
        cout << "No tasks available!\n";
        return;
    }
    cout << "\n--- To-Do List ---\n";
    for(int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". " << tasks[i] << "\n";
    }
}

void deleteTask() {
    viewTasks();
    if(tasks.empty()) return;

    int index;
    cout << "Enter task to delete: ";
    cin >> index;

    if(index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    while(true) {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: cout << "Exiting..."; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
