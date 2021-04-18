/*
 Section:   NII
 Date:      2021/02/04
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
class Food {
    char m_foodName[31];
    int m_calorieNum;
    int m_consumptionTime;
    void setName(const char* name);
    
public:
    void setEmpty();
    void set(const char* name, int calorie, int time);
    void display()const;
    bool isValid()const;
    int calorie()const;
    int time()const;
};
}

#endif // !SDDS_FOOD_H
