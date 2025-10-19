# Simple College Management System

## Objective

Create a C++ program to manage student records in a college, applying OOP concepts like encapsulation, constructors, operator overloading, and deep copying.

## Requirements

### 1. Student Class

- **Attributes** (private):
  - `studentID` (string): Unique identifier (e.g., "S001").
  - `name` (string): Student’s full name.
  - `gpa` (float): GPA (0.0 to 4.0).
- **Methods** (public):
  - **Default Constructor**: Sets `studentID` and `name` to empty, `gpa` to 0.0.
  - **Parameterized Constructor**: Initializes with `studentID`, `name`, `gpa`.
  - **Copy Constructor**: Performs deep copy.
  - **Setters/Getters**: Validate `gpa` (0.0–4.0).
  - **Operator Overloading**:
    - `==`: Compares `studentID`.
    - `<<`: Prints student details.
  - **Static Member**: `totalStudents` tracks number of `Student` objects.
  - **Destructor**: Prints destruction message.

### 2. College Class

- **Attributes** (private):
  - `students`: Dynamic array of `Student` objects.
  - `capacity`: Max array size.
  - `currentSize`: Current number of students.
- **Methods** (public):
  - **Default Constructor**: Sets `capacity` to 10, `currentSize` to 0.
  - **Parameterized Constructor**: Sets custom `capacity`.
  - **Copy Constructor**: Deep copies `students` array.
  - **Add Student**: Adds a `Student` using `new`.
  - **Update GPA**: Updates GPA by `studentID`.
  - **Find Student**: Checks if `studentID` exists using `==`.
  - **Print All Students**: Uses `<<` operator.
  - **Destructor**: Deallocates `students`, prints message.
  - **Operator Overloading**:
    - `[]`: Accesses `Student` by index.
  - **Friend Function**: `swapStudents` swaps two `Student` objects by index.

### 3. Main Program

- Create a `College` with capacity 5.
- Add 3+ students.
- Demonstrate copy constructor.
- Update one student’s GPA.
- Print all students.
- Use `[]` to access a student.
- Swap two students.
- Display `totalStudents`.
- Test destructors.

## Notes

- Use `<string>` for string handling.
- Ensure proper memory management (`new`, `delete`).
- Validate inputs (e.g., GPA range).
- Test all OOP concepts from Days 1–4.