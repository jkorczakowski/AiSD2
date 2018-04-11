
import java.util.Comparator;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

import static java.lang.Math.sqrt;

class ReadFile
{
    static char[] readFile(String filename) throws IOException
    {
        String data;
        data = new String(Files.readAllBytes(Paths.get(filename)));
        return data.toCharArray();
    }
}


class Node
{
    int data;
    char c;


    Node left;
    Node right;
}

class MyComparator implements Comparator<Node>
{
    public int compare(Node x, Node y)
    {
        return x.data - y.data;
    }
}


public class Main
{
    private static int counter = 0;
    private static String[] huffmanLength = new String[26];
    private static int[] huffmanData = new int[26];

   private static void print(Node root, String s)
    {

        if(root.left == null && root.right == null && Character.isLetter(root.c))
        {
            if(s.length()>3)
                System.out.println("\t\t" + root.c + "\t  |\t\t" + s + "\t\t|\t" + root.data);
            else
                System.out.println("\t\t" + root.c + "\t  |\t\t" + s + "\t\t\t|\t" + root.data);

            huffmanLength[counter] = s;
            huffmanData[counter] = root.data;
            counter++;

                return;
        }
        print(root.left, s + "0");
        print(root.right, s + "1");
    }

    public static void main(String[] args) throws Exception
    {

       // String path = "E:\\Study\\AiSD2\\Huffmann\\input.txt";
        char[] buf;
        buf = ReadFile.readFile(args[0]);
        //System.out.println(buf.length);
       // System.out.println(buf);

        Map<Character,Integer> frequencies = new HashMap<>();
        for (char ch : buf)
            frequencies.put(ch, frequencies.getOrDefault(ch, 0) + 1);

        Set<Character> keys = frequencies.keySet();
        Character[] letters = keys.toArray(new Character[keys.size()]);

        Collection<Integer> values =  frequencies.values();
        Integer[] freq = values.toArray(new Integer[values.size()]);

      //  for(int i=0; i<frequencies.size();i++)
      //      System.out.println(letters[i] + " - " + freq[i] + " " + frequencies.size());


        PriorityQueue<Node> queue = new PriorityQueue<>(frequencies.size(), new MyComparator());

        for(int i=0; i<frequencies.size(); i++)
        {
            Node node = new Node();

            node.c = letters[i];
            node.data = freq[i];
            node.left = null;
            node.right = null;


            queue.add(node);
        }

        Node root = null;

        while(queue.size() > 1)
        {
            Node x = queue.peek();
            queue.poll();

            Node y = queue.peek();
            queue.poll();

            Node z = new Node();

            z.data = x.data + y.data;
            z.c = '-';
            z.left = x;
            z.right = y;
            root = z;
            queue.add(z);
        }



        System.out.println("|  Character  |  Huffman Code   | Frequency  |");
        System.out.println("----------------------------------------------");

        print(root, "");

        int encodedLength = 0;

        for(int i=0; i<frequencies.size(); i++)
        {
            encodedLength +=huffmanData[i] * huffmanLength[i].length();
            //System.out.println(huffmanLength[i].length() + " " + huffmanData[i]);
        }

        int normalLength = (int) Math.ceil(sqrt(frequencies.size()));

        System.out.println("Normal lenght: " + buf.length*normalLength);
        System.out.println("Encoded lenght: " + encodedLength);


    }


}
