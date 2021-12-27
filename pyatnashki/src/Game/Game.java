package Game;

import java.util.Random;

public class Game {
    private int[][] numbers = new int[4][4];
    private IndexPair emptyIndex = new IndexPair();
    public IndexPair getEmptyIndex(){
        return emptyIndex;
    }
    public Game(){
        Random generator = new Random();
        for (int i = 1; i < 16; i++) {
            int k, l;
            do {
                k = generator.nextInt(4);
                l = generator.nextInt(4);
            }
            while (numbers[k][l] != 0);
            numbers[k][l] = i;
        }
    }
    public int[][] getNumbers(){return numbers;}
    public void setNumbers(int[][] numbers) {this.numbers = numbers;}
    public GameChangeInfo changeByIndex(int i, int j){
        int num = numbers[i][j];
        if (i-1 == emptyIndex.i && j == emptyIndex.j) {
            numbers[i - 1][j] = num;
            numbers[i][j] = 0;
            emptyIndex.i = i;
            return new GameChangeInfo(i-1,j,num);
        }

        if (i+1 == emptyIndex.i && j == emptyIndex.j) {
            numbers[i + 1][j] = num;
            numbers[i][j] = 0;
            emptyIndex.i = i;
            return new GameChangeInfo(i+1,j,num);
        }

        if (i == emptyIndex.i && j-1 == emptyIndex.j) {
            numbers[i][j - 1] = num;
            numbers[i][j] = 0;
            emptyIndex.j = j;
            return new GameChangeInfo(i,j-1,num);
        }

        if (i == emptyIndex.i && j+1 == emptyIndex.j) {
            numbers[i][j + 1] = num;
            numbers[i][j] = 0;
            emptyIndex.j = j;
            return new GameChangeInfo(i,j+1,num);
        }
        return null;
    }
    public void moveLeft(boolean all){
        if(all){
            while (emptyIndex.j!=3){
                emptyIndex = getEmptyIndex();
                changeByIndex(emptyIndex.i,emptyIndex.j+1);
            }
        }else {
            changeByIndex(emptyIndex.i,emptyIndex.j+1);
        }

    }
    public void moveRight(boolean all){
        if(all){
            while (emptyIndex.j!=0){
                emptyIndex = getEmptyIndex();
                changeByIndex(emptyIndex.i,emptyIndex.j-1);
            }
        }else {
            changeByIndex(emptyIndex.i,emptyIndex.j-1);
        }

    }
    public void moveUp(boolean all){
        if(all){
            while (emptyIndex.i!=3){
                emptyIndex = getEmptyIndex();
                changeByIndex(emptyIndex.i+1,emptyIndex.j);
            }
        }else {
            changeByIndex(emptyIndex.i+1,emptyIndex.j);
        }

    }
    public void moveDown(boolean all){
        if(all){
            while (emptyIndex.i!=0){
                emptyIndex = getEmptyIndex();
                changeByIndex(emptyIndex.i-1,emptyIndex.j);
            }
        }else {
            changeByIndex(emptyIndex.i-1,emptyIndex.j);
        }

    }
    public GameChangeInfo changeByNumber(int num) {
        int i = 0, j = 0;
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                if (numbers[k][l] == num) {
                    i = k;
                    j = l;
                }
            }
        }
        return changeByIndex(i,j);
    }
}
