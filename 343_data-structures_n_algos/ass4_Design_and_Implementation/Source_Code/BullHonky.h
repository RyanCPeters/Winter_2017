//
// Created by Peter on 2/21/2018.
//

#ifndef ASS4_DESIGN_AND_IMPLEMENTATION_BULLHONKY_H
#define ASS4_DESIGN_AND_IMPLEMENTATION_BULLHONKY_H


class BullHonky {
private:
    int localCount{1};
    int anotherLocal;
    static int someCount{0};
public:
    
    //ctor
    BullHonky(const int &ref):anotherLocal(ref){};

};


#endif //ASS4_DESIGN_AND_IMPLEMENTATION_BULLHONKY_H
