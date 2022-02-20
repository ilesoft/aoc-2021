import java.io.File;
import java.io.FileNotFoundException;
import java.util.stream.DoubleStream;
import java.util.Scanner;

public class LanternFish {
    public static void main(String[] args) throws FileNotFoundException {
        File inputFile = new File(args[0]);
        Scanner reader = new Scanner(inputFile);
        String input = reader.nextLine();
        reader.close();
        System.out.printf("a: %.0f\n", calc(input, 80));
        System.out.printf("b: %.0f\n", calc(input, 256));
    }

    static double calc(String input, int days) {
        double[] table = new double[9];
        for (int i = 0; i < input.length(); ++i) {
            if (input.charAt(i) == ',') continue;
            table[Character.getNumericValue(input.charAt(i))] += 1;
        }

        for (int i = 0; i <= days; ++i) {
            table[(i + 6) % 9] += table[(i + 8) % 9];
        }

        return DoubleStream.of(table).sum();
    }
}
