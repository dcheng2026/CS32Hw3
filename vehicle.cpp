#include <iostream>
#include <string>
using namespace std;

class Vehicle{

public: 

    virtual bool canHover() const {
        return true; 
    }
    Vehicle(string make) {
        name = make; 
        hover = true; 
    }
    virtual ~Vehicle() {}
    virtual string description() const = 0; 
    string id () const {
        return name; 
    }

private: 
    string name; 
    bool hover; 

};


class Drone: public Vehicle {
public:
    Drone(string name) :Vehicle(name) {}

  
    virtual string description() const {
        return "a drone";
    }

    virtual ~Drone() {
        cout << "Destroying " << id() << ", a drone" << endl; 
    }
  
};

class Balloon: public Vehicle {
public: 

    Balloon(string a, double b) : Vehicle(a) { diameter = b; }

    virtual string description() const {
        if (diameter < 8) {
            return "a small balloon";
        }
        else {
            return "a large balloon";
        }
            
    }

    virtual ~Balloon() {
        cout << "Destroying the balloon " << id() << endl;
    }
    
private: 
    double diameter; 
};

class Satellite : public Vehicle {
public: 
    Satellite(string c) :Vehicle(c) {}

    virtual bool canHover() const {
        return false;
    }
    virtual string description() const {
        return "a satellite"; 
    }
    virtual ~Satellite () {
        cout << "Destroying the satellite " << id() << endl;
    }
    
};





void display(const Vehicle* v)
{
    cout << v->id() << " is " << v->description();
    if (v->canHover())
        cout << ", so it can hover";
    cout << endl;
}

int main()
{
    Vehicle* fleet[4];
    fleet[0] = new Drone("CB4UP");
    // Balloons have an id and a diameter in meters  Balloons with a
    // diameter under 8 meters are small balloons; those with a diameter
    // 8 meters or more are large balloons
    fleet[1] = new Balloon("99LB", 6.3);
    fleet[2] = new Balloon("CN20230201", 30.2);
    fleet[3] = new Satellite("EB8675309");

    for (int k = 0; k < 4; k++)
        display(fleet[k]);

    // Clean up the vehicles before exiting
    cout << "Cleaning up" << endl;
    for (int k = 0; k < 4; k++)
        delete fleet[k];

}

