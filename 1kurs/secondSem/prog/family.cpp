#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Human
{
private:
    std::string name;
    std::vector<Human *> parents;
    std::vector<Human *> children;

    void actualAddParent(Human &parent) { parents.push_back(&parent); }
    void actualAddChild(Human &child) { children.push_back(&child); }
public:
    Human(std::string name)
    {
        if(name.empty())
            throw std::invalid_argument("Name is empty!");

        this->name = name;
    }

    void setName(std::string name_){ name = name_; }
    std::string getName() const { return name; }

    void addParent(Human *parent) //текущий экземпляр, для которого вызывается метод -  ребёнок
    {
        actualAddParent(*parent);
        actualAddChild(*this);
    }
    void addChild(Human *child) //текущий экземпляр, для которого вызывается метод -  родитель
    {
        actualAddChild(*child);
        actualAddParent(*this);
    }
    void getParents()
    {
        for(size_t i = 0; i < 2; ++i)
            std::cout << this->getName() << " is a child of " << this->parents[i] << std::endl;
    }

};


int main(int argc, char const *argv[])
{
    Human grandfather("John"); //father of Nick
    Human grandmother("Kate"); //mother of Sofia
    Human mother("Sofia"); // Daughter of Kate and mother of Alex
    Human father("Nick"); // Son of John and father of Alex
    Human son("Alex"); // Son of Nick and Sofia, grandchild of John and Kate

    grandfather.addChild(&father);
    grandmother.addChild(&mother);
    mother.addChild(&son);
    father.addChild(&son);

    son.getParents();

    return 0;
}
