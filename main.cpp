/**
 * Program Cpp
 * Constructing and creating methods for Robot class
 * CS210-03
 * February 2, 2025
 * @author Ethan Truong
 */

#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
   string name;
   string model;
   int batteryLife;

public:
   // Constructor
   Robot(string n, string m, int battery): name(n), model(m), batteryLife(battery){}


   // Getter Methods
   string getName() {return name;}
   string getModel(){return model;}
   int getBatteryLife(){return batteryLife;}


   // Setter Methods
   void setName(string inputName){name=inputName;}
   void setModel(string inputModel){model=inputModel;}
   void setBatteryLife(int inputBattery){batteryLife=inputBattery;}


   // Display function
   void displayRobot() {
       cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
   }
};

// Step 2: Function to modify robot (pass by value)
void modifyRobotByValue(Robot temp) {
   temp.setBatteryLife(10); //used for indicating pass by value
   cout << "The inside function of battery life by value is: " << temp.getBatteryLife() << endl;
}


// Step 3: Function to modify robot (pass by reference)
void modifyRobotByReference(Robot& temp) {
   temp.setBatteryLife(20); //used for indicating pass by reference
   cout << "The inside function of battery life by reference is: " << temp.getBatteryLife() << endl;
}


// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
   T* robots;
   int capacity;
   int count;


public:
   // Constructor: Allocates space for 'capacity' robots
   Fleet(int cap) {
       capacity = cap;
       count = 0;
       robots = new T[capacity];
   }


   // Add robot to fleet
   void addRobot(T robot) {
       if (count < capacity) {
           robots[count] = robot;
           count++;
       } else {
           cout << "Fleet is full!\n";
       }
   }


   // Display all robots
   void showFleet() {
       cout << "Fleet contains:\n";
       for (int i = 0; i < count; i++) {
           cout << "- " << robots[i] << "\n";
       }
   }


   // Destructor: Free allocated memory
   ~Fleet() {
       delete[] robots;
   }
};


int main() {
   // Step 5: Create a Robot object
   Robot myRobot("bob", "red", 79);


   // Step 6: Use pointers to access Robot object
   Robot* robotPtr= &myRobot;
   cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";


   // Step 7: Pass by value (no change outside function)
   modifyRobotByValue(myRobot);
   cout << "After modifyRobotByValue, Battery Life: " << myRobot.getBatteryLife() << "%\n";


   // Step 8: Pass by reference (changes persist)
   modifyRobotByReference(myRobot);
   cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";


   // Step 9: Use the Fleet template class
   Fleet<string> myFleet(3);
   myFleet.addRobot("Autobot-X");
   myFleet.addRobot("Cybertron-7");
   myFleet.addRobot("NanoDroid-3");
   myFleet.addRobot("Joe!"); //checking for Fleet is full! message

   myFleet.showFleet();

   return 0;
}