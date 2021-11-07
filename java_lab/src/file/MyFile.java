package file;

import java.io.*;
import java.util.ArrayList;

public class MyFile {
    private final ArrayList<String> _lines = new ArrayList<String>();
    private final String fileName;
    public MyFile(String fileName){
        this.fileName = fileName;
    }
    public void AddLine(String line){
        StringBuilder sb = new StringBuilder();
        sb.append("\n");
        sb.append(line);
        if(Write(sb.toString(),true)){
            _lines.add(line);
        }
    }
    public String GetLine(int index){ return _lines.get(index);}
    public int Size(){ return  _lines.size();}
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
        try {
            fileReader = new FileReader(fileName);
        } catch (FileNotFoundException e) { return false;}
        String line;
        try {
            BufferedReader reader = new BufferedReader(fileReader);
            while ((line = reader.readLine()) != null){
                _lines.add(line);}
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
    public ArrayList<String> list(){return _lines;}
    public void ChangeLine(int index, String replacementString){
        try {
            _lines.set(index,replacementString);
            Write(FileToString(), false);
        } catch (Exception e) { return;}
    }
}
