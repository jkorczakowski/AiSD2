
import javax.xml.bind.SchemaOutputResolver;
import java.util.Comparator;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

class ReadFile
{
    public static char[] readFile(String filename) throws IOException
    {
        String data = "";
        data = new String(Files.readAllBytes(Paths.get(filename)));
        return data.toCharArray();
    }
}


class HuffmanNode
{
    int data;
    char c;


    HuffmanNode left;
    HuffmanNode right;
}

class MyComparator implements Comparator<HuffmanNode>
{
    public int compare(HuffmanNode x, HuffmanNode y)
    {
        return x.data - y.data;
    }
}


public class Main
{

    static int z = 0;



    public static void printCode(HuffmanNode root, String s)
    {






        if(root.left == null && root.right == null && Character.isLetter(root.c))
        {
            z++;
            if(s.length()>3)
                System.out.println("\t\t" + root.c + "\t  |\t\t" + s + "\t\t|\t" + root.data);
            else
                System.out.println("\t\t" + root.c + "\t  |\t\t" + s + "\t\t\t|\t" + root.data);


                return;
        }





        printCode(root.left, s + "0");

        printCode(root.right, s + "1");
        

    }
    public static void main(String[] args) throws Exception
    {

       // String path = "E:\\Study\\AiSD2\\Huffmann\\input.txt";
        ReadFile RF = new ReadFile();
        char[] buf;
        buf = RF.readFile(args[0]);
        //System.out.println(buf.length);
       // System.out.println(buf);

        Map<Character,Integer> frequencies = new HashMap<>();
        for (char ch : buf)
            frequencies.put(ch, frequencies.getOrDefault(ch, 0) + 1);

        Set<Character> keys = frequencies.keySet();
        Character[] letters = keys.toArray(new Character[keys.size()]);

        Collection<Integer> values =  frequencies.values();
        Integer[] freq = values.toArray(new Integer[values.size()]);

        for(int i=0; i<frequencies.size();i++)
            System.out.println(letters[i] + " - " + freq[i] + " " + frequencies.size());




        PriorityQueue<HuffmanNode> queue = new PriorityQueue<HuffmanNode>(frequencies.size(), new MyComparator());

        for(int i=0; i<frequencies.size(); i++)
        {
            HuffmanNode hn = new HuffmanNode();

            hn.c = letters[i];
            hn.data = freq[i];
            hn.left = null;
            hn.right = null;


            queue.add(hn);
        }

        HuffmanNode root = null;

        while(queue.size() > 1)
        {
            HuffmanNode x = queue.peek();
            queue.poll();

            HuffmanNode y = queue.peek();
            queue.poll();

            HuffmanNode f = new HuffmanNode();

            f.data = x.data + y.data;
            f.c = '-';
            f.left = x;
            f.right = y;
            root = f;
            queue.add(f);
        }

        System.out.println("|  Character  |  Huffman Code   | Frequency  |");
        System.out.println("----------------------------------------------");

        printCode(root, "");

    }


}
