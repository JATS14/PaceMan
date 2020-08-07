package gui;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import Sockets.SocketServidor;

public class StartWindow extends JFrame {
	
	Boolean coneccion = false;
	
	public static void main(String[] args) {
		//crear thread aqui
		Thread thread1 = new Thread() {
			public void run() {
				iniciarSokcet();
			}
		};
		
		thread1.start();
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					StartWindow frame = new StartWindow();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	private Image Image = new ImageIcon("Images/pacmanbckgrnd.jpg").getImage();
	private Image play = new ImageIcon("Images/play.png").getImage();
	private JPanel contentpane;


	public StartWindow() {
		setLayout(null);
		setTitle("Menu principal");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(0,0,1366,700);
		setResizable(true);
		setVisible(true);



		contentpane = new JPanel();
		contentpane.setBounds(0,0,1366,700);
		contentpane.setLayout(null);

		JLabel background = new JLabel();
		background.setBounds(0, 0, 1366, 700);
		background.setIcon(new ImageIcon(Image));

		JButton btn = new JButton();
		btn.setBounds(600, 490, 96,96);
		btn.setIcon(new ImageIcon(play));
		btn.setOpaque(false);
		btn.setContentAreaFilled(false);
		btn.setBorderPainted(false);
		
		btn.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				coneccion = SocketServidor.probarConeccion();
				if(coneccion) {
				windowJFrame frame = new windowJFrame();
				 StartWindow.this.dispose();
				}
			}
		});

		contentpane.add(btn);
		contentpane.add(background);
		this.add(contentpane);
	}

	static Runnable iniciarSokcet() {
		try {
			new SocketServidor();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

}
