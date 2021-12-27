package com.company;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class PanelKeyListener implements KeyListener {
    private Panel panel;
    public PanelKeyListener(Panel panel){
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
