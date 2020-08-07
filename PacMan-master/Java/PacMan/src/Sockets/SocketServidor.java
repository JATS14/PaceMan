package Sockets;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import gui.GameWindow;
public class SocketServidor {

	private final int PUERTO = 25578;
    protected String mensajeServidor; 
    protected ServerSocket ss; 
    protected Socket cs; 
    static String mensaje;

    
    public static String getMensaje() {
   	 return mensaje;
    }
    
    
    
    @SuppressWarnings("deprecation")
	public SocketServidor() throws IOException {
    	try {
    	
    ss = new ServerSocket(PUERTO);
    
    while(true) {
    	mensaje = "";
    	System.out.print("Nueva conecion... ");
    	
    	cs = new Socket();
    	System.out.println("Esperando a C");
    	cs = ss.accept(); 
        System.out.println("C en línea");
        
    	DataOutputStream bufferSalida =
    	            new DataOutputStream (cs.getOutputStream());
    	DataInputStream bufferEntrada =
    	            new DataInputStream (cs.getInputStream());
        
        while((mensajeServidor = bufferEntrada.readLine()) != null) {
        	System.out.println("------Resiviendo datos del servidor");
        	System.out.print("Mensaje del Servidor: ");
            System.out.println(mensajeServidor);
            mensaje = mensajeServidor;
            GameWindow.asignarTexto(mensaje);
        }
        cs.close();   
		bufferEntrada.close();
		bufferSalida.close();
		Thread.sleep(1);
    }
    }
        catch (Exception e){
            e.printStackTrace();
        }
    
    }
	
}
