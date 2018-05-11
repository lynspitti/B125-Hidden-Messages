/*
Square root is a recursive algorithm to locate the square root of a given number.
It works by first comparing an initial squared guess (quess is the square root)
to the actual square number, and if close enough (determined by a factor, epsilon)
then the algorithm returns the correct value (i.e. the 'close enough' value).

If the guess was not close enough, then the algorithm will call itself with
either a larger or lesser guess, depending on whether the initial guess was too
high or too low.
*/
#define EPS 0.1
#include <iostream>
using namespace std;

class SquareRoot1 {

private:
	float sqrt(float, float, float);
public:
    SquareRoot1(float val);
    float res;
}; // End of class definition


SquareRoot1::SquareRoot1(float val) {
	res = sqrt(val,val/2.0,0.5);
;
}

//Det her er kernen i algoritmen
float SquareRoot1::sqrt(float tal, float gaet, float step)
{
  cout << "b";
  float tmp;
  //int tohigh=1;

  tmp = gaet;

  if (((tmp-tal)*(tmp-tal))< EPS*EPS) { // Nr. 3
    cout << "\nFound " << tal << ", " << gaet;
    cout << "n";
    return (gaet);
  }
  else {
    cout << "c";
    if ((tmp+EPS)*(tmp+EPS) > tal) { // 4
      cout << "i";
      if (1) { // 6 // tohigh
        cout << "j";
       // tohigh = 1; // original value: 1
        step = 0.5*gaet*0.9;
        cout << "k";
      }
      else {
        cout << "l";
      }
      cout << "\n Too large: " << tal << ", " << tmp << ", " << step << "   Gaet size: " << gaet << "   ";
      cout << "m";
      return sqrt(tal, step, step); //1.0-step
    }
    else { // 9
      cout << "d";
      if (1) { // 10
        cout << "e";
       // tohigh = 0; // original value: 0
        step = 1.5*gaet*0.9;
        cout << "f";
      }
      else{
        cout << "g";
      }
      cout << "\n Too small: " << tal << ", " << tmp << ", " << step << "   Gaet size: " << gaet << "   ";
      cout << "h";
      return sqrt(tal, step, step);   // 11
    }
  }
}

int main(void)
{
	float f,res;
  	while (1) {
  		cout << "\nEnter a floating point number: ";
   	 	cin >> f;
   	 	cout << "a";
   		SquareRoot1 sq1(f);
    	cout << "\nsqrt(" << f << ") = " << sq1.res;
  	}
  	return 0;
}
