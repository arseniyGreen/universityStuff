#include <iostream>
#include <string>
#include <set>

class Person;

class Car
{
private:
    std::string model, vin;
    std::set<Person *> owners;

    void actualAddOwner(Person &owner) { owners.insert(&owner); }
    friend class Person;    
public:
    void setModel(std::string model_) { model = model_; }
    std::string getModel() const { return model; }
    void setVin(std::string vin_) { vin = vin_; }
    std::string getVin() const { return vin; }

     

    Car(std::string vin, std::string model, Person *owner)
	{
		this->vin = vin;
		this->model = model;
		addOwner(owner);
	}

    void addOwner(Person *newOwner);
    void removeOwner(Person *Name) { owners.erase(Name); }
    size_t getOwnersCount() const { return owners.size(); }
};

class Person
{
private:
    std::string name;
    std::set<Car *> cars;

    void actualAddCar(Car &car){ cars.insert(&car); }
    friend class Car;
public:
    Person(const std::string name) { this->name = name; }

    std::string getName() const { return name; }

    void addCar(Car &car)
    {
        actualAddCar(car);
        car.actualAddOwner(*this);
    }
    void removeCar(Car &car)
    {
        car.removeOwner(this);
    }

    size_t getCarCount() const { return cars.size(); }

};

void Car::addOwner(Person *newOwner)
{
    actualAddOwner(*newOwner);
    newOwner->actualAddCar(*this);        
}

int main(int argc, char const *argv[])
{
    Person* persons[] = 
    {
        new Person("Ivan Ivanov"),
        new Person("Ivanka Ivanova")
    };

    Car* cars[] = 
    {
        new Car("123456", "Zaporozhec", persons[0]),
		new Car("234567", "Oka", persons[1]),
		new Car("345678", "Smart", persons[1])
    };

	for (size_t i = 0; i < sizeof(persons)/sizeof(persons[0]); i++)
		std::cout << persons[i]->getName() << " has " << persons[i]->getCarCount() << " cars" << std::endl;

    // Ожидаемый вывод:
	// Ivan Ivanov has 1 cars
	// Ivanka Ivanova has 2 cars


    return 0;
}
