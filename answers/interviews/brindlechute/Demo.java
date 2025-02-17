package com.example;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

public class Main {
    public static void main(String[] args) {
         try {
            //test short-condensed medium-condensed
            String condensed = new String(Files.readAllBytes(Paths.get("data/short-condensed.txt")), StandardCharsets.UTF_8);
            File myObj = new File("data/words");
            Scanner myReader = new Scanner(myObj);
            List<String> unigrams = new ArrayList<>();
            while (myReader.hasNextLine()) {
                unigrams.add(myReader.nextLine());
            }
            myReader.close();

            Map<String, Double> bigrams = new HashMap<>();
            try (BufferedReader br = new BufferedReader(new FileReader("data/bert.eng.uncased.bigrams.csv"))) {
                String line;
                while ((line = br.readLine()) != null) {
                    if (line.matches("^[a-zA-Z0-9 \\t]+$")) {
                        //System.out.println(line);
                        bigrams.put(line, 0.0);
                    }
                }
            }
            List<String> result = wordBreakBigram(condensed, unigrams, bigrams);
            System.out.println(result);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public static List<String> wordBreak(String s, List<String> wordDict) {
        Map<Integer, Set<String>> lengthMap = new HashMap<>();
        for (String word : wordDict) {
            int length = word.length();
            Set<String> set = lengthMap.getOrDefault(length, new HashSet<>());
            set.add(word);
            lengthMap.put(length, set);
        }

        Map<Integer, List<String>> indexMap = new HashMap<>();
        List<String> temp = new LinkedList<>();
        temp.add("");
        indexMap.put(s.length(), temp);
        for (int i = s.length() - 1; i >= 0; i--) {
            if (!indexMap.containsKey(i + 1)) {
                continue;
            }
            List<String> nextList = indexMap.get(i + 1);
            for (int length : lengthMap.keySet()) {
                int start = i - length + 1;
                if (start < 0) {
                    continue;
                }
                String sub = s.substring(start, i + 1);
                if (lengthMap.get(length).contains(sub)) {
                    List<String> list = indexMap.getOrDefault(start, new LinkedList<>());
                    for (String next : nextList) {
                        String current = sub + (next.length() > 0 ? " " + next : "");
                        list.add(current);
                    }
                    indexMap.put(start, list);
                    if (start == 0) {
                        break;
                    }
                }
            }
            if (indexMap.containsKey(0)) {
                break;
            }
        }

        return indexMap.getOrDefault(0, Collections.emptyList());
    }

    private static List<String> wordBreakBigram(String s, List<String> unigrams, Map<String, Double> bigrams) {
        int unigramMaxLength = 0;
        Set<String> unigramSet = new HashSet<>();
        /*for (String line : unigrams) {
            unigramMaxLength = Math.max(unigramMaxLength, line.length());
            unigramSet.add(line);
        }*/

        int bigramMaxLength = 0;
        long sum = 0l;
        Map<String, Double> bigramMap = new HashMap<>();
        for (String line : bigrams.keySet()) {
            String[] split = line.split("\\s+");
            try {
                Integer.parseInt(split[2]);
                bigramMap.put(split[0] + split[1], (double)Long.parseLong(split[2]));
                sum += Long.parseLong(split[2]);
                bigramMaxLength = Math.max(bigramMaxLength, split[0].length() + split[1].length());
                unigramMaxLength = Math.max(unigramMaxLength, split[0].length());
                unigramMaxLength = Math.max(unigramMaxLength, split[1].length());
                unigramSet.add(split[0]);
                unigramSet.add(split[1]);
            } catch (NumberFormatException e) {
                //System.out.println(e);
            }
        }

        Map<Integer, List<String>> indexMap = new HashMap<>();
        Map<Integer, Double> countMap = new HashMap<>();
        for (int i = 0; i < unigramMaxLength && i < s.length(); i++) {
            String substring = s.substring(0, i + 1);
            if (unigramSet.contains(substring)) {
                List<String> list = new ArrayList<>();
                list.add(substring);
                indexMap.put(i, list);
                countMap.put(i, 1.0);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (!indexMap.containsKey(i)) {
                continue;
            }
            List<String> words = indexMap.get(i);
            String lastWord = words.get(words.size() - 1);
            double count = countMap.get(i);
            for (int j = 0; j < bigramMaxLength && i + j + 1 < s.length(); j++) {
                double oldCount = countMap.getOrDefault(i + j + 1, 0.0);
                String substring = s.substring(i + 1, i + j + 2);
                System.out.println((i + 1) + "-" + (i + j + 1) + " " + lastWord  + " " + substring);
                if (bigramMap.containsKey(lastWord + substring)) {
                    double newCount = count * bigramMap.get(lastWord + substring) / sum;
                    System.out.println((i + 1) + "-" + (i + j + 1) + " " + lastWord  + " " + substring + " = " + newCount);
                    if (newCount > oldCount) {
                        countMap.put(i + j + 1, newCount);
                        List<String> newWords = new ArrayList<>(words);
                        newWords.add(substring);
                        indexMap.put(i + j + 1, newWords);
                    }
                }/* else if (!countMap.containsKey(i + j + 1) && unigramSet.contains(substring)) {
                    countMap.put(i + j + 1, 0.0);
                    List<String> newWords = new ArrayList<>(words);
                    newWords.add(substring);
                    indexMap.put(i + j + 1, newWords);
                    System.out.println((i + 1) + "-" + (i + j + 1) + " " + lastWord  + " " + substring + " = " + countMap.get(i + j + 1));
                }*/
            }
        }

        return indexMap.getOrDefault(s.length() - 1, new ArrayList<>());
    }
}