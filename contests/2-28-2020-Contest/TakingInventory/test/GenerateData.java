import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import java.lang.ProcessBuilder;


public class GenerateData {
    static boolean inTest = true;

    static final int TEST_NUM = 30;
    static Random rand = new Random(88898);
    static String inputPath = inTest? "input/" : "test/input/";
    static String outputPath = inTest ? "output/" : "test/output/";
    static String javaFilePath = inTest ? "../ac/" : "src/";

    public static void generateInputFile (int testNumber) throws IOException {
        PrintWriter out = new PrintWriter(new FileWriter(inputPath + "input" + (testNumber+2) + ".txt"));
        // INSERT SOLUTION SPECIFIC LOGIC HERE
        for (int i=0; i<4; i++) {
            out.print(rand.nextInt(1000000) + " ");
        }
        out.println();
        // END SOLUTION SPECIFIC LOGIC
        out.close();
    }

    public static void main (String[] args) throws IOException, InterruptedException {
        // Compile solution
        new ProcessBuilder("javac", javaFilePath + "Emily.java").start().waitFor();
        Process[] solverProcs = new Process[TEST_NUM];
        // Generate input/output
        for (int t = 0; t < TEST_NUM; t++) {
            generateInputFile(t);
            solverProcs[t] = generateOutputFile(t);
        }
        for (int p = 0; p < solverProcs.length; p++) {
            solverProcs[p].waitFor();
            System.out.println("Solved " + p);
        }
    }

    public static Process generateOutputFile (int testNumber) throws IOException {
        ProcessBuilder pb = new ProcessBuilder("java", "-cp", javaFilePath, "Emily");
        pb.redirectInput(new File(inputPath + "input" + (testNumber+2) + ".txt"));
        pb.redirectOutput(ProcessBuilder.Redirect.to(new File(outputPath + "output" + (testNumber+2) + ".txt")));
        return pb.start();
    }
}
