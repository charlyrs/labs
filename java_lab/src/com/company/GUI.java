package com.company;
import file.FileHandler;
import file.MyFile;
import org.xml.sax.SAXException;
import pattern.IndexRange;
import pattern.Pattern;
import pattern.PatternHandler;
import xml.XMLParser;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.filechooser.FileSystemView;
import javax.swing.text.*;
import javax.xml.parsers.ParserConfigurationException;

public class GUI extends JFrame {
    private final JTextPane input = new JTextPane();
    private final JMenuBar menuBar = new JMenuBar();
    private final JMenu mFile = new JMenu("File");
    private final JMenu mFind = new JMenu("Find and Replace");
    private final JMenuItem miFind = new JMenuItem("Find");
    private final JMenuItem miReplace = new JMenuItem("Replace");
    private final JMenuItem miOpen = new JMenuItem("Open");
    private final JMenuItem miSave = new JMenuItem("Save");
    ArrayList<Pattern> patterns = new ArrayList<>();
    final StyleContext cont = StyleContext.getDefaultStyleContext();

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
        input.setForeground(Color.decode("#b82e5c"));
        input.setFont(new Font("Monospaced", Font.TYPE1_FONT, 16));
        JScrollPane sp = new JScrollPane(input);
        add(sp, BorderLayout.CENTER);
        setJMenuBar(menuBar);
    }
    private void Validate(){
        StyledDocument doc = input.getStyledDocument();
        for (var pattern:patterns) {
            PatternHandler ph = new PatternHandler(pattern.getPattern());
            final AttributeSet attrRed = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, pattern.getColor());
            var indexes = ph.FindPattern(input.getText().replaceAll("\r",""));
            for (var i : indexes) {
                doc.setCharacterAttributes(i.getStartIndex(), i.getEndIndex() - i.getStartIndex(), attrRed, false);
            }
        }
        input.setCharacterAttributes(doc.getDefaultRootElement().getAttributes(), true);

    }
    class KeyListenerCustom implements KeyListener{

        public KeyListenerCustom(){
            try {
                patterns = XMLParser.Read();
            }catch (Exception e){

            }

        }
        @Override
        public void keyTyped(KeyEvent e) {}
        @Override
        public void keyPressed(KeyEvent e) {

        }
        @Override
        public void keyReleased(KeyEvent e) {
            Validate();
        }

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
                    Validate();
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
