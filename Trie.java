// https://leetcode.com/problems/implement-trie-prefix-tree/description/

public class Trie {

    class Node {
        Node links[] = new Node[26];
        boolean isEndOfWord;
        Node() {
            isEndOfWord = false;
            for(int i=0; i<26; i++)
                links[i] = null;
        }
    }

    Node root;

    public Trie() {
        root  = new Node();
    }

    public void insert(String word) {
        Node node = root;
        for(int i=0; i<word.length(); i++) {
            int index = word.charAt(i)-'a';
            if(node.links[index] == null)
                node.links[index] = new Node();
            node = node.links[index];
        }
        node.isEndOfWord = true;
    }

    public boolean search(String word) {
        Node node = root;
        for(int i=0; i<word.length(); i++) {
            int index = word.charAt(i)-'a';
            if(node.links[index] == null)
                return false;
            node = node.links[index];
        }
        return node.isEndOfWord;
    }

    public boolean startsWith(String word) {
        Node node = root;
        for(int i=0; i<word.length(); i++) {
            int index = word.charAt(i)-'a';
            if(node.links[index] == null)
                return false;
            node = node.links[index];
        }
        return true;
    }

    public static void main(String args[]) {
        Trie trie = new Trie();
        System.out.println("Inserting word: apple");
        trie.insert("apple");
        System.out.println("Searching word: apple");
        System.out.println("Result: " + trie.search("apple"));
        System.out.println("Searching word: app");
        System.out.println("Result: " + trie.search("app"));
        System.out.println("Searching prefix: app");
        System.out.println("Result: " + trie.startsWith("app"));
    }
}
