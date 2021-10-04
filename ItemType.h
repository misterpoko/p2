#ifndef ITEMTYPE_H 
#define ITEMTYPE_H

using namespace std;


class ItemType
  {
    public:
      ItemType();
      enum Comparison {GREATER,LESS,EQUAL}; //Need to put this back in the class and not have it as a global variabe
      Comparison compareTo(ItemType item);
      int getValue() const;
      void initialize(int num); 
      
    private:
      int value;
      
  };

#endif 