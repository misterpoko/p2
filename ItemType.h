#ifndef ITEMTYPE_H 
#define ITEMTYPE_H

using namespace std;

class ItemType
  {
    public:
      ItemType();
      enum Comparison {GREATER,LESS,EQUAL};
      Comparison compareTo(ItemType item);
      int getValue() const;
      void initialize(int num); 
      
    private:
      int value;
      
  };

#endif 