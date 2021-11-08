package xml;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;
import pattern.Pattern;

import javax.xml.XMLConstants;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class XMLParser {
    private final static String filename="src/pattern.xml";
    public static ArrayList<Pattern> Read() throws ParserConfigurationException, IOException, SAXException {
        File xmlFile = new File(filename);
        ArrayList<Pattern> res = new ArrayList<>();
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = factory.newDocumentBuilder();
        Document doc = dBuilder.parse(xmlFile);
        doc.getDocumentElement().normalize();
        int len = doc.getDocumentElement().getElementsByTagName("color").getLength();
        for (int i = 0; i < len; i++){
            var a = doc.getDocumentElement().getElementsByTagName("color").item(i).getTextContent();
            var b = doc.getDocumentElement().getElementsByTagName("color").item(i).getAttributes().item(0).getTextContent();
            res.add(new Pattern(a, Color.decode(b)));
        }
        return res;

    }



}
