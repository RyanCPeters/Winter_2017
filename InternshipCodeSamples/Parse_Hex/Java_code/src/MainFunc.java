import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Ryan Peters on 1/13/2018.
 */
public class MainFunc {
    public static void main(String[] args) {
        ArrayList<String> test_strings = new ArrayList<>(List.of("#800080", "#F00", "#ffa500","oops", "#000000", "#000"));
        ArrayList<Integer> test_answers = new ArrayList<>(List.of(8388736, 255, 42495, -1, 0, 0 ));

        for (int i = 0; i < test_strings.size(); ++i) {
            try{
                int tmp = Parse_CSS_Hex.cssStringToColor(test_strings.get(i));
                System.out.printf("expecting %-7d\tand got %-8d\n",test_answers.get(i), tmp);

            }
            catch (Exception str)
            {
                System.out.printf("Failure on %-7s\texpected %-2d; but got %s;\n",test_strings.get(i),test_answers.get(i),str);
            }
        }
    }



    public void givenUsingJava7_whenWritingToFile_thenCorrect(String input, String fileName)
            throws IOException {

        Path path = Paths.get(fileName);
        byte[] strToBytes = input.getBytes();

        Files.write(path, strToBytes);

        String read = Files.readAllLines(path).get(0);
    }
}
