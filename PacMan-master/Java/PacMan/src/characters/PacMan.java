package characters;

import java.awt.Image;
import java.awt.Rectangle;
import java.awt.Shape;

import javax.swing.ImageIcon;

public class PacMan {
	Integer posX = 460;
	
	Integer posY = 300;
	Integer lives;
	Image pacmanImg;
	Image pacmanImgder = new ImageIcon("Images/pacman.gif").getImage().getScaledInstance(19,19,1);

	Image pacmanImgizq = new ImageIcon("Images/pacmanizq.gif").getImage().getScaledInstance(19,19,1);


	Image pacmanImgabj = new ImageIcon("Images/pacmanabj.gif").getImage().getScaledInstance(19,19,1);
 
	Image pacmanImgarr = new ImageIcon("Images/pacmanarr.gif").getImage().getScaledInstance(19,19,1);


	
	Integer velX = 0; 
	
	Integer velY = 0;
	
	Rectangle colisionZone;
	
	Boolean notColliding = true;
	Integer option = 0;
	Integer score =0;
	Integer currentLevel = 1;
	
	public Integer getCurrentLevel() {
		return currentLevel;
	}
	public void setCurrentLevel(Integer currentLevel) {
		this.currentLevel = currentLevel;
	}
	public Integer getScore() {
		return score;
	}
	public void setScore(Integer score) {
		this.score = score;
	}
	public Boolean getNotColliding() {
		return notColliding;
	}
	public void setNotColliding(Boolean notColliding) {
		this.notColliding = notColliding;
	}
	public Rectangle getColisionZone() {
		return colisionZone;
	}
	public void setColisionZone(Rectangle colisionZone) {
		this.colisionZone = colisionZone;
	}
	
	public Integer getPosX() {
		return posX;
	}
	public void setPosX(Integer posX) {
		this.posX = posX;
	}
	public Integer getPosY() {
		return posY;
	}
	public void setPosY(Integer posY) {
		this.posY = posY;
	}
	public Integer getLives() {
		return lives;
	}
	public void setLives(Integer lives) {
		this.lives = lives;
	}
	public Image getpacmanImg() {
		return pacmanImg;
	}
	public void setpacmanImg(Image pacmanImg) {
		this.pacmanImg = pacmanImg;
	
	}
	public void setDir(Integer option1) {
		switch (option1) {
		case 0:
			this.setpacmanImg(pacmanImgder);
			break;
		case 1:
			this.setpacmanImg(pacmanImgizq);
			break;
		case 2:
			this.setpacmanImg(pacmanImgabj);
			break;
		case 3:
			this.setpacmanImg(pacmanImgarr);
			break;
		}
		this.option = option1;
	}
	public Integer getOption() {
		
		return this.option;
	}
	
	public Integer getVelX() {
		return velX;
	}
	public void setVelX(Integer velX) {
		this.velX = velX;
	}
	public Integer getVelY() {
		return velY;
	}
	public void setVelY(Integer velY) {
		this.velY = velY;
	}

}
