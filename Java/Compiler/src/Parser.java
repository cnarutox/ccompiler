import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;

public class Parser {
    public static void main(String[] args) {
        int STATE = 0;
        System.out.println("STATE: FILE");
        Scanner sc = new Scanner(System.in);
        String input;
        Parser series = new Parser("");
        while (true) {
            if ((input = sc.nextLine()) != null) {
                if (input.equals("@file")) {
                    STATE = 0;
                    System.out.println("STATE: FILE");
                } else if (input.equals("@single")) {
                    STATE = 1;
                    System.out.println("STATE: SINGLE");
                } else if (input.equals("@series")) {
                    STATE = 2;
                    series = new Parser("");
                    System.out.println("STATE: SERIES");
                } else if (input.equals("@exit")) {
                    break;
                } else {
                    switch (STATE) {
                        case Parser.STATE_FILE: {
                            try {
                                BufferedReader br = new BufferedReader(new FileReader(new File(input)));
                                StringBuilder buf = new StringBuilder();
                                String s;
                                while ((s = br.readLine()) != null) {
                                    buf.append("\n");
                                    buf.append(s);
                                }
                                Parser parser = new Parser(buf.toString());
                                parser.parser();
                                parser.showLexemes();
                            } catch (FileNotFoundException e) {
                                System.out.println("File Not Found.");
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                            break;
                        }
                        case Parser.STATE_SERIES: {
                            if (input.equals("@show")) {
                                series.showLexemes();
                            } else {
                                series.parser(input);
                            }
                            break;
                        }
                        case Parser.STATE_SINGLE: {
                            Parser parser = new Parser(input);
                            parser.parser();
                            parser.showLexemes();
                            break;
                        }
                    }
                }
            }
        }
    }

    private final static int STATE_FILE = 0;
    private final static int STATE_SINGLE = 1;
    private final static int STATE_SERIES = 2;

    private final static String Blank = "[ \\t\\n]+";
    private final static String Number = "[0-9]+(.[0-9]+)?(E[+-]?[0-9]+)?";
    private final static String Symbol = "[A-Za-z_]([0-9]|[A-Za-z_])*";
    private final static String AnnotationLine = "\\/\\/(\\s|.)*?\\n";
    private final static String AnnotationBlock = "\\/\\*(\\s|.)*?\\*\\/";
    private final static String Array = Symbol + "\\[" + Number + "?\\]";
    private final static String ArrayDefine = "\\{(" + Number + ",)*" + Number + "\\}";
    private final static Lexeme[] Keywords = {
            new Lexeme("VOID", "void", false),
            new Lexeme("MAIN", "main", false),
            new Lexeme("ASSIGN", "=", false),
            new Lexeme("INT", "int", false),
            new Lexeme("FLOAT", "float", false),
            new Lexeme("CHAR", "char", false),
            new Lexeme("DOUBLE", "double", false),
            new Lexeme("SHORT", "short", false),
            new Lexeme("LONG", "long", false),
            new Lexeme("COLON", ":", false),
            new Lexeme("LP", "(", false),
            new Lexeme("RP", ")", false),
            new Lexeme("LBRACE", "{", false),
            new Lexeme("RBRACE", "}", false),
            new Lexeme("SEMICOL", ";", false),
            new Lexeme("FOR", "for", false),
            new Lexeme("LESS", "<", false),
            new Lexeme("ADD", "+", false),
            new Lexeme("MINUS", "-", false),
            new Lexeme("IF", "if", false),
            new Lexeme("MORE", ">", false),
            new Lexeme("MUTIPLY", "*", false),
            new Lexeme("DIVIDE", "/", false),
            new Lexeme("THEN", "then", false),
            new Lexeme("BREAK", "break", false),
            new Lexeme("CASE", "case", false),
            new Lexeme("CONST", "const", false),
            new Lexeme("CONTINUE", "continue", false),
            new Lexeme("DEFAULT", "default", false),
            new Lexeme("DO", "do", false),
            new Lexeme("DOUBLE", "else", false),
            new Lexeme("ENUM", "enum", false),
            new Lexeme("EXTERN", "extern", false),
            new Lexeme("GOTO", "goto", false),
            new Lexeme("RETURN", "return", false),
            new Lexeme("REGISTER", "register", false),
            new Lexeme("SIGNED", "signed", false),
            new Lexeme("UNSIGNED", "unsigned", false),
            new Lexeme("SIZEOF", "sizeof", false),
            new Lexeme("STATIC", "static", false),
            new Lexeme("STRUCT", "struct", false),
            new Lexeme("SWITCH", "switch", false),
            new Lexeme("TYPEDEF", "typedef", false),
            new Lexeme("UNION", "union", false),
            new Lexeme("VOLATILE", "volatile", false),
            new Lexeme("WHILE", "while", false)
    };
    private final static Pattern[] Patterns = {new Pattern(AnnotationLine) {
        @Override
        protected void action(Parser parser, String str) {
            parser.putLexeme("ANNOTATION", str.substring(2, str.length() - 2));
        }
    }, new Pattern(AnnotationBlock) {
        @Override
        protected void action(Parser parser, String str) {
            parser.putLexeme("ANNOTATION", str.substring(2, str.length() - 2));
        }
    }, new Pattern(ArrayDefine) {
        @Override
        protected void action(Parser parser, String str) {
            parser.putLexeme("ARRAY", str);
        }
    }};

    private ArrayList<Lexeme> Symbols;
    private ArrayList<Lexeme> Lexemes;
    private String string;

    private final static String StringFormat = "| %10s | %10s | %10s |";

    static class Lexeme {
        // 类型   值   引用
        private String type;
        private String value;
        private String quote;

        public Lexeme(String type, String value, boolean quote) {
            this.type = type;
            this.value = value;
            if (quote) {
                this.quote = String.valueOf(this.hashCode());
            }
        }

        public boolean match(String str) {
            return str.equals(value);
        }

        @Override
        public String toString() {
            return String.format(StringFormat, type, value, quote);
        }
    }

    static abstract class Pattern {
        private String regex;
        private java.util.regex.Pattern pattern;
        private Matcher matcher;

        public Pattern(String regex) {
            this.regex = regex;
            this.pattern = java.util.regex.Pattern.compile(regex);
        }

        public String solve(Parser parser, String str) {
            matcher = pattern.matcher(str);
            while (matcher.find()) {
                action(parser, matcher.group());
            }
            return Pattern.stringJoin(str.split(regex));
        }

        protected void action(Parser parser, String str) {
        }

        private final static String stringJoin(String[] strings) {
            StringBuilder buf = new StringBuilder();
            for (String s : strings) {
                buf.append(s);
            }
            return buf.toString();
        }
    }

    public Parser(String string) {
        this.string = string;
        Symbols = new ArrayList<>();
        Lexemes = new ArrayList<>();
    }

    public void showLexemes() {
        System.out.println(String.format(StringFormat, "TYPE", "VALUE", "QUOTE"));
        for (Lexeme lexeme : Lexemes) {
            System.out.println(lexeme);
        }
        for (Lexeme lexeme : Symbols) {
            System.out.println(lexeme);
        }
    }

    private void getLexemesFromNoBlankString(String string) {
        getLexemesFromNoBlankString(string, string.length());
    }

    private void getLexemesFromNoBlankString(String string, Integer endIndex) {
        int index = 0;
        for (; getLexeme(string.substring(index, endIndex)) == null &&
                index < endIndex;
             index++) {
        }
        endIndex = index;
        if (endIndex > 0) {
            getLexemesFromNoBlankString(string, endIndex);
        }
    }

    private Lexeme getLexeme(String string) {
        return getKeyword(string);
    }

    private Lexeme getKeyword(String string) {
        for (Lexeme lexeme : Keywords) {
            if (lexeme.match(string)) {
                return putLexeme(lexeme);
            }
        }
        return getSymbol(string);
    }

    private Lexeme getSymbol(String string) {
        for (Lexeme lexeme : Symbols) {
            if (lexeme.match(string)) {
                putLexeme(lexeme);
                return lexeme;
            }
        }
        if (string.matches(Symbol)) {
            return putSymbol(string);
        } else if (string.matches(Array)) {
//            数组存储头地址
            return putSymbol(string.split("\\[")[0]);
        } else if (string.matches(Number)) {
            return putLexeme("NUMBER", string);
        }
        return null;
    }

    private Lexeme putSymbol(String symbol) {
        Lexeme lexeme = new Lexeme("ID", symbol, true);
        Symbols.add(lexeme);
        return lexeme;
    }

    private Lexeme putLexeme(String type, String value) {
        Lexeme lexeme = new Lexeme(type, value, false);
        Lexemes.add(lexeme);
        return lexeme;
    }

    private Lexeme putLexeme(Lexeme lexeme) {
        Lexemes.add(lexeme);
        return lexeme;
    }

    // 解析一整个文件
    public Parser parser() {
        return parser(this.string);
    }

    // 在源文件的解析基础上解析
    public Parser parser(String string) {
        String tmp = string;
        for (Pattern pattern : Patterns) {
            tmp = pattern.solve(this, tmp);
        }
        String[] strings = tmp.split(Blank);
        for (String s : strings) {
            getLexemesFromNoBlankString(s);
        }
        return this;
    }

    // 单独解析一个字符串
    public static void Parser(String string) {
        new Parser(string).parser().showLexemes();
    }
}
