// Jerry Olds
// 1001533643
// CSE-4344-001
// Project 1

package networks_project1;

import java.io.*;
import java.net.*;

/**
 *
 * @author Jerry Olds
 */

public class jdo3643_project1 
{
    public static void main(String [] args) throws Exception
    {
        // Port number
        int port_num = 6789;
        
        // Create listener socket
        try(ServerSocket listener = new ServerSocket(port_num))
        {
            // Process requests
            while(true)
            {
                // 
                Socket connection = listener.accept();
                HttpRequest request = new HttpRequest(connection);
                Thread thread = new Thread(request);
                thread.start();
            }
        }
        
        
    }
}

final class HttpRequest implements Runnable
{
    final static String CRLF = "\r\n";
    Socket socket;
    
    // Constructor
    public HttpRequest(Socket socket) throws Exception
    {
        this.socket = socket;
    }
    
    // Run method
    @Override
    public void run()
    {
        try
        {
            processRequest();
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
    }
    
    private void processRequest() throws Exception
    {
        // Readers
        InputStreamReader isr = new InputStreamReader(socket.getInputStream());
        BufferedReader reader = new BufferedReader(isr);
        
        // Get content of request
        String content = reader.readLine();
        
        // Display the content of request
        while(content.length() != 0)
        {
            System.out.println(content);
            content = reader.readLine();
        }
    }
}