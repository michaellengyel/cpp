#include <iostream>
#include <string>

class Cat {
public:


    Cat() 
    {
        std::cout << "Constructor" << std::endl;
        Cat::s_numberOfCats++;
    }

    Cat(int age, int id, float weight) : m_age(age), m_id(id), m_weight(weight)
    {
        std::cout << "Constructor" << std::endl;
        Cat::s_numberOfCats++;
    }

    ~Cat() {
        std::cout << "Destructor" << std::endl;
        Cat::s_numberOfCats--;
    }

    void emitSound(std::string sound) {
        std::cout << sound << std::endl;
    }

    void printData() {
        std::cout << "Age: " << m_age << " ID: " << m_id << " Weight: " << m_weight << std::endl;
    }

    static void printNumberOfInstances() {
        std::cout << "Number of instances: " << Cat::s_numberOfCats << std::endl;
    }

private:

    int m_age = 0;
    int m_id = 0;
    float m_weight = 0.0f;

    static int s_numberOfCats; // Declaration of static member variable
};


int Cat::s_numberOfCats = 0; // Initialization of static member variable (default set to zero)

int main() {

    std::cout << "Section 1.0 - Classes" << std::endl;

    {
        Cat::printNumberOfInstances();

        Cat fluffy;
        fluffy.emitSound("Meow");
        fluffy.printData();

        Cat mavric(1, 2, 4.3);
        mavric.emitSound("Meow");
        mavric.printData();

        Cat roman{3, 4, 7.2};
        roman.emitSound("Meow");
        roman.printData();

        Cat::printNumberOfInstances();

        Cat mittens;
        Cat::printNumberOfInstances();

        std:: cout << "sizeof class: " << sizeof(Cat) << std::endl;
        std:: cout << "sizeof instance: " << sizeof(mittens) << std::endl;

        Cat* gin = new Cat();
        Cat::printNumberOfInstances();

        delete gin;
        Cat::printNumberOfInstances();
    }

    return 0;
}