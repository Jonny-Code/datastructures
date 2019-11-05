//Jon Sledge
//COP2535.001
//student names and scores using array and struct

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;



struct Data				//in structs everything is public. no inheritence, no polymorphism
{
	string name;
	float score;
};

//prototypes
void sort(Data *a, const int SIZE);
float average(Data *a, int SIZE);
void display(Data *a, const int SIZE, const float avg);

int main()
{
	int numStudents;		//number of students to be entered
	Data *studentData;		//pointer to dynamically allocated array of Data
	float avg;				//calculate avg

	//determine the number of students to be entered
	cout << "Enter the number of students : ";
	cin >> numStudents;

	studentData = new Data[numStudents];

	//get score from the user
	cout << "Enter the " << numStudents
		<< " name and score pairs separated by spaces\n";

	Data *p = studentData;		//pointer object to student data array of Data structs

	//loop through the input
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Enter name and score: ";
		cin >> p->name;
		cin >> p->score;

		
		if (p->score < 0 || !cin)
		{
			cout << "No negative scores, try again: ";
			cin.clear();
			fseek(stdin, SEEK_END, 0);
			cin >> p->score;
		}
		//increment p
		p++;
	}

	//Echo back the values entered
	cout << "Data entered: " << endl;
	
	p = studentData;

	for (int j = 0; j < numStudents; j++)
	{
		cout << p->name << '\t' << p->score << endl;
		p++;
	}

	//sort the array
	sort(studentData, numStudents);

	//compute the average
	avg = average(studentData, numStudents);

	//display the output
	display(studentData, numStudents, avg);

	return 0;
}

//--------------fucntion definitions---------------------//

float average(Data *a, int SIZE)
{
	float sum = 0;

	//set the pointer to the beginning of the array
	Data *p = a;

	for (int k = 0; k < SIZE; k++)
	{
		sum += p->score;
		p++;
	}

	return sum / SIZE;
}

//sort the array
void sort(Data *a, const int SIZE)
{
	for (int k = SIZE - 1; k >= 1; k--)
	{
		//find the maximum of a[0,k]
		Data *max = a;

		for (Data *p = a + 1; p != a + k + 1; p++)
		{
			if (p->score > max->score)
				max = p;
		}
		//swap *max with *a
		swap(*max, *(a + k));
	}
}

void display(Data *a, const int SIZE, const float avg)
{
	Data *p = a;

	cout << "The list of students sorted by scores is: " << endl;

	for (int m = 0; m < SIZE; m++)
	{
		cout << p->name << '\t' << p->score << endl;
		p++;
	}

	cout << endl << endl;
	cout << "The average is: " << avg << endl << endl;
}