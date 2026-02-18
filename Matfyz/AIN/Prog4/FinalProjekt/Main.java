package com.labyrinth.projekt;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * Hlavná trieda aplikácie Labyrinth, ktorá spúšťa JavaFX aplikáciu.
 * Inicializuje hernú scénu, nastavuje ovládanie a zobrazuje úvodnú obrazovku.
 *
 * @author Peter Kendra
 */
public class Main extends Application {

    /**
     * Hlavný vstupný bod aplikácie.
     * Spúšťa JavaFX aplikáciu pomocou metódy {@code launch(args)}.
     *
     * @param args argumenty príkazového riadku (nepoužívajú sa)
     */
    public static void main(String[] args) {
    launch(args);
    }

    /**
     * Štartovacia metóda JavaFX aplikácie, ktorá sa volá po inicializácii JavaFX runtime.
     * Vytvorí hernú scénu, nastaví ovládanie a zobrazí hlavné menu.
     *
     * @param primaryStage hlavné okno aplikácie
     */
    public void start(Stage primaryStage){
        Board board = new Board();

        Scene scene = new Scene(board, board.getSizeX()*board.getTileSize(), board.getSizeY()*board.getTileSize());

        board.setStageAndScene(primaryStage, scene);

        scene.setOnKeyPressed(event -> {
            if (!board.getMenu()) {
                switch (event.getCode()) {
                    case UP, W -> board.movePlayer(-1, 0);
                    case DOWN, S -> board.movePlayer(1, 0);
                    case LEFT, A -> board.movePlayer(0, -1);
                    case RIGHT, D -> board.movePlayer(0, 1);
                }

                if (board.checkWin()) {
                    board.drawLevelPassedScreen();
                } else if (board.checkLose()) {
                    board.drawRestartScreen();
                } else {
                    board.drawBoard();
                }
            }
        });

        primaryStage.setTitle("Level 1");
        primaryStage.setScene(scene);
        primaryStage.show();
        board.drawMainScreen();

    }

}
