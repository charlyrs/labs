package Panel;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PanelKeyListener implements KeyListener {
    private PanelPyatnashki panel;
    public PanelKeyListener(PanelPyatnashki panel){
        super();
        this.panel = panel;
    }
    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
        var emptyIndex = panel.getEmptyIndex();
        if(e.getKeyCode() == KeyEvent.VK_LEFT && emptyIndex.j < 3){
            panel.moveLeft(e.isControlDown());
        }
        if(e.getKeyCode() == KeyEvent.VK_RIGHT&& emptyIndex.j > 0){
            panel.moveRight(e.isControlDown());

        }
        if(e.getKeyCode() == KeyEvent.VK_UP && emptyIndex.i < 3){
            panel.moveUp(e.isControlDown());

        }
        if(e.getKeyCode() == KeyEvent.VK_DOWN && emptyIndex.i > 0){
            panel.moveDown(e.isControlDown());
        }
        panel.repaintPanel();
    }
    @Override
    public void keyReleased(KeyEvent e) {}
}
