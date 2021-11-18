package gui;
import file.FileGUI;
import pattern.Pattern;
import pattern.PatternHandler;
import xml.XMLParser;

import java.awt.*;
import java.awt.event.*;

import java.util.ArrayList;
import javax.swing.*;
import javax.swing.text.*;


public class GUI extends JFrame {
    private final JTextPane input = new JTextPane();
    private final JMenuBar menuBar = new JMenuBar();
    private final JMenu mFile = new JMenu("File");
    private final JMenu mFind = new JMenu("Find and Replace");
    private final JMenuItem miFind = new JMenuItem("Find");
    private final JMenuItem miReplace = new JMenuItem("Replace");
    private final JMenuItem miOpen = new JMenuItem("Open");
    private final JMenuItem miNew = new JMenuItem("New");
    private final JMenuItem miSave = new JMenuItem("Save");
    ArrayList<Pattern> patterns = new ArrayList<>();
    final StyleContext cont = StyleContext.getDefaultStyleContext();
    AttributeSet attrDefault = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground,Color.decode("#b82e5c") );

    public GUI(){
        super("Notebook");
        this.setBounds(100,100, 650,500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        FileEventListener f = new FileEventListener();
        input.addKeyListener(new KeyListenerCustom());
        miNew.addActionListener(f);
        miOpen.addActionListener(f);
        miSave.addActionListener(f);
        miFind.addActionListener(f);
        miReplace.addActionListener(f);
        mFile.add(miNew);
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
        XMLParser parser = new XMLParser();
        try{
            patterns = parser.Read();
        }catch (Exception e){}

    }
    public void Paint(){
        StyledDocument doc = input.getStyledDocument();
        doc.setCharacterAttributes(0,input.getText().length(), attrDefault, false );

        for (var pattern:patterns) {
            PatternHandler ph = new PatternHandler(pattern.getPattern());
            AttributeSet attr = cont.addAttribute(cont.getEmptySet(), StyleConstants.Foreground, pattern.getColor());
            var indexes = ph.FindPattern(input.getText().replaceAll("\r",""));
            for (var i : indexes) {
                doc.setCharacterAttributes(i.getStartIndex(), i.getEndIndex() - i.getStartIndex(), attr, false);
            }
        }
        input.setCharacterAttributes(doc.getDefaultRootElement().getAttributes(), true);

    }
    class KeyListenerCustom implements KeyListener{

        @Override
        public void keyTyped(KeyEvent e) {}
        @Override
        public void keyPressed(KeyEvent e) {}
        @Override
        public void keyReleased(KeyEvent e) {
            Paint();
        }

    }
    class FileEventListener implements ActionListener {
        private String fileName = "";
        private FileGUI fileDialog = new FileGUI(input, fileName);
        @Override
        public void actionPerformed(ActionEvent e) {
            if(e.getSource().equals(miNew)){
                fileDialog.NewFile();
            }
            if(e.getSource().equals(miOpen)){
                fileDialog.Open();
                Paint();
            }
            if(e.getSource().equals(miSave)){
                fileDialog.Save();
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
