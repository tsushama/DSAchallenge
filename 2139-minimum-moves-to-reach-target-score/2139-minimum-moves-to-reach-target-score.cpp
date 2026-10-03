class Solution {
public:
    int minMoves(int target, int maxDoubles) {
       int move=0;
       while(target>1){
        if(target%2==0 && maxDoubles){
            target=target/2;
            maxDoubles--;
        }
        else if(maxDoubles==0){
            move+=target-1;
            break;
        }
        else{
            target=target-1;
        }
        move++;
       }
       return move;
    }
};