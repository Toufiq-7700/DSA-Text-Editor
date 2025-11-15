# Stack-Based Text Editor with Undo/Redo

A C++ implementation of a interactive text editor demonstrating Data Structures and Algorithms (DSA) concepts, specifically using stacks to implement undo/redo functionality.

## 🚀 Features

- **📝 Add Text**: Append new text to the current content
- **🗑️ Remove Text**: Delete specified number of characters from the end
- **↩️ Undo Functionality**: Revert to previous state using stack LIFO principle
- **↪️ Redo Functionality**: Restore undone actions using dual stack system
- **👀 View Content**: Display current text state
- **💾 State Management**: Efficient history tracking using stack data structure

## 🛠️ Technologies Used

- **C++** (Object-Oriented Programming)
- **Stack Data Structure** (Standard Template Library)
- **DSA Concepts**: LIFO, State Management, Algorithm Design

## 📋 DSA Concepts Demonstrated

### Core Data Structures:
- **Stack** (`std::stack`): Used for undo/redo history management
- **String** (`std::string`): Text content storage

### Key Algorithms:
- **Undo Algorithm**: LIFO-based state restoration
- **Redo Algorithm**: Dual-stack state management
- **State Preservation**: Efficient history tracking

## 🎯 How It Works



1. **Adding Text**: Current state saved to undo stack, redo stack cleared
2. **Undo**: Move current state to redo stack, pop from undo stack
3. **Redo**: Move current state to undo stack, pop from redo stack

## 🏃‍♂️ How to Run

### Prerequisites:
- C++ Compiler (g++, clang++, or Visual Studio)
- Standard Template Library support

### Compilation:
```bash
g++ -o text_editor main.cpp
./text_editor

=== MENU ===
1. Add Text
2. Remove Text
3. Undo
4. Redo
5. Show Current Text
6. Exit
Enter your choice (1-6): 1
Enter text to add: Hello World
Text after addition: Hello World

Enter your choice (1-6): 3
After undo: 
