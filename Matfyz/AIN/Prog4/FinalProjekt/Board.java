package com.labyrinth.projekt;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;


/**
 * Trieda Board reprezentuje hernú plochu pre hru Labyrinth.
 * Zabezpečuje načítanie úrovní, vykreslenie hracej plochy,
 * pohyb hráča, logiku výhry/prehry a zobrazenie rôznych obrazoviek
 * ako je hlavné menu, reštartovanie alebo prechod na ďalšiu úroveň.
 *
 * Obsahuje aj vizuálne spracovanie políčok pomocou obrázkov.
 *
 * Trieda rozširuje {@link javafx.scene.layout.Pane}, v ktorom sa vykresľujú herné prvky.
 *
 * @author Peter Kendra
 */
public class Board extends Pane {
     private int sizeX, sizeY;
     private int playerX, playerY;
     private int checkpoints, currCheckpoints;
     private int level;
     private int memX , memY;
     private final int tileSize = 50;
     private ArrayList<ArrayList<Character>> board;
     private ArrayList<ArrayList<Boolean>> visited;
     private Stage stage;
     private Scene scene;
     private boolean menu;

    /**
     * Konštruktor triedy Board.
     * Inicializuje hernú plochu načítaním prvej úrovne z CSV súboru.
     */
     public Board() {
         level = 1;
         loadLevel("lvl1.csv");
     }

    /**
     * Získa počet riadkov (výšku) herného poľa.
     *
     * @return počet riadkov v hernom poli
     */
     public int getSizeX() {
         return sizeX;
     }

    /**
     * Získa počet stĺpcov (šírku) herného poľa.
     *
     * @return počet stĺpcov v hernom poli
     */
     public int getSizeY() {
         return sizeY;
     }

    /**
     * Získa veľkosť jednej dlaždice v pixeloch.
     *
     * @return veľkosť jednej dlaždice
     */
     public int getTileSize() {
         return tileSize;
     }

    /**
     * Nastaví inštanciu {@link Stage} a {@link Scene} pre hernú plochu.
     * Tieto objekty sa používajú na manipuláciu s oknom a zobrazením hry.
     *
     * @param stage hlavné okno aplikácie
     * @param scene scéna obsahujúca hernú plochu
     */
    public void setStageAndScene(Stage stage, Scene scene) {
        this.stage = stage;
        this.scene = scene;
    }

    /**
     * Zistí, či je aktuálne zobrazená nejaká menu obrazovka.
     *
     * @return {@code true}, ak je zobrazené menu; inak {@code false}
     */
    public boolean getMenu() {
         return menu;
    }


     private void loadLevel(String file) {
         currCheckpoints = 0;
         checkpoints = 0;
         memX = 0;
         memY = 0;

         try {
             BufferedReader br = new BufferedReader(new FileReader(file));
             String line = br.readLine();
             sizeX = Integer.parseInt(line.split(";")[0]);
             sizeY = Integer.parseInt(line.split(";")[1]);

             line = br.readLine();
             playerX = Integer.parseInt(line.split(";")[0]);
             playerY = Integer.parseInt(line.split(";")[1]);

             board = new ArrayList<>();
             visited = new ArrayList<>();
             for(int i = 0; i < sizeX; i++){
                 board.add(new ArrayList<>());
                 visited.add(new ArrayList<>());
                 line = br.readLine();
                 for(int j = 0; j < sizeY; j++){
                     board.get(i).add(line.charAt(2*j));
                     if (Character.isDigit(board.get(i).get(j))) checkpoints++;
                     if (i == playerX && j == playerY) {
                         visited.get(i).add(true);
                     } else {
                         visited.get(i).add(false);
                     }

                 }
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
     }

    /**
     * Skontroluje, či hráč vyhral úroveň.
     * Výhra nastáva, ak hráč prešiel všetky kontrolné body.
     *
     * @return {@code true}, ak sú všetky checkpointy splnené; inak {@code false}
     */
     public boolean checkWin() {
         return checkpoints == currCheckpoints;
     }

    /**
     * Skontroluje, či hráč prehral úroveň.
     * Prehra nastáva, ak nie sú dostupné žiadne platné ťahy.
     *
     * @return {@code true}, ak nie je možný žiadny ďalší pohyb; inak {@code false}
     */
     public boolean checkLose() {
         return !(isValidMove(0,1) || isValidMove(0,-1) || isValidMove(1,0) || isValidMove(-1,0));
     }

     private void nextLevel() {
         if (level == 1) {
             level++;
             loadLevel("lvl2.csv");
             stage.setTitle("Level 2");
         } else if (level == 2) {
             level++;
             loadLevel("lvl3.csv");
             stage.setTitle("Level 3");
         } else if (level == 0) {
             level++;
             loadLevel("lvl1.csv");
             stage.setTitle("Level 1");
         }

         stage.setWidth(sizeX * tileSize + 14);
         stage.setHeight(sizeY * tileSize + 38);
     }

     private void restartLevel() {
         if (level == 1) {
             loadLevel("lvl1.csv");
         } else if (level == 2) {
             loadLevel("lvl2.csv");
         } else if (level == 3) {
             loadLevel("lvl3.csv");
         }
     }

     private boolean isValidMove(int x, int y) {

         if (playerX + x >= 0 && playerX + x < sizeX && playerY + y >= 0 && playerY + y < sizeY) {
             if (visited.get(playerX + x).get(playerY + y)) {
                 return false;
             }

             char tmp = board.get(playerX + x).get(playerY + y);

             if (tmp == '#') {
                 return false;
             }

             if (Character.isDigit(tmp) && (tmp - '0' != currCheckpoints + 1)) {
                 return false;
             }


             if (tmp == '>' && y != 1){
                 return false;
             }

             if (tmp == '<' && y != -1){
                 return false;
             }

             if (tmp == '^' && x != -1){
                 return false;
             }

             if (tmp == 'v' && x != 1){
                 return false;
             }


             if (memX != memY && (memX != x || memY != y)) {
                 return false;
             }


             return true;
         }
         return false;
     }

    /**
     * Presunie hráča v hernom poli podľa zadaného smeru.
     * Zohľadňuje logiku platných ťahov, teleporty a checkpointy.
     *
     * @param x posun v riadkoch (napr. -1 pre pohyb hore)
     * @param y posun v stĺpcoch (napr. 1 pre pohyb doprava)
     */
     public void movePlayer(int x, int y) {

         if (memX != memY && memX == x && memY == y) {
             memX = 0;
             memY = 0;
         }

         if (!isValidMove(x, y)) {
             return;
         }

         playerX += x;
         playerY += y;
         visited.get(playerX).set(playerY, true);

         char tmp = board.get(playerX).get(playerY);

         if (tmp == '>' || tmp == '<' || tmp == '^' || tmp == 'v') {
             board.get(playerX).set(playerY, '#');
             memX = x;
             memY = y;
         }
         else if (Character.isDigit(tmp)) {
             board.get(playerX).set(playerY, '0');
             currCheckpoints++;
         } else if (tmp == 'A'){
             board.get(playerX).set(playerY, 'a');
             teleport('A');
         } else if (tmp == 'B'){
             board.get(playerX).set(playerY, 'b');
             teleport('B');
         } else if (tmp == 'C'){
             board.get(playerX).set(playerY, 'c');
             teleport('C');
         }

     }

    private void teleport(char tp){
         for (int i = 0; i < sizeX; i++) {
             for (int j = 0; j < sizeY; j++) {
                 if (board.get(i).get(j) == tp && playerX != i && playerY != j) {
                     playerX = i;
                     playerY = j;
                     board.get(i).set(j, Character.toLowerCase(tp));
                     visited.get(i).set(j, true);
                }
            }
        }
    }

    /**
     * Vykreslí hlavné menu s tlačidlom na začatie hry.
     */
    public void drawMainScreen(){
         menu = true;
         Button startButton = new Button("Start");
         Label title = new Label("Labyrinth");
         title.setStyle("-fx-font-size: 36px; -fx-font-weight: bold;");

         startButton.setOnAction(e -> {
             drawBoard();
             menu = false;
         });

        VBox vbox = new VBox(20);
        vbox.setAlignment(Pos.CENTER);
        vbox.getChildren().addAll(title, startButton);
        vbox.setPrefSize(sizeY * tileSize, sizeX * tileSize);

        getChildren().add(vbox);
    }

    /**
     * Vykreslí obrazovku po úspešnom dokončení úrovne.
     * Ak ide o poslednú úroveň, zobrazí sa možnosť reštartu hry.
     */
    public void drawLevelPassedScreen(){
         if (level == 3) {
             menu = true;
             getChildren().clear();
             Button gamePassed = new Button("Restart game");
             Label title = new Label("All levels passed");
             title.setStyle("-fx-font-size: 36px; -fx-font-weight: bold;");

             gamePassed.setOnAction(e -> {
                 level = 0;
                 nextLevel();
                 drawBoard();
                 menu = false;
             });

             VBox vbox = new VBox(20);
             vbox.setAlignment(Pos.CENTER);
             vbox.getChildren().addAll(title, gamePassed);
             vbox.setPrefSize(sizeY * tileSize, sizeX * tileSize);

             getChildren().add(vbox);

             return;
         }

        menu = true;
        getChildren().clear();
        Button nextLevel = new Button("Next Level");
        Label title = new Label("Level " + level +" passed");
        title.setStyle("-fx-font-size: 36px; -fx-font-weight: bold;");

        nextLevel.setOnAction(e -> {
            nextLevel();
            drawBoard();
            menu = false;
        });

        VBox vbox = new VBox(20);
        vbox.setAlignment(Pos.CENTER);
        vbox.getChildren().addAll(title, nextLevel);
        vbox.setPrefSize(sizeY * tileSize, sizeX * tileSize);

        getChildren().add(vbox);
    }

    /**
     * Vykreslí obrazovku, ktorá informuje hráča, že prehral (nemá ďalší možný ťah),
     * a ponúka možnosť reštartovať aktuálnu úroveň.
     */
    public void drawRestartScreen(){
        menu = true;
        getChildren().clear();
        Button restartLevel = new Button("Restart Level");
        Label title = new Label("No more possible moves");
        title.setStyle("-fx-font-size: 18px; -fx-font-weight: bold;");

        restartLevel.setOnAction(e -> {
            restartLevel();
            drawBoard();
            menu = false;
        });

        VBox vbox = new VBox(20);
        vbox.setAlignment(Pos.CENTER);
        vbox.getChildren().addAll(title, restartLevel);
        vbox.setPrefSize(sizeY * tileSize, sizeX * tileSize);

        getChildren().add(vbox);
    }


    /**
     * Vykreslí hernú plochu vrátane stien, checkpointov, teleportov a hráča.
     * Používa grafické prvky a obrázky pre jednotlivé typy políčok.
     */
    public void drawBoard(){
        getChildren().clear();
        Image image;

        for(int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY; j++){


                Rectangle tile = new Rectangle(j*tileSize, i*tileSize, tileSize, tileSize);
                tile.setStroke(Color.BLACK);

                if (i == playerX && j == playerY){
                    image = new Image(getClass().getResource("/images/player.png").toExternalForm());
                    tile.setFill(new ImagePattern(image));

                } else {
                    char tmp = board.get(i).get(j);

                    if (tmp == '#'){
                        image = new Image(getClass().getResource("/images/wall.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '>'){
                        image = new Image(getClass().getResource("/images/wall_right.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '<'){
                        image = new Image(getClass().getResource("/images/wall_left.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '^'){
                        image = new Image(getClass().getResource("/images/wall_up.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'v'){
                        image = new Image(getClass().getResource("/images/wall_down.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    }

                    else if (tmp == 'A'){
                        image = new Image(getClass().getResource("/images/teleportA_active.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'a'){
                        image = new Image(getClass().getResource("/images/teleportA_inactive.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'B'){
                        image = new Image(getClass().getResource("/images/teleportB_active.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'b'){
                        image = new Image(getClass().getResource("/images/teleportB_inactive.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'C'){
                        image = new Image(getClass().getResource("/images/teleportC_active.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == 'c'){
                        image = new Image(getClass().getResource("/images/teleportC_inactive.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    }

                    else if (tmp == '0'){
                        image = new Image(getClass().getResource("/images/checkpoint_taken.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '1'){
                        image = new Image(getClass().getResource("/images/checkpoint1.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '2'){
                        image = new Image(getClass().getResource("/images/checkpoint2.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '3'){
                        image = new Image(getClass().getResource("/images/checkpoint3.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '4'){
                        image = new Image(getClass().getResource("/images/checkpoint4.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    } else if (tmp == '5'){
                        image = new Image(getClass().getResource("/images/checkpoint5.png").toExternalForm());
                        tile.setFill(new ImagePattern(image));
                    }

                    else if(visited.get(i).get(j)){
                        tile.setFill(Color.LIGHTYELLOW);
                    } else {
                        tile.setFill(Color.WHITE);
                    }
                }
                getChildren().add(tile);
            }
        }
    }
}
