package application;

import java.util.ArrayList;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ComboBox;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;


public class Main extends Application implements EventHandler<ActionEvent>{

	private ArrayList<Button> buttons;

	private ArrayList<ComboBox<String>> comboboxes;

	// Optional
	private ArrayList<ArrayList<ComboBox<String>>> arrayListOfArrayLists;

	private ArrayList<Pane> panes;

	private ArrayList<Circle> guessCircles;

	private ArrayList<Circle> hintCircles;

	int numButtons = 10;

	int numComboBoxes = 4;

	int numCircles = 10;

	private Model model = new Model();

	private String s = "";

	int throwAwayInt = 0;

	private boolean debugMode = false;

	@Override
	public void start(Stage primaryStage) {
		try {
			model.newGame();
			primaryStage.setTitle("COS212 Final Project: Mastermind Game");
			BorderPane borderPane = new BorderPane();
			Scene scene = new Scene(borderPane,500,600, Color.BEIGE); 
			GridPane leftGridPane = new GridPane(); // Left grid pane is for guesses
			GridPane rightGridPane = new GridPane(); // Right grid pane is for hints
			GridPane comboGridPane = new GridPane(); // Grid pane for combo boxes
			GridPane bottomGridPane = new GridPane(); // Grid pane for bottom row

			// BorderPane has 5 sections, top bottom left right and middle
			// borderPane.setStyle("-fx-background-color: linear-gradient(from 25% 25% to 100% 100%, #dc143c, #661a33)");
			borderPane.setStyle("-fx-background-color: #F5F5DC");

			// Creating and adding an arraylist of buttons
			buttons = new ArrayList<Button>();


			// Change Scene color
			/*
			for (int i = 0; i < numButtons; i++) // or as many buttons as you want (instead of 10)
			{
				buttons.add(new Button(i+""));
				buttons.get(i).setPrefSize(40, 40);
				if (i % 2 == 0)
					buttons.get(i).setBackground(new Background(new BackgroundFill(Color.DARKRED, CornerRadii.EMPTY, Insets.EMPTY)));
				else 
					buttons.get(i).setBackground(new Background(new BackgroundFill(Color.LIGHTBLUE, CornerRadii.EMPTY, Insets.EMPTY)));

				buttons.get(i).setOnAction(this);  // when there's an action, check THIS class to see how to handle it
				borderPane.add(buttons.get(i), i, 0); 
			}
			 */

			// Add a submit button
			buttons.add(new Button("Submit")); // index 0
			buttons.add(new Button("Reset")); // index 1
			buttons.add(new Button("Debug Mode")); // index 2


			// Set button size [(width, height)
			buttons.get(0).setPrefSize(100, 40);
			buttons.get(1).setPrefSize(100, 40);
			buttons.get(2).setPrefSize(100,  40);

			// Set color to green
			buttons.get(0).setBackground(new Background(new BackgroundFill(Color.DARKGREEN, CornerRadii.EMPTY, Insets.EMPTY)));
			buttons.get(1).setBackground(new Background(new BackgroundFill(Color.DARKORANGE, CornerRadii.EMPTY, Insets.EMPTY)));
			buttons.get(2).setBackground(new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY)));


			// Set action to check
			buttons.get(0).setOnAction(this); // When there's an action, check THIS class to see how to handle it
			buttons.get(1).setOnAction(this);
			buttons.get(2).setOnAction(this);

			// Set the position to the bottom right
			bottomGridPane.add(buttons.get(0), 0, 0);
			bottomGridPane.add(buttons.get(1), 1, 0);
			bottomGridPane.add(buttons.get(2), 2, 0);
			borderPane.setBottom(bottomGridPane);


			// Make a bunch of heckin blank circles on the left for guesses
			guessCircles = new ArrayList<Circle>();

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					guessCircles.add(new Circle(20));
					guessCircles.get(4*i + j).setFill(Color.WHITE);
					leftGridPane.add(guessCircles.get(4*i + j), j, i);
				}
			}
			borderPane.setLeft(leftGridPane);


			// Make a bunch of heckin blank circles on the right for hints
			hintCircles = new ArrayList<Circle>();

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					hintCircles.add(new Circle(20));
					hintCircles.get(4*i + j).setFill(Color.BEIGE);
					rightGridPane.add(hintCircles.get(4*i + j), j, i);
				}
			}
			borderPane.setRight(rightGridPane);



			// Creating an arraylist of combo boxes
			String [] colorNames = {"Red", "Blue", "Yellow", "Green", "Purple", "Orange"};
			comboboxes = new ArrayList<ComboBox<String>>();
			for (int i = 0; i < numComboBoxes; i++)
			{
				comboboxes.add(new ComboBox<String>());
				comboboxes.get(i).getItems().addAll(colorNames);
				comboGridPane.add(comboboxes.get(i), i*2, 1);
			}
			borderPane.setTop(comboGridPane);


			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setScene(scene);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void handle(ActionEvent event) {


		// If the submit button is pressed
		if (event.getSource() == buttons.get(0))  // Submit button
		{ // Fill array with the guesses
			try {
				s = "";

				if (debugMode)
				{
					System.out.println("Getting to custom game on turn: " + model.getTurn());
					debugMode = false;
					for (int i = 0; i < 4; i++)
					{
						//  Sets string to be passed into 'set guess' of model
						if (comboboxes.get(i).getSelectionModel().isEmpty())
						{ // !model.isViableGuess(comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0)) || 
							Alert error = new Alert(Alert.AlertType.ERROR);
							error.setTitle("ERROR");
							error.setContentText("You did not enter a valid argument, game will now reset....");
							error.showAndWait();
							resetGame();
							return;
						}
						else if (!model.isViableGuess(comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0)))
						{
							Alert error = new Alert(Alert.AlertType.ERROR);
							error.setTitle("ERROR");
							error.setContentText("You did not enter a valid argument, game will now reset....");
							error.showAndWait();
							resetGame();
							return;
						}
								
						s = s + comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0);

						// Sets the correct circle to the correct color, based on first char of string and index of circle
						// setCircleColorFromChar(comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0), model.getTurn()*4 + i);
					}
					// set things to normal
					buttons.get(0).setBackground(new Background(new BackgroundFill(Color.DARKGREEN, CornerRadii.EMPTY, Insets.EMPTY)));
					buttons.get(1).setBackground(new Background(new BackgroundFill(Color.DARKORANGE, CornerRadii.EMPTY, Insets.EMPTY)));
					buttons.get(2).setBackground(new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY)));
					model.newCustomGame(s);
					System.out.println("exiting custom game on turn: " + model.getTurn());

				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						//  Sets string to be passed into 'set guess' of model
					//  Sets string to be passed into 'set guess' of model
						if (comboboxes.get(i).getSelectionModel().isEmpty())
						{
							Alert error = new Alert(Alert.AlertType.ERROR);
							error.setTitle("ERROR");
							error.setContentText("You did not enter a valid argument, game will now reset....");
							error.showAndWait();
							resetGame();
							return;
						}
						else if (!model.isViableGuess(comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0)))
						{
							Alert error = new Alert(Alert.AlertType.ERROR);
							error.setTitle("ERROR");
							error.setContentText("You did not enter a valid argument, game will now reset....");
							error.showAndWait();
							resetGame();
							return;
						}
						
						s = s + comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0);

						// Sets the correct circle to the correct color, based on first char of string and index of circle
						setCircleColorFromChar(comboboxes.get(i).getSelectionModel().getSelectedItem().charAt(0), model.getTurn()*4 + i);
					}
					model.setGuess(s);

					// Set hint color
					for (int i = 0; i < model.countNumBlack(); i++)
					{
						hintCircles.get(model.getTurn()*4 + i).setFill(Color.BLACK);
					}


					// If they win
					if (model.countNumBlack() == 4)
					{
						Alert win = new Alert(Alert.AlertType.INFORMATION);
						win.setTitle("WINNER");
						win.setContentText("You've won with " + (10 - model.getTurn()) + " points!!");
						win.showAndWait();
						resetGame();
					}


					int blackPegs = model.countNumBlack(), whitePegs = model.countNumWhite();
					for (int i = blackPegs; i < blackPegs + whitePegs; i++)
					{
						hintCircles.get((model.getTurn()-1)*4 + i).setFill(Color.WHITE);
					}


					// If that was their last turn, kill'em
					if (model.getTurn() >= 10)
					{
						Alert lose = new Alert(Alert.AlertType.INFORMATION);
						lose.setTitle("LOSER");
						lose.setContentText("You lost :( The code was: " + model.printKey());
						lose.showAndWait();
						resetGame();
					}


				}
			}
			catch (Exception e)
			{
				e.printStackTrace();
			}
		} // end of if statement for Submit button

		try // Reset button
		{
			if (event.getSource() == buttons.get(1)) 
			{
				debugMode = false;
				buttons.get(0).setBackground(new Background(new BackgroundFill(Color.DARKGREEN, CornerRadii.EMPTY, Insets.EMPTY)));
				buttons.get(1).setBackground(new Background(new BackgroundFill(Color.DARKORANGE, CornerRadii.EMPTY, Insets.EMPTY)));
				buttons.get(2).setBackground(new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY)));
				s = "";
				model.newGame();

				// TODO: Loop through and reset all loop colors
				for (int i = 0; i < hintCircles.size(); i++)
				{
					guessCircles.get(i).setFill(Color.WHITE);
					hintCircles.get(i).setFill(Color.BEIGE);

				}
			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}

		try // Debug Mode
		{
			if (event.getSource() == buttons.get(2)) 
			{
				// submit and reset to grey
				buttons.get(0).setBackground(new Background(new BackgroundFill(Color.GREY, CornerRadii.EMPTY, Insets.EMPTY)));
				buttons.get(1).setBackground(new Background(new BackgroundFill(Color.GREY, CornerRadii.EMPTY, Insets.EMPTY)));
				buttons.get(2).setBackground(new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY)));

				// reset game
				debugMode = true;
				s = "";
				model.newGame();

				// TODO: Loop through and reset all loop colors
				for (int i = 0; i < hintCircles.size(); i++)
				{
					guessCircles.get(i).setFill(Color.WHITE);
					hintCircles.get(i).setFill(Color.BEIGE);
				}


			}
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}




	}

	/**
	 * This method returns nothing, but is passed in a circle and it's index. 
	 	* This method will take that information and set the cooresponding circle to the correct color
	 * @param c char color
	 * @param circleIndex index of circle
	 */
	public void setCircleColorFromChar(char c, int circleIndex) 
	{
		if (model.isViableGuess(c))
		{
			if (model.lowerCaseToUpperCase(c) == 'R')
				guessCircles.get(circleIndex).setFill(Color.RED);
			else if(model.lowerCaseToUpperCase(c) == 'B')
				guessCircles.get(circleIndex).setFill(Color.BLUE);
			else if(model.lowerCaseToUpperCase(c) == 'Y')
				guessCircles.get(circleIndex).setFill(Color.YELLOW);
			else if(model.lowerCaseToUpperCase(c) == 'G')
				guessCircles.get(circleIndex).setFill(Color.GREEN);
			else if(model.lowerCaseToUpperCase(c) == 'O')
				guessCircles.get(circleIndex).setFill(Color.ORANGE);
			else if(model.lowerCaseToUpperCase(c) == 'P')
				guessCircles.get(circleIndex).setFill(Color.PURPLE);
		}

	}

	/**
	 * This method resets the game. Just a little shortcut for me
	 * Nothing is passed in, and nothing is returned.
	 */
	public void resetGame()
	{
		debugMode = false;
		buttons.get(0).setBackground(new Background(new BackgroundFill(Color.DARKGREEN, CornerRadii.EMPTY, Insets.EMPTY)));
		buttons.get(1).setBackground(new Background(new BackgroundFill(Color.DARKORANGE, CornerRadii.EMPTY, Insets.EMPTY)));
		buttons.get(2).setBackground(new Background(new BackgroundFill(Color.BLUE, CornerRadii.EMPTY, Insets.EMPTY)));
		s = "";
		model.newGame();

		// TODO: Loop through and reset all loop colors
		for (int i = 0; i < hintCircles.size(); i++)
		{
			guessCircles.get(i).setFill(Color.WHITE);
			hintCircles.get(i).setFill(Color.BEIGE);

		}
	}


}


/*
 * //Loop through your buttons
		for (int i = 0; i < guessCircles.size(); i++)
		{
			if (event.getSource() == buttons.get(i)) 
			{
				System.out.println("yep");
				// If a button is clicked, chenge the color of the circle
				guessCircles.get(i).setFill(Color.MEDIUMAQUAMARINE);
				break;
			}
		}
 */
