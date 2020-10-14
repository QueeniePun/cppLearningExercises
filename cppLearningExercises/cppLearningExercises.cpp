#include <iostream>
#include <cmath>
#define PI 3.14159

/* Note:
#include <iostream> is a preprocessor directive that tells the compiler to include iostream library
*/ 

using namespace std;

void ConvertDegreesToF();
void VolumeCylinder(); 
void FeetToMeters();
void PoundToKg();
void CalculateTips();
void SumDigitInInt();
void ConvertToLowercase();
void FindChar();
void ComputeChange(); 
void CalculateInterest();
void CalculateInvestment();
void CalculateCompoundValue();
void CalculateBMI();
void CalculateEnergy();
void CalculateWindChill();
void CalculateDistance();
void CalculateAreaOfHexagon();
void CalculateAreaOfTriangle();
void CalculateAcceleration();
void CalculateRunwayLength();

// Programming Exercises
int main()
{

	// 2.1 Converting Celsius to Fahrenheit
	// ConvertDegreesToF();

	// 2.2 Computing the volume of a cylinder
	// VolumeCylinder();

	// 2.3 Converting feet into meters 
	// FeetToMeters();

	// 2.4 Converting pounds to kg
	// PoundToKg();
	
	// 2.5 Calculate Tips
	// CalculateTips();

	// 2.6 Summing the digits in an integer 
	// SumDigitInInt();

	// 2.7 Convert to Lower
	//ConvertToLowercase();

	// 2.8 Finding the character of an ASCII code 
	//FindChar();

	// 2.9 Rewrite Listing 2.10 to fix loss of accuracy when converting double to int 
	// ComputeChange();

	// 2.10 Calculating interests
	// CalculateInterest(); 

	// 2.11 Calculate investment 
	// CalculateInvestment();

	// 2.12 CompoundValue 
	// CalculateCompoundValue();

	// 2.13 Calculate BMI
	// CalculateBMI(); 

	// 2.14 Calculate Energy 
	// CalculateEnergy();

	// 2.15 Calculate Wind Chill
	// CalculateWindChill();

	// 2.16 Printing a Table 
	// use couts to print each line 

	// 2.17 CalculateDistance 
	// CalculateDistance();

	// 2.18 Calculate Area of Hexagon 
	// CalculateAreaOfHexagon(); 

	// 2.19 Calculate Area of Triangle 
	// CalculateAreaOfTriangle();

	// 2.20 Calculate Acceleration
	// CalculateAcceleration();

	// 2.21 Calculate Runway Length
	CalculateRunwayLength();

	return 0;
   
}

void ConvertDegreesToF()
{
	double celsius;
	cout << "Enter a degree in Celsius:" << endl;
	cin >> celsius; 
	double fahrenheit = (9.0 / 5) * celsius + 32;
	cout << "Fahrenheit degree is " << fahrenheit << endl;
}

void VolumeCylinder()
{
	double radius, length;
	cout << "Enter the radius and length of a cylinder: " << endl;
	cin >> radius >> length; 
	double area = radius * radius * PI;
	cout << "The area is " << area << endl;
	double volume = area * length; 
	cout << "The volume is " << volume << endl;
}

void FeetToMeters()
{
	double feet; 
	cout << "Enter a value for feet:" << endl;
	cin >> feet;
	double meter = feet * .305; 
	cout << "The meter is " << meter << endl;
}

void PoundToKg()
{
	double pounds; 
	cout << "Enter a number in pounds:" << endl;
	cin >> pounds;
	double kg;
	kg = pounds * 0.454;
	cout << "The kilograms is " << kg << endl;
}

void CalculateTips()
{
	double subtotal, gratuityRate; 
	cout << "Enter the subtotal and gratuity rate: " << endl;
	cin >> subtotal >> gratuityRate;
	double gratuity = subtotal * (gratuityRate * 0.01);
	double total = subtotal + gratuity; 
	cout << "The gratuity is " << gratuity << " and total is " << total << endl;
}

void SumDigitInInt()
{
	int num= 0;
	cout <<	 "Enter a number between 0 and 1000:" << endl;
	cin >> num;
	int numOfOnes = num % 10;
	int numOfTens = (num / 10) % 10;
	int numOfHundreds = num / 100;
	int sum = numOfOnes + numOfTens + numOfHundreds;
	cout << "The sum of the digits is " << sum << endl;
	
}

void ConvertToLowercase()
{
	char uppercase;
	cout << "Enter an uppercase letter: " << endl;
	cin >> uppercase;
	char lowercase = (char)(uppercase + 32);
	cout << "The lowercase letter is " << lowercase << endl;
}
void FindChar()
{
	int asciiCode; 
	cout << "Enter an ASCII code: " << endl;
	cin >> asciiCode;
	char character = asciiCode; 
	cout << "The character is " << character << endl;
}

void ComputeChange()
{
	cout << "Enter an amount in in int, where last 2 digits are cents, (1156 = $11.56): ";
	int amount;
	cin >> amount;

	int remainingAmount = amount;

	int numberOfOnes = remainingAmount / 100; 
	remainingAmount = remainingAmount % 100;

	int numberOfQuarters = remainingAmount / 25; 
	remainingAmount = remainingAmount % 25;

	int numberOfDimes = remainingAmount / 10;
	remainingAmount = remainingAmount % 10;

	int numberOfNickels = remainingAmount / 5; 
	remainingAmount = remainingAmount % 5;

	int numberOfPennies = remainingAmount; 

	cout << "Your amount " << amount << "consists of \n" <<
		"\t" << numberOfOnes << "dollars\n"
		"\t" << numberOfQuarters << "quarters\n"
		"\t" << numberOfDimes << "dime\n"
		"\t" << numberOfNickels << "nickels\n"
		"\t" << numberOfPennies << "pennies\n";

}

void CalculateInterest()
{
	cout << "Enter balance and interest rate (e.g., 3 for 3%): " << endl;
	double balance, annualInterestRate;
	cin >> balance >> annualInterestRate;
	double interest = balance * ((annualInterestRate / 1200));
	cout << "The interest is " << interest << endl;
}

void CalculateInvestment()
{

	double investmentAmount;
	cout << "Enter investment amount: " << endl;
	cin >> investmentAmount;
	
	double monthlyInterestRate; 
	cout << "Enter monthly interest rate: " << endl;
	cin >> monthlyInterestRate;
	monthlyInterestRate = monthlyInterestRate / 1200;
	

	double numberOfYears;
	cout << "Enter number of years: " << endl;
	cin >> numberOfYears;
	

	double accumulatedValue = investmentAmount * pow(1 + monthlyInterestRate, numberOfYears * 12);
	cout << "Accumulated value is :" << accumulatedValue << endl;

}

void CalculateCompoundValue()
{

	double initialValue = 100; 
	double compoundValue = 0;
	for (int i = 0; i < 6; i++)
	{
		compoundValue = (initialValue + compoundValue) * 1.004177;
	}
	cout << compoundValue << endl;
}

void CalculateBMI()
{
	double weightPounds;
	cout << "Enter your weight in pounds: " << endl; 
	cin >> weightPounds; 
	double weightKilos = weightPounds * 0.45359237; 

	double heightInches;
	cout << "Enter your height in inches: " << endl;
	cin >> heightInches;
	double heightMeters = heightInches * 0.0254;

	double bmi = weightKilos / pow(heightMeters, 2); 
	cout << bmi << endl;
}

void CalculateEnergy()
{
	double M; 
	cout << "Enter the amount of water in kilograms: " << endl;
	cin >> M;
	
	double initialTemp;
	cout << "Enter the intial temperature in Celsius: " << endl;
	cin >> initialTemp;

	double finalTemp;
	cout << "Enter the final temperature in Celsius: " << endl;
	cin >> finalTemp;

	double Q = M * (finalTemp - initialTemp) * 4184;

	cout << Q << endl;
}

void CalculateWindChill()
{
	double temp, windSpeedMPH; 
	cout << "Enter the temperature in Fahrenheit: " << endl;
	cin >> temp;
	cout << "Enter the wind speed in miles per hour: " << endl;
	cin >> windSpeedMPH;

	double windChill = 35.74 + 0.6215 * temp - 35.75 * pow(windSpeedMPH, 0.16) + 0.4275 * temp * pow(windSpeedMPH, 0.16); 
	cout << "The wind-chill index is " << windChill << endl;
}

void CalculateDistance()
{
	double x1, y1, x2, y2; 
	cout << "Enter x1, y1, x2, y2: " << endl;
	cin >> x1 >> y1 >> x2 >> y2;

	double distance = pow((pow(x2 - x1, 2) + pow(y2 - y1, 2)), 0.5);
	cout << "The distance of the two points is: " << distance << endl;
}

void CalculateAreaOfHexagon()
{
	double side; 
	cout << "Enter the side: " << endl;
	cin >> side;
	
	double area = ((3 * 1.732) / 2) * pow(side, 2); 

	cout << "The area of a hexagon is " << area << endl;

}

void CalculateAreaOfTriangle()
{
	double x1, y1, x2, y2, x3, y3; 
	cout << "Enter three points for a triangle: " << endl;
	cin >> x1 >>  y1 >> x2 >> y2 >> x3 >> y3;

	double area = 0.5 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));
	cout << "The area of the triangle is: " << area << endl;
}

void CalculateAcceleration()
{
	double v0, v1, t; 
	cout << "Enter v0, v1, t: " << endl;
	cin >> v0 >> v1 >> t;

	double acceleration = (v1 - v0) / t;
	cout << "The average acceleration is: " << acceleration << endl;
}

void CalculateRunwayLength()
{
	double v, a;
	cout << "Enter v and a: " << endl;
	cin >> v >> a; 

	double length = (pow(v, 2)) / (2 * a);
	cout << "The minimum runway length for this airplane is " << length << endl;
}