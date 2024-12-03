#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Wagon {
    int number;         
    int totalSeats;     
    int occupiedSeats;  

public:
  
    Wagon(int num, int seats) : number(num), totalSeats(seats), occupiedSeats(0) {}

    int getFreeSeats() const { return totalSeats - occupiedSeats; }

    bool occupySeat() {
        if (occupiedSeats < totalSeats) {
            occupiedSeats++;
            return true;
        }
        return false;
    }

    bool freeSeat() {
        if (occupiedSeats > 0) {
            occupiedSeats--;
            return true;
        }
        return false;
    }

    bool isFullyOccupied() const { return occupiedSeats == totalSeats; }
};


class Station {
    string name;        
    string city;        

public:
    
    Station(const string& n, const string& c) : name(n), city(c) {}

    string getName() const { return name; }
    string getCity() const { return city; }
};


class Train {
    string name;                
    int number;                 
    Station station;             
    vector<Wagon> wagons;        

public:
   
    Train(const string& n, int num, const Station& st) : name(n), number(num), station(st) {}

    string getStationName() const { return station.getName(); }

    double getAverageFreeSeats() const {
        if (wagons.empty()) return 0;
        int totalFreeSeats = 0;
        for (const auto& wagon : wagons) {
            totalFreeSeats += wagon.getFreeSeats();
        }
        return static_cast<double>(totalFreeSeats) / wagons.size();
    }

    void addWagon(int num, int seats) {
        wagons.emplace_back(num, seats);
    }

    bool occupySeatInWagon(int wagonNumber) {
        if (wagonNumber >= 0 && wagonNumber < wagons.size()) {
            return wagons[wagonNumber].occupySeat();
        }
        return false;
    }

    bool freeSeatInWagon(int wagonNumber) {
        if (wagonNumber >= 0 && wagonNumber < wagons.size()) {
            return wagons[wagonNumber].freeSeat();
        }
        return false;
    }

    int getTotalFreeSeats() const {
        int totalFreeSeats = 0;
        for (const auto& wagon : wagons) {
            totalFreeSeats += wagon.getFreeSeats();
        }
        return totalFreeSeats;
    }

    double getFullyOccupiedPercentage() const {
        if (wagons.empty()) return 0;
        int fullyOccupiedCount = 0;
        for (const auto& wagon : wagons) {
            if (wagon.isFullyOccupied()) {
                fullyOccupiedCount++;
            }
        }
        return (static_cast<double>(fullyOccupiedCount) / wagons.size()) * 100;
    }
};


int main() {
    Station station("Central Station", "Kyiv");
    Train train("Express", 101, station);

    
    train.addWagon(1, 50);
    train.addWagon(2, 60);
    train.addWagon(3, 40);

    cout << "Вокзал: " << train.getStationName() << endl;
    cout << "Середня кількість вільних місць: " << train.getAverageFreeSeats() << endl;

   
    train.occupySeatInWagon(0);
    train.occupySeatInWagon(0);

    cout << "Загальна кількість вільних місць: " << train.getTotalFreeSeats() << endl;

    
    train.freeSeatInWagon(0);

    cout << "Відсоток повністю зайнятих вагонів: " << train.getFullyOccupiedPercentage() << "%" << endl;

    return 0;
}
