#include <iostream> 
#include <string>

using namespace std;

class Transistor{
    
    private:
        string resType ; 
        double coef ; 
        double maxC ;

    public: 
    
    Transistor(){
        resType = " nothing" ;
        coef =  0  ; 
        maxC = 0 ;
    }

    Transistor(string t, double i, double c) {
        resType = t;
        coef = i;
        maxC = c;
    }
        

    void input(){
        string line;
        cout<< " enter Transistor type" ;

        getline(cin, line);

        if (line.empty()) {
            resType = "nothing";
            coef =  0  ; 
            maxC = 0 ;
            return ;    
        } 
        else {
            resType = line;
        }
        
        cout << "enter coefficient  ";
        getline(cin, line);
        if (line.empty()) {
            coef = 0.0;
        } else {
            coef = stod(line);
        }








        cout<< " Enter max current :" ;\
        getline(cin, line);
        if (line.empty()) {
            maxC = 0.0;
        } else {
            maxC = stod(line);
        }
        
    }
    void show(){
        cout << " Type :" << resType << '\n' ;
        cout << " coefficient " << coef << '\n' ; 
        cout << " Max current " << maxC << '\n' ;
    }
        

    ~Transistor(){
        cout << " Transistor destroyed" ;
    }
};


int main() {

    Transistor r1;   
    r1.input();    
    cout << "result ";
    r1.show();

    return 0;
}