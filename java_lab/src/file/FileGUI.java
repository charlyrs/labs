package file;


import javax.swing.*;
import javax.swing.filechooser.FileSystemView;

public class FileGUI {
    private final JTextPane input;
    private String fileName;
    public FileGUI(JTextPane pane, String fileName){
        this.input = pane;
        this.fileName = fileName;
    }
    public void NewFile(){
        input.setText("");
        fileName = "";
    }
    public void Save(){
        if(fileName == "") {
            JFileChooser fileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
            int dialog = fileChooser.showSaveDialog(null);
            if (dialog == JFileChooser.APPROVE_OPTION) {
                fileName = fileChooser.getSelectedFile().getAbsolutePath();
                CustomFile fileHandler = new CustomFile(fileName);
                fileHandler.Write(input.getText(),false);
            }
        }
        else {
            CustomFile fileHandler = new CustomFile(fileName);
            fileHandler.Write(input.getText(),false);
        }
    }
    public void Open(){
        JFileChooser fileChooser = new JFileChooser(FileSystemView.getFileSystemView().getHomeDirectory());
        int dialog = fileChooser.showOpenDialog(null);
        if (dialog == JFileChooser.APPROVE_OPTION) {
            fileName = fileChooser.getSelectedFile().getAbsolutePath();
            CustomFile fileHandler = new CustomFile(fileName);
            fileHandler.Read();
            input.setText(fileHandler.FileToString());
        }
    }
}
