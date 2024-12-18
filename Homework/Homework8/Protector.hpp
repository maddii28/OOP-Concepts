// File: Protector.hpp
// Author: Maddhav Suneja
// Description: Defines the Protector class and its derived classes (e.g., 
// Archer, Swordsman) for warriors hired by nobles.


#ifndef PROTECTOR_HPP
#define PROTECTOR_HPP

#include <string>


namespace WarriorCraft {

    class Lord;  // Forward Declaration of Noble class

    class Protector {
        friend std::ostream& operator<<(std::ostream& os, const Protector& protector);
    public:
        Protector(const std::string& name, double strength);
        const std::string& getName() const;
        double getStrength() const;
        Lord* getLord() const;
        void setStrength(double newStrength);
        void setLord(Lord* newLord);
        virtual void defend() const = 0;  // Pure virtual function for defend
        bool runaway();

    private:
        std::string name;
        double strength;
        Lord* lord;  // A Protector can belong to a Lord
    };

    class Warrior : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  // class Warrior

    class Wizard : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  // class Wizard

    class Archer : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };  // class Archer

    class Swordsman : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };  // class Swordsmen

}  // namespace WarriorCraft

#endif