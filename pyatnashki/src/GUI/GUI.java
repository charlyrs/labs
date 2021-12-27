package GUI;

import javax.swing.*;
import java.awt.*;
import Panel.*;


public class GUI extends JFrame {
    private PanelPyatnashki panel;

    public GUI() {
        super("Pyatnashki");
        panel = new PanelPyatnashki(new GridLayout(4, 4, 2, 2), new ColorPalette());
        setBounds(200, 200, 300, 300);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setFocusable(true);
        Container container = getContentPane();
        addKeyListener(new PanelKeyListener(panel));
        container.add(panel);
    }


}