/*
Square root is a recursive algorithm to loctate the square root of a given number.
It works by first comparing an initial squared guess (quess is the square root)
to the actual square number, and if close enough (determined by a factor, epsilon)
then the algorithm returns the correct value (i.e. the 'close enough' value).

If the guess was not close enough, then the algorithm will call itself with
either a larger or lesser guess, depending on wether the initial guess was too
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
	res = sqrt(val*val,val/2.0,0.5);
;
}

//Det her er kernen i algoritmen
float SquareRoot1::sqrt(float tal, float gaet,float step)
{
 float tmp;
 int tohigh=1;

  tmp = gaet*gaet;

  cout << "C";
  if (((tmp-tal)*(tmp-tal))< EPS*EPS) {
    cout << "\nFound " << tal << ", " << gaet;
    return (gaet);
  }
  else {
    if (tal+EPS > tmp) {
      if (tohigh) {
        tohigh = 1;
        step = 0.5*step;
      }
      cout << "\n Too large: " << tal << ", " << tmp << ", " << step;
      return sqrt(tal, (1.0-step)*gaet,step);
    }
    else {
      if (!tohigh) {
        tohigh = 0;
        step = 0.5;
      }
      cout << "\n Too small: " << tal << ", " << tmp << ", " << step;
      return sqrt(tal, (1.0+step)*gaet,step);
    }
  }
}

int main(void)
{
	float f,res;
  	while (1) {
      cout << "A";
  		cout << "\nEnter a floating point number: ";
   	 	cin >> f;
   	 	cout << "B";
   		SquareRoot1 sq1(f);
   		cout << "K";
    	cout << "\nsqrt(" << f << ") = " << sq1.res;
    	cout << "L";
  	}
  	return 0;
}
