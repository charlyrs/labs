package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.Random;

public class Panel extends JPanel {
    private JButton[][] buttons = new JButton[4][4];
    private ColorPalette colorPalette;
    private Game game = new Game();
    public Panel(GridLayout gl, ColorPalette colorPalette){
        super(gl);
        this.colorPalette = colorPalette;
        GenerateLayout();
    }

    public void GenerateLayout() {
        var numbers = game.getNumbers();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                buttons[i][j] = new JButton(Integer.toString(numbers[i][j]));
                buttons[i][j].setBackground(colorPalette.getDefaultColor());
                buttons[i][j].setForeground(Color.WHITE);
                buttons[i][j].setFont(new Font("Liliya", Font.BOLD, 20));
                buttons[i][j].setFocusable(false);
                this.add(buttons[i][j]);
                buttons[i][j].addActionListener(new PanelClickListener(this));
                if (numbers[i][j] == 0) {
                    buttons[i][j].setVisible(false);
                    game.getEmptyIndex().i = i;
                    game.getEmptyIndex().j = j;
                }
            }
        }
        repaintPanel();
    }
    public void swapLabels(int i, int j, int num){
        buttons[game.getEmptyIndex().i][game.getEmptyIndex().j].setVisible(false);
        buttons[i][j].setText(Integer.toString(num));
        buttons[i][j].setVisible(true);
    }

    public void changeByIndex(int i, int j){
        var change = game.changeByIndex(i,j);
        if (change == null){
            return;
        }
        swapLabels(change.getI(),change.getJ(),change.getLabel());
    }
    public void changeByNumber(int num) {
       var change = game.changeByNumber(num);
        if (change == null){
            return;
        }
        swapLabels(change.getI(),change.getJ(),change.getLabel());
    }
    public void processKeyEvent(KeyEvent e){
        var emptyIndex = game.getEmptyIndex();
        if(e.getKeyCode() == KeyEvent.VK_LEFT && emptyIndex.j < 3){
            if(e.isControlDown()){
                while (emptyIndex.j!=3){
                    changeByIndex(emptyIndex.i,emptyIndex.j+1);
                }
            }else { changeByIndex(emptyIndex.i,emptyIndex.j+1);}

        }
        if(e.getKeyCode() == KeyEvent.VK_RIGHT&& emptyIndex.j > 0){
            if(e.isControlDown()){
                while (emptyIndex.j!=0){
                    changeByIndex(emptyIndex.i,emptyIndex.j-1);
                }
            } else {
                changeByIndex(emptyIndex.i,emptyIndex.j-1);}

        }
        if(e.getKeyCode() == KeyEvent.VK_UP && emptyIndex.i < 3){
            if(e.isControlDown()){
                while (emptyIndex.i!=3){
                    changeByIndex(emptyIndex.i+1,emptyIndex.j);
                }
            } else {
                changeByIndex(emptyIndex.i+1,emptyIndex.j);}

        }
        if(e.getKeyCode() == KeyEvent.VK_DOWN && emptyIndex.i > 0){
            if(e.isControlDown()){
                while (emptyIndex.i!=0){
                    changeByIndex(emptyIndex.i-1,emptyIndex.j);
                }
            } else {
                changeByIndex(emptyIndex.i-1,emptyIndex.j);}
        }
        repaintPanel();
    }

    public void repaintPanel(){
        var numbers = game.getNumbers();
        int count = 1;
        boolean paint = true;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if(numbers[i][j] == count && paint){
                    buttons[i][j].setBackground(colorPalette.getWinColor());
                }else {
                    buttons[i][j].setBackground(colorPalette.getDefaultColor());
                    paint = false;
                }
                count++;
            }
        }
    }

}
