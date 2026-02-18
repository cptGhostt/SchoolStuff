package com.example.cva;

import java.util.Calendar;
import java.util.GregorianCalendar;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import javafx.util.Duration;


public class RucickyFxCvicenie extends Application {
    @Override // Override the start method in the Application class
    public void start(Stage primaryStage) {
        ClockPaneCvicenie3 clock = new ClockPaneCvicenie3();

        // Create a handler for animation
        EventHandler<ActionEvent> eventHandler = e -> {
            clock.setCurrentTime(); // Set a new clock time
        };

        // Create an animation for a running clock
        //Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), eventHandler));

        Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), e -> {clock.setCurrentTime();}));
        animation.setCycleCount(Timeline.INDEFINITE);
        animation.play(); // Start animation

        Scene scene = new Scene(clock);	// vytvor scenu

        // nastavena vazieb
        scene.widthProperty().addListener(ov -> clock.setW(scene.getWidth()));
        scene.heightProperty().addListener(ov -> clock.setH(scene.getHeight()));

        primaryStage.setTitle("Hodinky"); 	// pomenuj okno aplikacie, javisko
        primaryStage.setScene(scene); 			// vloz scenu do hlavneho okna, na javisko
        primaryStage.show(); 					// zobraz javisko
    }
    public static void main(String[] args) {
        launch(args);
    }
}

class ClockPaneCvicenie3 extends Pane {
    private int hour;
    private int minute;
    private int second;

    // Clock pane's width and height
    private double w = 450, h = 450;

    public ClockPaneCvicenie3() {
        setPrefSize(w, h);
        setCurrentTime();
    }
    public void setH(double h) {
        this.h = h;
        paintClock();
    }
    public void setW(double w) {
        this.w = w;
        paintClock();
    }
    public void setCurrentTime() {
        Calendar calendar = new GregorianCalendar();
        // nastav this.hour, minute, second podla aktualneho casu
        second = calendar.get(Calendar.SECOND);
        minute = calendar.get(Calendar.MINUTE);
        hour = calendar.get(Calendar.HOUR);
        paintClock(); // Repaint the clock
    }

    protected void paintClock() {
        System.out.println("paint " + second);
        double clockRadius = Math.min(w, h) * 0.7/2;
        double centerX = w / 2;
        double centerY = h / 2;
        getChildren().clear();

        // kresli cifernik
        Circle c = new Circle(centerX, centerY, clockRadius);
        c.setStroke(Color.BLACK);
        c.setFill(Color.YELLOWGREEN);
        getChildren().add(c);

        // kresli sekudnovku
        double alpha = second * 2* Math.PI/60;
        double secLen = Math.min(w, h) * 0.6/2;
//        Line secLine = new Line(centerX, centerY,
//                centerX + secLen*Math.sin(alpha),
//                centerY - secLen*Math.cos(alpha)
//        );
        double alpha270 = alpha + 3*Math.PI/2;
        Line secLine = new Line(centerX, centerY,
                centerX + secLen*Math.cos(alpha270),
                centerY + secLen*Math.sin(alpha270)
        );

        secLine.setStroke(Color.RED);
        secLine.setStrokeWidth(3);
        getChildren().add(secLine);

        // kresli minutovku
        // dorobit

        double beta = minute * 2* Math.PI/60;
        double minLen = Math.min(w, h) * 0.5/2;
        double beta270 = beta + 3*Math.PI/2;

        Line minLine = new Line(centerX, centerY,
                centerX + minLen * Math.cos(beta270),
                centerY + minLen * Math.sin(beta270));

        minLine.setStroke(Color.BLACK);
        minLine.setStrokeWidth(4);
        getChildren().add(minLine);

        // kresli hodinovku
        // dorobit

        double hourIn60 = (hour % 12 + minute / 60.0) * 5; // tento riadok mi poradil chatGPT
        double gama = hourIn60 * 2 * Math.PI/60;
        double hourLen = Math.min(w, h) * 0.3/2;
        double gama270 = gama + 3*Math.PI/2;
        Line hourLine = new Line(centerX, centerY,
                centerX + hourLen * Math.cos(gama270),
                centerY + hourLen * Math.sin(gama270));

        hourLine.setStroke(Color.BLACK);
        hourLine.setStrokeWidth(6);
        getChildren().add(hourLine);

        // kresli ciselnik
        // dorobit

        for (int i = 1; i <= 12; i++){
            double numAngle = i * 2 * Math.PI/12;
            double numRadius = clockRadius * 0.85; // tento riadok mi poradil chatGPT
            double x = centerX + numRadius * Math.sin(numAngle);
            double y = centerY - numRadius * Math.cos(numAngle);

            javafx.scene.text.Text text = new javafx.scene.text.Text(x - 10, y + 5, String.valueOf(i));
            text.setFill(Color.BLACK);
            text.setStyle("-fx-font-size: 18px; -fx-font-weight: bold;");
            getChildren().add(text);

        }

    }
}