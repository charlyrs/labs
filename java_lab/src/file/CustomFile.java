package file;

import java.io.*;
import java.util.ArrayList;

public class CustomFile {
    private final ArrayList<String> _lines = new ArrayList<String>();
    private final String fileName;
    public CustomFile(String fileName){
        this.fileName = fileName;
    }
    public String FileName(){ return fileName;}
    public boolean Write(String str, boolean append){
        try(FileWriter writer = new FileWriter(fileName, append)) {
            writer.write(str);
            writer.flush();
        }
        catch(IOException ex){ return false; }
        return true;
    }
    public boolean Read(){
        FileReader fileReader = null;
        try { fileReader = new FileReader(fileName);} catch (FileNotFoundException e) { return false;}
        String line;
        try {
            BufferedReader reader = new BufferedReader(fileReader);
            while ((line = reader.readLine()) != null){
                _lines.add(line);
            }
        } catch (IOException e) {  return false; }
        return true;
    }
    public String FileToString(){
        StringBuilder res = new StringBuilder();
        for (String line : _lines) {
            res.append(line);
            res.append("\n");
        }
        return res.toString();
    }

}
