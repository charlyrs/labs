package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;


public class GUI extends JFrame {
    private Panel panel;

    public GUI() {
        super("Pyatnashki");
        panel = new Panel(new GridLayout(4, 4, 2, 2), new ColorPalette());
        setBounds(200, 200, 300, 300);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setFocusable(true);
        Container container = getContentPane();
        addKeyListener(new PanelKeyListener(panel));
        container.add(panel);
    }


}