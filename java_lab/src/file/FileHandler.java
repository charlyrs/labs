package file;

import pattern.PatternHandler;
import java.util.ArrayList;

public class FileHandler {
    private final MyFile file;

    public FileHandler(String fileName){
        file = new MyFile(fileName);
    }
    public boolean ReadFile() {
        return file.Read();
    }
    public void WriteLineToFile(String str){
        if (str == null) return;
        file.AddLine(str);
    }

    public ArrayList<String> list(){return file.list();}
    public void ReplacePattern(String pattern, String replacementString){
        PatternHandler patternHandler = new PatternHandler(pattern);
        for (int i = 0; i < file.Size(); i++){
            file.ChangeLine(i,patternHandler.ReplacePattern(file.GetLine(i),replacementString));
        }
    }
    public String FileToString(){
        return file.FileToString();
    }
}
