package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PanelClickListener implements ActionListener {
    private Panel panel;
    public PanelClickListener(Panel panel){
        super();
        this.panel = panel;
    }
    public void actionPerformed(ActionEvent e) {
        JButton button = (JButton) e.getSource();
        String name = button.getText();
        panel.changeByNumber(Integer.parseInt(name));
        panel.repaintPanel();
    }
}
