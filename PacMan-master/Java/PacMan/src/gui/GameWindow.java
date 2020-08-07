package gui;

import characters.*;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Event;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.Timer;
import javax.swing.border.BevelBorder;
import javax.swing.border.EmptyBorder;

import Sockets.SocketServidor;

public class GameWindow extends JPanel implements ActionListener {

	Integer[][] matrix = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 1, 1, 3, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 3, 1, 1, 1, 1, 1, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 1 },
			{ 1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1, 1, 1 },
			{ 1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 3, 1, 1, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1 },
			{ 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };

	PacMan pacman = new PacMan();
	Boolean playing;
	Rectangle colisionZone;
	private Timer timer;
	ArrayList<Rectangle> rectList = new ArrayList<Rectangle>();
	ArrayList<Rectangle> dotList = new ArrayList<Rectangle>();
	ArrayList<Point> dotConsumedListX = new ArrayList<Point>();
	//ArrayList<Integer> dotConsumedListY = new ArrayList<Integer>();
	Image dotImg = new ImageIcon("Images/dot.png").getImage().getScaledInstance(15,15,1);
	Integer size = 25;
	Point pointVer;
	public GameWindow() {
		setBounds(0, 0, 1366, 740);
		setBackground(Color.BLACK);
		setLayout(null);
		setVisible(true);
		playing = true;
		addKeyListener(new TAdapter());
		setFocusable(true);
		colisionZone = new Rectangle(pacman.getPosX(), pacman.getPosY(), 17, 17);
		pacman.setColisionZone(colisionZone);
		pacman.setDir(0);
		timer = new Timer(40, this);
		timer.start();


	}

	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		doDrawing(g);
		isCollidingDots();


	}

	private void doDrawing(Graphics g) {
		verificarCambio();

		for (int f = 0; f < 31; f++) {
			for (int c = 0; c < 28; c++) {
				
				if (matrix[f][c] == 1) {
					Shape rect = new Rectangle((f * size) + 200, (c * size), size, size);
					rectList.add((Rectangle) rect);
					g.setColor(Color.BLUE);
					g.drawRect((f * size) + 200, (c * size), size, size);
				}else if(matrix[f][c] == 3) {
					pointVer= new Point(f,c);
					if(!dotConsumedListX.contains(pointVer)) {
					Shape dotRect = new Rectangle((f * size) + 205, (c * size)+5, 15, 15);
					dotList.add((Rectangle) dotRect);
					g.setColor(Color.RED);
					g.drawRect((f * size) + 205, (c * size)+5, 15, 15);
					g.drawImage(dotImg,(f * size) + 205, (c * size)+5, this);
						
					}
				}


			}
		}

		Graphics2D g2d = (Graphics2D) g;
		g.setFont(new Font("TimesRoman", Font.BOLD, 16));
		g.setColor(Color.YELLOW);
		g.drawString("Level: "+ pacman.getCurrentLevel().toString(), 1000, 80);
		g.drawString("Score: "+ pacman.getScore().toString(), 1000, 100);
		pacman.setPosX(pacman.getPosX() + pacman.getVelX());
		pacman.setPosY(pacman.getPosY() + pacman.getVelY());
		colisionZone = new Rectangle(pacman.getPosX(), pacman.getPosY(), 17, 17);
		pacman.setColisionZone(colisionZone);
		if(isCollidingWalls() == false) {

			g2d.drawImage(pacman.getpacmanImg(), pacman.getPosX(), pacman.getPosY(), this);
			g.setColor(Color.GREEN);
			g.drawRect(pacman.getPosX(), pacman.getPosY(), 17, 17);

		}else {

			pacman.setPosX(pacman.getPosX() - pacman.getVelX());
			pacman.setPosY(pacman.getPosY() - pacman.getVelY());
			colisionZone = new Rectangle(pacman.getPosX(), pacman.getPosY(), 17, 17);
			pacman.setColisionZone(colisionZone);
			g2d.drawImage(pacman.getpacmanImg(), pacman.getPosX(), pacman.getPosY(), this);
			g.setColor(Color.GREEN);
			g.drawRect(pacman.getPosX(), pacman.getPosY(), 17, 17);
		}


	}

	public Boolean isCollidingWalls() {
		for(int i=0; i<rectList.size();i++) {
			if(pacman.getColisionZone().intersects(rectList.get(i))) {
				return true;
			}
		}
		return false;

	}
	public void isCollidingDots() {
		for(int i=0; i<dotList.size();i++) {
			if(pacman.getColisionZone().intersects(dotList.get(i))) {
				Point pointConsumed = new Point((dotList.get(i).x-205)/size,(dotList.get(i).y - 5)/size);
				if(!dotConsumedListX.contains(pointConsumed)) {
					dotConsumedListX.add(pointConsumed);
					pacman.setScore(pacman.getScore()+5);
				}
				


			}
		}


	}

	class TAdapter extends KeyAdapter {

		@Override
		public void keyPressed(KeyEvent e) {

			int key = e.getKeyCode();
		
			if (playing) {
				if (key == KeyEvent.VK_LEFT) {
					if(pacman.getOption() != 1) {
						pacman.setDir(1);
					}
					pacman.setVelX(-5);
					pacman.setVelY(0);

				} else if (key == KeyEvent.VK_RIGHT) {
					if(pacman.getOption() != 0) {
						pacman.setDir(0);
					}
					pacman.setVelX(5);
					pacman.setVelY(0);

				} else if (key == KeyEvent.VK_UP) {
					if(pacman.getOption() != 3) {
						pacman.setDir(3);
					}
					pacman.setVelX(0);
					pacman.setVelY(-5);
				} else if (key == KeyEvent.VK_DOWN) {
					if(pacman.getOption() != 2) {
						pacman.setDir(2);
					}
					pacman.setVelX(0);
					pacman.setVelY(5);
				} else if (key == KeyEvent.VK_ESCAPE && timer.isRunning()) {
					playing = false;
				} else if (key == KeyEvent.VK_PAUSE) {
					if (timer.isRunning()) {
						timer.stop();
					} else {
						timer.start();
					}
				}
			}

		}

		@Override
		public void keyReleased(KeyEvent e) {

			int keyCode = e.getKeyCode();
			if (keyCode == e.VK_LEFT) {
				pacman.setVelX(0);
			}
			if (keyCode == e.VK_RIGHT) {
				pacman.setVelX(0);
			}
			if (keyCode == e.VK_UP) {
				pacman.setVelY(0);
				;
			}
			if (keyCode == e.VK_DOWN) {
				pacman.setVelY(0);
			}

		}
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		repaint();
	}
	
	void verificarCambio(){
		
		if (mens != "") {
			System.out.print("Mensaje obtenido desde GameWindow: ");
			System.out.println(mens);
			String[] datos = mens.split(",");
			mens="";
			
			if(datos[0].contentEquals("fruta")) {
				//Crear fruta
				System.out.println("Creando Fruta ");
			}
			if(datos[0].contentEquals("fantasma")) {
				//Crear fantasma
				System.out.println("Creando fantasma ");
			}
			if(datos[0].contentEquals("pastilla")) {
				//Crear pastilla
				System.out.println("Creando pastilla ");
			}
			if(datos[0].contentEquals("velocidad")) {
				//Cambiando velocidad
				System.out.println("Cambiando velocidad ");
			}
			
		}
	}
	static String mens = "";
	public static void asignarTexto(String texto) {
		mens = texto;
	}

}
