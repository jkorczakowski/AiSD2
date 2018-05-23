import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Main {

    private static final int alphaSize = 256;

    public static void main(String[] args)
    {
        String text = readAllBytes(args[0]);
        String pattern = readAllBytes(args[1]);

    //    System.out.println("TEXT: " + text);
    //    System.out.println("PATTERN: " + pattern);


        System.out.println("Naive algorithm:");
        long start = System.currentTimeMillis();
        naive(text,pattern);
        long elapsedTimeMillis = System.currentTimeMillis()-start;
        System.out.println("TIME: " + elapsedTimeMillis);
        System.out.println();
        int prime = 101;
        System.out.println("Rabin-Karp algorithm:");
        start = System.currentTimeMillis();
        rabinKarp(text,pattern,prime);
        elapsedTimeMillis = System.currentTimeMillis()-start;
        System.out.println("TIME: " + elapsedTimeMillis);
        System.out.println();
        System.out.println("Knuth-Morris-Pratt algorithm:");
        start = System.currentTimeMillis();
        KMP(text,pattern);
        elapsedTimeMillis = System.currentTimeMillis()-start;
        System.out.println("TIME: " + elapsedTimeMillis);

    }


    private static void naive(String text, String pattern)
    {
        text = text.replaceAll("\r", "").replaceAll("\n", "");
        pattern = pattern.replaceAll("\n", "").replaceAll("\n","");
        int M = pattern.length()-1;
        int N = text.length()-1;
        System.out.println("M = " + M);

        for (int i=0; i<=N-M; i++) {
            int j;

            for (j=0; j<M; j++) {
                if (text.charAt(i + j) != pattern.charAt(j)) break;
            }


            if (j==M) System.out.println("Znalezione wystąpienie wzorca od pozycji: " + (i));
        }

    }

    private static void rabinKarp(String text, String pattern, int prime)
    {
        text = text.replaceAll("\r", "").replaceAll("\n", "");
        pattern = pattern.replaceAll("\n", "").replaceAll("\n","");
        int M = pattern.length();
        int N = text.length();
        int i,j;
        int h=1;

        for(i=0; i<M-1; i++)
            h=(h*alphaSize)%prime;

        int p=0;
        int t=0;

        for(i=0; i<M; i++)
        {
            p=(alphaSize*p + pattern.charAt(i))%prime;
            t=(alphaSize*t + text.charAt(i))%prime;
        }

        for (i = 0; i <= N - M; i++)
        {
            if ( p == t )
            {
                for (j = 0; j < M; j++)
                {
                    if (text.charAt(i+j) != pattern.charAt(j))
                        break;
                }

                if (j == M)
                    System.out.println("Znalezione wystąpienie wzorca od pozycji: " + i);
            }

            if ( i < N-M )
            {
                t = (alphaSize*(t - text.charAt(i)*h) + text.charAt(i+M))%prime;
                if (t < 0)
                    t = (t + prime);
            }
        }
    }

    private static void KMP(String text, String pattern)
    {
        text = text.replaceAll("\r", "").replaceAll("\n", "");
        pattern = pattern.replaceAll("\n", "").replaceAll("\n","");
        int M = pattern.length();
        int N = text.length();

        int pi[] = new int[M];
        int j = 0;

        prefixFunction(pattern,M,pi);
        int i = 0;
        while(i<N)
        {
            if(pattern.charAt(j) == text.charAt(i))
            {
                j++;
                i++;
            }

            if(j == M)
            {
                System.out.println("Znalezione wystąpienie wzorca od pozycji: " + (i-j));
                j = pi[j-1];
            }

            else if(i<N && pattern.charAt(j) != text.charAt(i))
            {
                if (j!=0) j=pi[j-1];
                else i++;
            }
        }

    }

    private static void prefixFunction(String pattern, int M, int pi[])
    {
        int len=0;
        int i=1;
        pi[0]=0;

        while(i<M)
        {
            if (pattern.charAt(i) == pattern.charAt(len))
            {
                len++;
                pi[i] = len;
                i++;
            }

            else
            {
                if(len!=0) len = pi[len-1];
                else { pi[i] = len; i++; }
            }
        }

    }





    private static String readAllBytes(String filePath)
    {
        String content = "";

        try
        {
            content = new String ( Files.readAllBytes( Paths.get(filePath) ) );
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }

        return content;
    }


}
