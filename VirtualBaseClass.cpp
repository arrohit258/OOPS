#include <iostream>
using namespace std;

class Student{
	protected:
	int roll_number;
	public:
	Student(){
		cout<<"Student Created"<<endl;
	}
};
class Exam : protected virtual Student{//virtual to avoid roll_number conflict as Exam and Sports dono se ayega
	protected:
	int score;
	public:
	Exam(){
		cout<<"Exam created"<<endl;
	}
};
class Sports : public virtual Student{
	protected:
	int score;
	public:
	Sports(){
		cout<<"Sports created"<<endl;
	}
};

class Result : public Exam,protected Sports{
	protected:
	int total;
	public:
	Result(){
		cout<<"Result created"<<endl;
	}
	void set_params(int roll_no,int a,int b){
		Exam::score=a; // Ambuiguity handle karne ko
		Sports::score=b; //
		roll_number=roll_no;
		total=a+b;
	}
	void show(){
		cout<<roll_number<<" "<<total<<endl;

	}
};
int main()
{
    Result rohit;
   rohit.set_params(420,50,60);
   rohit.show();
    return 0;
}

/*
OUTPUT 

Student Created
Exam created
Sports created
Result created
420 110




*/
