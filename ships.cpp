
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class Ship 
{
public:
    Ship() 
    {
        this->name = "";
    }
    Ship(string name) 
    {
        this->name = name;
    }
    void changeToNULL() 
    {
        this->name = "";
    }
    bool isNULL() 
    {
        if (name == "")
        {
            return true;
        }
        return false;
    }
    string getName() 
    {
        return name;
    }
private:
    string name;
};


int main() {
    ofstream fout("shipsout.txt");
    ifstream fin("shipsin.txt");
    int N;
    fin >> N;
    string line;
    queue<Ship> ships;
    vector<Ship> shipsInPort;
    shipsInPort.resize(N);
    fout << "Port start working.\n" << endl;
    while (getline(fin, line)) 
    {
        if (line[0] == '1') 
        {
            string name;
            for (int i = 2; i < line.size(); i++)
                name += line[i];
            Ship ship(name);
            if (ships.empty()) 
            {
                bool isAdded = false;
                for (int i = 0; i < N; i++) 
                {
                    if (shipsInPort[i].isNULL()) 
                    {
                        shipsInPort[i] = ship;
                        isAdded = true;
                        fout << "The " << ship.getName() << " ship sucñessfully entered the port.\n";
                        break;
                    }
                }
                if (!isAdded) 
                {
                    ships.push(ship);
                    fout << "The " << ship.getName() << " ship is waiting for place in port.\n";
                }
            }
            else 
            {
                ships.push(ship);
                fout << "The " << ship.getName() << " ship is waiting for place in port.\n";
            }
            fout << endl;
            continue;
        }
        if (line[0] == '2') 
        {
            fout << "The " << shipsInPort[(line[2] - '0') - 1].getName() << " ship left the port.\n";
            shipsInPort[(line[2] - '0') - 1].changeToNULL();
            if (!ships.empty()) 
            {
                shipsInPort[line[2] - '0' - 1] = ships.front();
                fout << "The " << ships.front().getName() << " ship sucñessfully entered the port.\n";
                ships.pop();
            }
            fout << endl;
            continue;
        }
        if (line[0] == '3') 
        {
            if (ships.empty()) 
            {
                fout << "The queue to the port is empty. Nobody is waiting entering the port.\n";
            }
            else {
                fout << "There're " << ships.size() << " ships still waiting:\n";
                queue<Ship> fake = ships;
                while (!fake.empty()) 
                {
                    fout << "   The " << fake.front().getName() << endl;
                    fake.pop();
                }
            }
            fout << endl;
            continue;
        }
        if (line[0] == '4') 
        {
            fout << "There're " << shipsInPort.size() << " docks: " << endl;
            for (int i = 0; i < shipsInPort.size(); i++) 
            {
                fout << "   " << i + 1 << " dock: ";
                if (shipsInPort[i].isNULL())
                {
                    fout << "this dock is free.\n";
                }
                else
                {
                    fout << shipsInPort[i].getName() << " is staying at this dock.\n";
                }
            }
            fout << endl;
            continue;
        }
    }
    fout.close();
    fin.close();
    return 0;
}
