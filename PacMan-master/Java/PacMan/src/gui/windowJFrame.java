package gui;



import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Shape;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

import javax.swing.*;




public class windowJFrame extends JFrame {
	
	
	public windowJFrame() {
		setTitle("Pac Man");
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0, 0, 1366, 740);
		
		
		GameWindow game = new GameWindow();
		
		this.add(game);
	}


}