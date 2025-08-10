# Student Grade Management System in C++

A command-line application developed for a Data Structures university assignment. This program allows a user to input data for multiple students (name, grades, sex) and calculates their average, approval status, and generates a final report with statistics.

### Live Demo (GIF)

![GIF of the application running](demo.gif)

---

### Features

- **Dynamic Student Entry:** Add multiple students in a single session.
- **Dynamic Grade Calculation:** The user defines the number of grades to be entered for each student.
- **Status Report:** Automatically calculates if a student is "Approved" or "Failed" based on a user-defined passing average.
- **Statistical Report:** Generates a final report including statistics of approved/failed students broken down by sex.

---

### Concepts Applied

This project was a practical exercise in fundamental C programming concepts:

- **Structs:** To model the student data structure.
- **Arrays:** To store the list of all students and the grades for each student.
- **Loops (`while`, `do-while`, `for`):** To control the application flow and iterate over data.
- **Conditional Logic (`if/else`):** To validate input and determine student status.
- **Input/Output Handling:** Using `stdio.h` (`printf`, `scanf`) to manage user interaction in the console.
- **String Manipulation:** Using `string.h` (`strcpy`) to handle text data.

---

### How to Run

This is a standard C application and can be compiled with any C/C++ compiler. Using the MSVC compiler (cl.exe):

1.  Open the Developer Command Prompt for Visual Studio.
2.  Navigate to the project directory.
3.  Compile the source code:
    ```bash
    cl main.c /EHsc
    ```
4.  Run the executable:
    ```bash
    main.exe
    ```

---

### Author

**João Vitor Roveda Bontempo**

- **LinkedIn:** `https://www.linkedin.com/in/veetgoodtime/`
- **GitHub:** `https://github.com/veetgt`
