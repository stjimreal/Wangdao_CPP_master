#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	// 姓名,年龄,学号,第一学年平均成绩,第二学年平均成绩,第三学年平均成绩,第四学年平均成绩。
	char name[24];
	unsigned age, sno, sumGrade;
	double avgGrade;
	public:
	void input()
	{
		char ch;
		char word[48];
		int t;
		t = 0;
		bzero(name, 24);
		age = 0; sno = 0; sumGrade = 0;
		while((ch = getchar())!= ',')
		{
			name[t++] = ch;
		}
		t = 0;bzero(word, 48);
		while((ch = getchar())!= ',')
			word[t++] = ch;
		age = atoi(word);
		t = 0;bzero(word, 48);
		while((ch = getchar())!= ',')
			word[t++] = ch;
		sno = atoi(word);
		t = 0;bzero(word, 48);
		while((ch = getchar())!= EOF)
		{
			if(ch == ',')
			{
				sumGrade += atoi(word);
				t = 0;bzero(word, 48);
				continue;
			}
			word[t++] = ch;
		}
		sumGrade += atoi(word);
	}
	void calculate()
	{
		avgGrade = double(sumGrade) / 4.0;
	}
	void output()
	{
		cout<<name<<","<<age<<","<<sno<<","<<avgGrade<<endl;
	}

};
int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
	// printf("\10");
}