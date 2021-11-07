package xml;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.xml.sax.SAXException;

import javax.xml.XMLConstants;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class XMLParser {
    private final String filename="src/pattern.xml";
    public void Read() throws ParserConfigurationException, IOException, SAXException {
        File xmlFile = new File(filename);

        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = factory.newDocumentBuilder();
        Document doc = dBuilder.parse(xmlFile);
        doc.getDocumentElement().normalize();

        var a = doc.getDocumentElement().getElementsByTagName("color").item(0).getTextContent();
        var b = doc.getDocumentElement().getElementsByTagName("color").item(0).getAttributes().item(0).getTextContent();

    }



}
