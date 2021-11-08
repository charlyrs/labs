package pattern;

import java.awt.*;

public class Pattern {
    private String pattern;
    private Color color;
    public Pattern(String pattern, Color color){
        this.pattern = pattern;
        this.color = color;
    }

    public String getPattern() {
        return pattern;
    }

    public Color getColor() {
        return color;
    }
}
