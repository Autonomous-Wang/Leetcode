#include <iostream>
using namespace std;
 
class Box
{
protected:
	double width; // can only be accessed by public function 
};

class SmallBox:Box
{
public:
	void setSmallWidth(double wid);
	double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void)
{
	return width;
}

void SmallBox::setSmallWidth(double wid)
{
	width = wid;
}

int main()
{
	SmallBox box;
	box.setSmallWidth(10.0);
	cout << "width of box: " << box.getSmallWidth() << endl;

}