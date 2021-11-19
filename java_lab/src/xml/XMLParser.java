package xml;
import org.w3c.dom.Document;
import org.xml.sax.SAXException;
import pattern.Pattern;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class XMLParser {
    private String filename="src/themes/pattern.xml";
    private ArrayList<Pattern> patterns = new ArrayList<>();
    private Color backgroundColor;
    private Color foregroundColor;
    public XMLParser(){
        try {
            Parse();
        }catch (Exception e){}
    }
    public XMLParser(String file){
        filename = file;
        try {
            Parse();
        }catch (Exception e){}}
    public Color GetBackgroundColor(){
        return backgroundColor;
    }
    public Color GetForegroundColor(){
        return foregroundColor;
    }
    public ArrayList<Pattern> GetPatterns(){
        return patterns;
    }
    public void Parse() throws ParserConfigurationException, IOException, SAXException {
        File xmlFile = new File(filename);
        ArrayList<Pattern> res = new ArrayList<>();
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = factory.newDocumentBuilder();
        Document doc = dBuilder.parse(xmlFile);
        doc.getDocumentElement().normalize();
        int len = doc.getDocumentElement().getElementsByTagName("color").getLength();

        for (int i = 0; i < len; i++){
            int len1 = doc.getElementsByTagName("color").item(i).getChildNodes().getLength();
            for (int j = 0; j< len1; j++) {
                var a = doc.getElementsByTagName("color").item(i).getChildNodes().item(j).getTextContent();
                var b = doc.getElementsByTagName("color").item(i).getAttributes().item(0).getTextContent();
                res.add(new Pattern(a, Color.decode(b)));
            }
        }
        var bgcolor = doc.getElementsByTagName("background_color").item(0).getTextContent();
        var fgcolor = doc.getElementsByTagName("font_color").item(0).getTextContent();
        backgroundColor = Color.decode(bgcolor);
        foregroundColor = Color.decode(fgcolor);
        patterns = res;

    }



}
