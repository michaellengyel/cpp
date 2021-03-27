#include <iostream>
#include <string>

//*******************************
//*****************Animal******** <- Pure Virtual Class
//*****************/***\*********
//****************/*****\********
//***************/*******\*******
//*********Mammel*********Bird*** <- Pure Virtual Class
//*******/*\*****\*******/*******
//******/***\*****\*****/********
//*****/*****\*****\***/*********
//**Cat******Dog***Platypus****** <- Instantiatable Class
//****\**************************
//*****\*************************
//******\************************
//****Siamese******************** <- Instantiatable Class, "final" (can't be derived from)
//*******************************

// Abstract Animal class due to pure virtual function
class Animal
{
public:

    Animal() {
        std::cout << "Animal C'tor" << std::endl;
    }

    ~Animal() {
        std::cout << "Animal D'tor" << std::endl;
    }

    // Pure virtual function
    virtual void move() = 0;

};

// Abstract Mammer class due to pure virtual function
class Mammel : public Animal
{
public:

    Mammel() {
        std::cout << "Mammel C'tor" << std::endl;
    }

    ~Mammel() {
        std::cout << "Mammel D'tor" << std::endl;
    }

    virtual void move() override
    {
        std::cout << "Mammel::move(): Walk" << std::endl;
    }

    // Pure virtual function
    virtual void neocortex() = 0;
};

// Abstract Bird class due to pure virtual function
class Bird : public Animal
{
public:

    Bird()
    {
        std::cout << "Bird C'tor" << std::endl;
    }

    ~Bird()
    {
        std::cout << "Bird D'tor" << std::endl;
    }

    void move() override
    {
        std::cout << "Bird::move(): Fly" << std::endl;
    }

    // Pure virtual function
    virtual void beak() = 0;
};

class Cat : public Mammel
{
public:

    Cat()
    {
        std::cout << "Cat C'tor" << std::endl;
    }

    ~Cat()
    {
        std::cout << "Cat D'tor" << std::endl;
    }

    void move()
    {
        std::cout << "Cat::move(): Strut around, Climb trees, Jump on table" << std::endl;
    };

    // virtual keyword hints that functon might be overridden in a derived class
    // override keyword checks if virtual function exists in parent class
    virtual void neocortex() override
    {
        std::cout << "Cat::neocortex(): Meow, Play, Look out window, Chase mice, Contemplate world domination." << std::endl;
    };

};

class Dog : private Mammel
{
public:

    Dog()
    {
        std::cout << "Dog C'tor" << std::endl;
    }

    ~Dog()
    {
        std::cout << "Dog D'tor" << std::endl;
    }

    using Mammel::move;

    // override keyword checks if virtual function exists in parent class
    void neocortex() override
    {
        std::cout << "Dog::neocortex(): Bork, Play, Look at cat, Chase mailman, Dream about loyal stuff." << std::endl;
    };
};

class Platypus : public Mammel, public Bird
{
public:

    Platypus() {
        std::cout << "Platypus C'tor" << std::endl;
    }

    ~Platypus() {
        std::cout << "Platypus D'tor" << std::endl;
    }

    // using keyword clarifies which parent classe's move function is inherited by default
    using Mammel::move;

    void beak() override
    {
        std::cout << "Platypus::beak(): Peck." << std::endl;
    }

    // override keyword checks if function exists in parent class
    void neocortex() override
    {
        std::cout << "Platypus::neocortex(): Do Duck, Trout, Beaver stuff." << std::endl;
    };
};

// final keyword ensures you can't derive from Siamese class
class Siamese final : public Cat
{
public:

    Siamese() {
        std::cout << "Siamese C'tor" << std::endl;
    }

    ~Siamese() {
        std::cout << "Siamese D'tor" << std::endl;
    }

    // override keyword checks if function exists in parent class
    void neocortex() override
    {
        std::cout << "Siamese::neocortex(): Howl like a demon from hell, Contemplate world domination." << std::endl;
    };

};

int main() {

    std::cout << "Section 1.0 - Inheritance\n\n";

    {
        std::cout << "Creating Siamese instance:\n";
        Siamese siamese;
        siamese.move();
        siamese.neocortex();
    }
    std::cout << "\n";

    {
        std::cout << "Creating Cat instance:\n";
        Cat cat;
        cat.move();
        cat.neocortex();
    }
    std::cout << "\n";

    {
        std::cout << "Creating Dog instance:\n";
        Dog dog;
        dog.move();
        dog.neocortex();
    }
    std::cout << "\n";

    {
        std::cout << "Creating Platypus instance:\n";
        Platypus platypus;
        platypus.move();        // Using move() defined as default by "using" keyword in Platypus class
        platypus.Bird::move();  // Using move() defined by Bird parent class
        platypus.beak();
        platypus.neocortex();
    }
    std::cout << "\n";

    return 0;
}