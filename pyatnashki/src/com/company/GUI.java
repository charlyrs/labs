package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;


public class GUI extends JFrame {
    private JPanel panel = new JPanel(new GridLayout(4, 4, 2, 2));
    private int[][] numbers = new int[4][4];
    private Pair emptyIndex = new Pair();
    private JButton[][] buttons = new JButton[4][4];
    private Color defaultColor = Color.decode("#ffc0cb");
    private Color winColor = Color.decode("#ff5c77");

    private class Pair{
        public int i = -1;
        public int j = -1;
    }
    public GUI() {
        super("Pyatnashki");

        setBounds(200, 200, 300, 300);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.setFocusable(true);

        Container container = getContentPane();
        addKeyListener(new MyKeyListener());
        container.add(panel);
        GenerateLayout();
    }

    public void GenerateLayout() {
        Random generator = new Random();
        for (int i = 1; i < 16; i++) {
            int k, l;
            do {
                k = generator.nextInt(4);
                l = generator.nextInt(4);
            }
            while (numbers[k][l] != 0);
            numbers[k][l] = i;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                buttons[i][j] = new JButton(Integer.toString(numbers[i][j]));
                buttons[i][j].setBackground(defaultColor);
                buttons[i][j].setForeground(Color.WHITE);
                buttons[i][j].setFont(new Font("Liliya", Font.BOLD, 20));
                buttons[i][j].setFocusable(false);
                panel.add(buttons[i][j]);
                buttons[i][j].addActionListener(new ClickListener());
                if (numbers[i][j] == 0) {
                    buttons[i][j].setVisible(false);
                    emptyIndex.i = i;
                    emptyIndex.j = j;
                }
            }
        }
        Repaint();
    }

    public void Repaint(){
        int count = 1;
        boolean paint = true;
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                if(numbers[i][j] == count && paint){
                    buttons[i][j].setBackground(winColor);
                }else {
                    buttons[i][j].setBackground(defaultColor);
                    paint = false;
                }
                count++;
            }
        }
    }
    public void SwapLabels(int i, int j, int num){
        buttons[emptyIndex.i][emptyIndex.j].setVisible(false);
        buttons[i][j].setText(Integer.toString(num));
        buttons[i][j].setVisible(true);
    }


    private class ClickListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JButton button = (JButton) e.getSource();
            String name = button.getText();
            ChangeByNumber(Integer.parseInt(name));
            Repaint();
        }
    }
    public void ChangeByIndex(int i, int j){
        int num = numbers[i][j];
            if (i-1 == emptyIndex.i && j == emptyIndex.j) {
                numbers[i - 1][j] = num;
                numbers[i][j] = 0;
                emptyIndex.i = i;
                SwapLabels(i-1,j,num);
            }

            if (i+1 == emptyIndex.i && j == emptyIndex.j) {
                numbers[i + 1][j] = num;
                numbers[i][j] = 0;
                emptyIndex.i = i;
                SwapLabels(i+1,j,num);
            }

            if (i == emptyIndex.i && j-1 == emptyIndex.j) {
                numbers[i][j - 1] = num;
                numbers[i][j] = 0;
                emptyIndex.j = j;
                SwapLabels(i,j-1,num);
            }

            if (i == emptyIndex.i && j+1 == emptyIndex.j) {
                numbers[i][j + 1] = num;
                numbers[i][j] = 0;
                emptyIndex.j = j;
                SwapLabels(i,j+1,num);
            }
    }
    public void ChangeByNumber(int num) {
        int i = 0, j = 0;
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < 4; l++) {
                if (numbers[k][l] == num) {
                    i = k;
                    j = l;
                }
            }
        }
        ChangeByIndex(i,j);
    }

    class MyKeyListener implements KeyListener{
        @Override
        public void keyTyped(KeyEvent e) {}

        @Override
        public void keyPressed(KeyEvent e) {
            if(e.getKeyCode() == KeyEvent.VK_LEFT && emptyIndex.j < 3){
                if(e.isControlDown()){
                    while (emptyIndex.j!=3){
                        ChangeByIndex(emptyIndex.i,emptyIndex.j+1);
                    }
                }else { ChangeByIndex(emptyIndex.i,emptyIndex.j+1);}

            }
            if(e.getKeyCode() == KeyEvent.VK_RIGHT&& emptyIndex.j > 0){
                if(e.isControlDown()){
                    while (emptyIndex.j!=0){
                        ChangeByIndex(emptyIndex.i,emptyIndex.j-1);
                    }
                } else {
                    ChangeByIndex(emptyIndex.i,emptyIndex.j-1);}

            }
            if(e.getKeyCode() == KeyEvent.VK_UP && emptyIndex.i < 3){
                if(e.isControlDown()){
                    while (emptyIndex.i!=3){
                        ChangeByIndex(emptyIndex.i+1,emptyIndex.j);
                    }
                } else {
                    ChangeByIndex(emptyIndex.i+1,emptyIndex.j);}

            }
            if(e.getKeyCode() == KeyEvent.VK_DOWN && emptyIndex.i > 0){
                if(e.isControlDown()){
                    while (emptyIndex.i!=0){
                        ChangeByIndex(emptyIndex.i-1,emptyIndex.j);
                    }
                } else {
                    ChangeByIndex(emptyIndex.i-1,emptyIndex.j);}
            }
            Repaint();
        }
        @Override
        public void keyReleased(KeyEvent e) {}
    }


}