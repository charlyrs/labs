package com.company;
import file.FileHandler;
import file.MyFile;
import pattern.IndexRange;
import pattern.PatternHandler;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import javax.swing.text.*;

public class GUI extends JFrame {
    private final JTextPane input = new JTextPane();
    private final JMenuBar menuBar = new JMenuBar();
    private final JMenu mFile = new JMenu("File");
    private final JMenu mFind = new JMenu("Find and Replace");
    private final JMenuItem miFind = new JMenuItem("Find");
    private final JMenuItem miReplace = new JMenuItem("Replace");
    private final JMenuItem miOpen = new JMenuItem("Open");
    private final JMenuItem miSave = new JMenuItem("Save");
    final StyleContext cont = StyleContext.getDefaultStyleContext();
    final AttributeSet attrRed = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, Color.decode("#ee9086"));
    public GUI(){
        super("Notebook");
        this.setBounds(100,100, 650,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FileEventListener f = new FileEventListener();
        input.addKeyListener(new KeyListenerCustom());

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
        input.setForeground(Color.decode("#5c0006"));
        input.setFont(new Font("Monospaced", Font.TYPE1_FONT, 16));
        JScrollPane sp = new JScrollPane(input);
        add(sp, BorderLayout.CENTER);
        setJMenuBar(menuBar);
    }
    class KeyListenerCustom implements KeyListener{
        @Override
        public void keyTyped(KeyEvent e) {}
        @Override
        public void keyPressed(KeyEvent e) {
            StyledDocument doc = input.getStyledDocument();
            PatternHandler ph = new PatternHandler("h\\S{3}");
            var indexes = ph.FindPattern(input.getText().replaceAll("\n",""));
            for (var i : indexes) {
                doc.setCharacterAttributes(i.getStartIndex(), i.getEndIndex() - i.getStartIndex(), attrRed, false);
            }
            input.setCharacterAttributes(doc.getDefaultRootElement().getAttributes(), true);
        }
        @Override
        public void keyReleased(KeyEvent e) {}

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
