#include <iostream>
using namespace std;

class Student{
	protected:
	int roll_number;
};
class Exam : public virtual Student{//virtual keyword to avoid clash on roll_number when being accessed in Result
	protected:
	int score;
};
class Sports : public virtual Student{
	protected:
	int marks;
};

class Result : public Exam,public Sports{
	protected:
	int total;
	public:
	void set_params(int roll_no,int a,int b){
		score=a;
		marks=b;
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
