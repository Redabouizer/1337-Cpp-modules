#include <iostream>

class Mere {
public:
    virtual void affiche() { std::cout << "Mere" << std::endl; }
};

class Fille : public Mere {
public:
    void affiche() { std::cout << "Fille" << std::endl; }
};

int main() {
    Fille zbi;
    Mere  *a = &zbi;
    a->affiche();
}