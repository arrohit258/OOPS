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
	Exam(int a){
		score=a;
		cout<<"Exam created "<<a<<endl;
	}
};
class Sports : public virtual Student{
	protected:
	int score;
	public:
	Sports(int a){
		score=a;
		cout<<"Sports created "<<a<<endl;
	}
};

class Result : public Exam,protected Sports{
	protected:
	int total;
	public:
	
	Result(int roll_no,int a,int b) : Exam(a),Sports(b){//parametrized for constructors for base class
		cout<<"Result Created\n";
		roll_number=roll_no;
		total=Exam::score + Sports::score;
	}
	void show(){
		cout<<roll_number<<" "<<total<<endl;

	}
};
int main()
{
    Result rohit = Result(420,50,60);
 
   rohit.show();
    return 0;
}

/*
OUTPUT 

Student Created
Exam created 50
Sports created 60
Result Created
420 110




*/
