package com.company;

import java.awt.*;

public class ColorPalette {
    private final Color defaultColor ;
    private final Color winColor ;
    public ColorPalette(){
        defaultColor = Color.decode("#ffc0cb");
        winColor = Color.decode("#ff5c77");
    }

    public Color getDefaultColor() {
        return defaultColor;
    }

    public Color getWinColor() {
        return winColor;
    }
}
