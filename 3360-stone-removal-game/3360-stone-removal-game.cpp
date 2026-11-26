class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 10;
        bool aliceTurn = true;

        while(n >= turn) {
            n -= turn;
            aliceTurn = !aliceTurn;
            turn--;
        }

        return !aliceTurn;
    }
};