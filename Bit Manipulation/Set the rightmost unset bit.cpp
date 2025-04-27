// Time complexity: O(1)
class Solution {
    public:
      int setBit(int n) {
          int flipped = ~n;
          flipped = (flipped & (flipped - 1));
          flipped = ~flipped;
          
          return flipped;
      }
  };