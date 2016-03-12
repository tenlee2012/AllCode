/**
工厂设计模式？？？
**/
interface Game { boolean move(); }
interface GameFactory { Game getGame(); }

class Checkers implements Game {
    private int moves = 0;
    private static final int MOVES = 3;
    public boolean move() {
        System.out.println("Checkers move " + moves);
        return ++moves != MOVES;
    }
}

class CheckersFactory implements GameFactory {
    public Game getGame() { return new Checkers(); }
}

class Chess implements Game {
    private int moves = 0;
    private static final int MOVES = 3;
    public boolean move() {
        System.out.println("Chess move " + moves);
        return ++moves != MOVES;
    }
}

class ChessFactory implements GameFactory {
    public Game getGame() { return new Chess(); }
}

public class Factories {
    public static void playFactory(GameFactory factory) {
        Game s = factory.getGame();
        while(s.move());
    }
    public static void playGame(Game game) {
        while(game.move());
    }
    public static void main(String[] args) {
        playFactory(new ChessFactory());
        playFactory(new CheckersFactory());
        System.out.println("-----------------------");
        playGame(new Chess());
        playGame(new Checkers());
    }
}
