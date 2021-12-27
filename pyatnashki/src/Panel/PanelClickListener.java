package Panel;

import Game.Game;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PanelClickListener implements ActionListener {
    private PanelPyatnashki panel;
    private Game game;
    public PanelClickListener(PanelPyatnashki panel, Game game){
        super();
        this.panel = panel;
        this.game = game;
    }
    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        String name = button.getText();
        game.changeByNumber(Integer.parseInt(name));
        panel.repaintPanel();
    }
}
