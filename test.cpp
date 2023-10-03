#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Toy {
public:
    Toy(string _name) : name(_name) {};
    Toy() : Toy("Basic") {};
    string getName() { return name; }
private:
    string name;
};

class Dog {
public:
    Dog(string _name, int _age) : name(_name), age(_age) {};
    Dog(string _name) : Dog(_name, 10) {};
    Dog(int age) : Dog("Sharik", age) {};
    void get_toy(shared_ptr<Toy> toy)
    {
        if (hisToy == toy)
        {
            cout << "Im already have this toy!" << endl;
        }
        else if (toy.use_count() > 2)
        {
            cout << name << "Cannot play, another dog is playing with this toy." << endl;
        }
        else
        {
            hisToy = toy;
        }
    }
    void dropToy()
    {
        if (hisToy == nullptr)
            cout << "nothing to drop" << endl;
        else
            hisToy = nullptr;
    }
private:
    string name;
    int age;
    shared_ptr<Toy> hisToy;
};

int main() {
    shared_ptr<Toy> ball = make_shared<Toy>("Ball");
    Dog sharik("Sharik", 12);
    Dog bolvan("Bolvanchik", 1);
    sharik.get_toy(ball);
    bolvan.get_toy(ball);

    sharik.dropToy();
    bolvan.get_toy(ball);

    bolvan.dropToy();
    ball.reset();
}