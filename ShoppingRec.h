//
//  ShoppingRec.hpp
//  WS1
//
//  Created by YiHsun  on 2021-01-16.
//

#ifndef ShoppingRec_h
#define ShoppingRec_h

namespace sdds{
    
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);

}

#endif /* ShoppingRec_h */



