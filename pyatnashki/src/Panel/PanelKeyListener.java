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
        panel.processKeyEvent(e);
    }
    @Override
    public void keyReleased(KeyEvent e) {}
}
