# OOP-Practice
My Object Oriented Programming practice tasks using C++
#Practice on:
* defference between C and C++ - Function Overloading - Default Parameters - Reference.
* new and delete KeyWords.
* Encapsulation - Abstraction - Access modifiers.
* Set - Get.
* Constructor - Default Constructor - Constructor Overloading.
* this KeyWord.
* Operator overloading.
* Shallow and Deep Copy - Friend funcion.
* static members.
* Destructor.
* Copy Constructor.
===================
#Requirements:
Coding Task: Simple College Management System
Project Overview
You’ll create a C++ program to manage a college’s student records. The system will allow you to add students, update their grades, and display their information. This will test your understanding of classes, encapsulation, constructors, operator overloading, copy constructors, and more.
Requirements
Your program must include the following:
1.	Student Class: 
o	Attributes (private): 
	studentID (string): A unique identifier for the student (e.g., "S001").
	name (string): The student’s full name.
	gpa (float): The student’s GPA (0.0 to 4.0).
o	Methods (public): 
	Default Constructor: Initializes studentID to an empty string, name to an empty string, and gpa to 0.0.
	Parameterized Constructor: Takes studentID, name, and gpa as parameters and initializes the object.
	Copy Constructor: Creates a deep copy of a Student object.
	Setters and Getters: For studentID, name, and gpa. Ensure gpa is validated (must be between 0.0 and 4.0).
	Operator Overloading: 
	Overload the == operator to compare two Student objects based on studentID.
	Overload the << operator to print a Student object’s details (e.g., ID: S001, Name: Ahmed Mohamed, GPA: 3.5).
	Static Member: A static counter (totalStudents) to track the number of Student objects created.
	Destructor: Prints a message when a Student object is destroyed (e.g., “Student S001 destroyed”).
2.	College Class: 
o	Attributes (private): 
	students (dynamic array of Student objects): Stores all students in the college.
	capacity (int): Maximum number of students the array can hold.
	currentSize (int): Current number of students in the array.
o	Methods (public): 
	Default Constructor: Initializes students as a dynamic array with capacity of 10, currentSize to 0.
	Parameterized Constructor: Takes a custom capacity and initializes the array.
	Copy Constructor: Creates a deep copy of the College object, ensuring the students array is copied correctly.
	Add Student: Adds a new Student to the array if there’s space. Use new to allocate memory for the Student object.
	Update GPA: Takes a studentID and new gpa, updates the student’s GPA if found.
	Find Student: Takes a studentID and returns true if the student exists, false otherwise. Use the == operator.
	Print All Students: Displays all students’ details using the overloaded << operator.
	Destructor: Deallocates the students array and prints a message (e.g., “College destroyed”).
	Operator Overloading: 
	Overload the [] operator to access a Student by index (e.g., college[0] returns the first student).
o	Friend Function: A function swapStudents that swaps two Student objects in the College by their indices.
3.	Main Program: 
o	Create a College object with a capacity of 5.
o	Add at least 3 students using the parameterized constructor for Student.
o	Demonstrate the copy constructor by creating a copy of the College object.
o	Update the GPA of one student.
o	Print all students in the original College.
o	Use the [] operator to access and print one student.
o	Swap two students using the friend function.
o	Display the total number of students using the static totalStudents member.
o	Test the destructors by letting objects go out of scope.
Concepts Tested
•	Day 1: Function overloading (in constructors), default parameters (optional), references (in setters/getters), new and delete (for dynamic arrays).
•	Day 2: Encapsulation (private attributes, public methods), abstraction (hiding implementation details), access modifiers, setters/getters, constructors, constructor overloading.
•	Day 3: this keyword (in setters), operator overloading (==, <<, []), shallow vs. deep copy (copy constructor), friend function (swapStudents).
•	Day 4: Static members (totalStudents), destructor, copy constructor.
Submission
•	Write the C++ code for the entire program.
•	Share it with me (e.g., paste it in your reply or describe it if you prefer).
•	I’ll review it for correctness, clarity, and adherence to OOP principles, providing detailed feedback and suggestions.

Simple College Management System
Objective
Create a C++ program to manage student records in a college, applying OOP concepts like encapsulation, constructors, operator overloading, and deep copying.
Requirements
1. Student Class
•	Attributes (private):
o	studentID (string): Unique identifier (e.g., "S001").
o	name (string): Student’s full name.
o	gpa (float): GPA (0.0 to 4.0).
•	Methods (public):
o	Default Constructor: Sets studentID and name to empty, gpa to 0.0.
o	Parameterized Constructor: Initializes with studentID, name, gpa.
o	Copy Constructor: Performs deep copy.
o	Setters/Getters: Validate gpa (0.0–4.0).
o	Operator Overloading:
	==: Compares studentID.
	<<: Prints student details.
o	Static Member: totalStudents tracks number of Student objects.
o	Destructor: Prints destruction message.
2. College Class
•	Attributes (private):
o	students: Dynamic array of Student objects.
o	capacity: Max array size.
o	currentSize: Current number of students.
•	Methods (public):
o	Default Constructor: Sets capacity to 10, currentSize to 0.
o	Parameterized Constructor: Sets custom capacity.
o	Copy Constructor: Deep copies students array.
o	Add Student: Adds a Student using new.
o	Update GPA: Updates GPA by studentID.
o	Find Student: Checks if studentID exists using ==.
o	Print All Students: Uses << operator.
o	Destructor: Deallocates students, prints message.
o	Operator Overloading:
	[]: Accesses Student by index.
o	Friend Function: swapStudents swaps two Student objects by index.
3. Main Program
•	Create a College with capacity 5.
•	Add 3+ students.
•	Demonstrate copy constructor.
•	Update one student’s GPA.
•	Print all students.
•	Use [] to access a student.
•	Swap two students.
•	Display totalStudents.
•	Test destructors.
Notes
•	Use <string> for string handling.
•	Ensure proper memory management (new, delete).
•	Validate inputs (e.g., GPA range).
•	Test all OOP concepts from Days 1–4.
