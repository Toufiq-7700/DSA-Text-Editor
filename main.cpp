#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string content;
    stack<string> undoHistory;
    stack<string> redoHistory;
    
    void saveToHistory() {
        undoHistory.push(content);
        while (!redoHistory.empty()) {
            redoHistory.pop();
        }
    }
    
public:
    TextEditor() {
        content = "";
    }
    
    void addText(const string& inputText) {
        saveToHistory();
        content += inputText;
        cout << "Text after addition: " << content << endl;
    }
    
    void removeText(int count = 1) {
        if (content.empty() || count <= 0) {
            cout << "No text to remove!" << endl;
            return;
        }
        
        saveToHistory();
        if (count >= content.length()) {
            content = "";
        } else {
            content = content.substr(0, content.length() - count);
        }
        cout << "Text after removal: " << content << endl;
    }
    
    void performUndo() {
        if (undoHistory.empty()) {
            cout << "No actions to undo!" << endl;
            return;
        }
        
        redoHistory.push(content);
        content = undoHistory.top();
        undoHistory.pop();
        
        cout << "After undo: " << content << endl;
    }
    
    void performRedo() {
        if (redoHistory.empty()) {
            cout << "No actions to redo!" << endl;
            return;
        }
        
        undoHistory.push(content);
        content = redoHistory.top();
        redoHistory.pop();
        
        cout << "After redo: " << content << endl;
    }
    
    void showText() const {
        cout << "Current content: " << content << endl;
    }
};

void runInteractiveEditor() {
    TextEditor editor;
    int choice;
    string input;
    
    cout << "=== INTERACTIVE TEXT EDITOR ===" << endl;
    
    while (true) {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Add Text" << endl;
        cout << "2. Remove Text" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Show Current Text" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter text to add: ";
                cin.ignore();
                getline(cin, input);
                editor.addText(input);
                break;
                
            case 2:
                int removeCount;
                cout << "Enter number of characters to remove: ";
                cin >> removeCount;
                editor.removeText(removeCount);
                break;
                
            case 3:
                editor.performUndo();
                break;
                
            case 4:
                editor.performRedo();
                break;
                
            case 5:
                editor.showText();
                break;
                
            case 6:
                cout << "Thank you for using the Text Editor!" << endl;
                return;
                
            default:
                cout << "Invalid choice! Please enter 1-6." << endl;
                break;
        }
    }
}

int main() {
    runInteractiveEditor();
    return 0;
}
