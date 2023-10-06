#include<iostream>
using namespace std;

//Virtual Function
// class Instrument{
//     public:
//         virtual void makeSound(){
//             cout<<"Instrument is playing..."<<endl;
//         }
// };

//Pure Virtual Function -> Now this class became an abstract class as there is atleast 1 pure virtual function
class Instrument{
    public:
        virtual void makeSound() = 0;
};

class Piano : public Instrument{
    public:
        void makeSound(){
            cout<<"Piano playing..."<<endl;
        }
};

class Guitar : public Instrument{
    public:
        // If I comment this...it will throw an error as the derived class won't be having any makeSound function to override parent class' pure virtual function.
        void makeSound(){
            cout<<"Guitar playing..."<<endl;
        }
};

int main(){
    Instrument* i1 = new Piano();
    // i1->makeSound();

    Instrument* i2 = new Guitar();
    // i2 -> makeSound();

    Instrument* instruments[2] = {i1, i2};
    for(auto it: instruments){
        it -> makeSound();
    }

    return 0;
}