#include <iostream>
using namespace std;

class Competition {
protected:
    string competitionName;
    double prizeFund;
public:
    Competition(string compName = "Null", double prize = 0.0) : competitionName(compName), prizeFund(prize) {};
    virtual ~Competition() = default;
    void setPrizeFund(double value) {
        prizeFund = value;
    }

    void calculateTax(double tax) {
        tax /= 100;
        double realValue = prizeFund - prizeFund*tax;
        cout << "Prize fund after tax is: " << realValue << "€" << endl;
    }
    void isHighStakes() const {
        string state = (prizeFund >= 20000) ? "High stakes prize" : "Non high stakes prize";
        cout << state << endl;
    }
    virtual void printInfo() const = 0;
};

class TeamSport : public Competition {
protected:
    string type;
    int playerCount;
public:
    TeamSport(string objType = "Null", int objHolder = 0) : type(objType), playerCount(objHolder) { ; }

    void evaluateTeamSize() const {
        if (playerCount >= 11) {
            cout << "This sport has a big team. " << endl;
        }
        else {
            cout << "This sport has a small/medium team." << endl;
        }
    }

    bool isTeamComplete(int currentPlayers) {
        if (currentPlayers == playerCount) {
            cout << "All team players are on the field." << endl;
            return true;
        }
        else {
            cout << "Team is missing a few people. There are " << (playerCount - currentPlayers) << " missing players." << endl;
            return false;
        }
    }

    void printInfo() const override {
        cout << "Type: " << type << endl;
        cout << "Player count: " << playerCount << endl;
    }
};

class Football : public TeamSport {
protected:
    int winCount;
    string teamName;
    string stadiumName;
public:
    Football(string objType = "Contact Sport", int objPlayerCount = 11, string objName = "Null", string objStadium = "Null", int objWins = 0) : TeamSport(objType, objPlayerCount), teamName(objName), winCount(objWins), stadiumName(objStadium) {};

    void winRatio() {
        int totalMatches;
        int periodMatches;
        int periodWins;
        int answer;
        cout << "Please select an option: \n 1) Total winrate \n 2) Recent winrate \n";
        cin >> answer;
        if (answer == 1) {
            while (true) {
                cout << "Enter total match count: ";
                cin >> totalMatches;
                if (winCount <= totalMatches)
                {
                    double winrate = ((double)winCount / totalMatches) * 100;
                    cout << "Total winrate is: " << winrate << "%";
                    break;
                }
                else
                {
                    cout << "Please enter a number higher than or equal to the number of wins." << endl;
                    
                }
            }

        }
        else if (answer == 2){ 
            while (true)
            {
                cout << "Enter match count: ";
                cin >> periodMatches;
                cout << "Matches won in this period: ";
                cin >> periodWins;
                if (periodMatches >= periodWins)
                {
                    double winrate = ((double)periodWins / periodMatches) * 100;
                    cout << "Recent winrate is: " << winrate << "%";
                    break;
                }
                else
                {
                    cout << "Please enter a number higher than or equal to the number of wins." << endl;
                }


                
            }
        }
        else
        {
            cout << "Invalid prompt" << endl;
        }
    }
    void rave() const{
        cout << "WHOO ARE WEEE?!?!?" << endl;
        cout << teamName << endl;
        cout << "WHAT ARE WEEE?!?!?" << endl;
        cout << "THE GODS OF THE GODS!" << endl;
    }

    void printInfo() const override {
        TeamSport::printInfo();
        cout << "Team Name: " << teamName << endl;
        cout << "Win count: " << winCount << endl;
    }
};

class BeachFootball : public Football {
private:
    int sandQuality;
    int currentTemperature;
public:
    BeachFootball(string objType = "Beach Sport", int objPlayerCount = 5, string objName = "Null", string objStadium = "Beach", int objWins = 0, int objQuality = 0, int temp = 0) : Football(objType, objPlayerCount, objName, objStadium, objWins), sandQuality(objQuality), currentTemperature(temp) {};

    void inspect() const{
        if (sandQuality > 60) {
            cout << "The sand here is perfect for playing." << endl;
        }
        else if (sandQuality > 40)
        {
            cout << "It's not the best but it will do." << endl;
        }
        else
        {
            cout << "We're gonna get hurt if we play on this... better stick to sun bathing" << endl;
        }
    }

    void doBicycleKick() const {
        cout << "A player from " << teamName << " has done a bicycle kick and landed the ball on the sea!" << endl;
    }

    void printInfo() const override {
        Football::printInfo();
        cout << "Sand Quality: " << sandQuality << " %" << endl;
        cout << "Current Temperature: " << currentTemperature << endl;
    }
};

class Volleyball : public TeamSport {
protected:
    int winCount;
    string teamName;
    string variation;
    string stadiumName;
public:
    Volleyball(string objType = "Contact Sport", int objPlayerCount = 6, string objName = "Null", int objWins = 0, string objStadium = "Null", string objVar = "Null") : TeamSport(objType, objPlayerCount), teamName(objName), winCount(objWins), stadiumName(objStadium), variation(objVar) {};

    void win() {
        winCount++;
        cout << teamName << " have just won the game! They are currently sitting at " << winCount << " wins!" << endl;
    }

    void ballChange() const {
        cout << "A player from " << teamName << " has just sent the ball to outer space! A new one will be provided shortly." << endl;
    }

    void printInfo() const override {
        TeamSport::printInfo();
        cout << "Team Name: " << teamName << endl;
        cout << "Win count: " << winCount << endl;
        cout << "Type: " << variation << endl;
        cout << "Place: " << stadiumName << endl;
    }
};

class IndividualSport : public Competition {
protected:
    string type;
    string genderCategory;
public:
    IndividualSport(string objType = "Null", string objCategory = "Null") : type(objType), genderCategory(objCategory) { ; }

    void isEligible(string playerGender) const {
        if (genderCategory == "Mixed" || genderCategory == playerGender) {
            cout << "Player is eligible to participate." << endl;
            
        }
        else {
            cout << "Player is not eligible to participe." << endl;
        }
    }

    void dopingTest(bool result) const {
        cout << "A mandatory doping test is currently being conducted in the '" << genderCategory << " category." << endl;
        
        if (result) {
            cout << "Player has been confirmed to be doping." << endl;
        }
        else
        {
            cout << "All test came out negative." << endl;
        }
    }

    void printInfo() const override {
        cout << "Type: " << type << endl;
        cout << "Gender category: " << genderCategory << endl;
    }
};

class Tennis : public IndividualSport {
protected:
    int winCount;
    int popularity;
    int brokenRackets;
    string playerName;
    string courtSurface;
public:
    Tennis(string objType = "Null", string gCateg = "Null", string objName = "Null", int objPopularity = 0, string surface = "Null", int objWins = 0, int broken = 0) : IndividualSport(objType, gCateg), playerName(objName), popularity(objPopularity) , courtSurface(surface), brokenRackets(broken), winCount(objWins) { ; }

    void changeRacket() {
        brokenRackets++;
        cout << playerName << " has broken the Racket! This marks the " << brokenRackets << " one!" << endl;
    }
    
    void win(int add) {
        popularity += add;
        cout << playerName << " has just won the game and gained " << add << " fans!" << endl;
    }

    void printInfo() const override {
        IndividualSport::printInfo();
        cout << "Player name: " << playerName << endl;
        cout << "Preferred court surface: " << courtSurface << endl;
        cout << "Win count: " << winCount << endl;
        cout << "Fan count: " << popularity << endl;
    }
};

int main()
{
    const int size = 4;
    Competition* sports[size];
    sports[0] = new Football("Contact Sport", 11, "Beroe", "Gerena", 15);
    sports[0]->setPrizeFund(15000);
    sports[1] = new BeachFootball("Beach Sport", 5, "Boca Seniors", "Copacabana", 8, 70, 32);
    sports[1]->setPrizeFund(10000);
    sports[2] = new Volleyball("Team Sport", 6, "Hebar", 20, "Vasil Levski", "Indoor");
    sports[2]->setPrizeFund(20000);
    sports[3] = new Tennis("Racket Sport", "Men's Singles", "Grigor Dimitrov", 100000, "Clay", 45, 2);
    sports[3]->setPrizeFund(25000);
    
    for (int i = 0; i < size; i++) {
        cout << "\n======================================================\n" << endl;

        sports[i]->printInfo();
        sports[i]->calculateTax(15);
        sports[i]->isHighStakes();

        if (BeachFootball* bf = dynamic_cast<BeachFootball*>(sports[i])) {
            bf->inspect();
            bf->doBicycleKick();
        }
        else if (Football* f = dynamic_cast<Football*>(sports[i])) {
            f->rave();
            f->evaluateTeamSize();
            f->isTeamComplete(8);
            f->winRatio();
        }
        else if (Volleyball* v = dynamic_cast<Volleyball*>(sports[i])) {
            v->ballChange();
            v->win();
        }
        else if (Tennis* t = dynamic_cast<Tennis*>(sports[i])) {
            t->changeRacket();
            t->win(1000);
            t->isEligible("Men's Singles");
            t->dopingTest(false);
        }
    }

    for (int i = 0; i < size; i++) {
        delete sports[i];
    }
}

