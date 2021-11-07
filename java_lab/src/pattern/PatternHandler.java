package pattern;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import pattern.IndexRange;

public class PatternHandler {
    private final Pattern pattern;
    public PatternHandler(String pattern){this.pattern = Pattern.compile(pattern);}
    public ArrayList<IndexRange> FindPattern(String text){
        ArrayList<IndexRange> result = new ArrayList<IndexRange>();
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            IndexRange range = new IndexRange(matcher.start(), matcher.end());
            result.add(range);
        }
        return result;
    }
    public String ReplacePattern(String text,String replacementText){
        return text.replaceAll(pattern.toString(),replacementText);
    }


}
