#include <iostream>
#include <string>
#include <iomanip>        // setw()
#include <algorithm>     // transform Function
#include <ctime>        // Time Function

using namespace std;

using usi = unsigned short int ;

//Global Variable
usi beatPc{},beatHum{};

// Function
string pc();
void rules(string,string);
void sleep ();

int main() {

    usi count{},round{3}; // Counter & Number Of Round
    string human,computer;

    // Game Start After
    cout<<setw(33)<<"Game Start After"<<endl;
    for(int i{3};i>0;i--) {
        cout<<setw(25)<<i<<endl;
        sleep();
    }
    cout<<"me";
    cout<<setw(50)<<"PC";
    cout<<endl;
    for(int i{};i<53;i++) cout<<"-";
    cout<<endl;

    do {
        // Human Turn
        cin>>human;
        // Pc Turn
        computer = pc();
        cout<<setw(55)<<computer<<endl;

        // Convert input String To lowerCase
        transform(human.begin(),human.end(),human.begin(),::tolower);

        // Game Rules
        if( human == computer )
        {
            count   =  0;
            beatPc  =  0;
            beatHum =  0;
            cout<<setw(25)<<"Tie"<<endl;
            continue;
        } else {
            rules(human,computer);}

        count++;

    }while(count < round);

    cout<<(beatHum > beatPc ? "You Win :)" : "You Lose :(")<<endl;

    system("pause");
}

string pc()
{
    string beats[]{"rock","paper","scissors"};
    srand(time(nullptr));
    return beats[(rand()%3)];
}

void rules(string hum,string pc)
{
    // Rock Beats Scissors & Paper Beats Rock
    if (hum == "rock")
    {
        if(pc == "paper") beatPc++;
        else    beatHum++;
    }
    // Scissors Beats paper & Rock Beats Scissors
    if (hum == "scissors")
    {
        if(pc == "paper") beatHum++;
        else    beatPc++;
    }
    // Paper beats Rock && Scissors beats Paper
    if (hum == "paper")
    {
        if(pc == "scissors") beatPc++;
        else    beatHum++;
    }
}

void sleep ()
{
    for(size_t i{} ; i < 1000000000;i++); // Do nothing
}
