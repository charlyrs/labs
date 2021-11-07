package com.company;
import pattern.PatternHandler;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ReplaceDialog extends JFrame {
    private JTextField part = new JTextField();
    private JTextField replacement = new JTextField();
    private JButton buttonFind = new JButton("Replace");
    private String fileName = "";
    private JTextPane input;
    public ReplaceDialog(String file, JTextPane area){
        fileName = file;
        input = area;
        buttonFind.addActionListener(new ButtonActionListener());
        this.setBounds(200,200, 350,200);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        Container c = getContentPane(); // клиентская область окна
        setLayout(new BorderLayout());
        add(part, BorderLayout.PAGE_START);
        add(replacement, BorderLayout.CENTER);
        add(buttonFind, BorderLayout.PAGE_END);

    }
    class ButtonActionListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e)
        {
            PatternHandler patternHandler = new PatternHandler(part.getText());

            var str = patternHandler.ReplacePattern(input.getText(), replacement.getText());
            input.setText(str);
        }


    }
}

