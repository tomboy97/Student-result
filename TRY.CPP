#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
class student
{
	protected:
	int rollno,ptr;
	char name[10];
	float phy,chem,math,tot,av;
	public:
	void getdata();
	void getf();
	void putdata();
	void display();
	float total();
	float average();
};
float student::total()
{
	return(phy+chem+math);
}
float student::average()
{
	return(total()/3);
}
void student::getdata()
{
	cout<<"Roll number: ";
	cin>>rollno;
	cout<<endl;
	cout<<"Name: ";
	cin>>name;
	cout<<endl;
	cout<<"Marks in physics, chemistry and maths: ";
	cin>>phy>>chem>>math;
	cout<<endl;
}
void student::putdata()
{
	cout<<"\nRoll number: "<<rollno<<endl;
	cout<<"Name: "<<name<<endl;
	cout<<"Total Marks: "<<total()<<endl;
	cout<<"Average marks: "<<average();
	cout<<"\n";
}
void student::getf()
{
	int size;
	student ob;
	fstream out;
	out.open("c:\\lucky.doc",ios::app);
	ob.getdata();
	out.write((char *)&ob,sizeof(ob));
	out.close();
}
void student::display()
{
	fstream inj;
	student ob;
	inj.open("c:\\lucky.doc",ios::in);
	if(!inj)
		cout<<"\nCannot open file,";
	else
	{
		while((inj.read((char *)&ob,sizeof(ob)))!=NULL)
		ob.putdata();
	}
	inj.close();
}
void main()
{
clrscr();
int num;
char ch;
student stu;
cout<<setw(55)<<"Welcome to the academic block!!!";
cout<<endl<<endl<<endl;
cout<<setw(62)<<"You can see ur result by entering ur marks: "<<endl;
cout<<setw(109)<<setfill('*')<<"\n\nSelect one of the options: "<<endl;
cout<<"1. Add the data."<<endl;
cout<<"2. Display all the students result."<<endl;
cout<<"3. Exit."<<endl;
do
{
	cout<<setw(10)<<"Enter the choice of ur option: ";
	cin>>num;
	switch(num)
	{
		case 1:
		stu.getf();
		break;
		case 2:
		stu.display();
		break;
		case 3:
		exit(0);
		break;
	}
	cout<<endl;
	cout<<setw(10)<<"Do u want to continue: ";
	cin>>ch;
}
while(ch=='y');
getch();
}