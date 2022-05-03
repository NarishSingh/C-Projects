using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    Person();
    Person(string name, int age);

    int GetAge() const {
        return age;
    }

    void SetAge(int age) {
        this->age = age;
    }

    string GetName() const {
        return name;
    }

    void SetName(string name) {
        this->name = name;
    }


private:
    string name;
    int age;
};

#endif /* PERSON_H */

