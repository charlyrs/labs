package Panel;

import Game.Game;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PanelKeyListener implements KeyListener {
    private PanelPyatnashki panel;
    private Game game;
    public PanelKeyListener(PanelPyatnashki panel, Game game){
        super();
        this.panel = panel;
        this.game = game;
    }
    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
        var emptyIndex = panel.getEmptyIndex();
        if(e.getKeyCode() == KeyEvent.VK_LEFT && emptyIndex.j < 3){
            game.moveLeft(e.isControlDown());
        }
        if(e.getKeyCode() == KeyEvent.VK_RIGHT&& emptyIndex.j > 0){
            game.moveRight(e.isControlDown());

        }
        if(e.getKeyCode() == KeyEvent.VK_UP && emptyIndex.i < 3){
            game.moveUp(e.isControlDown());

        }
        if(e.getKeyCode() == KeyEvent.VK_DOWN && emptyIndex.i > 0){
            game.moveDown(e.isControlDown());
        }
        panel.repaintPanel();
    }
    @Override
    public void keyReleased(KeyEvent e) {}
}
