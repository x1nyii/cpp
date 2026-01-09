/*
Target practise #15.1:   
-	A car game/simulator models a number of different car models. Design the various base/non-base classes for use, for a generic car with the following description:
  o	Components of a car: 
    >	Characteristics: Total weight, max speed, max acceleration, max turn radius
    > Chassis: 3, 4 or 7 seater
      •	Characteristics: Weight, size
    > Engine:
      •	Characteristics: Power, weight
    >	Wheels  
      •	Characteristics: Rim type (Beadlock, split, safety), wheel type (steel, allow, carbon filter), Weight
    >	Seats
      •	Characteristics: Leather, PU Leather, Cloth

Restrictions, assumptions:
-	Methods in classes need not be implemented
-	These classes / base classes will be used in future via inheritance
-	Create a set of classes that derive/reuse/inherit from these set of classes – use fictitious values for illustration purposes rather than based on real-world research – to create a car model.
-	Illustrate the above using Class Diagram(s) in UML
*/

#include <iostream>
#include <string>
using namespace std;


// since there is nothing to abstract in common for the classes, no base class is needed.
/// <summary> Base class for all car components</summary>
//class CarComponent 
//{
//public:
//    /// <summary>Default constructor</summary>
//    CarComponent() {}
//
//    /// <summary>Virtual destructor for proper cleanup of derived classes</summary>
//    virtual ~CarComponent() {}
//};


/// <summary>Base class for chassis</summary>
class CarChassis //: public CarComponent 
{
public:
    /// <summary>Number of seats (3, 4, or 7)</summary>
    int numSeats;
    /// <summary>Weight of the chassis</summary>
    float weight;
    /// <summary>Size of the chassis</summary>
    float size;

    // CarChassis() {}// need to have your own constructor as creation of line 40 will no longer provide default constructor

    /// <summary>Constructor initializing chassis characteristics</summary>
    /// <param name="seats"></param>
    /// <param name="weight"></param>
    /// <param name="size"></param>
    CarChassis(int seats=0, float weight=0, float size=0)
        : numSeats(seats), weight(weight), size(size) {}

    /// <summary>Destructor</summary>
    ~CarChassis() {}
};


/// <summaryBase class for engine</summary>
class CarEngine //: public CarComponent 
{
public:

    /// <summary>Engine power</summary>
    float power;
    /// <summary>Engine weight</summary>
    float weight;

    /// <summaryConstructor initializing engine characteristics</summary>
    /// <param name="power"></param>
    /// <param name="weight"></param>
    CarEngine(float power=0, float weight=0)
        : power(power), weight(weight) {}

    /// <summary>Destructor</summary>
    ~CarEngine() {}
};

/// <summary>Base class for wheels</summary>
class CarWheels //: public CarComponent 
{
public:
    /// <summary>Rim type (Beadlock, Split, Safety)</summary>
    string rimType;
    /// <summary>// Wheel type (Steel, Alloy, Carbon Fiber)</summary>
    string wheelType;
    /// <summary>// Weight of the wheels</summary>
    float weight;

    /// <summary>Constructor initializing wheel characteristics</summary>
    /// <param name="rim"></param>
    /// <param name="wheel"></param>
    /// <param name="weight"></param>
    CarWheels(string rim="", string wheel="", float weight=0)
        : rimType(rim), wheelType(wheel), weight(weight) {}

    /// <summary>Destructor</summary>
    ~CarWheels() {}
};

/// <summaryBase class for seats</summary>
class CarSeats //: public CarComponent 
{
public:
    /// <summary> Material of the seat (Leather, PU Leather, Cloth)</summary>
    string material;

    /// <summaryConstructor initializing seat characteristics</summary>
    /// <param name="material"></param>
    CarSeats(string material = "")
        : material(material) {}

    /// <summary>Destructor</summary>
    ~CarSeats() {}
};

/// <summaryClass representing a generic car with basic</summary>
class Car // must be self sufficient, will work on its own
{
public:
    // Characteristics of a car

    /// <summary>Total weight of the car</summary>
    float totalWeight;
    /// <summary>Maximum speed the car can achieve</summary>
    float maxSpeed;
    /// <summary>Maximum acceleration of the car</summary>
    float maxAcceleration;  // Maximum acceleration 
    /// <summary>Maximum turning radius of the car</summary>
    float maxTurnRadius;

    // need to include other instances: wheel, engine
    CarChassis Chassis; // declaration of an instance of car chassis
    CarEngine Engine;
    CarWheels Wheel;
    CarSeats Seats;

    /// <summaryConstructor initializing the car characteristics</summary>
    /// <param name="weight"></param>
    /// <param name="speed"></param>
    /// <param name="acceleration"></param>
    /// <param name="turnRadius"></param>
    Car(float weight, float speed, float acceleration, float turnRadius, CarChassis chassis, CarEngine engine, CarWheels wheel, CarSeats seats)
        : totalWeight(weight), maxSpeed(speed), maxAcceleration(acceleration), maxTurnRadius(turnRadius) {} // , Chassis(chassis), Engine(engine), Wheel(wheel), Seats(seats) 

    /// <summary>Destructor</summary>
    ~Car() {}
};

/// <summary>A derived class representing a specific car model</summary>
class SportsCar : public Car
{
public:
    // when inherit a base class, must call constructor of inherited class

    /// <summary>Constructor initializing a specific sports car with arbitrary values</summary>
    SportsCar(float weight, float speed, float acceleration, float turnRadius, CarChassis chassis, CarEngine engine, CarWheels wheel, CarSeats seats)
        : Car(weight, speed, acceleration, turnRadius, chassis, engine, wheel, seats) {}  // Set random generic values for sports car characteristics
    
    // another method
    //SportsCar(CarChassis chassis, CarEngine engine, CarWheels wheel, CarSeats seats)
    //    : Car(400, 200, 50, 2, chassis, engine, wheel, seats) {}  // Set random generic values for sports car characteristics

    /// <summary>Destructor</summary>
    ~SportsCar() {}
};


int main() 
{
    cout << "Hello beloved car owner... (i took a lot of effort to put this together) - by your sincere car seller" << endl;

    // define a constructor then fill in

    // Output basic details of the sports car (for illustration purposes)
    // Create other components
    // mega cinstructor
    CarChassis myChassis(4, 500, 2.5);
    CarEngine myEngine(400, 300);
    CarWheels myWheels("Beadlock", "Alloy", 100);
    CarSeats mySeats("Leather");

    // Creating a sports car object
    // declaring instance of the object
    SportsCar xinyiCar(400, 200, 50, 2, myChassis, myEngine, myWheels, mySeats); // have all the class included

    // Output car details directly in main()
    cout << "Car Details: " << endl;
    cout << "Total Weight: " << xinyiCar.totalWeight << " kg" << endl;
    cout << "Max Speed: " << xinyiCar.maxSpeed << " km/h" << endl;
    cout << "Max Acceleration: " << xinyiCar.maxAcceleration << " m/s^2" << endl;
    cout << "Max Turn Radius: " << xinyiCar.maxTurnRadius << " meters" << endl;

    // Output chassis details
    cout << "\nChassis Details: " << endl;
    // cout << "Number of Seats: " << myChassis.numSeats << endl;
    cout << "Number of Seats: " << xinyiCar.Chassis.numSeats << endl; // composition
    cout << "Weight: " << xinyiCar.Chassis.weight << " kg" << endl;
    cout << "Weight: " << myChassis.weight << " kg" << endl;
    cout << "Size: " << myChassis.size << " meters" << endl;

    // Output engine details
    cout << "\nEngine Details: " << endl;
    cout << "Power: " << myEngine.power << " HP" << endl;
    cout << "Weight: " << myEngine.weight << " kg" << endl;

    // Output wheels details
    cout << "\nWheels Details: " << endl;
    cout << "Rim Type: " << myWheels.rimType << endl;
    cout << "Wheel Type: " << myWheels.wheelType << endl;
    cout << "Weight: " << myWheels.weight << " kg" << endl;

    // Output seats details
    cout << "\nSeats Details: " << endl;
    cout << "Material: " << mySeats.material << endl;
    return 0;
}
