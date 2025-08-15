# Windows Based Library System

A comprehensive Windows-based Library Management System built with C++ and Qt Framework, demonstrating advanced object-oriented programming concepts, template usage, and custom library integration.

## Project Setup
### Prerequisites

- Qt Framework 6.x or 5.x
- CMake 3.16 or higher
- C++ Compiler with C++17 support (MinGW, MSVC, or GCC)
- Qt Creator (recommended IDE)

## Project Structure Requirements
This project consists of two separate components that must be set up correctly:

1. Main Application - Library Management System
2. Custom Library - LibraryUtils (separate project)

## Setup Instructions

### Step 1 Download project

```
downloaded_project/
├── Windows-Based-Library-Management-System/  (Main project)
└── LibraryUtils/                             (Custom library)
```
### Step 2: Build the Custom Library First

- Open Qt Creator
- File → Open File or Project
- Navigate to LibraryUtils folder
- Open CMakeLists.txt
- Configure with your Qt kit
- Build the library (Ctrl+B)
- Note the build output path 

### Step 3: Build the Main Application

- In Qt Creator, File → Open File or Project
- Navigate to Windows-Based-Library-Management-System folder
- Open CMakeLists.txt
- Configure with your Qt kit
- Verify library path in CMakeLists.txt matches your LibraryUtils - build location
- Build the main application (Ctrl+B)
- Run the application (Ctrl+R)

### Important Notes

- Both projects must be built for the application to work
- Relative paths are used - maintain the folder structure as shown
- Library builds first - the main application depends on LibraryUtils
- Build configurations must match (Debug/Release) between library and main app

## Features

### Core Functionality
- **Add Books and Magazines** - Easy input with validation
- **Search Functionality** - Find items by title with real-time filtering
- **Sort Operations** - Sort by title or author alphabetically
- **Data Persistence** - Automatic save/load functionality
- **Input Validation** - Popup warnings for invalid entries

### Technical Features
- **Object-Oriented Design** - Inheritance hierarchy with LibraryItem base class
- **Template Programming** - Generic Storage<T> class for type-safe containers
- **Custom Qt Library** - Separate LibraryUtils library for utility functions
- **Professional GUI** - Clean interface with Qt Widgets
- **File Handling** - Persistent data storage between sessions

## Usage

### Adding Items
1. Enter **Title** and **Author**
2. Select **Book** or **Magazine** radio button
3. Click **Add Item**
4. Item appears in the list below

### Searching
1. Type search term in the **search box**
2. Click **Search** button
3. Results are filtered and displayed

### Sorting
- Click **Sort by Title** for alphabetical title sorting
- Click **Sort by Author** for author name sorting

### Data Persistence
- Data is **automatically saved** when adding items
- Data is **automatically loaded** when starting the application
- Stored in `library_data.txt` in the application directory

## Technical Implementation

### Object-Oriented Programming
- **Inheritance** - LibraryItem → Book/Magazine hierarchy
- **Polymorphism** - Virtual displayInfo() methods
- **Encapsulation** - Protected member variables with proper access

### Template Programming
- **Generic Storage<T>** class for type-safe containers
- **Template functions** for adding, removing, and searching
- **STL integration** with std::vector

### Custom Library Usage
- **LibraryUtils** separate library for utility functions
- **Static methods** for file operations, searching, and sorting
- **Clean separation** of concerns between GUI and business logic

## Requirements Fulfilled

- **Class Design (OOP Concepts)** 
- **Use of Qt Lists and Containers** 
- **Use of Custom Qt Library** 
- **Implementation of Generics (Templates)** 
- **Graphical User Interface using Qt Widgets** 
- **File Handling for Data Persistence** 

