#include <iostream>
#include <cstdlib>
using namespace std;


// From: http://www.dailyfreecode.com/code/inheritance-shape-class-area-2939.aspx

class shape
{
    protected:
        double b;
        double h;
    public:
        shape(double b1,double h1)
        {
            b=b1;
            h=h1;
        }
       virtual void disp_area()=0;    // method is declared as abstract/virtual pure (so, late binding is in effect AND class is not instantiable)
	  // virtual void disp_area();  // method is declared as abstract/vitual (so late binding is in effect)
	   //void disp_area();  // method is a regular method, early binding (compile time) is effect

};

class triangle :public shape
{
    public:
        triangle(double b1, double h1):shape(b1,h1)
        {
        }
        void disp_area();
};

class rectangle:public shape
{
    public:
        rectangle(double b1,double h1):shape(b1,h1)
        {
        }
        void disp_area();
};

class square:public rectangle
{
public:
        square (double b1,double h1):rectangle(b1,h1)
        {
        }
        void disp_area();
};


int main()
{
    double b1,h1;
   shape * sptr;
    
    //cout<<"\n\nPLEASE ENTER THE SHAPE DETAILS\n";
    //cout<<"BASE         = ";
    //cin>>b1;
    //cout<<"\nHeight   = ";
    //cin>>h1;
    
    //shape sh1(b1, h1);  // note, you can't create a shape if it base class has pure virtual method
    //sh1.disp_area();
 
    cout<<"\n\nPLEASE ENTER THE TRIANGLE DETAILS\n";
    cout<<"BASE         = ";
    cin>>b1;
    cout<<"\nHeight   = ";
    cin>>h1;
    
    triangle t1(b1,h1);
    sptr = & t1;
    sptr->disp_area();
    
    cout<<"\n\nPLEASE ENTER THE RECTANGLE DETAILS\n";
    cout<<"\nLENGTH  = ";
    cin>>b1;
    cout<<"\nHEIGHT = ";
    cin>>h1;
    
    rectangle r1(b1,h1);
    sptr= & r1;
    sptr->disp_area();
    
}



void triangle::disp_area()
{
    double a1;
    a1=(b*h)*1/2;
    cout<<"\nTHE AREA OF TRIANGLE IS :"<<a1 << endl;
    //getch();
}

void rectangle::disp_area()
{
    double a1;
	
    a1=b*h;
    cout<<"\nTHE AREA OF RECTANGLE IS :"<<a1 << endl;
    //getch();
}

void square::disp_area()
{
    double a1;
    a1=b*h;
    cout<<"\nTHE AREA OF SQUARE IS :"<<a1 << endl;
    //getch();
}

// This definition cannot exist for a method that is virtual pure
//void shape::disp_area()
//{ cout << "\nThis is the placeholder area function of the base class shape" << endl; cin.ignore();}
