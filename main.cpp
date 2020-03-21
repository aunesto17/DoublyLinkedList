//
//  main.cpp
//  AED_ListaDoblementeEnlazada
//
//  Created by Alexander Arturo Baylon Ibanez on 10/10/15.
//  Copyright © 2015 aunesto17. All rights reserved.
//

#include "lista.hpp"



int main(int argc, const char * argv[]) {
    
    doubleList<CListTrait<int>> prueba;
    
    cout << prueba.insert(10) << endl;
    cout << prueba.insert(9) << endl;
    cout << prueba.insert(8) << endl;
    cout << prueba.insert(7) << endl;
    
    prueba.printList();
    
    
    return 0;
}
