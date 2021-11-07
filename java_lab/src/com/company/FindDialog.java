package com.company;
import file.FileHandler;
import file.MyFile;
import pattern.PatternHandler;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
public class FindDialog extends JFrame {
    private JTextField find = new JTextField();
    private JButton buttonFind = new JButton("Find");
    private String fileName = "";
    private JTextPane input;
    public FindDialog(String file, JTextPane area){
        fileName = file;
        input = area;
        buttonFind.addActionListener(new ButtonActionListener());
        this.setBounds(200,200, 350,200);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        Container c = getContentPane(); // клиентская область окна
        setLayout(new BorderLayout());
        add(find, BorderLayout.PAGE_START);
        add(buttonFind, BorderLayout.PAGE_END);

    }
    class ButtonActionListener implements ActionListener{
        private int i = 0;

        @Override
        public void actionPerformed(ActionEvent e)
        {
            PatternHandler patternHandler = new PatternHandler(find.getText());
            var list = patternHandler.FindPattern(input.getText());
            input.setSelectionColor(Color.PINK);
            input.setSelectionStart(list.get(i).getStartIndex());
            input.setSelectionEnd(list.get(i).getEndIndex());
            i++;
            if(i >= list.size()) {i=0;}
        }


        }
    }



