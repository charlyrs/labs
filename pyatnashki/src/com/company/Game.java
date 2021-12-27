package com.company;

import java.util.Random;

public class Game {
    private int[][] numbers = new int[4][4];
    private Pair emptyIndex = new Pair();
    public Pair getEmptyIndex(){
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
