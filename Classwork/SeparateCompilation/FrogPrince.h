// FrogPrince.h
// 24F - Sec A

#ifndef FROGPRINCE_H
#define FROGPRINCE_H

#include <iostream>
#include <string>

namespace Fantasy {

    class Princess;

    class FrogPrince {
        friend std::ostream& operator<<(std::ostream& os, const FrogPrince& rhs);
    public:
        FrogPrince(const std::string& name);
        const std::string& getName() const;
        void setSpouse(Princess*);
    private:
        std::string name;
        Princess* spouse;
    };

}

#endif // FROGPRINCE_H
