#include<iostream>
using namespace std;
void line()
{
	cout << "-------------------------------------------------\n";
}

//Student
class Student
{
private:
	string studentID, name;
	float gpa;

public:
	//static variable
	static int totalStudents;

	//Constructor
	Student()
	{
		this->studentID = "";
		this->name = "";
		this->gpa = 0.0;

		Student::totalStudents++;
	}
	//Parameterized Constructor
	Student(string studentID, string name, float gpa)
	{
		this->studentID = studentID;
		this->name = name;
		this->gpa = gpa;

		Student::totalStudents++;
	}

	//Copy Constructor
	Student(const Student &c)
	{
		this->studentID = c.studentID;
		this->name = c.name;
		this->gpa = c.gpa;

		Student::totalStudents++;
	}

	//Setters
	void setStudentID(string studentID)
	{
		this->studentID = studentID;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setGPA(float gpa)
	{
		if (gpa >= 0.0 && gpa <= 4.0)
		{
			this->gpa = gpa;
		}
		else
		{
			this->gpa = 0.0;
		}
	}
	//Getters
	string getStudentID()
	{
		return this->studentID;
	}
	string getName()
	{
		return this->name;
	}
	float getGPA()
	{
		return this->gpa;
	}

	static void DisplayTotalStudents()
	{
		cout << "Total Students: " << Student::totalStudents << '\n';
	}

	//Operator overload for '=='
	bool operator==(Student s2)
	{
		if (this->studentID == s2.studentID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Operator Overload for '<<' (friend function)
	friend ostream& operator<<(ostream& cout,  Student& s);

	//Destructor
	~Student()
	{
		//cout << "Student " << this->studentID << " destroyed\n";
		Student::totalStudents--;
	}
};
//static variable initialization
int Student::totalStudents = 0;

//Operator Overload for '<<' (friend function) Impelementation
ostream& operator<<(ostream& cout, Student& s)
{
	cout << "ID: " << s.studentID
		 << "\tName: " << s.name
		 << "\tGPA: " << s.gpa << '\n';
	return cout;
}

//College
class College
{
//private:
public:
	int capacity;
	Student* students; //pointer of type Student: to make ddynamic array of Student from him
	int currentSize;

public:
	//constructor
	College()
	{
		this->currentSize = 0;
		this->capacity = 10;
		this->students = new Student[capacity];
	}
	//parameterized constructor
	College(int capacity)
	{
		this->capacity = capacity;
		this->students = new Student[capacity];

		this->currentSize = 0;
	}
	//Copy Constructor
	College(const College& OldC)
	{
		//this now points to NewC
		this->capacity = OldC.capacity;
		this->currentSize = OldC.currentSize;

		this->students = new Student[OldC.capacity];

		for (int i = 0; i < OldC.capacity; ++i)
		{
			this->students[i] = OldC.students[i];
		}
	}

	//Methods:
	void AddStudent(Student s)
	{
		if (this->currentSize < this->capacity)
		{
			this->students[this->currentSize] = s;
			currentSize++;
			cout << "Student added Successfully.\n";
		}
		else
		{
			cout << "Faild: there is no capacity!\n";
		}
	}
	//
	void UpdateGPA(string studentID, float NewGPA)
	{
		bool flag = true;
		for (int i = 0; i < this->currentSize; ++i)
		{
			if (this->students[i].getStudentID() == studentID)
			{
				this->students[i].setGPA(NewGPA);
				cout << "GPA Updated Successfully\n";
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << "StudentID not found!\n";
		}
	}
	//
	bool FindStudent(string studentID)
	{
		for (int i = 0; i < this->currentSize; ++i)
		{
			if (this->students[i].getStudentID() == studentID)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//= overload
	College operator=(College C)
	{
		//this now points to NewC
		this->capacity = C.capacity;
		this->currentSize = C.currentSize;

		this->students = new Student[C.capacity];

		for (int i = 0; i < C.capacity; ++i)
		{
			this->students[i] = C.students[i];
		}

		return (*this);
	}

	//[] overload
	const Student& operator[](int index)
	{
		return (this->students[index]);
	}


	//Operator Overload for '<<' (friend function)
	friend ostream& operator<<(ostream& cout, College& c);

	//swapStudents (friend function)
	friend void swapStudents(const Student& s1, const Student& s2);

	//Destructor
	~College()
	{
		delete[] this->students;
		cout << "College destroyed";
	}
};

//Operator Overload for '<<' (friend function)
ostream& operator<<(ostream& cout, College& c)
{
	cout << "-----------------------All Student-----------------------\n";
	for (int i = 0; i < c.currentSize; ++i)
	{
		cout << c.students[i];
	}
	cout << "----------------------------------------------------------\n";
	return cout;
}

//swapStudents (friend function)
void swapStudents(Student& s1, Student& s2)
{
	Student sTemp = s1;
	s1 = s2;
	s2 = sTemp;
}

////////////////////////////////////////////////////////////////////////////////////////

int main()
{

//My test:
/*
{
	//Test class Student:

	Student s1;
	s1.setName("Ahmed");
	s1.setStudentID("S1853");
	s1.setGPA(3.6);

	cout << s1 << '\n';

	Student s2;
	s2.setName("Omar");
	s2.setStudentID("S2635");
	s2.setGPA(3.7);

	cout << s2 << '\n';

	Student s3 = s1;

	cout << s3 << '\n';

	if (s1 == s2)
	{
		cout << "s1 == s2" << '\n';
	}
	else
	{
		cout << "s1 != s2" << '\n';
	}

	if (s1 == s3)
	{
		cout << "s1 == s3" << '\n';
	}
	else
	{
		cout << "s1 != s3" << '\n';
	}

	Student::DisplayTotalStudents();

	cout << "////////////////////////////////////////////////////////////////\n";

	/////////////////////////////////////

	//Test class Student:
	College C(10);

	C.AddStudent(s1);

	C.students[1].setStudentID("S3845");
	C.students[1].setName("Mohamed");
	C.students[1].setGPA(3.5);
	C.currentSize++;

	C.AddStudent(s2);

	cout << C.students[0] << '\n';

	cout << C;

	College NewC = C;  //Need deep copy
	//NewC = C;//Also work because i make = overload //NewC = C => NewC.operator=(C)

	cout << NewC;

	NewC.students[2].setStudentID("---");
	NewC.students[2].setName("---");
	NewC.students[2].setGPA(0.0);

	cout << C;
	cout << NewC;

	C.UpdateGPA("S3845", 3.8);
	cout << C;

	C.UpdateGPA("S0000", 3.8);

	cout << C;

	line();

	//C[0]; => C.operator[](0);

	Student s0 = C[0];
	cout << s0;

	line();

	cout << "Before Swap:\n";
	cout << C;

	//Swap
	swapStudents(C.students[0], C.students[1]);

	cout << "After Swap:\n";
	cout << C;

}*/

	//Main Program:
	
	//Create a College with capacity 5
	College college(5);

	//Add 3+ students.
	Student s1("S1", "Ahmed", 3.5);
	Student s2("S2", "Omar", 3.7);
	Student s3("S3", "Mohamed", 3.6);

	college.AddStudent(s1);
	college.AddStudent(s2);
	college.AddStudent(s3);

	cout << "college:\n";
	cout << college;

	//Demonstrate copy constructor.
	College NewCollege = college;

	//Update one student’s GPA.
	NewCollege.students[0].setGPA(3.6);
	cout << "NewCollge:\n";
	cout << NewCollege;

	//Print all students.
	cout << "college:\n";
	cout << college;

	//Use [] to access a student.
	Student s0 = college[0];
	cout << s0;

	//Swap two students.
	swapStudents(college.students[0], college.students[1]);
	cout << "college:\n";
	cout << college;

	//Display totalStudents.
	Student::DisplayTotalStudents();

	//Test destructors.
	{
		Student s;
		Student::DisplayTotalStudents();
	}

	Student::DisplayTotalStudents();

	return 0;
}