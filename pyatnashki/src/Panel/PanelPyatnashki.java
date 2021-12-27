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
    public Game getGame(){
        return game;
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
                buttons[i][j].addActionListener(new PanelClickListener(this, getGame()));
                if (numbers[i][j] == 0) {
                    buttons[i][j].setVisible(false);
                    game.getEmptyIndex().i = i;
                    game.getEmptyIndex().j = j;
                }
            }
        }
        repaintPanel();
    }


    public void repaintPanel(){
        var numbers = game.getNumbers();
        int count = 1;
        boolean paint = true;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                buttons[i][j].setText(Integer.toString(numbers[i][j]));
                buttons[i][j].setVisible(true);
                if (numbers[i][j] == 0) {
                    buttons[i][j].setVisible(false);
                }
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
