// File: Noble.hpp
// Author: Maddhav Suneja
// Description: Defines the Noble class and the Lord class for managing 
// nobles and their armies in the WarriorCraft game.


#ifndef NOBLE_HPP
#define NOBLE_HPP

#include <string>
#include <vector>
#include "Protector.hpp"

namespace WarriorCraft {

    class Protector;

    class Noble {
    public:
        Noble(const std::string& name);
        const std::string& getName() const;
        void battle(Noble& enemy);
        void die();
        virtual double getStrength() const = 0;
        virtual void updateStrength(double winner_strength, double loser_strength) = 0;
        virtual void defend() const = 0;

    protected:  
        void changeAliveStatus();
        bool getAliveStatus() const;

    private:  
        std::string name;
        bool alive;
    };  

    class Lord : public Noble {
        friend std::ostream& operator<<(std::ostream& os, const Lord& lord);
    public:
        Lord(const std::string& name);
        double getStrength() const override;
        void updateStrength(double winner_strength, double loser_strength) override;
        void defend() const override;
        bool hires(Protector& protector);
        bool fires(Protector& protector);
        bool remove(Protector& someprotector);

    private:
        std::vector<Protector*> army;  // List of Protectors hired by this Lord
    };

    class PersonWithStrengthToFight : public Noble {
        friend std::ostream& operator<<(std::ostream& os, const PersonWithStrengthToFight& person);
    public:
        PersonWithStrengthToFight(const std::string& name, double strength);
        double getStrength() const override;
        void updateStrength(double winner_strength, double loser_strength) override;
        void defend() const override;

    private:
        double strength;
    };

}

#endif
