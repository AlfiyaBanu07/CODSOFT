#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Function to add a task to the list
    void add_task(const string& desc) {
        tasks.emplace_back(desc);
        cout << "Task added: " << desc << endl;
    }

    // Function to view all tasks
    void view_tasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    // Function to mark a task as completed
    void mark_completed(size_t index) {
        if (index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    // Function to remove a task
    void remove_task(size_t index) {
        if (index < tasks.size()) {
            cout << "Task removed: " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList todo;

    while (true) {
        cout << "\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string desc;
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, desc);
                todo.add_task(desc);
                break;
            }
            case 2:
                todo.view_tasks();
                break;
            case 3: {
                cout << "Enter task index to mark as completed: ";
                size_t index;
                cin >> index;
                todo.mark_completed(index - 1); // Adjust index to 0-based
                break;
            }
            case 4: {
                cout << "Enter task index to remove: ";
                size_t index;
                cin >> index;
                todo.remove_task(index - 1); // Adjust index to 0-based
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}