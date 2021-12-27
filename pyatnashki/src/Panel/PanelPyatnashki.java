package Panel;

import Game.Game;
import GUI.ColorPalette;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import Game.*;

public class PanelPyatnashki extends JPanel {
    private JButton[][] buttons = new JButton[4][4];
    private ColorPalette colorPalette;
    private Game game = new Game();
    public PanelPyatnashki(GridLayout gl, ColorPalette colorPalette){
        super(gl);
        this.colorPalette = colorPalette;
        GenerateLayout();
    }
    public IndexPair getEmptyIndex(){
        return game.getEmptyIndex();
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
    public void moveLeft(boolean all){
        var emptyIndex = game.getEmptyIndex();
        if(all){
            while (emptyIndex.j!=3){
                emptyIndex = game.getEmptyIndex();
                changeByIndex(emptyIndex.i,emptyIndex.j+1);
            }
        }else {
            changeByIndex(emptyIndex.i,emptyIndex.j+1);
        }

    }
    public void moveRight(boolean all){
        var emptyIndex = game.getEmptyIndex();
        if(all){
            while (emptyIndex.j!=0){
                emptyIndex = game.getEmptyIndex();
                changeByIndex(emptyIndex.i,emptyIndex.j-1);
            }
        }else {
            changeByIndex(emptyIndex.i,emptyIndex.j-1);
        }

    }
    public void moveUp(boolean all){
        var emptyIndex = game.getEmptyIndex();
        if(all){
            while (emptyIndex.i!=3){
                emptyIndex = game.getEmptyIndex();
                changeByIndex(emptyIndex.i+1,emptyIndex.j);
            }
        }else {
            changeByIndex(emptyIndex.i+1,emptyIndex.j);
        }

    }
    public void moveDown(boolean all){
        var emptyIndex = game.getEmptyIndex();
        if(all){
            while (emptyIndex.i!=0){
                emptyIndex = game.getEmptyIndex();
                changeByIndex(emptyIndex.i-1,emptyIndex.j);
            }
        }else {
            changeByIndex(emptyIndex.i-1,emptyIndex.j);
        }

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
