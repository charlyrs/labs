package com.company;
import file.FileHandler;
import file.MyFile;
import pattern.IndexRange;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import javax.swing.text.*;

public class GUI extends JFrame {
    private JTextPane input = new JTextPane();
    private JMenuBar menuBar = new JMenuBar();
    private JMenu mFile = new JMenu("File");
    private JMenu mFind = new JMenu("Find and Replace");
    private JMenuItem miFind = new JMenuItem("Find");
    private JMenuItem miReplace = new JMenuItem("Replace");
    private JMenuItem miOpen = new JMenuItem("Open");
    private JMenuItem miSave = new JMenuItem("Save");
    public GUI(){
        super("Notebook");
        this.setBounds(100,100, 650,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FileEventListener f = new FileEventListener();
        miOpen.addActionListener(f);
        miSave.addActionListener(f);
        miFind.addActionListener(f);
        miReplace.addActionListener(f);
        mFile.add(miSave);
        mFile.add(miOpen);
        mFind.add(miFind);
        mFind.add(miReplace);

        menuBar.add(mFile);
        menuBar.add(mFind);
        menuBar.setBackground(Color.WHITE);
        input.setBackground(Color.getHSBColor(48,34,100));
        input.setSelectionColor(Color.PINK);
        input.setFont(new Font("Monospaced", Font.TYPE1_FONT, 16));
        JScrollPane sp = new JScrollPane(input);
        add(sp, BorderLayout.CENTER);
        setJMenuBar(menuBar);
        var sc = input.getStyle("l");
        
//        StyleContext st = new StyleContext();
//        AttributeSet aset = st.addAttribute(st)
//        input.setCharacterAttributes(st,false);

    }
    class FileEventListener implements ActionListener {
        private String fileName = "";
        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource().equals(miOpen)){
                JFileChooser j = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
                int r = j.showOpenDialog(null);
                if (r == JFileChooser.APPROVE_OPTION)
                {
                    fileName = j.getSelectedFile().getAbsolutePath();
                    FileHandler fileHandler = new FileHandler(fileName);
                    fileHandler.ReadFile();
                    input.setText(fileHandler.FileToString());
                }
            }
            if(e.getSource().equals(miSave)){
                if(fileName == "")
                {
                    JFileChooser j = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
                    int r = j.showSaveDialog(null);
                    if (r == JFileChooser.APPROVE_OPTION)
                    {
                        fileName = j.getSelectedFile().getAbsolutePath();
                        MyFile fileHandler = new MyFile(fileName);
                        fileHandler.Write(input.getText(),false);
                    }
                }
                else {
                    MyFile fileHandler = new MyFile(fileName);
                    fileHandler.Write(input.getText(),false);
                }
            }
            if(e.getSource().equals(miFind)){
                FindDialog dg = new FindDialog(fileName, input);
                dg.setVisible(true);
            }
            if(e.getSource().equals(miReplace)){
                ReplaceDialog dg = new ReplaceDialog(fileName,input);
                dg.setVisible(true);
            }
        }
    }

}
